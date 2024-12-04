#include <iostream>
#include <windows.h>
#include "file.h"
using namespace std;

void animation()
{
	cout << "\t<"; Sleep(60);
	cout << "F"; Sleep(60);
	cout << "i"; Sleep(60);
	cout << "l"; Sleep(60);
	cout << "e"; Sleep(60);
	cout << " "; Sleep(60);
	cout << "E"; Sleep(60);
	cout << "n"; Sleep(60);
	cout << "c"; Sleep(60);
	cout << "r"; Sleep(60);
	cout << "y"; Sleep(60);
	cout << "p"; Sleep(60);
	cout << "t"; Sleep(60);
	cout << "i"; Sleep(60);
	cout << "o"; Sleep(60);
	cout << "n"; Sleep(60);
	cout << " "; Sleep(60);
	cout << "&"; Sleep(60);
	cout << " "; Sleep(60);
	cout << "D"; Sleep(60);
	cout << "e"; Sleep(60);
	cout << "c"; Sleep(60);
	cout << "r"; Sleep(60);
	cout << "y"; Sleep(60);
	cout << "p"; Sleep(60);
	cout << "t"; Sleep(60);
	cout << "i"; Sleep(60);
	cout << "o"; Sleep(60);
	cout << "n"; Sleep(60);
	cout << endl << endl;
}
int mainMenu(void)
{
	int x;

	cout << "<<Menu>>" << endl << endl;
	cout << "1. Generate Pair Of Keys" << endl;
	cout << "2. Encrypt The File" << endl;
	cout << "3. Decrypt the File" << endl;
	cout << "4. Exit" << endl;

	cin >> x;
	

	return x;
}


void takeKey(int& a, int& b)
{
	char temp;
	while (true)
	{
		
		cin >> a >> temp >> b;

		if ((temp != ':') || (a < 1) || (b < 1))//we might change it in future 
		{
			cout << "Ivalid key or Invalid Format, Please try again" << endl;
			Sleep(1500);
			system("cls");
			continue;
		}
		break;
	}

}


string takeName(bool validate)
{
	string input;
	cin.clear();
	cin.ignore(10000, '\n');
	while (true)
	{
		input = "";
		cout << "Write Source File Name:" << endl;
		cout << "Note: only \".txt\" format is allowed and no space in File name." << endl;

		// Now, get the file name input from the user
		getline(cin, input);

		int size = input.size();

		// Check if the file name is too short to be valid
		if (size < 4) {
			cout << "File name too short. Please try again." << endl;

			Sleep(1500);
			system("cls");
			continue;
			
		}
		// Check if the last 4 characters are ".txt"
		if ((input[size - 4] != '.') || (input[size - 3] != 't') || (input[size - 2] != 'x') || (input[size - 1] != 't')) {
			cout << "Invalid file extension, please try again." << endl;

			Sleep(1500);
			system("cls");
			continue;
		}

		//validate if file exist or not
		file check(input);
		if (validate)
		{
			if (check.isFileExist())
			{
				break;
			}
			else
			{
				cout << "No Such File found. Please Recheck And Try Again." << endl;

				Sleep(1500);
				system("cls");
				continue;
			}
		}
		else
		{
			break;
		}
	}
	return input;
}
