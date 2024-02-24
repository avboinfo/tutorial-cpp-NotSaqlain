#include <iostream>
#include <string>

using namespace std;

/* 
se in griglia c'e' ZERO cella vuota
se in griglia c'e' UNO stiamo parlando di una X o (giocatore 1)
se in griglia c'e' DUE stiamo parlando di un CERCHIO (giocatore 2)
*/

class Tris{
public:
    char griglia[3][3];

    void reset_tabella(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j] = '-';
            }
        }
    }

    void stampa_griglia(){
        cout << "⚝──⭒──⭑──⭒──⚝\n"; 
        for (int i = 0; i < 3; i++) { 
            cout << "┋ "; 
            for (int j = 0; j < 3; j++) { 
                cout << griglia[i][j] << " ┋ "; 
            } 
            cout << "\n⚝──⭒──⭑──⭒──⚝\n"; 
        } 

    }

    bool giocatore_uno(int x, int y) {
        if (x > 2 || x < 0 || y > 2 || y < 0)
            return false;

        if (griglia[x][y] != '-')
            return false;

        griglia[x][y] = 'X';
        return true;
    }

    bool giocatore_due(int x, int y) {
        if (x > 2 || x < 0 || y > 2 || y < 0)
            return false;

        if (griglia[x][y] != '-')
            return false;

        griglia[x][y] = 'O';
        return true;
    }

    char controlla_vincitore() {
        char risultato;
        for (int i = 0; i < 3; i++) {
            risultato = controlla_collonna(i);
            if (risultato != '-')
                return risultato;

            risultato = controlla_riga(i);
            if (risultato != '-')
                return risultato;
        }

        risultato = controlla_diagonali();
        if (risultato != '-')
            return risultato;

        return '-';
    }

private:
    char controlla_collonna(int col) {
        char cella = griglia[0][col];
        if (cella != '-') {
            if (griglia[1][col] == cella && griglia[2][col] == cella)
                return cella;
        }
        return '-';
    }

    char controlla_riga(int riga) {
        char cella = griglia[riga][0];
        if (cella != '-') {
            if (griglia[riga][1] == cella && griglia[riga][2] == cella)
                return cella;
        }
        return '-';
    }

    char controlla_diagonali() {
        char cella = griglia[0][0];
        if (cella != '-') {
            if (griglia[1][1] == cella && griglia[2][2] == cella)
                return cella;
        }

        cella = griglia[0][2];
        if (cella != '-') {
            if (griglia[1][1] == cella && griglia[2][0] == cella)
                return cella;
        }

        return '-';
    }
};

int main(int argc, char const *argv[]) {
    Tris myTris;
    myTris.reset_tabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;
    char vincitore = '-';
    int mosse_totali = 0;

    while (mosse_totali < 9) {
        do {
            cout << "Mossa del giocatore 1 (X)." << endl;
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            mossa_valida = myTris.giocatore_uno(y, x);
        } while (!mossa_valida);

        myTris.stampa_griglia();
        vincitore = myTris.controlla_vincitore();
        if (vincitore != '-')
            break;

        mosse_totali++;

        if (mosse_totali == 9)
            break; // Controllo per parità

        do {
            cout << "Mossa del giocatore 2 (O)." << endl;
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            mossa_valida = myTris.giocatore_due(y, x);
        } while (!mossa_valida);

        myTris.stampa_griglia();
        vincitore = myTris.controlla_vincitore();
        if (vincitore != '-')
            break;

        mosse_totali++;
    }

    if (vincitore == 'X')
        cout << "Vince giocatore 1 (X)!" << endl;
    else if (vincitore == 'O')
        cout << "Vince giocatore 2 (O)!" << endl;
    else
        cout << "Pareggio!" << endl;

    return 0;
}