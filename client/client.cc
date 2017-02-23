/* 
IBSSS Main Client 

This client the following:
	- Communication protocal
	- Stream keys and stream access
	- User settings and permissions
Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/
#include "client.hh"
#include "ibsss_op_codes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <bitset>
#include <netdb.h>

int main(int argc, char *argv[])
{
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_OPCODES)
		printOpCodes();
	

	int main_socket, server_port, out;
	struct sockaddr_in server_address;
	struct hostent * server;
	char buffer[4096];
	buffer[0] = 'H';
	buffer[1] = 'e';
	buffer[2] = 'l';
	buffer[3] = 'l';
	buffer[4] = 'o';
	buffer[5] = '\0';
	
	if (argc >= 3){
		server = gethostbyname(argv[1]);
		server_port = atoi(argv[2]);
	} else {
		server = gethostbyname(IBSSS_DEFAULT_HOSTNAME);
		server_port = IBSSS_DEFAULT_PORT;	
	}
	
	main_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (main_socket < 0) 
		ibsssError("could not open main socket");
	bzero((char *) &server_address, sizeof(server_address));

	bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(server_port);

	if (connect(main_socket,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) 
		ibsssError("failed to establish a connection to the server");

      if ((out = write(main_socket, &buffer, 6)) < 0)
            ibsssError("failed to write");

      if ((out = read(main_socket, buffer, 9)) < 0)
            ibsssError("failed to read");

	std::cout << buffer << std::endl;

	close(main_socket);
	
	return 0; 
}
