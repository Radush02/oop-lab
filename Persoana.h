//
// Created by Radu on 4/24/2023.
//

#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Persoana {
private:
    string nume;
    int varsta;
    float height,weight;
public:
    Persoana();
    Persoana(const string& nume,const int varsta,const float height,const float weight);
    Persoana(const Persoana& rhs);
    const string& getnume() const;
    int getvarsta() const;
    void setnume(const string& nume);
    void setvarsta(const int varsta);
    void setHeight(const float height);
    void setWeight(const float weight);
    virtual void showPersoana();
    virtual int takeDecision()=0;
    virtual ~Persoana();
    friend std::ostream& operator<<(std::ostream &os,const Persoana &rhs);
    friend std::istream& operator>>(std::istream &is,Persoana &rhs);
};

class ConcretePersoana : public Persoana {
public:
    ConcretePersoana();
    ConcretePersoana(const string& nume,const int varsta,const float height,const float weight);
    int takeDecision() override;
};


class Fotbalist : public Persoana{
private:
    string role;
    int goluri,cartonase;
    bool hasBall;
public:
    Fotbalist();
    Fotbalist(const string& role,const int goluri,const bool hasBall,const ConcretePersoana &p);
    void showPersoana() override;
    int takeDecision() override;
};



class Arbitru : public Persoana{
private:
    string position;
    bool isStrict;
public:
    Arbitru();
    Arbitru(const string& position,const bool isStrict, const ConcretePersoana &p);
    int takeDecision() override;
    void showPersoana() override;
};

#endif //OOP_PERSOANA_H
