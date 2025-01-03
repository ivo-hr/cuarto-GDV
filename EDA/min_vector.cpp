#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin) {
    //cuando quede un solo elemento, será el mayor, lo que significa que el punto de inflexión es el elemento anterior
    //si el punto de inflexión es el primer elemento, devolvemos el último
    if (fin == ini){
        if (ini == 0)
            return sec[sec.size() - 1];
        else
            return sec[ini - 1];
    }
    else {
        int mitad = (ini + fin) / 2;
        
        //si esto se  cumple, punto de inflexion a la izquierda
        if (sec[mitad] <= sec[fin])
            return minimo(sec, mitad + 1, fin);
        //si esto se cumple, punto de inflexion a la derecha
        else
            return minimo(sec, ini, mitad);
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
    cout << minimo(sec, 0, n - 1) << endl;
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