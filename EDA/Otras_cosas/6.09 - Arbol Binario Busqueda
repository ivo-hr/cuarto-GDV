// David Brey Plaza
// VJ05


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct rama {
    int maximo;
    int minimo;
    bool valido;
};

rama resolver(const bintree<int>& arbol) 
{
    // Si no hay nodo, esa parte cumple
    if (arbol.empty())
    {
        return { -1, -1, true };
    }
    else if (arbol.left().empty() && arbol.right().empty()) // Si hay nodo, pero esta al final del arbol, cumple 
    {
        return { arbol.root(), arbol.root(), true };
    }
    else if (arbol.left().empty())
    {
        rama sol = resolver(arbol.right());

        // Si no hay izquierdo, cogemos la rama derecha y nos aseguramos 
        // que su elemento minimo es mayor que el valor que tiene la raiz (y que sigue siendo valido)
        if (sol.valido && arbol.root() < sol.minimo) sol.valido = true;
        else sol.valido = false;

        // Comparamos los elementos minimos y maximos con la raiz y los sustituimos si es necesario
        sol.minimo = min(sol.minimo, arbol.root());
        sol.maximo = max(sol.maximo, arbol.root());
        return sol;
    }
    else if (arbol.right().empty())
    {
        rama sol = resolver(arbol.left());

        // Si no hay izquierdo, cogemos la rama izquierdo y nos aseguramos
        // que su elemento maximo es mayor que el valor que tiene la raiz (y que sigue siendo valido)
        if (sol.valido && arbol.root() > sol.maximo) sol.valido = true;
        else sol.valido = false;

        // Comparamos los elementos minimos y maximos con la raiz y los sustituimos si es necesario
        sol.minimo = min(sol.minimo, arbol.root());
        sol.maximo = max(sol.maximo, arbol.root());
        return sol;
    }
    else
    {
        rama sol;
        rama iz = resolver(arbol.left());
        rama dr = resolver(arbol.right());

        // Cogemos los valores maximos y minimos de ambas ramas 
        // y lo comparamos con el valor de la raiz
        sol.maximo = max(dr.maximo, iz.maximo);
        sol.maximo = max(sol.maximo, arbol.root());

        sol.minimo = min(iz.minimo, dr.minimo);
        sol.minimo = min(sol.minimo, arbol.root());

        // Comprobamos si siguen siendo validos, y estan bien ordenados por valor
        if (iz.valido && dr.valido && iz.maximo < arbol.root() && dr.minimo > arbol.root()) sol.valido = true;
        else sol.valido = false;
        return sol;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);

    if (resolver(arbol).valido) cout << "SI\n";
    else cout << "NO\n";

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
    system("PAUSE");
#endif

    return 0;
}
