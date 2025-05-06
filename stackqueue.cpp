#include <iostream>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<cctype>

using namespace std;

//STACK
//LIFO
//adapter over other stl container, implemented as vector,list,deque
//top
//no iterators
//push,pop.top,empty?, size

//QUEUE
//FIFO
//adapter over implemented as list or deque
//no iterators are supported
//push,pop,front,back,empty,size

template<typename T>
void display ( stack<T> s ) { //pass by value to not disturb original stack
	while ( !s.empty ( ) ) {
		T t = s.top ( );
		s.pop ( );
		cout << t << " ";
		}
	cout << endl;
	}

template<typename T>
void displayq ( queue<T> s ) { //pass by value to not disturb original stack
	while ( !s.empty ( ) ) {
		T t = s.front ( );
		s.pop ( );
		cout << t << " ";
		}
	}

bool is_palindrome ( const string& str ) {
	stack<char> s; 
	queue<char> q;
	for ( auto& i : str ) {
		if(isalpha(i ) )
		s.push ( toupper(i) );
		}
	for ( auto& i : str ) {
		if ( isalpha ( i ) )
		q.push ( toupper(i) );
		}
	while ( !s.empty ( ) ) {
		char a { q.front ( ) };
		q.pop ( );
		char b { s.top ( ) };
		s.pop ( );
		if ( a != b ) return false;
		}
	return true;
	}

int main ( ) {
	stack<int> s; //deque by default
	queue<int> q; //deque by default
	queue<int , list<int>> q1;
	stack<int , vector<int>> s1;

	s.push ( 10 );
	s.push ( 20 );
	cout << s.size ( ) << endl;
	s.pop ( );
	cout << s.size ( ) << endl;
	s.push ( 1 );
	s.top ( ) = 100;
	display ( s );

	q.push ( 10 ); //back
	q.pop ( ); //front popped
	q.push ( 100 );
	q.push ( 30 );

	q.front ( ) = 10;
	q.back ( ) = 100;

	displayq ( q );

	string str = "a santa's AT nasa";

	if ( is_palindrome ( str ) ) cout << "\"" << str << "\"" << " is a palindrome." << endl;
	else cout << "\"" << str << "\"" << " is NOT a palindrome." << endl;
	}