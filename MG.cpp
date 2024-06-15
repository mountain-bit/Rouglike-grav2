#include "MG.h"

MG::MG()
{
	P = new Player();
	logs = true;
}

void MG::game()
{

	srand(time(NULL));
	//strat
	GE.Show_start();
	//wybór postaci
	int n = DATABASE.GetCharacterNameConut();
	string* nazwydraczy = new string[n];
	for (int i = 0; i < n; i++) {
		*(nazwydraczy + i) = DATABASE.GetCharacterName(i);
	}
	int wybor = GE.Show_choice(nazwydraczy, n, 1, "Wybierz postaæ"); //Show_choice 1
	switch (wybor)
	{
	case 0:
		P->SetProtagonist(new Warrior()); 
		break;
	case 1:
		P->SetProtagonist(new Hunter());
		break;
	case 2:
		P->SetProtagonist(new Sorcerer());
		break;
	default:

		break;
	}
	delete[]nazwydraczy;
	GE.SetPlayer(P);
	int dmg = 0;
	while (true) {

		M = new Map();
		GE.SetMap(M);
		M->SetEnemiCount();
		P->getProtagonist()->setHp(P->getProtagonist()->maxHp_level(P->GetLevel()));

	

		Enemi* em;

		for (int i = 0; i < 10; i++) {
			

		travel: while (M->GetEnemiCount() > 0) {

			em = M->GiveEnemi();
			GE.SetEnemi(em);
			while (em->getHp() > 0) {
				cout << em->getName();

				wybor = GE.Show_choice(P->getattacksNames(), P->getAttackCount(),3,"Wybierz atak: ");//Show_choice 2
				dmg = P->getProtagonist()->atack(P->getattacksChance(wybor), P->getattacksMulty(wybor)); cout << "*obrarzenia ustalone" << dmg << "*" << endl;
				dmg= em->takenDng(dmg);

				GE.Anamacja(31,-1,to_string(dmg));

				if (em->isDead()) {
					GE.Anamacja(4);//animacja umierania
					int gold = (em->getId() + 1) * (em->getArchetype() + 1) * 10 + rand() % 500;
					int exp = em->maxHp() * em->getBaseDng() * 0.3;
					P->SetGoldPlus(gold);
					P->SetExpPlus(exp);
					GE.Show_info(41, "Zdobywasz\n z³oto: " + to_string(gold) + "\t exp: " + to_string(exp));
					int pom=0;
					while (P->LevelUpAlready()) {
						P->levleUp();
						pom++;
						
					}
					if (pom != 0) {
						GE.Show_info(42, "Zdowbywasz poziom! +"+to_string(pom));
					}

				}
				else {

					int atakPotwor = rand() % em->getAttackCount();
					int dmgPotwor = em->atack(atakPotwor);
					
					GE.Anamacja(32,-1,to_string(P->getProtagonist()->takenDng(dmgPotwor)));
					//umieranie gracza
					if (P->getProtagonist()->isDead()) {
						P->SetGold((int)(P->GetGold() * 0.1 + 1));
						P->SetLevel((int)(P->GetLevel() * 0.5 + 1));
						GE.Anamacja(7);
						break;
					}
				}
			}
			if (P->getProtagonist()->isDead()) {
				break;
			}
			delete em;
		}
		if (P->getProtagonist()->isDead()) {
			break;
		}
		M->nextLocation();
		GE.Anamacja(2);
		P->getProtagonist()->cure(P->GetLevel());


		//nieskoñczona pêtla podró¿y dzia³¹ :)
		}
		delete M;

		// ulepszenia na koniec gry 
		bool isdead = P->getProtagonist()->isDead();
		int punkty = P->GetGold() / 100 + P->GetLevel() / 2;
		P->SetGold(0);
		P->SetLevel(0);
		string t[] = { "vitality +5","arrmor +10","DMG +1" };

		for (int i = 1; i <= punkty; i++) {
			string t[3];
			t[0] = "vitality +5 (+" + to_string(DATABASE.GetPowerUpVitality()) + ")";
			t[1] = "arrmor +10 (+" + to_string(DATABASE.GetPowerUpArrmor()) + ")";
			t[2] = "DMG +1(+" + to_string(DATABASE.GetPowerUpDng()) + ")";
		
			cout << i << "/" << punkty << endl;
			wybor = GE.Show_choice(t, 3,6,"Punkty do rozdysponowania " +to_string(i)+"/"+to_string(punkty));
			switch (wybor)
			{
			case 0:
				P->plusVitality();
				break;
			case 1:
				P->plusArrmor();
				break;
			case 2:
				P->plusDmg();
				break;
			default:
				break;
			}
		}
		if (isdead) {
			int n = DATABASE.GetCharacterNameConut();
			string* nazwydraczy = new string[n];
			for (int i = 0; i < n; i++) {
				*(nazwydraczy + i) = DATABASE.GetCharacterName(i);
			}
			int wybor = GE.Show_choice(nazwydraczy, n, 1, "Wybierz now¹ postaæ"); //Show_choice 1
			switch (wybor)
			{
			case 0:
				P->SetProtagonist(new Warrior());
				break;
			case 1:
				P->SetProtagonist(new Hunter());
				break;
			case 2:
				P->SetProtagonist(new Sorcerer());
				break;
			default:

				break;
			}
			delete[]nazwydraczy;
		}
	}

}
/*
* tasama funkcja co gra() ale nie u¿ywa Silnika graficznego
*/
void MG::game_test()
{
	srand(time(NULL));
	//strat
	
	cout << "start"<<endl;  //Show_start
	//wybór postaci
	int n = DATABASE.GetCharacterNameConut(); cout<<"*wziêcie ile jest nazw graczy*"<<endl;
	string* nazwydraczy = new string[n];
	for (int i = 0; i < n; i++) {
		*(nazwydraczy+i) = DATABASE.GetCharacterName(i);
	}
	cout << "*Wziêcie nazw graczy*" << endl;
	int wybor = GE.showGame(-1, nazwydraczy, n); //Show_choice 1
	cout << "wybor:" << wybor << endl;
	switch (wybor)
	{
	case 0:
		P->SetProtagonist(new Warrior()); cout << "wojownik" << endl;
		break;
	case 1:
		P->SetProtagonist(new Hunter()); cout << "³owca" << endl;
		break;
	case 2:
		P->SetProtagonist(new Sorcerer()); cout << "mag" << endl;
		break;
	default:

		break;
	}
	delete[]nazwydraczy;
	cout << P->toString();
	int dmg = 0;
	cout << "*rozpoczêcie gry*" << endl;
	while (true) {
		cout << "*Tworzenie mapy*"<<endl;

		M = new Map();
		M->SetEnemiCount();
		P->getProtagonist()->setHp(P->getProtagonist()->maxHp_level(P->GetLevel()));
		cout << M->toString();
		cout << "*Tworzenie wskaŸnika dla prezciwnika*" << endl;

		Enemi* em;

		cout << "*rozpoczêcie podró¿y"<<endl;
		cout << "------------------------" << endl;
		for (int i = 0; i < 10; i++) {
			cout << "*wrogowie atakuj¹*" << endl;
			
			travel: while (M->GetEnemiCount() > 0) {
				cout << M->toString();
				cout << "------------------------" << endl;

				em = M->GiveEnemi();

				cout << "bohater            wróg" << endl;    
				cout << P->getProtagonist()->getHp() << "/" << P->getProtagonist()->maxHp_level(P->GetLevel()) << "      ";
				cout << em->getHp() << "/" << em->maxHp() << endl;
				while (em->getHp() > 0) {
					cout << "*przeciwnik ¿yje" << endl;
					
					cout << "*atakuje gracz*" << endl;

					wybor = GE.choise(P->getattacksNames(), P->getAttackCount());//Show_choice 2
					dmg = P->getProtagonist()->atack(P->getattacksChance(wybor), P->getattacksMulty(wybor)); cout << "*obrarzenia ustalone"<<dmg<<"*" << endl;
					cout<<em->takenDng(dmg)<<endl;

					cout << "bohater    atakG>     wróg" << endl; //animacja1
					cout << P->getProtagonist()->getHp() << "/" << P->getProtagonist()->maxHp_level(P->GetLevel()) << "      ";
					cout << em->getHp() << "/" << em->maxHp() << endl;
					if (em->isDead()) {
						int gold = (em->getId() + 1) * (em->getArchetype() + 1) * 10 + rand() % 500;
						int exp = em->maxHp() * em->getBaseDng()*0.3;
						P->SetGoldPlus(gold);
						P->SetExpPlus(exp);
						
						cout << "Zdobysza\n z³oto: " << gold << "\t exp: " << exp << endl;
						cout << "sprawdzanie levelu"<<endl;   //Show_info
						if (P->LevelUpAlready()) {
							P->levleUp();
						}

					}
					else {
						cout << "*atakuje potwór*" << endl;

						int atakPotwor = rand() % em->getAttackCount();
						int dmgPotwor = em->atack(atakPotwor);
						cout<<P->getProtagonist()->takenDng(dmg)<<endl;
						cout << "bohater    <atakP     wróg" << endl; //anamacja 2
						cout << P->getProtagonist()->getHp() << "/" << P->getProtagonist()->maxHp_level(P->GetLevel()) << "      ";
						cout << em->getHp() << "/" << em->maxHp() << endl;

						//umieranie gracza
						if (P->getProtagonist()->isDead()) {
							P->SetGold((int)(P->GetGold() * 0.1+1));
							P->SetLevel((int)(P->GetLevel() * 0.5+1));
							cout << "nie ¿yjesz" << endl;
							break ;
						}
					}
				}
				if (P->getProtagonist()->isDead()) {
					break;
				}
				delete em;
			}
			if (P->getProtagonist()->isDead()) {
				break;
			}
			cout << "*nowa lokacja*" << endl;
			M->nextLocation();
			cout << "*leczenie*" << endl;
			P->getProtagonist()->setHp(P->getProtagonist()->maxHp_level(P->GetLevel()));
			
			//dodaj umieranie gracza 
			//nieskoñczona pêtla podró¿y dzia³¹ :)
		}
		delete M;

		// ulepszenia na koniec gry 
		cout << "*koniec podró¿y*" << endl;
		int punkty = P->GetGold() / 100 + P->GetLevel() / 5;
		string t[] = { "vitality","arrmor","DMG" };
		for (int i = 1; i <= punkty; i++) {
			cout << i << "/" << punkty<<endl;
			wybor = GE.choise(t, 3);
			switch (wybor)
			{
			case 0:
				P->plusVitality();
				break;
			case 1:
				P->plusArrmor();
				break;
			case 2:
				P->plusDmg();
				break;
			default:
				break;
			}
		}

		cin >> wybor;
	}

	/*
	GE.SetPlayer(P); log("ustawienie gracza dala GE");
	//nieskoñczona pêtla gry	
	while (true) {
		//tworzemie mapy
		M = new Map();
		Enemi* em;
		GE.SetMap(M); log("ustawienie mapy");

		for (int i = 0; i < 10; i++) {
			GE.showGame(2);
			srand(time(NULL));
			log("nowa lokacja");
			M->SetEnemiCount();
			while (M->GetEnemiCount() > 0) {
				//walka
				em = M->GiveEnemi();
				GE.SetEnemi(em); log("ustawienie przeciwnika");
				while (!em->isDead()) {
					//int n = rand() % 11; 
					int n = 2; log("kto pierwszy");
					if (n % 2 == 0) {
						//atakuje pierwszy gracz
						log("gracz");
						//ogarniêcie akatów
						int wybor = 0;
						int count = DATABASE.GetAttackCount(P->getProtagonist()->getId()) + 1; log(to_string(count));
						string* t = new string[count]; log("ogarniêcie ataków1");
						t[0] = "Wybierz atak";
						for (int i = 1; i < count; i++) {
							t[i] = DATABASE.GetAttackNames(P->getProtagonist()->getId(), i - 1);
						} log("ogarniêcie ataków2");
						wybor = GE.showGame(3, t, count);
						delete[]t;
						//ustalenie dmg
						int dmg = P->getProtagonist()->atack(
							DATABASE.GetAttackChance(P->getProtagonist()->getId(), wybor),
							DATABASE.GetAttackMulti(P->getProtagonist()->getId(), wybor));
						log("atak");
						log(to_string(dmg));
						//sprawdzenie trafienia
						if (dmg == 0)
							GE.showGame(31, true, false, dmg);
						else
							GE.showGame(31, true, true, dmg);
						em->takenDng(dmg); log("otrzymanie obrarzeñ");
						//sprawdzanie czy nie ¿yje
						if (em->isDead()) {
							log("przeciwnik nie ¿yje");
							GE.showGame(4);
							int gold = em->getId() * 100;
							int exp = em->getArchetype() * em->getId() * 10;
							P->SetExpPlus(exp);
							P->SetGoldPlus(gold);
							GE.showGame(41, exp, gold);
						}

					}
				}


				log("usuwanie przeciwnika");
				delete em;
			}
			M->nextLocation();

		}
	}
	*/
}

void MG::log(string s)
{
	if(logs)
	cout << "*" << s << "*" << endl;
}

MG::~MG()
{
	delete P;
	if (M != nullptr) delete M;
}
