#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

//an interface is an abstract class with pure virtual functions
class I_Printable {
	friend ostream& operator<<( ostream& os , const I_Printable& obj );
public:
	virtual void print ( ostream& os ) const = 0;
	 };

ostream& operator<<( ostream& os , const I_Printable& obj ) {
	obj.print ( os ); //call it from here...using dynamic binding.. here's where abstract classes come into play.
	return os;
	}

class Account : public I_Printable {
public:
	virtual void print ( ostream& os ) const override {
		os << "Accounts display";
		}
	virtual~ Account( ){}
	};

class Checking :public Account {
public:
	virtual void print ( ostream& os ) const override {
		os << "Checking display";
		}
	virtual~Checking ( ){}
	};

int main ( ) {
	Account* p1 = new Account ( );
	cout << *p1 << endl;
	Account* p2 = new Checking ( );
	cout << *p2 << endl;
	}