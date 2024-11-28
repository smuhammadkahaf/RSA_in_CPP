#include <iostream>
#include <windows.h>
#include <string>
#include "file.h"
#include "crypto.h"

using namespace std;

int mainMenu(void);
void takeKey(int& , int& );
string takeName(bool=true);

int main()
{
	srand(time(0));	//get time Pc time in miliseconds and use it as a seed for random number
	system("color 17");
	
	
	//variables

	string nameOfFile = "";		//To get file name from the user
	int choice = 0;				//for user what he want to do
	int n,e,d;					//for product, public key, and private key respectively
	
	//objects
	crypto obj;

	

	home://main menu of program
	
	
	choice = mainMenu();
	//system("cls");
	switch (choice)
	{
		case 1:
		{
			cout << "Calculating public and private keys, this may take a few moments..." << endl;
			obj.createKeys();
			system("cls");

			cout << obj.getPublicKey() << endl;
			cout << obj.getPrivateKey() << endl;

			cout << endl <<"note: " << endl;
			cout << "Private key must be kept secret and secure!" << endl;
			cout << "Public key is safe to share with others." << endl;

			break;
		}
		case 2:
		{	
			//cout << "Enter Public Key:" << endl;//format =>		n:e or n:d
			//takeKey(n, e);//take key inputs by reference
			//obj.setE(e);// Set Public key
			//obj.setN(n);//set private key
			
			obj.setE(307);// Set Public key
			obj.setN(746);//set private key
			system("cls");//clear console for better user expirence
			//nameOfFile = takeName();
			nameOfFile = "test.txt";
			file source(nameOfFile);

			cout << "File encryption in progress..." << endl;
			obj.encrypt_file(source);
			//system("cls");

			cout << "Encryption successful. Your file is now securely locked." << endl;
			break;
		}
		case 3:
		{
			//cout << "Enter private Key:" << endl;//format =>		n:e or n:d
			//takeKey(n, d);//take key inputs by reference
			//obj.setD(d);// Set Public key
			//obj.setN(n);//set private key

			obj.setD(103);// Set Public key
			obj.setN(746);//set private key


			system("cls");//clear console for better user expirence
			//nameOfFile = takeName(false);

			nameOfFile = "test.txt";
			file source(nameOfFile);

			cout << "File decryption in progress..." << endl;
			obj.decrypt_file(source);
			//system("cls");

			cout << "The decryption process has been completed successfully." << endl;
			break;
		}
		case 4:
		{
			return 0;
		}
		default:
		{
			cout << "Invalid Choice, Try Again" << endl;
			Sleep(1500);
			system("cls");
			goto home;
		}
		char x;
	
	}
	
	
	/*
	obj.setD(41);
	obj.setE(29);
	obj.setN(133);


	for (int i = 0; i < 256; i++) {
		// Encrypt the message (i) with exponent e
		unsigned long long encrypted = obj.encrypt_char(i);
		cout << "Original: " << i << ", Encrypted: " << encrypted;

		// Decrypt the encrypted message with exponent d
		unsigned long long decrypted = obj.decrypt_char(encrypted);
		if (decrypted != i) {
			cout << "Error at i = " << i << endl;
		}
		cout << ", Decrypted: " << decrypted << endl;
	}*/
	cout <<endl<< "Thank you for using the File Encryption & Decryption Program" << endl;
	
	return 0;
}