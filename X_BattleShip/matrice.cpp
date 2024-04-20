/*
    Saqlain Khalid
    BattleField.cpp
    19/04/2024
    questo file contiene la definizione delle funzioni della classe BattleField
*/

#include <iostream>

using namespace std;

const int N = 10;
const char MISS = 'O';
const char HIT = '*';
const char VOID = '-';
const char SHIP = 'x';


class BattleField {
private:    
    char m[N][N];

public:
    BattleField() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = 97 + rand() % 26;
    }

    BattleField(char n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[i][j] = n;
    }

    char get( int x, int y ) {
        return m[x][y];
    }

    void put( int x, int y, char c ) {
        m[x][y] = c;
    }

    void stampa() {
        cout << "---------- BattleField ----------\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%2c ", m[i][j]);
                //cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------\n";
    }

    void bomb() {
        int x = rand() % N;
        int y = rand() % N;
        m[x][y] = '*';
    }

    void placeHorizontalShip(int len) {
        if (len<=0 || len>=N) return;
        int x = rand() % (N);
        int y = rand() % (N-len);
        for (int i=0; i<len; i++) m[x][y+i] = 'O';
    }

    void placeVerticalShip(int len) {
        if (len<=0 || len>=N) return;
        int x = rand() % (N-len);
        int y = rand() % (N);
        for (int i=0; i<len; i++) m[x+i][y] = 'O';
    }
};

int main() {
    srand(time(NULL));
    BattleField mappa = BattleField('-');
    BattleField campo = BattleField(' ');

    cout << "- initial map -" << endl;
    mappa.stampa();

    // posizionamento navi sul campo di gioco e aggiornamento della mappa nascosta
    campo.placeHorizontalShip(3);
    campo.placeHorizontalShip(4);
    campo.placeVerticalShip(2);
    campo.placeVerticalShip(4);

    //cout << endl << "- updated map - ships placed" << endl;
    //campo.stampa(); // mappa aggiornata
    
    // lancia 20 bombe a caso
    for (int i=0; i<=20; i++) {
        int x = rand() % N;
        int y = rand() % N;
        if (mappa.get(x, y) == HIT || mappa.get(x, y) == MISS) continue;
        if (campo.get(x, y) == '-' || campo.get(x, y) == '|') {
            mappa.put(x, y, HIT);
            campo.put(x, y, HIT);
        } else mappa.put(x, y, MISS);
    }

    cout << endl << "- updated map - bombs dropped" << endl;
    mappa.stampa(); // mappa aggiornata

    return 0;
}