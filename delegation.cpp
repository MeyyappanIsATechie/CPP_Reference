#include <iostream>
#include<vector>
using namespace std;
//
//class A {
//	int x , y , z;
//public:
//	//default constructor
//	//A ( int x = 1 , int y = 2 , int z = 3 );
// A(){} //not allowed
//	A ( ) {
//		x = 0;
//		y = 0;
//		z = 0;
//		}
//
//	A ( int z ) :A ( ) {
//		this->z = z;
//		}
//	void show ( ) {
//		cout << x << endl << y << endl << z << endl;
//		}
//
//	A ( int a , int b , int c ) :x { a } , y { b } , z { c }{
//		cout << "three args called";
//		}
//
//	//copy constructor
//	A ( const A& source );
//
//	};
//
//A::A ( const  A& src ) :x { src.x } , y { src.y } , z { src.z }{
//	cout << "copy constructor" << endl;
//	}

//A::A ( int a , int b , int c ) :x { a } , y { b } , z { c }{
//	cout << "three-args constructor" << endl;
//	}

class Player {
private:
	string name;
	int level;
	int hp;
public:
	Player ( );
	Player ( string name );
	Player ( string name , int health , int xp );
	};

Player::Player ( ) : Player ( "none" , 0 , 0 ) {
cout << "no arg constructor" << endl;
	}

Player::Player ( string s) : Player ( s , 0 , 0 ) {
	cout << "one arg constructor" << endl;
	}

Player::Player ( string s , int h , int x ) : name { s } , level { h } , hp { x } {
	cout << "three arg constructor" << endl;
	}

int main ( ) {
	/*A obj ( 3 );
	obj.show ( );*/
	Player empty;
	Player frank { "Frank" };
	Player villain { "Villain",100,55 };
	}