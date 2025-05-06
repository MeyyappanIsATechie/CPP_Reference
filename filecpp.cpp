#include <iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    //boolean stream manip
    cout << boolalpha;
    cout << ( 10 == 20 ) << endl;
    cout << noboolalpha;
    cout << ( 10 == 20 ) << endl;

    //method version
    cout.setf ( ios::boolalpha );
    cout << ( 10 == 20 ) << endl;
    cout << resetiosflags ( ios::boolalpha );
    cout << ( 10 == 20 ) << endl;

    //integer stream manip
    int n { 255 };
    //cout.setf(ios::showbase);
    cout << showbase << uppercase <<showpos;
    cout << dec << n << endl; //default;
    cout << hex << n << endl;
    cout << oct << n << endl;
    cout << noshowbase << noshowpos;
    //cout<<resetiosflags(ios::uppercase);
    cout << "----------------------------------" << endl;
    //floating point stream manip
    double num1 { 123456789.987654321 };
    double num2 { 1234.5678 };
    double num3 { 1234.0 };

    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << "----------------------------------" << endl;
    cout << setprecision ( 2 );
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << "----------------------------------" << endl;
    cout << setprecision ( 5 );
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << "----------------------------------" << endl;
    cout << setprecision ( 9 );
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << "----------------------------------" << endl;
    cout << nouppercase;

    cout << setprecision ( 3 ) << fixed;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << "----------------------------------" << endl;
    cout << setprecision ( 3 ) << scientific ;
    cout << num1 << endl;
    cout << num2 << endl << uppercase;
    cout << num3 << endl;
    cout << "----------------------------------" << endl;
    cout << setprecision ( 10 ) << showpoint;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout.unsetf ( ios::scientific | ios::fixed );
    cout << resetiosflags ( ios::showpos );
    cout << resetiosflags ( ios::showpoint );

   
}   
