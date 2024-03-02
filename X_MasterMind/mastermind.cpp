#include <iostream>


class mastermind {
public:
    int cella[4];
    int ball = 0;   // Posizione sbagliata;
    int strike = 0; // Posizione giusta

    mastermind() {
        std::cout << "Hello, World!";
    }

};