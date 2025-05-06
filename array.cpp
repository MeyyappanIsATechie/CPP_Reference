#include <iostream>
#include<array>
#include<algorithm>
#include<numeric>

using namespace std;

void display ( const array<int , 5>& a ) {
	for ( const auto& i : a ) {
		cout << i << " ";
		}
	cout << endl;
	}

int main ( ) {
	array<int , 5> arr1 { {1,2,3,4,5 } };
	array<int , 5> arr2; //garbage, add initializer
	arr1 = { 2,4,6,8,10 };
	cout << arr1.size ( ) << endl;
	cout << arr1.at ( 0 ) << endl;
	cout << arr1 [ 1 ] << endl;
	cout << arr1.front ( )<<endl<<arr1.back( )<<endl;
	cout << arr1.empty ( )<<endl;
	cout << arr1.max_size ( );
	arr1.swap ( arr1 );
	int* data = arr1.data ( ); //get raw array address
	cout << "raw:"<< * data << endl;

	//arr1 [ 7 ] = 0; no bounds checking
	//arr1.at ( 7 ) = 1; bounds checking

	display ( arr1 );

	arr2.fill ( 0 );
	display ( arr2 );

	sort ( arr1.begin ( ) , arr1.end ( ) );

	array<int , 5>::iterator min = min_element ( arr1.begin ( ) , arr1.end ( ) );
	auto max = max_element ( arr1.begin ( ) , arr1.end ( ) );

	cout << *min << " " << *max << endl;

	//adjacent similar values
	auto adj = adjacent_find ( arr1.begin ( ) , arr1.end ( ) );
	if ( adj != arr1.end ( ) ) {
		cout << *adj << endl;
		}
	else {
		cout << "no adjacent values" << endl;
		}

	int sum = accumulate ( arr1.begin ( ) , arr1.end ( ) , 0 ); //<numeric>
	cout << sum << endl;
	}