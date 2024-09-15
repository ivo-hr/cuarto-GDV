// Eva Sanchez
// VJ60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
void resolver(std::vector<int>daltons)
{
    int pos = 1, tam = daltons.size();
    bool isDalton = true;

    if (daltons[pos] > daltons[pos - 1])
    {
        pos++;

        while (pos < tam && isDalton)
        {
            if (daltons[pos] <= daltons[pos - 1])
                isDalton = false;

            pos++;
        }
    }

    else if (daltons[pos] < daltons[pos - 1])
    {
        pos++;

        while (pos < tam && isDalton)
        {
            if (daltons[pos] >= daltons[pos - 1])
                isDalton = false;

            pos++;
        }
    }

    else
        isDalton = false; 

    if (isDalton)
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

    if (datos == 0)
        return false;

    int hermano;
    std::vector <int> daltons(datos);

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
