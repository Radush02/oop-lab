//
// Created by Radu on 4/24/2023.
//

#include "Persoana.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include "exceptii.h"
Persoana::Persoana(){
    nume=nullptr;
    varsta=height=weight=0;
}
const string& Persoana::getnume() const{
    return nume;
}
Persoana::~Persoana(){

}
Persoana::Persoana(const string& nume,const int varsta,const float height,const float weight){
    if(varsta<13 || varsta>80){
        throw exceptiiPersoane(nume,13,80,false);
    }
    this->nume=nume;
    this->varsta=varsta;
    this->weight=weight;
    this->height=height;
}
Persoana::Persoana(const Persoana& rhs){
    if(rhs.getvarsta()<13 || rhs.getvarsta()>80){
        throw exceptiiPersoane(rhs.nume,13,80,false);
    }
    this->nume=rhs.nume;
    this->varsta=rhs.varsta;
    this->weight=rhs.weight;
    this->height=rhs.height;
}
ConcretePersoana::ConcretePersoana():Persoana() {}

ConcretePersoana::ConcretePersoana(const string& nume, const int varsta, const float height, const float weight) : Persoana(nume, varsta, height, weight) {}

int Persoana::getvarsta() const{
    return varsta;
}
void Persoana::showPersoana(){
    cout<<nume<<" "<<varsta<<" "<<height<<" "<<weight;
}
void Persoana::setnume(const string& nume_){
    nume=nume_;
}
std::istream& operator>>(std::istream &is,ConcretePersoana &rhs){
    string nume;
    int varsta;
    float weight,height;
    cout<<"Nume: ";
    cin>>nume;
    return is;
    cout<<"Varsta: ";
    cin>>varsta;
    cout<<"Greutate: ";
    cin>>weight;
    cout<<"Inaltime: ";
    cin>>height;
    rhs.setnume(nume);
    return is;
}
void Fotbalist::showPersoana() {
    Persoana::showPersoana();
    cout<<" "<<role<<" "<<goluri<<" "<<hasBall<<"\n";
}

Fotbalist::Fotbalist(){
    role=nullptr;
    goluri=hasBall=0;
}

int ConcretePersoana::takeDecision() {
    return 0;
}
Fotbalist::Fotbalist(const string& role,const int goluri,const bool hasBall,const ConcretePersoana& p):Persoana(p){
    if(p.getvarsta()<16 || p.getvarsta()>45){
        throw exceptiiPersoane(p.getnume(),16,45,true);
    }
        this->role=role;
        this->goluri=goluri;
        this->hasBall=hasBall;
        this->cartonase=0;
}


int Fotbalist::takeDecision() {
    if(!hasBall)
        return 0;
    if(this->role=="Atacant")
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);

        int random_num = distr(gen);
        if (random_num<3)
            return 1;
    }
    return 0;
}

Arbitru::Arbitru(){
    position=nullptr;
    isStrict=false;
}
Arbitru::Arbitru(const string& position,const bool isStrict,const ConcretePersoana &p):Persoana(p){
    if(p.getvarsta()<16 || p.getvarsta()>55){
        throw exceptiiPersoane(p.getnume(),16,55,true);
    }
    this->position=position;
    this->isStrict=isStrict;
};

int Arbitru::takeDecision()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);
    int random_num = distr(gen);
    if(position=="VAR")
        random_num--;

    if(this->isStrict==true){
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