
#include "Walka.h"

Walka::Walka(Gracz &gracz1) : glownyGracz(gracz1){
    this->turn = 1;
    this->elitarnaCzworka = vector<Gracz>();
    this->pokedex = vector<Pokemon>();
    dodajPokemonyDoPokedexu();
    setElitarnaCzworka();
}

int Walka::getTurn() const {
    return turn;
}

void Walka::start() {
    Walka::wyborGracza();
}

void Walka::wyborGracza() {
    char choice = ' ';
    int something = 0;

    do {
        Walka::wyswietlPoczatek();
        cin>>choice;
        if (isdigit(choice)){
            int wybor = choice - '0';
            switch (wybor) {
                case 1:
                    //Funkcja callujaca kompletowanie druzyny
                    skompletujDruzyne();
                    break;
                case 2:
                    if (!getGlownyGracz().czyJakikolwiekPokemonZyje()){
                        cout<<"Aby zapisac, musisz przynajmniej rozegrac jedna rozgrywke!"<<endl;
                    } else {
                        //Funkcja zapisujaca aktualny stan rozgrywki
                        something = 1;
                    }
                    break;
                case 3:
                    //Funkcja kierujaca to zawalczenia z elitarna czworka
                    if (!getGlownyGracz().czyJakikolwiekPokemonZyje()){
                        cout<<"Aby zagrac, musisz skompletowac swoja druzyne!"<<endl;
                    } else {
                        wielkaWalkaZElitarnaCzworka();

                    }
                    break;
                default:
                    cout<<"Brak podanego numeru, wpisz jeszcze raz"<<endl;

            }
        } else if(choice == 'h'){
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<endl;
            cout<<"Aby wybrac opcje wpisz numer na poczatku pytania / funkcji."<<endl;
            cout<<endl;
            cout<<"-------------------------------------------------------------"<<endl;

        } else {
            cout<< "Zostal wprowadzony zly numer / litera"<<endl;

        }
        cout<<endl;
    } while (something == 0);

}

 Gracz &Walka::getGlownyGracz() {
    return glownyGracz;
}

 vector<Gracz> &Walka::getElitarnaCzworka()  {
    return elitarnaCzworka;
}

void Walka::setElitarnaCzworka() {
    Gracz marshal("Marshal"); // wodne // kontra magnezone
    marshal.getPokemonyGracza().push_back(Walka::getPokedex().at(0));
    marshal.getPokemonyGracza().push_back(Walka::getPokedex().at(1));
    marshal.getPokemonyGracza().push_back(Walka::getPokedex().at(2));
    getElitarnaCzworka().push_back(marshal);

    Gracz flint("Flint"); // fire // wodne // starmie
    flint.getPokemonyGracza().push_back(Walka::getPokedex().at(3));
    flint.getPokemonyGracza().push_back(Walka::getPokedex().at(4));
    flint.getPokemonyGracza().push_back(Walka::getPokedex().at(5));
    getElitarnaCzworka().push_back(flint);

    Gracz jacob("Jacob"); // ziemia // lapras
    jacob.getPokemonyGracza().push_back(Walka::getPokedex().at(13));
    jacob.getPokemonyGracza().push_back(Walka::getPokedex().at(14));
    jacob.getPokemonyGracza().push_back(Walka::getPokedex().at(15));
    getElitarnaCzworka().push_back(jacob);

    Gracz monika("Monika"); // powietrze // pidgey
    monika.getPokemonyGracza().push_back(Walka::getPokedex().at(7));
    monika.getPokemonyGracza().push_back(Walka::getPokedex().at(16));
    monika.getPokemonyGracza().push_back(Walka::getPokedex().at(17));
    getElitarnaCzworka().push_back(monika);

}

void Walka::dodajPokemonyDoPokedexu() {
    Pokemon starmie("Starmie","woda", 2000, 20, 400, 500);
    Pokemon samurott("Samurott","woda", 2000, 20, 600, 400);
    Pokemon walrein("Walrein","woda", 2400, 5, 300, 700);

    Pokemon rapidash("Rapidash","ogien", 1800, 30, 600, 400);
    Pokemon reshiram("Reshiram","ogien", 2100, 20, 700, 300);
    Pokemon salazzle("Salazzle","ogien", 1800, 30, 500, 600);

    Pokemon lapras("Lapras","lod",1700,30,700,300);
    Pokemon glaceon("Glaceon","lod",1400,40,700,400);
    Pokemon aurora("Aurora","lod",1900,30,600,300);

    Pokemon steelix("Steelix","stal",1700,30,500,400);
    Pokemon magnezone("Magnezone","stal",1600,30,600,300);
    Pokemon matwile("Matwile","stal",1600,30,600,300);

    Pokemon geodude("Geodude", "ziemia",1800,20,400,500);
    Pokemon diglett("Diglett", "ziemia",1600,30,600,400);
    Pokemon onix("Onix", "ziemia",1800,20,400,500);

    Pokemon pidgey("Pidgey", "powietrze", 1500, 30, 600, 300);
    Pokemon dragonite("Dragonite", "powietrze", 1700, 30, 700, 300);
    Pokemon starie("Starie", "powietrze", 1400, 30, 800, 300);

    getPokedex().push_back(starmie);
    getPokedex().push_back(samurott);
    getPokedex().push_back(walrein);

    getPokedex().push_back(rapidash);
    getPokedex().push_back(reshiram);
    getPokedex().push_back(salazzle);

    getPokedex().push_back(magnezone);
    getPokedex().push_back(pidgey);
    getPokedex().push_back(lapras);

    getPokedex().push_back(glaceon);

    getPokedex().push_back(aurora);
    getPokedex().push_back(steelix);
    getPokedex().push_back(matwile);

    getPokedex().push_back(geodude);
    getPokedex().push_back(diglett);
    getPokedex().push_back(onix);

    getPokedex().push_back(dragonite);
    getPokedex().push_back(starie);
}

 vector<Pokemon> &Walka::getPokedex()  {
    return pokedex;
}

