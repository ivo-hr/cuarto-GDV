// Enrique Juan Gamboa
// EDA-GDV36


#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits.h>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> const& valores, int pos)
{
    //Variables para la resolución
    bool isCorrect = true;
    int size = valores.size();
    int maxLeft = valores[0];

    //Bucle de resolución
    for (int i = 0; i <= pos; i++) {
        //Mientras que estemos antes de la posición, buscamos el numero mas alto
        if (valores[i] > maxLeft)
            maxLeft = valores[i];
    }
    for (int i = pos + 1; i < size; i++) {
        //Despues de la posición, miramos si es mayor que el maximo de la izquierda
        //Si no es mayor, no es correcto
        if (valores[i] <= maxLeft) {
            isCorrect = false;
            break;
        }
    }

    if (isCorrect)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, pos, vec;
    std::cin >> n >> pos;

    std::vector <int> valores(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> vec;
        valores[i] = vec;
    }

    resolver(valores, pos);

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
// #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif

    int casos;
    std::cin >> casos;

    for (int i = 0; i < casos; i++)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
// #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
// #endif

    return 0;
}
