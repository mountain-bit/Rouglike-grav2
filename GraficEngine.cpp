#include "GraphicEngine.h"

void GraphicEngine::ShowGame_Characters()
{
	cout << E->getArchetype();
	cout << setw(10) <<DATABASE.GetCharacterName(P->getProtagonist()->getId())<<setw(11)<<" "<<setw(9)<<DATABASE.GetNamesEnemi(E->getArchetype(),E->getId()) << endl;
	cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
	cout << setw(10) << "o " << setw(10) << " " << setw(10) << "| |000| |" << endl;
	cout << setw(10) << "/|\\" << setw(10) << " " << setw(10) << "|  ___  |" << endl;
	cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;
	cout << setw(4) << P->getProtagonist()->getHp() << " / " << setw(4) << P->getProtagonist()->maxHp()<<setw(10)<<" " <<setw(4)<< E->getHp()<<" / "<<setw(4)<<E->maxHp()<<endl;
}

void GraphicEngine::ShowGame_separator()
{
	cout << setw(40) << "----------------------------------------" << endl;
}

void GraphicEngine::ShowGame_choice(string s)
{
	

	switch (stan)
	{
	case 1:
	case 6:
		ShowGame_separator();
		ShowGame_title();
		ShowGame_separator();
		cout << s << endl;
		break;
	case 3:
		ShowGame_separator();
		ShowGame_title();
		ShowGame_separator();
		ShowGame_map();
		ShowGame_separator();
		ShowGame_Characters();
		cout << s << endl;
		break;
	case -1:
		break;
		default:
		break;
	}
}

void GraphicEngine::ShowGame_hello()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));

	cout << setw(10) << "witaj podró¿niku!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));

}

void GraphicEngine::ShowGame_title()
{

	cout << setw(24) << right << "NAME GAME" << endl;

}

void GraphicEngine::ShowGame_travelEnd()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
	cout << setw(20) << "Uda³o Ci siê! Ukoñczy³êœ swoj¹ podró¿!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
	cout << setw(20) << "O to twoje zdobycze" << endl;
	cout << setw(10) << "1. Z³oto: " << P->GetGold()<<endl;
	cout << setw(10) << "2. Poziomy: " << P->GetLevel()<<endl;

}

void GraphicEngine::ShowGame_playerDie()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony));
	cout << setw(20) << "NIE ¯YJESZ!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
	cout << setw(20) << "O to twoje zdobycze" << endl;
	cout << setw(10) << "1. Z³oto: " << P->GetGold()/10 << endl;
	cout << setw(10) << "2. Poziomy: " << P->GetLevel() / 3 << endl;

}

void GraphicEngine::ShowGame_map(int x)
{
	if (!log) cout << "mapa";
	int location = M->GetLocationCount() - 3;
	if (location < 0)location += 3;
	if (x == 0) {
		
		if (!log) cout << "mapa";
		for(int i=0;i<=2&&i<=location;i++)
		cout << setw(3) << " " << setw(5) << "_____" << location+i << setw(5) << "______";
		cout << endl;
		for (int i = 0; i <= 2 && i <= location; i++)
			cout << setw(3) << " " <<"|" << setw(11) << " "<<"|";
		cout << endl;
		for (int i = 0; i <= 2 && i <= location; i++)
			cout << setw(3) << "---" << "|" << setw(11) << M->GetNameLocation(location + i) << "|";
		cout << endl;
		for (int i = 0; i <= 1 && i <= location-1; i++)
			cout << setw(3) << " " <<"|" << setw(11) << "___________"<<"|";

		cout << setw(3) << " " << setw(5) << "_____" << M->GetEnemiCount() << setw(5) << "______";
		cout << endl;
	}
	else {
		for (int i = 0; i <= 1 && i <= location; i++)
			cout << setw(3) << " " << setw(5) << "_____" << location + i << setw(5) << "______";
		cout << endl;
		for (int i = 0; i <= 1 && i <= location; i++)
			cout << setw(3) << " " << "|" << setw(11) << " " << "|";
		cout << endl;
		for (int i = 0; i <= 1 && i <= location; i++)
			cout << setw(3) << "---" << "|" << setw(11) << M->GetNameLocation(location + i) << "|"; for (int j = 4; j >= x; j--)cout << "-";
		cout << endl;
		for (int i = 0; i <= 1 && i <= location; i++)
			cout << setw(3) << " " << "|" << setw(11) << "___________" << "|";
		cout << endl;
		ShowGame_separator();
		if (x == 4) cout << " o" << endl << "/|\\" << endl << "/|"<<endl;
		if (x == 3) cout << " o" << endl << "/|\\" << endl << "/ \\ " << endl;
		if (x == 2) cout << " o" << endl << "/|\\" << endl << " |\\ " << endl;
		if (x == 1) cout << " o" << endl << "/|\\" << endl << "/ \\" << endl;
	}
}