void Walka::wyswietlPoczatek() {
    cout<<"Witamy w grze Pokemon!"<<endl;
    cout<<"Aby wybrac opcje, nalezy wpisac numer sprzed funkcji"<<endl;
    cout<<"1. Skompletuj swoja druzyne"<<endl;
    cout<<"2. Zapisz aktualny stan rozgrywki"<<endl; //kiedy sie zaczyna, wyskoczy blad ze dopiero co zaczelismy rozgrywke
    cout<<"3. Zawalcz z Elitarna czworka!"<<endl; //kiedy nie ma pokemonow wyskoczy blad
    cout<<endl;
    cout<<"-h - Wpisz 'h' aby uzyskac pomoc"<<endl;
}

void Walka::skompletujDruzyne() {
    int swap = 0;
    char wybor = ' ';

    do {
        cout<<endl;
        cout<<"Aby dodac pokemona do swojej druzyny, wpisz jego numer."<<endl;
        for (int i = 0; i < Walka::getPokedex().size(); ++i) {
            cout<<i<< ". "<< Walka::getPokedex().at(i).getNazwa()<<endl;
        }
        cout<<"Aby wyswietlic swoje pokemony, wpisz w"<<endl;
        cout<<"Aby powrocic do Menu glownego, wpisz b."<<endl;

        cin>>wybor;
        if (isdigit(wybor)) {
            int iwybor = wybor - '0';
            if (iwybor < Walka::getPokedex().size()){
                getGlownyGracz().getPokemonyGracza().push_back(getPokedex()[iwybor]);

                cout<<"Pokemon "<< getGlownyGracz().getPokemonyGracza().at(getGlownyGracz().getPokemonyGracza().size()-1).getNazwa()
                <<" zostal pomyslnie dodany."<<endl;
            } else {
                cout<<"Podany numer nie znajduje sie w pokedexie"<<endl;
            }
        }else if (wybor == 'b'){
            swap = 1;
        } else if (wybor == 'w'){
            if (getGlownyGracz().getPokemonyGracza().empty()){
                cout<<"Brak pokemonow w twojej druzynie"<<endl;
            } else {
                cout<<"Twoje pokemony to: "<<endl;
                for (int i = 0; i < getGlownyGracz().getPokemonyGracza().size(); ++i){
                    cout<< "Pokemon: "<<getGlownyGracz().getPokemonyGracza().at(i).getNazwa()<< endl;
                    cout<< "Zycie: " << getGlownyGracz().getPokemonyGracza().at(i).getZycie()<<endl;
                    cout<< "Moc specjalna: " << getGlownyGracz().getPokemonyGracza().at(i).getMocSpecjalna().getNazwa()<<endl;
                    cout<<endl;
                }
            }
        }else {
            cout<<"Nie jest to litera/numer";
        }
    } while (swap == 0);
}

void Walka::wypisanieInfoPC(Gracz &gracz2) {
    cout << gracz2.getNick() << " wyrzuca " << gracz2.getPokemonyGracza().at(gracz2.getAktualnyPokemon()).getNazwa()
         << "!"<<endl;
    cout << "Pokemon: "<<gracz2.getPokemonyGracza().at(gracz2.getAktualnyPokemon()).getNazwa()<<endl;
    cout << "Zycie: " <<gracz2.getPokemonyGracza().at(gracz2.getAktualnyPokemon()).getZycie()<<endl;
    cout<<endl;
}

bool Walka::sprawdzaCzyElitarnaCzworkaPokonana(){
    for (int i = 0; i < getElitarnaCzworka().size(); ++i) {
        if (getElitarnaCzworka().at(i).isCzyPokonany()){
            return false;
        }
    }
    return true;
}


