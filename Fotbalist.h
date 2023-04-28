//
// Created by Radu on 4/28/2023.
//

#ifndef OOP_FOTBALIST_H
#define OOP_FOTBALIST_H
#include "Persoana.h"

class Fotbalist : virtual public Persoana{
private:
    string role,echipa;
    short cartonase;
    bool hasBall;
public:
    Fotbalist();
    Fotbalist(const string& role,const string echipa,const bool hasBall,const ConcretePersoana &p);
    void showPersoana() override;
    int takeDecision() override;
    void setBall(const bool stare);
    void setRole(const string role);
    void setEchipa(const string echipa);
    void setCartonase(const short cartonase);
    friend std::istream& operator>>(std::istream &is,Fotbalist &rhs);
    string getRole();
    string getEchipa();
    short getCartonase();
};

#endif //OOP_FOTBALIST_H