void GraphicEngine::ShowGame_Fight(bool who, bool t, int i, int obr)
{
	if(who)
		switch (i)
		{
		case 0:
		atak00: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId())<<endl;
			cout << setw(10) << " " << setw(10) << " ";if(t) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu)); cout << setw(10) << "_______" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << "o " << setw(10) << " "; if (t) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu)); cout << setw(10) << "| |000| |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << "/|\\";
			cout << setw(10) << "          "; if (t) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu)); cout << setw(10) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << "/ \\" << setw(10) << " "; if (t) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu)); cout << setw(10) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << " " << setw(10) << " " << setw(10) << obr;
		}
			break;
		case 1:
		atak01: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << "o " << setw(10) << " " << setw(10) << "| |000| |" << endl;
			cout << setw(10) << "/|\\ ";
			switch (P->getProtagonist()->getId())
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
				cout << setw(10) << "     ->---";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(10) << "     >>-->";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(10) << "     -<0>-";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			default:
				break;
			} cout  << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;
		}
			break;
		case 2:
		atak02: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << "o " << setw(10) << " " << setw(10) << "| |000| |" << endl;
			cout << setw(10) << "/|\\";
			switch (P->getProtagonist()->getId())
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
				cout << setw(10) << "   ->---  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(10) << "   >>-->  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(10) << "   -<0>-  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			default:
				break;
			} cout  << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;
		}
			break;
		case 3:
		atak03: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << " o " << setw(10) << " " << setw(10) << "| |000| |" << endl;
			cout << setw(10) << "/|\\";
			switch (P->getProtagonist()->getId())
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
				cout << setw(10) << "  ->---   ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(10) << "  >>-->  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(10) << "  -<0>-   ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			default:
				break;
			} cout << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;
		}
			break;
		case 4:
		atak04: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << " o/" << setw(10) << " " << setw(10) << "| |000| |" << endl;
			cout << setw(10) << "/| ";
			switch (P->getProtagonist()->getId())
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
				cout << setw(10) << "->---     ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(10) << ">>-->    ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(10) << "-<0>-     ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				break;
			default:
				break;
			} cout << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;
		}
			break;
		
		default:
			break;
		}
	else
		switch (i)
		{
		case 0:
		atak10: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			if(t)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
			cout << setw(10) << " o ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << " " << setw(10) << "| |0000| |" << endl;
			if (t)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
			cout << setw(10) << "/|\\";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout <<setw(10)<<" "<< setw(10) << "|  ___  |" << endl;
			if (t)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
			cout << setw(10) << "/ \\";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(10) << " " << setw(10) << "|_|___|_|" << endl;
			cout << setw(10) << obr << setw(10) << " " << setw(10) << " ";
		}
		break;
		case 1:
		atak11: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << " o " << setw(10) << " " << setw(10) << "| |0000| |" << endl;
			cout << setw(10) << "/|\\ ";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
			cout << setw(10) << "-<0>-     ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;

		}
		break;
		case 2:
		atak12: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << " o " << setw(10) << " " << setw(10) << "| |0000| |" << endl;
			cout << setw(10) << "/|\\ ";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
			cout << setw(10) << "  -<0>-   ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;

		}
		break;
		case 3:
		atak13: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << " o " << setw(10) << " " << setw(10) << "| |0000| |" << endl;
			cout << setw(10) << "/|\\";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
			cout << setw(10) << "   -<0>-  ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(10) << "|  ___  |" << endl;
			cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;

		}
		break;
		case 4:
		atak14: {
			cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId()) << endl;
			cout << setw(10) << " " << setw(10) << " " << setw(10) << "_______" << endl;
			cout << setw(10) << " o " << setw(10) << " " << setw(10) << "| |----| |" << endl;
			cout << setw(10) << "/|\\";
			
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(10) << "     -<0>-";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << setw(10) << "|  ___  |" << endl;
				cout << setw(10) << "/ \\" << setw(10) << " " << setw(10) << "|_|___|_|" << endl;

		}
		break;

		default:
			break;
		}

}

