//
// Created by Radu on 4/26/2023.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <iostream>
using namespace std;
class exceptiiPersoane : public std::exception {
private:
    string message;
public:
    exceptiiPersoane(const string nume,const int minAge,const int maxAge,const bool isSoccerPlayer);
    virtual const char* what() const throw();
    exceptiiPersoane(const string nume,const int IMC);
    exceptiiPersoane(const string nume,const int height,const int weight);
};

class exceptiiVanzare : public std::exception{
private:
    string message;
public:
    exceptiiVanzare();
    virtual const char* what() const throw();
};

class exceptiiMeci : public std::exception{
private:
    string message;
public:
    exceptiiMeci();
    exceptiiMeci(char* text);
    virtual const char* what() const throw();
};

#endif //OOP_EXCEPTII_H
