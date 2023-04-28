//
// Created by Radu on 4/28/2023.
//

#include "Arbitru.h"
#include "Persoana.h"
#include "exceptii.h"
#include <random>
#include <iostream>
using namespace std;
string Arbitru::getPosition(){
    return position;
}
void Arbitru::setPosition(string position_){
    position=position_;
}
void Arbitru::setStrict(bool strictete){
    isStrict=strictete;
}
std::istream& operator>>(std::istream &is, Arbitru& rhs) {
    is >> static_cast<Persoana&>(rhs);
    if (rhs.getvarsta() < 16 || rhs.getvarsta() > 45) {
        throw exceptiiPersoane(rhs.getnume(), 16, 45, true);
    }
    string pozitie;
    bool isStrict;
    cout << "Rol (Pozitie):";
    cin >> pozitie;
    cout << "Este strict?";
    cin >> isStrict;
    rhs.setPosition(pozitie);
    rhs.setStrict(isStrict);
    return is;
}
Arbitru::Arbitru(){
    position="";
    isStrict=false;
}
Arbitru::Arbitru(const string& position,const bool isStrict,const ConcretePersoana &p):Persoana(p){
    if(p.getvarsta()<16 || p.getvarsta()>55){
        throw exceptiiPersoane(p.getnume(),16,55,true);
    }
    this->position=position;
    this->isStrict=isStrict;
}

int Arbitru::takeDecision()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);
    int random_num = distr(gen);
    if(this->isStrict){
        if (random_num<5)
            return 1;
    }
    else{
        if(random_num<3)
            return 1;
    }
    return 0;
}

void Arbitru::showPersoana() {
    Persoana::showPersoana();
    cout<<" "<<position<<" "<<isStrict;
}