/* 
IBSSS Client Operations

This file defines the client requested operations used by the ibsss client handler

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

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


int Client_Handle::operationHello(){
	
	// unsigned char AES_key[4096];
	// unsigned int length = 0;
	// int operation_successful = 0;
	// int read_status, write_status;
	
	// //read the length of the key, if operation fails issue ibsssError	
	// ibsssReadMessage(client_descriptor, &length, 4, read_status);

	// //read the key	
	// ibsssReadMessage(client_descriptor, AES_key, length, read_status);
	
	// //put string termination character at the end of the string	
	// AES_key[length] = '\0';		

	// //print what you received in the following format:
	// //[session token][length of message (key in this case)]: message (key in this case)
	// //format this however you want just make sure it's clear to help us debug	
	// ibsssAnnounceMessage(getSessionToken(), length, AES_key);

	// //set the client in the client's storage	
	// setAESKey(std::string(AES_key, AES_key+length));

	// establishSecuredStatus();
	
	// //flag success if you successed by changing the success variable to 1:
	// operation_successful++;	
	// //let the client now you were successful or that you failed base on the status
	// if (operation_successful){
	// 	ibsssWriteMessage(client_descriptor, &IBSSS_OP_SUCCESS, 1, write_status);
	// } else {
	// 	ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
	// }


	unsigned char AES_key;
	unsigned int length = 0;
	int operation_successful = 0;
	int read_status, write_status;
	char was_success;

	//TODO: generate AES key and send it
	// make a fake AES key for now
	AES_key = "123";
	length = strlen(AES_key);

	// Remeber the AES key
	setAESKey(std::string(AES_key, AES_key+length));

	// send length and aes_key
	ibsssWriteMessage(server_connection_descriptor, &length, sizeof(length), write_status);
	ibsssWriteMessage(server_connection_descriptor, AES_key, length, write_status);

	ibsssReadMessage(server_connection_descriptor, &was_success, 1, read_status);

	switch (wasSuccess) {
		case IBSSS_OP_SUCCESS:
		return 1 break;
		case IBSSS_OP_FAILURE:
		return 0 break;
	}


}



int Client_Handle::operationCreateUser(char username[], char password[], char email[]) {
	int read_status, write_status;

	if (!secured_status){
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
		return;
	}

	int username_length = strlen(username);
	int password_length = strlen(password);
	int email_length = strlen(email);

	char was_success;

	char session_token[];

	//send length of username	
	ibsssWriteMessage(server_connection_descriptor, &username_length, sizeof(username_length), write_status);

	//send username 
	ibsssWriteMessage(server_connection_descriptor, username, username_length, write_status);
	
	//send length of password
	ibsssWriteMessage(server_connection_descriptor, &password_length, sizeof(password, write_status));

	//send password
	ibsssWriteMessage(server_connection_descriptor, password, password_length, write_status);

	//send length of email
	ibsssWriteMessage(server_connection_descriptor, &email_length, sizeof(email_length), write_status);

	//send email
	ibsssWriteMessage(server_connection_descriptor, email, email_length, write_status);


	// read what server returns
	ibsssReadMessage(server_connection_descriptor, &was_success, 1, read_status);

	switch (wasSuccess) {
		case IBSSS_OP_SUCCESS:
		ibsssReadMessage(server_connection_descriptor,session_token, IBSSS_SESSION_TOKEN_LENGTH, read_status);
		setSessionToken(std::string(session_token));
		return 1 break;
		case IBSSS_OP_FAILURE:
		return 0 break;
	}
}



void Client_Handle::operationLogin(char username[], char password[]) {
	
	int read_status, write_status;
	
	if(!secured_status){
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
		return;
	}

	int username_length = strlen(username);
	int password_length = strlen(password);
	char was_success;
	char session_token[];

	//send username length
	ibsssWriteMessage(server_connection_descriptor, &username_length, sizeof(username_length), write_status);

	//send username
	ibsssWriteMessage(server_connection_descriptor, username, username_length, write_status);

	//send password length
	ibsssWriteMessage(server_connection_descriptor, &password_length, sizeof(password_length), write_status);
	
	// send password
	ibsssWriteMessage(server_connection_descriptor, password, password_length, write_status);		

	// read what server returns
	ibsssReadMessage(server_connection_descriptor, &was_success, 1, read_status);

	switch (wasSuccess) {
		case IBSSS_OP_SUCCESS:
		ibsssReadMessage(server_connection_descriptor,session_token, IBSSS_SESSION_TOKEN_LENGTH, read_status);
		setSessionToken(std::string(session_token));
		return 1 break;
		case IBSSS_OP_FAILURE:
		return 0 break;
	}
}

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
void Client_Handle::operationLogout() {

	int read_status, write_status;

	if (!secured_status){
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
		return;
	}

	char session_token[IBSSS_SESSION_TOKEN_LENGTH];


	//read the session token, if operation fails issue ibsssError	
	ibsssReadMessage(client_descriptor, session_token, IBSSS_SESSION_TOKEN_LENGTH, read_status);

	//put string termination character at the end of the string	
	session_token[IBSSS_SESSION_TOKEN_LENGTH] = '\0';		

	ibsssAnnounceMessage(getSessionToken(), IBSSS_SESSION_TOKEN_LENGTH, session_token);

	if(session_token == getSessionToken()){
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_SUCCESS, 1, write_status);
		establishLoggedoutStatus();
		killSession();
		return;	
	}

	//let the client now you were successful or that you failed base on the status
	ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
}


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
void Client_Handle::operationRequestStreamLinks(){

	int write_status;
	//TODO request links from database and send to user
	ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);

}

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
void Client_Handle::operationRequestStreamKey(){

	int write_status;
	//TODO request key for stream from database and send to user
	ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);

}

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
void Client_Handle::operationChangePassword(){

	int read_status, write_status;

	if (!secured_status){
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
		return;
	}
	
	char username[256];
	char old_password[256];
	char new_password[256];

	int username_length;
	int old_password_length;
	int new_password_length;

	int operation_successful = 0;

	//read the length of the username, if operation fails issue ibsssError	
	ibsssReadMessage(client_descriptor, &username_length, 4, read_status);

	//read the username 
	ibsssReadMessage(client_descriptor, username, username_length, read_status);
	
	//put string termination character at the end of the string	
	username[username_length] = '\0';		

	ibsssAnnounceMessage(getSessionToken(), username_length, username);

	//read the length of the old password, if operation fails issue ibsssError	
	ibsssReadMessage(client_descriptor, &old_password_length, 4, read_status);

	//read the password 
	ibsssReadMessage(client_descriptor, old_password, old_password_length, read_status);
	
	//put string termination character at the end of the string	
	old_password[old_password_length] = '\0';		

	ibsssAnnounceMessage(getSessionToken(), old_password_length, old_password);

	//read the length of the new password, if operation fails issue ibsssError	
	ibsssReadMessage(client_descriptor, &new_password_length, 4, read_status);

	//read the new password 
	ibsssReadMessage(client_descriptor, new_password, new_password_length, read_status);
	
	//put string termination character at the end of the string	
	new_password[new_password_length] = '\0';		

	ibsssAnnounceMessage(getSessionToken(), new_password_length, new_password);

	if(usernameIsValid(username) && passwordIsValid(old_password) && passwordIsValid(new_password))
		if(database_handle.changePassword(username, old_password, new_password)){
			operation_successful++;	
		}
	//let the client now you were successful or that you failed base on the status
	if (operation_successful){
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_SUCCESS, 1, write_status);
	} else {
		ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);
	}
}

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
void Client_Handle::operationForgotPassword(){

	int write_status;
	//TODO: create new password, store in database and send to user
	ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);

}

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
void Client_Handle::operationForgotUsername(){

	int write_status;
	//TODO: send username to user's email
	ibsssWriteMessage(client_descriptor, &IBSSS_OP_FAILURE, 1, write_status);

}
