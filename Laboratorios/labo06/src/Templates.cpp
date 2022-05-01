#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
int cuadrado(int x) {
  return x * x;
}

// Ejercicio 2: Pasar a templates
bool contiene(string s, char c) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor

// Ejercicio 4: Función maximo con un template contenedor y uno elemento
