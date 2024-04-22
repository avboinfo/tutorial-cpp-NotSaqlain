/*
** BattleShip.cpp una classe per giocare alla Battaglia Navale
** Saqlain Khalid - 20/04/2024
*/

#include <iostream>
#include "BattleField.cpp"

class BattleShip {

    private:

    BattleField mappa;
    BattleField campo;

    public:
    BattleShip() {
        mappa = BattleField(VOID);
        campo = BattleField(VOID);
        campo.placeHorizontalShip(3);
        campo.placeVerticalShip(4);
        campo.placeVerticalShip(2);
        campo.placeHorizontalShip(5);
    }

    void play() {

        // lancia 20 bombe a caso
        for (int i=0; i<20; i++) {
            int x = rand() % N;
            int y = rand() % N;
            if (campo.get(x,y)==HIT) continue;
            if (campo.get(x,y)==SHIP) {
                mappa.put(x,y,HIT);
                campo.put(x,y,HIT);
            } else mappa.put(x,y,MISS);
        }

        mappa.stampa();

        ask();

        mappa.stampa();
        campo.stampa();

    }

    void ask() {
        std::cout << "Dove vuoi lanciare la bomba? (x y)";
        int x, y;
        std::cin >> x;
        std::cin >> y;
        if (campo.get(x,y)==SHIP) {
            mappa.put(x,y,HIT);
            campo.put(x,y,HIT);
        } else mappa.put(x,y,MISS);
    }

};