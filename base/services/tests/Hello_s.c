/*** Autogenerated by WIDL 0.4-SVN from Hello.idl - Do not edit ***/
#include <string.h>

#include "Hello.h"

#ifndef DECLSPEC_HIDDEN
#define DECLSPEC_HIDDEN
#endif

#ifndef _WIN64

#ifndef USE_COMPILER_EXCEPTIONS

#include "wine/exception.h"
#undef RpcTryExcept
#undef RpcExcept
#undef RpcEndExcept
#undef RpcTryFinally
#undef RpcFinally
#undef RpcEndFinally
#undef RpcExceptionCode
#undef RpcAbnormalTermination

struct __exception_frame;
typedef int (*__filter_func)(struct __exception_frame *);
typedef void (*__finally_func)(struct __exception_frame *);

#define __DECL_EXCEPTION_FRAME \
    EXCEPTION_REGISTRATION_RECORD frame; \
    __filter_func                 filter; \
    __finally_func                finally; \
    sigjmp_buf                    jmp; \
    DWORD                         code; \
    unsigned char                 abnormal_termination; \
    unsigned char                 filter_level; \
    unsigned char                 finally_level;

struct __exception_frame
{
    __DECL_EXCEPTION_FRAME
};

static inline void __widl_unwind_target(void)
{
    struct __exception_frame *exc_frame = (struct __exception_frame *)__wine_get_frame();
    if (exc_frame->finally_level > exc_frame->filter_level)
    {
        exc_frame->abnormal_termination = 1;
        exc_frame->finally( exc_frame );
        __wine_pop_frame( &exc_frame->frame );
    }
    exc_frame->filter_level = 0;
    siglongjmp( exc_frame->jmp, 1 );
}

static DWORD __widl_exception_handler( EXCEPTION_RECORD *record,
                                       EXCEPTION_REGISTRATION_RECORD *frame,
                                       CONTEXT *context,
                                       EXCEPTION_REGISTRATION_RECORD **pdispatcher )
{
    struct __exception_frame *exc_frame = (struct __exception_frame *)frame;

    if (record->ExceptionFlags & (EH_UNWINDING | EH_EXIT_UNWIND | EH_NESTED_CALL))
    {
        if (exc_frame->finally_level && (record->ExceptionFlags & (EH_UNWINDING | EH_EXIT_UNWIND)))
        {
            exc_frame->abnormal_termination = 1;
            exc_frame->finally( exc_frame );
        }
        return ExceptionContinueSearch;
    }
    exc_frame->code = record->ExceptionCode;
    if (exc_frame->filter_level && exc_frame->filter( exc_frame ) == EXCEPTION_EXECUTE_HANDLER)
        __wine_rtl_unwind( frame, record, __widl_unwind_target );
    return ExceptionContinueSearch;
}

#define RpcTryExcept \
    if (!sigsetjmp( __frame->jmp, 0 )) \
    { \
        if (!__frame->finally_level) \
            __wine_push_frame( &__frame->frame ); \
        __frame->filter_level = __frame->finally_level + 1;

#define RpcExcept(expr) \
        if (!__frame->finally_level) \
            __wine_pop_frame( &__frame->frame ); \
        __frame->filter_level = 0; \
    } \
    else \

#define RpcEndExcept

#define RpcExceptionCode() (__frame->code)

#define RpcTryFinally \
    if (!__frame->filter_level) \
        __wine_push_frame( &__frame->frame ); \
    __frame->finally_level = __frame->filter_level + 1;

#define RpcFinally \
    if (!__frame->filter_level) \
        __wine_pop_frame( &__frame->frame ); \
    __frame->finally_level = 0;

#define RpcEndFinally

#define RpcAbnormalTermination() (__frame->abnormal_termination)

#define RpcExceptionInit(filter_func,finally_func) \
    do { \
        __frame->frame.Handler = __widl_exception_handler; \
        __frame->filter = (__filter_func)(filter_func); \
        __frame->finally = (__finally_func)(finally_func); \
        __frame->abnormal_termination = 0; \
        __frame->filter_level = 0; \
        __frame->finally_level = 0; \
    } while (0)

#else /* USE_COMPILER_EXCEPTIONS */

#define RpcExceptionInit(filter_func,finally_func) \
    do { (void)(filter_func); } while(0)

