//Sebastian Sanchez Castelli-Gair
//VJ57


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool esSol(int numProdsTotales, int k) {
    return numProdsTotales - 1 == k;
}

bool valida(int i, const vector<int>& prodsTomadosTienda) {
    //sera valida si no has tomado mas de tres productos de la tienda
    return prodsTomadosTienda[i] <= 3;
}
// función que resuelve el problema
void resolver(int m, int k, int& mejorPrecio, int precioAcum, vector<int>& sol, vector<int>& prodsTomadosTienda, const vector<vector<int>>& precios, const vector<int>& minPrecios){
    
    for (int i = 0; i < m; i++) //cada supermercado es un candidato posible
    {
        sol[k] = i;

        prodsTomadosTienda[i]++;
        precioAcum += precios[i][k];

        if (valida(i, prodsTomadosTienda)) {
            if (esSol(sol.size(), k)) {
                if (precioAcum <= mejorPrecio)
                    mejorPrecio = precioAcum;
            }
            else{
                if(precioAcum + minPrecios[k + 1] < mejorPrecio)
                    resolver(m, k + 1, mejorPrecio, precioAcum, sol, prodsTomadosTienda, precios, minPrecios);
            }
        }

        prodsTomadosTienda[i]--;
        precioAcum -= precios[i][k];


    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int m, n;

    cin >> m >> n;

    int precioFinal = INT_MAX;

    vector<int> sol(n); //tendra la tienda en la que se comprara cada producto
    vector<vector<int>> precios(m); vector<int> precios2(n);
    vector<int> prodsTomadosTienda(m, 0);
    vector<int> minPrecios(n, INT_MAX);
    int prod;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> prod;
            precios2[j] = prod;
            if (minPrecios[j] > prod)
                minPrecios[j] = prod;
        }
            precios[i] = precios2;
    }

    //vector con la suma de los minPrecios restantes

    for (int i = n - 2; i >= 0; i--)
    {
        minPrecios[i] += minPrecios[i + 1];
    }
    
    resolver(m, 0, precioFinal, 0, sol, prodsTomadosTienda, precios, minPrecios);
    // escribir sol
    precioFinal == INT_MAX ? cout << "Sin solucion factible\n" : cout << precioFinal << '\n';
    
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
