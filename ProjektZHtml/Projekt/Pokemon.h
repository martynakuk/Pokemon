#include <string>
#include "MocSpecjalna.h"

using namespace std;
#ifndef PROJEKT_POKEMON_H
#define PROJEKT_POKEMON_H


class Pokemon {
    int zycie;
    int zrecznosc;
    int sila;
    int exp;
    string nazwa;
    string typ;
    int silaZwyklegoAtaku;
    MocSpecjalna mocSpecjalna;

public:

    /**
    * Utworzenie nowego pokemona
    * @param nazwa Nazwa pokemona
    * @param typ Typ pokemona
    * @param zycie Zycie pokemona
    * @param zrecznosc Szansa na unik pokemona
    * @param sila Sila pokemona
    * @param exp Exp zdobyte za pokonanie pokemona
    */
    Pokemon(string nazwa, string typ, int zycie, int zrecznosc, int sila, int exp);

    int getZycie() const;

    void setZycie(int zycie);

    int getZrecznosc() const;

    int getSila() const;

    int getExp() const;

    const string &getTyp() const;

    const string &getNazwa() const;

    int getlUzyc() const;

    MocSpecjalna getMocSpecjalna() const;

    int getSilaZwyklegoAtaku() const;

    /**
    * Funkcja sprawdzajaca czy pokemon, na rzecz ktorego funkcja jest wywolywana jest zdatny do walki
    * @return true - jesli jest zdatny do walki, false - jesli nie
    */
    bool isAlive() const;
};


#endif //PROJEKT_POKEMON_H
