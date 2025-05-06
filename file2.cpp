#include<iostream>
#include<iomanip>

using namespace std;

int main ( ) {
    //stream width,align, and fill
    double num { 423.5678 };
    string hello { "hello" };
    cout << setfill ( '+' );
    cout << setw ( 10 ) << num << hello << endl; //justification is from right
    cout << setw ( 10 ) << left << num << hello << endl;
	}