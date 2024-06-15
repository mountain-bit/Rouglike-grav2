// Roguelike.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>;
#include "DataBase.h";
#include "PlayerClass.h";
#include "Enemis.h";
#include "Map.h";
#include "GraphicEngine.h";
#include "MG.h";

int main()
{
    setlocale(LC_CTYPE, ".UTF8");
    /*
    Protagonist* p1, * p2, *p3;
    p1 = new Warrior();
    p2 = new Sorcerer();
    p3 = new Hunter();

    cout << p1->toString()<<endl;
    cout << p2->toString()<<endl;
    cout << p3->toString()<<endl;


    cout<<p1->takenDng(100);
    cout << p1->toString() << endl;
    cout << p1->atack(0.90, 1.10);

    Enemi* e1, *e2;
    e1 = new Spider(1);

    cout << e1->toString() << endl;;
    cout << e1->takenDng(100);
    e2 = new Undead(2);
    cout << e2->toString() << endl;;
    cout << e2->takenDng(100);

    Map m;
    for (int i = 0; i < 10; i++) {
        cout <<i+1<< m.GetNameLocation(i)<<endl;
        m.nextLocation();
    }
    Player pla;


    GraphicEngine ge;

    ge.SetPlayer(&pla);
    ge.showGame(0);
    int a;
    cin >> a;
    */

    MG mg;

    mg.game();
}