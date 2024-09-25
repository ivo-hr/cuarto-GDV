// Enrique Juan Gamboa
// EDA-GDV36


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



void resolver(std::vector<int>& datos) {
    int j = 0;  // Índice para los elementos válidos

    //Recorrer el vector y conservar solo los números pares
    for (int i = 0; i < datos.size(); i++) {
        if (datos[i] % 2 == 0) {
            datos[j] = datos[i];  //Sobreescritura en un punto <= al índice actual
            j++;  //Aumentar el índice de los elementos válidos
        }
    }

    // Redimensionar el vector para eliminar los elementos sobrantes
    datos.resize(j);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (! std::cin)
        return false;
    int numDatos;
    std::cin >> numDatos;

    std::vector<int> datos(numDatos);
    for(int i = 0; i < numDatos; i++){
        std::cin >> datos[i];
    }

    resolver(datos);

    // escribir sol
    if (datos.size() == 0) {
        std::cout << std::endl;
    }
    else {
        for(int i = 0; i < datos.size(); i++){
            std::cout << datos[i] << " ";
        }
    }
    //std::cout << std::endl;

    return true;

}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
// #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
// #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
// #endif

    return 0;
}