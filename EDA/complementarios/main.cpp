// Enrique Juan Gamboa
// EDA-GDV26


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// El coste de la funcion es 2 void *(N digitos que tenga dato)

// función que resuelve el problema
int resolveComp(int dato, int nVeces) {
    int n, sol;
    if (dato > 0 || nVeces == 0)
    {
        n = dato % 10;
        dato /= 10;

        sol = resolveComp(dato, nVeces+1);
    }
    else
    {
        // Si alcanza el limite y vale 0, entonces volvemos
        return dato;
    }

    // Cambiamos el valor de n a su numero complementario
    n = 9 - n;

    int nDieces = 1;

    // Lo colocamos segun su digito
    for (int i = 0; i < nVeces; i++)
    {
        nDieces *= 10;
    }

    sol += n * nDieces;
    return sol;
}

int resolveInv(int dato, int& nVeces, bool unDigito0) {

    int n;
    int sol;
    if (dato > 0 || (nVeces == 0 && !unDigito0))
    {
        n = dato % 10;
        dato /= 10;
        unDigito0 = true;
        sol = resolveInv(dato, nVeces, unDigito0);
    }
    else
    {
        // Si alcanza el limite y vale 0, entonces volvemos
        return dato;
    }

    // Cambiamos el valor de n a su numero complementario
    n = 9 - n;

    int nDieces = 1;

    // Lo colocamos segun su digito
    for (int i = 0; i < nVeces; i++)
    {
        nDieces *= 10;
    }

    nVeces++;
    sol += n * nDieces;
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    cin >> numero;

    int nV = 0;

    int normal = resolveComp(numero,0);
    int inverso = resolveInv(numero, nV, false);

    // escribir sol
    cout << normal << " " << inverso << "\n";
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
