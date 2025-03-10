
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin) {
    
    //por si acaso no hay ningun elemento
    if (ini < 0 || fin < 0 || ini > fin) return false;
    
    int mitad = (ini + fin) / 2;

    if (v[mitad] == mitad) 
        return true;
    else if (ini == fin)
        return false;
    else if (v[mitad] < mitad)
        return resolver(v, mitad + 1, fin);
    else
        return resolver(v, ini, mitad - 1);

   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << (resolver(sec,0,n - 1) ? "SI" : "NO") << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#define DOMJUDGE

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
