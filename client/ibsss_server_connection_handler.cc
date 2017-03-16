/* 
IBSSS Client Handler 

This file defines the ibsss client handler class and functionlity

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/
#include "ibsss_restrictions.h"
#include "ibsss_server_connection_handler.hh"
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
#include <ibsss_session_token.h> 
#include <ibsss_mutex.hh>
#include <algorithm>
#include <ibsss_error.hh>
#include <netdb.h>

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
Server_Connection_Handle::Server_Connection_Handle(){
     		server_hostname = gethostbyname(IBSSS_DEFAULT_HOSTNAME);	
		server_port = IBSSS_DEFAULT_PORT;
		server_connection_descriptor = -1;
            AES_key = "\0";
		username = "\0";
            session_token = "\0";
            secured_status = 0;
            logged_in_status = 0;
            connected_status = 0;
}

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
void Server_Connection_Handle::killSession(){
	close(server_connection_descriptor);	
    server_connection_descriptor = -1;
        AES_key.assign("\0");
    username.assign("\0");
        session_token.assign("\0");
        secured_status = 0;
        logged_in_status = 0;
        connected_status = 0;

}

/*
setSessionToken()
	
Arguments:
	string session token with IBSSS_SESSION_TOKEN_LENGTH length
Returns:
	none
*/
void Server_Connection_Handle::setSessionToken(std::string new_session_token){
	session_token.assign(new_session_token);
}

/*
getSessionToken()
	
Arguments:
	none
Returns:
	string session token with IBSSS_SESSION_TOKEN_LENGTH length
*/
std::string Server_Connection_Handle::getSessionToken(){
	return session_token;
}

/*
getUsername()

Arguments:
    none
Returns:
    std::string username
*/
std::string Server_Connection_Handle::getUsername(){
    return username;
}

/*
setConnectionDescriptor()
      
Sets server connetion descriptor.
The descritor will be used to read and write messages to the server_connetion through a TCP socket.

Arguments:
     int server connetion descriptor 
Returns:
	none
*/
void Server_Connection_Handle::setConnectionDescriptor(int descriptor){
	server_connection_descriptor = descriptor;
}

/*
getConnectionDescriptor()
	
Returns server connetion decritpor which can be used to read to, write from and manage a TCP socket.

Arguments:
	none
Returns:
	int server connetion descriptor	
*/
int Server_Connection_Handle::getConnectionDescriptor(){
	return server_connection_descriptor;
}

/*
connect()

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
int Server_Connection_Handle::connect(){
	
      server_connection_descriptor= socket(AF_INET, SOCK_STREAM, 0);
      if (server_connection_descriptor < 0)
            ibsssError("could not open server connection socket");
      bzero((char *) &server_address, sizeof(server_address));

      bcopy((char *)server_hostname->h_addr, (char *)&server_address.sin_addr.s_addr, server_hostname->h_length);
      server_address.sin_family = AF_INET;
      server_address.sin_port = htons(server_port);

      if (::connect(server_connection_descriptor,(struct sockaddr *) &server_address,sizeof(server_address)) < 0)
            ibsssError("failed to establish a connection to the server");

	return operationHello();

}

/*
Client_Handle::establishSecuredStatus()

Enables the secured flag

Arguments:
	none
Returns:
	none
*/
void Server_Connection_Handle::establishSecuredStatus(){
	secured_status = 1;
}

/*
Client_Handle::establishDisonnectedStatus()

Disables the connected flag

Arguments:
    none
Returns:
    none
*/
void Server_Connection_Handle::establishDisonnectedStatus(){
    secured_status = 0;
}

/*
Client_Handle::establishConnectedStatus()

Enables the connected flag

Arguments:
    none
Returns:
    none
*/
void Server_Connection_Handle::establishConnectedStatus(){
    secured_status = 1;
}
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
int Server_Connection_Handle::isConnected(){
    return connected_status;
}


/*
establishLoggedinStatus()

Enables the logged_in flag	

Arguments:
	none
Returns:
	none
*/
void Server_Connection_Handle::establishLoggedinStatus(){
	logged_in_status = 1;
}

/*
establishLoggedoutStatus()

Disables the logged_in flag	

Arguments:
	none
Returns:
	none
*/
void Server_Connection_Handle::establishLoggedoutStatus(){
	logged_in_status = 0;
}

/*
setAESKey(std::string key)

Sets the symetric encryption key	

Arguments:
	- std::string key, the symetric AES key	
Returns:
	none
*/
void Server_Connection_Handle::setAESKey(std::string key){
	AES_key.assign(key);
}


/*
setUsername(std::string username)

Sets the username

Arguments:
    - std::string username
Returns:
    none
*/
void Server_Connection_Handle::setUsername(std::string id){
    username.assign(id);
}

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
int Server_Connection_Handle::usernameIsValid(std::string username){
      int length = username.length();
      if (length > IBSSS_GLOBAL_MAXIMUM_USERNAME_LENGTH || length < IBSSS_GLOBAL_MINIMUM_USERNAME_LENGTH)
            return 0;
      for(int i = 0; username[i];)
            if (!std::isalnum(username[i++]))
                  return 0;
	return 1;
}

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
int Server_Connection_Handle::passwordIsValid(std::string password){
      int length = password.length();
      if (length > IBSSS_GLOBAL_MAXIMUM_PASSWORD_LENGTH || length < IBSSS_GLOBAL_MINIMUM_PASSWORD_LENGTH)
            return 0;
      for(int i = 0; password[i];)
            if (!std::isalnum(password[i++]))
                  return 0;
      return 1;
}

