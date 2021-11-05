
#include <iostream>
#include <time.h>
using namespace std;
//Player class
class Player {
private:
	string name;
	int rank = 0;
	int id;
public:
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
	void rankWin() {
		rank += 25;
	}
	void rankLose() {
		rank -= 25;
	}
	
};
//Hero Class
class Hero {
private:
	int id, hp, damage;
	string name;
public:
	void CreateHero(int hp, int damage, string name1) {
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
	int HP() {
		return hp;
	}
	int DMG() {
		return damage;
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
//Hero + Player using Id
class PlayerHero {
private:
	Player p;
	Hero h;
	int id, hp, dmg;
public:
	void MatchingHeroPlayer(Player a, Hero b, int id) {
		p = a;
		h = b;
		this->id = id;
		hp = b.HP();
		dmg = b.DMG();
	}
	void View() {
		p.ShowPlayerInfo();
		h.ShowHeroInfo();
	}
	int GetID() {
		return id;
	}
	int HP() {
		return hp;
	}
	int DMG() {
		return dmg;
	}
	void addRank() {
		p.rankWin();
	}
	void SubtractRank() {
		p.rankLose();
	}
};
//Team Manager class
class TeamManager {
private:
	PlayerHero a[10], team1[5], team2[5];
	int hp1Final, hp2Final;
	int Team1HP = 0, Team1DMG = 0, Team2HP = 0, Team2DMG = 0;
	bool winner;
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
	};
	void GetTeamInfo1() {
		cout << "\n\n**************" << "\nTeam1:" << endl;
		for (int i = 0; i < 5; i++) {
			team1[i].View();
		}

	}
	void GetTeamInfo2() {
		cout << "\n\n**************" << "\nTeam2:" << endl;
		for (int i = 0; i < 5; i++) {
			team2[i].View();
		}

	}
	void TeamOne() {
		for (int i = 0; i < 5; i++) {
			Team1HP += team1[i].HP();
			Team1DMG += team1[i].DMG();
		}
	}
	void TeamTwo() {
		for (int i = 0; i < 5; i++) {
			Team2HP += team2[i].HP();
			Team2DMG += team2[i].DMG();
		}
	}
	bool CalculateWinner() {
		bool team1win;
		hp1Final = Team1HP - Team2DMG;
	    hp2Final = Team2HP - Team1DMG;
		if (hp1Final > hp2Final) {
			for (int i = 0; i < 5; i++) {
				team1[i].addRank();
				team2[i].SubtractRank();
			}
			return 1;
		}
		else if (hp2Final > hp1Final) {
			for (int i = 0; i < 5; i++) {
				team2[i].addRank();
				team1[i].SubtractRank();
			}
			return 0;
		}
		
	}
	
};
class Session {
	TeamManager a;
public:
	void GetTeamManager(TeamManager b) {
		a = b;
	}
	void SessionInfo(int i) {
		cout << "\n\n\n\n**************" << "\nGame session " << i + 1 <<": " << "\nWinner team: " << endl;
		if (a.CalculateWinner() == 1) a.GetTeamInfo1(); else a.GetTeamInfo2();
		cout << "**************" << "\nLoser team: " << endl;
		if (a.CalculateWinner() == 1) a.GetTeamInfo2(); else a.GetTeamInfo1();
	}

};
class GameManager {
	Session s[5];
public:
	void GetSession(Session b, int i) {
		s[i] = b;
	}
	void SessionsList() {
		for (int i = 0; i < 5; i++) {
			s[i].SessionInfo(i);
		}
	}

};