void GraphicEngine::ShowGame_EnemiDie()
{
	cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << DATABASE.GetNamesEnemi(E->getArchetype(), E->getId())<<endl;
	cout << setw(10) << " " << setw(10) << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony));
	cout << setw(10) << "_______" ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
	cout << endl << setw(10) << " o" << setw(10) << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony));

	cout << setw(10) << "| |000| |" ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));

	cout << endl << setw(10) << "/|\\" << setw(10) << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony));

	cout << setw(10) << "|  ___  |" ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));

	cout << endl << setw(10) << "/ \\ " << setw(10) << " ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony));

	cout << setw(10) << "|_|___|_|" ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));

	cout << endl;
}

void GraphicEngine::ShowGame_prize(int gold, int exp)
{
	cout << setw(10) << DATABASE.GetCharacterName(P->getProtagonist()->getId()) << setw(11) << " " << setw(9) << "";
	cout << setw(10) << " " << setw(10) << " " << setw(10) << " " << endl;
	cout << setw(10) << " o" << setw(10) << " " << setw(6) << "z³oto: " <<setw(5)<<gold<< endl;
	cout << setw(10) << "/|\\" << setw(10) << " " << setw(4) << "exp:" <<setw(6)<<exp<< endl;
	cout << setw(10) << "/ \\ " << setw(10) << " " << setw(10) << " " << endl;

}

GraphicEngine::GraphicEngine()
{
	stan = 0;
	animationTime = 100;
	log = false;
}

void GraphicEngine::SetPlayer(Player* p)
{
	P = p;
}

void GraphicEngine::SetEnemi(Enemi* e)
{
	E = e;
}

void GraphicEngine::SetMap(Map* m)
{
	M = m;
}

int GraphicEngine::choise(string* tab, int n)
{
	int wybor = 0;
	int znak = 0;

	while (true) {
		if(log)system("cls");
		ShowGame_choice("jakiœ wybór trza dopisaæ swicha");

		//wypisanie
		for (int i = 0; i < n; i++) {
			if (wybor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(4) << i << ". ";
				cout << setw(30) << tab[i];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));

			}
			else {
				cout << setw(4) << i << ". ";
				cout << setw(30) << tab[i];
			}
			cout << endl;
		}
		ShowGame_separator();
		//wybór
		znak = _getch();
		switch (znak)
		{
		case 0: //klawisze specjalne (czasem zero czasem 224 - zale?ne od pc'ta chyba)
		case 224: //klawisze specjalne
			znak = _getch();
			switch (znak)
			{
			case 72: //strza?ka w g?r?
				wybor--;
				if (wybor < 0) {
					wybor = n ;
				}
				break;
			case 80: //strza?ka w d?
				wybor++;
				if (wybor >= n) {
					wybor = 0;
				}
				break;
			}
			znak = 0;
			break;
		case 13: //ENTER
			return wybor;
			break;
		}

	}

	return 0;
}

void GraphicEngine::showGame(int s)
{
	stan = s;
	string g;
	if(log)system("cls");
	switch (stan)
	{
		//start
		
	case 0:
		ShowGame_separator();
		ShowGame_title();
		ShowGame_separator();
		ShowGame_hello();
		
		cin >> g;
		break;
	case 2:
		for (int i = 4; i >= 1; i--) {
			if(log)system("cls");
			ShowGame_separator();
			ShowGame_title();
			ShowGame_separator();
			ShowGame_map(i);
			ShowGame_separator();
			Sleep(animationTime);
		}
		break;
	//koniec podró¿y
	case 5:
		ShowGame_separator();
		ShowGame_title();
		ShowGame_separator();
		ShowGame_travelEnd();
		ShowGame_separator();
		cin >> g;
		break;
	case 7:
		ShowGame_separator();
		ShowGame_title();
		ShowGame_separator();
		ShowGame_playerDie();
		ShowGame_separator();
		cin >> g;
		break;
	case 4:
		if(log)system("cls");
		ShowGame_separator();
		ShowGame_title();
		ShowGame_separator();
		ShowGame_map();
		ShowGame_separator();
		ShowGame_EnemiDie();
		Sleep(animationTime * 4);
		break;
	default:
		cout << endl<<"---------------B³ad silnika-----------" << endl;
		break;
	}
}

