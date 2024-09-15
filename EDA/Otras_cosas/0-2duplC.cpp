//Enrique JG

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

bool resuelveCaso() {
    // Número de elementos en el caso actual
    int numElementos;

    // Leer el número de elementos para este caso
    if (!(std::cin >> numElementos))
        return false;  // Fin de la entrada

    // Si el número de elementos es 0, imprimir una línea en blanco y terminar
    if (numElementos == 0) {
        std::cout << std::endl;
        return true;
    }

    // Ignorar el salto de línea que queda en el buffer después de leer numElementos
    std::cin.ignore();  

    std::string datos;
    std::getline(std::cin, datos);  // Leer la línea completa de números

    // Creamos un stringstream para dividir los números
    std::istringstream iss(datos);
    std::string salida = "";
    int numero;

    // Extraemos cada número, lo multiplicamos por 2 y construimos la cadena de salida
    for (int i = 0; i < numElementos; ++i) {
        iss >> numero;
        salida += std::to_string(numero * 2) + " ";
    }

    if (!salida.empty()) {
        salida.pop_back(); // Eliminamos el último espacio en blanco
    }

    std::cout << salida << std::endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // Guardar el buffer viejo y redirigir std::cin a datos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
