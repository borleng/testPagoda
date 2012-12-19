/*
*         Copyright (c), Philips Semiconductors Gratkorn / Austria
*
*                     (C)PHILIPS Electronics N.V.2000
*       All rights are reserved. Reproduction in whole or in part is 
*      prohibited without the written consent of the copyright owner.
*  Philips reserves the right to make changes without notice at any time.
* Philips makes no warranty, expressed, implied or statutory, including but
* not limited to any implied warranty of merchantability or fitness for any
*particular purpose, or that the use will not infringe any third party patent,
* copyright or trademark. Philips must not be liable for any loss or damage
*                          arising from its use.
*/

/*! \file MfRc500.h
*
* Projekt: MF EV X00 Firmware
*
* $Workfile:: MfRc500.h                                                 $ 
* $Modtime:: 10.09.01 11:53                                             $ 
* $Author:: Hb                                                          $
* $Revision:: 1                                                         $
*
*/
//#ifndef MFRC500_H
#define MFRC500_H

// General Include File for serveral defines concerning conditional library
// compilation and microcontroller usage
#include <windows.h>
#include "OsDefs.h"

// define function prefix for convinience
#define FCT_PREF DLLEXP_IMP RET_STATUS CALL_CONV

#ifdef __cplusplus

extern "C" {

// _____________________________________________________________________________
//                            Function Prototypes
// _____________________________________________________________________________

// _____________________________________________________________________________
//                            Global Variable Declaration
// _____________________________________________________________________________

// _____________________________________________________________________________
//
//  FUNCTION: Mf500LibInfo
//        IN: unsigned long key
//       OUT: -
//    RETURN: const char *   *VERSION returns char *
//                           *BUILD returns unsigned long
//                    NULL    on error
//   COMMENT: 
//
DLLEXP_IMP const char * CALL_CONV Mf500LibInfo(unsigned long key);

// _____________________________________________________________________________
//
//  FUNCTION: Mf500InterfaceOpen
//        IN: unsigned long mode
//        IN: unsigned long options
//       OUT: -
//    RETURN: RET_STATUS MI_POLLING                 interface opened
//                       MI_WRONG_PARAMETER_VALUE   invalid mode and/or options
//                       MI_INTERFACE_ERROR         error while opening interface
//   COMMENT: Necessary for MfGeneric compatibility.
//            Constructs the internal used InterfaceHandle and ReaderInterface
//            object instances using the options given in mode and options.
//
FCT_PREF Mf500InterfaceOpen(unsigned long mode, unsigned long options);

// _____________________________________________________________________________
//
//  FUNCTION: Mf500InterfaceClose
//        IN: -
//       OUT: -
//    RETURN: MI_OK
//   COMMENT: Necessary for MfGeneric compatibility.
//            Deletes the internal used InterfaceHandle and ReaderInterface
//            object instances.
//
FCT_PREF Mf500InterfaceClose(void);

/// PCD Configuration
FCT_PREF Mf500PcdConfig(void);

/// Active Antenna Slave Configuration of the MF RC500.
FCT_PREF Mf500ActiveAntennaSlaveConfig(void);

/// Active Antenna Master Configuration of the MF RC 500
FCT_PREF Mf500ActiveAntennaMasterConfig(void);

/// Set default attributes for the baudrate divider
FCT_PREF Mf500PcdSetDefaultAttrib(void);

#ifndef NO_DOCUMENTATION
/// Set attributes for the baudrate divider 
FCT_PREF Mf500PcdSetAttrib(unsigned char DSI,
                           unsigned char DRI);

/// Get transmission properties of the PCD
FCT_PREF Mf500PcdGetAttrib(unsigned char *FSCImax,
                          unsigned char *FSDImax,
                          unsigned char *DSsupp,
                          unsigned char *DRsupp,
                          unsigned char *DREQDS);

/// PICC Request command
FCT_PREF Mf500PiccRequest(unsigned char req_code, 
                       unsigned char *atq);
                       
/// PICC Request command for ISO 14443 A-4 Command set
FCT_PREF Mf500PiccCommonRequest(unsigned char req_code, 
                             unsigned char *atq);  

/// PICC Anticollision Command
FCT_PREF Mf500PiccAnticoll (unsigned char bcnt,
                         unsigned char *snr);

/// PICC Cascaded Anticollision Command
FCT_PREF Mf500PiccCascAnticoll (unsigned char select_code,
                             unsigned char bcnt,
                             unsigned char *snr);                     

/// PICC Select Command
FCT_PREF Mf500PiccSelect(unsigned char *snr, 
                      unsigned char *sak);

/// PICC Select Command
FCT_PREF Mf500PiccCascSelect(unsigned char select_code, 
                             unsigned char *snr, 
                             unsigned char *sak); 

/// Activation of a PICC in IDLE mode
FCT_PREF Mf500PiccActivateIdle(unsigned char br,
                           unsigned char *atq, 
                           unsigned char *sak, 
                           unsigned char *uid, 
                           unsigned char *uid_len);

/// Activation of a PICC in IDLE mode within a loop function
FCT_PREF Mf500PiccActivateIdleLoop(unsigned char br,
                                   unsigned char *atq, 
                                   unsigned char *sak, 
                                   unsigned char *uid, 
                                   unsigned char *uid_len,
                                   unsigned char sec);
 
/// Activation of all PICC's in the RF field
FCT_PREF Mf500PiccActivateWakeup(unsigned char br,
                             unsigned char *atq, 
                             unsigned char *sak,
                             unsigned char *uid, 
                             unsigned char uid_len);

/// MIFARE®  Authentication
FCT_PREF Mf500PiccAuth(unsigned char auth_mode, 
                      unsigned char key_sector, 
                      unsigned char block);   
  
/// MIFARE ® Authentication with  keys stored  in the MF RC 500's EEPROM.
FCT_PREF Mf500PiccAuthE2( unsigned char auth_mode, 
                         unsigned char *snr,      
                         unsigned char key_sector,
                         unsigned char block); 

/// Authentication Key Coding
FCT_PREF Mf500HostCodeKey(unsigned char *uncoded, 
                         unsigned char *coded); 

/// Key Loading into the MF RC500's EEPROM.
FCT_PREF Mf500PcdLoadKeyE2(unsigned char key_type,
                          unsigned char sector,
                          unsigned char *uncoded_keys); 
                     
/// Authentication with direct key loading form the microcontroller
FCT_PREF Mf500PiccAuthKey(unsigned char auth_mode,
                         unsigned char *snr,   
                         unsigned char *keys,  
                         unsigned char sector);   
                     
/// PICC Read Block
FCT_PREF Mf500PiccRead(unsigned char addr,  
                       unsigned char* data);

/// PICC Read Block of variable length
FCT_PREF Mf500PiccCommonRead(unsigned char cmd,
                             unsigned char addr,  
                             unsigned char datalen,
                             unsigned char *data);
                  
/// PICC Write Block
FCT_PREF Mf500PiccWrite(unsigned char addr,
                        unsigned char *data);

/// PICC Write 4 Byte Block
FCT_PREF Mf500PiccWrite4(unsigned char addr,
                         unsigned char *data);
                       
/// PICC Write Block of variable length
FCT_PREF Mf500PiccCommonWrite(unsigned char cmd,
                              unsigned char addr,
                              unsigned char datalen,
                              unsigned char *data);

/// PICC Value Block Operation
FCT_PREF Mf500PiccValue(unsigned char dd_mode, 
                       unsigned char addr, 
                       unsigned char *value,
                       unsigned char trans_addr);

/// PICC Value Block Operation for Cards with automatic transfer
FCT_PREF Mf500PiccValueDebit(unsigned char dd_mode, 
                             unsigned char addr, 
                             unsigned char *value);

/// Exchange Data Blocks PCD --> PICC --> PCD
FCT_PREF Mf500PiccExchangeBlock(unsigned char *send_data,
                               unsigned short send_bytelen,
                               unsigned char *rec_data,  
                               unsigned short *rec_bytelen,
                               unsigned char append_crc, 
                               unsigned long timeout );                  

/// PICC Halt
FCT_PREF Mf500PiccHalt(void);

#endif //NO_DOCUMENTATION
 

#ifdef __cplusplus
}
#endif

#endif // MFRC500DLLEXT_H