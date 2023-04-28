//
// Created by Radu on 4/28/2023.
//

#include "Fotbalist.h"
#include "Persoana.h"
#include "exceptii.h"
#include <random>
#include <iostream>
using namespace std;
string Fotbalist::getRole(){
    return role;
}
void Fotbalist::setEchipa(const string echipa_){
    echipa=echipa_;
}
void Fotbalist::setRole(const string role_){
    role=firstLetter(role_);
}
std::istream& operator>>(std::istream &is, Fotbalist& rhs){
    is>>static_cast<Persoana&>(rhs);
    if(rhs.getvarsta()<16 || rhs.getvarsta()>45){
        throw exceptiiPersoane(rhs.getnume(),16,45,true);
    }
    string role,echipa;
    cout<<"Rol (Pozitie):";
    cin>>role;
    rhs.setBall(false);
    rhs.setRole(role);
    rhs.setCartonase(0);
    return is;
}



void Fotbalist::showPersoana() {
    Persoana::showPersoana();
    cout<<" "<<role<<" "<<echipa<<" ";
}

Fotbalist::Fotbalist(){
    role=echipa="";
    hasBall=0;
    cartonase=0;
}
Fotbalist::Fotbalist(const string& role,const string echipa,const bool hasBall,const ConcretePersoana& p):Persoana(p){
    if(p.getvarsta()<16 || p.getvarsta()>45){
        throw exceptiiPersoane(p.getnume(),16,45,true);
    }
    this->role=role;
    this->echipa=echipa;
    this->hasBall=hasBall;
    this->cartonase=0;
}
string Fotbalist::getEchipa(){
    return echipa;
}
short Fotbalist::getCartonase(){
    return cartonase;
}
void Fotbalist::setCartonase(const short cartonase_){
    this->cartonase=cartonase_;
}
void Fotbalist::setBall(const bool stare){
    this->hasBall=stare;
}
int Fotbalist::takeDecision() {
    if(!hasBall)
        return -1;
    if(this->role=="Atacant")
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);

        int random_num = distr(gen);
        if (random_num<4)
            return 1;
    }
    return 0;
}