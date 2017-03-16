#ifndef _IBSSS_NODE_SERVER_HEADER
#define _IBSSS_NODE_SERVER_HEADER

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

#define IBSSS_MAXIMUM_BENDING_CONNECTIONS 40
extern volatile sig_atomic_t IBSSS_NODE_SERVER_IS_ALIVE;

class Server_Node_Handle {
	
	public:

		/*
		Server_Node_Handle()
		
		Creates a Server_Node_Handle

		Arguments:
			none
		Returns:
		      none
		*/
		Server_Node_Handle();
	
		/*
		Server_Node_Handle::shutdown()

		Shut the server down.
		Can be called with Ctrl + C interruption.

		Arguments:
			- int signal -- unused
		Returns:
		      none
		*/
		void shutdown();

		/*
		Server_Node_Handle::setDescriptor(int descriptor)
	
		Sets the server socket descriptor;
		Will be used later to write to, read from and maanage the main server socket.
		
		Arguments:
			int descriptor, main socket descriptor 
		Returns:
		      none
		*/
		void setDescriptor(int descriptor);

		/*
		Server_Node_Handle::init(int port)
	
		Initalizes the server by
			- Initalizing srand()
			- Opening the main server socket
			- Setting the main server signal handlers
			- Opening connection to the database

		Arguments:
			(int) port, main server port	
		Returns:
		      none
		*/
		void init(int port);

		/*
		Server_Node_Handle::runConnectionManager(Server_Node_Handle * server_handle)

		Manages server connections by:
			- Accepting connection to the main server sucket
			- Starting a new thread to handle every new client session 
		
		Arguments:
			Server_Node_Handle * server_handle, a pointer to a server handle	
		Returns:
		      none
		*/
		void runConnectionManager(Server_Node_Handle * server_handle);


	private:

		int main_socket, main_port;
		struct sockaddr_in server_address;
		std::thread * thread_handle;
		Stream_Handle stream_handle;
};

#endif /*_Ibsss_node_server_header*/
