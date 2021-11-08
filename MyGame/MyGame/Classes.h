
#include <iostream>
#include <time.h>
using namespace std;
//Player class
class Player {
private:
	string name, rank;
	int points = 0;
	int id = 0;
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
	int createplayer() {
		int sw;
		cout << "**************\n" << "Do you wish to add player?\n1.Yes\n2.No\n" << "**************" << endl;
		cin >> sw;
		if (sw == 1) {
			cout << "Creating new player..." << endl << "**************" << endl << "Your name is: ";
			cin >> name;
			cout << endl << "**************" << endl;
		}
		if (sw != 1 && sw != 2)
			cout << "Invalid number. Skipping..." << endl;
		if (sw == 2) {
			cout << "Skipping players creation..." << endl;
		}
		
		return sw;
	}
	void ShowPlayerInfo() {
		cout << "**************" << endl << "\nName: " << name << "\nRank: " << rank << "\nPoints: " << points << endl;
		
	}
	void PointsWin() {
		points =points + 25;
	}
	void PointsLose() {
		points =points - 25;
	}
	void setRank(string rank) {
		this->rank = rank;
	}
	int Points() {
		return points;
	}
	
};
//Hero Class
class Hero {
private:
	int id = 0, hp = 0, damage = 0;
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
	void ShowHeroInfo() {
		cout << "\nClass is: " << name << "\nHp is: " << hp << "\nDamage is: " << damage << "\n**************" << endl;

	}

};
//Hero + Player using Id
class Team {
private:
	Player p;
	Hero h;
	int id = 0, hp = 0, dmg = 0;
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
};
//Team Manager class
class TeamManager {
private:
	Team a[10], team1[5], team2[5];
	int hp1Final = 0, hp2Final = 0;
	int Team1HP = 0, Team1DMG = 0, Team2HP = 0, Team2DMG = 0;
	bool winner;
public:
	void GenerateTeams(Team g, int i) {
		    a[i] = g;
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
	int CalculateWinner() {
		hp1Final = Team1HP - Team2DMG;
	    hp2Final = Team2HP - Team1DMG;
		if (hp1Final > hp2Final) {
			return 1;
		}
		else if (hp1Final < hp2Final) {
			return 0;
		}
		else if(hp2Final == hp1Final)
			return 2;
	}	
};

class Session {
	TeamManager a;

public:
	bool exist;
	int sessionwinner = 0;
	void GetTeamManager(TeamManager b) {
		a = b;
	}
	void SessionInfo(int team1win, int i) {		
		if (team1win == 2) {
			cout << "**************" << "\nDraw" << endl;
			a.GetTeamInfo1(); a.GetTeamInfo2();
		}
		else {
			cout << "\n\n\n\n**************" << "\nGame session " << i + 1 << ": " << "\nWinner team: " << endl;
			if (team1win == 1) a.GetTeamInfo1(); else a.GetTeamInfo2();
			cout << "**************" << "\nLoser team: " << endl;
			if (team1win == 0) a.GetTeamInfo1(); else a.GetTeamInfo2();		
		}
	}
};

class GameManager {
	Session s[5];
public:
	void GetSession(Session b, int i, int winner) {
		s[i] = b;
		s[i].sessionwinner = winner;
		s[i].exist = true;
	}
	void SessionsList() {
		for (int i = 0; i < 5; i++) {
		if(s[i].exist == true)
			s[i].SessionInfo(s[i].sessionwinner, i);
		}
	}
	int PerformGameSession() {
		int create;	
		cout << "Perform game session that consists of 5 games?\n1.Yes\n2.No." << endl;
		cin >> create;
		if (create == 1) cout << "Initialising game session..." << endl;
		else if (create == 2) {
	   cout << "Ok" << endl;
		}
		else if (create != 2 && create != 1)cout << "Invalid option. Game session will be started anyway" << endl;		
		return create;
	}

};