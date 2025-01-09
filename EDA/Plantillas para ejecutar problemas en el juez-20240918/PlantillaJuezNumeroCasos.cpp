// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

using namespace std;
// función que resuelve el problema
void resolver(int n, int pos, int lon, int k, list<char>& datos) {
    if (n == 0 || lon == 0 || k == 0 || pos >= n || pos - k < 0) return;

    // Ajustar lon si el segmento se sale de la lista
    if (pos + lon > n) {
        lon = n - pos;
    }


    // Crear iteradores al inicio y final del segmento
    auto itBegin = datos.begin();
    advance(itBegin, pos);

    auto itEnd = itBegin;
    advance(itEnd, lon);

    // Copiar el segmento a una lista auxiliar
    list<char> segmento;
    segmento.assign(itBegin, itEnd);

    // Borrar el segmento de la lista original
    itEnd = datos.erase(itBegin, itEnd);

    // Calcular la nueva posición de inserción
    auto itFinal = datos.begin();
    if (k >= pos) {
        // Si k es mayor o igual a pos, el segmento se mueve al inicio
        itFinal = datos.begin();
    } else {
        // Si k es menor que pos, se inserta en pos - k
        advance(itFinal, pos - k);
    }

    // Insertar el segmento en la nueva posición
    datos.insert(itFinal, segmento.begin(), segmento.end());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, pos, lon, k;
    cin >> n >> pos >> lon >> k;
    list<char> datos;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        datos.push_back(x);
    }
    
    resolver(n, pos, lon, k, datos);
    // escribir solucion

    for (auto x : datos) {
        cout << x << " ";
    }
    cout << endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #define DOMJUDGE

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