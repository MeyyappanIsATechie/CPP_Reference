#include <iostream>
#include<vector>
#include<string>

using namespace std;

class MyClass {
public:
    int x=0;

    MyClass ( ) :x ( 0 ) {} 
    void display ( ) {
        cout << "x = " << x << std::endl;
        }
    };

int main ( ) {
    MyClass obj;       
    //obj.x = 10;       
    obj.display ( );    
    return 0;
    }