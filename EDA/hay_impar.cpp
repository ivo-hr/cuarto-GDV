#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& sec, int ini, int fin) {
    //Chequear si se puede usar el rango
    if (ini > fin) return -1;

    
    // Buscar el elemento impar si solo hay un elemento
    if (ini == fin){
        if (sec[ini] % 2 != 0) return sec[ini];
        else return -1;
    }

    int mitad = (ini + fin) / 2;

    if (sec[mitad] % 2 != 0) return sec[mitad];

    int izq = resolver(sec, ini, mitad);
    int der = resolver(sec, mitad + 1, fin);


    if (izq != -1 && izq % 2 != 0) return izq;
    else if (der != -1 && der % 2 != 0) return der;
    else return -1;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << resolver(sec,0,n) << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #define DOMJUDGE
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