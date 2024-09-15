// Eva Sanchez
// VJ60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

bool anagramas(const string& pal1, string pal2) 
{
    int posicion = 0, tam = pal1.size(); 
    bool esAnagrama = true;

    while (posicion < tam && esAnagrama)
    {
        int i = posicion; 

        while (i < tam && pal1[posicion] != pal2[i])
            i++;

        if (i == tam)
            esAnagrama = false; 
        else
        {
            char aux = pal2[posicion]; 
            pal2[posicion] = pal2[i];
            pal2[i] = aux; 
        }

        posicion++; 
    }

    return esAnagrama; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    string pal1, pal2; 
    cin >> pal1 >> pal2; 

    if (anagramas(pal1, pal2))
        cout << "SI\n";
    else
        cout << "NO\n"; 
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
