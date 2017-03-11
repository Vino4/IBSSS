/* 
IBSSS Main Server

This file runs the ibsss server
The ibsss server manages the following:
	- Users, streams, stream keys and access control
	- Communication protocal

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/


#include "ibsss_server_connection_handler.hh"
#include "ibsss_op_codes.hh"
#include "ibsss_error.hh"
#include <stdio.h>
#include <stdlib.h>

/*
int main(int argc, char *argv[]){
	Server_Connection_Handle connection;
	if (connection.connect())
		std::cout << "conNeKtid" << std::endl;
	else
		std::cout << "Fak" << std::endl;
	
	std::string username("test");
	std::string email("lol@iOiOiO.fuck");
	std::string password("KTNXBYE");
	std::string new_password("lolololol");

	if(connection.operationCreateUser(username, password, email))
		std::cout << "Made It" << std::endl;
	else
		std::cout << "Fucked" << std::endl;

	if(connection.operationLogin(username, password))
		std::cout << "Killing It" << std::endl;
	else
		std::cout << "Fakedd" << std::endl;

	if(connection.operationChangePassword(username, new_password, password))
		std::cout << "chAAAAINJED" << std::endl;
	else
		std::cout << "no chnj :(" << std::endl;

	if(connection.operationLogin(username, password))
		std::cout << "old pass: yes" << std::endl;
	else
		std::cout << "old pass: nah" << std::endl;

	if(connection.operationLogin(username, new_password))
		std::cout << "NEW PASS IN" << std::endl;
	else
		std::cout << "new pass sad :(" << std::endl;

	std::cout << "NA NA NA NANA" << std::endl;	
	
	return 0; 
}*/
