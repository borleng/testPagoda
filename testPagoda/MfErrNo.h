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
// Files           : CommonLib.h CommonLib.c OsDefs.h MfErrNo.h DesEncryption.c
// Created         : 01.04.00
//
// COMMENT: This header contains error codes for CommonLib project
// MODIFICATIONS:
// 29.11.00  HB  first issue
// 08.01.01  JW  updated error codes (including MfRc500, MfRd260 error codes)
// 02.08.01  TR  updated error codes (inlcuding RdMUX error codes)
///////////////////////////////////////////////////////////////////////////////
#ifndef MFERRNO_H
#define MFERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "OsDefs.h"

//////////////////////////////////////////////////////////////////////////////
// Reader Error Codes                   Base Address Start:      0000
//                                      Base Address End:        -999
//////////////////////////////////////////////////////////////////////////////
#define READER_ERR_BASE_START           0
#define MI_OK                           0
#define MI_CHK_OK                       0
#define MI_CRC_ZERO                     0
// ICODE1 Error   Codes
#define  I1_OK                      0
#define  I1_NO_ERR                  0

#define MI_CRC_NOTZERO                  1

#define MI_NOTAGERR                     (-1)
#define MI_CHK_FAILED                   (-1)
#define MI_CRCERR                       (-2)
#define MI_CHK_COMPERR                  (-2)
#define MI_EMPTY                        (-3)
#define MI_AUTHERR                      (-4)
#define MI_PARITYERR                    (-5)
#define MI_CODEERR                      (-6)

#define MI_SERNRERR                     (-8)
#define MI_KEYERR                       (-9)
#define MI_NOTAUTHERR                   (-10)
#define MI_BITCOUNTERR                  (-11)
#define MI_BYTECOUNTERR                 (-12)
#define MI_IDLE                         (-13)
#define MI_TRANSERR                     (-14)
#define MI_WRITEERR                     (-15)
#define MI_INCRERR                      (-16)
#define MI_DECRERR                      (-17)
#define MI_READERR                      (-18)
#define MI_OVFLERR                      (-19)
#define MI_POLLING                      (-20)
#define MI_FRAMINGERR                   (-21)
#define MI_ACCESSERR                    (-22)
#define MI_UNKNOWN_COMMAND              (-23)
#define MI_COLLERR                      (-24)
#define MI_RESETERR                     (-25)
#define MI_INITERR                      (-25)
#define MI_INTERFACEERR                 (-26)
#define MI_ACCESSTIMEOUT                (-27)
#define MI_NOBITWISEANTICOLL            (-28)
#define MI_QUIT                         (-30)
#define MI_CODINGERR                    (-31)
#define MI_SENDBYTENR                   (-51)
#define MI_CASCLEVEX                    (-52)    
#define MI_SENDBUF_OVERFLOW             (-53)
#define MI_BAUDRATE_NOT_SUPPORTED       (-54)
#define MI_SAME_BAUDRATE_REQUIRED       (-55)

#define MI_WRONG_PARAMETER_VALUE        (-60)

// ICODE1 Error   Codes
#define  I1_WRONGPARAM                  (-61)
#define  I1_NYIMPLEMENTED               (-62)
#define  I1_TSREADY                     (-63)

#define  I1_TIMEOUT                     (-70)
#define  I1_NOWRITE                     (-71)
#define  I1_NOHALT                      (-72)
#define  I1_MISS_ANTICOLL               (-73) 

#define  I1_COMM_ABORT                  (-82)

#define MI_BREAK                        (-99)
#define MI_NY_IMPLEMENTED               (-100)
#define MI_NO_MFRC                      (-101)
#define MI_MFRC_NOTAUTH                 (-102)
#define MI_WRONG_DES_MODE               (-103)
#define MI_HOST_AUTH_FAILED             (-104)

#define MI_WRONG_LOAD_MODE              (-106)
#define MI_WRONG_DESKEY                 (-107)
#define MI_MKLOAD_FAILED                (-108)
#define MI_FIFOERR                      (-109)
#define MI_WRONG_ADDR                   (-110)
#define MI_DESKEYLOAD_FAILED            (-111)

#define MI_WRONG_SEL_CNT                (-114)

