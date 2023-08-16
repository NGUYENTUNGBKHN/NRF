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
typedef enum STA_CODE_E
{
    STA_CODE_OK,
    STA_CODE_EXISTED,
    STA_CODE_FAIL,
    STA_CODE_TIMEOUT
}sta_code_t;


#ifdef __cplusplus
}
#endif
#endif
