#include <iostream>
#include "bilete.h"
/*
 * Cordunianu Radu - Gr 133
 */
using namespace std;
char* toUpper(char *x){
    for(char* c=x; (*c=toupper(*c)); ++c)
        ;
    return x;
}
int main() {
    int nr_meciuri = 5, nr_bilete = 0;
    partida *meciuri = new partida[nr_meciuri];
    meciuri[0] = partida("10/03/2023", "Univ. Craiova", "CS Mioveni"); //constructor & operator de atribuire
    meciuri[1] = partida("11/03/2023", "FC Arges", "Petrolul Ploiesti");
    meciuri[2].setDate("11/03/2023"); //testat setteri
    meciuri[2].setHome("Farul Constanta"); //testat setteri
    meciuri[2].setAway("Rapid Bucuresti"); //testat setteri
    meciuri[3] = partida("12/03/2023", "FC Hermannstadt", "U Craiova 1948");
    meciuri[4] = partida("12/03/2023", "FCSB", "Sepsi Sf. Gheorghe");
    bilete *vandute = new bilete[nr_bilete];
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
            bilete *aux = new bilete[nr_bilete];
            for (int i = 0; i < nr_bilete - 1; i++)
                aux[i] = vandute[i];
            cin >> aux[nr_bilete - 1]; //override operator >>
            for (int i = 0; i < nr_meciuri; i++)
                if (aux[nr_bilete - 1].getMatch() == meciuri[i]) { //testat operator de egalitate
                    gasit = true;
                    break;
                }
            if (!gasit) {
                cout << "Meciul nu a fost gasit! Nu am putut achizitona biletul!";
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
            cout<<"Doriti sa vedeti toate meciurile, sau doar echipele gazda?\n1)Toate meciurile\n2)Echipele gazda";
            cin>>n;
            cin.get();
            if(n==1)
                for(int i=0;i<nr_meciuri;i++)
                    cout<<meciuri[i]<<"\n"; //operator <<
            else if(n==2)
                for(int i=0;i<nr_meciuri;i++)
                    cout<<meciuri[i].getAway()<<"\n"; //testat getteri
            else
                cout<<"Renuntam la vizualizare";
            break;
        }
        case 3:{
            for(int i=0;i<nr_bilete;i++)
                cout<<vandute[i]<<"\n";
            break;
        }
        case 4:{
            nr_meciuri++;
            partida *aux = new partida[nr_meciuri];
            for(int i=0;i<nr_meciuri-1;i++)
                aux[i]=meciuri[i];
            cin>>aux[nr_meciuri-1];
            delete[] meciuri;
            meciuri=aux;
            cout<<"Meci adaugat!"<<meciuri[nr_meciuri-1]<<"\n";
            break;
        }
        default:
        {
            cout<<"Va mai asteptam!";
            return 0;
        }
    }
    cout<<"Doriti sa continuati?\n1)Da\n2)Nu\n";
    cin>>n;
    if(n==1)
        goto start;
    cout<<"Va mai asteptam!";
    return 0;
}