//
// Created by Radu on 4/24/2023.
//

#include "Persoana.h"

#include <iostream>
#include <random>
#include "exceptii.h"
#include "bilete.h"

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
    getline(cin,nume);
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


std::istream& operator>>(std::istream &is, ConcretePersoana& rhs){
    is>>static_cast<Persoana&>(rhs);
    return is;
}
int ConcretePersoana::takeDecision() {
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


