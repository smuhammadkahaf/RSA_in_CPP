#include<iostream>
#include <string>
#include <fstream>

using namespace std;
#ifndef FILE_H
#define FILE_H

class file {
	public:
		string fileName;
		ifstream read;//take input from file
		
	public:
		file(string);	//constructor

		bool isFileExist (void);				//check file existance
		int numberOfLines(void);			//find number of lines in file
		string readLineNum(int);			//read the particular line number
		
		void writeFile( string data ,bool =true );	//write in file (if file not created it create itself)
		
		
};



#endif