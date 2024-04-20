/*
    Saqlain Khalid
    matrice.cpp
    13/04/2024
    questo file contiene la definizione delle funzioni della classe matrice
*/

#include <iostream>

using namespace std;

const int N = 10;
const char MISS = 'O';
const char HIT = '*';
const char VOID = '-';
const char SHIP = 'x';


class Matrice {
private:    
    int m[N][N];

public:
    Matrice() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = 97 + rand() % 26;
    }

    Matrice(int n) {
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
        cout << "----- Matrice -----\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%2c ", m[i][j]);
                //cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------------\n";
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
    Matrice mappa = Matrice( '-' );
    Matrice campo = Matrice( '.' );
    campo.placeHorizontalShip(3);
    campo.placeVerticalShip(4);
    campo.placeVerticalShip(2);
    campo.placeHorizontalShip(5);

    // lancia 20 bombe a caso
    for (int i=0; i<20; i++) {
        int x = rand() % N;
        int y = rand() % N;
        if (campo.get(x,y)=='O') mappa.put(x,y,'*'); else mappa.put(x,y,'X');
    }

    mappa.stampa();

}