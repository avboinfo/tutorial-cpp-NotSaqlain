#include <iostream>
#include "BattleShip.cpp"
using namespace std;

int main() {

    cout << "BATTLESHIP GAME" << endl;
    BattleShip gioco = BattleShip();
    gioco.play();
    cout << "GAME OVER!" << endl;

}