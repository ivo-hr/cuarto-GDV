// EnriqueJG


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>




bool resuelveCaso() {
    // leer los datos de la entrada

    int numCasos, numElementos;
    std::string datos;
    if (!(std::cin >> numCasos))
        return false; 

    std::cin >> numElementos;
    std::cin >> datos;
    std::string salida = "";

    for (int i = 0; i < numCasos; i++)
    {
        //Coger cada número separado por un espacio y multiplicarlo por 2

        int j = 0;
        int k = 0;
        while (i < numElementos)
        {
            std::string num = "";

            if (datos[k] == ' ')
                k++;
            
            else while (k < datos.size() && datos[k] != ' ')
            {
                num += datos[k];
                k++;
            }

            salida += std::to_string(std::stoi(num) * 2) + " ";
            i++;
        }
        

    }

    std::cout << salida << std::endl;
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
