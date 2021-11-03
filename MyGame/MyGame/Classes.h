
#include <iostream>
#include <time.h>
using namespace std;
class Player {
private:
	string name, rank = "norank";
	int points = 0;
public:
	int id;
	int setId(int ID) {
		id = ID;
		return id;
	}
	int getId() {
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
		cout << "**************" << endl << "Players id: " << id << "\nName: " << name << "\nRank: " << rank << endl;
		
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
	void CreateHero(int hp, int damage, string name1) {
		this->id = id;
		this->hp = hp;
		this->damage = damage;
		name = name1;
	}
	int getHeroId() {
		return id;
	}
	int SetHeroId(int ID) {
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
	void ShowHeroInfo() {
		cout << "Heroes id: " << id << "\nClass is: " << name << "\nHp is: " << hp << "\nDamage is: " << damage << "\n**************" << endl;

	}

};
class PlayerHero {
private:
	Player p;
	Hero h;
	int id;
public:
	void MatchingHeroPlayer(Player a, Hero b, int id) {
		p = a;
		h = b;
		this->id = id;
	}
	void View() {
		p.ShowPlayerInfo();
		h.ShowHeroInfo();
	}
	int GetID() {
		return id;
	}
};
class TeamManager {
private:
	PlayerHero a[10], team1[5], team2[5];
public:
	void GetPlayerHero(PlayerHero g, int i) {
		a[i] = g;
	}
	void GenerateTeams() {
		for (int i = 0; i < 10; i++) {
			if (a[i].GetID() == 1)	team1[0] = a[i];
			if (a[i].GetID() == 2)	team1[1] = a[i];
			if (a[i].GetID() == 3)	team1[2] = a[i];
			if (a[i].GetID() == 4)	team1[3] = a[i];
			if (a[i].GetID() == 5)	team1[4] = a[i];
			if (a[i].GetID() == 6)	team2[0] = a[i];
			if (a[i].GetID() == 7)	team2[1] = a[i];
			if (a[i].GetID() == 8)	team2[2] = a[i];
			if (a[i].GetID() == 9)	team2[3] = a[i];
			if (a[i].GetID() == 10)	team2[4] = a[i];
		}
	}
	void GetTeamInfo1() {
		cout << "**************" << "\nTeam1:" << endl;
		for (int i = 0; i < 5; i++) {
			team1[i].View();
		}

	}
	void GetTeamInfo2() {
		cout << "**************" << "\nTeam2:" << endl;
		for (int i = 0; i < 5; i++) {
			team2[i].View();
		}

	}
};
