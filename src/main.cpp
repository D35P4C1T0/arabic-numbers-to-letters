#include "numeriparole.h"
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
  string numero(argv[1]);
  if (is_digits(numero)) {
    string risultato = numberToLetter(numero);
    printf("%s\n", risultato.c_str());
  }
  return 0;
}