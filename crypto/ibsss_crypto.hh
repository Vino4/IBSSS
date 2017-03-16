#ifndef _IBSSS_CRYPTO_H 
#define _IBSSS_CRYPTO_H 

#include "ibsss_public_key.h"
#include "ibsss_private_key.h"

#include <salsa.h>
using CryptoPP::Salsa20;

#include <osrng.h>
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::endl;

#include <rsa.h>


#define IBSSS_KEY_SIZE 32
#define IBSSS_NONCE_SIZE 8

std::string encrypt_decrypt(std::string plaintext, byte key[IBSSS_KEY_SIZE], byte iv[IBSSS_NONCE_SIZE]);

void generate_random_key(byte key[IBSSS_KEY_SIZE]);

void generate_random_iv(byte iv[IBSSS_NONCE_SIZE]);

std::string RSA_encrypt(std::string plaintext); 

std::string RSA_decrypt(std::string ciphertext);

#endif // _IBSSS_CRYPTO_H 
