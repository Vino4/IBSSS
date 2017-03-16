/* 
IBSSS Client Handler Header

This file defines the ibsss client handler specifications

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#ifndef _IBSSS_CLIENT_HANDLER_HEADER
#define _IBSSS_CLIENT_HANDLER_HEADER
#include "ibsss_database_handler.hh"
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

#define ibsssConnectionDropped(statement) std::cout << statement << std::endl; break

#define ibsssReadMessage(descriptor, buffer, length, status)		\
												\
	if ((status = read(descriptor, buffer, length)) < 0)			\
		ibsssError("failed to read");						\
												\
	if (IBSSS_TRACE_READ_WRITE_STATUS)						\
		std::cout << "Read Status: " << status << std::endl;		\
												\
	if (status == 0)									\
		return;

#define ibsssWriteMessage(descriptor, buffer, length, status)		\
												\
	if ((status = write(descriptor, buffer, length)) < 0)			\
		ibsssError("failed to write");					\
												\
	if (IBSSS_TRACE_READ_WRITE_STATUS)						\
		std::cout << "Write Status: " << status << std::endl;		\
												\
	if (status == 0)									\
		return;

#define ibsssAnnounceMessage(token, length, message)				\
	std::cout << "[" << token << "]["						\
	<< length << "]: "								\
	<< message										\
	<< std::endl;

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
		getAESKey(std::string key)

		returns the symetric encryption key

		Arguments:
			none
		Returns:
			- std::string key, the symetric AES key
		*/
		std::string getAESKey();
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
		Client_Handle::establishSecuredStatus()

		Enables the secured flag

		Arguments:
			none
		Returns:
			none
		*/
		void establishSecuredStatus();
	
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

		/*
		Client_Handle::operationHello()

		Initiates client handshake

		Receives (in order):
			- (int) AES Key Length
			- char[AES Key Length] AES Key
		
		Performs:
			- set Client_Handle AES_key

		Sends: 
			- (unsigned char) IBSSS_OP_SUCCESS
			OR
			- (unsigned char) IBSSS_OP_FAILURE

		Arguments:
			none
		Returns:
			none
		*/
		void operationHello();

		/*
		Client_Handle::operationCreateUser()

		creates a new user with login details

		Receives (in order):
			- (int) User ID length
			- char[User ID Length] User ID
			- (int) Password Length
			- char[Password Length] Password
			- (int) Email Address Length
			- char[Email Length] Email

		Performs:
			- set User ID, Password, Email

		Sends (in order)
			- (unsigned char) IBSSS_OP_SUCCESS

		Arguments:
			none
		Returns:
			none
		*/
		void operationCreateUser();

		/*
		Client_Handle::operationLogin()

		creates a new user with login details

		Receives (in order):
			- (int) User ID length
			- char[User ID Length] User ID
			- (int) Password Length
			- char[Password Length] Password
		
		Performs:
			- authenticate User
		
		Sends (in order)
			- (unsigned char) IBSSS_OP_SUCCESS
			OR
			- (unsigned char) IBSSS_OP_FAILURE
		Arguments:
			none
		Returns:
			none
		*/
		void operationLogin();

		/*
		Client_Handle::operationLogout()

		creates a new user with login details
		
		Receives: 
			- char[IBSSS_SESSION_TOKEN_LENGTH] ibsss session token 

		Performs:
			- ends the session 

		Sends (in order)
			- (unsigned char) IBSSS_OP_SUCCESS
			OR
			- (unsigned char) IBSSS_OP_FAILURE

		Arguments:
			none
		Returns:
			none
		*/
		void operationLogout();

		/*
		Client_Handle::operationRequestStreamLinks()

		Sends links to all the streams to the user
		
		Receives: 
			- char[IBSSS_SESSION_TOKEN_LENGTH] ibsss session token

		Performs:
			- look up the database for stream links and dilver them to the user  

		Sends (in order)
			- (int) number of streams 
				for each stream:
					- (int) stream id 
					- (int) stream link length
					- (string) stream link
			
		Arguments:
			none
		Returns:
			none
		*/
		void operationRequestStreamLinks();

		/*
		Client_Handle::operationRequestStreamKey()

		Request stream key for a certain stream
		
		Receives: 
			- char[IBSSS_SESSION_TOKEN_LENGTH] ibsss session token 
			- (int) stream id

		Performs:
			- checks user priviliges for the stream
			- if autherized to view, provides stream key to user 

		Sends (in order)
			- (int) AES Key length 
			- char[AES Key Length] AES Key 

		Arguments:
			none
		Returns:
			none
		*/
		void operationRequestStreamKey();

		/*
		Client_Handle::operationChangePassword()

		creates a new user with login details
		
		Receives: 
			- (int) User ID length
			- char[User ID Length] User ID
			- (int) Old Password Length
			- char[Old Password Length] Old Password
			- (int) New Password Length
			- char[New Password Length] New Password

		Performs:
			- changes the password in the database 

		Sends (in order)
			- (unsigned char) IBSSS_OP_SUCCESS
			OR
			- (unsigned char) IBSSS_OP_FAILURE

		Arguments:
			none
		Returns:
			none
		*/
		void operationChangePassword();

		/*
		Client_Handle::operationForgotPassword()

		Restore user password

		Receives: 
			- (int) User ID length
			- char[User ID Length] User ID
			- (int) Email 
			- char[Email Length] Email 

		Performs:
			creates a new random password, stores it into the database and sends it to the user.

		Sends (in order)
			- (unsigned char) IBSSS_OP_SUCCESS
			OR
			- (unsigned char) IBSSS_OP_FAILURE

		Arguments:
			none
		Returns:
			none
		*/
		void operationForgotPassword();

		/*
		Client_Handle::operationForgotUsername()

		restore user's username
		
		Receives: 
			- (int) Email 
			- char[Email Length] Email 

		Performs:
			- email username to user's email 

		Sends (in order)
			- (unsigned char) IBSSS_OP_SUCCESS
			OR
			- (unsigned char) IBSSS_OP_FAILURE

		Arguments:
			none
		Returns:
			none
		*/
		void operationForgotUsername();
	private:
		
		Database_Handle database_handle;
		std::vector<Client_Handle*> * connections;
		int client_descriptor;
		std::thread * thread_handle;
		std::string AES_key;
		std::string ID;
		std::string username;
		std::string session_token;
		int secured_status;
		int logged_in_status;
};
	
#endif /*_IBSSS_CLIENT_HANDLER_HEADER*/
