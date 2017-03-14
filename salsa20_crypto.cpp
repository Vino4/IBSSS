#include "salsa.h"
using CryptoPP::Salsa20;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::endl;

using std::string;

#define KEY_SIZE 32
#define NONCE_SIZE 8

string encrypt_decrypt(string plaintext, string key, string iv) {

    byte *keyBytes = (byte *) key.c_str();
    byte *ivBytes = (byte *) iv.c_str();

    byte *plaintextBytes = (byte *) plaintext.c_str();
    byte *ciphertextBytes = new byte[plaintext.length()];
    string ciphertext;

    Salsa20::Encryption salsa;
    salsa.SetKeyWithIV(keyBytes, KEY_SIZE, ivBytes);

    salsa.ProcessData(ciphertextBytes, plaintextBytes, plaintext.length());
    ciphertext.assign((char *) ciphertextBytes)

    return ciphertext
}





// int main() {

// 	AutoSeededRandomPool prng;

// 	string ciphertextStr(""), plaintextStr("My Plaintext!! My Dear plaintext!!");
// 	byte *plaintextBytes = (byte *) plaintextStr.c_str();
// 	//I could statically allocate this, but then changes will require work, and typing
// 	byte *ciphertextBytes = new byte[plaintextStr.length()];

// 	//~Key and IV Generation/Initialization======================================
// 	/////////////////////////////////////////////////////////////////////////////
// 	/////////////////////////////////////////////////////////////////////////////
// 	byte key[32];
// 	byte iv[8];
// 	prng.GenerateBlock(key, 32);
// 	prng.GenerateBlock(iv, 8);

// 	//~Encryption================================================================
// 	/////////////////////////////////////////////////////////////////////////////
// 	/////////////////////////////////////////////////////////////////////////////
// 	Salsa20::Encryption salsa;	
// 	salsa.SetKeyWithIV(key, 32, iv);
// 	salsa.ProcessData(ciphertextBytes, plaintextBytes, plaintextStr.length());
// 	ciphertextStr.assign((char *) ciphertextBytes);

// 	//Output plaintext/ciphertext for sanity check
// 	cout << "Plaintext: " << plaintextStr << endl;
// 	cout << "Ciphertext: " << ciphertextStr << endl;

// 	//Reset plaintext (for sanity again)
// 	plaintextStr.assign("");

// 	//Reset Key & IV
// 	//!!! THIS IS IMPORTANT: If you do not reset the stream cipher the data will
// 		//be encrypted again with a different part of the streaming key
// 		//Resetting the key & IV ensure that the same key is used, and we decrypt
// 	/////////////////////////////////////////////////////////////////////////////
// 	/////////////////////////////////////////////////////////////////////////////
//     prng.GenerateBlock(key,32);
// 	salsa.SetKeyWithIV(key, 32, iv);

// 	//~Decryption================================================================
// 	/////////////////////////////////////////////////////////////////////////////
// 	/////////////////////////////////////////////////////////////////////////////
// 	salsa.ProcessData(plaintextBytes, ciphertextBytes, ciphertextStr.length());
// 	plaintextStr.assign((char *) plaintextBytes);

// 	//Output newly decrypted plaintext
// 	cout << "Plaintext Again: " << plaintextStr << endl << endl;
// 	cout << endl << "SALSA!" << endl << endl << "     " << "...20..." << endl;

// 	delete[] ciphertextBytes;

// 	return 0;
// }