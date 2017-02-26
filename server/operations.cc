
#define IBSSS_CHECK_WRITE_STATUS if (IBSSS_TRACE_READ_WRITE_STATUS) \
		std::cout << "Write Status: " << write_status << std::endl; \
	if (write_status == 0){ \
		break;\
	} 

#define IBSSS_CHECK_READ_STATUS if (IBSSS_TRACE_READ_WRITE_STATUS) \
		std::cout << "Read Status: " << read_status << std::endl; \
	if (read_status == 0){ \
		break;\
	}  

/*
Client_Handle::operationHello()

Initiates client handshake

Receives (in order):
	- (int) AES Key Length
	- char[AES Key Length] AES Key

Performs:
	- set Client_Handle AES_key

Sends (in order)
	- (unsigned char) IBSSS_OP_SUCCESS

Arguments:
	none
Returns:
	none
*/
void Client_Handle::operationHello(){
	
	unsigned char AES_Key[4096];
	unsigned int length = 0;
	int operation_successful = 0;
	int read_status, write_status;
	
	//read the length of the key, if operation fails issue ibsssError	
	if ((read_status = read(client_descriptor, &length, 4)) < 0)
		ibsssError("failed to read");
	
	if (IBSSS_TRACE_READ_WRITE_STATUS)
		std::cout << "Read Status: " << read_status << std::endl;
	
	if (read_status == 0){
		break;
	}	

	//read the key	
	if ((read_status = read(client_descriptor, AES_Key, length)) < 0)
		ibsssError("failed to read");
	
	if (IBSSS_TRACE_READ_WRITE_STATUS)
		std::cout << "Read Status: " << read_status << std::endl;
		
	if (read_status == 0){
		break;
	}
	
	//put string termination character at the end of the string	
	message_buffer[length] = '\0';		

	//print what you received in the following format:
	//[session token][length of message (key in this case)]: message (key in this case)
	//format this however you want just make sure it's clear to help us debug	
	std::cout << "[" << getSessionToken() << "]["
	<< length << "]: "
	<< AES_key 
	<< std::endl;

	/*
		TODO: call functions to set the key
		**for now just write a TODO statement coz i'm still working on the client handler
		this will return operation status
		
	*/
	
	//flag success if you successed by changing the success variable to 1:
	operation_successful++;	

	//let the client now you were successful or that you failed base on the status
	if (operation_successful){
		if ((write_status = write(client_descriptor, IBSSS_OP_SUCCESS, 1)) < 0)
			ibsssError("failed to write");
	
		if (IBSSS_TRACE_READ_WRITE_STATUS)
			std::cout << "Write Status: " << write_status << std::endl;
		
		if (write_status == 0){
			break;
		}

	} else {
		if ((write_status = write(client_descriptor, IBSSS_OP_FAILURE, 1)) < 0)
			ibsssError("failed to write");

		if (IBSSS_TRACE_READ_WRITE_STATUS)
			std::cout << "Write Status: " << write_status << std::endl;

		if (write_status == 0){
			break;
		}
	}
}



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


void Client_Handle::operationCreateUser() {
	u_char user_id[256];
	u_char password[256];
	u_char email[256];

	u_int user_id_length;
	u_int password_length;
	u_int email_length;

	int operation_successful;
	int read_status, write_status;

	// read length of user_id
	if((read_status = read(client_descriptor, &user_id_length, 4)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	// read user_id
	if((read_status = read(client_descriptor, user_id, user_id_length)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	user_id[length] = '\0';

	// read password_length
	if((read_status = read(client_descriptor, &password_length, 4)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	// read password
	if((read_status = read(client_descriptor, password, password_length)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	password[length] = '\0';	

	// read email_length
	if((read_status = read(client_descriptor, &email_length, 4)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	// read email
	if((read_status = read(client_descriptor, email, user_length)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	email[length] = '\0';	

	// print out for debugging purposes
	std::cout << "[" << getSessionToken() << "] "
	<< "user_id: " << user_id
	<< ", password: " << password
	<< ", email: " << email
	<< std::endl;

	/*
		TODO: call functions to set the user_id, password, and email
		TODO: hash user details and store in database
		TODO: generate token key
	*/

	//flag success if you successed by changing the success variable to 1:
	operation_successful++;	

	//let the client now you were successful or that you failed base on the status
	if (operation_successful){
		if ((write_status = write(client_descriptor, IBSSS_OP_SUCCESS, 1)) < 0)
			ibsssError("failed to write");
	
			IBSSS_CHECK_WRITE_STATUS

		if ((write_status = write(client_descriptor, getSessionToken(), 1)) < 0)
			ibsssError("failed to write");

			IBSSS_CHECK_WRITE_STATUS
	} else {
		if ((write_status = write(client_descriptor, IBSSS_OP_FAILURE, 1)) < 0)
			ibsssError("failed to write");

			IBSSS_CHECK_WRITE_STATUS
	}
}


void Client_Handle::operationLogin() {
	u_char user_id;
	u_char password;

	u_int user_id_length;
	u_int password_length

	// read length of user_id
	if((read_status = read(client_descriptor, &user_id_length, 4)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	// read user_id
	if((read_status = read(client_descriptor, user_id, user_id_length)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	user_id[length] = '\0';

	// read password_length
	if((read_status = read(client_descriptor, &password_length, 4)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	// read password
	if((read_status = read(client_descriptor, password, password_length)) < 0) {
		ibsssError("failed to read")
	}
	IBSSS_CHECK_READ_STATUS

	password[length] = '\0';

	// print out for debugging purposes
	std::cout << "[" << getSessionToken() << "] "
	<< "user_id: " << user_id
	<< ", password: " << password
	<< std::endl;

	/*
		TODO: call functions to set the user_id, password
		TODO: check user details against database
		TODO: generate session token
	*/

	//flag success if you successed by changing the success variable to 1:
	operation_successful++;	

	//let the client now you were successful or that you failed base on the status
	if (operation_successful){
		if ((write_status = write(client_descriptor, IBSSS_OP_SUCCESS, 1)) < 0)
			ibsssError("failed to write");
	
			IBSSS_CHECK_WRITE_STATUS

		if ((write_status = write(client_descriptor, getSessionToken(), 1)) < 0)
			ibsssError("failed to write");

			IBSSS_CHECK_WRITE_STATUS
	} else {
		if ((write_status = write(client_descriptor, IBSSS_OP_FAILURE, 1)) < 0)
			ibsssError("failed to write");

			IBSSS_CHECK_WRITE_STATUS
	}

}


void Client_Handle::logout() {
	u_char session_token[IBSSS_SESSION_TOKEN_LENGTH];
	
}


/*
Client_Handle::processConnection()

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
void Client_Handle::processesConnection(){
	
	unsigned char message_buffer[4096];
	unsigned char op_code;
	unsigned int length = 0;
	int read_status, write_status;
	for (;;){	
		if ((read_status = read(client_descriptor, &op_code, 1)) < 0)
	            ibsssError("failed to read");

		switch(op_code){
			case IBSSS_OP_HELLO:
				operationHello();
				break;
			case IBSSS_OP_CREATE_USER:
				operationCreateUser();
				break;	
		}
	}
	killSession();
}






