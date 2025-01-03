
/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no: 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int charToInt(char c) {
    return c - '0';
}

char intToChar(int i) {
    return i + '0';
}

char resolver(const vector<char>& sec, const char prim, const char ult, int ini = 0, int fin = -1) {
    // Inicializar fin
    if (fin == -1) fin = sec.size() - 1;

    // Chequear si se puede usar el rango
    if (ini > fin) return '!';

    // Condición base: si queda un solo elemento
    if (ini == fin) {
        int esperado = charToInt(prim) + ini;
        if (charToInt(sec[ini]) != esperado) {
            return intToChar(esperado);
        }
        // Si se da el caso que hay que comparar con el último
        if (ini == sec.size() - 1) {
            if (charToInt(ult) != esperado) {
                return ult;
            }
        }
        return '!';
    }

    int mitad = ini + (fin - ini) / 2;
    int esperadoMitad = charToInt(prim) + mitad;

    // Dividir según donde falte el elemento
    if (charToInt(sec[mitad]) != esperadoMitad) {
        // Falta en la mitad izquierda
        return resolver(sec, prim, ult, ini, mitad);
    } else {
        // Falta en la mitad derecha
        return resolver(sec, prim, ult, mitad + 1, fin);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char prim, ult, n;
    cin >> prim >> ult;
    n = ult-prim;
    vector<char> sec(n);
    for (char& e : sec) cin >> e;
    cout << resolver(sec, prim, ult) << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}