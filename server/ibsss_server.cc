/* 
IBSSS Main Server

This server manages the following:
	- Users, streams, stream keys and access control
	- Communication protocal

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/
#include "ibsss_client_handler.hh"
#include "ibsss_server.hh"
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
#include <sqlite3.h> 
#include <ibsss_database.h> 
#include <ibsss_session_token.h> 
#include <signal.h>
#include <ibsss_mutex.hh>
#include <algorithm>

volatile sig_atomic_t IBSSS_SERVER_IS_ALIVE = 1;

void ibsssSignalHandler(int signal_number){

	
	if (signal_number == SIGINT)
		IBSSS_SERVER_IS_ALIVE = 0;

	if (signal(SIGINT, ibsssSignalHandler) == SIG_ERR)
		ibsssError("Failed to set SIGINT handler");

}

/*
Server_Handle::Server_Handle()

Creates a Server_Handle

Arguments:
	none
Returns:
      none
*/
Server_Handle::Server_Handle(){}

/*
Server_Handle::shutdown()

Shut the server down.
Can be called with Ctrl + C interruption.

Arguments:
	int signal -- unused
Returns:
      none
*/
void Server_Handle::shutdown(){

	IBSSS_SERVER_IS_ALIVE = 0;
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....Terminating Server....-=]}" << std::endl;
	close(main_socket);
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....Closed Main Socket....-=]}" << std::endl;
	while(connections.size() > 0)
		connections[0]->killSession();
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....All Connections Have Been Terminated....-=]}" << std::endl;
	sqlite3_close(db);
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_TERMINATION)
		std::cout << "\n\n{[=-....Closed Database Connection....-=]}" << std::endl;
}

/*
Server_Handle::setDescriptor(int descriptor)

Sets the server socket descriptor;
Will be used later to write to, read from and maanage the main server socket.

Arguments:
	int descriptor, main socket descriptor 
Returns:
      none
*/
void Server_Handle::setDescriptor(int descriptor){
	main_socket = 0;
}

/*
Server_Handle::init()

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
void Server_Handle::init(int port){
	
	main_port = port;

	srand(time(0));

	if ((main_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ibsssError("could not open main socket");

	bzero((char *) &server_address, sizeof(struct sockaddr_in));
	
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(main_port);

	if (bind(main_socket, (struct sockaddr *) &server_address, sizeof(struct sockaddr_in)) < 0) 
		ibsssError("binding main address failed");

	if (listen(main_socket, IBSSS_MAXIMUM_BENDING_CONNECTIONS) < 0)
		ibsssError("listening to main socket failed");
	
	if (signal(SIGINT, ibsssSignalHandler) == SIG_ERR)
		ibsssError("Failed to set SIGINT handler");

	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ibsssError("Failed to set SIGPIPE handler");

	if(sqlite3_open(IBSSS_DATABASE_FILE_PATH, &db)){
		sqlite3_close(db);
		ibsssError("failed to establish database connection");
	}
	
	thread_handle = new std::thread(&Server_Handle::runConnectionManager, this, this);	

	while (IBSSS_SERVER_IS_ALIVE != 0){
		sleep(1);
	}

	shutdown();
}

/*
Server_Handle::runConnectionManager()

Manages server connections by:
	- Accepting connection to the main server sucket
	- Starting a new thread to handle every new client session 

Arguments:
	none
Returns:
      none
*/
void Server_Handle::runConnectionManager(Server_Handle * server_handle){
	IBSSS_SERVER_IS_ALIVE = 1;

	int client_descriptor;
	struct sockaddr_in client_address;
	socklen_t client_address_size;

	while (IBSSS_SERVER_IS_ALIVE){
		if ((client_descriptor = accept(main_socket, (struct sockaddr *) &client_address
								, &client_address_size)) < 0)
			ibsssError("failed to accept incoming connection");
		Client_Handle * new_connection = new Client_Handle;
		new_connection->initClientSession(&connections, client_descriptor);	
		connections.push_back(new_connection);
	      if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
	            std::cout << "Fully Initiated Session: [" << new_connection->getSessionToken() << "]\n" << std::endl;		
	}

}


