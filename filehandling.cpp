#include <iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main ( ) {
	fstream in_file { "../cppfile.txt", ios::in };

	//fstream in_file {"D:\\files\\cppfile.txt", ios::in | ios::binary};

	//or 

	//ifstream in_file { "D:\\files\\cppfile.txt" };

	//or

	/*ifstream in_file_2;

	string file = "D:\\files\\cppfile2.txt";

	in_file_2.open ( file );*/

	//check if file is opened

	if ( in_file.is_open ( ) ) { //( in_file_2 )
		int a { };
		int b { };
		in_file >> a >> b;
		string line { };
		cout << a << " " << b << endl;
		while ( !in_file.eof ( ) ) {
			getline ( in_file , line );
			cout << line << endl;
			}
		//or
		// 
		//char c{};
		//while(in_file.get(c)){
		// cout<<c;
		//}
		}

	else {
		cerr << "file opening error" << endl;
		}

	in_file.close ( );
	//in_file_2.close ( );

	}