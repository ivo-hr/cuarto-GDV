#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función recursiva que genera y valida los números polidivisibles
void generarPolidivisibles(string numero, int maxDigitos) {
    int longitud = numero.length();
    
    // Verificamos si el número actual cumple con las condiciones
    for (int i = 1; i <= longitud; i++) {
        int subNum = stoi(numero.substr(0, i));
        if (subNum % i != 0) {
            return; // Si no es divisible, terminamos esta rama de la recursión
        }
    }
    
    // Si el número es polidivisible, lo imprimimos
    cout << numero << endl;

    // Si no hemos alcanzado el máximo número de dígitos, seguimos generando
    if (longitud < maxDigitos) {
        for (char dig = '0'; dig <= '9'; dig++) {
            generarPolidivisibles(numero + dig, maxDigitos);
        }
    }
}

// Función que maneja cada caso de prueba
void resuelveCaso() {
    long long N;
    int D;
    
    // Leer el caso de prueba (N y D)
    cin >> N >> D;
    
    // Convertir N a string y generar todos los números polidivisibles
    string raizStr = to_string(N);
    generarPolidivisibles(raizStr, D);
    
    // Imprimir la separación de casos
    cout << "---" << endl;
}

int main() {
    // Para la entrada por fichero. Comentar para aceptar el reto
// #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); // Redirigir std::cin a datos.txt
// #endif

    int numCasos;
    std::cin >> numCasos;
    
    // Resolver todos los casos
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Restaurar la entrada estándar. Comentar para aceptar el reto
// #ifndef DOMJUDGE
//     std::cin.rdbuf(cinbuf); // Restaurar el flujo original de entrada
//     //system("PAUSE"); // Si quieres hacer una pausa en Windows, puedes descomentar esto
// #endif

    return 0;
}
