#include <iostream> 
#include <string>

using namespace std;

class mastermind {
    int cella[4];
    int ball = 0;   // Posizione sbagliata;
    int strike = 0; // Posizione giusta

    mastermind(int a, int b, int c, int d) {
        cella[0] = a;
        cella[1] = b;
        cella[2] = c;
        cella[3] = d;
    }

};

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    mastermind m(a, b, c, d);
    return 0;
}