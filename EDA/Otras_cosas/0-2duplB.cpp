// EnriqueJG


#include <iostream>
#include <iomanip>
#include <fstream>




bool resuelveCaso() {
    // leer los datos de la entrada

    int datos; 
    std::cin >> datos; 

    if (datos == 0)
        return false;

    std::cout << datos*2 << std::endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
