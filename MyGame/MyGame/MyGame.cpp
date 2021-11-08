
#include "Classes.h"

int main()
{  
    //default settings
    srand(time(0));
    Player* p = new Player[10];              //Added some memory to the heap to
    Hero* h = new Hero[10];                  //avoid warning and possible error
    TeamManager a;
    Team* ph = new Team[10];
    Session* s =new Session[5];               
    GameManager mngr;

    p[0].setname("BOT James");
    p[1].setname("BOT Jacob");
    p[2].setname("BOT Frank");
    p[3].setname("BOT Patrick");
    p[4].setname("BOT Freddie");
    p[5].setname("BOT Tom");
    p[6].setname("BOT Endy");
    p[7].setname("BOT Merry");
    p[8].setname("BOT Peter");
    p[9].setname("BOT Vasiliy");
    h[0].CreateHero(50, 55, "Young Sorcerrer");
    h[1].CreateHero(100, 30, "Warrior");
    h[2].CreateHero(120, 25, "Fighter");
    h[3].CreateHero(200, 5, "Giant");
    h[4].CreateHero(50, 50, "Sniper");
    h[5].CreateHero(40, 60, "Mage");
    h[6].CreateHero(35, 75, "Higher Mage");
    h[7].CreateHero(80, 35, "Shooter");
    h[8].CreateHero(20, 120, "Dark sorcerrer");
    h[9].CreateHero(70, 15, "Weapon carrier");

    //creating players
    for (int i = 0; i < 10; i++) {
        if (p[i].createplayer() == 2)
            break;      
    }
    //Starting session
    while (true) {
        if (mngr.PerformGameSession() != 2) {
            break;
        }
    }
    //Game session with 5 games
for(int ses = 0; ses < 5; ses++){

    //Randomising player's and hero's ids
    const int k = 10;
    int m[k];
    int v[k];
    for (int i = 0; i < k; i++)
    {
        while (true) {
            int a = 0;
            m[i] = 1 + rand() % k;
            for (int j = 0; j < i; j++) {
                if (m[j] != m[i]) a++;
            }
            if (a == i) break;
        }
        while (true) {
            int b = 0;
            v[i] = 1 + rand() % k;
            for (int j = 0; j < i; j++) {
                if (v[j] != v[i]) b++;
            }
            if (b == i) break;
        }
        p[i].setId(m[i]);
        h[i].SetHeroId(v[i]);
    }

    //Combining heroes with players using ID, generating Teams
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (p[i].getId() == h[j].getHeroId()) {
                ph[i].MatchingHeroPlayer(p[i], h[j], p[i].getId());
            }
        }
        a.GenerateTeams(ph[i], i);
    }

    //session
    a.TeamOne();
    a.TeamTwo();
    int win1;
    win1 = a.CalculateWinner();

    //adding and subtracting points
    if (win1 == 1) {
        for (int i = 0; i < 10; i++) {
            if (p[i].getId() == 1)	p[i].PointsWin();
            if (p[i].getId() == 2)	p[i].PointsWin();
            if (p[i].getId() == 3)	p[i].PointsWin();
            if (p[i].getId() == 4)	p[i].PointsWin();
            if (p[i].getId() == 5)	p[i].PointsWin();
            if (p[i].getId() == 6)	p[i].PointsLose();
            if (p[i].getId() == 7)	p[i].PointsLose();
            if (p[i].getId() == 8)	p[i].PointsLose();
            if (p[i].getId() == 9)	p[i].PointsLose();
            if (p[i].getId() == 10)	p[i].PointsLose();
        }
    }
    else if (win1 == 0) {
        for (int i = 0; i < 10; i++) {
            if (p[i].getId() == 10)	p[i].PointsWin();
            if (p[i].getId() == 9)	p[i].PointsWin();
            if (p[i].getId() == 8)	p[i].PointsWin();
            if (p[i].getId() == 7)	p[i].PointsWin();
            if (p[i].getId() == 6)	p[i].PointsWin();
            if (p[i].getId() == 5)	p[i].PointsLose();
            if (p[i].getId() == 4)	p[i].PointsLose();
            if (p[i].getId() == 3)	p[i].PointsLose();
            if (p[i].getId() == 2)	p[i].PointsLose();
            if (p[i].getId() == 1)	p[i].PointsLose();
        }
    }
  //saving game session
    s[ses].GetTeamManager(a);
    mngr.GetSession(s[ses], ses, win1);
    }
  //sessions list
    mngr.SessionsList();

//adding ranks
   for (int i = 0; i < 10; i++) {
       if (p[i].Points() == 125)
           p[i].setRank("GOD");
       if (p[i].Points() == 100)
           p[i].setRank("King");
       if (p[i].Points() == 75)
           p[i].setRank("Wealthy nobleman");
       if (p[i].Points() == 50)
           p[i].setRank("Nobleman");
       if (p[i].Points() == 25)
           p[i].setRank("Knight");
       if (p[i].Points() == 0)
           p[i].setRank("Wealthy man");
       if (p[i].Points() == -25)
           p[i].setRank("Ordinary man");
       if (p[i].Points() == -50)
           p[i].setRank("Peasant");
       if (p[i].Points() == -75)
           p[i].setRank("Laborer");
       if (p[i].Points() == -100)
           p[i].setRank("slave");
       if (p[i].Points() == -125)
           p[i].setRank("WOW. Just wow");    
   }
  //results of all 5 games
   cout << "\n\n\n" << "Final results" << endl;
   for (int i = 0; i < 10; i++) {
       p[i].ShowPlayerInfo();
   }
   delete[] ph;
   delete[] p;
   delete[] h;
   delete[] s;
}