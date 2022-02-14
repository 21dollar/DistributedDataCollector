

/* this ALWAYS GENERATED file contains the RPC server stubs */


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

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>
#include "My_int.h"

#define TYPE_FORMAT_STRING_SIZE   49                                
#define PROC_FORMAT_STRING_SIZE   253                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _My_int_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } My_int_MIDL_TYPE_FORMAT_STRING;

typedef struct _My_int_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } My_int_MIDL_PROC_FORMAT_STRING;

typedef struct _My_int_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } My_int_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

extern const My_int_MIDL_TYPE_FORMAT_STRING My_int__MIDL_TypeFormatString;
extern const My_int_MIDL_PROC_FORMAT_STRING My_int__MIDL_ProcFormatString;
extern const My_int_MIDL_EXPR_FORMAT_STRING My_int__MIDL_ExprFormatString;

/* Standard interface: My_int, ver. 1.0,
   GUID={0x5b4be00c,0x3b74,0x4b1c,{0xa2,0x8a,0xe2,0x76,0xc5,0x3b,0xcb,0xfa}} */


extern const MIDL_SERVER_INFO My_int_ServerInfo;

extern const RPC_DISPATCH_TABLE My_int_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE My_int___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x5b4be00c,0x3b74,0x4b1c,{0xa2,0x8a,0xe2,0x76,0xc5,0x3b,0xcb,0xfa}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&My_int_v1_0_DispatchTable,
    0,
    0,
    0,
    &My_int_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE My_int_v1_0_s_ifspec = (RPC_IF_HANDLE)& My_int___RpcServerInterface;

extern const MIDL_STUB_DESC My_int_StubDesc;


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const My_int_MIDL_PROC_FORMAT_STRING My_int__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure impersonation */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 26 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 28 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 30 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter pass */

/* 32 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 34 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 36 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 40 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure to_serv */

/* 44 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x1 ),	/* 1 */
/* 52 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x3,		/* 3 */
/* 60 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x1 ),	/* 1 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter sz_buff */

/* 70 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 72 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter buff */

/* 76 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 78 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 80 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter serv_path */

/* 82 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 84 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 86 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Procedure to_cli */

/* 88 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 90 */	NdrFcLong( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x2 ),	/* 2 */
/* 96 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 98 */	NdrFcShort( 0x24 ),	/* 36 */
/* 100 */	NdrFcShort( 0x24 ),	/* 36 */
/* 102 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 104 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 106 */	NdrFcShort( 0x1 ),	/* 1 */
/* 108 */	NdrFcShort( 0x1 ),	/* 1 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter sz_buff */

/* 114 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 116 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter send_buff */

/* 120 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 122 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 124 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter serv_path */

/* 126 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 130 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter offset */

/* 132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 134 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure del_f */

/* 144 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x3 ),	/* 3 */
/* 152 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 160 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serv_path */

/* 170 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 172 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 174 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure key_send */

/* 182 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x4 ),	/* 4 */
/* 190 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 192 */	NdrFcShort( 0x42c ),	/* 1068 */
/* 194 */	NdrFcShort( 0x410 ),	/* 1040 */
/* 196 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 198 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbPublicKey */

/* 208 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 210 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 212 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Parameter dwPublicLen */

/* 214 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure msg_trade */

/* 220 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x5 ),	/* 5 */
/* 228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 230 */	NdrFcShort( 0x410 ),	/* 1040 */
/* 232 */	NdrFcShort( 0x410 ),	/* 1040 */
/* 234 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 236 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter scom_buf */

/* 246 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 248 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 250 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

			0x0
        }
    };

static const My_int_MIDL_TYPE_FORMAT_STRING My_int__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x0,	/* FC_RP */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x1 ),	/* 1 */
/* 14 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 18 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 20 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 22 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 24 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 26 */	
			0x11, 0x0,	/* FC_RP */
/* 28 */	NdrFcShort( 0x2 ),	/* Offset= 2 (30) */
/* 30 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 32 */	NdrFcShort( 0x1 ),	/* 1 */
/* 34 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 36 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 38 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 40 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 42 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 44 */	NdrFcShort( 0x400 ),	/* 1024 */
/* 46 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short My_int_FormatStringOffsetTable[] =
    {
    0,
    44,
    88,
    144,
    182,
    220
    };


static const MIDL_STUB_DESC My_int_StubDesc = 
    {
    (void *)& My_int___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    0,
    0,
    My_int__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

static const RPC_DISPATCH_FUNCTION My_int_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE My_int_v1_0_DispatchTable = 
    {
    6,
    (RPC_DISPATCH_FUNCTION*)My_int_table
    };

static const SERVER_ROUTINE My_int_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)impersonation,
    (SERVER_ROUTINE)to_serv,
    (SERVER_ROUTINE)to_cli,
    (SERVER_ROUTINE)del_f,
    (SERVER_ROUTINE)key_send,
    (SERVER_ROUTINE)msg_trade
    };

static const MIDL_SERVER_INFO My_int_ServerInfo = 
    {
    &My_int_StubDesc,
    My_int_ServerRoutineTable,
    My_int__MIDL_ProcFormatString.Format,
    My_int_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

