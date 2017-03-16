/*
IBSSS Trace 
This file defines the error handling and debugging messages settings for an ibsss server 

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/

#ifndef _IBSSS_TRACE
#define _IBSSS_TRACE

#define IBSSS_DEBUG_MESSAGES 1 
#define IBSSS_TRACE_OPCODES 0 
#define IBSSS_TRACE_TERMINATION 1 
#define IBSSS_TRACE_OPERATIONS 1 
#define IBSSS_TRACE_SESSIONS 1
#define IBSSS_TRACE_READ_WRITE_STATUS 1 
#define IBSSS_TRACE_READ_WRITE_MESSAGES 1 

#include <iostream>

void ibsssError(const char *msg);

#endif /*_IBSSS_TRACE*/

