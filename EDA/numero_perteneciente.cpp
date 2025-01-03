
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool elementoPerteneciente(const vector<int>& v, int ini, int fin, const int num) {
    if (ini > fin) return false;
    
    int mitad = (ini + fin) / 2;
    // Caso base
    if (v[mitad] == num) 
        return true;
    
    // miramos orden del vector

    if (v[ini] <= v[mitad]){
        if (num >= v[ini] && num <= v[mitad]) {
            return elementoPerteneciente(v, ini, mitad, num);
        }
        else {
            return elementoPerteneciente(v, mitad + 1, fin, num);
        }
    }

    else {
        if (num >= v[mitad + 1] && num <= v[fin]) {
            return elementoPerteneciente(v, mitad + 1, fin, num);
        }
        else {
            return elementoPerteneciente(v, ini, mitad, num);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int e, n, v;
    
    cin >> e;

    if (e == -1) return false;

    cin >> n;


    vector<int> sec;
    for (int i = 0; i < e; i++) {
        cin >> v;
        sec.push_back(v);

    }

    cout << (elementoPerteneciente(sec, 0, e - 1, n)? "SI" : "NO") << endl;
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