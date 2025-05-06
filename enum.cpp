#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

enum State {
	eng_failure = 0,
	bad_weather = 1,
	nominal = 2
	};

enum Sequence {
	abortt = 3,
	hold = 4, 
	launch = 5
	};

enum Dir {
	North,
	South,
	East,
	West
	};

//enum Street {Main, North, Elm} cant use in unscoped since north is ambiguous


//can also overload insertion << operator 

string direction_to_string ( Dir dir ) {
	string res;
	switch ( dir ) {
		case North:
			res = "North";
			break;
		case South:
			res = "South";
			break;
		case East:
			res = "east";
			break;
		case West:
		res = "west";
		break;
		default:
			res = "unknown";
		}
	return res;
	}

int main ( ) {
	int n;
	cin >> n;
	State state = State ( n );

	//or

	underlying_type_t<State> m;
	cin >> m;
	State state2 = State ( m ); //or use switch to assign to avoid invalid options 

	Sequence s1 = abortt;
	Sequence s2 = hold;
	Sequence s3 = launch;  

	if ( state == eng_failure ) cout << s1 << endl;
	else if ( state == bad_weather ) cout << Sequence ( 4 ) << endl;
	else cout << Sequence ( 5 ) << endl;

	Dir dir { North };
	cout << dir << endl;
	cout << direction_to_string ( dir ) << endl;

	dir = static_cast<Dir> ( 100 );
	cout << direction_to_string ( dir ) <<endl;
	}