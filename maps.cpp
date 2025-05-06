#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

//associative
//fast retrieval using a key
//balanced binary trees or hashsets

//types:
//map
//unordered_map
//multimap
//unordered_multimap
//ordered by key
//all iterators available
//no front and back

//multi map
//allows duplicate
//in <map>

//unordered map
//#include<unordered>
//no duplicate elements
//no reverse iterators

//unordered_multimap
//unordered, duplicate allowed
//no reverse iterators

void disp ( const map<string , set<int>>& g ) {
	for ( auto it = g.begin ( ); it != g.end ( ); ++it ) {
		cout << it->first << " : ";
		for ( auto valIt = it->second.begin ( ); valIt != it->second.end ( ); ++valIt ) {
			cout << *valIt << " ";
			}
		cout << endl;
		}
	}

template<typename T1, typename T2>
void display(const map<T1,T2>& m){
	for ( const auto& i : m ) {
		cout << i.first << " : " << i.second;
		}
	}

int main () {
	map<string , string> m { {
			"bob","butcher"
 },
		{"anne", "baker" },
		{"george","police" }
		};

	pair<string , string> p1 { "catherine","teacher" };
	m.insert ( p1 ); //same as set, <iterator, bool> return
	m.insert ( make_pair ( "dorothy" , "poultry farmer" ) );
	m [ "ethan" ] = "teacher";

	m [ "ethan" ] = "profrssor";
	m.at ( "ethan" ) = "staff"; //does bounds checking of keys

	m.erase ( "anne" );
	if ( m.find ( "george" ) != m.end ( ) ) cout << "found george";

	//similarly, count, clear, and empty.

	auto it = m.find ( "george" );
	if ( it != m.end ( ) ) {
		cout << it->first << " : " << it->second << endl; //key, value // also operator= and swap
		}

	//m["bob"] is equivalent to it->second, if it points to bob...

	map<string , set<int>> g {
			{"abc",{100,90 } },
		{"def",{94 } },
		{"ghi",{70,80,80 } }
		};

	disp ( g );

	auto it2 = g.find ( "abc" );
	if ( it2 != g.end ( ) ) {
		it2->second.insert ( 100 );
		}
	disp ( g );

	}