#include <iostream>
#include<vector>

using namespace std;

template<typename T, int N>
class Array {
	int size {N };
	T values [ N ];

	friend ostream& operator<<( ostream& os , const Array<T, N>& arr ) {
		for ( const auto& v : arr.values )
			os << v << " ";
		return os;
		}
public:
	Array ( ) = default;
	Array ( T v ) {
		for ( auto& i : values ) {
			i = v;
			}
		}
	void fill ( T n ) {
		for ( auto& i : values ) {
			i = n;
			}
		}
	int get_size ( ) const {
		return size;
		}

	T& operator[]( int i ) {
		return values [ i ];
		}
	};

int main ( ) {
	Array<int,5> a;
	a.get_size ( );
	cout << a << endl;

	a.fill ( 0 );
	cout << a.get_size ( ) << endl;
	cout << a << endl;

	a.fill ( 10 );
	cout << a << endl;

	a [ 0 ] = 1000;
	a [ 3 ] = 2000;
	cout << a << endl;

	Array<int,100> b { 1 };
	cout << b.get_size ( ) << endl;
	cout << b << endl;

	Array<string , 10> c { string{"hello" } };
	cout << c.get_size ( ) << endl;
	cout << c << endl;

	c [ 0 ] = string { "bye" };
	cout << c << endl;

	c.fill ( string { "x" } );
	cout << c << endl;
	}