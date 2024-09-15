//Sebastian Sanchez Castelli-Gair
//VJ57


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;

// función que resuelve el problema
void resolver(list<int>& l) {


    int antValor = -1;

    auto i = l.begin();
    int j = l.size();
    while (j > 0) {
        while (j > 0 && *(i) < antValor)
        {
            i = l.erase(i); --j;
        }

        if (j > 0) {
            antValor = *i;
            ++i;
        }

        --j;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int k; cin >> k;
    list<int> l;

    while (k != -1) {
        l.push_back(k);
        cin >> k;
    }
    
    resolver(l);

    // escribir sol
    while (!l.empty()) {
        cout << l.front() << ' '; l.pop_front();
    }
    cout << '\n';
    
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
