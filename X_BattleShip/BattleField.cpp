/*
    Saqlain Khalid
    BattleField.cpp
    19/04/2024
    questo file contiene la definizione delle funzioni della classe BattleField
*/

#include <iostream>
using namespace std;

const int N = 10;
const char SHIP = 'X';
const char MISS = '.';
const char HIT = '*';
const char VOID = '-';

class BattleField {

private:
    char m[N][N];

public:
    BattleField() {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                m[i][j] = 97 + rand()%26;        
    }

    BattleField( char c ) {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                m[i][j] = c;
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
        for (int i=0; i<len; i++) m[x][y+i] = SHIP;
    }

    void placeVerticalShip(int len) {
        if (len<=0 || len>=N) return;
        int x = rand() % (N-len);
        int y = rand() % (N);
        for (int i=0; i<len; i++) m[x+i][y] = SHIP;
    }

};