// David Brey Plaza
// VJ08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int resolver(int caps)
{
    unordered_map<int, int> lista; // El numero del capitulo y la cantidad de veces que se ha visto
    int distancia = 0;
    int ini = 1;
    int max = 0; // Numero de dias consecutivos
    int elem; // Capitulo

    for (int i = 1; i <= caps; ++i) {
        cin >> elem;

        // Si la posicion no existe en la lista, la creamos y si existe, entonces comparamos
        if (lista[elem] >= ini)
        {
            ini = lista[elem] + 1;
            distancia = i - lista[elem];
        }
        else
        {
            // Dias consecutivos sin repetir capitulo
            distancia++;
            if (distancia > max) { max = distancia; }
        }

        lista[elem] = i;
    }

    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int capitulos;
    cin >> capitulos;

    int max = resolver(capitulos);

    cout << max << "\n";


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