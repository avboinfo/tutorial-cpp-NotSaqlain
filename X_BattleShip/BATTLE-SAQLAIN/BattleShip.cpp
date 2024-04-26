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

       while(!isGameOver()) {
            mappa.stampa();

            if (!ask()) {
                break;
            } 

            campo.stampa();
            
        }

        /*
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
        */

    }

    bool ask() {
        std::cout << "Dove vuoi lanciare la bomba? (x y)";
        int x, y;
        std::cin >> x;
        std::cin >> y;

        if (x <= 0 || x >= N || y <= 0 || y >= N) {
            std::cout << "Coordinate non valide" << std::endl;
            return false;
        } else {
            x--;
            y--;
        }

        if (campo.get(x,y)==SHIP) {
            mappa.put(x,y,HIT);
            campo.put(x,y,HIT);
        } else
            mappa.put(x,y,MISS);
        
        return true;
    }

    bool isGameOver() {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (campo.get(i,j)==SHIP)
                    return false;
            }
        }
        return true;
    }
};