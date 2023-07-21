
#include "Pokemon.h"
#include "MocSpecjalna.h"
using namespace std;

Pokemon::Pokemon(string nazwa, string typ, int zycie, int zrecznosc, int sila, int exp) :
        nazwa(nazwa), typ(typ), zycie(zycie), zrecznosc(zrecznosc), sila(sila), exp(exp), mocSpecjalna(this->typ) {
    this ->silaZwyklegoAtaku = (int)(0.8 * sila);

}


int Pokemon::getZycie() const {
    return zycie;
}

void Pokemon::setZycie(int zycie){
    Pokemon::zycie = zycie;
}

int Pokemon::getZrecznosc() const {
    return zrecznosc;
}

int Pokemon::getSila() const {
    return sila;
}

int Pokemon::getExp() const {
    return exp;
}

const string &Pokemon::getTyp() const {
    return typ;
}

const string &Pokemon::getNazwa() const {
    return nazwa;
}

int Pokemon::getlUzyc() const {
    return mocSpecjalna.getLiczbaUzyc();
}

MocSpecjalna Pokemon::getMocSpecjalna() const {
    return this->mocSpecjalna;
}

int Pokemon::getSilaZwyklegoAtaku() const {
    return silaZwyklegoAtaku;
}

bool Pokemon::isAlive() const {
    if (Pokemon::getZycie() >= 0){
        return true;
    } else {
        return false;
    }
}



