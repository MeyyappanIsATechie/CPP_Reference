#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

//class
class Mystring {
	//friend decarlation can be anywhere in class
	/*friend bool operator==( const Mystring& lhs , const Mystring& rhs );
	friend Mystring operator-( const Mystring& obj );
	friend Mystring operator+( const Mystring& lhs , const Mystring& rhs );*/
	friend ostream& operator<<(ostream& os , const Mystring& rhs );
	friend istream& operator>>( istream& in , Mystring& rhs );
private:
	char* str;
public:
	Mystring ( );
	Mystring ( const char* s );
	Mystring ( const Mystring& src );
	Mystring ( Mystring&& src );
	~Mystring ( );

	Mystring& operator=( const Mystring& rhs );
	Mystring& operator=( Mystring&& rhs );

	Mystring operator-( ) const;
	Mystring operator+( const Mystring& rhs ) const;
	bool operator==( const Mystring& rhs ) const;
	bool operator!=( const Mystring& rhs ) const;
	bool operator<( const Mystring& rhs ) const;
	bool operator>( const Mystring& rhs ) const;
	Mystring& operator+=( const Mystring& rhs );
	Mystring operator*( int n ) const;
	Mystring& operator*=( int n );
	Mystring operator++( );
	Mystring operator++( int );
	Mystring operator*( );
	void* operator new( size_t size );
	void operator delete( void* pointer ) noexcept;

	void display ( ) const;
	int get_length ( ) const;
	const char* get_str ( ) const;
	};

//noarg constrcutor
Mystring::Mystring ( )
	:str { nullptr } {
	str = new char [ 1 ];
	*str = '\0'; //str[0] = '\0'; 
	}

//arg constructor
Mystring::Mystring ( const char* s ) : str { nullptr } {
	if ( s == nullptr ) {
		str = new char [ 1 ];
		*str = '\0';
		}
	else {
		str = new char [ strlen ( s ) + 1 ];
		strcpy ( str , s );
		}
	}

//copy constructor
Mystring::Mystring ( const Mystring& src ) :str { nullptr } {
	str = new char [ strlen ( src.str ) + 1 ];
	strcpy ( str , src.str );
	}

//move constructor
Mystring::Mystring ( Mystring&& src ) : str { src.str } {
	src.str = nullptr;
	}

//copy assignemt overloading
Mystring& Mystring::operator=( const Mystring& rhs ) {
	if ( this == &rhs ) {
		return *this;
		}

	delete [ ] str;
	str = new char [ strlen ( rhs.str ) + 1 ];
	strcpy ( str , rhs.str );

	return *this;
	}

//move asisignemt overloading
Mystring& Mystring::operator=( Mystring&& rhs ) {
	if ( this == &rhs ) {
		return *this;
		}

	delete [ ] str;
	str = rhs.str;
	rhs.str = nullptr;

	return *this;
	}

//as member functions

//equality
bool Mystring::operator==( const Mystring& rhs ) const {
	return strcmp ( str , rhs.str ) == 0;
	}

//make lowercase
Mystring Mystring::operator-( ) const {
	char* buff = new char [ strlen ( str ) + 1 ];
	strcpy ( buff , str );
	for ( size_t i = 0; i < strlen ( buff ); i++ ) {
		buff [ i ] = tolower ( buff [ i ] );
		}
	Mystring temp { buff };
	delete [ ] buff;
	return temp;
	}

//concatentate
Mystring Mystring::operator+( const Mystring& rhs ) const {
	char* buff = new char [ strlen ( str ) + strlen ( rhs.str ) + 1 ];
	strcpy ( buff , str );
	strcat ( buff , rhs.str );
	Mystring temp { buff };
	delete [ ] buff;
	return temp;
	}

//additionassignment
Mystring& Mystring::operator+=( const Mystring& rhs ) {
	*this = *this + rhs;
	return *this;
	}

//repeat
Mystring Mystring::operator*( int n ) const {
	Mystring temp;
	for ( int i = 0; i < n; i++ ) {
		temp += *this;
		}
	return temp;
	}

//multiplication assignment
Mystring& Mystring::operator*=( int n ) {
	*this = *this * n;
	return*this;
	}

//pre-increment
Mystring Mystring::operator++( ) {
	for ( size_t i = 0; i < strlen ( str ); i++ ) {
		str [ i ] = toupper ( str [ i ] );
		}
	return *this;
	}

