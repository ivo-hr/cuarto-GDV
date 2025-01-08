#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;



//Funcion de poda heuristica
bool podaPorHeuristica(int k, int gastoActual, int mejorGasto, int numSupermercados, int numProductos, 
                       vector<vector<int>> const& precios) {
    int costeMinimoFuturo = gastoActual;

    // Para cada producto que aún no ha sido asignado
    for (int j = k; j < numProductos; j++) {
        int menorPrecio = INT_MAX;
        // Encontramos el menor precio para ese producto en todos los supermercados
        for (int i = 0; i < numSupermercados; i++) {
            menorPrecio = min(menorPrecio, precios[i][j]);
        }
        costeMinimoFuturo += menorPrecio;
    }

    // Si el coste estimado es mayor o igual al mejor gasto conocido, podar
    return costeMinimoFuturo >= mejorGasto;
}



// Función que resuelve el problema mediante backtracking
// soluc es la solución parcial, donde se guarda qué supermercado está asignado a cada producto
// k es la capa actual del árbol (producto que estamos asignando)
// numSupermercados es el número total de supermercados
// numProductos es el número total de productos
// mejorGasto almacena el costo mínimo encontrado hasta el momento
// gastoActual es el costo acumulado en la rama actual del árbol
// visitado es un vector que indica cuántos productos se han asignado a cada supermercado (máximo 3)
// precios es la matriz que contiene los precios de los productos en cada supermercado
void resolver(vector<int>& soluc, int k, int numSupermercados, int numProductos, int& mejorGasto, int gastoActual, 
                vector<int>& visitado, vector<vector<int>> const& precios) {
    // Caso base: si hemos asignado todos los productos
    if (k == numProductos) {
        // Actualizamos el mejor costo si esta solución es mejor
        mejorGasto = min(mejorGasto, gastoActual);
        return;
    }

    // Aplicamos la heurística de poda
    if (podaPorHeuristica(k, gastoActual, mejorGasto, numSupermercados, numProductos, precios)) {
        return; // Podamos esta rama si el límite inferior no es prometedor
    }

    // Para cada supermercado, intentamos asignarle el producto k
    for (int i = 0; i < numSupermercados; i++) {
        // Si el supermercado i no ha alcanzado su límite de 3 productos
        if (visitado[i] < 3) {
            // Asignamos el producto k al supermercado i
            soluc[k] = i;
            visitado[i]++;
            gastoActual += precios[i][k];

            // Solo exploramos si el costo actual no supera el mejor conocido (poda)
            if (gastoActual < mejorGasto) {
                resolver(soluc, k + 1, numSupermercados, numProductos, mejorGasto, gastoActual, visitado, precios);
            }

            // Deshacemos la asignación (backtracking)
            gastoActual -= precios[i][k];
            visitado[i]--;
        }
    }
}

// Resuelve un caso de prueba, procesando la entrada y mostrando la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numSupermercados, numProductos;
    cin >> numSupermercados >> numProductos;

    // Matriz de precios: precios[i][j] indica el precio del producto j en el supermercado i
    vector<vector<int>> precios(numSupermercados, vector<int>(numProductos));

    // Leer precios para cada supermercado y producto
    for (int i = 0; i < numSupermercados; i++) {
        for (int j = 0; j < numProductos; j++) {
            cin >> precios[i][j];
        }
    }

    // Inicializamos estructuras necesarias para el algoritmo
    vector<int> soluc(numProductos);          // Vector para almacenar la asignación de productos
    vector<int> visitado(numSupermercados, 0); // Vector para contar productos asignados a cada supermercado
    int mejorGasto = INT_MAX;                 // Costo mínimo inicializado al mayor valor posible
    int gastoActual = 0;                      // Costo acumulado de la solución parcial actual
    int k = 0;                                // Nivel inicial del árbol de decisiones (producto actual)

    // Llamada inicial a la función de backtracking
    resolver(soluc, k, numSupermercados, numProductos, mejorGasto, gastoActual, visitado, precios);

    // Imprimimos el mejor costo encontrado para este caso de prueba, o "Sin solución factible"
    if (mejorGasto == INT_MAX) {
        cout << "Sin solucion factible" << endl;
    } else {
        cout << mejorGasto << endl;
    }
}

// Función principal
int main() {
    // Configuración para leer datos de archivo (solo para pruebas locales)
    #define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // Guardamos el buffer original de cin y lo redirigimos al archivo
#endif

    // Leer el número de casos de prueba
    int numCasos;
    cin >> numCasos;

    // Procesar cada caso de prueba
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }

    // Restaurar la configuración original de cin (solo para pruebas locales)
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
