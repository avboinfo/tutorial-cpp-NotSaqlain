#include <iostream>

class mastermind {
private:
    int numero_mosse;
    std::string ultima_mossa;
    static const int DIM_MOSSA_VALIDA = 4;
    int mossa_valida[DIM_MOSSA_VALIDA];
    int ball = 0;   // Posizione sbagliata;
    int strike = 0; // Posizione giusta

    bool sanifica_input() {

        if (ultima_mossa.size() != DIM_MOSSA_VALIDA) {
            return false;
        }

        for (int i = 0; i < ultima_mossa.size(); i++) {
            char c = ultima_mossa[i];

            if (c >= '0' && c <= '9') {
                mossa_valida[i] = c - '0';
            } else if (c == '-') {
                mossa_valida[i] = -1;
            } else {
                return false;

            }
            return true;
        }
        return true;
    }

public:
    mastermind() {
        numero_mosse = 0;
        ultima_mossa = "";
    }

    void nuova_giocata() {
        std::cout << numero_mosse + 1 << "° Giocata" << std::endl;
        
        do {
            std::cout << "Inserisci la tua mossa: ";
            std::getline(std::cin, ultima_mossa); // std::cin >> ultima_mossa; non funziona con gli spazi
        } while (!sanifica_input());
    }

};