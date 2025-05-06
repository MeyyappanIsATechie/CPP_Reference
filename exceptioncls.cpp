#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<exception>

using namespace std;

//create exception cls and throw instances of those clses
//throw an obj not primitive type
//throq an obj by value
//catch an object by reference (const)

//member method throw exceptions
//cosntructors
//not in destructors

class NegValException: public exception {
	//NegValException ( ) = default;
	//~NegValException ( ) = default;
public:
	 virtual const char* what ( ) const noexcept override {
		return "neg value exception";
		}
	};

class A {
private:
	int a;
public:
	A ( int a ) :a { a } {
		if ( a < 0 ) throw NegValException ( );
		}
	};

class DivByZero {
	};



double calc ( int a , int b ) {
	if ( b == 0 ) throw DivByZero ( );
	if ( a < 0 || b < 0 ) throw NegValException ( );
	return static_cast< double >( a ) / b;
	}

int main ( ) {
	try {
		cout << calc ( 5 , 0 ) << endl;
		}
	catch ( const DivByZero& ex ) {
		cerr << "cant divide by zero" << endl;
		}
	catch ( const NegValException& ex ) {
		cerr << "negative values arent allowed" << ex.what() << endl;
		}

	try {
		A* a = new A (-1 );
		}
	catch ( NegValException& ex ) {
		cerr << "couldn't create account " <<ex.what()<< endl;
		}
	catch ( exception& e ) {
		cerr << e.what ( ) << endl;
		}
	}