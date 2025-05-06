#include<iostream>
#include<set>

//associative containers
//fast retrieval using key
//balanced binary tree (red black) set / hashamps unrdered_set
//efficient

//types:
//set
//unordered_set
//multiset
//unordered_multoset
//ordered by key

//size,max_size
//not .at, [], fornt(), back()
//insert(n) available

//multi set:
//sorted by key
//allows duplicate elements
//all iterators available

//unordered set:
//no duplicates
//unordered
//cannot be modifies...erased and inserted
//no reverse iterators

//unordered_multiset
//duplicates, no reverse iterators

using namespace std;

template<typename T>
ostream& operator<<( ostream& os , const set<T>& v ) {
	for ( const auto& i : v ) {
		cout << i << " ";
		}
	return os;
	}

int main ( ) {
	set<int> s;
	int a = 5 , b = 6;
	s.insert ( a );

	auto res = s.insert ( b ); //returns pair<iterator,bool> 
							   //if successful newly pointed character, and true. 
                               //else, iterataor points to already existing characater. and false.
	cout << s << endl;
	s.erase ( a );

	cout << s << endl;

	auto it = s.find ( a ); //set verwsion of find
	if ( it != s.end ( ) ) s.erase ( it );

	int n = s.count ( 6 ); //obv. either going to be 0 or 1
	s.clear ( );
	bool is_empty = s.empty ( ); //bool
	}