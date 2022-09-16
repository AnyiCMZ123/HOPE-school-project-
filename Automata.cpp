//Instituto Politecnico Nacional 
//Materia: Teoria de automatas  
//Automata finito no determinista 
//Alumno:
//Castillo Martinez Angela Belen 


#include <iostream>
#include <string>

using namespace std;

bool validarCamino(string, int, char, string);

int main() {
  while (true) {
    cout << "Ingresa la cadena: \n";
    string cadena;
    cin >> cadena;
    validarCamino(cadena, 0, 'p', "") ? cout << "Es valida"
                                      : cout << "No es valida";
    cout << endl;
  }
  return 0;
}

// estado p: hacia q  (a)
// estado q: hacia q, hacia r (a)
// estado r: hacia r (b)

bool validarCamino(string cadena, int posicion, char estado, string caminito) {

  if (posicion != cadena.size() - 1) {
    caminito.push_back(estado);
    cout << caminito << endl;
  }

  if (estado == 'r' and posicion >= cadena.size())
    return true;
  if (estado == 'p' and cadena[posicion] == 'a')
    return validarCamino(cadena, posicion + 1, 'q', caminito);

  if (estado == 'q' and cadena[posicion] == 'a')
    return validarCamino(cadena, posicion + 1, 'q', caminito) or
           validarCamino(cadena, posicion + 1, 'r', caminito);

  if (estado == 'r' and cadena[posicion] == 'b')
    return validarCamino(cadena, posicion + 1, 'r', caminito);

  return false;
}
