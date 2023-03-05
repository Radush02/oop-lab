//
// Created by Radu on 3/5/2023.
//

#include "bilete.h"
#include <cstring>
/**
class bilete {
private:
    char *tip_bilet;
    int pret,loc;
class partida{
private:
    char *data,*gazda,*oaspeti;
 */
partida::partida(const char *date,const char *home, const char *away){
    data=new char[strlen(date)];
    gazda=new char[strlen(home)];
    oaspeti=new char[strlen(away)];
    strcpy(data,date);
    strcpy(gazda,home);
    strcpy(oaspeti,away);
}

bilete::bilete(const char *ticket_type, int pret_, int loc_, partida match) : match(match) {
    tip_bilet=new char[strlen(ticket_type)];
    strcpy(tip_bilet,ticket_type);
    pret=pret_;
    loc=loc_;
}
char* partida::getDate(){
    return this->data;
}
char* partida::getHome(){
    return this->gazda;
}
char* partida::getAway(){
    return this->oaspeti;
}
int bilete::getPrice(){
    return this->pret;
}
partida bilete::getMatch(){
    return this->match;
}