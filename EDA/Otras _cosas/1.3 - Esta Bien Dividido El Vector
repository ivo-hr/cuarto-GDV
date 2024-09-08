// Eva Sanchez
// VJ60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int>valores, int pos)
{
    bool isCorrect = true; 
    int tam = valores.size();

    if (pos + 1 < tam) 
    {
        int maxMin = valores[0], minMax = valores[pos + 1], aux = 0;

        while (aux < tam && isCorrect)
        {
            if (aux < pos + 1)
            {
                if (valores[aux] >= minMax)
                    isCorrect = false;
                else if (valores[aux] > maxMin)
                    maxMin = valores[aux];
            }

            else
            {
                if (valores[aux] <= maxMin)
                    isCorrect = false;
                else if (valores[aux] < minMax)
                    minMax = valores[aux];
            }

            aux++;
        }
    }
    
    if (isCorrect)
        std::cout << "SI\n";
    else
        std::cout << "NO\n"; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, pos, aux;
    std::cin >> n >> pos;

    std::vector <int> valores(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> aux;
        valores[i] = aux; 
    }

    resolver(valores, pos); 

    return true;
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