int GraphicEngine::showGame(int s, string* tab, int n)
{
	stan = s;
	if(log)system("cls");
	return choise(tab,n);
}

void GraphicEngine::showGame(int s, bool who, bool t,int obr)
{
	for (int i = 4; i >= 0; i--) {
		if (log)system("cls");
	ShowGame_separator();
	ShowGame_title();
	ShowGame_separator();
	ShowGame_map();
	ShowGame_separator();
	
		ShowGame_Fight(who, t, i,obr);
		if (i == 0)
			Sleep(2000);
		else
			Sleep(animationTime);
	}
	
}

void GraphicEngine::showGame(int s, int exp, int gold)
{
	ShowGame_separator();
	ShowGame_title();
	ShowGame_separator();
	ShowGame_map();
	ShowGame_separator();
	ShowGame_prize(gold,exp);
	Sleep(animationTime * 10);
}
//popraw ---maksymalna iloœæ znaków w nazwie to 9
void GraphicEngine::Show_map()
{
	int ileLokacji = M->GetLocationCount();
		if (ileLokacji >= 4) {
			for (int i = 0; i < 4; i++) {
				cout << setw(5) << "____-" << ileLokacji - (3 - i) << setw(5) << "-_____" << setw(4) << " ";
			}
			cout << endl;
			for (int i = 0; i < 4; i++) {
				cout << setw(11) << "|         |" << setw(4) << " ";
			}
			cout << endl;
			for (int i = 0; i < 4; i++) {
				cout << setw(1) << "|" << setw(8) << M->GetNameLocation(ileLokacji - (3 - i)) << setw(2) << " |";
				if (i != 2) {
					cout << setw(4) << "----";
				}
				else {
					cout << setw(4) << "----";  //tutaj siê zmienia
				}
			}

			cout << endl;
			for (int i = 0; i < 3; i++) {
				cout << setw(12) << "|_________|" << setw(4) << " ";
			}
			cout << setw(5) << "|___-" << setw(1) << M->GetEnemiCount() << setw(5) << "-___| " << setw(4) << " " << endl;


		}
		else {
			for (int i = 0; i <= ileLokacji ; i++) {
				cout << setw(5) << "____-" << i + 1 << setw(5) << "-____" << setw(4) << " ";
			}
			cout << endl;
			for (int i = 0; i <= ileLokacji ; i++) {
				cout << setw(11) << "|         |" << setw(4) << " ";
			}
			cout << endl;
			for (int i = 0; i <= ileLokacji ; i++) {
				cout << setw(1) << "|" << setw(8) << M->GetNameLocation(i) << setw(2) << " |";
				if (i == ileLokacji) {
					cout << setw(4) << " ";
				}
				else {
					cout << setw(4) << "----";  //tutaj siê zmienia
				}
			}

			cout << endl;
			for (int i = 0; i <= ileLokacji-1; i++) {
				cout << setw(11) << "|_________|" << setw(4) << " ";
			}
			cout << setw(5) << "|___-"<<setw(1)<<M->GetEnemiCount()+1 <<setw(5)<<"-___|" << setw(4) << " "<<endl;
		}
		Show_separator();
		setlocale(LC_CTYPE, "Polish"); //¿eby mo¿na by³o wyœwietliæ "³"
		cout << "Level " << P->GetLevel() << endl;
		cout << P->GetExp() << "/" << P->GetToNextLevel() << " exp" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
		cout << "z³oto " << P->GetGold() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
		setlocale(LC_CTYPE, ".UTF8");
}

