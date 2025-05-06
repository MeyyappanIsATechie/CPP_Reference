#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main ( ) {
	int n { };
	double t { };
	string name { };

	string info { "String 100 1234.5" };
	istringstream iss { info };

	iss >> name >> n >> t;
	cout << setw ( 10 ) << left << name << setw ( 5 ) << n << setw ( 10 ) << t << endl;

	ostringstream oss { };
	oss << setw ( 10 ) << left << name << setw ( 5 ) << n << setw ( 10 ) << t << endl;

	cout << oss.str ( ) << endl;

	//data validation using ss

	int v { };
	string s { };
	bool done = false;
	do {
		cout << "enter an integer: ";
		cin >> s;
		istringstream ss { s };
		if ( ss >> v ) {
			done = true;
			}
		else {
			cout << "sorry not an integer" << endl;
			}

		//dsicard input buffer
		cin.ignore ( numeric_limits<streamsize>::max ( ) , '\n' );
		} while ( !done );

	} 