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
#include "bintree_eda.h"
using namespace std;


template <class T>
int descendientes(bintree<T> const& tree, int sumAntepasados, int& numSingulares) {

    //Caso base. hoja final
    if (tree.empty()) {
        return 0;
    }


    //contamos el numero de descendientes
    int sumDescendientes = 0;
    //if (!tree.left().empty())
    sumDescendientes += descendientes(tree.left(), sumAntepasados + tree.root(), numSingulares);
    //if (!tree.right().empty())
    sumDescendientes += descendientes(tree.right(), sumAntepasados + tree.root(), numSingulares);

    //Comprobamos si la suma de antepasados es igual que la suma de descendientes
    if (sumAntepasados == sumDescendientes)
        numSingulares++;

    //Devolvemos la suma de descendientes, incluido esta raíz
    return tree.root() + sumDescendientes;



}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);

    int sumAntepasados = 0;
    int numSingulares = 0;
    int sumDescendientes = descendientes(tree, sumAntepasados, numSingulares);
    cout << numSingulares << endl;
}

#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("input2.txt");
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
