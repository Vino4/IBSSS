#ifndef _IBSSS_CLIENT_HEADER
#define _IBSSS_CLIENT_HEADER

#include "ibsss_server_handler.hh"
#include "ibsss_client.hh"
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

extern volatile sig_atomic_t IBSSS_CLIENT_IS_ALIVE;

class Client_Handle {
	
	public:

		/*
		Client_Handle()
		
		Creates a Client_Handle

		Arguments:
			none
		Returns:
		      none
		*/
		Client_Handle();
	
		/*
		Client_Handle::shutdown()

		Shut the client down.
		Can be called with Ctrl + C interruption.

		Arguments:
			- int signal -- unused
		Returns:
		      none
		*/
		void shutdown();

		/*
		Client_Handle::setHostname(std::string hostname)
	
		Sets the server hostname;
		Will be used later to establish a connection to the server.
		
		Arguments:
			string hostname	
		Returns:
		      none
		*/
		void setHostname(std::string hostname);

		/*
		Client_Handle::setPort(int port)
	
		Sets the server port;
		Will be used later to establish a connection to the server.
		*if not called, IBSSS_DEFAULT_HOSTNAME will be used		
		
		Arguments:
			int port
		Returns:
		      none
		*/
		void setPort(int port);
		
		/*
		Client_Handle::setDescriptor(int descriptor)
	
		Sets the client socket descriptor;
		Will be used later to write to, read from and manage the main client socket.
		*if not called, IBSSS_DEFAULT_PORT will be used		
		
		Arguments:
			int descriptor, main socket descriptor 
		Returns:
		      none
		*/
		void setDescriptor(int descriptor);

		/*
		Client_Handle::init()
	
		Initalizes the connection to the server by
			- Initalizing srand()
			- Initializing status variables
		Arguments:
			none
		Returns:
		      none
		*/
		void init();

		/*
		Client_Handle::connect()

		Connects to server. Init must be called before any calls to this function
		Calls to setPort and setHostname are optional.
		If no Port or Hostname are set, IBSSS_DEFAULT_HOSTNAME and IBSSS_DEFAULT_PORT will be used.
		(Server_Connection_Handle) conenction will maintane the connection descriptor 

		Arguments:
			none
		Returns:
		      none
		*/
		void connect();


	private:

		int main_socket, main_port;
		int connected_status;
		struct sockaddr_in server_address;
		struct hostent * server;
		Server_Connection_Handle connection;
};

#endif /*_IBSSS_CLIENT_HEADER*/
