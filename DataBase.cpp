#include "DataBase.h"
#include <fstream>
#include <string>
#include<cmath>

using namespace std;

DataBase::DataBase(bool show)
{
    if (show) {
        cout << "DATABASE" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||" << endl;
    }
    //-------------Player_Start-----------------
Gracz: {
    if (show) {
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^GRACZ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }
    //ile postaci
    try {
        ifstream plik;
        plik.open("Data/player/C.txt", ios::out);
        string s;
        char* r = new char[5];
        plik.getline(r, 5);
        s.assign(r);
        plik.close();
        CharacterCount = s[0] - 48;
        delete[]r;

    }
    catch (...) {
        cout << endl << "z³y plik" << endl;
    }
    //show
    if (show) {
        cout << "-----------------" << endl;
        cout << "Data / player / C.txt" << " success" << endl;
        cout << "C = " << CharacterCount << endl;
        cout << "-----------------" << endl;
    }

    CharacterName = new string[CharacterCount];
    //nazwy
    try {

        ifstream plik;
        plik.open("Data/player/Names.txt", ios::out);
        string s;
        char* r = new char[100];
        for (int i = 0; i < CharacterCount; i++) {

            plik.getline(r, 100);
            s.assign(r);


            CharacterName[i] = s;
        }
        plik.close();
        delete[]r;

    }
    catch (...) {
        cout << endl << "z³y plik" << endl;

    }
    //show
    if (show) {
        cout << "-----------------" << endl;
        cout << "Data/player/Names.txt" << " success" << endl;
        for (int i = 0; i < CharacterCount; i++) {
            cout << "Name[" << i << "]=" << CharacterName[i] << endl;
        }
        cout << "-----------------" << endl;
    }

    //teraz ka¿d¹ klasê z osobna
    //-------------------------BASA-player--------------------------
    BaseVitality = new int[CharacterCount];
    BaseArrmor = new int[CharacterCount];
    BaseDng = new int[CharacterCount];
    //-------------Special-player-----------------
    SpecialAbility = new double[CharacterCount];
    //--------------Multi-level-player--------------
    MultiLevelHp = new double[CharacterCount];
    for (int i = 0; i < CharacterCount; i++) {

        try {

            ifstream plik;
            plik.open("Data/player/" + CharacterName[i] + "/Stat.txt", ios::out);
            string s;
            char* r = new char[5];

            plik.getline(r, 5);
            s.assign(r);
            BaseVitality[i] = stoi(s);

            plik.getline(r, 5);
            s.assign(r);
            BaseArrmor[i] = stoi(s);

            plik.getline(r, 5);
            s.assign(r);
            BaseDng[i] = stoi(s);

            plik.getline(r, 5);
            s.assign(r);
            SpecialAbility[i] = (double)stoi(s) * 1.00;

            plik.getline(r, 5);
            s.assign(r);
            MultiLevelHp[i] = (double)stoi(s) / 100;
            delete[]r;

            plik.close();

        }
        catch (...) {
            cout << endl << "z³y plik" << endl;
        }
    }

    //show
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < CharacterCount; i++) {
            cout << "Data/player/" + CharacterName[i] + ".txt" << " success" << endl;
        }

        for (int i = 0; i < CharacterCount; i++) {
            cout << "*************" << endl;
            cout << CharacterName[i] << endl;
            cout << "Vitality: " << BaseVitality[i] << endl;
            cout << "Arrmor: " << BaseArrmor[i] << endl;
            cout << "Dng: " << BaseDng[i] << endl;
            cout << "SpecialAbility: " << SpecialAbility[i] << endl;
            cout << "MultiLevelHp: " << MultiLevelHp[i] << endl;
            cout << "*************" << endl;
        }
        cout << "-----------------" << endl;
    }


    //jeszcze nazwy ataków

    AttackCount = new int[CharacterCount];
    for (int i = 0; i < CharacterCount; i++) {
        try {

            ifstream plik;
            plik.open("Data/player/" + CharacterName[i] + "/CAttack.txt", ios::out);

            string s;
            char* r = new char[5];

            plik.getline(r, 5);
            s.assign(r);
            AttackCount[i] = stoi(s);
            delete[]r;


            plik.close();
        }
        catch (...) {
            cout << endl << "z³y plik" << endl;
        }


    }
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < CharacterCount; i++) {

                cout << "Data/player/" + CharacterName[i] + "/CAttack.txt" << " success" << endl;
            
        }

        for (int i = 0; i < CharacterCount; i++) {
            cout << CharacterName[i] << ": "<<AttackCount[i] << endl;
            
        }
        cout << "-----------------" << endl;
    }
    
    
     //ataki nazwy i wartoœci
    AttackNames = new string * [CharacterCount];
    AttackChance = new double* [CharacterCount];
    AttackMulti = new double* [CharacterCount];
    for (int j = 0; j < CharacterCount; j++) {


            AttackNames[j] = new string[AttackCount[j]];
            AttackChance[j] = new double[AttackCount[j]];
            AttackMulti[j]= new double[AttackCount[j]];


    }


    for (int i = 0; i < CharacterCount; i++) {

            try {

                ifstream plik;
                plik.open("Data/player/" + CharacterName[i] +  "/Attack.txt", ios::out);

                string s;

                for (int k = 0; k < AttackCount[i]; k++) {
                    char* r = new char[20];
                    plik.getline(r, 20);
                    s.assign(r);
                    AttackNames[i][k] = s;

                    plik.getline(r, 20);
                    s.assign(r);
                    AttackChance[i][k] = (double)stoi(s) / 100;

                    plik.getline(r, 20);
                    s.assign(r);
                    AttackMulti[i][k] = (double)stoi(s) / 100;

                    delete[]r;
                }




                plik.close();
            }
            catch (...) {
                cout << endl << "z³y plik" << endl;
            }
        

    }
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < CharacterCount; i++) {

                cout << "Data/player/" + CharacterName[i] + "/Atack.txt" << " success" << endl;
            
        }

        for (int i = 0; i < CharacterCount; i++) {
            cout << CharacterName[i] << ":" << endl;
                for (int k = 0; k < AttackCount[i]; k++) {

                    cout << "\t\t-" << AttackNames[i][k] << endl;

                    cout << "\t\t-Szansa: " << AttackChance[i][k] << endl;


                    cout << "\t\t-Mnoznik: " << AttackMulti[i][k] << endl;

                }
            
            cout << endl;
        }
        cout << "-----------------" << endl;
    }




        PowerUpVitality=0;
        PowerUpDng=0;
        PowerUpArrmor=0;
      


    if (show) {
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^GRACZ-Koniec^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }
}
    //--------------------Player-END----------------------------

    //----------------------ENEMI-Start----------------------
