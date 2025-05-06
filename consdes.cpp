#include <iostream>
#include<vector>
#include<string>

using namespace std;

//conmstructor
//special membor method
//invoked during object creation
//useful for initializaation
//same name as the class
//no return type is speicifed
//can be overloaded
//define user-define no arg constructor if want to use along with paramtereized constructor,
//since paramtereized constructor overshadows compiler generated default constructor

//constructor initialization lists
//efficient
//immediately follows paramter list
//init daa memebrs as object is created
//order of initalization is order of declaration in class

//destructor
//cannot be overloaded
//clean up

class Player {
private:
	string name;
	int health;
public:
	//default
	Player ( ) {
		name = "None";
		health = 0;
		}
	Player( ):name{"None" },health{0 }{} //constructor init lists
	Player(string s,  int h) : name(s ),health(h ) {}
	//copy constructor
	Player ( const Player& other ) {
		name = other.name;
		health = other.health;
		}
	Player ( string name );
	Player ( string name , int health ) {
		this->name = name;
		this->health = health;
		}
	~Player ( ); //called once obj goes out of scope or delete is used...if multiple, it destructs objects LIFO...
	};

int main ( ) {
	Player p;

	}