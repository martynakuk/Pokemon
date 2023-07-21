
#include "MocSpecjalna.h"
#include <string>
#include <iostream>
using namespace std;

MocSpecjalna::MocSpecjalna(string typ) {
    if (typ == "woda"){
        this->liczbaUzyc = 5;
        this->nazwa = "Hydro Cannon";
    } else if (typ == "ziemia"){
        this->liczbaUzyc = 10;
        this->nazwa = "Earthquake";
    } else if (typ == "stal"){
        this->liczbaUzyc = 15;
        this->nazwa = "Shift Gear"; //Zwieksza atak na 3 tury
    } else if (typ == "powietrze"){
        this->liczbaUzyc = 5;
        this->nazwa = "Roost"; //Leczy 20% pelnego hp przez 3 tury
    } else if (typ == "lod"){
        this->liczbaUzyc = 10;
        this->nazwa = "Frost Breath"; //Zamraza przeciwnika na 3 tury
    } else if (typ == "ogien") {
        this->liczbaUzyc = 5;
        this->nazwa = "Inferno";
    } else {
        cout<<"Something is wrong";
    }
}

int MocSpecjalna::getLiczbaUzyc() const {
    return liczbaUzyc;
}

const string &MocSpecjalna::getNazwa() const {
    return nazwa;
}

void MocSpecjalna::setLiczbaUzyc(int liczbaUzyc) {
    MocSpecjalna::liczbaUzyc = liczbaUzyc;
}
