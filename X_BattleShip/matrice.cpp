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
                m[i][j] = rand() % 10;
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
                printf("%2d ", m[i][j]);
                //cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------------\n";
    }
};

int main() {
    srand(time(NULL));
    matrice m(9);
    matrice n;
    n.stampa();
    m.stampa();
    return 0;
}