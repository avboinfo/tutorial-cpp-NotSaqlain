/*
    Saqlain Khalid
    matrice.cpp
    13/04/2024
    questo file contiene la definizione delle funzioni della classe matrice
*/

#include <iostream>

using namespace std;

class matrice {
private:
    int m[10][10];

public:
    matrice() {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                m[i][j] = 0;
    }

    void stampa() {
        cout << "----- Matrice -----\n";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    matrice m;
    m.stampa();
    return 0;
}