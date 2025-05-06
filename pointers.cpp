#include <iostream>
#include<vector>
#include<string>

using namespace std;

void fun ( int& num );

void fun ( int& num ) {
	num = 100;
	}

void change ( vector<int>& v ) {
	v.at ( 0 ) = 5;
	}

int main ( ) { 
	/*int num { 1000 };
	fun ( num );
	cout << num << endl;
	vector<int> vec { 1,2,3,4 };
	change ( vec );
	for ( auto i : vec ) {
		cout << i << endl;
		}*/

	/*int* ptr { };
	double* d_ptr { nullptr };
	int a = 5;
	ptr = &a;
	cout << *ptr << endl;
	int* ptr2;
	ptr2 = nullptr;
	cout << ptr2 << endl;

	string name { "John" };
	string* s_ptr { &name };
	cout << *s_ptr << endl;
	name = "Doe";
	cout << *s_ptr << endl;*/

	cout << sizeof (int) << endl;

	int* iptr { nullptr };
	iptr = new int;
	cout << *iptr << endl; //garbage
	*iptr = 100;
	cout << *iptr << endl; 
	delete iptr;

	int* aptr { nullptr };
	int size {};

	cin >> size;
	aptr = new int [ size ];


	}