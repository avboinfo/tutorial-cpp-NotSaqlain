#include <iostream>
#include "BattleShip.cpp"

using namespace std;

bool playAgain() {
    char c;
    cout << "Vuoi giocare ancora? (s/n) ";
    cin >> c;
    return c == 's';
}

int main() {
    srand(time(NULL));
    //cout << "Hai 10 tentativi per colpire tutte le navi nemiche!" << endl;
    
    do {
        cout << "------- BATTLESHIP GAME -------" << endl;
        BattleShip game;
        game.start();
        cout << "GAME OVER!" << endl;
    } while (playAgain());

}