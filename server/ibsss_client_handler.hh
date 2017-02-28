/* 
IBSSS Client Handler Header

This file defines the ibsss client handler specifications

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#ifndef _IBSSS_CLIENT_HANDLER_HEADER
#define _IBSSS_CLIENT_HANDLER_HEADER

#include "ibsss_restrictions.h"
#include "ibsss_client_handler.hh"
#include "ibsss_op_codes.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <vector>
#include <thread>
#include <sqlite3.h>
#include <ibsss_database.h>
#include <ibsss_session_token.h>
#include <ibsss_mutex.hh>
#include <algorithm>
#include <ibsss_error.hh>

/*
Client Handle classs
Used for managing each client connection
*/
class Client_Handle{

	public:
	
		/*
		Client_Handle()
		
		Initializes a client handle by:
			- Setting all strings to '\0'
			- Setting all status, descriptor and other integeral variables to -1 or 0 where needed
		
		Arguments:
			none
		Returns:
			none
		*/
		Client_Handle();
		
		/*
		killSession()
		**Thread Safe**
		- Closes TCP connection
		- Removes connection from connection manager
		- Deletes client handle from memory
		
		Arguments:
			none
		Returns:
			none
		*/
		void killSession();
		
		/*
		processConnection()
		
		Reads messages from the clients and responds by calling the appropriate handler functions.
		Functions may respond by doing the following:
			- Processing data (possibly from the ibsss database)
			- Sending back responses
			- Managing session states (possibly other sessions)
			
		Arguments:
			none
		Returns:
			none
		*/
		void processConnection(Client_Handle * client_handle);
		
		/*
		getSessionToken()
			
		Arguments:
			none
		Returns:
			string session token with IBSSS_SESSION_TOKEN_LENGTH length
		*/
		std::string getSessionToken();
		
		/*
		getThreadHandle()
			
		Arguments:
			none
		Returns:
			thread pointer to the thread running the connection processing function	
		*/
		std::thread * getThreadHandle();
		
		/*
		setClientDescriptor()
		      
		Sets client descriptor.
		The descritor will be used to read and write messages to the client through a TCP socket.
		
		Arguments:
		     int client descriptor 
		Returns:
			none
		*/
		void setClientDescriptor(int descriptor);
		
		/*
		getClientDescriptor()
			
		Returns client decritpor which can be used to read to, write from and manage a TCP socket.
		
		Arguments:
			none
		Returns:
			int client descriptor	
		*/
		int getClientDescriptor();
		
		/*
		generateToken()
		
		Creates a randomized string from the characters defined in char IBSSS_SESSION_TOKEN_ALLOWED_CHARACTERS[]
		The maximum index for the array must be defined as IBSSS_SESSION_TOKEN_CHARACTER_POOL_SIZE
		The token size length must be globally defined as IBSSS_SESSION_TOKEN_LENGTH
		
		Arguments:
			none
		Returns:
			none
		*/
		void generateToken();
		
		/*
		initClientSession()
		
		Initialize the client session by:
			- Setting the appropriate session variables
			- Generating session token
			- Starting session thread
		
		Arguments:
			- std::vector<Client_Handle*> * connection_manager, 
									a pointer to a vector referencing all client handles
			- int descriptor, socket descriptor to be used for writing to, reading from and managing a connection
		Returns:
			none
		*/
		void initClientSession(std::vector<Client_Handle*> * connections, int descriptor);
	
		/*
		establishLoggedinStatus()
	
		Enables the logged_in flag	
		
		Arguments:
			none
		Returns:
			none
		*/
		void establishLoggedinStatus();	
	
		/*
		establishLoggedoutStatus()
	
		Disables the logged_in flag	
		
		Arguments:
			none
		Returns:
			none
		*/
		void establishLoggedoutStatus();

		/*
		setAESKey(std::string key)
	
		Sets the symetric encryption key	
	
		Arguments:
			- std::string key, the symetric AES key	
		Returns:
			none
		*/
		void setAESKey(std::string key);

		/*
		Server_Handle::usernameIsValid()

		Validates the username to ensure that:
					- Username is not longer than IBSSS_GLOBAL_MAXIMUM_USERNAME_LENGTH
					- Username is not shorter than IBSSS_GLOBAL_MINIMUM_USERNAME_LENGTH
					- Username is composed of letters and numbers only
		Arguments:
			- std::string username
		Returns:
			int status
				1: success
				0: failure
		*/
		static int usernameIsValid(std::string username);

		/*
		Server_Handle::passwordIsValid()

		Validates the password to ensure that:
					- Password is not longer than IBSSS_GLOBAL_MAXIMUM_PASSWORD_LENGTH
					- Password is not shorter than IBSSS_GLOBAL_MINIMUM_PASSWORD_LENGTH
					- Password is composed of letters and numbers only
		Arguments:
			- std::string password 
		Returns:
			int status
				1: success
				0: failure
		*/
		static int passwordIsValid(std::string password);
	private:
		
		std::vector<Client_Handle*> * connections;
		int client_descriptor;
		std::thread * thread_handle;
		std::string AES_key;
		std::string ID;
		std::string username;
		std::string session_token;
		int logged_in;
};
	
#endif /*_IBSSS_CLIENT_HANDLER_HEADER*/
