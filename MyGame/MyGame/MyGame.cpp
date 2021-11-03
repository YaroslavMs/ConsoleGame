
#include "Classes.h"

int main()
{
    //default settings
    srand(time(0));
    Player a, b, c, d, e, f, g, h, i, j;
    Hero h1, h2, h3, h4, h5, h6, h7, h8, h9, h10;
    string bot1, bot2, bot3, bot4, bot5, bot6, bot7, bot8, bot9, bot10;
    PlayerHero ph1, ph2, ph3, ph4, ph5, ph6, ph7, ph8, ph9, ph10;
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
    a.setname(bot1);
    b.setname(bot2);
    c.setname(bot3);
    d.setname(bot4);
    e.setname(bot5);
    f.setname(bot6);
    g.setname(bot7);
    h.setname(bot8);
    i.setname(bot9);
    j.setname(bot10);
    a.setId(1);
    b.setId(2);
    c.setId(3);
    d.setId(4);
    e.setId(5);
    f.setId(6);
    g.setId(7);
    h.setId(8);
    i.setId(9);
    j.setId(10);
    h1.CreateHero(1, 50, 55, "Young Sorcerrer");
    h2.CreateHero(2, 100, 30, "Warrior");
    h3.CreateHero(3, 120, 25, "Fighter");
    h4.CreateHero(4, 200, 5, "Tank");
    h5.CreateHero(5, 50, 50, "Sniper");
    h6.CreateHero(6, 40, 60, "Mage");
    h7.CreateHero(7, 35, 70, "Higher Mage");
    h8.CreateHero(8, 80, 35, "Shooter");
    h9.CreateHero(9, 20, 120, "Dark sorcerrer");
    h10.CreateHero(10, 70, 15, "Weapon carrier");
    a.ShowPlayerInfo();
    int sw;
    //creating players
    cout << "**************\n" << "Do you wish to add player?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        a.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        b.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        c.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        d.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        e.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        f.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        g.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        h.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        i.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
    cout << "**************\n" << "Do you wish to add more players?\n1.Yes\n2.No\n" << "**************" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        j.createplayer();
        break;
    case 2:
        goto aftercreating;
        break;
    default:
        cout << "Invalid number. Skipping..." << endl;
    }
aftercreating:;
    //Randomising player's and hero's ids
    const int k = 10;
    int m[k];

    for (int i = 0; i < k; i++)
    {
    a: m[i] = 1 + rand() % k;
        for (int j = 0; j < i; j++)
            if (m[j] == m[i]) goto a;
    }
   a.setId(m[0]);
   b.setId(m[1]);
   c.setId(m[2]);
   d.setId(m[3]);
   e.setId(m[4]);
   f.setId(m[5]);
   g.setId(m[6]);
   h.setId(m[7]);
   i.setId(m[8]);
   j.setId(m[9]);
   int v[k];

   for (int i = 0; i < k; i++)
   {
   b: v[i] = 1 + rand() % k;
       for (int j = 0; j < i; j++)
           if (v[j] == v[i]) goto b;
   }
   h1.GetHeroId(v[0]);
   h2.GetHeroId(v[1]);
   h3.GetHeroId(v[2]);
   h4.GetHeroId(v[3]);
   h5.GetHeroId(v[4]);
   h6.GetHeroId(v[5]);
   h7.GetHeroId(v[6]);
   h8.GetHeroId(v[7]);
   h9.GetHeroId(v[8]);
   h10.GetHeroId(v[9]);

  

}