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
    matrice(int n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[i][j] = 0;
    }

    void stampa(int n) {
        cout << "----- Matrice -----\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
        cout << "-------------------\n";
    }
};

int main() {
    matrice m(10);
    m.stampa(10);
    return 0;
}