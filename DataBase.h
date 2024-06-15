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
	 int* BaseDng;		   //podstawa obra¿eñ                  //to tabele
	 int* BaseEnemiDng;	                                       //to tabele
	//------------------NAMES------------------------
	 string* NamesArchetypeEnemi; //nazwy archetypów np nieumar³y, paj¹k
	 string** NamesEnemi;  //nazwy potworków
	 string* CharacterName;
	//---------------------Attack----------------------
	//    enemi   [arch][level][nazwa]
	//    player  [class][nazwa]
	 int** AttackEnemiCount;
	 int* AttackCount;
	 string*** AttackEnemiNames;     // nazwy ataków potwotków              //tabele dwu wymiarowe
	 string** AttackNames;
	 double*** AttackEnemiChance;    // szansa na trafienie  w pliku bêdzie max 100 a tu zapisane max 1  v/100
	 double** AttackChance;
	 double*** AttackEnemiMulti;     // zwiêkszenie obra¿eñ np 1.23   // zapis w pliku jak powy¿ej 
	 double** AttackMulti;
	//----------------------Special-----------------------
	 double* SpecialAbility;  //wartoœæ dla umiêtnoœci specjalnej zale¿ne od klasy
	//---------------------Multi-Level-----------------------
	 double* MultiLevelHp;// zwiêkszenie hp na level // 1.01
	 double* MultiLevelHpEnemi;
	//--------------------PowerUp---------------------------
	//wybierane przez gracza przy levelowaniu w mieœcie
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

