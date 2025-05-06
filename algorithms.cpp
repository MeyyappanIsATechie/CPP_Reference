#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cctype>

using namespace std;

class Person {
	string name;
	int age;
public:
	Person ( ) = default;
	Person(string name,int age ):name{name },age{age } {}
	bool operator<( const Person& rhs ) const {
		return this->age < rhs.age;
		}
	bool operator==( const Person& rhs ) const {
		return ( this->name == rhs.name && this->age == rhs.age );
		}
	};

int main ( ) {
	vector<int> v { 1,2,3,4,5,1,1 };

	//common algorithms

	//find
	auto loc = find ( begin ( v ) , v.end ( ) , 1 );

	if ( loc != end ( v ) ) {
		cout << *loc << endl;
		}
	else {
		cout << "not found" << endl;
		}

	//count
	int n = count ( v.begin ( ) , v.end ( ) , 1 );

	cout << n << " times found" << endl;

	//count_if
	int n2 = count_if ( v.begin ( ) , v.end ( ) , [ ] ( int x ) {return x % 2 == 0; } );

	int n3 = count_if ( v.begin ( ) , v.end ( ) , [ ] ( int x ) {return x >= 5; } );

	//replace
	replace ( v.begin ( ) , v.end ( ) , 1 , 100 );

	string s1 { "this is a test" };

	transform ( s1.begin ( ) , s1.end ( ) , s1.begin ( ) , ::toupper );

	cout << s1 << endl;
	}