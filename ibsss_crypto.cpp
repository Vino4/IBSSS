#include "salsa.h"
using CryptoPP::Salsa20;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::endl;

using std::string;

#include "rsa.h"


#define KEY_SIZE 32
#define NONCE_SIZE 8

#define IBSSS_PRIVATE_KEY_N  "17469450475267467179150117614325993228410674482075808103579966374112703922942231755173538886998524053965335192498052728851897751467586074704890570336709275912173006923705413747487776790461990043438287416322146538074538905146872344125369415103178112116886835318199192707879645790611960980804702878914267923859741547773177071772411375440746397704073953898006559594377223356713821710404234570010875843854491212983079484758634739873945655133000881840661500203939705275448138813115865886657423855210426809357009687745139549690556599791305959734162074963753462744353143105468550968748460778881096463328558383136920688004277"
#define IBSSS_PRIVATE_KEY_E "65537"
#define IBSSS_PRIVATE_KEY_D "4826576434009308149791280950342566174631613940933314880625027864199745638840883628956578247812415506433775185476330023670923487279301479388459245267357292200462588100882462223259550701815695770580543360961672144970256129445876642737355448056414637168324304241979840126364904501741165715236137678387790855506409397683803621503205071016458007820709533789982723274789361972453489138721348835536446979794770869696415401072404235816082080654845997846723099607345554487139978803007723033846321181538565304392459669137469092176266425575894583296117635777324460785095840041505628065596416958831023080225525502454689530792069"


string encrypt_decrypt(string plaintext, byte key[KEY_SIZE], byte iv[NONCE_SIZE]) {


    byte *plaintextBytes = (byte *) plaintext.c_str();
    byte *ciphertextBytes = new byte[plaintext.length()];
    string ciphertext;

    Salsa20::Encryption salsa;
    salsa.SetKeyWithIV(key, KEY_SIZE, iv);

    salsa.ProcessData(ciphertextBytes, plaintextBytes, plaintext.length());
    ciphertext.assign((char *) ciphertextBytes);

    return ciphertext;
}

void generate_random_key(byte key[KEY_SIZE]) {
    AutoSeededRandomPool prng;
    prng.GenerateBlock(key, KEY_SIZE);
}


void generate_random_iv(byte iv[NONCE_SIZE]) {
    AutoSeededRandomPool prng;
    prng.GenerateBlock(iv, NONCE_SIZE);
}



// RSA Functions

string RSA_encrypt(string plaintext) {
    AutoSeededRandomPool rng;
    CryptoPP::InvertibleRSAFunction params;
    params.Initialize(CryptoPP::Integer::Integer(IBSSS_PRIVATE_KEY_N), CryptoPP::Integer::Integer(IBSSS_PRIVATE_KEY_E),CryptoPP::Integer::Integer(IBSSS_PRIVATE_KEY_D));

    string ciphertext;
    CryptoPP::RSA::PublicKey publicKey(params);

    CryptoPP::RSAES_OAEP_SHA_Encryptor e(publicKey);

    CryptoPP::StringSource ss1(plaintext, true, new CryptoPP::PK_EncryptorFilter(rng, e, new CryptoPP::StringSink(ciphertext))); 

    return ciphertext;
}

string RSA_decrypt(string ciphertext) {
    AutoSeededRandomPool rng;
    CryptoPP::InvertibleRSAFunction params;
    params.Initialize(CryptoPP::Integer::Integer(IBSSS_PRIVATE_KEY_N), CryptoPP::Integer::Integer(IBSSS_PRIVATE_KEY_E),CryptoPP::Integer::Integer(IBSSS_PRIVATE_KEY_D));

    string recoveredtext;
    CryptoPP::RSA::PrivateKey privateKey(params);

    CryptoPP::RSAES_OAEP_SHA_Decryptor d(privateKey);

    CryptoPP::StringSource ss2(ciphertext, true, new CryptoPP::PK_DecryptorFilter(rng, d, new CryptoPP::StringSink(recoveredtext)));

    return recoveredtext;
}


int main() {

    string plaintext = "hello, everyone";
    string ciphertext = RSA_encrypt(plaintext);

    byte *ciphertextBytes = (byte *) ciphertext.c_str();

    for( int i = 0; i < sizeof(ciphertext); i++ ) {

        cout << "0x" << std::hex << (0xFF & ciphertextBytes[i]) << " ";
    }

    string recoveredtext = RSA_decrypt(ciphertext);
    cout << recoveredtext << endl;

    return 0;

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