void GraphicEngine::Show_heroAndEnemi()
{
	cout << right;
	cout << setw(size/4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
	cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
	cout << setw(size / 4) << "/|\\" << setw(size / 4) << " " << setw(size / 4) << "|  ___  |" << endl;
	cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;

}

void GraphicEngine::Show_stats()
{
	
	cout << setw(size / 4) <<left<< P->GetName() << setw(size / 4) << " " << setw(size / 4) << E->getName() <<endl;

	if(P->getProtagonist()->getHp()/(double) P->getProtagonist()->maxHp_level(P->GetLevel())>0.7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
	else if (P->getProtagonist()->getHp() / (double)P->getProtagonist()->maxHp_level(P->GetLevel()) > 0.4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
	cout << setw(size / 4) << left << "Hp: " + to_string(P->getProtagonist()->getHp()) + " / " + to_string(P->getProtagonist()->maxHp_level(P->GetLevel())) << setw(size / 4) << " ";
	if (E->getHp() / (double)E->maxHp() > 0.7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
	else if (E->getHp() / (double)E->maxHp() > 0.4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
	cout << setw(size / 4) << left << "Hp: " + to_string(E->getHp()) + " / " + to_string(E->maxHp())<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
	cout << setw(size / 4) << left << "Arrmor: " + to_string(P->getProtagonist()->getBaseArrmor()) << setw(size / 4) << " ";
	cout << setw(size / 4) << left << "Arrmor: " + to_string(E->getBaseArrmor()) << endl;

	cout << setw(size / 4) << left << "DMG: " + to_string(P->getProtagonist()->getBaseDng()) << setw(size / 4) << " ";
	cout << setw(size / 4) << left << "DMG: " + to_string(E->getBaseDng()) << endl;

}

void GraphicEngine::Show_separator()
{
	for (int i = 0; i < size; i++) {
		cout << "-";
	}
	cout << endl;
}

void GraphicEngine::Show_start()
{
	system("cls");
	Show_separator();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(cyjan));
	cout <<setw(17)<< "Legendy";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
	cout << setw(20) << " Zapomnianych";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty)); 
	cout << setw(10) << " Krain";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
	cout << endl;
	Show_separator();
	char g;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
	cout << "START"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
	do {
		g = _getch();
	} while (g != 13);
	return;

}

int GraphicEngine::Show_choice(string* t, int n, int stan, string komunikat, int inne, string inneS)
{
	int wybor = 0;
	int znak = 0;
	this->stan = stan;
	while (true) {
		system("cls");
		switch (stan)
		{
		case 1:
			Show_separator();
			cout << "Wybierz swoj¹ postaæ: " << endl;
			break;
		case 3:
			//separator
			//mapa
			// //separator
			//bohater i potwór
			// //separator
			//sattystyki
			//separator
			// i dopiero tutaj wybor
			Show_separator();
			Show_map();
			Show_separator();
			Show_heroAndEnemi();
			Show_separator();
			Show_stats();
			Show_separator();
			cout << "Wybierz atak: " << endl;
			break;
		case 6:
		case 61:
			Show_separator();
			cout << komunikat << endl;

			break;
		default:
			break;
		}

		//wypisanie
		for (int i = 0; i < n; i++) {
			if (wybor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(4) << i << ". ";
				cout << setw(30) << t[i];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));

			}
			else {
				cout << setw(4) <<to_string(i)+".";
				cout << setw(30) << t[i];
			}
			cout << endl;
		}
		Show_separator();
		//wybór
		znak = _getch();
		switch (znak)
		{
		case 0: //klawisze specjalne (czasem zero czasem 224 - zale?ne od pc'ta chyba)
		case 224: //klawisze specjalne
			znak = _getch();
			switch (znak)
			{
			case 72: //strza?ka w g?r?
				wybor--;
				if (wybor < 0) {
					wybor = n-1;
				}
				break;
			case 80: //strza?ka w d?
				wybor++;
				if (wybor >= n) {
					wybor = 0;
				}
				break;
			}
			znak = 0;
			break;
		case 13: //ENTER
			return wybor;
			break;
		}

	}
	return 0;
}