#define __DECL_EXCEPTION_FRAME \
    DWORD code;

#endif /* USE_COMPILER_EXCEPTIONS */

struct __server_frame
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
};

static int __server_filter( struct __server_frame *__frame )
{
    return (__frame->code == STATUS_ACCESS_VIOLATION) ||
           (__frame->code == STATUS_DATATYPE_MISALIGNMENT) ||
           (__frame->code == RPC_X_BAD_STUB_DATA) ||
           (__frame->code == RPC_S_INVALID_BOUND);
}

#define TYPE_FORMAT_STRING_SIZE 7
#define PROC_FORMAT_STRING_SIZE 13

typedef struct _MIDL_TYPE_FORMAT_STRING
{
    short Pad;
    unsigned char Format[TYPE_FORMAT_STRING_SIZE];
} MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
{
    short Pad;
    unsigned char Format[PROC_FORMAT_STRING_SIZE];
} MIDL_PROC_FORMAT_STRING;


static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

/*****************************************************************************
 * hello interface
 */

static RPC_DISPATCH_TABLE hello_v1_0_DispatchTable;
static const MIDL_SERVER_INFO hello_ServerInfo;

static const RPC_SERVER_INTERFACE hello___RpcServerInterface =
{
    sizeof(RPC_SERVER_INTERFACE),
    {{0x906b0ce0,0xc70b,0x1067,{0xb3,0x17,0x00,0xdd,0x01,0x06,0x62,0xda}},{1,0}},
    {{0x8a885d04,0x1ceb,0x11c9,{0x9f,0xe8,0x08,0x00,0x2b,0x10,0x48,0x60}},{2,0}},
    &hello_v1_0_DispatchTable,
    0,
    0,
    0,
    &hello_ServerInfo,
    0,
};
RPC_IF_HANDLE hello_v1_0_s_ifspec DECLSPEC_HIDDEN = (RPC_IF_HANDLE)& hello___RpcServerInterface;

static const MIDL_STUB_DESC hello_StubDesc;

struct __frame_hello_HelloProc
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    handle_t h1;
    unsigned char * pszString;
};

