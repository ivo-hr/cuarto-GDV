
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

template <class T>
int esHoja(bintree<T> const& tree) {
    if (tree.empty()) return false;
    if (tree.left().empty() && tree.right().empty()) return true;
    else return false;
}

using GrupoEnanos = pair<string,int>; // <Nombre del lider, nº de enanos que forman el grupo>

// función recursiva que resuelve el problema
GrupoEnanos enanos(const bintree<string>& a) {
    if (a.empty()) return {"Ninguno", 0};
    if (esHoja(a)) return {a.root(), 1};

    auto [liderIz, tamIz]  = enanos(a.left());
    auto [liderDr, tamDr] = enanos(a.right());
    string nuevoLider;
    if (tamIz > tamDr) nuevoLider = liderIz;
    else if (tamDr > tamIz) nuevoLider = liderDr;
    else nuevoLider = min(liderIz, liderDr);
    int nuevoTam = tamIz + tamDr;
    if (a.root() == "Orcos") nuevoTam = nuevoTam/2;
    if (nuevoTam == 0) nuevoLider = "Ninguno";
    return {nuevoLider, nuevoTam};
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    GrupoEnanos sol;
    bintree<string> a = leerArbol(string("."));
    sol = enanos(a);
    if (sol.second == 0) cout << "Ninguno" << endl;
    else cout << sol.first << " " << sol.second << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("../Tema6/datos.txt");
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