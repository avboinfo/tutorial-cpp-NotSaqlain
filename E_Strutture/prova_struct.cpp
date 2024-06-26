/*
** prova_struct.cpp
** Author: IAV 3CIN
** 28/02/2021
** ~ 26/02/2024
*/

#include <iostream>
#include <string>

using namespace std;

/* Il tipo di dato "struct" serve per memorizzare dati di tipi uguali o diversi
** nella stessa struttura, per poter accedere a ciascuno dei membri 
** attraverso il nome unico della struttura.
*/

struct persona {
    string nome;
    int eta;
};

int main() {
  struct persona gigi, gigietto;
  gigi.nome = "Saqlain";
  gigi.eta = 18;
  gigietto.nome = "TopG";
  gigietto.eta = 6;
  cout << "Gigi si chiama: " << gigi.nome << " e ha " << gigi.eta << " anni." << endl;
  return 0;
}

/*
typedef struct { int uno; int due; } COPPIA;
int main() {
  struct persona gigi, gigietto;
  COPPIA coppia_eta;
  coppia_eta.uno = 17;
  coppia_eta.due = 7;
  gigi.nome = "Luigi";
  gigi.eta = coppia_eta.uno;
  gigietto.nome = "Luigino";
  gigietto.eta = coppia_eta.due;
}
*/