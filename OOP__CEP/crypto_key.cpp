#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include "crypto.h"
using namespace std;


//Key generation continue here
int crypto::getRandom()//this function return  any random number
{
	int x = rand() % 999 + 2;//rand() return random number
	//+2 means it should not be 0 or 1
	return x;
}

bool crypto::validatePrime(int x)
{
	for (int i = 2; i < x; i++)
	{
		// check each number if it is factor or not
		if (x % i == 0)
		{
			return false;// if yes means , it is not prime number
		}
	}
	return true;
}

int crypto::getPrime()
{
	int x = getRandom();
	while (!validatePrime(x))// repeatedly get random number until it is Prime
	{
		x = getRandom();
	}

	return x;

}
void crypto::calculateN(void)
{
	N = P * Q;
}

void crypto::calculateT(void)
{
	T = (P - 1) * (Q - 1);
}

void crypto::generateE(void)
{
	E = getPrime();

	if (E >= T)
	{
		generateE();
	}
	else if (T % E == 0)
	{
		generateE();
	}

}

void crypto::generateD(void)
{
	D = 1;
	while (!(((D * E) % T) == 1))
	{
		D++;
	}
}

void crypto::createKeys(void)
{

	P = getPrime();
	Q = getPrime();

	//we want number in between 256 to 1000
	while (P * Q < 256 || P * Q >1000)
	{
		P = getPrime();
		Q = getPrime();
	}
	calculateN();
	calculateT();
	generateE();
	generateD();

}
string crypto::getPublicKey(void)
{
	ostringstream output;
	output << "Your Public Key is \"" << N << ":" << E << "\" ";
	return output.str();
}

string crypto::getPrivateKey(void)
{
	ostringstream output;
	output << "Your Private Key is \"" << N << ":" << D << "\" ";
	return output.str();
}
