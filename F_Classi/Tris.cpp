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

};

int main(int argc, char const* argv[]){

    Tris myTris;

    myTris.reset_tabella();

    return 0;
}