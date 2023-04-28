#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include "bilete.h"
#include "meci.h"
#include "Persoana.h"
#include "exceptii.h"
#include <map>
#include "Arbitru.h"
#include "Fotbalist.h"
/*
 * Cordunianu Radu - Gr 133
 */
using namespace std;
int nrRandom(int mn,int mx){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(mn, mx);
    return  distr(gen);
}

Fotbalist genereazaFotbalist(const string rol,const string echipa){
    vector<string> prenume={"Florinel","Bahoi","Daniel","Marcus","Kylian","Lionel","Neymar","Dan","Aurel","Cristiano","Teodor","Radu","Alexandru","Mihai"};
    vector<string> nume = {"Popescu", "Ionescu", "Dragomir", "Stoica", "Dumitru", "Munteanu", "Vasilescu", "Radulescu", "Marinescu", "Constantin", "Tanase", "Preda", "Chiriac", "Tudorache"};
    int varsta=nrRandom(16,40);
    float inaltime=(float)nrRandom(160,200)/100;
    float greutate=inaltime*inaltime*(float)nrRandom(180,290)/10;
    return Fotbalist(rol,echipa,false,ConcretePersoana(prenume[nrRandom(0,13)]+" "+nume[nrRandom(0,13)],varsta,inaltime,greutate));
    ///Fotbalist("Mijlocas","Rapid Brodoc",false,ConcretePersoana("Frenkie de Jong",21,1.64,74.4)));

}
int decideScor(vector<shared_ptr<Persoana>> const p, unique_ptr<Arbitru> &ref){
    int rezultat,scor=0;
    vector<string> motiveVAR {"jucatorul se afla in poztie neregulamentara.","a fost hent.","jucatorul a comis un fault in constructia atacului."};
    vector<string> motiveCartonase {"jucatorul a comis un fault.","arbitrul nu putut trece cu vederea atacul facut de jucator","a comis un hent","a adresat injurii altor jucatori","nu si-a pastrat cumpatul cu privire la suporteri"};
    for(auto& x:p)
    {
        Fotbalist* aux = dynamic_cast<Fotbalist*>(x.get());
        if(aux)
        {
            bool minge=false;
            int nrRand=nrRandom(1,3);
            for(int i=0;i<nrRand;i++)
            {
                if(aux->getCartonase()>1)
                    break;
                aux->setBall(nrRand%3==0 && minge==false?false:true);
                rezultat=aux->takeDecision();
                if(rezultat==1)
                {
                    cout << "Gol " << aux->getnume() << "\n";
                    if (ref->getPosition()=="VAR")
                        if(ref->takeDecision()==1)
                        {
                            scor--;
                            cout<<"Gol anulat de VAR deoarece "+motiveVAR[nrRandom(0,2)]+"\n";
                        }
                    scor++;
                }
                if(rezultat==0){
                    if(ref->getPosition()!="VAR")
                        if(ref->takeDecision()==1)
                        {
                            aux->setCartonase(aux->getCartonase()+1);
                            cout<<aux->getnume()+" a primit un cartonas galben deoarece "+motiveCartonase[nrRandom(0,4)]+"\n";
                            if(aux->getCartonase()==2)
                                cout<<aux->getnume()+" a fost eliminat si nu va mai putea juca decat la urmatoarea etapa!\n";
                        }
                }
                else if(rezultat==-1)
                    minge=true;
            }
            aux->setCartonase(0);
        }
    }
    return scor;
}
int getNrRol(vector<shared_ptr<Fotbalist>> f,const string rol){
    string aux=firstLetter(rol);
    int roluri=0;
    for(auto &x:f){
        if(x->getRole()==aux)
            roluri++;
    }
    return roluri;
}
int bilete::balanta=400;
int main() {
    ConcretePersoana p;

    vector<shared_ptr<Persoana>> echipaJucator;
    int nrAtacanti=0;
    string echipa;
    try{
        cout<<"Bine ai venit, noule patron! "
              "Pentru inceput, vrem sa stim cateva delatii despre tine.\n";
        cin>>p;
    }
    catch(exceptiiPersoane &e){
        cout<<e.what();
        return 0;
    }

    int nr_meciuri = 5, nr_bilete = 2;
    vector<partida> meciuri {
            partida("10/03/2023", "Univ. Craiova", "CS Mioveni"),
            partida("11/03/2023", "FC Arges", "Petrolul Ploiesti"),
            partida(),
            partida("12/03/2023", "FC Hermannstadt", "U Craiova 1948"),
            partida("12/03/2023", "FCSB", "Sepsi Sf. Gheorghe")
    };
    meciuri[2].setDate("11/03/2023");
    meciuri[2].setHome("Farul Constanta");
    meciuri[2].setAway("Rapid Bucuresti");
    map<string,vector<shared_ptr<Fotbalist>>> lotEchipe;
    for(const auto &x:meciuri){
        for(int i=0;i<3;i++)
        {
            if(getNrRol(lotEchipe[x.getHome()],"Atacant")<=3)
                lotEchipe[x.getHome()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Atacant",x.getHome())));
            if(getNrRol(lotEchipe[x.getAway()],"Atacant")<=3)
                lotEchipe[x.getAway()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Atacant",x.getAway())));
        }
        for(int i=0;i<2;i++)
        {
            if(getNrRol(lotEchipe[x.getHome()],"Mijlocas")<=2)
                lotEchipe[x.getHome()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Mijlocas",x.getHome())));
            if(getNrRol(lotEchipe[x.getAway()],"Mijlocas")<=2)
                lotEchipe[x.getAway()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Mijlocas",x.getAway())));
        }
    }
    vector<bilete> vandute {
            bilete("VIP", 300, 15, meciuri[0]),
            bilete("Peluza Nord", 30, 26, meciuri[1])
    };
    vector<Arbitru> arbitri={
            Arbitru("VAR",true,ConcretePersoana("Pierluigi Collina",50,1.68,64.6)),
            Arbitru("Central",false,ConcretePersoana("Howard Webb",48,1.91,91.2)),
            Arbitru("Tusier",false,ConcretePersoana("Markus Merk",42,1.84,85.5)),
            Arbitru("Tusier",false,ConcretePersoana("Milorad Mazic",48,1.85,82.5))
    };
    int n;
    start:
    cout << "Bine ati venit pe Arena Nationala. Momentan se vor juca " << nr_meciuri << " meciuri si s-au vandut "<<nr_bilete<<" bilete!\n";
    cout<< "Ce doriti sa faceti?"
           "\n1)Vinde un bilet\n"
           "2)Lista de meciuri\n"
           "3)Bilete vandute\n"
           "4)Adauga un nou meci\n"
           "5)Joaca un amical\n"
           "6)Vezi un meci\n"
           "7)Angajeaza arbitru\n"
           "8)Verificati banii obtinuti din biletele vandute.\n";
    cin >> n;
    cin.get();
    switch (n) {
        case 1: {
            bool gasit = false;
            nr_bilete++;
            bilete aux;
            cin >> aux;
            for (int i = 0; i < nr_meciuri; i++)
                if (aux.getMatch() == meciuri[i]) { //testat operator de egalitate
                    gasit = true;
                    break;
                }
            if (!gasit) {
                cout << "Meciul nu a fost gasit! Nu am putut achizitona biletul!\n";
                nr_bilete--;
                break;
            }
            vandute.push_back(aux);
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
            partida aux;
            try {
                cin >> aux;
            }
            catch(exceptiiMeci &e){
                cout<<e.what();
                break;
            }
            nr_meciuri++;
            meciuri.push_back(aux);
            cout<<"Meci adaugat! "<<meciuri[nr_meciuri-1]<<"\n";
            for(int i=0;i<3;i++)
            {
                if(getNrRol(lotEchipe[aux.getHome()],"Atacant")<=3)
                    lotEchipe[aux.getHome()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Atacant",aux.getHome())));
                if(getNrRol(lotEchipe[aux.getAway()],"Atacant")<=3)
                    lotEchipe[aux.getAway()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Atacant",aux.getAway())));
            }
            for(int i=0;i<2;i++)
            {
                if(getNrRol(lotEchipe[aux.getHome()],"Mijlocas")<=2)
                    lotEchipe[aux.getHome()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Mijlocas",aux.getHome())));
                if(getNrRol(lotEchipe[aux.getAway()],"Mijlocas")<=2)
                    lotEchipe[aux.getAway()].emplace_back(make_shared<Fotbalist>(genereazaFotbalist("Mijlocas",aux.getAway())));
            }
            break;
        }
        case 5:
        {
            if(nrAtacanti<3 && echipaJucator.size()<10){
                cout<<"Se pare ca nu ai o echipa, sau ai membri lipsa! Regulile sunt putin diferite"
                      "Nu esti obligat sa ai 10 membri in echipa, ci fie 3 atacanti fie 10 membri."
                      "Dar pentru sanse mai mari de castig, recomandam sa aveti 10 membri.\nPentru inceput, cum se numeste echipa ta?\n";
                getline(cin,echipa);
            }
            while(nrAtacanti<3 && echipaJucator.size()<10){
                try{
                    Fotbalist aux;
                    cin>>aux;
                    cin.get();
                    aux.setEchipa(echipa);
                    echipaJucator.push_back(make_shared<Fotbalist>(aux));
                    if(aux.getRole()=="Atacant")
                        nrAtacanti++;
                }
                catch(exceptiiPersoane &e){
                    cout<<e.what();
                    cin.get();
                }
            }
            vector<shared_ptr<Persoana>> onField;
            auto& fotbalisti = lotEchipe[meciuri[nrRandom(0,meciuri.size()-1)].getHome()];
            for (auto& f : fotbalisti)
                onField.emplace_back(f);
            cout<<"Se va disputa meciul intre "+echipa+" si "+dynamic_cast<Fotbalist*>(onField[0].get())->getEchipa()+"\n";

            unique_ptr<Arbitru> ref=make_unique<Arbitru>("Central",true,ConcretePersoana("Pierluigi Collina",50,1.68,64.6));

            int scorGazda=decideScor(echipaJucator,ref);
            int scorOaspeti=decideScor(onField,ref);
            cout<<echipa+" - " + dynamic_cast<Fotbalist*>(onField[0].get())->getEchipa()+"\n"+ to_string(scorGazda)+" - "+
                  to_string(scorOaspeti);
            onField.clear();
            break;
        }
        case 6:
        {
            int numar;
            cout<<"Alegeti meci: \n";
            for(int i=0;i<nr_meciuri;i++)
                cout<<i+1<<") "<<meciuri[i]<<"\n"; //operator <<
            cin>>numar;
            if(numar>nr_meciuri)
            {
                cout << "Nu exista acel meci! ";
                break;
            }
            vector<shared_ptr<Persoana>> Gazda,Oaspeti;
            auto& fotbalisti = lotEchipe[meciuri[numar-1].getHome()];
            for (auto& f : fotbalisti)
                Gazda.emplace_back(f);
            fotbalisti = lotEchipe[meciuri[numar-1].getAway()];
            for (auto& f : fotbalisti)
                Oaspeti.emplace_back(f);
            cout<<"Se va disputa meciul intre "+dynamic_cast<Fotbalist*>(Gazda[0].get())->getEchipa()+" si "+dynamic_cast<Fotbalist*>(Oaspeti[0].get())->getEchipa()+"\n";

            unique_ptr<Arbitru> ref=make_unique<Arbitru>(arbitri[nrRandom(0,arbitri.size())]);
            cout<<"Arbitrul acestui meci este: "<<ref->getnume()<<"\n";

            int scorGazda=decideScor(Gazda,ref);
            int scorOaspeti=decideScor(Oaspeti,ref);
            cout<<dynamic_cast<Fotbalist*>(Gazda[0].get())->getEchipa()+" - " + dynamic_cast<Fotbalist*>(Oaspeti[0].get())->getEchipa()+"\n"+ to_string(scorGazda)+" - "+
                  to_string(scorOaspeti);
            Gazda.clear();
            Oaspeti.clear();
            break;
        }
        case 7:
        {
            Arbitru arb;
            cin>>arb;
            arbitri.push_back(arb);
            arbitri[arbitri.size()-1].showPersoana();
            break;
        }
        case 8:
        {
            cout<<bilete::getBalanta();
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


     echipaJucator.clear();
     lotEchipe.clear();
    return 0;
}




