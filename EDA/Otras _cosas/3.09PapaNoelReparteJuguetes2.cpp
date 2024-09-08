// Sebastian Sanchez Hombria
// VJ57


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void procesaSolucion(const vector<int>& sol) {
    for (auto i : sol) {
        cout << i << ' ';
    }

    cout << '\n';
}

bool valida(int i, int s, int k, const vector<int>& sol, const vector<pair<int, int>>& juguetes, const vector<string>& tiposJuguete, const vector<vector<int>>& satisfaccion) {

    if (juguetes[i].first < 0)
        return false;

    if (k % 2 != 0) { //solo comprobamos cuando metemos el segundo juguete

        if (tiposJuguete[sol[k]] == tiposJuguete[sol[k - 1]]) //si son el mismo tipo de regalo
            return false;
        
        if (satisfaccion[k / 2][sol[k]] + satisfaccion[k / 2][sol[k - 1]] < s) //suma de satisfacciones
            return false;

        if (sol[k] < sol[k - 1])
            return false;
    }


    return true;
}

// función que resuelve el problema
void resolver(bool& haySol, int m, int n, int s, int k, vector<int> sol, vector<pair<int, int>>& juguetes, const vector<string>& tiposJuguete, const vector<vector<int>>& satisfaccion) {
    
    for (int i = 0; i < m; i++)
    {
        sol[k] = juguetes[i].second;

        //sumas
        juguetes[i].first--;

        if (valida(i, s, k, sol, juguetes, tiposJuguete, satisfaccion)) {
            if (k == 2*n - 1) {
                haySol = true;
                procesaSolucion(sol);
            }
            else {
                resolver(haySol, m, n, s, k + 1, sol, juguetes, tiposJuguete, satisfaccion);
            }
        }
        

        //restas
        juguetes[i].first++;

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n, s;

    cin >> m;

    if (! std::cin)
        return false;
    
    cin >> n >> s;

    vector<pair<int,int>> juguetes(m); int numJuguete; //cantidades y numeros de juguetes
    vector<vector<int>> satisfaccion(n); int auxint;
    vector<string> tiposJuguetes(m); string tipoJuguete;

    for (int i = 0; i < m; i++)
    {
        cin >> auxint;
        juguetes[i].first = auxint;
        juguetes[i].second = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tipoJuguete;
        tiposJuguetes[i] = tipoJuguete;
    }

    vector<vector<int>> satisfaccionRegalo(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> auxint;
            satisfaccionRegalo[i].push_back(auxint);
        }
    }
    vector<int> sol(2 * n);
    bool haySol = false;

    resolver(haySol, m, n, s, 0, sol, juguetes, tiposJuguetes, satisfaccionRegalo);
    
    // escribir sol
    if (!haySol)
        cout << "SIN SOLUCION\n";
    
    cout << '\n';

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
