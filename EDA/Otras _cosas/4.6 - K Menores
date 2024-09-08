// David Brey Plaza
// VJ08

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"
#include <vector>
using namespace std;

// Coste = Numero elementos de datos * (log(nMinimos))


Set<int> resolver(vector<int> datos, int nMinimos) {

    Set<int> solucion;
    int k = 0;

    for (int i = 0; i < datos.size(); i++)
    {
        if (!solucion.contains(datos[i]))
        {
            // Si hay espacio, entonces lo metemos
            if (k < nMinimos)
            {
                solucion.add(datos[i]);
                k++;
            }
            else
            {
                // Comprobamos que el numero no supera al maximo de nuestro Set y que no esta repetido
                if (solucion.getMax() > datos[i])
                {
                    solucion.removeMax();
                    solucion.add(datos[i]);
                }
            }
        }
    }

    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nMinimos;
    cin >> nMinimos;
    if (!std::cin || nMinimos == 0)
        return false;


    vector<int> datos;
    int aux = 0;
    while (aux != -1) 
    {
        cin >> aux;
        if (aux != -1)
        {
            datos.push_back(aux);
        }
    }

    Set<int> sol = resolver(datos, nMinimos);

    // escribir sol
    for (int i = 0; i < sol.size(); i++)
    {
        int n = sol.toArray()[i];
        cout << n << " ";
    }

    cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
