//
// Created by Radu on 3/5/2023.
//

#ifndef OOP_BILETE_H
#define OOP_BILETE_H
#include <iostream>

class partida{
private:
    char *data,*gazda,*oaspeti;
public:
    partida(const char *date, const char *home, const char *away);
    partida(const partida &game);
    partida();
    partida& operator=(const partida &rhs);
    bool operator==(const partida &rhs) const;
    bool operator!=(const partida &rhs) const;
    char* getDate() const;
    char* getHome() const;
    char* getAway() const;
    void setDate(const char* date);
    void setHome(const char* home);
    void setAway(const char* away);
    friend std::ostream& operator<<(std::ostream &os,const partida &rhs);
    friend std::istream& operator>>(std::istream &is,partida &rhs);
    ~partida();
};

class bilete {
private:
    partida match;
    char *tip_bilet;
    int pret,loc;
public:
    bilete();
    bilete(const char *ticket_type, int pret, int loc,const partida &m);
    bilete(const bilete &ticket);
    bilete& operator=(const bilete &rhs);
    int getPrice() const;
    int getSeat() const;
    char* getType() const;
    partida getMatch() const;
    void setPrice(const int price);
    void setSeat(const int seat);
    void setType(const char* type);
    void setMatch(const partida &m);
    bool operator !=(const bilete &rhs) const;
    bool operator ==(const bilete &rhs) const;
    friend std::ostream& operator<<(std::ostream &os,const bilete &rhs);
    friend std::istream& operator>>(std::istream &is,bilete &rhs);
    ~bilete();
};

#endif //OOP_BILETE_H
