// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

char intToChar(int n) {
    char c = 'a' + n;

    return c;
}

void generarCombinaciones(int n, int k, std::string actual, std::vector<std::string>& resultados) {
    if (actual.length() == k) {
        resultados.push_back(actual);
        return;
    }

    for (int i = 0; i < n; i++) {
        //comprobar si el caracter no está ya en la cadena
        if (actual.find(intToChar(i)) != string::npos) continue;

        generarCombinaciones(n, k, actual + intToChar(i), resultados);
    }
}

// Función principal para resolver el problema
std::string resolver(int n, int k) {
    std::vector<std::string> combinaciones;
    generarCombinaciones(n, k, "", combinaciones);

    std::string resultado;
    for (const std::string& combinacion : combinaciones) {
        resultado += combinacion + "\n";
    }

    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    if (! std::cin)
        return false;
    
    int n, k;

    cin >> n >> k;

    string sol = resolver(n, k);
    
    // escribir sol
    cout << sol << endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #define DOMJUDGE
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}