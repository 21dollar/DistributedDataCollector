

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for My_int.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __My_int_h__
#define __My_int_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __My_int_INTERFACE_DEFINED__
#define __My_int_INTERFACE_DEFINED__

/* interface My_int */
/* [implicit_handle][version][uuid] */ 

int impersonation( 
    /* [string][in] */ unsigned char *name,
    /* [string][in] */ unsigned char *pass);

void to_serv( 
    /* [in] */ int sz_buff,
    /* [size_is][in] */ unsigned char *buff,
    /* [string][in] */ unsigned char *serv_path);

int to_cli( 
    /* [out][in] */ int *sz_buff,
    /* [size_is][out][in] */ unsigned char *send_buff,
    /* [string][in] */ unsigned char *serv_path,
    /* [in] */ int offset);

int del_f( 
    /* [string][in] */ unsigned char *serv_path);

void key_send( 
    /* [out][in] */ unsigned char pbPublicKey[ 1024 ],
    /* [in] */ int *dwPublicLen);

void msg_trade( 
    /* [out][in] */ unsigned char scom_buf[ 1024 ]);


extern handle_t My_int_handler;


extern RPC_IF_HANDLE My_int_v1_0_c_ifspec;
extern RPC_IF_HANDLE My_int_v1_0_s_ifspec;
#endif /* __My_int_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


