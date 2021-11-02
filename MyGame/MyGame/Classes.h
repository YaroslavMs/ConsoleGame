
#include <iostream>
using namespace std;

class Player {
private:
	int id;
	string name, rank;
	int points = 0;
public:
	void setId(int ID) {
		id = ID;
	}
	void setname(string name) {
		this->name = name;
	}
	void createplayer() {
		cout << "Creating new player..." << endl << "**************" << endl << "Your name is: ";
		cin >> name;
		cout << endl << "**************" << endl;

	}
	
};
class Hero {
private:
	int id, hp, damage;
	string name;
public:
	void CreateHero(int id, int hp, int damage, string name1) {
		this->id = id;
		this->hp = hp;
		this->damage = damage;
		name = name1;

	}

};
