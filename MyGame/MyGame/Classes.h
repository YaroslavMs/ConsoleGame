
#include <iostream>
#include <time.h>
using namespace std;
class Player {
private:
	int id;
	string name, rank = "norank";
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
	void ShowPlayerInfo() {
		cout << "**************" << endl << "Players id: " << id << "\nName: " << name << "\nRank: " << rank << "\n**************" << endl;
		
	}
	bool GetPlayerByName(string name) {
		if (this->name == name) {
			bool NameMatch = true;
			return NameMatch;
		}
		else return 0;
	}
	bool GetPlayerByID(int id) {
		if (this->id == id) {
			bool IDmatch = true;
			return IDmatch;
		}
		else return 0;
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
class Team {
private:
	string name = "Blue";
	Player a, b, c, d, e;
public:

};

