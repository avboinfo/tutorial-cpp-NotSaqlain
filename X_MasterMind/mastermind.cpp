#include <iostream>
#include <cstdlib>
#include <ctime>

class mastermind {
private:
    std::string ultima_mossa;
    int numero_mosse;
    bool hai_vinto;
    static const int NUMERO_MASSIMO_MOSSE = 9;
    static const int DIM_MOSSA_VALIDA = 4;
    int mossa_valida[DIM_MOSSA_VALIDA];
    int codice_segreto[DIM_MOSSA_VALIDA];

     bool sanifica_input() {
        if (DIM_MOSSA_VALIDA != ultima_mossa.size())
            return false;
        for(int i = 0; i < ultima_mossa.size(); i++) {
            char c = ultima_mossa[i];

            if(c >='0' && c <= '9')
                mossa_valida[i] = c - '0';
            else if(c == '-')  // il trattino verra convertito in -1  
                mossa_valida[i]= -1;
            else
                return false;
        }
        return true;
    }

    void genera_codice() {
        srand(time(NULL));
        for (int i = 0; i < DIM_MOSSA_VALIDA; i++) {
            codice_segreto[i] = rand() % 10;
        }
    }

    int* copia_vettore(int vettore_oroginale[]) {
        static int vettore_copia[DIM_MOSSA_VALIDA];
        for (int i = 0; i < DIM_MOSSA_VALIDA; i++) {
            vettore_copia[i] = vettore_oroginale[i];
        }
        return vettore_copia;
    }
    int copia_vettore(int vettore_oroginale[], int vetore_copia[], int dim_vet) {
        for (int i = 0; i < DIM_MOSSA_VALIDA; i++) {
            vetore_copia[i] = vettore_oroginale[i];
        }
    }

public:
    mastermind() {
        numero_mosse = 0;
        ultima_mossa = "";
        hai_vinto = false;
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

        int codice_segreto_copia[DIM_MOSSA_VALIDA];
        copia_vettore(codice_segreto);
        
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
