#include <iostream>
#include <cstdlib>
#include <ctime>

class mastermind {
private:
    int numero_mosse;
    std::string ultima_mossa;
    static const int DIM_MOSSA_VALIDA = 4;
    int mossa_valida[DIM_MOSSA_VALIDA];
    int codice_segreto[DIM_MOSSA_VALIDA];

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
        }
        return true;
    }

    void genera_codice() {
        srand(time(NULL));
        for (int i = 0; i < DIM_MOSSA_VALIDA; i++) {
            codice_segreto[i] = rand() % 10;
        }
    }

public:
    mastermind() {
        numero_mosse = 0;
        ultima_mossa = "";
        genera_codice();
    }

    void nuova_giocata() {
        std::cout << numero_mosse + 1 << "° Giocata" << std::endl;
        
        do {
            std::cout << numero_mosse + 1 << ": ";
            std::getline(std::cin, ultima_mossa); // [std::cin >> ultima_mossa;] non funziona con gli spazi
        } while (!sanifica_input());

        numero_mosse++;
    }

    void risultato_mossa() {
        int ball = 0;   // Posizione sbagliata;
        int strike = 0; // Posizione giusta

        for (int i = 0; i < DIM_MOSSA_VALIDA; i++) {
            if (mossa_valida[i] == codice_segreto[i]) {
                strike++;
            } else {
                for (int j = 0; j < DIM_MOSSA_VALIDA; j++) {
                    if (mossa_valida[i] == codice_segreto[j]) {
                        ball++;
                    }
                }
            }
        }
        
        std::cout << "Strike: " << strike << " Ball: " << ball << std::endl;
        if (strike == DIM_MOSSA_VALIDA) {
            std::cout << "Hai vinto!" << std::endl;
        }
    }

};
