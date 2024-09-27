/*
Nombre completo: Enrique Juan Gamboa

Usuario del juez: EDA-GDV36
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Función que resuelve el problema
//Cuenta con complejidad O(log n) siendo n el tamaño de la secuencia de letras.
char resolver(const vector<char>& sec, char prim, char ult) {

    int l = 0, r = sec.size() - 1;
    //La idea es usar búsqueda binaria para encontrar el char que falta
    //En resumen, iremos buscando las mitades de la secuencia de letras hasta encontrar el char que falta
    //Gracias a que está ordenada, si el char de la mitad no es el que esperamos, sabemos que el que falta está a la izquierda
    while (l <= r) {
        //Indicamos la mitad del rango que estamos buscando
        int  half = l + ((r - l) / 2);
        //Si el char de la mitad no es el que esperamos haciendo prim + half, significa que el que falta está a la izquierda
        if (sec[half] != prim + half) {
            //Si estuviérmos en el primer char o el anterior es correcto, devolvemos éste
            if (half == 0 || sec[half - 1] == prim + half - 1)
                return prim + half;
            //Si no lo hemos encontrado, seguimos buscando a la izquierda limitando el rango a la izquierda de la mitad
            r = half - 1;
        }
        //Si el char de la mitad es el que esperamos, seguimos buscando a la derecha limitando el rango a la derecha de la mitad
        else l = half + 1;
    }
    //Si no hemos encontrado el char que falta, devolvemos el último
    return ult;


}

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer los datos de la entrada
    char prim, ult;
    cin >> prim >> ult;
    int n = ult - prim; // Cantidad de letras esperadas - 1 (ya que una falta)
    vector<char> sec(n);
    for (char& e : sec) cin >> e; // Leer las letras presentes
    cout << resolver(sec, prim, ult) << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
// #ifndef DOMJUDGE
//     std::ifstream in("input2.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); // Save old buf and redirect std::cin to input2.txt
// #endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

//     // Para restablecer entrada. Comentar para acepta el reto
// #ifndef DOMJUDGE // Para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     //system("PAUSE");
// #endif

    return 0;
}
