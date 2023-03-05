//
// Created by Radu on 3/5/2023.
//

#ifndef OOP_BILETE_H
#define OOP_BILETE_H


class partida{
private:
    char *data,*gazda,*oaspeti;
public:
    partida(const char *date, const char *home, const char *away);
    char* getDate();
    char* getHome();
    char* getAway();
};

class bilete {
private:
    partida match;
    char *tip_bilet,*id;
    int pret,loc;
public:
    bilete(const char *ticket_type, int pret, int loc, partida match);
    bilete(const bilete &ticket);
    int getPrice();
    partida getMatch();
};

#endif //OOP_BILETE_H
