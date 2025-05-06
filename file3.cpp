#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ( ) {
	//fstream out_file { "../cppfile.txt", ios::out };

	//fstream out_file2 { "../cppfile.txt",ios::out | ios::binary };

	//ofstream out_file3 { "../cppfile.txt",ios::out }; //same as ios::trunc

	//ofstream out_file4 { "../cppfile.txt" };

	//ofstream out_file5 { "../cppfile.txt",ios::binary };

	//append on each write
	ofstream out_file6 { "../cppfile.txt", ios::app };

	//seek to end of stream
	//ofstream out_file7 { "../cppfile.txt" ,ios::ate }; //or declare and .open(filename)

	int n { 1200 };
	double tot { 255.67 };
	string s { "Hello" };

	out_file6 <<"\n" << n << "\n" << tot << "\n" << s << endl;
	}