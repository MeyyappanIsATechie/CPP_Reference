#include <iostream>
#include<deque>
#include<algorithm>
#include<vector>
#include<cctype>

using namespace std;

//not stored in contiguous memory
//O(1) time element access
//O(1) insertion and deletion at front and back
//O(n) time insertion or removal of elements
//may invalidate
//insert delete both ways

bool is_palindrome ( const string& s ) {
	deque<char> d;
	for ( char i : s ) {
		if ( isalpha ( i ) ) {
			d.push_back ( toupper ( i ) );
			}
		}
	char a { };
	char b { };
	while ( d.size ( ) > 1 ) {
		a = d.front ( );
		b = d.back ( );
		d.pop_back ( );
		d.pop_front ( );
		if ( a != b ) return false;
		}
	return true;
	}

template<typename T>
ostream& operator<<( ostream& os , const deque<T>& v ) {
	for ( size_t i = 0; i < v.size ( ); i++ ) {
		os << v [ i ] << " ";
		}
	return os;
	}

int main ( ) {
	deque<string> d { string{"helo" },"world" };
	//simialr to some vector methods
	//additonally, push_front, pop_front, emplace_front

	vector<int> v { 1,2,3,4,5 };
	deque<int> dq;

	copy ( v.begin ( ) , v.end ( ) , front_inserter ( dq ) );
	cout << dq << endl;

	dq.clear ( );

	copy ( v.begin ( ) , v.end ( ) , back_inserter ( dq ) );
	cout << dq << endl;

	string s = "a santa's AT nada";

	if ( is_palindrome ( s ) ) cout << s << " is a palindrome." << endl;
	else cout << s << " is not a palindrome." << endl;
	}