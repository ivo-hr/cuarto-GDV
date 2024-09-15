// Eva Sanchez
// VJ60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
void resolver(std::vector<int>temperaturas)
{
    int valles = 0, picos = 0, tam = temperaturas.size();

    for (int i = 1; i < tam; i++)
    {
        if (i + 1 < tam) 
        {
            if (temperaturas[i] > temperaturas[i - 1] &&
                temperaturas[i] > temperaturas[i + 1])
                picos++;
            else if (temperaturas[i] < temperaturas[i - 1] &&
                temperaturas[i] < temperaturas[i + 1])
                valles++;
        }
    }

    std::cout << picos << " " << valles << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    int n, valor; 
    std::cin >> n; 

    std::vector<int> temperaturas(n); 

    for (int i = 0; i < n; i++)
    {
        std::cin >> valor; 
        temperaturas[i] = valor; 
    }

    resolver(temperaturas); 
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int casos; 
    std::cin >> casos; 

    for (int i = 0; i < casos; i++)
        resuelveCaso(); 


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
