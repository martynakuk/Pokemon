#ifndef PROJEKT_GRACZ_H
#define PROJEKT_GRACZ_H

#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Gracz {
    vector<Pokemon> pokemonyGracza;
    int aktualnyPokemon;
    string nick;
    bool czyPokonany;
public:

    /**
    * Stworzenie nowego obiektu klasy gracz
    * @param nick Imie gracza
    */
    Gracz(string nick);

    void setAktualnyPokemon(int aktualnyPokemon);

    int getAktualnyPokemon() const;

    vector<Pokemon>& getPokemonyGracza();

    /**
    * Funkcja wykonuje w zaleznosci od naszego wyboru
    * Zwykly atak naszego pokemona, Moc specjalna naszego pokemona
    * Zmiane naszego pokemona lub jego mega ewolucje
    * @param gracz2 Przeciwnik
    */
    void tura(Gracz &gracz2);

    /**
    * Funkcja wyswietlajaca menu walki z przeciwnikiem, i zapisujaca nasz wybor
    * @return Numer wyboru
    */
    int wyswietlMenu();

    bool isNumber(char s);

    /**
    * Funkcja wywolujaca atak pokemona gracza, na rzecz ktorego jest wywolywana funkcja,
    * na pokemona gracza podanego w parametrze
     * @param gracz2 Gracz, ktorego pokemon zostanie zaatakowany
     */
    void pokemonAtakujePokemona(Gracz &gracz2);

    /**
    * Funkcja sprawdzajaca czy pokemon, na rzecz ktorego jest wywolywana funkcja,
    * trafil pokemona podanego w parametrze
    * @param pokemon2 Pokemon, ktory ma zostac trafiony
    * @return zwraca czy pokemon zostal trafiony czy nie
    */
    bool czyPokemonTrafil(const Pokemon& pokemon2);

    /**
    * Funkcja sprawdzajaca jakiego typu jest pokemon, na rzecz ktorego jest wywolywana funkcja
    * oraz typ przeciwnika, w zaleznosci od typu jest wypisywane zdanie okreslajace czy
    * jest to super efektywne, malo efektywne.
    * @param pokemon Pokemon, ktory zostanie zaatakowany
    * @return Zwraca moc ataku, jesli super efektywne - 2, malo efektywne - 0.5, normalne - 1
    */
    double jakaMocAtaku(const Pokemon& pokemon);

    /**
    * Funkcja sprawdzajaca pokemony gracza, na rzecz ktorego wywolywana jest funkcja,
    * czy jakikolwiek z nich jest zyjacy
    * @return true - jesli ktorys z pokemonow jest zdatny do walki, false - jesli żaden
     */
    bool czyJakikolwiekPokemonZyje();

    /**
    * Funkcja wypisujaca zakonczenie gry
    */
    void koniecGry();

    const string &getNick() const;

    /**
    * Funkcja ataku moca specjalna
    * @param pokemon pokemon, ktory zostanie zaatakowany
    */
    void pokemonAtakujeMocaSpecjalnaPokemona(const Pokemon& pokemon);

    /**
    * Funkcja wypisujaca wszystkie pokemony.
    * Zamienia naszego pokemona z wybranym.
    */
    void wybierzPokemonaDoZmiany();

    void przeciwnikWybieraPokemonaDoZmiany(Gracz &gracz2);

    /**
    * Funkcja sprawdzajaca czy podany numer pokemona jest na liscie zyjacych pokemonow
    * @param number numer na liscie pokemonow gracza
    * @return czy pokemon jest na liscie - true, jesli nie - false
    */
    bool czyJestNaliscieZyjacychPokemonow(int number);

    bool isCzyPokonany() const;

    void setCzyPokonany(bool czyPokonany);

};


#endif //PROJEKT_GRACZ_H
