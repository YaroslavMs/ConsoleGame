
#include "Classes.h"

int main()
{
    //default settings
    srand(time(0));
    Player p[10];
    Hero h[10];
    string bot1, bot2, bot3, bot4, bot5, bot6, bot7, bot8, bot9, bot10;
    TeamManager a;
    PlayerHero ph[10];
    Session s[5];
    GameManager mngr;
    int ses = 0;
    bot1 = "BOT James";
    bot2 = "BOT Jacob";
    bot3 = "BOT Frank";
    bot4 = "BOT Patrick";
    bot5 = "BOT Freddie";
    bot6 = "BOT Tom";
    bot7 = "BOT Endy";
    bot8 = "BOT Merry";
    bot9 = "BOT Peter";
    bot10 = "BOT Vasiliy";
    p[0].setname(bot1);
    p[1].setname(bot2);
    p[2].setname(bot3);
    p[3].setname(bot4);
    p[4].setname(bot5);
    p[5].setname(bot6);
    p[6].setname(bot7);
    p[7].setname(bot8);
    p[8].setname(bot9);
    p[9].setname(bot10);
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
    for (int i = 0; i < 10; i++) {
        p[i].setPoints(0);
    }

    //creating players
start:;
    for (int i = 0; i < 10; i++) {
        int sw;
        cout << "**************\n" << "Do you wish to add player?\n1.Yes\n2.No\n" << "**************" << endl;
        cin >> sw;
        switch (sw) {
        case 1:
            p[i].createplayer();
            break;
        case 2:
            goto aftercreating;
            break;
        default:
            cout << "Invalid number. Skipping..." << endl;
        }
    }
aftercreating:;

    //Starting session
    int st;
    cout << "Are you ready to play?\n1.Yes\n2.No. I want to change players" << endl;
    cin >> st;
    if (st == 1) cout << "Initialising game session..." << endl;
    else if (st == 2) {
        cout << "Player creation is restarted" << endl;
        goto start;
    }
    else if (st != 2 && st != 1)cout << "Invalid option. Game session will be started anyway" << endl;
sessionbegin:;

    //Randomising player's and hero's ids
    const int k = 10;
    int m[k];

    for (int i = 0; i < k; i++)
    {
    a: m[i] = 1 + rand() % k;
        for (int j = 0; j < i; j++)
            if (m[j] == m[i]) goto a;
    }
    int v[k];

    for (int i = 0; i < k; i++)
    {
    b: v[i] = 1 + rand() % k;
        for (int j = 0; j < i; j++)
            if (v[j] == v[i]) goto b;
    }
    for (int i = 0; i < 10; i++) {
        p[i].setId(m[i]);
    }
    for (int i = 0; i < 10; i++) {
        h[i].SetHeroId(v[i]);
    }

    //Combining heroes with players using ID
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (p[i].getId() == h[j].getHeroId()) {
                ph[i].MatchingHeroPlayer(p[i], h[j], p[i].getId());
            }
        }
    }

    //Generating Teams
    for (int i = 0; i < 10; i++) {
        a.GetPlayerHero(ph[i], i);
    }

    a.GenerateTeams();

    //session
    a.TeamOne();
    a.TeamTwo();
    int win1;
    win1 = a.CalculateWinner();

    //adding and subtracting points
    if (win1 == 1) {
        for (int i = 0; i < 10; i++) {
            if (p[i].getId() == 1)	p[i].rankWin();
            if (p[i].getId() == 2)	p[i].rankWin();
            if (p[i].getId() == 3)	p[i].rankWin();
            if (p[i].getId() == 4)	p[i].rankWin();
            if (p[i].getId() == 5)	p[i].rankWin();
            if (p[i].getId() == 6)	p[i].rankLose();
            if (p[i].getId() == 7)	p[i].rankLose();
            if (p[i].getId() == 8)	p[i].rankLose();
            if (p[i].getId() == 9)	p[i].rankLose();
            if (p[i].getId() == 10)	p[i].rankLose();
        }
    }
    else if (win1 == 0) {
        for (int i = 0; i < 10; i++) {
            if (p[i].getId() == 10)	p[i].rankWin();
            if (p[i].getId() == 9)	p[i].rankWin();
            if (p[i].getId() == 8)	p[i].rankWin();
            if (p[i].getId() == 7)	p[i].rankWin();
            if (p[i].getId() == 6)	p[i].rankWin();
            if (p[i].getId() == 5)	p[i].rankLose();
            if (p[i].getId() == 4)	p[i].rankLose();
            if (p[i].getId() == 3)	p[i].rankLose();
            if (p[i].getId() == 2)	p[i].rankLose();
            if (p[i].getId() == 1)	p[i].rankLose();
        }
    }

  //saving game session
    s[ses].GetTeamManager(a);
    s[ses].SessionWinner(win1);
    mngr.GetSession(s[ses], ses);
    mngr.GetSessionWin(win1, ses);

  //Performing more sessions
    if (ses < 4) {
        ses++;
        goto sessionbegin;
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
           p[i].setRank("Earl");
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
   cout << "\n\n\n" << "Final results" << endl;
   for (int i = 0; i < 10; i++) {
       p[i].ShowPlayerInfo();
   }




}