//
// Created by Radu on 3/5/2023.
//

#include "bilete.h"
#include <cstring>
#include <iostream>
/**
class partida{
private:
    char *data,*gazda,*oaspeti;
 */


///partida
partida::partida(const char *date,const char *home, const char *away){
    data=new char[strlen(date)];
    gazda=new char[strlen(home)];
    oaspeti=new char[strlen(away)];
    strcpy(data,date);
    strcpy(gazda,home);
    strcpy(oaspeti,away);
}

char* partida::getDate(){
    return data;
}
char* partida::getHome(){
    return gazda;
}
char* partida::getAway(){
    return oaspeti;
}
partida::partida(const partida &game){
    data=new char[strlen(game.data)];
    gazda=new char[strlen(game.gazda)];
    oaspeti=new char[strlen(game.oaspeti)];
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
void partida::setDate(char* date){
    delete[] data;
    data=new char[strlen(date)];
    strcpy(data,date);
}

void partida::setHome(char* home){
    delete[] gazda;
    gazda=new char[strlen(home)];
    strcpy(gazda,home);
}
void partida::setAway(char* away){
    delete[] oaspeti;
    oaspeti=new char[strlen(away)];
    strcpy(oaspeti,away);
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
///bilete
/**
class bilete {
private:
    partida match;
    char *tip_bilet;
    int pret,loc;
 */
bilete::bilete(const char *ticket_type, int pret_, int loc_,const partida &m) : match(m) {
    tip_bilet=new char[strlen(ticket_type)];
    strcpy(tip_bilet,ticket_type);
    pret=pret_;
    loc=loc_;
}

    bilete::bilete(const bilete &ticket,const partida &m) : match(m) {
    tip_bilet=new char[strlen(ticket.tip_bilet)];
    strcpy(tip_bilet,ticket.tip_bilet);
    pret=ticket.pret;
    loc=ticket.loc;
    match=m;
}
int bilete::getPrice() const{
    return pret;
}
partida bilete::getMatch()const{
    return match;
}
int bilete::getSeat() const{
    return loc;
}
char* bilete::getType() const{
    return tip_bilet;
}

void bilete::setPrice(int price){
    pret=price;
}
void bilete::setMatch(const partida &m){
    match=m;
}
void bilete::setSeat(int seat){
    loc=seat;
}
void bilete::setType(char* type){
    delete[] tip_bilet;
    tip_bilet=new char[strlen(type)];
    strcpy(tip_bilet,type);
}
bool bilete::operator !=(const bilete &rhs) const{
    return pret!=rhs.pret || match!=rhs.match || loc!=rhs.loc || strcmp(tip_bilet,rhs.tip_bilet)!=0;
}
bool bilete::operator ==(const bilete &rhs) const{
    return pret==rhs.pret && match==rhs.match && loc==rhs.loc && strcmp(tip_bilet,rhs.tip_bilet)==0;
}
bilete::~bilete(){
    delete[] tip_bilet;
    match.~partida();
}
std::ostream& operator<<(std::ostream &os,const bilete &rhs){
    os<<"Tip Bilet: "<<rhs.tip_bilet<<", Pret: "<<rhs.pret<<" RON, Loc: "<<rhs.loc<<"\nMeci:\n"<<rhs.match<<"\n";
    return os;
}