#include <iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

struct Item {
	string name;
	int quantity;
	double price;
	};

int main ( )
	{
	Item items [ 3 ] = {
			{"apples", 4,0.99 },
		{"milk",1,2.49 },
		{"bread",2,1.89 }
		};

	double t = 0;

	cout << setfill ( '=' ) << setw ( 45 ) << "=" << endl;
	cout << setfill ( ' ' ) << left;
	cout << setw ( 20 ) << "Item" << setw ( 10 ) << "Qty" << setw ( 10 ) << "Price" << setw ( 10 ) << "Total" << endl;
	cout << setfill ( '-' ) << setw ( 45 ) << "-" << endl;
	cout << setfill ( ' ' );

	for ( int i = 0; i < 3; i++ ) {
		double itemt = items [ i ].quantity * items [ i ].price;
		t += itemt;

		cout << left << setw ( 20 ) << items [ i ].name << setw ( 10 ) << items [ i ].quantity << fixed << setprecision ( 2 ) << setw ( 10 ) << items [ i ].price << setw ( 10 ) << itemt << endl;
		}

	cout << setfill ( '-' ) << setw ( 45 ) << "-" << endl;
	cout << setfill ( ' ' ) << right;
	cout << setw ( 30 ) << "Total: $" << showpos << fixed << setprecision ( 2 ) << t << noshowpos << endl;
	cout << setfill ( '=' ) << setw ( 45 ) << "=" << endl;
	}