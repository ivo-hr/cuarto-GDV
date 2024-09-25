/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cmath>

#include <climits>
using namespace std;

#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 La solución se basa en recorrer el árbol verificando si es balanceado.
 Un árbol es AVL si para todos los nodos, la diferencia de alturas entre
 el hijo izquierdo y el hijo derecho es como máximo 1.

 En el caso de los árboles de palabras, convertimos cada palabra a su 
 correspondiente valor numérico antes de realizar las operaciones. 
 Para ello, se utiliza una función que convierte las palabras de números 
 escritos en español a sus equivalentes en enteros.

 La estrategia consiste en hacer un recorrido postorden del árbol para,
 en cada nodo, calcular la altura y comprobar si está balanceado. Se
 utilizan funciones recursivas que, al mismo tiempo que calculan la
 altura de un nodo, determinan si su subárbol es AVL.

 El coste de la solución es lineal, O(n), donde n es el número de nodos
 del árbol, ya que visitamos cada nodo una sola vez.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

// Función auxiliar para convertir palabras de números a enteros
int palabra_a_numero(const std::string& palabra) {
    static std::unordered_map<std::string, int> palabras_a_numeros = {
        {"uno", 1}, {"dos", 2}, {"tres", 3}, {"cuatro", 4}, {"cinco", 5},
        {"seis", 6}, {"siete", 7}, {"ocho", 8}, {"nueve", 9}, {"diez", 10},
        {"once", 11}, {"doce", 12}, {"trece", 13}, {"catorce", 14}, {"quince", 15}
        // Puedes agregar más palabras si es necesario
    };

    auto it = palabras_a_numeros.find(palabra);
    if (it != palabras_a_numeros.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Palabra de número desconocida: " + palabra);
    }
}

bool inEquil(bintree<int> const& tree, int& height, int min, int max) {

    if (!tree.empty()) {
        int lHei, rHei;

        bool lEq, rEq;

        lEq = inEquil(tree.left(), lHei, min, tree.root());
        rEq = inEquil(tree.right(), rHei, tree.root(), max);

        if (lHei < rHei) height = rHei;
        else height = lHei;
        height++;

        return (lEq && rEq &&
            (tree.root() < max) && (tree.root() > min) &&
            abs(lHei - rHei) <= 1);
    }

    height = 0;
    return true;
}

bool resuelveCaso() {

    


    // leer los datos de la entrada
    int n;
    bintree<int> tree;

    tree = leerArbol(-1);
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    int iteration = 0;
    bool isEquil = inEquil(tree, iteration, INT_MIN, INT_MAX);
    cout << (isEquil ? "SI" : "NO") << endl;

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
