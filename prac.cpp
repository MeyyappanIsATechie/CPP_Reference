#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main ( ) {
	//char name [ 8] { "frank" };
	//name [ 5 ] = 'y';
	////cout << name;
	//char my_name [ 8 ];
	////strcpy ( my_name , "frank" );
	////cout << my_name;

	//string d { "this is a test" };
	//cout << d.substr ( 11 , 4 );
	string s;
	getline ( cin , s );
	for ( int i = 0; i < s.length ( ); i++ ) {
		for ( int j = 1; j < s.length ( ) - i; j++ ) {
			cout << " ";
			}
		cout << s.substr ( 0 , i + 1 );
		reverse ( s.begin ( ) , s.end ( ) );
		cout << s.substr ( s.length ( ) - i , i );
		reverse ( s.begin ( ) , s.end ( ) );
		cout << endl;
		}
	}