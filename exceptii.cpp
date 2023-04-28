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
exceptiiPersoane::exceptiiPersoane(string nume,int IMC){
    if(IMC>25)
        message=nume+" are indicele de masa corporala prea mare!";
    else
        message=nume+" are indicele de masa corporala prea mic!";
}
exceptiiPersoane::exceptiiPersoane(string nume,int height,int weight){
    message=nume+" nu poate avea "+std::to_string(weight)+" kilograme si "+std::to_string(height)+" metri!";
}
const char* exceptiiPersoane::what() const throw() {
    return message.c_str();
}

exceptiiVanzare::exceptiiVanzare() {
    message="Tip de bilet invalid!\nBilete valide si preturile: "
               "Peluza Nord - 30 RON, Peluza Sud - 30 RON, Tribuna II - 50 RON, Tribuna I - 60 RON, "
               "Tribuna 0 - 100 RON, VIP - 300 RON\n";
}
const char* exceptiiVanzare::what() const throw(){
    return message.c_str();
}
exceptiiMeci::exceptiiMeci(char* data){
    string s(data);
    message="Data "+s+" este invalida. Data trebuie sa fie de forma dd/mm/yyyy sau sa fie o data valida.\n";

}
const char* exceptiiMeci::what() const throw(){
    return message.c_str();
}