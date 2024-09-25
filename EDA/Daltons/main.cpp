// Enrique Juan Gamboa
// EDA-GDV36


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
void resolver(const std::vector<int>& daltons) {
    int tam = daltons.size();
    //Booleanos para mantener si van en orden ascendente o descendente
    bool ascendente = true, descendente = true;

    //Comprobamos si los hermanos van en orden ascendente o descendente
    for (int i = 1; i < tam; ++i) {
        //Si el siguiente hermano es igual o más pequeño, ya no es orden ascendente
        if (daltons[i] <= daltons[i - 1])
            ascendente = false;
        //Si el siguiente hermano es igual o más grande, ya no es orden descendente
        if (daltons[i] >= daltons[i - 1])
            descendente = false;
        //Si no es ascendente ni descendente, salimos del bucle
        if (!ascendente && !descendente)
            break;
    }

    if (ascendente || descendente)
        std::cout << "DALTON\n";
    else
        std::cout << "DESCONOCIDOS\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int datos;
    std::cin >> datos;

    //Fin de la entrada
    if (datos == 0)
        return false;

    int hermano;
    std::vector <int> daltons(datos);

    //Creamos el vector con los hermanos
    for (int i = 0; i < datos; i++)
    {
        std::cin >> hermano;
        daltons[i] = hermano;
    }

    resolver(daltons);

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
// #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
// #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
// #endif

    return 0;
}
