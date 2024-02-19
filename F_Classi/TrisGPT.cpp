#include <iostream>
#include <vector>

using namespace std;

class Tris {
private:
  vector<vector<char>> _casella;
  bool _turnoGiocatore;

public:
  Tris() {
    _casella.resize(3, vector<char>(3, ' '));
    _turnoGiocatore = true;
  }

  void stampa() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << _casella[i][j] << ".";
      }
      cout << endl;
    }
  }

  bool gioca(int x, int y) {
    if (_casella[x][y] != ' ') {
      return false;
    }

    _casella[x][y] = _turnoGiocatore ? 'X' : 'O';
    _turnoGiocatore = !_turnoGiocatore;

    return true;
  }

  bool controllaVincitore() {
    // Controlla righe
    for (int i = 0; i < 3; i++) {
      if (_casella[i][0] == _casella[i][1] && _casella[i][1] == _casella[i][2] && _casella[i][0] != ' ') {
        return true;
      }
    }

    // Controlla colonne
    for (int i = 0; i < 3; i++) {
      if (_casella[0][i] == _casella[1][i] && _casella[1][i] == _casella[2][i] && _casella[0][i] != ' ') {
        return true;
      }
    }

    // Controlla diagonali
    if (_casella[0][0] == _casella[1][1] && _casella[1][1] == _casella[2][2] && _casella[0][0] != ' ') {
      return true;
    }
    if (_casella[0][2] == _casella[1][1] && _casella[1][1] == _casella[2][0] && _casella[0][2] != ' ') {
      return true;
    }

    return false;
  }

  bool isPieno() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (_casella[i][j] == ' ') {
          return false;
        }
      }
    }
    return true;
  }
};



int main() {
  Tris gioco;

  while (true) {
    gioco.stampa();

    int x, y;
    cout << "Inserisci la tua mossa (riga, colonna): ";
    cin >> x >> y;

    if (!gioco.gioca(x - 1, y - 1)) {
      cout << "Mossa non valida!" << endl;
      continue;
    }

    if (gioco.controllaVincitore()) {
      gioco.stampa();
      cout << "Hai vinto!" << endl;
      break;
    }

    if (gioco.isPieno()) {
      gioco.stampa();
      cout << "Pareggio!" << endl;
      break;
    }
  }

  return 0;
}
