#ifndef _MAIN_SERVER_HEADER
#define _MAIN_SERVER_HEADER

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

#define IBSSS_DEFAULT_PORT 4777
#define IBSSS_MAXIMUM_BENDING_CONNECTIONS 40

void ibsssError(const char *msg){
	std::cerr << "ERROR: " << msg << std::endl;
	exit(1);
}

/*
Initializes a multithreaded ISBBB server
Takes a port and and address 
Returns a socket descriptor for the server
*/
int initServer(struct sockaddr_in * server_address, int main_port);

#endif /*_MAIN_SERVER_HEADER*/
