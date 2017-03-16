/* 
IBSSS Client Operations

This file defines the client requested operations used by the ibsss client handler

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#include "ibsss_restrictions.h"
#include "ibsss_server_connection_handler.hh"
#include "ibsss_op_codes.hh"
#include "ibsss_crypto.hh"
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

int Server_Connection_Handle::operationHello(){
	
	unsigned char AES_key[IBSSS_KEY_SIZE];
	unsigned int length;
	int read_status, write_status;
	char operation_status;

	//TODO: generate AES key and send it
    generate_random_key(AES_key);

    std::string AES_key_str = std::string(AES_key, AES_key+4);
	// Remeber the AES key
	setAESKey(AES_key_str);

    std::string AES_key_encrypted_str = RSA_encrypt(AES_key_str);
    length = AES_key_encrypted_str.length();

	// Send Op Code to server
	ibsssWriteMessage(server_connection_descriptor, &IBSSS_OP_HELLO, 1, write_status);

	// send length and aes_key
	ibsssWriteMessage(server_connection_descriptor, &length, sizeof(length), write_status);
	ibsssWriteMessage(server_connection_descriptor, &AES_key_encrypted_str[0], length, write_status);

	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			establishSecuredStatus();
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}
}

int Server_Connection_Handle::operationCreateUser(std::string username, std::string password, std::string email){

	if (!secured_status)
		return 0;

	int read_status, write_status;
	char operation_status;

	unsigned char iv[IBSSS_NONCE_SIZE];	
	generate_random_iv(iv);

	unsigned char receivedIV[IBSSS_NONCE_SIZE];
	std::string received_session_token;

	std::string username_encrypt = encrypt_decrypt(username, (unsigned char) (&(getAESkey()[0])), iv);
	std::string password_encrypt = encrypt_decrypt(password, (unsigned char) (&(getAESkey()[0])), iv);
	std::string email_encrypt = encrypt_decrypt(email, (unsigned char) (&(getAESkey()[0])), iv);

	int username_length = username_encrypt.length();
	int password_length = password_encrypt.length();
	int email_length = email_encrypt.length();
	
	// Send Op Code to server
	ibsssWriteMessage(server_connection_descriptor, &IBSSS_OP_CREATE_USER, 1, write_status);

	// Send IV to server
	ibsssWriteMessage(server_connection_descriptor, iv, IBSSS_NONCE_SIZE, write_status);

	//send length of username	
	ibsssWriteMessage(server_connection_descriptor, &username_length, sizeof(username_length), write_status);


	//send username 
	ibsssWriteMessage(server_connection_descriptor, username_encrypt.c_str(), username_length, write_status);
	
	//send length of password
	ibsssWriteMessage(server_connection_descriptor, &password_length, sizeof(password_length), write_status);

	//send password
	ibsssWriteMessage(server_connection_descriptor, password_encrypt.c_str(), password_length, write_status);
	
	//send length of email
	ibsssWriteMessage(server_connection_descriptor, &email_length, sizeof(email_length), write_status);

	//send email
	ibsssWriteMessage(server_connection_descriptor, email_encrypt.c_str(), email_length, write_status);


	// read what server returns
	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			session_token.resize(IBSSS_SESSION_TOKEN_LENGTH);

			// read the IV
			ibsssReadMessage(server_connection_descriptor, &receivedIV[0], IBSSS_NONCE_SIZE, read_status)

			ibsssReadMessage(server_connection_descriptor, &received_session_token[0], IBSSS_SESSION_TOKEN_LENGTH, 
						read_status);
			session_token = encrypt_decrypt(username, (unsigned char) (&(getAESkey()[0])), receivedIV);
			std::cout << "got session token: " << session_token << std::endl;
			establishLoggedinStatus();
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}
}



int Server_Connection_Handle::operationLogin(std::string username, std::string password) {

	if(!secured_status)
		return 0;

	int read_status, write_status;
	char operation_status;

	unsigned char iv[IBSSS_NONCE_SIZE];	
	generate_random_iv(iv);

	std::string username_encrypt = encrypt_decrypt(username, (unsigned char) (&(getAESkey()[0])), iv);
	std::string password_encrypt = encrypt_decrypt(password, (unsigned char) (&(getAESkey()[0])), iv);

	int username_length = username_encrypt.length();
	int password_length = password_encypt.length();
	
	// Send Op Code to server
	ibsssWriteMessage(server_connection_descriptor, &IBSSS_OP_LOGIN, 1, write_status);

	// Send iv to the server
	ibsssWriteMessage(server_connection_descriptor, iv, IBSSS_NONCE_SIZE, write_status);

	//send username length
	ibsssWriteMessage(server_connection_descriptor, &username_length, sizeof(username_length), write_status);

    //send username
	ibsssWriteMessage(server_connection_descriptor, &username_encrypt[0], username_length, write_status);

	//send password length
	ibsssWriteMessage(server_connection_descriptor, &password_length, sizeof(password_length), write_status);

	// send password
	ibsssWriteMessage(server_connection_descriptor, &password_encrypt[0], password_length, write_status);		

	// read what server returns
	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			session_token.resize(IBSSS_SESSION_TOKEN_LENGTH);
			ibsssReadMessage(server_connection_descriptor, &session_token[0], IBSSS_SESSION_TOKEN_LENGTH, 
						read_status);
			std::cout << "got session token: " << session_token << std::endl;
			establishLoggedinStatus();
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}
}

/*
Server_Connection_Handle::operationLogout()

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
int Server_Connection_Handle::operationLogout() {

	if (!secured_status)
		return 0;

	int read_status, write_status;
	char operation_status;

	unsigned char iv[IBSSS_NONCE_SIZE];	
	generate_random_iv(iv);

	std::string session_token_encrypt = encrypt_decrypt(getSessionToken(), (unsigned char) (&(getAESkey()[0])), iv);
	
	// Send Op Code to server
	ibsssWriteMessage(server_connection_descriptor, &IBSSS_OP_LOGOUT , 1, write_status);

	// Send IV to server
	ibsssWriteMessage(server_connection_descriptor, iv, IBSSS_NONCE_SIZE, write_status);

	// Send Session token to server
	ibsssWriteMessage(server_connection_descriptor, &session_token_encrypt[0], IBSSS_SESSION_TOKEN_LENGTH, 
				write_status);

	// read what server returns
	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			establishLoggedoutStatus();
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}
}


/*
Server_Connection_Handle::operationRequestStreamLinks()

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
int Server_Connection_Handle::operationRequestStreamLinks(){

	//TODO impelement  
	return 0;
}

/*
Server_Connection_Handle::operationRequestStreamKey()

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
int Server_Connection_Handle::operationRequestStreamKey(){

	//TODO implement 
	return 0;
}

/*
Server_Connection_Handle::operationChangePassword()

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
int Server_Connection_Handle::operationChangePassword(std::string username, std::string old_password, std::string new_password){
	if (!secured_status)
		return 0;

	int read_status, write_status;
	
	int username_length = username.length();
	int old_password_length = old_password.length();
	int new_password_length = new_password.length();

	char operation_status;

	// Send Op Code to Server
	ibsssWriteMessage(server_connection_descriptor, &IBSSS_OP_CHANGE_PASSWORD, 1, write_status);

	// send username length
	ibsssWriteMessage(server_connection_descriptor, &username_length, sizeof(username_length), write_status);
	// send username
	ibsssWriteMessage(server_connection_descriptor, &username[0], username_length, write_status);
	
	// send old password length
	ibsssWriteMessage(server_connection_descriptor, &old_password_length, sizeof(old_password_length), write_status);
	// send old password 
	ibsssWriteMessage(server_connection_descriptor, &old_password[0], old_password_length, write_status);
	
	// send new password length
	ibsssWriteMessage(server_connection_descriptor, &new_password_length, sizeof(new_password_length), write_status);
	// send new_password
	ibsssWriteMessage(server_connection_descriptor, &new_password[0], new_password_length, write_status);

	// read what server returns
	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}
}

/*
Server_Connection_Handle::operationForgotPassword()

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
int Server_Connection_Handle::operationForgotPassword(std::string username, std::string email){
	if (!secured_status)
		return 0;

	int read_status, write_status;

	int username_length = username.length();
	int email_length = email.length();

	char operation_status;

	//send op code to server
	ibsssWriteMessage(server_connection_descriptor,&IBSSS_OP_FORGOT_PASSWORD, 1, write_status);

	//send username length
	ibsssWriteMessage(server_connection_descriptor, &username_length, sizeof(username_length), write_status);

	//send username
	ibsssWriteMessage(server_connection_descriptor, &username[0], username_length, write_status);

	//send email length
	ibsssWriteMessage(server_connection_descriptor, &email_length, sizeof(email_length), write_status);

	//send email
	ibsssWriteMessage(server_connection_descriptor, &email[0], email_length, write_status);

	//read what server returns
	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}
}

/*
Server_Connection_Handle::operationForgotUsername()

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
int Server_Connection_Handle::operationForgotUsername(std::string email){

	if (!secured_status)
		return 0;

	int read_status, write_status;

	int email_length = email.length();

	char operation_status;

	//send op code to server
	ibsssWriteMessage(server_connection_descriptor,&IBSSS_OP_FORGOT_USERNAME, 1, write_status);

	//send email length
	ibsssWriteMessage(server_connection_descriptor, &email_length, sizeof(email_length), write_status);

	//send email
	ibsssWriteMessage(server_connection_descriptor, &email[0], email_length, write_status);

	//read what server returns
	ibsssReadMessage(server_connection_descriptor, &operation_status, 1, read_status);

	switch (operation_status) {
		case IBSSS_OP_SUCCESS:
			return 1;
		case IBSSS_OP_FAILURE:
			return 0;
		default:
			return -1;
	}

}
