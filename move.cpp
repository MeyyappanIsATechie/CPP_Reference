#include<iostream>
#include<vector>

using namespace std;

//return value optimization 

//class A {
//public:
//	A ( ) {
//		cout << "constructor" << endl;
//		}
//	A ( const A& ) {
//		cout << "copy constructor" << endl;
//		}
//	};
//
//A fun ( ) {
//	return A ( ); //doesnt call copy construcotr
//	}

class D {
private:
	int* data;
public:
	D ( int d );
	D ( const D& src );//copy
	D ( D&& src ) noexcept;
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
	if ( data != nullptr ) {
		cout << "destructor freeing data for: " << *data << endl;
		}
	else { 
		cout << "destructor freeing data for nullptr" << endl;
		}
	delete data;
	cout << "Destrcutor freeing data" << endl;
	}

D::D ( const D& s ) 
	:D ( *s.data ) {
	cout << "copy constructor - delegation" << endl;
	}

D::D ( D&& src ) noexcept //for rvalue
	:data { src.data } {
	src.data = nullptr;
	cout << "move constructor" << *data << endl;
	}

int main ( ) {
	/*int x { 100 };
	int& lref = x;
	lref = 10;

	int&& rref = 200;
	rref = 300;*/

	vector<D> vec;
	vec.push_back ( D { 10 } );
	}