//post-increment
Mystring Mystring::operator++( int ) {
	Mystring temp { *this };
	operator++( );
	return temp;
	}

//non-equality
bool Mystring::operator!=( const Mystring& rhs ) const {
	return strcmp ( str , rhs.str ) != 0;
	}

//less than
bool Mystring::operator<( const Mystring& rhs ) const {
	return strcmp ( str , rhs.str ) < 0;
	}

//greater than
bool Mystring::operator>( const Mystring& rhs ) const {
	return strcmp ( str , rhs.str ) > 0;
	}

Mystring Mystring::operator*( ) {
	return *this;
	}

void* Mystring::operator new( size_t size ) {
	return malloc ( size );
	}

void Mystring::operator delete( void* pointer ) noexcept {
	free ( pointer );
	}

//destructor
Mystring::~Mystring ( ) {
	delete [ ] str;
	}


void Mystring::display ( ) const {
	cout << str << ":" << get_length ( ) << endl;
	}

int Mystring::get_length ( ) const {
	return strlen ( str );
	}

const char* Mystring::get_str ( ) const {
	return str;
	}

//anyone of the global overloading functions/member overloading function can only be used

//bool operator==( const Mystring& lhs , const Mystring& rhs ) {
//	return strcmp ( lhs.str , rhs.str ) == 0;
//	}
//
//Mystring operator-( const Mystring& obj ) {
//	char* buff = new char [ strlen ( obj.str ) + 1 ];
//	strcpy ( buff , obj.str );
//	for ( size_t i = 0; i < strlen ( buff ); i++ ) {
//		buff [ i ] = tolower ( buff [ i ] );
//		}
//	Mystring temp { buff };
//	delete [ ] buff;
//	return temp;
//	}
//
//Mystring operator+( const Mystring& lhs , const Mystring& rhs ) {
//	char* buff = new char [ strlen ( lhs.str ) + strlen ( rhs.str ) + 1 ];
//	strcpy ( buff , lhs.str );
//	strcat ( buff , rhs.str );
//	Mystring temp { buff };
//	delete [ ] buff;
//	return temp;
//	}

//insertion
ostream& operator<<( ostream& os , const Mystring& rhs ) {
	os << rhs.str;
	return os;

	}

//extraction
istream& operator>>( istream& is , Mystring& rhs ) {
	char* buff = new char [ 1000 ];
	is >> buff;
	rhs = Mystring { buff };
	delete [ ] buff;
	return is;
	}

int main ( ) {
	Mystring empty;
	Mystring larry { "Larry" };
	Mystring stooge { larry };

	empty.display ( );
	larry.display ( );
	stooge.display ( );

	

	Mystring s1 { "Meyyappan" };
	Mystring&& s2 = "abcd";
	//xxxxxxxxxxxxxxxxxxxxxx
	//Mystring s2 = s1; //not assignment
	//s2 = s1; //default shallowcopy assignment unless overloaded
	//xxxxxxxxxxxxxxxxxxxxxx
	//Mystring s3;
	//s3 = s2 = s1;

	//cout << "sbc";;

	Mystring s3 { s1++ + ++s2 };
	cout << s3<<" "<<s1;

	Mystring s4 { "Meyyappan" };
	cout << *s4 << endl;

	Mystring* s5 = new Mystring( );
	*s5 = "hello";
	cout << s5->get_str( );
	delete s5;

	//copy overloading

	//Type& Type::operator=(const Type &rhs);

	//move overloading

	//Type& Type::operator=(Type &&rhs);

	}

//class loc {
//	int longitude , latitude;
//public:
//	loc ( ) {}
//	loc ( int lg , int lt ) {
//		longitude = lg;
//		latitude = lt;
//		}
//	void show ( ) {
//		cout << longitude << " ";
//		cout << latitude << "\n";
//		}
//	loc operator+( loc op2 );
//	};
//// Overload + for loc.
//loc loc::operator+( loc op2 )
//	{
//	loc temp;
//	temp.longitude = op2.longitude + longitude;
//	temp.latitude = op2.latitude + latitude;
//	return temp;
//	}
//int main ( )
//	{
//	loc ob1 ( 10 , 20 ) , ob2 ( 5 , 30 );
//	ob1.show ( ); // displays 10 20
//	ob2.show ( ); // displays 5 30
//	ob1 = ob1 + ob2;
//	ob1.show ( ); // displays 15 50
//	return 0;
//	}