void GraphicEngine::Anamacja(int stan, int klatka, string info)
{
	this->stan = stan;
	int ileLokacji;//inicjalizacja jest tutaj bo kompulator siê pruje o to
	system("cls");
	if (klatka == -1)klatka = 0;
	switch (stan)
	{
	case 2: //animacja mapy
		
		Show_separator();
		 ileLokacji = M->GetLocationCount();
		if (ileLokacji ==0) {
			cout << setw(5) << "____-" << ileLokacji + 1 << setw(5) << "-____" << endl;
			cout << setw(11) << "|         |" << endl;
			cout << setw(1) << "|" <<setw(8)<< M->GetNameLocation(0) << setw(2) << " |" << endl;
			cout << setw(11) << "|_________|" << endl;
		}
		switch (klatka) {
		case 0:
			if (ileLokacji > 4) {
				for (int i = 0; i < 3 ; i++) {
					cout << setw(5) << "____-" << ileLokacji-(3-i) << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(ileLokacji - (3 - i)) << setw(2) << " |";
					if (i != 2) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "-   ";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}

			}
			else {
				for (int i = 0; i <= ileLokacji-1; i++) {
					cout << setw(5) << "____-" << i + 1 << setw(5) << "-____"<<setw(4)<<" ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(i) << setw(2) << " |";
					if (i != ileLokacji - 1) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "-   ";  //tutaj siê zmienia
					}
				}
				
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}
			}
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 1:
			if (ileLokacji > 4) {
				for (int i = 0; i < 3; i++) {
					cout << setw(5) << "____-" << ileLokacji - (3 - i) << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(ileLokacji - (3 - i)) << setw(2) << " |";
					if (i != 2) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "--  ";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}

			}
			else {
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(5) << "____-" << i + 1 << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(i) << setw(2) << " |";
					if (i != ileLokacji - 1) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "--  ";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}
			}
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 2:
			if (ileLokacji > 4) {
				for (int i = 0; i < 3; i++) {
					cout << setw(5) << "____-" << ileLokacji - (3 - i) << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(ileLokacji - (3 - i)) << setw(2) << " |";
					if (i != 2) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "--- ";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}

			}
			else {
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(5) << "____-" << i + 1 << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(i) << setw(2) << " |";
					if (i != ileLokacji - 1) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "--- ";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}
			}
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 3:
			if (ileLokacji > 4) {
				for (int i = 0; i < 3; i++) {
					cout << setw(5) << "____-" << ileLokacji - (3 - i) << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(ileLokacji - (3 - i)) << setw(2) << " |";
					if (i != 2) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "----";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}

			}
			else {
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(5) << "____-" << i + 1 << setw(5) << "-____" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|         |" << setw(4) << " ";
				}
				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(1) << "|" << setw(8) << M->GetNameLocation(i) << setw(2) << " |";
					if (i != ileLokacji - 1) {
						cout << setw(4) << "----";
					}
					else {
						cout << setw(4) << "----";  //tutaj siê zmienia
					}
				}

				cout << endl;
				for (int i = 0; i <= ileLokacji - 1; i++) {
					cout << setw(11) << "|_________|" << setw(4) << " ";
				}
			}
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		}
		
		break;
	case 31: //gracz atakuje
		Show_separator();
		Show_map();
		Show_separator();
		switch (klatka) {
		case 0:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
			cout << setw(size / 4) << " o/" << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
			cout << setw(size / 4) << "/| " << setw(size / 4) << " " << setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 1:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
			cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
			cout << setw(size / 4) << "/|\\";
			switch (P->getProtagonist()->getId()) {
			case 0:
				cout << left;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(szary));
				cout << setw(size / 4) << "->----";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << right;
				break;
			case 1:
				cout << left;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(size / 4) << ">>--->";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << right;
				break;
			case 2:
				cout << left;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
				cout << setw(size / 4) << "-<0>-"  ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << right;
				break;
			}
			

			cout<< setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" <<endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 2:

			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
			cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
			cout << setw(size / 4) << "/|\\";
			switch (P->getProtagonist()->getId()) {
			case 0:
				cout << right;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(szary));
				cout << setw(size / 4)<<"->----" ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << right;
				break;
			case 1:
				cout << right;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(size / 4)  << ">>--->" ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << right;
				break;
			case 2:
				cout << right;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwonu));
				cout << setw(size / 4) << "-<0>-" ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << right;
				break;
			}


			cout << setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 3:


			cout << left;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
			cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
			cout << setw(size / 4) << "/|\\";
			switch (P->getProtagonist()->getId()) {
			case 0:
				cout << right;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(szary));
				cout << setw(size / 4)<< "->----" ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << left;
				break;
			case 1:
				cout << right;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zielony));
				cout << setw(size / 4) << ">>--->"  ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << left;
				break;
			case 2:
				cout << right;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czarny_czerony));
				cout << setw(size / 4) << "-<0>-"  ;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
				cout << left;
				break;
			}


			cout << setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << info << endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime * 3);
			Anamacja(stan, klatka + 1, info);
			break;
		}


		
		break;
	case 32: //potwór atakuje

		Show_separator();
		Show_map();
		Show_separator();
		switch (klatka) {
		case 0:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "_()___()_" << endl;
			cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |---| |" << endl;
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " " << setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 1:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
			cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
			cout << setw(size / 4) << "/|\\";
			cout << right;
			cout << setw(size / 4) << "0/0/0";
			cout << right;



			cout << setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 2:

			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "__)___(__" << endl;
			cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << "| |000| |" << endl;
			cout << setw(size / 4) << "/|\\";

			cout << left;
			cout << setw(size / 4) << "0/0/0";
			cout << right;



			cout << setw(size / 4) << "|  ___  |" << endl;
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << "|_|___|_|" << endl;
			cout << info << endl;
			Show_separator();
			Show_stats();
			Sleep(animationTime*3);
			Anamacja(stan, klatka + 1, info);
			break;

			
		}
		break;
	case 4: //potwór nie ¿yje
		Show_separator();
		Show_map();
		Show_separator();
		switch (klatka)
		{
		case 0:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout  << setw(size / 4) << "__)___(__" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << " o " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "| |000| |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 1:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << " o " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "| |000| |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 2:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << " o " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 3:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << " o " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 4:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << " o " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		default:
			break;
		}
		
		break;
	case 41: //gracz leveluje
		break;
	case 7: //gracz umiera
		Show_separator();
		Show_map();
		Show_separator();
		switch (klatka)
		{
		case 0:
			cout << right;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));  cout << setw(size / 4) << "__)___(__" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "  " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "| |000| |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 1:
			cout << right;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));  cout << setw(size / 4) << "__)___(__" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "| |000| |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 2:
			cout << right;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));  cout << setw(size / 4) << "__)___(__" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "  " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "| |000| |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "|  ___  |" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		case 3:
			cout << right;
			cout << setw(size / 4) << " " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << " o " << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/|\\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << " " << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << setw(size / 4) << "/ \\" << setw(size / 4) << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(czerwony_czerwony)); cout << setw(size / 4) << "|_|___|_|" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
			cout << left;
			Show_separator();
			Show_stats();
			Sleep(animationTime);
			Anamacja(stan, klatka + 1, info);
			break;
		
		default:
			break;
		}

		break;
	default:
		break;
	}
}

