#pragma once
#include<iostream>

using namespace std;

class DataBase
{
private:
	//liczniki
	 int CharacterCount;
	 int ArchetypeCount;
	 int* NamesEnemiCount;
	//-------------------BASE-----------------
	 int* BaseVitality;   //to jest podstawa hp                 //to tabele
	 int* BaseEnemiVitality;                                     //to tabele
	 int* BaseArrmor;	  //pancerz liczony przez log 10000    //to tabele
	 int* BaseEnemiArrmor;                                      //to tabele
	 int* BaseDng;		   //podstawa obra�e�                  //to tabele
	 int* BaseEnemiDng;	                                       //to tabele
	//------------------NAMES------------------------
	 string* NamesArchetypeEnemi; //nazwy archetyp�w np nieumar�y, paj�k
	 string** NamesEnemi;  //nazwy potwork�w
	 string* CharacterName;
	//---------------------Attack----------------------
	//    enemi   [arch][level][nazwa]
	//    player  [class][nazwa]
	 int** AttackEnemiCount;
	 int* AttackCount;
	 string*** AttackEnemiNames;     // nazwy atak�w potwotk�w              //tabele dwu wymiarowe
	 string** AttackNames;
	 double*** AttackEnemiChance;    // szansa na trafienie  w pliku b�dzie max 100 a tu zapisane max 1  v/100
	 double** AttackChance;
	 double*** AttackEnemiMulti;     // zwi�kszenie obra�e� np 1.23   // zapis w pliku jak powy�ej 
	 double** AttackMulti;
	//----------------------Special-----------------------
	 double* SpecialAbility;  //warto�� dla umi�tno�ci specjalnej zale�ne od klasy
	//---------------------Multi-Level-----------------------
	 double* MultiLevelHp;// zwi�kszenie hp na level // 1.01
	 double* MultiLevelHpEnemi;
	//--------------------PowerUp---------------------------
	//wybierane przez gracza przy levelowaniu w mie�cie
	int PowerUpVitality;
	int PowerUpDng;
	int PowerUpArrmor;
	//--------------------MAPA-------------------------------------
	string* NamesLocation;
	int NamesLocationCount;

public:
	DataBase(bool show=0);
	~DataBase();
	int GetBaseVitality(int id) ;
	int GetBaseEnemiVitalit(int arch);
	double GetBaseArrmor(int id) 		;
	double GetBaseEnemiArrmor(int arch) 	;
	int GetBaseDng(int id) 			;
	int GetBaseEnemiDng(int arch) 		;
								;
	string GetNamesArchetypeEnem(int arch);
	string GetNamesEnemi(int arch, int level) 		;
	int GetNamesArchetypeEnemCount();
	int GetNamesEnemiCount(int arch);
					
	int GetAttackEnemiCount(int arch, int level);
	string GetAttackEnemiNames(int arch, int level,int idName) ;
	string GetAttackNames(int id, int idName)  	;
	double GetAttackEnemiChance(int arch, int level, int idName);
	double GetAttackChance(int id, int idName)  	;
	double GetAttackEnemiMulti(int arch, int level, int idName) ;
	double GetAttackMulti(int id, int idName) 		;
								;
	double GetSpecialAbility(int id)  ;
								;
	double  GetMultiLevelHp(int id) 	;
	double  GetMultiLevelHpEnemi(int arch);
								;
	int  GetPowerUpVitality( );
	int  GetPowerUpDng( )		;
	int  GetPowerUpArrmor( )  ;
	void SetPowerUpVitality( int value);
	void SetPowerUpDng(int value);
	void SetPowerUpArrmor( int value);
	void SetPlusPowerUpVitality(int plus);
	void SetPlusPowerUpDng( int plus);
	void SetPlusPowerUpArrmor( int plus);

	string GetNameLocation(int i);
	int GetNamesLocationCount();

	string GetCharacterName(int i);
	int GetCharacterNameConut();
	int GetAttackCount(int id);

	void Show_DATABASE();
};		
extern DataBase DATABASE;

