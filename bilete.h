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
    partida& operator=(const partida &rhs);
    bool operator==(const partida &rhs) const;
    bool operator!=(const partida &rhs) const;
    char* getDate();
    char* getHome();
    char* getAway();
    void setDate(char* date);
    void setHome(char* home);
    void setAway(char* away);
    friend std::ostream& operator<<(std::ostream &os,const partida &rhs);
    ~partida();
};

class bilete {
private:
    partida match;
    char *tip_bilet;
    int pret,loc;
public:
    bilete(const char *ticket_type, int pret, int loc,const partida &m);
    bilete(const bilete &ticket,const partida &m);
    int getPrice() const;
    int getSeat() const;
    char* getType() const;
    partida getMatch() const;
    void setPrice(int price);
    void setSeat(int seat);
    void setType(char* type);
    void setMatch(const partida &m);
    bool operator !=(const bilete &rhs) const;
    bool operator ==(const bilete &rhs) const;
    friend std::ostream& operator<<(std::ostream &os,const bilete &s);
    ~bilete();
};

#endif //OOP_BILETE_H
