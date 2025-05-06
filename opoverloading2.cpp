#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class Complex {
	friend ostream& operator<<( ostream& os , const Complex& c );
private:
	double real , img;
public:
	Complex(double r = 0, double i = 0 ): real{r },img{i }{}

	Complex ( const Complex& other ) = default;

	double getReal ( ) const {
		return real;
		}
	double getImg ( ) const {
		return img;
		}

	Complex operator+( const Complex& rhs ) const {
		return Complex ( real + rhs.real , img + rhs.img );
		}

	Complex& operator+=( const Complex& obj ) {
		real += obj.real;
		img += obj.img;
		return *this;
		}

	bool operator==( const Complex& rhs ) const {
		return real == rhs.real && img == rhs.img;
		}

	bool operator!=( const Complex& rhs ) const {
		return !( *this == rhs );
		}

	};

ostream& operator<<( ostream& os , const Complex& c ) {
	os << c.getReal ( ) << " " << c.getImg ( ) << endl;
	return os;
	}

class Logger {
private:
	string* s;
	size_t size;
public:
	void* operator new( size_t n ) {
		return ::operator new( n );
		}

	void operator delete( void* ptr ) {
		::operator delete( ptr );
		}

	Logger ( size_t n ) :size { n } {
		s = new string [ size ];
		}

	~Logger ( ) {
		delete [ ] s;
		}

	string& operator[]( size_t i ) {
		if ( i >= size ) throw out_of_range ( "index out of range" );
		return s [ i ];
		}

	Logger* operator->( ) {
		return this;
		}

	void print ( ) {
		for ( size_t i = 0; i < size; i++ ) {
			cout << s [ i ] << endl;
			}
		}
	};

int main ( ) {
	Logger* l = new Logger ( 3 );
	( *l ) [ 0 ] = "hello";
	cout << ( *l )[0 ].length( ) << endl;
	cout << ( *l ) [ 0 ].max_size( ) << endl;
	( *l ) [ 1 ] = "world";
	( *l ) [ 2 ] = "!";
	try {
		( *l ) [ 3 ] = "ehe";
		}
	catch ( const out_of_range& e ) {
		cerr << e.what ( ) << endl;
		}

	l->print ( );

	delete l;
	}