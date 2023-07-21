//
// Created by Martyna on 25.06.2022.
//

#include "Gracz.h"


using namespace std;

Gracz::Gracz(string nick) : nick(nick) {
    this->aktualnyPokemon = 0;
    this->czyPokonany = false;
    this->pokemonyGracza = vector <Pokemon>();
}

bool Gracz::isCzyPokonany() const {
    return czyPokonany;
}

void Gracz::setCzyPokonany(bool czyPokonany) {
    Gracz::czyPokonany = czyPokonany;
}

void Gracz::tura(Gracz &gracz2) {

    switch(Gracz::wyswietlMenu()){
        case 1:
            pokemonAtakujePokemona(gracz2);
            if (!gracz2.getPokemonyGracza().at(gracz2.getAktualnyPokemon()).isAlive()){
                cout<<"Pokemon: " <<gracz2.getPokemonyGracza().at(gracz2.getAktualnyPokemon()).getNazwa()<<" zostal pokonany"<<endl;
                cout<<endl;
                if (!gracz2.czyJakikolwiekPokemonZyje()){
                    cout<<"Gracz: " << gracz2.getNick()<<" zostal pokonany"<<endl;
                    cout<<endl;
                    gracz2.setCzyPokonany(true);
                }
            } else if (!getPokemonyGracza().at(getAktualnyPokemon()).isAlive()){
                cout<<getPokemonyGracza().at(getAktualnyPokemon()).getNazwa()<<" zostal pokonany"<<endl;
                cout<<endl;
                if (!Gracz::czyJakikolwiekPokemonZyje()){
                    koniecGry();
                } else {
                    wybierzPokemonaDoZmiany();
                }
            }
            break;
        case 2:
            //Moc specjalna

            break;
        case 3:
            wybierzPokemonaDoZmiany();
            break;
        case 4:
            //Mega ewolucja
            break;
    }

}

vector<Pokemon>& Gracz::getPokemonyGracza() {
    return pokemonyGracza;
}

int Gracz::getAktualnyPokemon() const {
    return aktualnyPokemon;
}

void Gracz::setAktualnyPokemon(int aktualnyPokemon) {
    Gracz::aktualnyPokemon = aktualnyPokemon;
}

int Gracz::wyswietlMenu() {
    char choice;
    int something = 1;
    cout << "Wybierz swoj ruch:" << endl;
    cout << "1. Atak" << endl;
    cout << "2. " << "Moc specjalna: "
         << Gracz::getPokemonyGracza().at(Gracz::getAktualnyPokemon()).getMocSpecjalna().getNazwa()
         << " | Liczba uzyc: " << Gracz::getPokemonyGracza().at(Gracz::getAktualnyPokemon()).getlUzyc() << endl;
    cout << "3. Zmiana Pokemona" << endl;
    cout << "4. Mega ewolucja" << endl; //dokonczyc

    do {
        cin >> choice;
        if (Gracz::isNumber(choice)) {
            switch (choice) {
                case '1':
                case '2':
                case '3':
                case '4':
                {
                    something = 1;
                    int wybor = choice - '0';
                    return wybor;
                }
                default: {
                    something = 0;
                    cout << "Zostal wprowadzony nieprawidlowy numer/litera" << endl;
                    break;
                }
            }
        } else {
            cout << "Zostal wprowadzony nieprawidlowy numer/litera" << endl;
            something = 0;
        }
    } while (something == 0);
}

bool Gracz::isNumber(char s) {
    return isdigit(s);
}

void Gracz::pokemonAtakujePokemona(Gracz &gracz2) {
    Pokemon& currentPokemon = gracz2.getPokemonyGracza().at(gracz2.getAktualnyPokemon());
    if (czyPokemonTrafil(currentPokemon) ){
        cout << this->getPokemonyGracza().at(getAktualnyPokemon()).getNazwa() <<
             " atakuje " << currentPokemon.getNazwa()<<endl;
        cout<<endl;
        currentPokemon.setZycie(
                currentPokemon.getZycie() - (
                this->jakaMocAtaku(currentPokemon) * this->getPokemonyGracza().at(this->getAktualnyPokemon()) .getSilaZwyklegoAtaku()));
    }
}

bool Gracz::czyPokemonTrafil(const Pokemon &pokemon2) {
    int los = rand() % 100 + 1;

    if (los <= pokemon2.getZrecznosc()) {
        cout << "Pokemon: "<< pokemon2.getNazwa() <<" nie zostal trafiony"<<endl;
        cout<<endl;
        return false;
    } else {
        return true;
    }
}