#define MI_WRONG_TEST_MODE              (-117)
#define MI_TEST_FAILED                  (-118)
#define MI_TOC_ERROR                    (-119)
#define MI_COMM_ABORT                   (-120)
#define MI_INVALID_BASE                 (-121)
#define MI_MFRC_RESET                   (-122)
#define MI_WRONG_VALUE                  (-123)
#define MI_VALERR                       (-124)

#define MI_WRONG_MAC_TOKEN              (-149)
#define MI_WRONG_TOKEN                  (-150)
#define MI_NO_VALUE                     (-151)
#define MI_MFRC150                      (-152)
#define MI_MFRC170                      (-153)

#define MI_WRONG_BASEADDR               (-180)

#define MI_NO_ERROR_TEXT_AVAIL          (-199)

#define MI_DRIVER_FAILURE               (-254)

#define MI_INTERFACE_FAILURE            (-255)
#define MI_PROTOCOL_FAILURE             (-256)

#define MI_SERERR                       (-260)
#define MI_CALLOPEN                     (-261)
#define MI_RESERVED_BUFFER_OVERFLOW     (-262)
#define MI_RECBUF_OVERFLOW              MI_RESERVED_BUFFER_OVERFLOW

#define READER_ERR_BASE_END             (-999)

//////////////////////////////////////////////////////////////////////////////
// HostRdCom Error Codes                Base Address Start:     -1000
//                                      Base Address End:       -1100
//////////////////////////////////////////////////////////////////////////////
#define COM_ERR_BASE_START              (-1000)
#define COM_SUCCESS                     0
#define COM_ERROR                       (COM_ERR_BASE_START   -1)
#define COM_NO_INTERFACE_HANDLE         (COM_ERR_BASE_START   -2)
#define COM_INTERFACE_OPEN              (COM_ERR_BASE_START   -3)
#define COM_INTERFACE_NOT_OPEN          (COM_ERR_BASE_START   -4)
#define COM_CREATE_FILE_FAILED          (COM_ERR_BASE_START   -5)
#define COM_PURGE_COMM_FAILED           (COM_ERR_BASE_START   -6)
#define COM_GET_COMM_STATE_FAILED       (COM_ERR_BASE_START   -7)
#define COM_SETUP_COMM_FAILED           (COM_ERR_BASE_START   -8)
#define COM_SET_COMM_STATE_FAILED       (COM_ERR_BASE_START   -9)
#define COM_SET_COMM_MASK_FAILED        (COM_ERR_BASE_START  -10)
#define COM_SET_COMM_TIMEOUTS_FAILED    (COM_ERR_BASE_START  -11)
#define COM_WRONG_VALUE                 (COM_ERR_BASE_START  -12)
#define COM_WSASTARTUP_FAILED           (COM_ERR_BASE_START  -13)
#define COM_WSA_SOCKET_FAILED           (COM_ERR_BASE_START  -14)
#define COM_GETSOCKOPT_FAILED           (COM_ERR_BASE_START  -15)
#define COM_READER_NOT_IN_RANGE         (COM_ERR_BASE_START  -16)
#define COM_CONNECT_FAILED              (COM_ERR_BASE_START  -17)
#define COM_NEW_FAILED                  (COM_ERR_BASE_START  -18)
#define COM_INVALID_WT_HANDLE           (COM_ERR_BASE_START  -19) // WT - Worker thread
#define COM_START_WT_FAILED             (COM_ERR_BASE_START  -20) // WT - Worker thread
#define COM_INVALID_CB_HANDLE           (COM_ERR_BASE_START  -21) // CB - Callback
#define COM_LEN_OVERFLOW                (COM_ERR_BASE_START  -22)
#define COM_RS232_SERCOM_ERR            (COM_ERR_BASE_START  -23)
#define COM_RS232_SEND_CMD_NO_DLE_ERR   (COM_ERR_BASE_START  -24)
#define COM_RS232_SEND_DEVICE_ERR       (COM_ERR_BASE_START  -25)
#define COM_RS232_RESP_CMD_NAK_ERR      (COM_ERR_BASE_START  -26)
#define COM_TIMEOUT                     (COM_ERR_BASE_START  -27)
#define COM_RS232_RESP_TO_ERR           (COM_ERR_BASE_START  -28)
#define COM_RS232_RESP_OVERFLOW_ERR     (COM_ERR_BASE_START  -29)
#define COM_RS232_RECV_DEVICE_ERR       (COM_ERR_BASE_START  -30)
#define COM_RS232_RESP_UNDERFLOW_ERR    (COM_ERR_BASE_START  -31)
#define COM_RS232_DATALENGTH_ERR        (COM_ERR_BASE_START  -32)
#define COM_RS232_CHECKSUM_ERR          (COM_ERR_BASE_START  -33)
#define COM_RS232_TX_RX_SEQ_ERR         (COM_ERR_BASE_START  -34)
#define COM_RS232_COPY_DATA_ERR         (COM_ERR_BASE_START  -35)
#define COM_IRDA_SELECT_FAILED          (COM_ERR_BASE_START  -36)
#define COM_IRDA_SEND_TIMEOUT           (COM_ERR_BASE_START  -37)
#define COM_IRDA_SOCKET_NOT_READY       (COM_ERR_BASE_START  -38)
#define COM_IRDA_SEND_DEVICE_ERR        (COM_ERR_BASE_START  -39)
#define COM_IRDA_RECV_DEVICE_ERR        (COM_ERR_BASE_START  -40)
#define COM_IRDA_RECV_TIMEOUT           (COM_ERR_BASE_START  -41)
#define COM_IRDA_TX_RX_SEQ_ERR          (COM_ERR_BASE_START  -42)
#define COM_IRDA_COPY_DATA_ERR          (COM_ERR_BASE_START  -43)
#define COM_IRDA_LEN_ERR                (COM_ERR_BASE_START  -44)
#define COM_NO_PROTOCOL_SET             (COM_ERR_BASE_START  -45)
#define COM_USB_DLL_LOAD_ERR            (COM_ERR_BASE_START  -46)
#define COM_USB_MISSING_FCT_ADDR        (COM_ERR_BASE_START  -47)
#define COM_USB_SEND_DEVICE_ERR         (COM_ERR_BASE_START  -48)
#define COM_USB_RECV_DEVICE_ERR         (COM_ERR_BASE_START  -49)
#define COM_USB_TX_RX_SEQ_ERR           (COM_ERR_BASE_START  -50)
#define COM_USB_LEN_ERR                 (COM_ERR_BASE_START  -51)
#define COM_USB_COPY_DATA_ERR           (COM_ERR_BASE_START  -52)
#define COM_USB_NO_DEVICE_FOUND         (COM_ERR_BASE_START  -53)
#define COM_USB_SEND_TIMEOUT            (COM_ERR_BASE_START  -54)
#define COM_USB_RECV_TIMEOUT            (COM_ERR_BASE_START  -55)
#define COM_USB_FILE_NOT_FOUND          (COM_ERR_BASE_START  -56)
#define COM_USB_ACCESS_DENIED           (COM_ERR_BASE_START  -57)
#define COM_RS232_ETX_DLE_EXPECTED      (COM_ERR_BASE_START  -58)