void Walka::wielkaWalkaZElitarnaCzworka() {
    cout<<"Witamy w turnieju!"<<endl;
    cout<<endl;
    int numerWalkiZCzworka = naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka();
    while (numerWalkiZCzworka < 4 ){
        if (numerWalkiZCzworka == 0){
            while (getGlownyGracz().czyJakikolwiekPokemonZyje() && getElitarnaCzworka().at(0).czyJakikolwiekPokemonZyje()){
                cout<<"Runda: "<<turn<<endl;
                wypisanieInfoPC(getElitarnaCzworka().at(0));
                wypisanieInfoPC(getGlownyGracz());
                getGlownyGracz().tura(getElitarnaCzworka().at(0));
                if (getElitarnaCzworka().at(0).getPokemonyGracza().at(getElitarnaCzworka().at(0).getAktualnyPokemon()).isAlive()){
                    ruchPC(getElitarnaCzworka().at(0));
                } else if (getElitarnaCzworka().at(0).czyJakikolwiekPokemonZyje()){
                    getElitarnaCzworka().at(0).przeciwnikWybieraPokemonaDoZmiany(getElitarnaCzworka().at(0));
                } else {

                    numerWalkiZCzworka = naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka();
                }
                turn+=1;
            }
        }

        else if (numerWalkiZCzworka == 1){
            turn = 1;
            while (getGlownyGracz().czyJakikolwiekPokemonZyje() && getElitarnaCzworka().at(1).czyJakikolwiekPokemonZyje()){
                cout<<"Runda: "<<turn<<endl;
                wypisanieInfoPC(getElitarnaCzworka().at(1));
                wypisanieInfoPC(getGlownyGracz());
                getGlownyGracz().tura(getElitarnaCzworka().at(1));
                if (getElitarnaCzworka().at(1).getPokemonyGracza().at(getElitarnaCzworka().at(1).getAktualnyPokemon()).isAlive()){
                    ruchPC(getElitarnaCzworka().at(1));
                } else if (getElitarnaCzworka().at(1).czyJakikolwiekPokemonZyje()){
                    getElitarnaCzworka().at(1).przeciwnikWybieraPokemonaDoZmiany(getElitarnaCzworka().at(1));
                } else {
                    numerWalkiZCzworka = naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka();
                }
                turn+=1;
            }

        } else if (numerWalkiZCzworka == 2){
            turn = 1;
            while (getGlownyGracz().czyJakikolwiekPokemonZyje() && getElitarnaCzworka().at(2).czyJakikolwiekPokemonZyje()){
                cout<<"Runda: "<<turn<<endl;
                wypisanieInfoPC(getElitarnaCzworka().at(2));
                wypisanieInfoPC(getGlownyGracz());
                getGlownyGracz().tura(getElitarnaCzworka().at(2));
                if (getElitarnaCzworka().at(2).getPokemonyGracza().at(getElitarnaCzworka().at(2).getAktualnyPokemon()).isAlive()){
                    ruchPC(getElitarnaCzworka().at(2));
                } else if (getElitarnaCzworka().at(2).czyJakikolwiekPokemonZyje()){
                    getElitarnaCzworka().at(2).przeciwnikWybieraPokemonaDoZmiany(getElitarnaCzworka().at(2));
                } else {
                    numerWalkiZCzworka = naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka();
                }
                turn+=1;
            }
        } else if (numerWalkiZCzworka == 3){
            turn = 1;
            while (getGlownyGracz().czyJakikolwiekPokemonZyje() && getElitarnaCzworka().at(3).czyJakikolwiekPokemonZyje()){
                cout<<"Runda: "<<turn<<endl;
                wypisanieInfoPC(getElitarnaCzworka().at(3));
                wypisanieInfoPC(getGlownyGracz());
                getGlownyGracz().tura(getElitarnaCzworka().at(3));
                if (getElitarnaCzworka().at(3).getPokemonyGracza().at(getElitarnaCzworka().at(3).getAktualnyPokemon()).isAlive()){
                    ruchPC(getElitarnaCzworka().at(3));
                } else if (getElitarnaCzworka().at(3).czyJakikolwiekPokemonZyje()){
                    getElitarnaCzworka().at(3).przeciwnikWybieraPokemonaDoZmiany(getElitarnaCzworka().at(3));
                } else {
                    numerWalkiZCzworka = naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka();
                }
                turn+=1;
            }
        }
    }

}

int Walka::naKtorymIndeksieZElitarnejCzworkiZostalaRozgrywka() {
   int index = 0;
    for (int i = 0; i < getElitarnaCzworka().size(); ++i) {
        if (!getElitarnaCzworka().at(i).isCzyPokonany()){
            index = i;
            return index;
        }
    }
    index = 3;
    return index;
}

void Walka::ruchPC(Gracz& gracz2) {
        gracz2.pokemonAtakujePokemona(getGlownyGracz());
}



