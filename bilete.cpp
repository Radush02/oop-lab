//
// Created by Radu on 3/5/2023.
//

#include "bilete.h"
#include <cstring>
#include <iostream>
#include <regex>
#include "exceptii.h"
bilete::bilete():tip_bilet(new char[1]){
    tip_bilet[0]='\0';
    pret=0;
    loc=0;
}
bilete::bilete(const char *ticket_type, int pret_, int loc_,const partida &m) : partida(m){
    tip_bilet=new char[strlen(ticket_type)+1];
    strcpy(tip_bilet,ticket_type);
    pret=pret_;
    balanta+=pret_;
    loc=loc_;
}
void bilete::updateBalanta(int valoareBilet){
    balanta+=valoareBilet;
}
int bilete::getBalanta(){
    return balanta;
}
bilete::bilete(const bilete &ticket):partida(ticket){
    tip_bilet=new char[strlen(ticket.tip_bilet)+1];
    strcpy(tip_bilet,ticket.tip_bilet);
    pret=ticket.pret;
    loc=ticket.loc;
}
bilete& bilete::operator=(const bilete &rhs){
    if(this!=&rhs){
        partida::operator=(rhs);
        setType(rhs.tip_bilet);
        pret=rhs.pret;
        loc=rhs.loc;
    }
    return *this;
}
int bilete::getPrice() const{
    return pret;
}
partida bilete::getMatch() const{
    return partida(this->getDate(),this->getHome(),this->getAway());
}
int bilete::getSeat() const{
    return loc;
}
const char* bilete::getType() const{
    return tip_bilet;
}

void bilete::setPrice(const int price){
    balanta+=price;
    pret=price;
}
void bilete::setMatch(const partida &m){
    setPartida(m);
}
void bilete::setSeat(const int seat){
    loc=seat;
}
void bilete::setType(const char* type) {
    if(type==nullptr || type[0]=='\0'){
        delete[] tip_bilet;
        tip_bilet=nullptr;
    }
    else{
        delete[] tip_bilet;
        tip_bilet=new char[strlen(type)+1];
        strcpy(tip_bilet,type);
    }
}
bool bilete::operator !=(const bilete &rhs) const{
    return pret!=rhs.pret || partida(this->getDate(),this->getHome(),this->getAway())!=partida(rhs.getDate(),rhs.getHome(),rhs.getAway()) || loc!=rhs.loc || strcmp(tip_bilet,rhs.tip_bilet)!=0;
}
bool bilete::operator ==(const bilete &rhs) const{
    return pret==rhs.pret && partida(this->getDate(),this->getHome(),this->getAway())==partida(rhs.getDate(),rhs.getHome(),rhs.getAway()) && loc==rhs.loc && strcmp(tip_bilet,rhs.tip_bilet)==0;
}
bilete::~bilete() {
    delete[] tip_bilet;
}
std::ostream& operator<<(std::ostream &os,const bilete &rhs){
    os<<"Tip Bilet: "<<rhs.tip_bilet<<", Pret: "<<rhs.pret<<" RON, Loc: "<<rhs.loc<<"\nMeci:"<<partida(rhs.getDate(),rhs.getHome(),rhs.getAway())<<"\n";
    return os;
}
void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}
std::istream& operator>>(std::istream &is, bilete &rhs){
    char tip_bilet_[100];
    int loc_;
    partida meci_;
    std::cout<<"Tipul de bilet:";
    std::cin.getline(tip_bilet_,100);
    char *aux=new char[sizeof(tip_bilet_)+1];
    strcpy(aux,tip_bilet_);
    toUpperCase(aux);
    if(strcmp(aux,"PELUZA NORD")==0 || strcmp(aux,"PELUZA SUD")==0)
        rhs.setPrice(30);

    else if(strcmp(aux,"TRIBUNA II")==0)
        rhs.setPrice(50);

    else if(strcmp(aux,"TRIBUNA I")==0)
        rhs.setPrice(60);

    else if(strcmp(aux,"TRIBUNA 0")==0)
        rhs.setPrice(100);

    else if(strcmp(aux,"VIP")==0)
        rhs.setPrice(300);
    else
        throw exceptiiVanzare();
    rhs.setType(tip_bilet_);
    std::cout<<"Locul dorit (0-99)";
    std::cin>>loc_;
    std::cin.get();
    rhs.setSeat(loc_%100);
    std::cin>>meci_;
    rhs.setMatch(meci_);
    delete[] aux;
    return is;
}