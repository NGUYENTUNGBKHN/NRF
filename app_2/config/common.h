/******************************************************************************/
/*! @addtogroup Group2
    @file       common.h
    @brief      
    @date       2023/06/29
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#ifndef _COMMON_H_
#define _COMMON_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CODE */
typedef enum APP_ERROR_E
{
    APP_ERROR_OK,
    APP_ERROR_EXISTED,
    APP_ERROR_FAIL,
    APP_ERROR_TIMEOUT
}app_error_t;


#ifdef __cplusplus
}
#endif
#endif
