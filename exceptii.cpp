//
// Created by Radu on 4/26/2023.
//

#include "exceptii.h"
exceptiiPersoane::exceptiiPersoane(string nume,int minAge, int maxAge, bool isSoccerPlayer) {
    if (isSoccerPlayer) {
        message = nume+" nu poate avea mai putin de " + std::to_string(minAge) +
                  " ani sau mai mult de " + std::to_string(maxAge)+" ani!\n";
    } else {
        message = "Participantii nu pot avea mai mult de " + std::to_string(maxAge) +
                  " ani sau mai putin de " + std::to_string(minAge)+" ani!\n";
    }
}

const char* exceptiiPersoane::what() const throw() {
    return message.c_str();
}