#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include "crypto.h"
using namespace std;


//logical member functions

//for encryption
unsigned int crypto::encrypt_char(unsigned int i)//encrypting character
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
    switch (x)
    {
        //each character if it is special escape sequence put extra backslash '\\'
    case '\n': return "\\n";    //new line character  
    case '\r': return "\\r";    //carriage return
    case '\t': return "\\t";    //horizontal tab
    case '\0': return "\\0";    //null character
    case '\x1A': return "\\x1A";//substitute character
    case '\b': return "\\b";    //backspace
    case '\f': return "\\f";    //form feed (new page)
    case '\v': return "\\v";    //vertical tab
    case '\a': return "\\a";    //bell (alert)
    case '\e': return "\\e";    //escape 

    default: return std::string(1, x); // Return the character itself if no escape is needed
    }
}

string crypto:: encrypt_character(unsigned char i)
{
    
	unsigned int n = encrypt_char(i);
   
	unsigned int part1 = 0, part2 = 0, part3 = 0, part4 = 0;
	string result = "";

    // Divide the number into four parts with each part being <= 250
    
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
   
    //convert each part into string and then append to single single string 
   
	result = ascii_string(part1);
	result.append(ascii_string(part2));
	result.append(ascii_string(part3));
	result.append(ascii_string(part4));

    //result represent encrypted form of single character
   

	return result;
}

void crypto::encrypt_string(string line)
{
	int size = line.size();         //first find the total characters to be encrypt
	encrypted_text = "";            //empty the temperary variable
	for (int i = 0; i < size; i++)
	{
        //encrypt each character
		encrypted_text.append(encrypt_character(line[i]));
	}
    //now encrypted text hold the encrypted line
    //ready to write in file
}

void crypto::encrypt_file(file& source, int cLine)
{
    //it will recieve the file object line to be read by default =1
    string data = source.readLineNum(cLine);//read the paricular line

    encrypt_string(data);//pass the string to encrypt
    
    source.writeFile(getEncryptedText());//write the encrypted data to new file

    if (cLine != source.numberOfLines())// check if source file is completely encrypt or not
    {
        //if not recall it self for the next line
        encrypt_file(source, cLine + 1);
    }

}


//decryption
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

unsigned int crypto:: decode_escape_sequence(const std::string& line, int& index) {
    if (line[index] == '\\' && index + 1 < line.size()) {
        
        switch (line[index + 1]) {
        case 't': index += 2; return '\t';//1
        case 'n': index += 2; return '\n';//2
        case '0': index += 2; return '\0';//3
        case 'r': index += 2; return '\r';//4
        case 'b': index += 2; return '\b';//5
        case 'f': index += 2; return '\f';//6
        case 'v': index += 2; return '\v';//7
        case 'a': index += 2; return '\a';//8
        case 'e': index += 2; return '\e';//9
        case 'x'://10
            {
                if (index + 3 < line.size() && line[index + 2] == '1' && line[index + 3] == 'A')
                {
                    index += 4; // Skip over "\x1A"
                    return 26; // ASCII value for control character SUB
                }
                break;
            }
        }
    }
    
    return static_cast<unsigned char>(line[index++]); // Return the current character and increment index
}

void crypto:: decrypt_string(string line) {
    int size = line.size();
    decrypted_text.clear(); // Initialize decrypted_text
    unsigned int temp;
    int i = 0;

    while (i < size) {
        unsigned int part1 = decode_escape_sequence(line, i);//retrive part 1
        unsigned int part2 = decode_escape_sequence(line, i);//retrive part 2
        unsigned int part3 = decode_escape_sequence(line, i);//retrive part 3
        unsigned int part4 = decode_escape_sequence(line, i);//retrive part 4

        temp = part1 + part2 + part3 + part4;        //add them to find the acctual enrypted character value
        decrypted_text.push_back(decrypt_char(temp));//decrypt character value and push to decrypted_text 
        
        // repeat untill all character are decrypted 
    }
    //once all lines decrypted, decrypted_text is ready to write in file
}

void crypto::decrypt_file(file& source, int cLine)//same logic as we previously done for encryption
{
	string data = source.readLineNum(cLine);

	decrypt_string(data);
	source.writeFile(getDecryptedText());

	if (cLine != source.numberOfLines())
	{
		decrypt_file(source, cLine + 1);
	}

}
