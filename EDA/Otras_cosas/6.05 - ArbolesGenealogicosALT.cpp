#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
bool gen(bintree<T> const& tree,int& g,int&alt) {
    if (tree.empty()) {
        return true;
    }
    else if (tree.left().empty() && tree.right().empty()) {
        return true;
    }
    else {
        g++;
        bool genIzq = gen(tree.left(), g,alt);
        bool genDer = gen(tree.right(), g,alt);
       

        if (genDer && genIzq) {
            if (g > alt) { //guardamos la maxima prfundidad/altura
                alt = g;
            }
            g--;
            
            if (!tree.left().empty()&&!tree.right().empty()) {
                
                if (tree.left().root() < tree.right().root() + 2) {
                    return false;
                }
                if (tree.root() < tree.left().root() + 18) {
                    return false;
                }

                return true;
            }

            else if (tree.right().empty()&&!tree.left().empty()) {
                
                if (tree.root() < tree.left().root() + 18) {
                    return false;
                }
                return true;
            }

            else if (!tree.right().empty() && tree.left().empty()) {
              
                return false;
                
            }



            else {
                return true;
            }
        }
        else {

            return false;
        }
       
        

    }
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<int> tree;
    tree = leerArbol(-1);
    int g=0;
    int alt=0;

    if (gen(tree, g,alt)) {
       if(!tree.empty()){
           alt++; //el primero tambien es una generacion
       }
       cout << "SI" << " " << alt << endl;
    }
    else 
        cout << "NO" << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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
