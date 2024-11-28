#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include "crypto.h"
using namespace std;


//constructors
crypto::crypto() :fileName{ "" }, P{ 0 }, Q{ 0 }, N{ 0 }, T{ 0 }, E{ 0 }, D{ 0 }, encrypted_text{ "" }, decrypted_text{ "" }	//default constructor
{

}

crypto::crypto(string n) : P{ 0 }, Q{ 0 }, N{ 0 }, T{ 0 }, E{ 0 }, D{ 0 }, encrypted_text{ "" }, decrypted_text{ "" }//with file name
{
	fileName = n;
}

crypto::crypto(string n, int e) : P{ 0 }, Q{ 0 }, N{ 0 }, T{ 0 }, D{ 0 }, encrypted_text{ "" }, decrypted_text{ "" } //file name + public key
{
	fileName = n;
	E = e;
}

crypto::crypto(string n, int e, int d) : P{ 0 }, Q{ 0 }, N{ 0 }, T{ 0 }, encrypted_text{ "" }, decrypted_text{ "" }//file name +public key + private key
{
	fileName = n;
	E = e;
	D = d;
}

//setters for each data member
void crypto::setFileName(string n)	//set file name
{
	fileName = n;
}

void crypto::setP(int p)	//set 1st prime number
{
	P = p;
}
void crypto::setQ(int q)	//set 2nd prime number
{
	Q = q;
}
void crypto::setN(int n)	//set product
{
	N = n;
}
void crypto::setT(int t)	//set Totient
{
	T = t;
}
void crypto::setE(int e)	//set Public key
{
	E = e;
}
void crypto::setD(int d)	//set private key
{
	D = d;
}

//getters for each data members

string crypto::getFileName(void)	//get file name
{
	return fileName;
}
int crypto::getP(void)	// get 1st prime number
{
	return P;
}
int crypto::getQ(void)	//get 2nd prime number
{
	return Q;
}
int crypto::getN(void)	//get Product
{
	return N;
}
int crypto::getT(void)	//get totient
{
	return T;
}
int crypto::getE(void)	//get Public key
{
	return E;
}
int crypto::getD(void)	//get private key
{
	return D;
}
string crypto::getEncryptedText(void)
{
	return encrypted_text;
}
string crypto::getDecryptedText(void)
{
	return decrypted_text;
}
