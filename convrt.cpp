#include <iostream>
#include<vector>

using namespace std;
int main ( )
	{
	int dol_val = 100;
	int q_val = 25;
	int d_val = 10;
	int n_val = 5;
	int cents;
	cin >> cents;
	int balance = 0 , dol = 0 , q = 0 , d = 0 , n = 0 , p = 0;
	dol = cents / dol_val;
	balance = cents % dol_val;

	q = balance / q_val;
	balance %= q_val;

	d = balance / d_val;
	balance %= d_val;

	n = balance / n_val;
	balance %= n_val;

	p = balance;

	cout << "dollars:" << dol << endl;
	cout << "quarters:" << q << endl;
	cout << "dimes:" << d << endl;
	cout << "nickels:" << n << endl;
	cout << "pennies:" << p << endl;
	}