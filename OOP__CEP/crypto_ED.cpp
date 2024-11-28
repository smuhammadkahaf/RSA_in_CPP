#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include "crypto.h"
using namespace std;




//logical member functions
unsigned int crypto::encrypt_char(unsigned char i)//encrypting character
{
	unsigned long long exp = E;//ensuring data member value not change
	unsigned long long msg = i;
	unsigned long long result = 1;
	msg = msg % N;  // Ensure the msg is less than N initially

	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * msg) % N;
		}
		exp = exp / 2;  // Divide exp by 2 (equivalent to exp = exp >> 1
		msg = (msg * msg) % N;  // Square the msg
	}

	return result;
}
string crypto::ascii_string(unsigned int x) {
    string result = "";
    unsigned char i = x;
    if (i == '\n') {
        result.push_back('\\');
        result.push_back('n');
    }
    else if (i == '\r') {
        result.push_back('\\');
        result.push_back('r');
    }
    else if (i == '\t') {
        result.push_back('\\');
        result.push_back('t');
    }
    else if (i == '\0') {
        result.push_back('\\');
        result.push_back('0');
    }
    else {
        result.push_back(i); // Correctly handle the integer
    }

   

    return result;
}

string crypto:: encrypt_character(unsigned char i)
{
    
	unsigned int n = encrypt_char(i);
   
	unsigned int part1 = 0, part2 = 0, part3 = 0, part4 = 0;
	string result = "";

    // Divide the number into four parts with each part being <= 255
    if (n > 250) 
	{
        part1 = 250;
        n -= 250;
    }
	else 
	{
        part1 = n;
        n = 0;
    }

    if (n > 250)
	{
        part2 = 250;
        n -= 250;
    } 
	else 
	{
        part2 = n;
        n = 0;
    }

    if (n > 250) 
	{
        part3 = 250;
        n -= 250;
    }
	else 
	{
        part3 = n;
        n = 0;
    }

    // The remaining part goes to part4
    part4 = n;
   
   
	result = ascii_string(part1);
	result.append(ascii_string(part2));
	result.append(ascii_string(part3));
	result.append(ascii_string(part4));

   

	return result;
}

unsigned char crypto::decrypt_char(unsigned int i)//encrypting character
{
	unsigned long long exp = D;//ensuring data member value not change
	unsigned long long msg = i;
	unsigned long long result = 1;
	msg = msg % N;  // Ensure the msg is less than N initially

	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * msg) % N;
		}
		exp = exp / 2;  // Divide exp by 2 (equivalent to exp = exp >> 1
		msg = (msg * msg) % N;  // Square the msg
	}
	
	return result;
}


void crypto::encrypt_string(string line)
{
	int size = line.size();
	encrypted_text = "";
	for (int i = 0; i < size; i++)
	{
		encrypted_text.append(encrypt_character(line[i]));
	}
}

void crypto::decrypt_string(string line)
{
    int size = line.size();
    decrypted_text = "";  // Initialize decrypted_text
    unsigned int temp;  // Temporary string to accumulate decrypted characters
    int i = 0;

    while (i < size && size-i>=4)
    {
        // Step 1: Retrieve the four parts (each can be an escaped character or regular character)
        unsigned int part1 = 0, part2 = 0, part3 = 0, part4 = 0;

        // Retrieve part 1
        if (line[i] == '\\' && i + 1 < line.size()) {
            // Handle escape sequences for part 1
            if (line[i + 1] == 't') {
                part1 = '\t';
                i += 2;  // Skip '\\' and 't'
            }
            else if (line[i + 1] == 'n') {
                part1 = '\n';
                i += 2;  // Skip '\\' and 'n'
            }
            else if (line[i + 1] == '0') {
                part1 = '\0';
                i += 2;  // Skip '\\' and '0'
            }
            else if (line[i + 1] == 'r') {
                part1 = '\r';
                i += 2;  // Skip '\\' and 'r'
            }
            else {
                part1 = static_cast<int>(static_cast<unsigned char>(line[i]));
                i++;  // Skip the '\\'
            }
        }
        else {
            part1 = static_cast<int>(static_cast<unsigned char>(line[i]));
            i++;
        }

        // Retrieve part 2
        if (line[i] == '\\' && i + 1 < line.size()) {
            // Handle escape sequences for part 2
            if (line[i + 1] == 't') {
                part2 = '\t';
                i += 2;
            }
            else if (line[i + 1] == 'n') {
                part2 = '\n';
                i += 2;
            }
            else if (line[i + 1] == '0') {
                part2 = '\0';
                i += 2;
            }
            else if (line[i + 1] == 'r') {
                part2 = '\r';
                i += 2;
            }
            else {
                part2 = static_cast<int>(static_cast<unsigned char>(line[i]));
                i++;
            }
        }
        else {
            part2 = static_cast<int>(static_cast<unsigned char>(line[i]));
            i++;
        }

        // Retrieve part 3
        if (line[i] == '\\' && i + 1 < line.size()) {
            // Handle escape sequences for part 3
            if (line[i + 1] == 't') {
                part3 = '\t';
                i += 2;
            }
            else if (line[i + 1] == 'n') {
                part3 = '\n';
                i += 2;
            }
            else if (line[i + 1] == '0') {
                part3 = '\0';
                i += 2;
            }
            else if (line[i + 1] == 'r') {
                part3 = '\r';
                i += 2;
            }
            else {
                part3 = static_cast<int>(static_cast<unsigned char>(line[i]));
                i++;
            }
        }
        else {
            part3 = static_cast<int>(static_cast<unsigned char>(line[i]));
            i++;
        }

        // Retrieve part 4
        if (line[i] == '\\' && i + 1 < line.size()) {
            // Handle escape sequences for part 4
            if (line[i + 1] == 't') {
                part4 = '\t';
                i += 2;
            }
            else if (line[i + 1] == 'n') {
                part4 = '\n';
                i += 2;
            }
            else if (line[i + 1] == '0') {
                part4 = '\0';
                i += 2;
            }
            else if (line[i + 1] == 'r') {
                part4 = '\r';
                i += 2;
            }
            else {
                part4 = static_cast<int>(static_cast<unsigned char>(line[i]));
                i++;
            }
        }
        else {
            part4 = static_cast<int>(static_cast<unsigned char>(line[i]));
            i++;
        }

        temp = part1 + part2 + part3 + part4;
        decrypted_text.push_back(decrypt_char(temp));
    }
}

void crypto::encrypt_file(file& source, int cLine)
{
	string data = source.readLineNum(cLine);
    
	encrypt_string(data);
	source.writeFile(getEncryptedText());

	if (cLine != source.numberOfLines())
	{
		encrypt_file(source, cLine + 1);
	}

}
void crypto::decrypt_file(file& source, int cLine)
{
	string data = source.readLineNum(cLine);

	decrypt_string(data);
	source.writeFile(getDecryptedText());

	if (cLine != source.numberOfLines())
	{
		decrypt_file(source, cLine + 1);
	}

}
