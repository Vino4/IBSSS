/*
IBSSS OP Codes
This file defines the opcodes for the IBSSS communication protocal

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/
#include "ibsss_op_codes.hh"
#include <iostream>
#include <bitset>

const unsigned char IBSSS_OP_HELLO = 0 | 1 << 0;
const unsigned char IBSSS_OP_CREATE_USER = 0 | 1 << 1;
const unsigned char IBSSS_OP_LOGIN = 0 | 1 << 2;
const unsigned char IBSSS_OP_LOGOUT = 0 | 1 << 2 | 1 << 0;
const unsigned char IBSSS_OP_REQUEST_STREAM_LINKS = 0 | 1 << 3;
const unsigned char IBSSS_OP_REQUEST_STREAM_KEY = 0 | 1 << 4;
const unsigned char IBSSS_OP_CHANGE_PASSWORD = 0 | 1 << 5;
const unsigned char IBSSS_OP_FORGOT_PASSWORD = 0 | 1 << 6;
const unsigned char IBSSS_OP_FORGOT_USERNAME = 0 | 1 << 7;

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
	<< std::endl; 
}