double Gracz::jakaMocAtaku(const Pokemon &pokemon) {
    if (Gracz::getPokemonyGracza().at(this->getAktualnyPokemon()).getTyp() == "woda") {
        if (pokemon.getTyp() == "ziemia" || pokemon.getTyp() == "ogien") {
            cout << "Jest to super efektywne!" << endl;
            cout<<endl;
            return 2;
        } else if (pokemon.getTyp() == "woda") {
            cout << "Jest to malo efektywne." << endl;
            cout<<endl;
            return 0.5;
        } else {
            cout<<endl;
            return 1;
        }
    } else if (Gracz::getPokemonyGracza().at(this->getAktualnyPokemon()).getTyp() == "ziemia") {
        if (pokemon.getTyp() == "ogien" || pokemon.getTyp() == "lod" || pokemon.getTyp() == "stal") {
            cout << "Jest to super efektywne!" << endl;
            cout<<endl;
            return 2;
        } else if (pokemon.getTyp() == "powietrze") {
            cout << "Jest to malo efektywne." << endl;
            cout<<endl;
            return 0.5;
        } else {
            cout<<endl;
            return 1;
        }
    } else if (Gracz::getPokemonyGracza().at(this->getAktualnyPokemon()).getTyp() == "powietrze") {
        if (pokemon.getTyp() == "lod") {
            cout << "Jest to super efektywne!" << endl;
            cout<<endl;
            return 2;
        } else if (pokemon.getTyp() == "ziemia" || pokemon.getTyp() == "stal") {
            cout << "Jest to malo efektywne." << endl;
            cout<<endl;
            return 0.5;
        } else {
            cout<<endl;
            return 1;
        }
    } else if (Gracz::getPokemonyGracza().at(this->getAktualnyPokemon()).getTyp() == "ogien") {
        if (pokemon.getTyp() == "lod" || pokemon.getTyp() == "stal") {
            cout << "Jest to super efektywne!" << endl;
            return 2;
        } else if (pokemon.getTyp() == "woda" || pokemon.getTyp() == "ziemia") {
            cout << "Jest to malo efektywne" << endl;
            return 0.5;
        } else {
            cout<<endl;
            return 1;
        }
    } else if (Gracz::getPokemonyGracza().at(this->getAktualnyPokemon()).getTyp() == "lod") {
        if (pokemon.getTyp() == "ziemia") {
            cout << "Jest to super efektywne!" << endl;
            cout<<endl;
            return 2;
        } else if (pokemon.getTyp() == "woda" || pokemon.getTyp() == "ogien" || pokemon.getTyp() == "lod") {
            cout << "Jest to malo efektywne" << endl;
            cout<<endl;
            return 0.5;
        } else {
            cout<<endl;
            return 1;
        }
    } else if (Gracz::getPokemonyGracza().at(this->getAktualnyPokemon()).getTyp() == "stal") {
        if (pokemon.getTyp() == "woda" || pokemon.getTyp() == "powietrze") {
            cout << "Jest to super efektywne!" << endl;
            cout<<endl;
            return 2;
        } else if (pokemon.getTyp() == "ogien" || pokemon.getTyp() == "stal") {
            cout << "Jest to malo efektywne." << endl;
            cout<<endl;
            return 0.5;
        } else {
            cout<<endl;
            return 1;
        }
    }
}

bool Gracz::czyJakikolwiekPokemonZyje(){
    for (int i = 0; i < Gracz::getPokemonyGracza().size(); ++i) {
        if (Gracz::getPokemonyGracza().at(i).isAlive()){
            return true;
        }
    }
    return false;
}

void Gracz::koniecGry() {

    if (Gracz::czyJakikolwiekPokemonZyje()){
        cout<<"Gratulujemy pokonania wszystkich przeciwnikow!"<<endl;
        cout<<"Dziekujemy za gre z nami!";
    } else {
        cout<<"Nie masz juz zyjacych pokemonow"<<endl;
        cout<<"Dziekujemy za gre z nami!";
    }
}

const string &Gracz::getNick() const {
    return nick;
}

void Gracz::pokemonAtakujeMocaSpecjalnaPokemona(const Pokemon& pokemon){ //do poprawienia
    if (Gracz::getPokemonyGracza().at(getAktualnyPokemon()).getTyp() == "powietrze" || Gracz::getPokemonyGracza().at(getAktualnyPokemon()).getTyp() == "stal"){

    }
    if (Gracz::czyPokemonTrafil(Gracz::getPokemonyGracza().at(getAktualnyPokemon()))){

    }
}

void Gracz::wybierzPokemonaDoZmiany() {
    if (this->czyJakikolwiekPokemonZyje()){
        cout<<"Wpisz numer pokemona aby zamienic"<<endl;
        int counter = 0;
        for (int i = 0; i < Gracz::getPokemonyGracza().size(); ++i) {
            if (getPokemonyGracza().at(i).isAlive()){
                cout<<i<< ". " << Gracz::getPokemonyGracza().at(i).getNazwa()<<endl;
                counter++;
            }
        }
        char choice;
        int something = 0;

        do {
            cin >> choice;
            if (Gracz::isNumber(choice)) {
                if (choice - '0' < getPokemonyGracza().size()){
                    Gracz::setAktualnyPokemon(choice - '0');
                    something = 1;
                } else {
                    cout << "Zostal wprowadzony nieprawidlowy numer" << endl;
                }
            } else {
                cout << "Zostal wprowadzony nieprawidlowy numer/litera" << endl;

            }
        } while (something == 0);
    } else {
        koniecGry();
    }


}

void Gracz::przeciwnikWybieraPokemonaDoZmiany(Gracz &gracz2) {

    gracz2.setAktualnyPokemon(getAktualnyPokemon()+1);
}

bool Gracz::czyJestNaliscieZyjacychPokemonow(int number) {
    for (int i = 0; i < Gracz::getPokemonyGracza().size(); ++i) {
        if (Gracz::getPokemonyGracza().at(i).isAlive()){
            if (&Gracz::getPokemonyGracza().at(number) == &Gracz::getPokemonyGracza().at(i)){
                return true;
            } else {
                cout<<"Brak pokemona na liscie"<<endl;
            }
        } else {
            return false;
        }
    }
    return false;
}












