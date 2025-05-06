#include <iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

int main ( ) {

	//OPERATORS
	vector<int> n { 1,2,3,4,5 };
	auto it = n.begin ( ); // or vector<int>::iterator it1 = ...

	cout << *it << endl;

	it++;

	cout << *it << endl;

	it += 2;

	cout << *it << endl;

	it = n.end ( ) - 1;

	cout << *it << endl;

	//ITERATING

	it = n.begin ( );

	while ( it != n.end ( ) ) {
		cout << *it << endl;
		it++;
		}

	it = n.begin ( );
	while ( it != n.end ( ) ) {
		*it = 0;
		it++;
		}

	it = n.begin ( );

	while ( it != n.end ( ) ) {
		cout << *it << endl;
		it++;
		}

	//COSNT ITERATOR
	vector<int>::const_iterator it1 = n.begin ( );
	//auto it1 = n.cbegin();

	//cannot modify

	//REVERSE ITERATOR
	auto it2 = n.rbegin ( );
	while ( it2 != n.rend ( ) ) {
		cout << *it2 << endl;
		it2++;
		}

	//CONSTANT REVERSE ITERATOR
	list<string> name { "alpha","beta","gamma" };
	auto it3 = name.crbegin ( );
	cout << *it3 << endl;
	it3++;
	cout << *it3 << endl;

	map<string , string> mp {
			{"alpha","one" },
		{"beta","two" },
		{"gamma", "three" }
		};
	auto it4 = mp.begin ( );
	while ( it4 != mp.end ( ) ) {
		cout << it4->first << ":" << it4->second << endl;
		it4++;
		}

	auto start = n.begin ( ) + 2;
	auto finish = n.end ( ) - 1;
	while ( start != finish ) {
		cout << *start << endl;
		start++;
		}
	}