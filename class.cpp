#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Player {
private:
	string name;
	int health;
	int xp;

public:
	void talk ( string msg ) {
		cout << msg << endl;
		}
	bool is_dead ( );
	};

class Account {
public:
	string name {"Account" };
	double balance{0.0 };

	bool deposit ( double );
	bool withdraw ( double );
	};

int main ( ) {
	Player frank;
	/*frank.name = "Frank";
	frank.health = 100;
	frank.xp = 3;*/
	frank.talk ( "hello there" );

	Player hero;

	Player players [ ] { frank, hero };

	vector<Player> vec { frank };
	vec.push_back ( hero );

	Player* enemy { nullptr };
	enemy = new Player;

	/*( *enemy ).name = "Enemy";
	( *enemy ).health = 100;
	enemy->xp = 15;*/
	enemy->talk ( "hehehehaww" );

	delete enemy;

	return 0;
	}