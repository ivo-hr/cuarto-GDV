//Eva Sanchez Muñoz
//VJ60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

//Debido a que el vector de numeros es un vector ordenado, el coste algoritmo 
//es solo de búsqueda binaria y por ello cuesta O(log n) 

int resolver(vector<int> v, int& ini, int& fin) 
{
    int tam = fin - ini;

    //Comprobamos los casos especiales, siendo estos el de un solo
    //valor y el de dos valores en el vector
    if (tam == 0)
        return v[ini];
    else if (tam == 1)
    {
        if (v[ini] % 2 != 0)
            return v[ini];
        else
            return v[fin]; 
    }

    //Si hay más de dos valores...
    else
    {
        //Buscamos el valor situado en la mitad
        int mitad = (ini + fin) / 2; 

        //Comprobamos que no es el impar
        if (v[mitad] % 2 != 0)
            return v[mitad];

        else
        {
            //Hallamos la distancia que hay hasta el último valor del vector
            int distancia = fin - mitad;

            //Si coincide, asumimos que el impar esta en el lado de números menores
            //Si no coincide, esta en el de mayores
            if (v[mitad] + 2 * distancia == v[fin])
                return resolver(v, ini, mitad);
            else
                return resolver(v, mitad, fin); 
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v(n);
    int aux;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v[i] = aux;
    }

    int ini = 0, fin = n - 1;

    cout << resolver(v, ini, fin) << "\n";

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
