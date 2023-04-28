//
// Created by Radu on 4/24/2023.
//

#include "meci.h"
#include <iostream>
#include <cstring>
#include <regex>
#include "exceptii.h"
partida::partida() : data(new char[1]), gazda(new char[1]), oaspeti(new char[1]) {
    data[0] = '\0';
    gazda[0] = '\0';
    oaspeti[0] = '\0';
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
void partida::setPartida(const partida &game){
    delete[] data;
    delete[] gazda;
    delete[] oaspeti;
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
    char data_[50];
    is.getline(data_,50);
    std::regex format("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-]\\d{4}$");
    if(!std::regex_search(data_,format))
        throw exceptiiMeci(data_);
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