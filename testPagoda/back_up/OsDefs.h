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

//
//
// Projekt         : CommonLib
// Files           : osdefs.h
// Created         : 04.05.99
//
// COMMENT: This header file should be included in every header.
//          Several defines to switch between operating systemes are placed
//          here.
//
//============================================================================
// 07.06.99          HB  File dependencies changed. 
// 04.03.00          HB  new definition of DLL_EXPORT
//////////////////////////////////////////////////////////////////////////////
#ifndef OSDEFS_H
#define OSDEFS_H

#ifndef _C166            // MS Win platform
   #ifdef WIN32		     // Win NT, Win98 or 32 bit Win95
      #define CALL_CONV __stdcall
      #ifdef  DLL_EXPORT // should be defined in every library source file
         #define DLLEXP_IMP __declspec(dllexport)
      #else
         #define DLLEXP_IMP __declspec(dllimport)
      #endif             // DLL_EXPORT
   #else  
      #define DLLEXP_IMP
      #define CALL_CONV
   #endif                // WIN32
   #define RET_STATUS short
#else                    // microcontroller platform
   #define CALL_CONV
   #define DLLEXP_IMP
   #define RET_STATUS char
#endif                   // !_C166

// define function prefix for convinience
#define FCT_PREF DLLEXP_IMP RET_STATUS CALL_CONV
#endif
//////////////////////////////////////////////////////////////////////////////
//                             End of File
//////////////////////////////////////////////////////////////////////////////
