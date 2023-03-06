#include <iostream>
#include "bilete.h"
int main() {
    partida meci("05.03.2023","FCSB","Dinamo");
    bilete bilet("Loja VIP",101,100,meci);
    partida meci2("08.03.2023","Rapid","Chindia");
    std::cout<<bilet;
    return 0;
}
