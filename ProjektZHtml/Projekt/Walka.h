#ifndef PROJEKT_WALKA_H
#define PROJEKT_WALKA_H


#include "Gracz.h"

class Walka {
    int turn;
    vector <Gracz> elitarnaCzworka;
    vector <Pokemon> pokedex;
    Gracz glownyGracz;

public:
    /**
     * Obiekt, ktorego glownym graczem bedzie nasza postac
     * @param gracz1 Nasza postac
     */
    Walka(Gracz &gracz1);

    vector<Pokemon> &getPokedex() ;

    vector<Gracz> &getElitarnaCzworka() ;

    /**
    * Funkcja inicjujaca liste przeciwnikow, z ktorymi gracz bedzie walczyc
    */
    void setElitarnaCzworka();

    Gracz &getGlownyGracz() ;

    void start();

    /**
    * Jest to funkcja przekierowująca do danego wyboru gracza na początku gry
    * Między innymi: skompletowanie drużyny, zapisywanie aktualnego stanu rozgrywki, walka z 4 przeciwnikami
    */
    void wyborGracza();

    /**
     * Funkcja inicjująca liste pokemonów w pokedexie
    */
    void dodajPokemonyDoPokedexu();

    /**
    * Funkcja wyswietlajaca wybory, jakie gracz moze podjac wpisujac liczbę/literę
    */
    static void wyswietlPoczatek();

    /**
    * Funkcja pozwalajaca na dodanie pokemona z pokedexu do naszej listy pokemonow
    */
    void skompletujDruzyne();

    /**
     * Funkcja wyswietlajaca jakiego pokemona gracz wyrzuca, oraz jego zycie
    * @param gracz2 Wypisujemy informacje aktualnym pokemonie gracza, ktory zostal przekazany parametrem
    */
    void wypisanieInfoPC(Gracz& gracz2);

    /**
    * Funkcja sprawdzajaca czy 4 przeciwnikow z ktorymi bedziemy walczyc, sa pokonani
    * @return Zwraca true, jesli pokonalismy 4 przeciwnikow, false jesli nie
    */
    bool sprawdzaCzyElitarnaCzworkaPokonana();

    /**
    * Funkcja, w ktorej walczymy z elitarna czworka
    * Jest po kolei wypisany nr. rundy, informacje o pokemonach
     * Nasz pokemon atakuje przeciwnika, a pozniej przeciwnik naszego
    */
    void wielkaWalkaZElitarnaCzworka();

    /**
    * Funkcja sprawdza na ktorym indeksie w liscie przeciwnikow zostala zakonczona rozgrywka
    * @return zwraca nr. indeksu
    */
    int naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka();

    /**
    *Funkcja losujaca, czy pokemon przeciwnika bedzie atakowac normalnym atakiem, czy moca specjalna,
    * jesli normalny atak, wywola funkcje z normalnym atakiem, jesli moc specjalna, wywola funkcje
    * z moca specjalna
    * @param gracz2 Przeciwnik
    */
    void ruchPC(Gracz& gracz2);

    int getTurn() const;

    void setTurn(int turn);

};


#endif //PROJEKT_WALKA_H
