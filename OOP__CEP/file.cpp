#include <iostream>
#include<fstream>
#include <string>

#include "file.h"
using namespace std;

file::file(string n):fileName{n}
{
	read.open(fileName);
}

bool file :: isFileExist()//validate the existance of file
{
	ifstream file(fileName);
	if (file.is_open())
	{
		file.close();
		return true;
	}

	return false;
}

int file :: numberOfLines()//return the number of line in file
{
	int line=0;
	ifstream file;
	string n;
	file.open(fileName);

	while (getline(file, n))
	{
		line++;
	}
	file.close();
	return line;
}

string file:: readLineNum(int line)	//read the particular line number
{
	ifstream file;
	file.open(fileName);
	string result;

	int current_line = 0;
	while (getline(file, result))
	{
		current_line++;
		if (current_line == line)
		{
			file.close();
			return result;
		}
	}
	return "";
}

void file::writeFile(string data, bool newline )		//write in file (if file not created it create itself)
{
	string name ="ED_";
	name.append(fileName);
	ofstream out;
	out.open(name, std::ios_base::app | std::ios_base::out);
	//above line open the file and keep the previos data, new data will be continue.
	
	out << data;//send data to file
	if (newline)
	{
		out << "\n";//to change the line for future 
	}
	//out.flush();
	out.close();
}
