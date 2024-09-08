//Sebastian Sanchez Castelli-Gair
//VJ57


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;

int alumnoAfortunado(list<int>& l, int n) {

    auto it = l.begin();
    int i = 0, j = 0;

    while (l.size() > 1) {
        while (i < n) {
            ++i; ++j;
            it = ++it;
            if (j >= l.size()) {
                it = l.begin(); j = 0;
            }
        }
        i = 0;

        
    
        it = l.erase(it);

        if (j >= l.size()) {
            it = l.begin();
            j = 0;
        }
    }

    return *it;
   
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0)
        return false;

    list<int> l;

    for (int i = 1; i <= a; i++)
    {
        l.push_back(i);
    }

    int sol = alumnoAfortunado(l, b);
    
    // escribir sol
    cout << sol << '\n';

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
