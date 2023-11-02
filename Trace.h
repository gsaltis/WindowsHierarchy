/*****************************************************************************
 * FILE NAME    : Trace.h
 * DATE         : November 01 2023
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _trace_h_
#define _trace_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TRACE_FUNCTION_START()                          \
  {                                                     \
    printf("    ENTRY : %40s::%-30s : %4d\n",           \
           __FILE__, __FUNCTION__, __LINE__);           \
  }                                                     \
  
#define TRACE_FUNCTION_END()                            \
  {                                                     \
    printf("     EXIT : %40s::%-30s : %4d\n",           \
           __FILE__, __FUNCTION__, __LINE__);           \
  }                                                     \
  
#define TRACE_FUNCTION_LOCATION()                       \
  {                                                     \
    printf(" LOCATION : %40s::%-30s : %4d\n",           \
           __FILE__, __FUNCTION__, __LINE__);           \
  }                                                     \
  
#define TRACE_FUNCTION_INT(n)                           \
  {                                                     \
    printf("      INT : %40s::%-30s : %4d"              \
           " %s = %d\n",                                \
           __FILE__, __FUNCTION__, __LINE__,            \
           #n, n);                                      \
  }                                                     \
  
/*****************************************************************************!
 * Exported Data
 *****************************************************************************/

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

#endif /* _trace_h_*/