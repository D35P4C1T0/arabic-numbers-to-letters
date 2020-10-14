#include <iostream>
#include <map>
using namespace std;

/*
    Il numero '1234' viene colmato degli zeri che gli manca per arrivare a
    12 cifre, perchè la scelta è stata di arrivare fino al miliardo e fermarmi.
    La funzione che lo converte in un numero in parole è una e una sola, ma
    contiene in essa chiamate ad altre funzioni cuscinetto che si prendono
    la responsabilità di convertire decine e centinaia "a cascata", visto che
    i numeri in parole spesso si ripetono.
 */

string decine(string input) {
  // input dovrebbe essere una stringa da 2 caratteri

  if (input.length() != 2) {
    return "[lunghezza input decine nelle decine]";
  }

  string decina(1, input.at(0));
  string unit(1, input.at(1));

  string out = "[problema nelle decine]";

  map<string, string> map0to9{
      {"0", "zero"},     {"01", "uno"},    {"02", "due"}, {"03", "tre"},
      {"04", "quattro"}, {"05", "cinque"}, {"06", "sei"}, {"07", "sette"},
      {"08", "otto"},    {"09", "nove"}};

  map<string, string> map10to19{{"10", "dieci"},       {"11", "undici"},
                                {"12", "dodici"},      {"13", "tredici"},
                                {"14", "quattordici"}, {"15", "quindici"},
                                {"16", "sedici"},      {"17", "diciassette"},
                                {"18", "diciotto"},    {"19", "diciannove"}};

  map<string, string> map20to90{{"2", "venti"},    {"3", "trenta"},
                                {"4", "quaranta"}, {"5", "cinquanta"},
                                {"6", "sessanta"}, {"7", "settanta"},
                                {"8", "ottanta"},  {"9", "novanta"}};

  if (decina == "0") {
    return map0to9["0" + unit];
    // sette
  }
  if (decina == "1") {
    return map10to19[input];
    // diciassette
  }
  if (decina != "0" && unit != "0") {
    return map20to90[decina] + map0to9["0" + unit];
    // trentasette
  }
  if (decina != "0" && unit == "0") {
    return map20to90[decina];
    // trenta
  }

  return out;
}

string centinaia(string input) {
  // input dovrebbe essere una stringa da 3 cifre

  if (input.length() != 3) {
    return "[problema nelle centinaia]";
  }

  string centinaia(1, input.at(0));
  string restante = input.substr(1, 2);

  string out = "problema";

  if (centinaia == "0") {
    return decine(restante);
    // ventisette
  }
  if (centinaia != "1") {
    return decine("0" + centinaia) + "cento" + decine(restante);
    // trecentoventisette
  }
  if (centinaia == "1") {
    return "cento" + decine(restante);
    // centoventisette
  }
  return out;
}

string migliaia(string input) {
  // input dev'essere una stringa da 6 caratteri

  // * * * * * *

  string tipoDiMigliaia = input.substr(0, 3);
  string restante = input.substr(3, 3);

  string out = "[problema nelle centinaia]";

  if (tipoDiMigliaia == "000") {
    return centinaia(restante);
  }
  if (tipoDiMigliaia != "001") {
    return centinaia(tipoDiMigliaia) + "mila" + centinaia(restante);
    // trecentomiladuecentoventi, oppure ventimiladuecentoventi
  }
  if (tipoDiMigliaia == "001") {
    return "mille" + centinaia(restante);
    // milletrecentoventi
  }
  return out;
}

string milioni(string input) {
  // input di 9 cifre

  // * * * * * * * * *

  string tipoDiMilione = input.substr(0, 3);
  string restante = input.substr(3, 6);

  string out = "[problema nei milioni]";

  if (tipoDiMilione == "000") {
    return migliaia(restante);
  }

  if (tipoDiMilione != "001") {
    return centinaia(tipoDiMilione) + "milioni" + migliaia(restante);
    // venti milioni trecentomila
  }
  if (tipoDiMilione == "001") {
    return "un milione" + migliaia(restante);
    // un milione trecento mila
  }
  return out;
}

string miliardi(string input) {
  // input di 12 cifre
  string tipoDiMiliardi = input.substr(0, 3);
  string restante = input.substr(3, 9);

  string out = "[problema nei miliardi]";

  if (tipoDiMiliardi == "000") {
    return milioni(restante);
  }

  if (tipoDiMiliardi != "001") {
    return centinaia(tipoDiMiliardi) + "miliardi" + milioni(restante);
  }
  if (tipoDiMiliardi == "001") {
    return "un miliardo" + milioni(restante);
  }
  return out;
}

// Utils

bool is_digits(const std::string &str) {
  return str.find_first_not_of("0123456789") == std::string::npos;
}

string prepare(string input) {
  int delta = 12 - input.length();
  // per arrivare a 12 cifre
  string out = "";
  for (int i = 0; i < delta; i++) {
    out += "0";
  }
  out += input;
  return out;
}

string numberToLetter(string input) { return miliardi(prepare(input)); }