Enemi: {
    //--------------------Count and Names-------------------------
    if (show) {
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^ENEMI^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }
    //ile archetypów
    try {
        ifstream plik;
        plik.open("Data/enemi/C.txt", ios::out);
        string s;
        char* r = new char[5];
        plik.getline(r, 5);
        s.assign(r);
        plik.close();
        ArchetypeCount= s[0] - 48;
        delete[]r;

    }
    catch (...) {
        cout << endl << "z³y plik" << endl;
    }
    //show
    if (show) {
        cout << "-----------------" << endl;
        cout << "Data / enemi / C.txt" << " success" << endl;
        cout << "C = " << ArchetypeCount << endl;
        cout << "-----------------" << endl;
    }



    NamesArchetypeEnemi = new string[ArchetypeCount];
    //nazwy archetypów
    try {

        ifstream plik;
        plik.open("Data/enemi/EnemiArchetype.txt", ios::out);
        string s;
        char* r = new char[100];
        for (int i = 0; i < ArchetypeCount; i++) {

            plik.getline(r, 100);
            s.assign(r);


            NamesArchetypeEnemi[i] = s;
        }
        plik.close();
        delete[]r;

    }
    catch (...) {
        cout << endl << "z³y plik" << endl;

    }
    //show
    if (show) {
        cout << "-----------------" << endl;
        cout << "Data/enemi/EnemiArchetype.txt" << " success" << endl;
        for (int i = 0; i < ArchetypeCount; i++) {
            cout << "NamesArchetypeEnemi[" << i << "]=" << NamesArchetypeEnemi[i] << endl;
        }
        cout << "-----------------" << endl;
    }

    NamesEnemiCount = new int[ArchetypeCount];
    //ile nazw przeciwników
    for (int i = 0; i < ArchetypeCount; i++) {

        try {

            ifstream plik;
            plik.open("Data/enemi/" + NamesArchetypeEnemi[i] + "/C.txt", ios::out);
            string s;
            char* r = new char[5];

            plik.getline(r, 5);
            s.assign(r);
            NamesEnemiCount[i] = stoi(s);
            delete[]r;

            plik.close();

        }
        catch (...) {
            cout << endl << "z³y plik" << endl;
        }
    }
    //show
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < ArchetypeCount; i++) {
            cout << "Data/enemi/"+NamesArchetypeEnemi[i]+"/C.txt" << " success" << endl;
        }
      
        for (int i = 0; i < ArchetypeCount; i++) {
            cout << NamesArchetypeEnemi[i] <<": "<<NamesEnemiCount[i]<< endl;
        }
        cout << "-----------------" << endl;
    }

    NamesEnemi = new string * [ArchetypeCount];
    for (int i = 0; i < ArchetypeCount; i++) {
        NamesEnemi[i] = new string[NamesEnemiCount[i]];
    }

    for (int i = 0; i < ArchetypeCount; i++) {
        ifstream plik;
        plik.open("Data/enemi/" + NamesArchetypeEnemi[i] + "/Names.txt", ios::out);
        for (int j = 0; j < NamesEnemiCount[i]; j++) {
            try {

                
               
                string s;
                char* r = new char[20];

                plik.getline(r, 20);
                s.assign(r);
                NamesEnemi[i][j] = s;
                delete[]r;

                

            }
            catch (...) {
                cout << endl << "z³y plik" << endl;
            }
        }
        plik.close();
    }

    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < ArchetypeCount; i++) {
            cout << "Data/enemi/" + NamesArchetypeEnemi[i] + "/Names.txt" << " success" << endl;
        }

        for (int i = 0; i < ArchetypeCount; i++) {
            cout << NamesArchetypeEnemi[i]<<": "<<endl;
            for (int j = 0; j < NamesEnemiCount[i]; j++) {
                cout << "- " << NamesEnemi[i][j] << endl;
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }

    //--------------------BASE-Enemi--------------------------------

    BaseEnemiVitality = new int[ArchetypeCount];
    BaseEnemiArrmor = new int[ArchetypeCount];
    BaseEnemiDng = new int[ArchetypeCount];
    //--------------Multi-level-Enemi--------------
    MultiLevelHpEnemi = new double[ArchetypeCount];

    for (int i = 0; i < ArchetypeCount; i++) {

        
        try {
            ifstream plik;
            plik.open("Data/enemi/" + NamesArchetypeEnemi[i] + "/Stats.txt", ios::out);
            string s;
            char* r = new char[5];

            plik.getline(r, 5);
            s.assign(r);
            BaseEnemiVitality[i] = stoi(s);

            plik.getline(r, 5);
            s.assign(r);
            BaseEnemiArrmor[i] = stoi(s);

            plik.getline(r, 5);
            s.assign(r);
            BaseEnemiDng[i] = stoi(s);


            plik.getline(r, 5);
            s.assign(r);
            MultiLevelHpEnemi[i] = (double)stoi(s) / 100;
            delete[]r;

            plik.close();

        }
        catch (...) {
            cout << endl << "z³y plik" << endl;
        }
    }

    //show
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < ArchetypeCount; i++) {
            cout << "Data/enemi/" + NamesArchetypeEnemi[i] + "/Stat.txt" << " success" << endl;
        }

        for (int i = 0; i < ArchetypeCount; i++) {
            cout << "*************" << endl;
            cout << NamesArchetypeEnemi[i] << endl;
            cout << "Vitality: " << BaseEnemiVitality[i] << endl;
            cout << "Arrmor: " << BaseEnemiArrmor[i] << endl;
            cout << "Dng: " << BaseEnemiDng[i] << endl;
            cout << "MultiLevelHp: " << MultiLevelHpEnemi[i] << endl;
            cout << "*************" << endl;
        }
        cout << "-----------------" << endl;
    }

    //Ataki
    //ile ataków
    AttackEnemiCount = new int* [ArchetypeCount];
    for (int j = 0; j < ArchetypeCount; j++) {


        
            AttackEnemiCount[j] = new int[NamesEnemiCount[j]];
        
    }
    
    for (int i = 0; i < ArchetypeCount; i++) {

        for (int j = 0; j < NamesEnemiCount[i]; j++) {
            try {

                ifstream plik;
                plik.open("Data/enemi/" + NamesArchetypeEnemi[i] + "/" + NamesEnemi[i][j] + "/CAttack.txt", ios::out);

                string s;
                char* r = new char[5];

                plik.getline(r, 5);
                s.assign(r);
                AttackEnemiCount[i][j] = stoi(s);
                delete[]r;


                plik.close();
            }
            catch (...) {
                cout << endl << "z³y plik" << endl;
            }
        }
       
    }
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < ArchetypeCount; i++) {

            for (int j = 0; j < NamesEnemiCount[i]; j++) {
                cout << "Data/enemi/" + NamesArchetypeEnemi[i] + "/" + NamesEnemi[i][j] + "/CAttack.txt" << " success" << endl;
            }
            for (int i = 0; i < ArchetypeCount; i++) {

                for (int j = 0; j < NamesEnemiCount[i]; j++) {
                    cout << "archetyp " << i << " przeciwnik " << j << " liczba ataków " << AttackEnemiCount[i][j] << endl;
                }
            }
        }

        for (int i = 0; i < ArchetypeCount; i++) {
            cout << NamesArchetypeEnemi[i] << ":" << endl;
            for (int j = 0; j < NamesEnemiCount[i]; j++) {
                
                cout << "-" << NamesEnemi[i][j] << " " << AttackEnemiCount[i][j]<<endl;
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }
    //ataki nazwy i wartoœci
    AttackEnemiNames = new string** [ArchetypeCount];
    AttackEnemiChance =new double**[ArchetypeCount];
    AttackEnemiMulti = new double**[ArchetypeCount];
    for (int j = 0; j < ArchetypeCount; j++) {



        AttackEnemiNames[j] = new string*[NamesEnemiCount[j]];
        AttackEnemiChance[j] = new double* [NamesEnemiCount[j]];
        AttackEnemiMulti[j] = new double* [NamesEnemiCount[j]];
        for (int i = 0; i < NamesEnemiCount[j]; i++) {
            AttackEnemiNames[j][i] = new string[AttackEnemiCount[j][i]];
            AttackEnemiChance[j][i] = new double[AttackEnemiCount[j][i]];
            AttackEnemiMulti[j][i] = new double[AttackEnemiCount[j][i]];
        }

    }


    for (int i = 0; i < ArchetypeCount; i++) {

        for (int j = 0; j < NamesEnemiCount[i]; j++) {
            try {

                ifstream plik;
                plik.open("Data/enemi/" + NamesArchetypeEnemi[i] + "/" + NamesEnemi[i][j] + "/Atack.txt", ios::out);

                string s;
                
                for (int k = 0; k < AttackEnemiCount[i][j]; k++) {
                    char* r = new char[20];
                    plik.getline(r, 20);
                    s.assign(r);
                    AttackEnemiNames[i][j][k] = s;

                    plik.getline(r, 20);
                    s.assign(r);
                    AttackEnemiChance[i][j][k] = (double)stoi(s)/100;

                    plik.getline(r, 20);
                    s.assign(r);
                    AttackEnemiMulti[i][j][k] = (double)stoi(s) / 100;

                    delete[]r;
                }
                
               


                plik.close();
            }
            catch (...) {
                cout << endl << "z³y plik" << endl;
            }
        }

    }
    if (show) {
        cout << "-----------------" << endl;
        for (int i = 0; i < ArchetypeCount; i++) {

            for (int j = 0; j < NamesEnemiCount[i]; j++) {
                cout << "Data/enemi/" + NamesArchetypeEnemi[i] + "/" + NamesEnemi[i][j] + "/Atack.txt" << " success" << endl;
            }
        }

        for (int i = 0; i < ArchetypeCount; i++) {
            cout << NamesArchetypeEnemi[i] << ":" << endl;
            for (int j = 0; j < NamesEnemiCount[i]; j++) {
                cout << "\t" << NamesEnemi[i][j]<<endl;
                for (int k = 0; k < AttackEnemiCount[i][j]; k++) {

                    cout<<"\t\t-"<<AttackEnemiNames[i][j][k] << endl;

                    cout << "\t\t-Szansa: " << AttackEnemiChance[i][j][k] << endl;

      
                    cout << "\t\t-Mnoznik: " << AttackEnemiMulti[i][j][k] << endl;

                }
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }









    //---------------------------------------koenic enemi-------------------------------------------
    if (show) {
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^ENEMI-Koniec^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }


  
}
//--------------------------------------------MAPA----------------------------------------------

Mapa: {
if (show) {
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^MAPA^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

try {
    ifstream plik;
    plik.open("Data/Map/C.txt", ios::out);
    string s;
    char* r = new char[5];
    plik.getline(r, 5);
    s.assign(r);
    plik.close();
    NamesLocationCount = stoi(s);
    delete[]r;

}
catch (...) {
    cout << endl << "z³y plik" << endl;
}
//show
if (show) {
    cout << "-----------------" << endl;
    cout << "Data / Map / C.txt" << " success" << endl;
    cout << "C = " << NamesLocationCount << endl;
    cout << "-----------------" << endl;
}

NamesLocation = new string[NamesLocationCount];
//nazwy
try {

    ifstream plik;
    plik.open("Data/Map/Names.txt", ios::out);
    string s;
    char* r = new char[100];
    for (int i = 0; i < NamesLocationCount; i++) {

        plik.getline(r, 100);
        s.assign(r);


        NamesLocation[i] = s;
    }
    plik.close();
    delete[]r;

}
catch (...) {
    cout << endl << "z³y plik" << endl;

}
//show
if (show) {
    cout << "-----------------" << endl;
    cout << "Data/Map/Names.txt" << " success" << endl;
    for (int i = 0; i < NamesLocationCount; i++) {
        cout << "Name[" << i << "]=" << NamesLocation[i] << endl;
    }
    cout << "-----------------" << endl;
}




if (show) {
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^END-MAPA^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
}
//--------------------------------------------END-MAPA----------------------------------------------

//ca³a baza suche dane

if (show) {
    cout << "-------------------------------" << endl;
    //gracz
    cout << "CharacterCount = " << CharacterCount<<endl;
    for (int i = 0; i < CharacterCount; i++) {
        cout << "\tCharakterNames" << "[" << i << "]" << " = " << CharacterName[i] << endl;
        cout << "\tBaseVitality" << "[" << i << "]" << " = " << BaseVitality[i] << endl;

        cout << "\tBaseArrmor" << "[" << i << "]" << " = " << BaseArrmor[i] << endl;

        cout << "\tBaseDng" << "[" << i << "]" << " = " << BaseDng[i] << endl;
        cout << "\tSpecialAbility" << "[" << i << "]" << " = " << SpecialAbility[i] << endl;
        cout << "\tMultiLevelHp" << "[" << i << "]" << " = " << MultiLevelHp[i] << endl;
        cout << "\tataki:" << endl;
        cout << "\tAttackCount" << "[" << i << "]" << " = " << AttackCount[i] << endl;
        for (int j = 0; j < AttackCount[i]; j++) {
            cout << "\t\tAttackNames" << "[" << i << "]" << "[" << j << "]" << " = " << AttackNames[i][j] << endl;
            cout << "\t\tAttackChance" << "[" << i << "]" << "[" << j << "]" << " = " << AttackChance[i][j] << endl;
            cout << "\t\tAttackMulti" << "[" << i << "]" << "[" << j << "]" << " = " << AttackMulti[i][j] << endl;
            cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
        }
        cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
    }
    //przeciwnicy

    cout << "-------------------------------" << endl;
    cout << "ArchetypeCount = " << ArchetypeCount << endl;
    for (int i = 0; i < ArchetypeCount; i++) {
        cout << "\tNamesEnemiCount" << "[" << i << "]" << " = " << NamesEnemiCount[i] << endl;
        cout << "\tNamesArchetypeEnemi" << "[" << i << "]" << " = " << NamesArchetypeEnemi[i] << endl;
        cout << "\tBaseEnemiVitality" << "[" << i << "]" << " = " << BaseEnemiVitality[i] << endl;
        cout << "\tBaseEnemiArrmor" << "[" << i << "]" << " = " << BaseEnemiArrmor[i] << endl;
        cout << "\tBaseEnemiDng" << "[" << i << "]" << " = " << BaseEnemiDng[i] << endl;
        for (int j = 0; j < NamesEnemiCount[i]; j++) {
            cout << "\t\tNamesEnemi" << "[" << i << "]" << "[" << j << "]" << " = " << NamesEnemi[i][j] << endl;
            cout << "\t\tataki" << endl;
            cout << "\t\tAttackEnemiCount " << "[" << i << "]" << "[" << j << "]" << " = " << AttackEnemiCount[i][j] << endl;
            for (int k = 0; k < AttackEnemiCount[i][j]; k++) {
                cout << "\t\t\tAttackEnemiNames" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << AttackEnemiNames[i][j][k] << endl;
                cout << "\t\t\tAttackEnemiChance" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << AttackEnemiChance[i][j][k] << endl;
                cout << "\t\t\tAttackEnemiMulti" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << AttackEnemiMulti[i][j][k] << endl;
                cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
            }
            cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
        }
        //mapa
        
    }
    cout << "-------------------------------" << endl;
    cout << "NamesLocationCount = " << NamesLocationCount << endl;
    for (int i = 0; i < NamesLocationCount; i++) {
        cout << "\tNamesLocation" << "[" << i << "]" << " = " << NamesLocation[i] << endl;
    }
    cout << "-------------------------------" << endl;
}


    if (show) {
        cout << "|||||||||||||||||||||||||||||||||||||||" << endl;
    }

}

DataBase::~DataBase()
{
    delete[]CharacterName;
    delete[]BaseVitality;
    delete[]BaseArrmor;
    delete[]BaseDng;
    delete[]SpecialAbility;
    delete[]MultiLevelHp;
    delete[]AttackCount;


    delete[]NamesArchetypeEnemi;

    for (int j = 0; j < CharacterCount; j++) {


        delete[]AttackNames[j];
        delete[]AttackChance[j];
        delete[]AttackMulti[j];


    }

    delete[]AttackNames ;
    delete[]AttackChance;
    delete[]AttackMulti;
    
    for (int i = 0; i < ArchetypeCount; i++) {
        delete[]NamesEnemi[i];
    }
    delete[]NamesEnemi ;
    delete[]NamesEnemiCount;


    delete[]BaseEnemiVitality;
    delete[]BaseEnemiArrmor ;
    delete[]BaseEnemiDng;

    delete[]MultiLevelHpEnemi;

    for (int j = 0; j < ArchetypeCount; j++) {
        delete[]AttackEnemiCount[j];
    }
    delete[]AttackEnemiCount;

   
    for (int j = 0; j < ArchetypeCount; j++) {



        delete[]AttackEnemiNames[j] ;
        delete[]AttackEnemiChance[j];
        delete[]AttackEnemiMulti[j];
        for (int i = 0; i < NamesEnemiCount[j]; i++) {
            delete[]AttackEnemiNames[j][i];
            delete[]AttackEnemiChance[j][i];
            delete[]AttackEnemiMulti[j][i];
        }

    }

    delete[]AttackEnemiNames ;
    delete[]AttackEnemiChance;
    delete[]AttackEnemiMulti;


    delete[] NamesLocation;
}

int DataBase::GetBaseVitality(int id)
{
	return BaseVitality[id];
}

int DataBase::GetBaseEnemiVitalit(int arch)
{
	return BaseEnemiVitality[arch];
}
double DataBase::GetBaseArrmor(int id)
{
    return   BaseArrmor[id];    // (log10(BaseArrmor[id])/log10(10000));
}
double DataBase::GetBaseEnemiArrmor(int arch)
{
    return BaseEnemiArrmor[arch];//(log10(BaseEnemiArrmor[arch]) / log10(10000));
}
int DataBase::GetBaseDng(int id)
{
    return BaseDng[id];
}
int DataBase::GetBaseEnemiDng(int arch)
{
    return BaseEnemiDng[arch];
}
string DataBase::GetNamesArchetypeEnem(int arch)
{
    return NamesArchetypeEnemi[arch];
}
string DataBase::GetNamesEnemi(int arch, int level)
{
    return NamesEnemi[arch][level];
}
int DataBase::GetNamesArchetypeEnemCount()
{
    return ArchetypeCount;
}
int DataBase::GetNamesEnemiCount(int arch)
{
    return NamesEnemiCount[arch];
}
int DataBase::GetAttackEnemiCount(int arch, int level)
{
    return AttackEnemiCount[arch][level];
}
string DataBase::GetAttackEnemiNames(int arch, int level, int idName)
{
    return AttackEnemiNames[arch][level][idName];
}
string DataBase::GetAttackNames(int id,int idName)
{
    return AttackNames[id][idName];
}
double DataBase::GetAttackEnemiChance(int arch, int level, int idName)
{
    return AttackEnemiChance[arch][level][idName];
}
double DataBase::GetAttackChance(int id, int idName)
{
    return AttackChance[id][idName];
}
double DataBase::GetAttackEnemiMulti(int arch, int level, int idName)
{
    return AttackEnemiMulti[arch][level][idName];
}
double DataBase::GetAttackMulti(int id, int idName)
{
    return AttackMulti[id][idName];
}
double DataBase::GetSpecialAbility(int id)
{
    return SpecialAbility[id];
}
double DataBase::GetMultiLevelHp(int id)
{
    return MultiLevelHp[id];
}
double DataBase::GetMultiLevelHpEnemi(int arch)
{
    return MultiLevelHpEnemi[arch];
}
int DataBase::GetPowerUpVitality( )
{
    return PowerUpVitality ;
}
int DataBase::GetPowerUpDng( )
{
    return PowerUpDng ;
}
int DataBase::GetPowerUpArrmor( )
{
    return PowerUpArrmor ;
}
void DataBase::SetPowerUpVitality(  int value)
{
    PowerUpVitality  = value;
}
void DataBase::SetPowerUpDng(  int value)
{
    PowerUpDng  = value;
}
void DataBase::SetPowerUpArrmor(  int value)
{
    PowerUpArrmor  = value;
}
void DataBase::SetPlusPowerUpVitality(  int plus)
{
    PowerUpVitality  += plus;
}
void DataBase::SetPlusPowerUpDng(  int plus)
{
    PowerUpDng  += plus;
}
void DataBase::SetPlusPowerUpArrmor(  int plus)
{
    PowerUpArrmor  += plus;
}

string DataBase::GetNameLocation(int i)
{
    if(i>=0||i<NamesLocationCount)
    return NamesLocation[i];
    return " ";
}

int DataBase::GetNamesLocationCount()
{
    return NamesLocationCount;
}

string DataBase::GetCharacterName(int i)
{
    return CharacterName[i];
}

int DataBase::GetCharacterNameConut()
{
    return CharacterCount;
}

int DataBase::GetAttackCount(int id)
{
    return AttackCount[id];
}

void DataBase::Show_DATABASE()
{
    cout << "-------------------------------" << endl;
    //gracz
    cout << "CharacterCount = " << CharacterCount << endl;
    for (int i = 0; i < CharacterCount; i++) {
        cout << "\tCharakterNames" << "[" << i << "]" << " = " << CharacterName[i] << endl;
        cout << "\tBaseVitality" << "[" << i << "]" << " = " << BaseVitality[i] << endl;

        cout << "\tBaseArrmor" << "[" << i << "]" << " = " << BaseArrmor[i] << endl;

        cout << "\tBaseDng" << "[" << i << "]" << " = " << BaseDng[i] << endl;
        cout << "\tSpecialAbility" << "[" << i << "]" << " = " << SpecialAbility[i] << endl;
        cout << "\tMultiLevelHp" << "[" << i << "]" << " = " << MultiLevelHp[i] << endl;
        cout << "\tataki:" << endl;
        cout << "\tAttackCount" << "[" << i << "]" << " = " << AttackCount[i] << endl;
        for (int j = 0; j < AttackCount[i]; j++) {
            cout << "\t\tAttackNames" << "[" << i << "]" << "[" << j << "]" << " = " << AttackNames[i][j] << endl;
            cout << "\t\tAttackChance" << "[" << i << "]" << "[" << j << "]" << " = " << AttackChance[i][j] << endl;
            cout << "\t\tAttackMulti" << "[" << i << "]" << "[" << j << "]" << " = " << AttackMulti[i][j] << endl;
            cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
        }
        cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
    }
    //przeciwnicy

    cout << "-------------------------------" << endl;
    cout << "ArchetypeCount = " << ArchetypeCount << endl;
    for (int i = 0; i < ArchetypeCount; i++) {
        cout << "\tNamesEnemiCount" << "[" << i << "]" << " = " << NamesEnemiCount[i] << endl;
        cout << "\tNamesArchetypeEnemi" << "[" << i << "]" << " = " << NamesArchetypeEnemi[i] << endl;
        cout << "\tBaseEnemiVitality" << "[" << i << "]" << " = " << BaseEnemiVitality[i] << endl;
        cout << "\tBaseEnemiArrmor" << "[" << i << "]" << " = " << BaseEnemiArrmor[i] << endl;
        cout << "\tBaseEnemiDng" << "[" << i << "]" << " = " << BaseEnemiDng[i] << endl;
        for (int j = 0; j < NamesEnemiCount[i]; j++) {
            cout << "\t\tNamesEnemi" << "[" << i << "]" << "[" << j << "]" << " = " << NamesEnemi[i][j] << endl;
            cout << "\t\tataki" << endl;
            cout << "\t\tAttackEnemiCount " << "[" << i << "]" << "[" << j << "]" << " = " << AttackEnemiCount[i][j] << endl;
            for (int k = 0; k < AttackEnemiCount[i][j]; k++) {
                cout << "\t\t\tAttackEnemiNames" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << AttackEnemiNames[i][j][k] << endl;
                cout << "\t\t\tAttackEnemiChance" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << AttackEnemiChance[i][j][k] << endl;
                cout << "\t\t\tAttackEnemiMulti" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << AttackEnemiMulti[i][j][k] << endl;
                cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
            }
            cout << ",,,,,,,,,,,,,,,,,,,,,,," << endl;
        }
        //mapa

    }
    cout << "-------------------------------" << endl;
    cout << "NamesLocationCount = " << NamesLocationCount << endl;
    for (int i = 0; i < NamesLocationCount; i++) {
        cout << "\tNamesLocation" << "[" << i << "]" << " = " << NamesLocation[i] << endl;
    }
    cout << "-------------------------------" << endl;
}

DataBase DATABASE = DataBase(0);