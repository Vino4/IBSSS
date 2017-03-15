/* 
IBSSS NodeServer

This file runs the ibsss serve noder

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#include "server.hh"
#include "ibsss_server_node.hh"
#include "ibsss_op_codes.hh"
#include "ibsss_error.hh"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_OPCODES)
		printOpCodes();
	
	int main_port = IBSSS_DEFAULT_PORT;	
	if (argc >= 2)
		main_port = atoi(argv[1]);

	Server_Node_Handle server;
	
	server.init(main_port);
	
	return 0; 
}
