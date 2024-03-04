#include <iostream>

using namespace std;

class Vettore {
protected:
    int dim, len;
    int * v;

public:
    Vettore(int d) {
        dim = d;
        len = 0;
        v = new int[dim];
    }

    void add(int x) {
        if (len == dim) {
            cout << "Vettore pieno" << endl;
            return;
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
    v.add(5);
    v.add(3);
    v.add(7);
    v.print();

    return 0;
}