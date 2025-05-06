#include <iostream>
#include<vector>
#include<list>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<forward_list>
#include<iterator>

//lists

//bidirectional (DLL)
//direct access not provided
//O(1) insertion and deletion
//iterators invalidate when corresponding element is invalidated
//at [] not available
//inserts left of iterator

//forward lists

//unidirectional (SLL)
//reverse iterators not available
//only front() available, neither back() not size() (memory overhead)
//provides _after methods

using namespace std;

template<typename T>
ostream& operator<<( ostream& os , const list<T>& v ) {
	for ( const auto& i : v ) {
		cout << i << " ";
		}
	return os;
	}

template<typename T>
ostream& operator<<( ostream& os , const forward_list<T>& v ) {
	for ( const auto& i : v ) {
		cout << i << " ";
		}
	return os;
	}

int main ( ) {
	list<int> l { 1,2,3,4,5 };
	cout << l.front ( )<<endl;
	auto it = find ( l.begin ( ) , l.end ( ) , 3 );

	l.insert ( it , 10 );
	cout << l << endl;
	list<int> t { 6,7,8 };
	l.insert ( it , t.begin ( ) , t.end ( ) );
	cout << l << endl;
	advance ( it , -4 ); //advance 4 positionss to left, in #include <iterator>
	l.erase ( it );
	cout << l << endl;
	l.resize ( 2 );
	cout << l << endl;
	l.resize ( 5 );
	cout << l << endl;

	//we can dereference iterators to get value and manipulate it (++,--).

	//forward list

	forward_list<int> l2 { 1,2,3,4,5 };
	auto it2 = find ( l2.begin ( ) , l2.end ( ) , 3 );

	l2.insert_after ( it2 , 10 );
	l2.emplace_after ( it2 , 100 );
	cout << l2 << endl;
	l2.erase_after ( it2 );
	cout << l2 << endl;
	l2.resize ( 2 );
	cout << l2 << endl;
	l2.resize ( 5 );
	cout << l2 << endl;
	}