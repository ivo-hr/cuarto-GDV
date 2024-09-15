// David Brey Plaza
// VJ08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
int minimo(vector<int> const &datos, int ini, int fin) 
{
    // Si no podemos dividir mas el vector
    if (fin - ini <= 0)
        return datos[ini];
    else
    {
        if (fin - ini == 1)
            return min(datos[ini], datos[fin]); // Comparamos cual de los 2 es mas pequeño y lo devolvemos

        int mit = (fin + ini) / 2;

        return min(minimo(datos, ini, mit), minimo(datos, mit, fin)); // Dividimos la busqueda por la mitad y devolvemos el minimo entre los 2
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    if (!std::cin)
        return false;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        int aux;
        cin >> aux;
        v[i] = aux;
    }

    cout << minimo(v, 0, v.size() - 1) << "\n";
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
