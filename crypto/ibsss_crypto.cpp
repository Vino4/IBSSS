#include "ibsss_crypto.hh"

#include "ibsss_public_key.h"
#include "ibsss_private_key.h"

#include <salsa.h>
using CryptoPP::Salsa20;

#include <osrng.h>
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::endl;

using std::string;

#include <rsa.h>

std::string encrypt_decrypt(std::string plaintext, byte key[IBSSS_KEY_SIZE], byte iv[IBSSS_NONCE_SIZE]) {

    byte *plaintextBytes = (byte *) plaintext.c_str();
    byte *ciphertextBytes = new byte[plaintext.length()];
    std::string ciphertext;

    Salsa20::Encryption salsa;
    salsa.SetKeyWithIV(key, IBSSS_KEY_SIZE, iv);

    salsa.ProcessData(ciphertextBytes, plaintextBytes, plaintext.length());
    ciphertext.assign((char *) ciphertextBytes);

    return ciphertext;
}

void generate_random_key(byte key[IBSSS_KEY_SIZE]) {
    AutoSeededRandomPool prng;
    prng.GenerateBlock(key, IBSSS_KEY_SIZE);
}


void generate_random_iv(byte iv[IBSSS_NONCE_SIZE]) {
    AutoSeededRandomPool prng;
    prng.GenerateBlock(iv, IBSSS_NONCE_SIZE);
}



// RSA Functions

std::string RSA_encrypt(std::string plaintext) {
    AutoSeededRandomPool rng;
    CryptoPP::InvertibleRSAFunction params;
    params.Initialize(CryptoPP::Integer(IBSSS_PUBLIC_KEY_N), CryptoPP::Integer(IBSSS_PUBLIC_KEY_E),CryptoPP::Integer(IBSSS_PRIVATE_KEY_D));

    std::string ciphertext;
    CryptoPP::RSA::PublicKey publicKey(params);

    CryptoPP::RSAES_OAEP_SHA_Encryptor e(publicKey);

    CryptoPP::StringSource ss1(plaintext, true, new CryptoPP::PK_EncryptorFilter(rng, e, new CryptoPP::StringSink(ciphertext))); 

    return ciphertext;
}

std::string RSA_decrypt(std::string ciphertext) {
    AutoSeededRandomPool rng;
    CryptoPP::InvertibleRSAFunction params;
    params.Initialize(CryptoPP::Integer(IBSSS_PUBLIC_KEY_N), CryptoPP::Integer(IBSSS_PUBLIC_KEY_E),CryptoPP::Integer(IBSSS_PRIVATE_KEY_D));

    std::string recoveredtext;
    CryptoPP::RSA::PrivateKey privateKey(params);

    CryptoPP::RSAES_OAEP_SHA_Decryptor d(privateKey);

    CryptoPP::StringSource ss2(ciphertext, true, new CryptoPP::PK_DecryptorFilter(rng, d, new CryptoPP::StringSink(recoveredtext)));

    return recoveredtext;
}
