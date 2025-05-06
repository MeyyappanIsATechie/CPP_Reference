#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

void func ( shared_ptr<int> k1) {
	cout << k1.use_count ( ) << endl;
	}

int main ( ) {
	shared_ptr<int> p1 { new int{100 } };
	cout << p1.use_count ( ) << endl;

	shared_ptr<int> p2 { p1 };
	cout << p1.use_count ( ) << endl;

	p1.reset ( );

	cout << p1.use_count ( ) << endl;
	cout << p2.use_count ( ) << endl;

	vector<shared_ptr<int>> vec;

	shared_ptr<int> ptr { new int{100 } };

	vec.push_back ( ptr );

	cout << ptr.use_count ( ) << endl; //2

	//since cpp11 make_shared is there
	shared_ptr<int> pp1 = make_shared<int> ( 100 );
	shared_ptr<int> pp2 { pp1 };
	shared_ptr<int> pp3;
	pp3 = pp1;

	cout << pp1.use_count ( ) << endl;
	cout << pp2.use_count ( ) << endl;
	cout << pp3.use_count ( ) << endl;

	shared_ptr<int> pp = make_shared<int> ( 100 );
	func ( pp );
	cout << pp.use_count ( ) << endl; //temporarily 2 then 1

	{
	shared_ptr<int> ptr1 = ptr;
	cout << ptr.use_count ( ) << endl; //2
	{
	shared_ptr<int> ptr2 = ptr;
	cout << ptr.use_count ( ) << endl; //3
	ptr.reset ( ); // null,2,2
	}
	cout << ptr.use_count ( ) << endl; //0
	} // last pointer that refer4nces the memory is the one that cleans it
	cout << ptr.use_count ( ) << endl; //0
	}