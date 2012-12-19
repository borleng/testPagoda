///////////////////////////////////////////////////////////////////////////////
//    Copyright (c), Philips Semiconductors Gratkorn
//
//                  (C)PHILIPS Electronics N.V.2000
//                     All rights are reserved. 
//  Philips reserves the right to make changes without notice at any time.
// Philips makes no warranty, expressed, implied or statutory, including but
// not limited to any implied warranty of merchantibility or fitness for any
//particular purpose, or that the use will not infringe any third party patent,
// copyright or trademark. Philips must not be liable for any loss or damage
//                          arising from its use.
///////////////////////////////////////////////////////////////////////////////

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "MfRc500.h"
#include "MfErrno.h"
#include "PICCCmdConst.h"
#include "CommonLib.h"

/*------------------------------------------------------------------------------------------------*/

#define MIF_LIGHT 0x01
#define MIF_STANDARD 0x08
#define MIF_PLUS 0x10

unsigned char keyA[]  =  {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
unsigned char keyB[]  =  {0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5};
unsigned char keyF[]  =  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

static signed short previousStatus = MI_OK;

/*------------------------------------------------------------------------------------------------*/

void block_show(unsigned char ats, unsigned char adr, unsigned char *data);

/*------------------------------------------------------------------------------------------------*/


void block_show (unsigned char ats, unsigned char adr, unsigned char *data)
{
    int i;

    printf("B%3d:  0x", adr);

    //  hex dump memory
    for (i = 0; i < (ats & MIF_LIGHT ? 8 : 16); i++)
        printf("%02X ",data[i]);
    printf("  ");

    //  ascii dump
    for (i = 0; i < (ats & MIF_LIGHT ? 8 : 16); i++)
        printf("%c", (data[i] != 0x00 &&
                      data[i] != 0x07 &&
                      data[i] != 0x08 &&
                      data[i] != '\t' &&
                      data[i] != '\r' &&
                      data[i] != '\n' &&
                      data[i] != 0x1A &&
                      data[i] != 0x1B &&
                      data[i] != 0xFF)? data[i] : 'ú');
    printf("\r\n");
}

/*------------------------------------------------------------------------------------------------*/

int rges(void)
{
    static unsigned short errorCnt = 0;
    short status = MI_OK;
    int nextauth = 0;
    char i;
    unsigned char ats = 0;
    unsigned char adr = 0;
    unsigned nblocks = 256;
    unsigned char tt[2];
    unsigned char snr[4];
    unsigned char data[16];
    unsigned char keyCoded[12];

    printf("\r\nPress Esc to Quit!                                RGES  \r\n");

    while ((status = Mf500PcdConfig()) != MI_OK)
    {
        if (status == previousStatus)
        {
           if ( ! (errorCnt++ % 100 ) )
              printf(".");
        }
        else
        {
           previousStatus = status;
           printf("\ninitialization error %d %s ",status,GetErrorMessage(status));
        }
    }
    
    while( 1 )
    {  
        if ( _kbhit( ) )
        {
           if( getch( ) == 27 )
             break;
           printf( "press any key to continue ..." );
           getch ( );
        }
        
        if (adr >= nblocks)
        {
            adr = 0;
        }

        if ((status = Mf500PiccRequest(PICC_REQALL,tt)) == MI_OK)
        {
            if ((status = Mf500PiccAnticoll(0,snr)) == MI_OK)
            {
                if ((status = Mf500PiccSelect(snr,&ats)) != MI_OK)
                {
                   if (status != previousStatus)
                      printf("\ncommunication error at select");
                }
            }
            else
            {
               if (status != previousStatus)
                  printf("\ncommunication error at anticollision");
            }
        }
        else
        {
           if (status != previousStatus)
              printf("\ncommunication error at request");
        }

        if (status == MI_OK)
        {
            if (ats & MIF_PLUS)              //answer to select
                nblocks = 256;
            else if (ats & MIF_STANDARD)
                nblocks = 64;
            else if (ats & MIF_LIGHT)
                nblocks = 12;
            else
                nblocks = 256;
      
            nextauth %= 4;
            //  try four different keys
            switch(nextauth)
            {
                case 0:
                    Mf500HostCodeKey(keyA,keyCoded);
                    status = Mf500PiccAuthKey(PICC_AUTHENT1A,snr,keyCoded,adr);
                    if (status != 0)
                    {
                        nextauth++;
                        continue;
                    }
                    break;

                case 1:
                    Mf500HostCodeKey(keyF,keyCoded);
                    status = Mf500PiccAuthKey(PICC_AUTHENT1A,snr,keyCoded,adr);
                    if (status != 0)
                    {
                        nextauth++;
                        continue;
                    }
                    break;

                case 2:
                    Mf500HostCodeKey(keyB,keyCoded);
                    status = Mf500PiccAuthKey(PICC_AUTHENT1B,snr,keyCoded,adr);
                    if (status != 0)
                    {
                        nextauth++;
                        continue;
                    }
                    break;

                case 3:
                    Mf500HostCodeKey(keyF,keyCoded);
                    status = Mf500PiccAuthKey(PICC_AUTHENT1B,snr,keyCoded,adr);
                    if (status != 0)
                    {
                       nextauth++;
                       continue;
                    }
                    break;

                default:
                    status = MI_NOTAUTHERR;
            }

            if(status == MI_OK)
            { 
                if (adr==0)
                {
                    printf("\r\n\n");
                    printf("tagtype    0x%02x%02x   snr 0x",tt[1],tt[0]);
                    for (i = 3;i>=0;i--)
                        printf("%02x",snr[i]);
                    printf("    ats 0x%02x",ats);
                    printf(nextauth%2 ? "   keyset1   ":"    keyset0   ");
                    printf(nextauth>=2 ? "keyB   ":"keyA   ");
                    printf("\r\n\n");
                }
 
                if((status = Mf500PiccRead(adr, data)) == MI_OK)
                {
                  if (status != previousStatus)
                  {
                     printf("\n");
                     previousStatus = status;
                  }
                  block_show(ats, adr, data);
                }
                else
                {
                   nextauth++;
                   if (status != previousStatus)
                      printf("\ncommunication error at read");
                }
            }
            else
            {
               if (status != previousStatus)
                  printf("\ncommunication error at authentication");
            }
      
            if (ats&MIF_LIGHT)      //MFL reads the pages two by two
                adr += 2;
            else
                adr++;
      
            Mf500PiccHalt();
        }

        if (status)
        {
           if (status == previousStatus)
           {
              if ( ! (errorCnt++ % 100 ) )
                 printf(".");
           }
           else
           {
              previousStatus = status;
              printf(" %d %s ",status,GetErrorMessage(status));
           }
        }
    } 

    printf( "finishing\n" );
    return 0;
}
