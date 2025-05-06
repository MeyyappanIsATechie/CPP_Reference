#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

class A {
public:
	//virtual void abs_method ( ) = 0;
	virtual void display ( ) {
		cout << "hello from A" << endl;
		}
	virtual ~A ( ){}
	};

class B :public A {
public:
	void display ( ) override {
		cout << "hello from B" << endl;
		}
	~B ( ){}
	};

//class A: final prevents a class from overrding
//final in method level prevents virtual function from further overriding

void do_display ( A& a ) {
	a.display ( );
	}

//abstract class - cannot instantaitee obects, used as base   class in inhrritamcr hierarchird


int main ( ) {
	/*A* p1 = new A ( );
	A* p2 = new B ( );
	p1->display ( );
	p2->display ( );
	A* a [ ] = { p1,p2 };
	for ( int i = 0; i < 2; i++ ) {
		a [ i ]->display ( );
		}
	vector<A*> acc { p1,p2 };
	for ( auto i : acc ) {
		i->display ( );
		}
	delete p1;
	delete p2;*/

	A a;
	A& ref = a;
	ref.display ( );
	B b;
	A& ref2 = b;
	ref2.display ( );

	do_display ( a );
	do_display ( b );

	}