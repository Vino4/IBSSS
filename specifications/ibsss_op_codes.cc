/*
IBSSS OP Codes
This file defines the opcodes for the IBSSS communication protocal

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/
#include "ibsss_op_codes.hh"
#include <iostream>
#include <bitset>

void printOpCodes(){
	
	std::cout 
	<< "IBSSS_OP_HELLO :" 
	<< std::bitset<8> (IBSSS_OP_HELLO) 
	<< std::endl 
	<< "IBSSS_OP_CREATE_USER:" 
	<< std::bitset<8> (IBSSS_OP_CREATE_USER) 
	<< std::endl 
	<< "IBSSS_OP_LOGIN :" 
	<< std::bitset<8> (IBSSS_OP_LOGIN) 
	<< std::endl 
	<< "IBSSS_OP_LOGOUT :" 
	<< std::bitset<8> (IBSSS_OP_LOGOUT) 
	<< std::endl 
	<< "IBSSS_OP_REQUEST_STREAM_LINKS :" 
	<< std::bitset<8> (IBSSS_OP_REQUEST_STREAM_LINKS) 
	<< std::endl 
	<< "IBSSS_OP_REQUEST_STREAM_KEY :" 
	<< std::bitset<8> (IBSSS_OP_REQUEST_STREAM_KEY) 
	<< std::endl 
	<< "IBSSS_OP_CHANGE_PASSWORD :" 
	<< std::bitset<8> (IBSSS_OP_CHANGE_PASSWORD) 
	<< std::endl 
	<< "IBSSS_OP_FORGOT_PASSWORD :" 
	<< std::bitset<8> (IBSSS_OP_FORGOT_PASSWORD) 
	<< std::endl 
	<< "IBSSS_OP_FORGOT_USERNAME :" 
	<< std::bitset<8> (IBSSS_OP_FORGOT_USERNAME) 
	<< std::endl 
	<< "IBSSS_OP_SUCCESS:" 
	<< std::bitset<8> (IBSSS_OP_SUCCESS) 
	<< std::endl 
	<< "IBSSS_OP_FAILURE:" 
	<< std::bitset<8> (IBSSS_OP_FAILURE) 
	<< std::endl; 
}
