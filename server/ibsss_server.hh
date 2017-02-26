#ifndef _IBSSS_SERVER_HEADER
#define _IBSSS_SERVER_HEADER

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

#define IBSSS_MAXIMUM_BENDING_CONNECTIONS 40
extern volatile sig_atomic_t IBSSS_SERVER_IS_ALIVE;

class Server_Handle {
	
	public:

		/*
		Server_Handle()
		
		Creates a Server_Handle

		Arguments:
			none
		Returns:
		      none
		*/
		Server_Handle();
	
		/*
		shutdown()

		Shut the server down.
		Can be called with Ctrl + C interruption.

		Arguments:
			- int signal -- unused
		Returns:
		      none
		*/
		void shutdown();

		/*
		setDescriptor(int descriptor)
	
		Sets the server socket descriptor;
		Will be used later to write to, read from and maanage the main server socket.
		
		Arguments:
			int descriptor, main socket descriptor 
		Returns:
		      none
		*/
		void setDescriptor(int descriptor);

		/*
		init(int port)
	
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
		runConnectionManager(Server_Handle * server_handle)

		Manages server connections by:
			- Accepting connection to the main server sucket
			- Starting a new thread to handle every new client session 
		
		Arguments:
			Server_Handle * server_handle, a pointer to a server handle	
		Returns:
		      none
		*/
		void runConnectionManager(Server_Handle * server_handle);
	private:

		int main_socket, main_port;
		struct sockaddr_in server_address;
		std::thread * thread_handle;
		std::vector<Client_Handle*> connections;
		sqlite3 *db;
};

#endif /*_IBSSS_SERVER_HEADER*/
