/* 
IBSSS Server Connection Handler Header

This file defines the ibsss server connetion handler specifications

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#ifndef _IBSSS_SERVER_CONNECTION_HANDLER_HEADER
#define _IBSSS_SERVER_CONNECTION_HANDLER_HEADER

#include "ibsss_restrictions.h"
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
#include <ibsss_session_token.h>
#include <ibsss_mutex.hh>
#include <algorithm>
#include <ibsss_error.hh>
#include <netdb.h>

#define IBSSS_DEFAULT_HOSTNAME "128.223.6.25"
#define IBSSS_DEFAULT_PORT 4774

#define ibsssReadMessage(descriptor, buffer, length, status)		\
												\
	if ((status = read(descriptor, buffer, length)) < 0)			\
		ibsssError("failed to read");						\
												\
	if (IBSSS_TRACE_READ_WRITE_STATUS)						\
		std::cout << "Read Status: " << status << std::endl;		\
												\
	if (status == 0)									\
		return 0;

#define ibsssWriteMessage(descriptor, buffer, length, status)		\
												\
	if ((status = write(descriptor, buffer, length)) < 0)			\
		ibsssError("failed to write");					\
												\
	if (IBSSS_TRACE_READ_WRITE_STATUS)						\
		std::cout << "Write Status: " << status << std::endl;		\
												\
	if (status == 0)									\
		return 0;

#define ibsssAnnounceMessage(token, length, message)				\
	std::cout << "[" << token << "]["						\
	<< length << "]: "								\
	<< message										\
	<< std::endl;

/*
Server Connection Handle classs
Used for communicating with the main server 
*/
class Server_Connection_Handle{

	public:
	
		/*
		Server_Connection_Handle()
		
		Initializes a server connetion handle by:
			- Setting default hostname and port 
			- Setting all strings to '\0'
			- Setting all status, descriptor and other integeral variables to -1 or 0 where needed
		
		Arguments:
			none
		Returns:
			none
		*/
		Server_Connection_Handle();
		
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

		/*
		Client_Handle::connect()

		Connects to server. Init must be called before any calls to this function
		Calls to setPort and setHostname are optional.
		If no Port or Hostname are set, IBSSS_DEFAULT_HOSTNAME and IBSSS_DEFAULT_PORT will be used.
		(Server_Connection_Handle) conenction will maintane the connection descriptor 

		Initialize the server connetion session by:
			- Setting the appropriate session variables
			- Sends operation hello to the server
			- Establishing the secure link

		Arguments:
			none
		Returns:
		     int status
				1: Success
				0: Failure
		*/
		int connect();


		/*
		killSession()
			- Closes TCP connection
			- Removes streams from stream manager
			- Deletes server connetion handle from memory
		
		Arguments:
			none
		Returns:
			none
		*/
		void killSession();
	
		/*
		setSessionToken()
			
		Arguments:
			string session token with IBSSS_SESSION_TOKEN_LENGTH length
		Returns:
			none
		*/
		void setSessionToken(std::string new_session_token);	

		/*
		getSessionToken()
			
		Arguments:
			none
		Returns:
			string session token with IBSSS_SESSION_TOKEN_LENGTH length
		*/
		std::string getSessionToken();
		
        /*
        getUsername()

        Arguments:
            none
        Returns:
            std::string username
        */
        std::string getUsername();

		/*
		setConnectionDescriptor()
		      
		Sets server connetion descriptor.
		The descritor will be used to read and write messages to the server_connetion through a TCP socket.
		
		Arguments:
		     int server connetion descriptor 
		Returns:
			none
		*/
		void setConnectionDescriptor(int descriptor);
		
		/*
		getConnectionDescriptor()
			
		Returns server connetion decritpor which can be used to read to, write from and manage a TCP socket.
		
		Arguments:
			none
		Returns:
			int server connetion descriptor	
		*/
		int getConnectionDescriptor();
		
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
        Client_Handle::establishDisonnected()

        Disables the connected flag

        Arguments:
            none
        Returns:
            none
        */
        void establishDisonnectedStatus();
        /*
        Client_Handle::establishConnected()

        Enables the connected flag

        Arguments:
            none
        Returns:
            none
        */
        void establishConnectedStatus();
        /*
        isConnected();
        Gets connection status

        Arguments:
            none
        Returns:
            int connection status
                1: securely connected
                0: not connected
        */
        int isConnected();


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
        setUsername(std::string username)

        Sets the username

        Arguments:
            - std::string username
        Returns:
            none
        */
        void setUsername(std::string key);

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

		Initiates server_connetion handshake

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
		int operationHello();

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
			std::string username, std::string password, std::string email
		Returns:
			none
		*/
		int operationCreateUser(std::string username, std::string password, std::string email);

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
			std::string username, std::string password
		Returns:
			none
		*/
		int operationLogin(std::string username, std::string password);

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
		int operationLogout();

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
		int operationRequestStreamLinks();

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
		int operationRequestStreamKey();

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
		int operationChangePassword(std::string username, std::string old_password, std::string new_password);

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
		int operationForgotPassword(std::string username, std::string email);

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
		int operationForgotUsername(std::string email);

	private:
	
		struct hostent * server_hostname;	
		int server_port;
		struct sockaddr_in server_address;
		int connected_status;
		int server_connection_descriptor;
		std::string AES_key;
		std::string username;
		std::string session_token;
		int secured_status;
		int logged_in_status;
};
	
#endif /*_IBSSS_SERVER_CONNECTION_HANDLER_HEADER*/
