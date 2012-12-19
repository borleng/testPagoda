///////////////////////////////////////////////////////////////////////////////
//    Copyright (c), Philips Semiconductors Gratkorn
//
//                     (C)PHILIPS Electronics N.V. 2000
//                        All rights are reserved. 
//  Philips reserves the right to make changes without notice at any time.
// Philips makes no warranty, expressed, implied or statutory, including but
// not limited to any implied warranty of merchantibility or fitness for any
//particular purpose, or that the use will not infringe any third party patent,
// copyright or trademark. Philips must not be liable for any loss or damage
//                          arising from its use.
///////////////////////////////////////////////////////////////////////////////
//
// Projekt         : CommonLib
// Files           : CommonLib.h CommonLib.c OsDefs.h DesEncryption.c
// Created         : 01.04.00
//
// COMMENT: This header contains common function declarations
// MODIFICATIONS:
// 01.04.00  HB  first issue
// 00.00.9X  first implementation made by WZ
// 05.05.00  CRi implementation
///////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_H
#define COMMON_H

#include "OsDefs.h"
#include "MfErrNo.h"
#include "LibInfo.h"

#ifdef __cplusplus
extern "C"
{
#endif

//////////////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////////////

// Function: HostCalcDes
#define ENCIPH            0x00
#define DECIPH            0x04

// Function: HostCalcCrc
#define CRC8             0x80
#define CRC16            0x00

// Initial Value 0
#define IV0 (unsigned char*)"\x00\x00\x00\x00\x00\x00\x00\x00"


//////////////////////////////////////////////////////////////////////////////
// Function Export Table
//////////////////////////////////////////////////////////////////////////////

typedef char*         (CALL_CONV * GET_ERROR_MESSAGE)            (int);
typedef unsigned char (CALL_CONV * ASSERT_MODE)                  (unsigned char, unsigned char);
typedef unsigned char (CALL_CONV * ASSERT_RANGE)                 (signed int, signed int, signed int);
typedef void          (CALL_CONV * EXOR_8)                       (unsigned char*, unsigned char*, unsigned char*);
typedef unsigned char (CALL_CONV * BIT_REVERSE)                  (unsigned char);
typedef void          (CALL_CONV * BYTE_REVERSE)                 (unsigned char*, unsigned char*, int);
typedef int           (CALL_CONV * HOST_CALC_CRC)                (unsigned char, int, unsigned char*, unsigned char*);
typedef int           (CALL_CONV * HOST_CALC_DES)                (unsigned char, unsigned char*, unsigned char*, unsigned char*);
typedef void          (CALL_CONV * HOST_GET_PREVIOUS_DES_RESULT) (unsigned char *result);
typedef void          (CALL_CONV * HOST_DES_RESET)               (void);
typedef void          (CALL_CONV * DES_KEY_INIT)                 (unsigned char *key);
typedef void          (CALL_CONV * DES_ENCRYPT)                  (unsigned char *b);
typedef void          (CALL_CONV * DES_DECRYPT)                  (unsigned char *b);

typedef struct tagCommonLibFunctionTable
{
  GET_ERROR_MESSAGE             GetErrorMessage;
  ASSERT_MODE                   AssertMode;
  ASSERT_RANGE                  AssertRange;
  EXOR_8                        Exor8;
  BIT_REVERSE                   BitReverse;
  BYTE_REVERSE                  ByteReverse;
  HOST_CALC_CRC                 HostCalcCrc;
  HOST_CALC_DES                 HostCalcDes;
  HOST_GET_PREVIOUS_DES_RESULT  HostGetPreviousDesResult;
  HOST_DES_RESET                HostDesReset;
  DES_KEY_INIT                  DesKeyInit;
  DES_ENCRYPT                   DesEncrypt;
  DES_DECRYPT                   DesDecrypt;
} COMMONLIB_FUNCTION_TABLE;


//////////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////////

// _____________________________________________________________________________
//
// FUNCTION: GetErrorMessage
//
//       IN: error_number  valid error number
//     
//      OUT: -
// 
//   RETURN: pointer to an internal message string.
//
//  COMMENT: Shows an error text (defined in mif2err.h) according to the 
//           error code
//
DLLEXP_IMP char* CALL_CONV GetErrorMessage(int error_number);

// _____________________________________________________________________________
//
// FUNCTION: AssertMode
//
//       IN: mode    Variable-Value which should be checked
//           value   valid value for mode
//     
//      OUT: -
// 
//   RETURN: bit pattern with wrong values
//
//  COMMENT: This function checks the variable for valid Bit-Pattern and returns
//           the wrong bit pattern. If the value is valid, this function
//           always returns zero. 
//
DLLEXP_IMP unsigned char CALL_CONV AssertMode(unsigned char mode,
                                              unsigned char value);

// _____________________________________________________________________________
//
// FUNCTION: AssertRange
//
//       IN: var     Variable-Value which should be checked
//           start   start-value
//           end     end-value
//     
//      OUT: -
// 
//   RETURN: 0   variable value is in the specified range
//           1   variable value is outside the specified range
//
//  COMMENT: This function checks the variable value to be in the specified range
//           In order to be conform with the analog function MfAssertMode, 
//           the constraint is matched, if zero is returned.
//
DLLEXP_IMP unsigned char CALL_CONV AssertRange(signed int var,
                                               signed int start,
												                       signed int end);

// _____________________________________________________________________________
// 
// FUNCTION: Exor8
//  
//       IN: in1   first character
//           in2   second character
//      OUT: out   calculation result
//   RETURN: -
//  COMMENT: Calculate the bitwise EXOR of a 8 byte long char array
//
DLLEXP_IMP void CALL_CONV Exor8(unsigned char *out, 
                                unsigned char *in1, 
                                unsigned char *in2);

// _____________________________________________________________________________
//
// FUNCTION: BitReverse
//
//       IN: in   character to reverse
//      OUT: -
//   RETURN: calculation result
//  COMMENT: Bit-Reverse -> changes the order of the bits within one character
//           d. h. 0101110 ==> 0111010
//
DLLEXP_IMP unsigned char CALL_CONV BitReverse(unsigned char in);

// _____________________________________________________________________________
//
// FUNCTION: ByteReverse
//
//       IN: in     character sequenz with "len" bytes
//      OUT: out    reversed character sequenze with "len" bytes
//   RETURN: -
//  COMMENT: Byte-Reverse -> changes the order of bytes within the sequenze
//           d. h. 0x1,0x3,0ab ==> 0ab,0x3,0x1
//
DLLEXP_IMP void CALL_CONV ByteReverse(unsigned char* in, 
                                      unsigned char* out, 
                                      int len);

// _____________________________________________________________________________
//
// FUNCTION: HostCalcCrc
//       IN: crc_mode   valid values are:
//                      CRC8     
//                      CRC16
//           len        specifies the number of data bytes for that the CRC shall 
//                      be calculated.
//           in         is a pointer to the input data. It is assumed, that 
//                      the variable in holds len input bytes.
//      OUT: out        is a pointer to the output data. If CRC8 is selected out has to hold one byte, in case of CRC16 out has to hold two bytes.
//   RETURN: MI_CRC_ZERO    CRC calculation correct
//           MI_CRC_NOTZERO CRC calculation with error
//  COMMENT: Calculates the 8 or 16 bit CRC for a given number of bytes using the
//           default values of the MFRC
//
DLLEXP_IMP int CALL_CONV HostCalcCrc(unsigned char crc_mode, 
                                     int len, 
                                     unsigned char *in, 
                                     unsigned char *out);

// _____________________________________________________________________________
//
// FUNCTION: HostCalcDes
//
//       IN: des_mode    ENCIPH, DECIPH     encipher or decipher data
//           iv          initial value. For CBC-mode, the previous value can be 
//                       passed
//           deskey      16 DES-keys to pass. 
//   IN/OUT: inout       Data is passed to the function  with this parameter. 
//                       The result is also returned with this variable.
//
//   RETURN: MI_WRONG_DESKEY
//           MI_OK
//
//  COMMENT: Calculate the DES en/deciphered cryptogram using the DES routines 
//           defined in 'mfdes.c'.
//
DLLEXP_IMP int CALL_CONV HostCalcDes(unsigned char des_mode, 
                                     unsigned char *iv, 
                                     unsigned char *inout,
                                     unsigned char *deskey);

// _____________________________________________________________________________
//
// FUNCTION: HostGetPreviousDesResult
//
//       IN: -
//      OUT: result      previous calculation cipher 
//                       a 8 bytes character buffer is expected
//   RETURN: -
//  COMMENT: Returns the value of the previous DES calculation. With this
//           function the implementation of a CBC over the whole program
//           sequenz is easier to implement.
//
DLLEXP_IMP void CALL_CONV HostGetPreviousDesResult(unsigned char *result);

// _____________________________________________________________________________
//
// FUNCTION: HostDesReset
//
//       IN: -
//      OUT: -
//   RETURN: -
//  COMMENT: This function resets the internal starting value to zero. It is the
//           corresponding function to MfPcdResetDes on the host computer.
//
DLLEXP_IMP void CALL_CONV HostDesReset(void);

// _____________________________________________________________________________
//
//  FUNCTION: DesKeyInit
//        IN: key        8 bytes en-/decryption key for single DES or
//                       16 bytes long keys for triple DES
//       OUT: -
//    IN/OUT: -
//    RETURN: -
//   COMMENT: 
//
DLLEXP_IMP void  CALL_CONV  DesKeyInit(unsigned char *key);

// _____________________________________________________________________________
//
//  FUNCTION: DesEncrypt
//        IN: b          8 bytes data, which should be encrypted
//       OUT: -
//    IN/OUT: -
//    RETURN: -
//   COMMENT: 
//
DLLEXP_IMP void  CALL_CONV  DesEncrypt(unsigned char *b);

// _____________________________________________________________________________
//
//  FUNCTION: DesDecrypt
//        IN: b          8 bytes data, which should be decrypted
//       OUT: -
//    IN/OUT: -
//    RETURN: -
//   COMMENT: 
//
DLLEXP_IMP void  CALL_CONV  DesDecrypt(unsigned char *b);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H

//////////////////////////////////////////////////////////////////////////////
//                             End of File
//////////////////////////////////////////////////////////////////////////////