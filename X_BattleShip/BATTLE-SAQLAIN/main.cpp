#include <iostream>
#include "BattleShip.cpp"

using namespace std;

int main() {
    srand(time(NULL));
    //cout << "Hai 10 tentativi per colpire tutte le navi nemiche!" << endl;
    cout << "------- BATTLESHIP GAME -------" << endl;
    BattleShip gioco = BattleShip();
    gioco.start();
    cout << "GAME OVER!" << endl;

}