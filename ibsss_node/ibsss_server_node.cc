/* 
IBSSS Node Server

This server manages the following:
	- capturing footage
	- sending encrypted footage to client
Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#include "ibsss_stream_handler.hh"
#include "ibsss_server_node.hh"
#include "ibsss_op_codes.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <thread>
#include <ibsss_session_token.h> 
#include <signal.h>
#include <ibsss_mutex.hh>
#include <algorithm>
#include <errno.h>

volatile sig_atomic_t IBSSS_SERVER_IS_ALIVE = 1;

void ibsssSignalHandler(int signal_number){
	if (signal_number == SIGINT)
		IBSSS_SERVER_IS_ALIVE = 0;

	if (signal(SIGINT, ibsssSignalHandler) == SIG_ERR)
		ibsssError("Failed to set SIGINT handler");

}

/*
Server_Node_Handle::Server_Node_Handle()

Creates a Server_Node_Handle

Arguments:
	none
Returns:
      none
*/
Server_Node_Handle::Server_Node_Handle(){}

/*
Server_Node_Handle::shutdown()

Shut the server down.
Can be called with Ctrl + C interruption.

Arguments:
	int signal -- unused
Returns:
      none
*/
void Server_Node_Handle::shutdown(){
	IBSSS_SERVER_IS_ALIVE = 0;
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....Terminating Server....-=]}" << std::endl;
	close(main_socket);
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....Closed Main Socket....-=]}" << std::endl;
	stream_handle.killSession();
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....All Connections Have Been Terminated....-=]}" << std::endl;
}

/*
Server_Node_Handle::setDescriptor(int descriptor)

Sets the server socket descriptor;
Will be used later to write to, read from and maanage the main server socket.

Arguments:
	int descriptor, main socket descriptor 
Returns:
      none
*/
void Server_Node_Handle::setDescriptor(int descriptor){
	main_socket = 0;
}

/*
Server_Node_Handle::init()

Initalizes the server by
	- Initalizing srand()
	- Opening the main server socket
	- Setting the main server signal handlers
	- Opening connection to the database

Arguments:
	none
Returns:
      none
*/
void Server_Node_Handle::init(int port){
	
	std::cout << "{[=-....Initializing Server....-=]}" << std::endl;
	
	main_port = port;

	srand(time(0));

	std::cout << "[Server Initializer]: Opening main port..";
	if ((main_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ibsssError("\ncould not open main socket");

	bzero((char *) &server_address, sizeof(struct sockaddr_in));
	
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(main_port);

	if (bind(main_socket, (struct sockaddr *) &server_address, sizeof(struct sockaddr_in)) < 0) 
		ibsssError("\nbinding main address failed");
	std::cout << "Done" << std::endl;

	std::cout << "[Server Initializer]: Initializing Listener..";
	if (listen(main_socket, IBSSS_MAXIMUM_BENDING_CONNECTIONS) < 0)
		ibsssError("\nlistening to main socket failed");
	std::cout << "Done (socket [" << main_socket  <<"])" << std::endl;
	
	std::cout << "[Server Initializer]: Setting signal handlers..";
	if (signal(SIGINT, ibsssSignalHandler) == SIG_ERR)
		ibsssError("\nFailed to set SIGINT handler");

	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ibsssError("\nFailed to set SIGPIPE handler");
	std::cout << "Done" << std::endl;
	
	std::cout << "[Server Initializer]: Starting Connection Manager..";
	thread_handle = new std::thread(&Server_Node_Handle::runConnectionManager, this, this);	
	std::cout << "Done" << std::endl;

	std::cout << "[Server Initializer]: Fully Initialized Server" << std::endl;
	while (IBSSS_SERVER_IS_ALIVE != 0){
		sleep(1);
	}

	shutdown();
}

/*

Manages server connections by:
	- Accepting connection to the main server sucket
	- Starting a new thread to handle every new client session 

Arguments:
	none
Returns:
      none
*/
void Server_Node_Handle::runConnectionManager(Server_Node_Handle * server_handle){

	IBSSS_SERVER_IS_ALIVE = 1;

	int client_descriptor;
	struct sockaddr_in client_address;
	socklen_t client_address_size = sizeof(client_address);

	stream_handle.initStreamSession();

	while (IBSSS_SERVER_IS_ALIVE){
		std::cout << "Accepting connections on socket: " << main_socket << std::endl;
		if ((client_descriptor = accept(main_socket, (struct sockaddr *) &client_address
								, &client_address_size)) < 0){
			std::cout << "failed to accept connection on socket [" << main_socket << "]" << std::endl
				  << "ERROR: " << errno << std:: endl;
			continue;
		}
	
		stream_handle.addConnection(client_descriptor); 
	
		if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
		std::cout << "Fully Initiated Session: [" << client_descriptor << "]\n" << std::endl;		
	}

}


