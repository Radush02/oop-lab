//
// Created by Radu on 4/24/2023.
//

#ifndef OOP_MECI_H
#define OOP_MECI_H
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
    virtual ~partida();
    void setPartida(const partida &game);
};

#endif //OOP_MECI_H
