//
// Created by Radu on 4/28/2023.
//

#ifndef OOP_ARBITRU_H
#define OOP_ARBITRU_H
#include "Persoana.h"

class Arbitru : virtual public Persoana{
private:
    string position;
    bool isStrict;
public:
    Arbitru();
    Arbitru(const string& position,const bool isStrict, const ConcretePersoana &p);
    void setPosition(string position);
    void setStrict(bool isStrict);
    int takeDecision() override;
    void showPersoana() override;
    string getPosition();
    friend std::istream& operator>>(std::istream &is, Arbitru& rhs);

};

#endif //OOP_ARBITRU_H
