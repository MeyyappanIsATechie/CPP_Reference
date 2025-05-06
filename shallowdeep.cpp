#include <iostream>
#include<vector>
using namespace std;

class S {
private:
	int* data;
public:
	S ( int d );
	S ( const S& s );
	~S ( );
	void set_data ( int n ) {
		*data = n;
		}
	};

class D {
private:
	int* data;
public:
	D ( int d );
	D ( const D& src );
	~D ( );
	void set_data ( int n ) {
		*data = n;
		}
	};

D::D ( int d ) {
	data = new int;
	*data = d;
	}

D::~D ( ) {
	delete data;
	cout << "Destrcutor freeing data" << endl;
	}

D::D ( const D& s ) 
	{
	data = new int;
	*data = *s.data;
	cout << "copy constructor" << endl;
	}

//D::D ( const D& s ) 
//	:D ( *s.data ) {
//	cout << "copy constructor - delegation" << endl;
//	}

S::S ( int d ) {
	data = new int;
	*data = d;
	cout << "copy constructor" << endl;
	}

S::~S ( ) {
	delete data;
	cout << "Destrcutor freeing data" << endl;
	}

S::S ( const S& s ) :data ( s.data ) {
	cout << "copy constructor" << endl;
	}

void display(S o ){}

void display_deep(D o ){}

int main ( ) {
	S o1 { 100 };
	display ( o1 );

	o1.set_data ( 1000 );
	S o2 { o1 };
	cout << "Hello World" << endl;

	D do1 { 100 };
	display_deep ( do1 );

	do1.set_data ( 1000 );
	D do2 { do1 };
	cout << "Hello World" << endl;
	}