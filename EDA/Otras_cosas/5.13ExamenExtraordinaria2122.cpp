﻿////Sebastian Sanchez Castelli-Gair
////VJ57
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include "list_eda.h"
//
//using namespace std;
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//    // leer los datos de la entrada
//    int n, pos, lon, k;
//
//    cin >> n >> pos >> lon >> k;
//    list<char> l; char aux;
//
//    for (int i = 0; i < n; ++i) {
//        cin >> aux;
//        l.push_back(aux);
//    }
//    
//    l.adelantaSegmento5_13(n, pos, lon, k);
//    // escribir sol
//    l.escribeLista();
//    
//}
//
//int main() {
//    // Para la entrada por fichero.
//    // Comentar para acepta el reto
//    #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//     #endif 
//    
//    
//    int numCasos;
//    std::cin >> numCasos;
//    for (int i = 0; i < numCasos; ++i)
//        resuelveCaso();
//
//    
//    // Para restablecer entrada. Comentar para acepta el reto
//     #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
//     #endif
//    
//    return 0;
//}
