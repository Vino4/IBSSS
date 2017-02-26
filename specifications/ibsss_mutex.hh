/*
IBSSS Mutex 
This file defines the mutexes used in IBSSS 

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/

#ifndef _IBSSS_MUTEX
#define _IBSSS_MUTEX

#include <stdio.h>
#include <stdlib.h>
#include <mutex>

extern std::mutex IBSSS_KILL_SESSION_MUTEX;

#endif /*_IBSSS_MUTEX*/

