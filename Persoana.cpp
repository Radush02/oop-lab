//
// Created by Radu on 4/24/2023.
//

#include "Persoana.h"

#include <iostream>
#include <random>
#include "exceptii.h"
string firstLetter(string k){
    k[0]=toupper(k[0]);
    for(int i=1;i<(int)k.length();i++){
        k[i]=tolower(k[i]);
    }
    return k;
}
Persoana::Persoana(){
    nume="";
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
void Persoana::setvarsta(const int varsta_){
    varsta=varsta_;
}
void Persoana::setWeight(const float weight_) {
    weight=weight_;
}
void Persoana::setHeight(const float height_){
    height=height_;
}

std::istream& operator>>(std::istream &is,Persoana &rhs){
    string nume;
    int varsta;
    float weight,height;
    cout<<"Nume:";
    cin>>nume;
    cout<<"Varsta:";
    cin>>varsta;
    cout<<"Greutate:";
    cin>>weight;
    cout<<"Inaltime:";
    cin>>height;
    rhs.setnume(nume);
    rhs.setvarsta(varsta);
    rhs.setHeight(height);
    rhs.setWeight(weight);
    if(varsta<13 || varsta>80){
        throw exceptiiPersoane(rhs.nume,13,80,false);
    }
    if(weight>100 || height>2.2 || weight<42 || height<1.5){
        throw exceptiiPersoane(nume,height,weight);
    }
    if(weight/(height*height)>25 || weight/(height*height)<18.5){
        throw exceptiiPersoane(nume,height/(weight*weight));
    }
    return is;
}
string Fotbalist::getRole(){
    return role;
}
string Arbitru::getPosition(){
    return position;
}
std::istream& operator>>(std::istream &is, ConcretePersoana& rhs){
    is>>static_cast<Persoana&>(rhs);
    return is;
}
void Fotbalist::setEchipa(string echipa_){
    echipa=echipa_;
}
void Fotbalist::setRole(string role_){
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
}

int ConcretePersoana::takeDecision() {
    return 0;
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
void Fotbalist::setBall(bool stare){
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
const ConcretePersoana& ConcretePersoana::getPersoana() const {
    return static_cast<const ConcretePersoana&>(*this);
}
const Persoana& Persoana::getPersoana() const {
    return static_cast<const Persoana&>(*this);
}
bool Persoana::operator ==(const Persoana &rhs) const{
    return nume==rhs.nume && varsta==rhs.varsta && height==rhs.height && weight==rhs.weight;
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

