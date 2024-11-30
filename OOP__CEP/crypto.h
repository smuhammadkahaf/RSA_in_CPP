#include <iostream>

#include <string>
#include "file.h"
using namespace std;

#ifndef CRYPTO_H
#define CRYPTO_H

class crypto {

	private:

		//Data members important for RSA implementation
		string fileName;
		int P,Q;	//prime numbers	---> from 256 to 1000
		int N;		//product
		int T;		//totient
		int E;		//public key
		int D;		//private key
		
		//logical data members
		string encrypted_text;
		string decrypted_text;
	
	public:
		//constructors overloading
		crypto();					//Default constructor
		crypto (string);			//file name
		crypto (string, int);		//file name + public key
		crypto (string, int, int);	//file name + public key + private key


		//setters
		void setFileName(string);	//set file name
		void setP(int);				//set 1st prime
		void setQ(int);				//set 2nd prime
		void setN(int);				//set product
		void setT(int);				//set totient
		void setE(int);				//set public key
		void setD(int);				//set private key

		//getters
		string getFileName(void);	//get File Name
		int getP(void);				//get 1st prime
		int getQ(void);				//get 2nd prime
		int getN(void);				//get prduct
		int getT(void);				//get totient
		int getE(void);				//get public key
		int getD(void);				//get Private key

		string getEncryptedText(void);		//return encrypted text that is temp. store
		string getDecryptedText(void);		//return decrypted text that is temp. store




		//member functions for encryption and decreption
		unsigned int encrypt_char(unsigned int);	//encrypt single char
		unsigned char decrypt_char(unsigned int);	//decrypt single char

		string encrypt_character(unsigned char);
		unsigned int decode_escape_sequence(const std::string& line, int& index);
		string ascii_string(unsigned int);

		void encrypt_string(string); //encrypt the string
		void decrypt_string(string); //decrypt the string

		void encrypt_file(file& source, int cLine = 1);
		void decrypt_file(file& source, int cLine = 1);
		



		//member functions for key generation
		int getRandom(void);		//return number from 0 to 1000 
		bool validatePrime(int);	// verify passed number is prime or not
		int getPrime(void);			// return random prime number
		void calculateN(void);		// calculate product of  P and Q
		void calculateT(void);		// calculate the Toteient
		void generateE(void);		//generate the public key
		void generateD(void);		//generate the private key
		string getPublicKey(void);	//return public key in format "N:E"
		string getPrivateKey(void);	//return public key in format "N:D"
		void createKeys(void);		//combine everything and find key pairs
};


#endif // !FSECURE_H