#define COM_ERR_BASE_END                (COM_ERR_BASE_START  -99)

//////////////////////////////////////////////////////////////////////////////
// T=CL Error Codes                     Base Address Start:     -1100
//                                      Base Address End:       -1150
//////////////////////////////////////////////////////////////////////////////
#define TCL_ERR_BASE_START              (COM_ERR_BASE_END     -1)

#define TCL_OK                          0
#define TCL_NOTAGERR                    (TCL_ERR_BASE_START   -1)
#define TCL_CRCERR                      (TCL_ERR_BASE_START   -2)
#define TCL_PRITYERR                    (TCL_ERR_BASE_START   -3)
#define TCL_OTHERERR                    (TCL_ERR_BASE_START   -4)
#define TCL_SERNRERR                    (TCL_ERR_BASE_START   -5)
#define TCL_BITCOUNTERR                 (TCL_ERR_BASE_START   -6)
#define TCL_POLLING                     (TCL_ERR_BASE_START   -7)
#define TCL_RF_CHANNEL                  (TCL_ERR_BASE_START   -8)
#define TCL_MULTACT_DISABLED            (TCL_ERR_BASE_START   -9)
#define TCL_MULTACT_ENABLED             (TCL_ERR_BASE_START   -10)
#define TCL_CID_NOT_ACTIVE              (TCL_ERR_BASE_START   -11)
#define TCL_BITANTICOLL                 (TCL_ERR_BASE_START   -12)
#define TCL_UIDLEN                      (TCL_ERR_BASE_START   -13)
#define TCL_CIDINVALID                  (TCL_ERR_BASE_START   -14)
#define TCL_ATSLEN                      (TCL_ERR_BASE_START   -15)
#define TCL_NO_ATS_AVAILABLE            (TCL_ERR_BASE_START   -16)
#define TCL_ATS_ERROR                   (TCL_ERR_BASE_START   -17)
#define TCL_FATAL_PROTOCOL              (TCL_ERR_BASE_START   -18)
#define TCL_RECBUF_OVERFLOW             (TCL_ERR_BASE_START   -19)
#define TCL_SENDBYTENR                  (TCL_ERR_BASE_START   -20)
#define TCL_TRANSMERR_HALTED            (TCL_ERR_BASE_START   -21)
#define TCL_TRANSMERR_NOTAG             (TCL_ERR_BASE_START   -22)
#define TCL_BAUDRATE_NOT_SUPPORTED_PICC (TCL_ERR_BASE_START   -23)
#define TCL_CID_NOT_SUPPORTED           (TCL_ERR_BASE_START   -24)
#define TCL_NAD_NOT_SUPPORTED           (TCL_ERR_BASE_START   -25)
#define TCL_PROTOCOL_NOT_SUPPORTED      (TCL_ERR_BASE_START   -26)
#define TCL_PPS_FORMAT                  (TCL_ERR_BASE_START   -27)
#define TCL_ERROR                       (TCL_ERR_BASE_START   -28)
#define TCL_NADINVALID                  (TCL_ERR_BASE_START   -30)
#define TCL_OTHER_ERR                   (TCL_ERR_BASE_START   -31)
#define TCL_BAUDRATE_NOT_SUPPORTED_PCD  (TCL_ERR_BASE_START   -32)
#define TCL_CID_ACTIVE                  (TCL_ERR_BASE_START   -33)

