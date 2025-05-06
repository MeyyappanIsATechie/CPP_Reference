#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>

using namespace std;

double calc ( int a , int b ) {
	if ( b == 0 ) throw 0; //throw ,return
	if ( a < 0 || b < 0 ) throw string ( "values cannot be negative" );
	return static_cast< double >( a ) / b;
	}

void c ( ) {
	cout << "starting c" << endl;
	throw 100;
	cout << "ending c" << endl;
	}

void b ( ) {
	cout << "starting b" << endl;
	try {
		c ( );
		}
	catch ( int& ex ) {
		cout << "error in func b" << endl;
		}
	cout << "ending b" << endl;
	}

void a ( ) {
	cout << "starting a" << endl;
	try {
		b ( );
		}
	catch ( int& ex ) {
		cout << "error in func a" << endl;
		}
	cout << "ending a" << endl;
	}

int main ( ) {
	//int km { };
	//int l { };
	//double kpl { };

	//cin >> km;
	//cin >> l;

	//try {
	//	//can alos use fucntion that may return exception
	//	/*if ( l == 0 ) throw 0;
	//	kpl = static_cast< double >( km ) / l;
	//	cout << kpl << endl;*/
	//	kpl = calc ( km , l );
	//	cout << kpl << endl;
	//	}
	//catch ( int& ex ) {
	//	cerr << "error dividing by zero";
	//	}
	////catch(...){}
	//catch ( string& ex ) {
	//	cerr << ex<<endl;
	//	}

	try {
		a ( );
		}
	catch ( int& x ) {
		cout << "error" << endl;
		}
	}