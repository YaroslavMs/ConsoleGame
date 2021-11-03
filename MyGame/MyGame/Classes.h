
#include <iostream>
#include <time.h>
using namespace std;
class Player {
private:
	int id;
	string name, rank = "norank";
	int points = 0;
public:
	int setId(int ID) {
		id = ID;
		return id;
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
	int GetHeroId(int ID) {
		id = ID;
		return id;
	}
	bool GetHeroByName(string name) {
		if (this->name == name) {
			bool NameMatch = true;
			return NameMatch;
		}
		else return 0;
	}
	bool GetHeroByID(int id) {
		if (this->id == id) {
			bool IDmatch = true;
			return IDmatch;
		}
		else return 0;
	}
};
class PlayerHero {
private:
	Player p;
	Hero h;
public:
	void MatchingHeroPlayer(Player a, Hero b) {
		p = a;
		h = b;
	}
};
class Team {
private:
	PlayerHero b[5];
};
