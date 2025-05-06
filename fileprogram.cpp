#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int main ( ) {
	ofstream out_file { "../output.txt",ios::app };
	if ( !out_file ) {
		cerr << "error creating file" << endl;
		return 1;
		}
	string line;
	cout << "enter something to write:";
	getline ( cin , line );

	out_file << line << endl;

	out_file.close ( );
	}