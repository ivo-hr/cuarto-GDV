// //
// // Created by h21 on 17/09/24.
// //
// // Enrique Juan Gamboa
// // EDA-GDV36
//
// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <vector>
//
//
// // funcion que resuelve el problema
// void resolver(std::vector<int> &nums) {
//     for (int i = 0; i < nums.size(); i++)
//         nums[i] *= 2;
// }
//
// // Resuelve un caso de prueba, leyendo de la entrada la
// // configuracion, y escribiendo la respuesta
// bool resuelveCaso() {
//     // leer los datos de la entrada
//     int numNums, num;
//
//     std::cin >> numNums;
//
//     if (numNums == -1)
//         return true;
//
//     std::vector<int> a(numNums); //Crea vector
//
//     if (numNums == 0)
//         return false;
//
//     for (int i = 0; i < numNums; i++) {
//         std::cin >> num;
//         a[i] = num;
//     }
//
//     resolver(a);
//
//     // escribir sol
//     std::cout << a[0];
//     for (int i = 1; i < numNums; i++)
//         std::cout << " " << a[i];
//
//     std::cout << std::endl;
//
//     return false;
// }
//
// int main() {
//     // Para la entrada por fichero.
//     // Comentar para acepta el reto
//     // #define DOMJUDGE
//     // #ifndef DOMJUDGE
//     //     std::ifstream in("datos.txt");
//     //     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//     // #endif
//
//
//     bool stopRead = false;
//     while (stopRead != true)
//         stopRead = resuelveCaso();
//
//
//     // Para restablecer entrada. Comentar para acepta el reto
//     /*#ifndef DOMJUDGE // para dejar todo como estaba al principio
//         std::cin.rdbuf(cinbuf);
//         system("PAUSE");
//     #endif*/
//
//     return 0;
// }