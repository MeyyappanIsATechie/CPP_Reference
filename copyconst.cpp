#include <iostream>
#include<vector>
#include<string>

using namespace std;

//when is copy of an obj made??

//passing object by value as a parameter
//returning an object from function by value
//constructing one object based on another of the same class

//Type::Type(const Type& source);

class Player {
private:
	string name;
	int level;
	int hp;
public:
	string getname ( ) {
		return name;
		}
	Player ( );
	Player ( string name );
	Player ( string name , int health , int xp );
	Player ( const Player& src );
	~Player ( ) {
		cout << name << " destructor called" << endl;
		}
	};

Player::Player ( ) : Player ( "none" , 0 , 0 ) {
	cout << "no arg constructor" << endl;
	}

Player::Player ( string s ) : Player ( s , 0 , 0 ) {
	cout << "one arg constructor" << endl;
	}

Player::Player ( string s , int h , int x ) : name { s } , level { h } , hp { x } {
	cout << "three arg constructor" << endl;
	}

//copy constructor
Player::Player ( const Player& src ) 
	//: name { src.name } , level { src.level } , hp { src.hp }
	: Player{src.name, src.level, src.hp}
	{
	cout << "copy constructor" << endl;
	}

void display ( Player p ) {
	cout << "name: " << p.getname( ) << endl;
	//p.~Player ( );
	}

int main ( ) {
	Player p;
	//p = Player ( );
	display ( p );
	}

//three arg constructor
//no arg constructor
//copy constructor
//name : none
//nonedestructor called
//nonedestructor called