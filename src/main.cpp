#include <iostream>
#include <map>

#include "numeriparole.h"
using namespace std;

int main() {
  string numero;
  cout << "Inserisci un numero: ";
  cin >> numero;
  if (is_digits(numero)) {
    string risultato = numberToLetter(numero);
    cout << risultato.c_str();
  }
  return 0;
}
