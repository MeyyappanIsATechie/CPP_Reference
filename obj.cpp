#include <iostream>
#include<vector>
#include<string>

using namespace std;

class A {
public:
	int x;
	A ( ) {
		x = 5;
		}

	A ( int n ) {
		x = n;
		}

	void show ( ) {
		cout << "x = " << x << endl;
		}
	};

int main ( ) {
	A o;
	o.show ( );
	cout << "x = " << o.x << endl;

	A* ptr = new A ( );
	ptr->show ( );
	cout << "x = " << ptr->x << endl;
	delete ptr;

	A ob ( 20 );
	ob.show ( );
	cout << "x = " << ob.x << endl;

	A* ptr2 = new A ( 30 );
	ptr2->show ( );
	cout << "x = " << ptr2->x << endl;
	delete ptr2;

	A arr [ 3 ];
	A* arr2 = new A [ 3 ];
	delete [ ] arr2;
	}