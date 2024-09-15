//Sebastian Sanchez Hombria
//VJ57


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


bool valido(int i, /*const vector<int>& sol,*/ const vector<bool>& usados) {

    return (usados[i] == true);
}

// función que resuelve el problema
void resolver(int n, int m, int k, int satisfActual, int& satisfMax, vector<int> sol, vector<bool>& usados, const vector<vector<int>>& satisfaccion, const vector<int>& maxSatisfPorJugueteRestante) {
    
    for (int i = 0; i < m; i++)
    {
        //sumas
        satisfActual += satisfaccion[k][i];

        if (usados[i] != true) {

            usados[i] = true;
            
            if (k == n-1) {
                //procesar sol
                if (satisfActual > satisfMax)
                    satisfMax = satisfActual;
            }
            else {
                //poda
                if(satisfActual + maxSatisfPorJugueteRestante[k+1] > satisfMax)
                    resolver(n, m, k + 1, satisfActual, satisfMax, sol, usados, satisfaccion, maxSatisfPorJugueteRestante);
            }

            usados[i] = false;;

        }

        //restas
        satisfActual -= satisfaccion[k][i];

    }

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;

    cin >> m >> n;
    if (!std::cin)
        return false;

    vector<vector<int>> satisfaccion(n);
    vector<int> satisfAux(m);
    vector<int> maxSatisfPorJuguete(n);
    int valor; int maxValor = 0;

    for (int i = 0; i < n; i++)
    {
        maxValor = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> valor;
            satisfAux[j] = valor;

            if (valor > maxValor) {
                maxValor = valor;
            }
        }
        maxSatisfPorJuguete[i] = maxValor;
        satisfaccion[i] = satisfAux;
    }
    

    for (int i = n - 2; i >= 0; --i) {
        maxSatisfPorJuguete[i] += maxSatisfPorJuguete[i + 1];
    }

    vector<int> sol(n);
    vector<bool> usados(m, false);

    int satisfMax = 0;
    resolver(n, m, 0, 0, satisfMax, sol, usados, satisfaccion, maxSatisfPorJuguete);

    // escribir sol
    cout << satisfMax << '\n';
    
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
    //system("PAUSE");
#endif

    return 0;
}
