/*
IBSSS session token 
This file defines the sesion token for ibsss client 

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/

#ifndef _IBSSS_SESSION_TOKEN
#define _IBSSS_SESSION_TOKEN

//subtract one for indexing, subtract one to account for '\0'
#define IBSSS_SESSION_TOKEN_CHARACTER_POOL_SIZE 69

extern const char IBSSS_SESSION_TOKEN_ALLOWED_CHARACTERS[71];

extern int IBSSS_SESSION_TOKEN_LENGTH;

#endif /*_IBSSS_SESSION_TOKEN*/

