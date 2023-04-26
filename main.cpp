#include <iostream>
#include <vector>
#include "bilete.h"
#include "meci.h"
#include "persoana.h"
#include "exceptii.h"
/*
 * Cordunianu Radu - Gr 133
 */
using namespace std;
int main() {
    vector<Persoana*> onField;
    ConcretePersoana cp1("Marcus Rashford", 23, 1.77, 80.5);
    ConcretePersoana cp2("Kylian Mbappe", 22, 1.78, 83.2);
    ConcretePersoana cp3("Pierluigi Collina",50,1.68,64.6);
    try {
        Fotbalist* sp1 = new Fotbalist("Atacant", 30, true, cp1);
        onField.push_back(sp1);
        Fotbalist* sp2 = new Fotbalist("Atacant", 25, false, cp2);
        onField.push_back(sp2);
        Arbitru* ref= new Arbitru("VAR",true,cp3);
        onField.push_back(ref);
    }
    catch (exceptiiPersoane &e) {
        cout << e.what();
    }
    cout << "Pe teren:\n";
    for(auto x:onField)
    {
        Fotbalist* aux = dynamic_cast<Fotbalist*>(x);
        if(aux)
            aux->showPersoana();
        else{
            Arbitru* aux2 = dynamic_cast<Arbitru*>(x);
            if(aux2)
                aux2->showPersoana();
        }
    }
    for(auto x:onField)
        delete x;
    onField.clear();
    return 0;
}
