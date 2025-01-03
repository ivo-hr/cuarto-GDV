#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin) {
    if (ini == fin - 1) {
        // Caso base: un solo elemento
        return sec[ini];
    }

    int mid = (ini + fin) / 2;

    // Verificamos el punto medio
    if ((mid == 0 || sec[mid] < sec[mid - 1]) &&
        (mid == sec.size() - 1 || sec[mid] < sec[mid + 1])) {
        return sec[mid];
    } else if (mid > 0 && sec[mid - 1] < sec[mid]) {
        // Mínimo está en la mitad izquierda
        return minimo(sec, ini, mid);
    } else {
        // Mínimo está en la mitad derecha
        return minimo(sec, mid + 1, fin);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << minimo(sec,0,n) << endl;
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
    //system("PAUSE");
#endif

    return 0;
}