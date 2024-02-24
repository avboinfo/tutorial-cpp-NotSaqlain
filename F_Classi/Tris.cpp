#include <iostream>
#include <string>

using namespace std;

class Tris{
public:
    char griglia[3][3];

    void reset_tabella(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j] = ' ';
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

        if (griglia[x][y] != ' ')
            return false;

        griglia[x][y] = 'X';
        return true;
    }

    bool giocatore_due(int x, int y) {
        if (x > 2 || x < 0 || y > 2 || y < 0)
            return false;

        if (griglia[x][y] != ' ')
            return false;

        griglia[x][y] = 'O';
        return true;
    }

    char controlla_vincitore() {
        for (int i = 0; i < 3; i++) {
            if (controlla_collonna(i) != ' ') return controlla_collonna(i);
            if (controlla_riga(i) != ' ') return controlla_riga(i);
            if (controlla_diagonali() != ' ') return controlla_diagonali();
        }   

        return ' ';
    }

private:
    char controlla_collonna(int col) {
        char cella = griglia[0][col];
        if (cella != ' ') {
            if (griglia[1][col] == cella && griglia[2][col] == cella) return cella;
        }
        return ' ';
    }

    char controlla_riga(int riga) {
        char cella = griglia[riga][0];
        if (cella != ' ') {
            if (griglia[riga][1] == cella && griglia[riga][2] == cella) return cella;
        }
        return ' ';
    }

    char controlla_diagonali() {
        char cella = griglia[0][0];
        if (cella != ' ') {
            if (griglia[1][1] == cella && griglia[2][2] == cella) return cella;
        }

        cella = griglia[0][2];
        if (cella != ' ') {
            if (griglia[1][1] == cella && griglia[2][0] == cella) return cella;
        }

        return ' ';
    }
};

int main(int argc, char const *argv[]) {
    Tris myTris;
    myTris.reset_tabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;
    int mosse_totali = 0;

    while (mosse_totali < 9) {
        do {
            cout << "Giocatore 1:" << endl;
            cout << "X e Y: ";
            cin >> x >> y;
        } while (!myTris.giocatore_uno(y, x));
        mosse_totali++;

        myTris.stampa_griglia();

        if (myTris.controlla_vincitore()!= ' ')
            break;

        if (mosse_totali == 9) break;

        do {
            cout << "Giocatore 2:" << endl;
            cout << "X e Y: ";
            cin >> x >> y;
        } while (!myTris.giocatore_due(y, x));
        mosse_totali++;

        myTris.stampa_griglia();

        if (myTris.controlla_vincitore() != ' ') break;
    }

    if (myTris.controlla_vincitore() == 'X') cout << "Il giocatore 1 ha vinto!" << endl;
    else if (myTris.controlla_vincitore() == 'O') cout << "Il giocatore 2 ha vinto!" << endl;
    else cout << "Pareggio!" << endl;

    return 0;
}