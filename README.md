# Proiect OOP - Managementul Meciurilor de Fotbal
## Descriere
Acest proiect implementează un sistem de management al meciurilor de fotbal, utilizând concepte avansate de programare orientată pe obiecte (OOP). Proiectul include gestionarea echipelor, jucătorilor, arbitrilor și biletelor pentru meciuri, oferind funcționalități pentru vânzarea biletelor, vizualizarea meciurilor și simularea meciurilor amicale.

## Concepte OOP Utilizate
### Moșteniri
Proiectul utilizează moștenirea pentru a crea ierarhii de clase. De exemplu, clasele Arbitru și Fotbalist moștenesc clasa de bază Persoana.
```c++
class Arbitru : virtual public Persoana { ... };
class Fotbalist : virtual public Persoana { ... };
```
### Funcții Virtuale Pure
Clasa de bază Persoana definește funcții virtuale pure, care sunt suprascrise în clasele derivate Arbitru și Fotbalist.
```c++
class Persoana {
public:
    virtual int takeDecision() = 0;
    virtual void showPersoana() = 0;
    ...
};
```
### STL
Proiectul utilizează containere STL precum vector, map și algoritmi STL pentru gestionarea colecțiilor de obiecte.
```c++
std::vector<std::shared_ptr<Persoana>> echipaJucator;
std::map<string, std::vector<std::shared_ptr<Fotbalist>>> lotEchipe;
```
### Smart Pointers
Proiectul utilizează smart pointers (std::shared_ptr, std::unique_ptr) pentru gestionarea memoriei și evitarea scurgerilor de memorie.
```c++
std::vector<std::shared_ptr<Persoana>> echipaJucator;
std::unique_ptr<Arbitru> ref = std::make_unique<Arbitru>("Central", true, ConcretePersoana("Pierluigi Collina", 50, 1.68, 64.6));
```
### Dynamic Cast
Proiectul utilizează dynamic_cast pentru a converti pointeri de clasă de bază la pointeri de clasă derivată.
```c++
Fotbalist* aux = dynamic_cast<Fotbalist*>(x.get());
```
### Excepții
Proiectul definește și utilizează excepții personalizate, derivate din std::exception. Excepțiile sunt aruncate în constructori și gestionate în funcția main.
```c++
class exceptiiPersoane : public std::exception { ... };
class exceptiiVanzare : public std::exception { ... };
class exceptiiMeci : public std::exception { ... };
```
### Apelarea Constructorului din Clasa de Bază
Constructorii claselor derivate apelează constructorul parametrizat al clasei de bază Persoana.
```c++
Arbitru::Arbitru(const string& position, const bool isStrict, const ConcretePersoana &p) : Persoana(p) { ... }
Fotbalist::Fotbalist(const string& role, const string echipa, const bool hasBall, const ConcretePersoana& p) : Persoana(p) { ... }
```
### Suprascrierea Operatorilor
Proiectul suprascrie operatori pentru a facilita compararea și afișarea obiectelor.
```c++
bool bilete::operator==(const bilete &rhs) const { ... }
std::ostream& operator<<(std::ostream &os, const bilete &rhs) { ... }
```


### Funcții și Atribute Statice
Proiectul utilizează funcții și atribute statice pentru a gestiona balanța totală a biletelor vândute.
```c++
class bilete {
private:
    static int balanta;
public:
    static void updateBalanta(int valoareBilet);
    static int getBalanta();
    ...
};
```

## Setup
1. Clonează repository-ul: ``git clone https://github.com/Radush02/oop-lab.git``
2. Compilează proiectul: ``g++ *.cpp -o fotbal``
3. Rulează-l: ``./fotbal``
