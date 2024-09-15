//Sebastian Sanchez Castelli-Gair
// VJ57


#include <iostream>
#include <iomanip>
#include <fstream>

#include "deque_eda.h"
#include "list_eda.h"
#include <string>
#include <cctype>

using namespace std;

// función que resuelve el problema
string resolver(string s) {

    list<char> l1;
    list<char> l2;
    //deque<char> dq;
    
    int i = 0;

    while (i < s.size()) {

        if (i % 2 == 0) 
            l1.push_back(s[i]);
        else
            l2.push_front(s[i]);
        ++i;
    }

    while (!l2.empty()) {
        l1.push_back(l2.front()); l2.pop_front();
    }

    i = l1.size();
    string sol = "";
    deque<char> aux;

    while (i > 0) {
        if (l1.front() == 'a' || l1.front() == 'e' || l1.front() == 'i' || l1.front() == 'o' || l1.front() == 'u'
            || l1.front() == 'A' || l1.front() == 'E' || l1.front() == 'I' || l1.front() == 'O' || l1.front() == 'U')
        {
            while (!aux.empty()) {
                sol.push_back(aux.front()); aux.pop_front();
            }
            sol.push_back(l1.front()); l1.pop_front();
        }
        else {
            aux.push_front(l1.front()); l1.pop_front();
        }
        

        --i;
    }

    if (!aux.empty()) {
        while (!aux.empty()) {
            sol.push_back(aux.front()); aux.pop_front();
        }
    }

   
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string linea;
    //list<char> list;
    
    getline(cin, linea);

    if (!std::cin)
        return false;

   /* for (char i : linea) {
        list.push_back(i);
    }*/

    string sol = resolver(linea);
    
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
    //system("PAUSE");
#endif

    return 0;
}