void GraphicEngine::Show_info(int stan, string info)
{
	this->stan = stan;
	char znak;
	system("cls");
	switch (stan) {
	case 41:
		Show_separator();
		Show_map();
		Show_separator();
		cout << setw(size / 4) << " " << setw(size / 4) << " " << setw(size / 4) << "  " << endl;
		cout << setw(size / 4) << " o " << setw(size / 4) << " " << setw(size / 4) << " " << endl;
		cout << setw(size / 4) << "/|\\" << setw(size / 4) << " " << setw(size / 4) << " " << endl;
		cout << setw(size / 4) << "/ \\" << setw(size / 4) << " " << setw(size / 4) << " " << endl;
		setlocale(LC_CTYPE, "Polish");
		cout << info << endl;
		setlocale(LC_CTYPE, ".UTF8");
		Show_separator();
			znak = _getch();
		break;
	case 42: //level up
		Show_separator();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
		cout << setw(size / 4) << "*" << setw(size / 4) << "* "  << setw(size / 4) << " * " << endl;

		cout << setw(size / 4) << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
		cout << setw(size / 4) << " o " << setw(size / 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
		cout << "* " << endl;
		cout << setw(size / 4) << " *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
		cout << setw(size / 4) << "/|\\";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
		cout << setw(size / 4) << "* " << endl;
		
		cout << setw(size / 4) << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy)); 
		cout << setw(size / 4) << "/ \\" << setw(size / 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(zolty));
		cout << " *" << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(niebieski));
		cout << info << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolory(bialy));
		Show_separator();
			znak = _getch();
		break;
	}
}


GraphicEngine GE = GraphicEngine();