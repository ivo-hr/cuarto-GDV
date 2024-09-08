
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <climits>
using namespace std;


template <class T>
bool Busq(bintree<T> const &tree, int& min, int& max){
    if (tree.empty() ||
        (tree.right().empty() && tree.left().empty())) return true;
    else {
        int minL, maxL, minR, maxR;
        bool lef = true, rig = true;

        if (!tree.left().empty()) {
            minL = tree.left().root();
            maxL = tree.left().root();
            lef = Busq(tree.left(), minL, maxL);
            if (lef && minL < tree.root()) min = minL;
            else if (lef && maxL > tree.root()) max = maxL;
        }
        if (!tree.right().empty()) {
            minR = tree.right().root();
            maxR = tree.right().root();
            rig = Busq(tree.right(), minR, maxR);
            if (rig && minR < tree.root()) min = minR;
            else if (rig && maxR > tree.root()) max = maxR;
        }
        if (!lef || !rig) return false;

        return (tree.left().empty() || tree.root() > maxL) &&
            (tree.right().empty() || tree.root() < minR);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int c = 0, k = 0;
    if (tree.empty()) cout << "SI" << endl;
    else if (Busq(tree, c, k)) cout << "SI" << endl;
    else cout << "NO" << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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
