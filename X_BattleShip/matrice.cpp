/*
    Saqlain Khalid
    matrice.cpp
    13/04/2024
    questo file contiene la definizione delle funzioni della classe matrice
*/

#include <iostream>

using namespace std;

const int N = 10;

class matrice {
private:    
    int m[N][N];

public:
    matrice() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                m[i][j] = 97 + rand() % 26;
    }
    matrice(int n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[i][j] = n;
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

    void bomb(){
        int x = rand() % N;
        int y = rand() % N;
        m[x][y] = '*';
    }

    void placeShip(int x, int y){
        m[x][y] = 'S';
    }
};

int main() {
    srand(time(NULL));
    matrice m('-');
    matrice n;
    m.stampa();
    for (int i = 0; i < 10; i++){
        n.bomb();
    }
    n.stampa();
    return 0;
}