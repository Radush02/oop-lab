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
    exceptiiPersoane(string nume,int minAge, int maxAge, bool isSoccerPlayer);
    virtual const char* what() const throw();
    exceptiiPersoane(string nume,int IMC);
    exceptiiPersoane(string nume,int height,int weight);
};


#endif //OOP_EXCEPTII_H
