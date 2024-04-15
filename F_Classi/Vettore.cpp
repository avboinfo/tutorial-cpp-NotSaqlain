#include <iostream>

using namespace std;

class Vettore {
protected:
    int dim, len, delta;
    int * v;

public:
    Vettore(int d) {
        dim = d;
        len = 0;
        delta = 10;
        v = new int[dim];
    }

    void add(int x) {
        if (len == dim) {
            int * nuovo = new int[dim+delta];
            cout << "Vettore pieno" << endl;
            for (int i = 0; i < len; i++) {
                nuovo[i] = v[i];
            }
            dim += delta;
            v = nuovo;
        }
        
        v[len] = x;
        len++;
    }

    void print() {
        cout << "Vettore: ";
        for (int i = 0; i < len; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Vettore v(10);
    
    for (int i = 0; i < 15; i++) {
        v.add(33*i);
    }
    v.print();

    return 0;
}