#include <iostream>
#include<vector>
#define SQUARE(a) ((a)*(a))

using namespace std;

//----------------------------------fucntion template--------------------------------------

template<typename T> // or class T
T add ( T a , T b ) {
    return a + b;
    }

template<typename T1, typename T2>
void func ( T1 a , T2 b ) {
    cout << a << " " << b << endl;
    }

struct Person {
    int age;
    string name;
    int operator+( const Person& rhs ) const {
        return this->age + rhs.age;
        }
    };

ostream& operator<<( ostream& os , const Person& p ) {
    os << "hi, " << p.name << ". your age is " << p.age << endl;
    return os;
    }

//---------------------------------class template----------------------

template<typename T>
class A {
    friend ostream& operator<< <>( ostream& os , const A<T>& o );
    string s;
    T v;
public:
    A(string s,T v ):s{s },v{v }{}
    void show ( ) const {
        cout << s << " " << v << endl;
        }
    };


template<typename T>
ostream& operator<< <>( ostream& os , const A<T>& o ) { 
    os << "hi, " << o.s << ". your value is " << o.v << endl;
    return os;
    }

template<typename T>
ostream& operator<<( ostream& os , const vector<T>& v ) {
    for ( size_t i = 0; i < v.size ( ); i++ ) {
        os << v [ i ] << " ";
        }
    return os;
    }


int main()
{
    cout << add<int> ( 5 , 6 ) << endl // or add(5,6)
        << add ( 5.34f , 8.5f ) << endl
        << add ( 6.7 , 8.99 ) << endl;
    Person p1 { 10,"john" };
    Person p2 { 20, "jane" };
    int a = p1 + p2;
    cout << a <<endl;

    func ( 1 , 2 );
    func ( "hello" , 3.14 );
    cout << p1;

    //CLASS TEMPLATE
    vector<int> v { 1,2,3,4 }; //this is an example of a class template

    A<int> b { "hello" ,1 };
    A<double> c { "bello",86 };

    cout << a << b << endl;

    b.show ( );
    c.show ( );

    vector<A<int>> vec { };
    vec.push_back ( A<int>{"cello" , 34} );
    vec.push_back ( b );

    cout << vec << endl;


}
