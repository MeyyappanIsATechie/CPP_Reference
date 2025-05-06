#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

//dynamic size
//contiguous memory
//access O(1)
//insertion deletion back (constant), anywhere O(1)
//may invalidate

class Person {
	friend ostream& operator<<( ostream& os , const Person& p );
	string name;
	int age;
public:
	Person ( ) = default;
	Person ( string name , int age ) :name { name } , age { age } {}
	bool operator<( const Person& rhs ) const {
		return this->age < rhs.age;
		}
	bool operator==( const Person& rhs ) const {
		return ( this->name == rhs.name && this->age == rhs.age );
		}
	};

ostream& operator<<( ostream& os , const Person& p ) {
	os << p.name << ", " << p.age << ". " << endl;
	return os;
	}

template<typename T>
ostream& operator<<( ostream& os , const vector<T>& v ) {
	for ( size_t i = 0; i < v.size ( ); i++ ) {
		os << v [ i ] << " ";
		}
	//or
	//for ( const auto& i : v ) {
	//	os << i << " ";
	//	}
	//or
	//for_each ( v.begin ( ) , v.end ( ) , [ ] ( int x ) {cout << x << " "; } );
	return os;
	}

int main ( ) {
	vector<int> v { 1,2,3,4 };
	vector<int> v1 ( 10 , 100 );
	v = { 2,4,6,8 };
	cout << v.front ( )<<endl;
	cout << v.back ( )<<endl;
	cout << v.size ( ) << endl;
	cout << v.capacity ( )<<endl;
	cout << v.max_size( )<<endl;

	Person p1 { "larry",18 };
	vector<Person> vec;
	vec.push_back ( p1 ); //creates a copy
	vec.pop_back ( );

	vec.push_back ( Person { "Larry",18 } );

	vec.emplace_back ( "Larry" , 18 );

	cout << vec << endl;

	cout << vec.size ( ) << endl;
	cout << vec.capacity ( ) << endl;
	cout << vec.empty ( )<<endl;
	vec.swap ( vec ); // can be of different sizes with same type, unlike in the case of array

	reverse ( v.begin ( ) , v.end ( ) );

	cout << v << endl;

	sort ( v.begin ( ) , v.end ( ) );

	cout << v << endl;

	auto it = find ( v1.begin ( ) , v1.end ( ) , 100 );

	v1.insert ( it , 3 );

	it = find ( v1.begin ( ) , v1.end ( ) , 100 );

	vector<int> v2 = { 1,2,3 };

	v1.insert ( it , v2.begin ( ) , v2.end ( ) );

	cout << v1 << endl;

	v1.clear ( );

	cout << v1.size ( ) << endl;
	cout << v1.capacity ( ) << endl;

	vector<int> vtr { 1,2,3,4,5,6,7,8,9,0 };
	vtr.erase ( vtr.begin ( ) , vtr.begin ( ) + 2 );

	cout << vtr << endl;

	auto it2 = vtr.begin ( );

	while ( it2 != vtr.end ( ) ) {
		if ( *it2 % 2 == 0 )
			it2 = vtr.erase ( it2 );
		else
			it2++;
		}

	cout << vtr << endl;

	vector<int> a { 1,2,3,4,5 };
	vector<int> b { 10,20 };
	vector<int> c;

	copy ( a.begin ( ) , a.end ( ) , back_inserter(b));
	cout << a << endl;
	cout << b << endl;

	transform ( a.begin ( ) , a.end ( ) , b.begin ( ) , back_inserter ( c ) , [ ] ( int x , int y ) {return x * y; }); //where b should be the same size as a or larger

	auto it3 = find ( a.begin ( ) , a.end ( ) , 3 );
	if ( it3 != a.end ( ) ) {
		a.insert ( it3 , b.begin ( ) , b.end ( ) );
		}

	cout << c << endl;

	}