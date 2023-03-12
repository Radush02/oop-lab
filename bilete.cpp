//
// Created by Radu on 3/5/2023.
//

#include "bilete.h"
#include <cstring>
#include <iostream>
#include <regex>
/**
class partida{
private:
    char *data,*gazda,*oaspeti;
 */


///partida
partida::partida(){
    data=nullptr;
    gazda=nullptr;
    oaspeti=nullptr;
}
partida::partida(const char *date,const char *home, const char *away){
    data=new char[strlen(date)+1];
    gazda=new char[strlen(home)+1];
    oaspeti=new char[strlen(away)+1];
    strcpy(data,date);
    strcpy(gazda,home);
    strcpy(oaspeti,away);
}

char* partida::getDate() const{
    return data;
}
char* partida::getHome() const{
    return gazda;
}
char* partida::getAway() const{
    return oaspeti;
}
partida::partida(const partida &game){
    data=new char[strlen(game.data)+1];
    gazda=new char[strlen(game.gazda)+1];
    oaspeti=new char[strlen(game.oaspeti)+1];
    strcpy(data,game.data);
    strcpy(gazda,game.gazda);
    strcpy(oaspeti,game.oaspeti);
}
partida& partida::operator=(const partida &rhs){
    if (&rhs!=this){
        setDate(rhs.data);
        setHome(rhs.gazda);
        setAway(rhs.oaspeti);
    }
    return *this;
}
void partida::setDate(const char* date){
    if(date==nullptr || date[0]=='\0'){
        delete[] data;
        data=nullptr;
    }
    else{
        delete[] data;
        data=new char[strlen(date)+1];
        strcpy(data,date);
    }
}

void partida::setHome(const char* home){
    if (home == nullptr || home[0] == '\0') {
        delete[] gazda;
        gazda = nullptr;
    } else {
        delete[] gazda;
        gazda = new char[strlen(home) + 1];
        strcpy(gazda, home);
    }
}
void partida::setAway(const char* away){
    if(away == nullptr || away[0]=='\0'){
        delete[] oaspeti;
        oaspeti=nullptr;
    }
    else{
        delete[] oaspeti;
        oaspeti=new char[strlen(away)+1];
        strcpy(oaspeti,away);
    }
}

bool partida::operator==(const partida &rhs) const{
    return (strcmp(data,rhs.data)==0) && (strcmp(oaspeti,rhs.oaspeti)==0) && (strcmp(gazda,rhs.gazda)==0);
}

bool partida::operator!=(const partida &rhs) const{
    return strcmp(data,rhs.data)!=0 || strcmp(oaspeti,rhs.oaspeti)!=0 || strcmp(gazda,rhs.gazda)!=0;
}
partida::~partida(){
    delete[] gazda;
    delete[] oaspeti;
    delete[] data;
}
std::ostream& operator<<(std::ostream &os,const partida &rhs){
    os<<"Data: "<<rhs.data<<" Echipa gazda: "<<rhs.gazda<<" Echipa oaspete: "<<rhs.oaspeti;
    return os;
}

std::istream& operator>>(std::istream &is,partida &rhs){
    std::cout<<"Data meciului:";
    start:
    char data_[50];
    is.getline(data_,50);
    std::regex format("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-]\\d{4}$");
    if(!std::regex_search(data_,format)){
        std::cout<<"Data trebuie sa fie de forma dd/mm/yyyy sau sa fie o data valida.\n";
        goto start;
    }
    std::cout<<"Echipa gazda:";
    char gazda_[100],oaspete_[100];
    is.getline(gazda_,100);
    std::cout<<"Echipa oaspete:";
    is.getline(oaspete_,100);
    rhs.setHome(gazda_);
    rhs.setAway(oaspete_);
    rhs.setDate(data_);
    return is;
}

///bilete
/**
class bilete {
private:
    partida match;
    char *tip_bilet;
    int pret,loc;
*/
bilete::bilete() : match(){
    tip_bilet=nullptr;
    pret=0;
    loc=0;
}
bilete::bilete(const char *ticket_type, int pret_, int loc_,const partida &m){
    tip_bilet=new char[strlen(ticket_type)+1];
    strcpy(tip_bilet,ticket_type);
    pret=pret_;
    loc=loc_;
    match=m;
}

bilete::bilete(const bilete &ticket){
    tip_bilet=new char[strlen(ticket.tip_bilet)+1];
    strcpy(tip_bilet,ticket.tip_bilet);
    pret=ticket.pret;
    loc=ticket.loc;
    match=ticket.match;
}
bilete& bilete::operator=(const bilete &rhs){
    if(this!=&rhs){
        setMatch(rhs.match);
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
    return match;
}
int bilete::getSeat() const{
    return loc;
}
char* bilete::getType() const{
    return tip_bilet;
}

void bilete::setPrice(const int price){
    pret=price;
}
void bilete::setMatch(const partida &m){
    match=m;
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
    return pret!=rhs.pret || match!=rhs.match || loc!=rhs.loc || strcmp(tip_bilet,rhs.tip_bilet)!=0;
}
bool bilete::operator ==(const bilete &rhs) const{
    return pret==rhs.pret && match==rhs.match && loc==rhs.loc && strcmp(tip_bilet,rhs.tip_bilet)==0;
}
bilete::~bilete(){
    delete[] tip_bilet;
}
std::ostream& operator<<(std::ostream &os,const bilete &rhs){
    os<<"Tip Bilet: "<<rhs.tip_bilet<<", Pret: "<<rhs.pret<<" RON, Loc: "<<rhs.loc<<"\nMeci:"<<rhs.match<<"\n";
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
    buy_ticket:
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
    {
        std::cout<<"Tip de bilet invalid!\nBilete valide si preturile: "
                  "Peluza Nord - 30 RON, Peluza Sud - 30 RON, Tribuna II - 50 RON, Tribuna I - 60 RON, "
                  "Tribuna 0 - 100 RON, VIP - 300 RON\n"<<aux;
        goto buy_ticket;
    }
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