/*
** BattleShip.cpp una classe per giocare alla Battaglia Navale
** Saqlain Khalid - 20/04/2024
*/

#include <iostream>
#include "BattleField.cpp"

class BattleShip {

private:
    BattleField mappa;
    BattleField boats;

public:
    BattleShip() {
        mappa = BattleField(VOID);
        boats = BattleField();

        boats.placeShips(5);

        /*
        boats.placeHorizontalShip(3);
        boats.placeVerticalShip(4);
        boats.placeVerticalShip(2);
        boats.placeHorizontalShip(5);
        */
    }

    void start() {
        int tentativi = 0;
        mappa.stampa();

        std::cout << "Hai 10 tentativi per colpire tutte le navi nemiche!" << std::endl;
        do {
            requestBombDrop();
            mappa.stampa();
            //boats.stampa();
        } while(!tentativiEsauriti(++tentativi) && !isGameOver());
    }

    bool isGameOver() {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (boats.get(i,j)==SHIP)
                    return false;
            }
        }
        return true;
    }

    bool tentativiEsauriti(int tentativi) {
        if (tentativi == 10) {
            std::cout << "Hai esaurito i tentativi" << std::endl;
            return true;
        }
        std::cout << "Tentativi rimasti: " << 10 - tentativi << std::endl;
        return false;
    }

    bool requestBombDrop() {
        std::cout << "Dove vuoi lanciare la bomba? ";
        int x, y;
        std::cin >> x;
        std::cin >> y;

        while (x <= 0 || x > N || y <= 0 || y > N) {
            std::cout << "Coordinate non valide" << std::endl;
            std::cout << "Dove vuoi lanciare la bomba? ";
            std::cin >> x;
            std::cin >> y;
        }

        x--;
        y--;
        
        if (boats.get(x, y) == SHIP) {
            mappa.put(x, y, HIT);
            boats.put(x, y, HIT);
        } else
            mappa.put(x, y, MISS);
        
        return true;
    }
};