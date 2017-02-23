#ifndef _MAIN_CLIENT_HEADER
#define _MAIN_CLIENT_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <bitset>
#include "ibsss_op_codes.h"
#include <errno.h>
#define IBSSS_DEBUG_MESSAGES 0
#define IBSSS_TRACE_OPCODES 1 

#define IBSSS_DEFAULT_HOSTNAME "localhost"
#define IBSSS_DEFAULT_PORT 4777

void ibsssError(const char *msg){
	std::cerr << "ERROR: " << msg << std::endl;
	exit(1);
}

#endif /*_MAIN_CLIENT_HEADER*/