#define TCL_ERR_BASE_END                (TCL_ERR_BASE_START   -49)

//////////////////////////////////////////////////////////////////////////////
// RdMUXError Codes                     Base Address Start:     -1200
//                                      Base Address End:       -1250
// Author: TR
//////////////////////////////////////////////////////////////////////////////
#define RdMUX_ERR_BASE_START            (TCL_ERR_BASE_END      -51)

#define RdMUX_OK												0
#define RdMUX_NO_RD_AVAIL								(RdMUX_ERR_BASE_START  -1)
#define RdMUX_RdINDEX_OUT_OF_RANGE			(RdMUX_ERR_BASE_START  -2)
#define RdMUX_MUXMODE_NOT_SUPPORTED_RM  (RdMUX_ERR_BASE_START  -3)
#define RdMUX_SELECTED_RD_NAVAIL				(RdMUX_ERR_BASE_START  -4)
#define RdMUX_UNKNOWN_PARAMIDX					(RdMUX_ERR_BASE_START  -5)
#define RdMUX_SELECTIONLIST_EMPTY				(RdMUX_ERR_BASE_START  -6)
#define RdMUX_CHANGES_TREATED						(RdMUX_ERR_BASE_START  -7)

#define RdMUX_ERR_BASE_END							(RdMUX_ERR_BASE_START  -49)





// Don't forget to provide error messages for added errors in MfErrNo.c!!
// At the end of a new added error block specify the next base address!!

// Next Base: -1250



// ---------------------------------------------------------------------------
//  FUNCTION: GetErrMsg
//        IN: err_nr    Error number for which the appropriate error message
//                      is needed
//       OUT: -
//    RETURN: Appropriate error message for passed error number
//   COMMENT: Searches the ErrList for the passed error number.
//            If the error number is found, the approriate error number is
//            return, otherwise "Unknown error" is returned.
// ---------------------------------------------------------------------------
DLLEXP_IMP char* GetErrMsg(short err_nr);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H

//////////////////////////////////////////////////////////////////////////////
//                             End of File
//////////////////////////////////////////////////////////////////////////////