#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "modes.h"
#include "aes.h"
#include "filters.h"
// #include "ibsss_connection_handler.hh"

int main(int argc, char* argv[]) {

    //Key and IV setup
    //AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-   
    //bit). This key is secretly exchanged between two parties before communication   
    //begins. DEFAULT_KEYLENGTH= 16 bytes
    byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    byte iv1[CryptoPP::AES::BLOCKSIZE];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

    memset(iv1, 0x01, CryptoPP::AES::BLOCKSIZE);

    std::cout << "block" << CryptoPP::AES::BLOCKSIZE << std::endl;
    // std::cout << sizeof(iv) << std::endl;
    std::cout << std::hex << (0xFF & iv[0]) << std::endl;

    std::cout << "block" << std::dec << CryptoPP::AES::BLOCKSIZE << std::endl;
    std::cout << "block" << CryptoPP::AES::BLOCKSIZE << std::endl;
    // Server_Connection_Handle connection;
    // connection.setAESKey("123");

    std::string AESKey = "asdfghjklqwertyu";

    std::vector<unsigned char> bbuffer;

    for (int i = 0; i < AESKey.length(); i ++){
        bbuffer.push_back((unsigned char) AESKey[i]);
    }
    for (int i=0; i < bbuffer.size(); i++){
        std::cout << std::hex << (0xFF & bbuffer[i]) << std::endl;
    }

    std::string AESKey1 = "bsdfghjklqwertyu";

    std::vector<unsigned char> bbuffer1;

    for (int i = 0; i < AESKey1.length(); i ++){
        bbuffer1.push_back((unsigned char) AESKey1[i]);
    }
    for (int i=0; i < bbuffer1.size(); i++){
        std::cout << std::hex << (0xFF & bbuffer1[i]) << std::endl;
    }
    
    //
    // String and Sink setup
    //
    std::string plaintext = "Now is the time for all good men to come to the aide...";
    std::string ciphertext;
    std::string decryptedtext;

    //
    // Dump Plain Text
    //
    std::cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    std::cout << plaintext;
    std::cout << std::endl << std::endl;



    //
    // Create Cipher Text
    //
    CryptoPP::AES::Encryption aesEncryption(&bbuffer[0], CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );

    std::cout << "test" <<std::endl;
    std::cout << sizeof(iv) << std::endl;
    std::cout << std::hex << (0xFF & iv[0]) << std::endl;

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( ciphertext ) );
    stfEncryptor.Put( reinterpret_cast<const unsigned char*>( plaintext.c_str() ), plaintext.length() + 1 );
    stfEncryptor.MessageEnd();

    //
    // Dump Cipher Text
    //
    std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;

    for( int i = 0; i < ciphertext.size(); i++ ) {

        std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
    }

    std::cout << std::endl << std::endl;

    //
    // Decrypt
    //
    CryptoPP::AES::Decryption aesDecryption(&bbuffer[0], CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv1 );

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>( ciphertext.c_str() ), ciphertext.size() );
    stfDecryptor.MessageEnd();

    //
    // Dump Decrypted Text
    //
    std::cout << "Decrypted Text: " << std::endl;
    std::cout << decryptedtext;
    std::cout << std::endl << std::endl;

    return 0;
}
