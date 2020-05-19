#include "numeriparole.h"
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char **argv) {
  string numero = "";
  cin >> numero;

  if (numero.length() > 12) {
    cout << "Numero troppo grande"
         << "\n";
    return 0;
  }

  numero = prepare(numero);
  string risultato = miliardi(numero);
  printf("%s\n", risultato.c_str());
  return 0;
}
