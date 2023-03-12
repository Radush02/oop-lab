#include <iostream>
#include "bilete.h"
/*
 * Cordunianu Radu - Gr 133
 */
using namespace std;
int main() {
    int nr_meciuri = 5, nr_bilete = 2;
    auto *meciuri = new partida[nr_meciuri];
    meciuri[0] = partida("10/03/2023", "Univ. Craiova", "CS Mioveni"); //constructor & operator de atribuire
    meciuri[1] = partida("11/03/2023", "FC Arges", "Petrolul Ploiesti");
    meciuri[2].setDate("11/03/2023"); //testat setteri
    meciuri[2].setHome("Farul Constanta"); //testat setteri
    meciuri[2].setAway("Rapid Bucuresti"); //testat setteri
    meciuri[3] = partida("12/03/2023", "FC Hermannstadt", "U Craiova 1948");
    meciuri[4] = partida("12/03/2023", "FCSB", "Sepsi Sf. Gheorghe");
    auto *vandute = new bilete[nr_bilete];
    vandute[0]=bilete("VIP",300,15,meciuri[0]);
    vandute[1]=bilete("Peluza Nord",30,26,meciuri[1]);
    int n;
    start:
    cout << "Bine ati venit pe Arena Nationala. Momentan se vor juca " << nr_meciuri << " meciuri si s-au vandut "<<nr_bilete<<" bilete!\n";
    cout<< "Doriti sa cumparati un bilet, sa vedeti lista de meciuri sau biletele deja vandute sau sa adaugati o noua disputa?\n1)Cumpara bilet\n2)Lista de meciuri\n3)Bilete vandute\n4)Adauga un nou meci\n";
    cin >> n;
    cin.get();
    switch (n) {
        case 1: {
            bool gasit = false;
            nr_bilete++;
            auto *aux = new bilete[nr_bilete];
            for (int i = 0; i < nr_bilete - 1; i++)
                aux[i] = vandute[i];
            cin >> aux[nr_bilete - 1]; //override operator >>
            for (int i = 0; i < nr_meciuri; i++)
                if (aux[nr_bilete - 1].getMatch() == meciuri[i]) { //testat operator de egalitate
                    gasit = true;
                    break;
                }
            if (!gasit) {
                cout << "Meciul nu a fost gasit! Nu am putut achizitona biletul!\n";
                delete[] aux;
                nr_bilete--;
                break;
            }
            delete[] vandute; //apelat destructor
            vandute = aux;
            cout<<"Bilet achizitionat!\n"<<vandute[nr_bilete-1]<<"\n";
            break;
        }
        case 2: {
            cout<<"Doriti sa vedeti toate meciurile, doar echipele gazda, doar cele oaspete sau datele la care se vor juca?\n1)Toate meciurile\n2)Echipele gazda\n3)Datele\n4)Oaspetii\n";
            cin>>n;
            cin.get();
            if(n==1)
                for(int i=0;i<nr_meciuri;i++)
                    cout<<meciuri[i]<<"\n"; //operator <<
            else if(n==2)
                for(int i=0;i<nr_meciuri;i++)
                    cout<<meciuri[i].getHome()<<"\n"; //testat getteri
            else if(n==3)
                for(int i=0;i<nr_meciuri;i++)
                    cout<<meciuri[i].getDate()<<"\n";
            else if(n==4)
                for(int i=0;i<nr_meciuri;i++)
                    cout<<meciuri[i].getAway()<<"\n";
            else
                cout<<"Renuntam la vizualizare.\n";
            break;
        }
        case 3:{
            cout<<"Doriti sa vedeti toate biletele, doar locurile ocupate la toate meciurile sau preturile la care s-au vandut biletele?"
                  "\n1)Locurile vandute\n2)Toate biletele\n3)Preturile\n";
            cin>>n;
            cin.get();
            if(n==2)
            for(int i=0;i<nr_bilete;i++)
                cout<<vandute[i]<<"\n";
            else if(n==1)
                for(int i=0;i<nr_bilete;i++)
                    cout<<"Loc: "<<vandute[i].getSeat()<<" Tip: "<<vandute[i].getType()<<" Meci: "<<vandute[i].getMatch()<<"\n";
            else if(n==3)
                for(int i=0;i<nr_bilete;i++)
                    cout<<"Tip: "<<vandute[i].getType()<<" Pret: "<<vandute[i].getPrice()<<"\n";
            break;
        }
        case 4:{
            nr_meciuri++;
            auto *aux = new partida[nr_meciuri];
            for(int i=0;i<nr_meciuri-1;i++)
                aux[i]=meciuri[i];
            cin>>aux[nr_meciuri-1];
            delete[] meciuri;
            meciuri=aux;
            cout<<"Meci adaugat! "<<meciuri[nr_meciuri-1]<<"\n";
            break;
        }
        default:
        {
            cout<<"Va mai asteptam!\n";
            return 0;
        }
    }
    cout<<"Doriti sa continuati?\n1)Da\n2)Nu\n";
    cin>>n;
    if(n==1)
        goto start;
    cout<<"Va mai asteptam!\n";
    delete[] meciuri;
    delete[] vandute;
    return 0;
}