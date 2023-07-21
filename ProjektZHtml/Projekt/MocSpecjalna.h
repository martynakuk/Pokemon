#ifndef PROJEKT_MOCSPECJALNA_H
#define PROJEKT_MOCSPECJALNA_H
#include <string>

using namespace std;

class MocSpecjalna {
    int liczbaUzyc;
    string nazwa;
public:

    /**
    * Ruch pokemona, jego moc specjalna, w zaleznosci od typu posiada rozne efekty
    * @param typ typ pokemona
    */
    MocSpecjalna(string typ);

    void setLiczbaUzyc(int liczbaUzyc);

    const string &getNazwa() const;

    int getLiczbaUzyc() const;

};


#endif //PROJEKT_MOCSPECJALNA_H