static void __finally_hello_HelloProc( struct __frame_hello_HelloProc *__frame )
{

    NdrPointerFree(
        &__frame->_StubMsg,
        (unsigned char *)__frame->pszString,
        (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[2]);

}

void __RPC_STUB hello_HelloProc( PRPC_MESSAGE _pRpcMessage )
{
    struct __frame_hello_HelloProc __f, * const __frame = &__f;

    NdrServerInitializeNew(
        _pRpcMessage,
        &__frame->_StubMsg,
        &hello_StubDesc);

    RpcExceptionInit( __server_filter, __finally_hello_HelloProc );
    __frame->pszString = 0;

    __frame->h1 = _pRpcMessage->Handle;

    RpcTryFinally
    {
        RpcTryExcept
        {
            if ((_pRpcMessage->DataRepresentation & 0x0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert(&__frame->_StubMsg, (PFORMAT_STRING)&__MIDL_ProcFormatString.Format[0]);


            NdrConformantStringUnmarshall(
                &__frame->_StubMsg,
                (unsigned char **)&__frame->pszString,
                (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[4],
                0);

            if (__frame->_StubMsg.Buffer > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        }
        RpcExcept(RPC_BAD_STUB_DATA_EXCEPTION_FILTER)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        RpcEndExcept

        HelloProc(
            __frame->h1,
            __frame->pszString);
    }
    RpcFinally
    {
        __finally_hello_HelloProc( __frame );
    }
    RpcEndFinally

    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

struct __frame_hello_Shutdown
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    handle_t h1;
};

static void __finally_hello_Shutdown( struct __frame_hello_Shutdown *__frame )
{

}

void __RPC_STUB hello_Shutdown( PRPC_MESSAGE _pRpcMessage )
{
    struct __frame_hello_Shutdown __f, * const __frame = &__f;

    NdrServerInitializeNew(
        _pRpcMessage,
        &__frame->_StubMsg,
        &hello_StubDesc);

    RpcExceptionInit( __server_filter, __finally_hello_Shutdown );

    __frame->h1 = _pRpcMessage->Handle;

    RpcTryFinally
    {
        RpcTryExcept
        {
            if ((_pRpcMessage->DataRepresentation & 0x0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert(&__frame->_StubMsg, (PFORMAT_STRING)&__MIDL_ProcFormatString.Format[8]);


            if (__frame->_StubMsg.Buffer > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        }
        RpcExcept(RPC_BAD_STUB_DATA_EXCEPTION_FILTER)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        RpcEndExcept

        Shutdown(
            __frame->h1);
    }
    RpcFinally
    {
        __finally_hello_Shutdown( __frame );
    }
    RpcEndFinally

    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

static const unsigned short hello_FormatStringOffsetTable[] =
{
    0,  /* HelloProc */
    8,  /* Shutdown */
};

static const MIDL_STUB_DESC hello_StubDesc =
{
    (void *)& hello___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    {
        0,
    },
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
};

static RPC_DISPATCH_FUNCTION hello_table[] =
{
    hello_HelloProc,
    hello_Shutdown,
    0
};
static RPC_DISPATCH_TABLE hello_v1_0_DispatchTable =
{
    2,
    hello_table
};

static const SERVER_ROUTINE hello_ServerRoutineTable[] =
{
    (SERVER_ROUTINE)HelloProc,
    (SERVER_ROUTINE)Shutdown,
};

static const MIDL_SERVER_INFO hello_ServerInfo =
{
    &hello_StubDesc,
    hello_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    hello_FormatStringOffsetTable,
    0,
    0,
    0,
    0
};

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
{
    0,
    {
/* 0 (parameter h1) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x0f,    /* FC_IGNORE */
/* 2 (parameter pszString) */
        0x4d,    /* FC_IN_PARAM */
        0x01,
        NdrFcShort(0x2),	/* type offset = 2 */
/* 6 (void) */
        0x5b,    /* FC_END */
        0x5c,    /* FC_PAD */
/* 8 (parameter h1) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x0f,    /* FC_IGNORE */
/* 10 (void) */
        0x5b,    /* FC_END */
        0x5c,    /* FC_PAD */
        0x0
    }
};

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
{
    0,
    {
        NdrFcShort(0x0),
/* 2 (unsigned char *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */
        0x22,    /* FC_C_CSTRING */
        0x5c, /* FC_PAD */
        0x0
    }
};


#else /* _WIN64 */

#ifndef USE_COMPILER_EXCEPTIONS

#include "wine/exception.h"
#undef RpcTryExcept
#undef RpcExcept
#undef RpcEndExcept
#undef RpcTryFinally
#undef RpcFinally
#undef RpcEndFinally
#undef RpcExceptionCode
#undef RpcAbnormalTermination

struct __exception_frame;
typedef int (*__filter_func)(struct __exception_frame *);
typedef void (*__finally_func)(struct __exception_frame *);

#define __DECL_EXCEPTION_FRAME \
    EXCEPTION_REGISTRATION_RECORD frame; \
    __filter_func                 filter; \
    __finally_func                finally; \
    sigjmp_buf                    jmp; \
    DWORD                         code; \
    unsigned char                 abnormal_termination; \
    unsigned char                 filter_level; \
    unsigned char                 finally_level;

struct __exception_frame
{
    __DECL_EXCEPTION_FRAME
};

static inline void __widl_unwind_target(void)
{
    struct __exception_frame *exc_frame = (struct __exception_frame *)__wine_get_frame();
    if (exc_frame->finally_level > exc_frame->filter_level)
    {
        exc_frame->abnormal_termination = 1;
        exc_frame->finally( exc_frame );
        __wine_pop_frame( &exc_frame->frame );
    }
    exc_frame->filter_level = 0;
    siglongjmp( exc_frame->jmp, 1 );
}

static DWORD __widl_exception_handler( EXCEPTION_RECORD *record,
                                       EXCEPTION_REGISTRATION_RECORD *frame,
                                       CONTEXT *context,
                                       EXCEPTION_REGISTRATION_RECORD **pdispatcher )
{
    struct __exception_frame *exc_frame = (struct __exception_frame *)frame;

    if (record->ExceptionFlags & (EH_UNWINDING | EH_EXIT_UNWIND | EH_NESTED_CALL))
    {
        if (exc_frame->finally_level && (record->ExceptionFlags & (EH_UNWINDING | EH_EXIT_UNWIND)))
        {
            exc_frame->abnormal_termination = 1;
            exc_frame->finally( exc_frame );
        }
        return ExceptionContinueSearch;
    }
    exc_frame->code = record->ExceptionCode;
    if (exc_frame->filter_level && exc_frame->filter( exc_frame ) == EXCEPTION_EXECUTE_HANDLER)
        __wine_rtl_unwind( frame, record, __widl_unwind_target );
    return ExceptionContinueSearch;
}

#define RpcTryExcept \
    if (!sigsetjmp( __frame->jmp, 0 )) \
    { \
        if (!__frame->finally_level) \
            __wine_push_frame( &__frame->frame ); \
        __frame->filter_level = __frame->finally_level + 1;

#define RpcExcept(expr) \
        if (!__frame->finally_level) \
            __wine_pop_frame( &__frame->frame ); \
        __frame->filter_level = 0; \
    } \
    else \

#define RpcEndExcept

#define RpcExceptionCode() (__frame->code)

#define RpcTryFinally \
    if (!__frame->filter_level) \
        __wine_push_frame( &__frame->frame ); \
    __frame->finally_level = __frame->filter_level + 1;

#define RpcFinally \
    if (!__frame->filter_level) \
        __wine_pop_frame( &__frame->frame ); \
    __frame->finally_level = 0;

#define RpcEndFinally

#define RpcAbnormalTermination() (__frame->abnormal_termination)

#define RpcExceptionInit(filter_func,finally_func) \
    do { \
        __frame->frame.Handler = __widl_exception_handler; \
        __frame->filter = (__filter_func)(filter_func); \
        __frame->finally = (__finally_func)(finally_func); \
        __frame->abnormal_termination = 0; \
        __frame->filter_level = 0; \
        __frame->finally_level = 0; \
    } while (0)

#else /* USE_COMPILER_EXCEPTIONS */

#define RpcExceptionInit(filter_func,finally_func) \
    do { (void)(filter_func); } while(0)

#define __DECL_EXCEPTION_FRAME \
    DWORD code;

#endif /* USE_COMPILER_EXCEPTIONS */

struct __server_frame
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
};

static int __server_filter( struct __server_frame *__frame )
{
    return (__frame->code == STATUS_ACCESS_VIOLATION) ||
           (__frame->code == STATUS_DATATYPE_MISALIGNMENT) ||
           (__frame->code == RPC_X_BAD_STUB_DATA) ||
           (__frame->code == RPC_S_INVALID_BOUND);
}

#define TYPE_FORMAT_STRING_SIZE 7
#define PROC_FORMAT_STRING_SIZE 13

typedef struct _MIDL_TYPE_FORMAT_STRING
{
    short Pad;
    unsigned char Format[TYPE_FORMAT_STRING_SIZE];
} MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
{
    short Pad;
    unsigned char Format[PROC_FORMAT_STRING_SIZE];
} MIDL_PROC_FORMAT_STRING;


static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

/*****************************************************************************
 * hello interface
 */

static RPC_DISPATCH_TABLE hello_v1_0_DispatchTable;
static const MIDL_SERVER_INFO hello_ServerInfo;

static const RPC_SERVER_INTERFACE hello___RpcServerInterface =
{
    sizeof(RPC_SERVER_INTERFACE),
    {{0x906b0ce0,0xc70b,0x1067,{0xb3,0x17,0x00,0xdd,0x01,0x06,0x62,0xda}},{1,0}},
    {{0x8a885d04,0x1ceb,0x11c9,{0x9f,0xe8,0x08,0x00,0x2b,0x10,0x48,0x60}},{2,0}},
    &hello_v1_0_DispatchTable,
    0,
    0,
    0,
    &hello_ServerInfo,
    0,
};
RPC_IF_HANDLE hello_v1_0_s_ifspec DECLSPEC_HIDDEN = (RPC_IF_HANDLE)& hello___RpcServerInterface;

static const MIDL_STUB_DESC hello_StubDesc;

struct __frame_hello_HelloProc
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    handle_t h1;
    unsigned char * pszString;
};

static void __finally_hello_HelloProc( struct __frame_hello_HelloProc *__frame )
{

    NdrPointerFree(
        &__frame->_StubMsg,
        (unsigned char *)__frame->pszString,
        (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[2]);

}

void __RPC_STUB hello_HelloProc( PRPC_MESSAGE _pRpcMessage )
{
    struct __frame_hello_HelloProc __f, * const __frame = &__f;

    NdrServerInitializeNew(
        _pRpcMessage,
        &__frame->_StubMsg,
        &hello_StubDesc);

    RpcExceptionInit( __server_filter, __finally_hello_HelloProc );
    __frame->pszString = 0;

    __frame->h1 = _pRpcMessage->Handle;

    RpcTryFinally
    {
        RpcTryExcept
        {
            if ((_pRpcMessage->DataRepresentation & 0x0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert(&__frame->_StubMsg, (PFORMAT_STRING)&__MIDL_ProcFormatString.Format[0]);


            NdrConformantStringUnmarshall(
                &__frame->_StubMsg,
                (unsigned char **)&__frame->pszString,
                (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[4],
                0);

            if (__frame->_StubMsg.Buffer > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        }
        RpcExcept(RPC_BAD_STUB_DATA_EXCEPTION_FILTER)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        RpcEndExcept

        HelloProc(
            __frame->h1,
            __frame->pszString);
    }
    RpcFinally
    {
        __finally_hello_HelloProc( __frame );
    }
    RpcEndFinally

    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

struct __frame_hello_Shutdown
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    handle_t h1;
};

static void __finally_hello_Shutdown( struct __frame_hello_Shutdown *__frame )
{

}

void __RPC_STUB hello_Shutdown( PRPC_MESSAGE _pRpcMessage )
{
    struct __frame_hello_Shutdown __f, * const __frame = &__f;

    NdrServerInitializeNew(
        _pRpcMessage,
        &__frame->_StubMsg,
        &hello_StubDesc);

    RpcExceptionInit( __server_filter, __finally_hello_Shutdown );

    __frame->h1 = _pRpcMessage->Handle;

    RpcTryFinally
    {
        RpcTryExcept
        {
            if ((_pRpcMessage->DataRepresentation & 0x0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert(&__frame->_StubMsg, (PFORMAT_STRING)&__MIDL_ProcFormatString.Format[8]);


            if (__frame->_StubMsg.Buffer > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        }
        RpcExcept(RPC_BAD_STUB_DATA_EXCEPTION_FILTER)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        RpcEndExcept

        Shutdown(
            __frame->h1);
    }
    RpcFinally
    {
        __finally_hello_Shutdown( __frame );
    }
    RpcEndFinally

    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const unsigned short hello_FormatStringOffsetTable[] =
{
    0,  /* HelloProc */
    8,  /* Shutdown */
};

static const MIDL_STUB_DESC hello_StubDesc =
{
    (void *)& hello___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    {
        0,
    },
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
};

static RPC_DISPATCH_FUNCTION hello_table[] =
{
    hello_HelloProc,
    hello_Shutdown,
    0
};
static RPC_DISPATCH_TABLE hello_v1_0_DispatchTable =
{
    2,
    hello_table
};

static const SERVER_ROUTINE hello_ServerRoutineTable[] =
{
    (SERVER_ROUTINE)HelloProc,
    (SERVER_ROUTINE)Shutdown,
};

static const MIDL_SERVER_INFO hello_ServerInfo =
{
    &hello_StubDesc,
    hello_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    hello_FormatStringOffsetTable,
    0,
    0,
    0,
    0
};

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
{
    0,
    {
/* 0 (parameter h1) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x0f,    /* FC_IGNORE */
/* 2 (parameter pszString) */
        0x4d,    /* FC_IN_PARAM */
        0x01,
        NdrFcShort(0x2),	/* type offset = 2 */
/* 6 (void) */
        0x5b,    /* FC_END */
        0x5c,    /* FC_PAD */
/* 8 (parameter h1) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x0f,    /* FC_IGNORE */
/* 10 (void) */
        0x5b,    /* FC_END */
        0x5c,    /* FC_PAD */
        0x0
    }
};

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
{
    0,
    {
        NdrFcShort(0x0),
/* 2 (unsigned char *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */
        0x22,    /* FC_C_CSTRING */
        0x5c, /* FC_PAD */
        0x0
    }
};


#endif /* _WIN64 */
