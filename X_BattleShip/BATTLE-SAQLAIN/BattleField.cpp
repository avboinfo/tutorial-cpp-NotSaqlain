/*
    Saqlain Khalid
    BattleField.cpp
    19/04/2024
    questo file contiene la definizione delle funzioni della classe BattleField
*/

#include <iostream>

const int N = 6;
const char SHIP = 'X';
const char MISS = '.';
const char HIT = '*';
const char VOID = ' ';

class BattleField {

private:
    char m[N][N];

public:
    BattleField() {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                m[i][j] = 97 + rand()%26;        
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
   void stampa_griglia(){
        cout << "⚝──⭒──⭑──⭒──⚝\n"; 
        for (int i = 0; i < 3; i++) { 
            cout << "┋ "; 
            for (int j = 0; j < 3; j++) { 
                cout << griglia[i][j] << " ┋ "; 
            } 
            cout << "\n⚝──⭒──⭑──⭒──⚝\n"; 
        } 

    }

    void stampa() {
        std::cout << "----------------- BattleField -----------------\n";
        for (int i = 0; i < N + 2; i++) {
            if (i == 0 || i == N + 1) {
                // Print top and bottom external borders
                std::cout << "+";
                for (int k = 0; k < N; ++k)
                    std::cout << " - ";
                std::cout << " +" << std::endl;
            } else {
                // Print internal rows with borders
                std::cout << "|";
                for (int j = 0; j < N; j++) {
                    if (j == 0 || j == N - 1) {
                        // Print vertical internal borders
                        std::cout << " " << m[i - 1][j] << " |";
                    } else {
                        std::cout << " " << m[i - 1][j] << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
        std::cout << "------------------------------------------------\n";
    }
    */

};