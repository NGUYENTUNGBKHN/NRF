/******************************************************************************/
/*! @addtogroup Group2
    @file       log.h
    @brief      
    @date       2024/03/19
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#ifndef _LOG_H_
#define _LOG_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CODE */
#include "stdint.h"

extern int logPrintf(const char *str);
extern void logInit();

#ifdef __cplusplus
}
#endif
#endif

