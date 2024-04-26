/*
    Saqlain Khalid
    BattleField.cpp
    19/04/2024
    questo file contiene la definizione delle funzioni della classe BattleField
*/

#include <iostream>

const int N = 6;
const char SHIP = 'S';
const char MISS = '-';
const char HIT = 'X';
const char VOID = ' ';

class BattleField {

private:
    char m[N][N];

public:
    BattleField() {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                m[i][j] = VOID;
    }

    BattleField(char c) {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                m[i][j] = c;
    }

    char get(int x, int y) {
        return m[x][y];
    }

    void put(int x, int y, char c) {
        m[x][y] = c;
    }

    void placeShips(int len) {
        int x, y;
        while (len > 0) {
            x = rand() % N;
            y = rand() % N;
            if (m[x][y] != SHIP) {
                m[x][y] = SHIP;
                len--;
            }
        }
    }

    void stampa() {
        std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
        for (int i = 0; i < N; i++) {
            std::cout << "┃ ";
            for (int j = 0; j < N; j++) {
                printf("%2c ┃ ", m[i][j]);
            }
            if (i != N - 1) {
                std::cout << "\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
            }
        }
        std::cout << std::endl;
        std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    }


     /*
    void placeHorizontalShip(int len) {
        if (len<=0 || len>=N){
            return;
        }

        int x = rand() % (N);
        int y = rand() % (N-len);

        for (int i=0; i<len; i++) {
            m[x][y+i] = SHIP;
        }
    }

    void placeVerticalShip(int len) {
        if (len<=0 || len>=N){
            return;
        }
        
        int x = rand() % (N-len);
        int y = rand() % (N);

        for (int i=0; i<len; i++) {
            m[x+i][y] = SHIP;
        }
    }
    */


};