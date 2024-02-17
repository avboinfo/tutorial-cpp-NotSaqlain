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
    int griglia[3][3];

    void reset_tabella(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j]=0;
            }
        }
    }

    void stampa_griglia(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << griglia[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool giocatore_uno(int x, int y){
        if (x < 0 || x > 2){
            return false;
        }

        if (y < 0 || y > 2){
            return false;
        }

        if (griglia[x][y] == 1 || griglia[x][y] == 2){
            return false;
        }
        griglia[x][y] = 1;
        return true;
    }

    bool giocatore_due(int x, int y){
        if (x < 0 || x > 2){
            return false;
        }

        if (y < 0 || y > 2){
            return false;
        }

        if (griglia[x][y] == 1 || griglia[x][y] == 2){
            return false;
        }
        griglia[x][y] = 2;
        return true;
    }

};

int main(int argc, char const* argv[]){

    Tris myTris;

    myTris.reset_tabella();

    cout << "Griglia iniziale" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;

    do {
        cout << "Giocatore 1: Inserisci le coordinate della tua mossa" << endl;
        cout << "Inserisci la coordinata x: ";
        cin >> x;
        cout << "Inserisci la coordinata y: ";
        cin >> y;
        mossa_valida = myTris.giocatore_uno(x, y);
    } while (!mossa_valida);

    cout << "Griglia dopo la mossa" << endl;
    myTris.stampa_griglia();

    do {
        cout << "Giocatore 2: Inserisci le coordinate della tua mossa" << endl;
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        mossa_valida = myTris.giocatore_due(x, y);
    } while (!mossa_valida);

    cout << "Griglia dopo la mossa" << endl;
    myTris.stampa_griglia();

    return 0;
}