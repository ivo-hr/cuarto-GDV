//Eva Sanchez Muñoz
//VJ60

#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

using namespace std;

//El coste del programa es O(n), ya que se trata de un arbol en el cual 
//debemos recorrer todos los nodos para comprobar si es de busqueda, siendo el peor caso 

//Hacemos un struct para almacenar el maximo, el minimo 
//y si es de busqueda
struct Lado 
{
    int maximo;
    int minimo;
    bool busqueda;
};

Lado resolver(const bintree<int>& arbol)
{
    Lado sol;

    //Si el arbol esta vacio, se cumple
    if (arbol.empty())
        return { -1, -1, true };

    //Si uno de los lados esta vacio...
    else if (arbol.left().empty() || arbol.right().empty())
    {
        if (arbol.left().empty())
        {
            //Si el lado izquierdo y derecho estan vacios, es de busqueda con la raiz
            if (arbol.right().empty())
                return { arbol.root(), arbol.root(), true };

            //Si no, comprobamos el lado derecho
            else
            {
                sol = resolver(arbol.right());
                sol.busqueda = (sol.busqueda && arbol.root() < sol.minimo);
            }     
        }

        //Teniendo en cuenta que el lado izquierdo no esta vacio,
        //comprobamos el lado izquierdo
        else
        {
            sol = resolver(arbol.left());
            sol.busqueda = (sol.busqueda && arbol.root() > sol.maximo); 
        }
            
        //Comparamos el maximo y el minimo de la raiz, sustituyendolos
        sol.minimo = min(sol.minimo, arbol.root());
        sol.maximo = max(sol.maximo, arbol.root());
    }

    else
    {
        Lado iz = resolver(arbol.left());
        Lado dr = resolver(arbol.right());

        //Comparamos el maximo y el minimo en las ramas
        sol.maximo = max(dr.maximo, iz.maximo);
        sol.minimo = min(iz.minimo, dr.minimo);

        //Comparamos el maximo y el minimo con la raiz
        sol.maximo = max(sol.maximo, arbol.root());
        sol.minimo = min(sol.minimo, arbol.root());

        sol.busqueda = (iz.busqueda && dr.busqueda && iz.maximo < arbol.root() && dr.minimo > arbol.root()); 
    }

    return sol; 
}

void resuelveCaso() 
{
    bintree<int> arbol = leerArbol(-1);

    if (resolver(arbol).busqueda) 
        cout << "SI\n";
    else 
        cout << "NO\n";
}

int main() 
{
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
