#include <iostream>
#include "bilete.h"
int main() {
    partida meci("05.03.2023","FCSB","Dinamo");
    bilete bilet("Loja VIP",101,100,meci);
    partida meci2("08.03.2023","Rapid","Chindia");
    std::cout<<bilet;
    bilete bilet2(bilet);
    bilet2.setPrice(100);
    bilet2.setMatch(meci2);
    bilet2.setSeat(106);
    char k[]="Peluza Nord";
    bilet2.setType(k);
    std::cout<<meci.getHome()<<" "<<meci.getAway()<<" "<<meci.getDate()<<bilet2.getPrice()<<bilet2.getType()<<bilet2.getSeat()<<bilet2.getMatch();
    return 0;
}
