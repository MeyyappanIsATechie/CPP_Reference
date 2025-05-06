#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class B;

class A {
	shared_ptr<B> b_ptr;
public:
	void set_B ( shared_ptr<B>& b ) {
		b_ptr = b;
		}
	A ( ) {
		cout << "A constructor" << endl;
		}
	~A ( ) {
		cout << "A destructor" << endl;
		}
	};

class B {
	weak_ptr<A> a_ptr; //if not memory will leak
public:
	void set_A ( shared_ptr<A>& a ) {
		a_ptr = a;
		}
	B ( ) {
		cout << "B constructor" << endl;
		}
	~B ( ) {
		cout << "B destructor" << endl;
		}
	};

class Test {
private:
	int data;
public:
	Test ( ) :data { 0 } {
		cout << "test constructor" << endl;
		}
	Test ( int data ) :data {data} {
		cout << "Test constructor"<<endl;
		}
	int get_data ( ) const {
		return data;
		}
	~Test ( ) {
		cout << "Test destructor" << endl;
		}
	};

void deleter ( Test* ptr ) {
	cout << "using custom function deleter" << endl;
	delete ptr;
	}

int main ( ) {
	shared_ptr<A> a = make_shared<A> ( );
	shared_ptr<B> b = make_shared<B> ( );
	a->set_B ( b );
	b->set_A ( a );
		/*{
		shared_ptr<Test> ptr1 { new Test{100 },deleter };
		}
		{
		shared_ptr<Test> ptr1 ( new Test { 100 } , [ ] ( Test* ptr ) {
			delete ptr;
			} );
		}*/
	}