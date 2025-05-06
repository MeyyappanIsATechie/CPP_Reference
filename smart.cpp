#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

int main ( ) {
	unique_ptr<int> p1 { new int{100 } };
	cout << *p1 << endl;
	*p1 = 200;
	//unique_ptr<int> p2 { p1 };
	cout << *p1 << endl;
	cout << p1.get( ) << endl;

	p1.reset ( ); //nullptr

	if ( p1 ) { 
		cout << *p1 << endl;
		}

	vector<unique_ptr<int>> vec;
	unique_ptr<int> ptr { new int{100 } };
	//vec.push_back ( ptr );
	vec.push_back ( move ( ptr ) ); //ptr set to null

	for ( const auto& i : vec ) { //csn only loop through reference
		cout << *i << endl;
		}

	//cpp 14-make unique, no need of new or delete

	unique_ptr<int> up1 = make_unique <int> ( 100 );
	auto up2 = make_unique<double> ( 102.3 ); 

	auto up3 = move ( up2 ); //up2 nullptr

	cout << *up3 << endl;

	/*
	unique_ptr<A> up1 = make_unique<B> ( 100 );
	auto up2 = make_unique<Child> ( 102.3 ); 
	*/

	int* p = up1.release( );
	delete p;

	double* rp = up2.get ( );
	delete rp; // doesnt delete up2

       
	struct MyClass {
		MyClass ( ) {
			std::cout << "MyClass constructor\n";
			}
		~MyClass ( ) {
			std::cout << "MyClass destructor\n";
			}
		void greet ( ) {
			std::cout << "Hello from MyClass!\n";
			}
		};
		// Using make_unique for construction
		std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass> ( );
		ptr1->greet ( );  // Accessing object through operator->

		// Using get()
		MyClass* rawPtr = ptr1.get ( );
		rawPtr->greet ( );  // Accessing object through raw pointer

		// Using reset()
		ptr1.reset ( );  // Destroying current object, ptr1 is now nullptr

		// Using release()
		std::unique_ptr<MyClass> ptr2 = std::make_unique<MyClass> ( );
		MyClass* releasedPtr = ptr2.release ( );  // ptr2 no longer owns the object
		delete releasedPtr;  // Manually deleting the object

		// Using swap()
		std::unique_ptr<MyClass> ptr3 = std::make_unique<MyClass> ( );
		std::unique_ptr<MyClass> ptr4 = std::make_unique<MyClass> ( );
		ptr3.swap ( ptr4 );  // Swap ownership between ptr3 and ptr4


	return 0;
	}