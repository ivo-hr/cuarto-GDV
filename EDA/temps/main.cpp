// // Enrique Juan Gamboa
// // EDA-GDV36
//
//
// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <vector>
//
//
//
// // función que resuelve el problema
// void resolver(const std::vector<int>& temperaturas) {
//
//     //Datos para la resolución
//     int val = 0, pic = 0, size = temperaturas.size();
//
//     //Bucle de resolución, acabamos en size - 1 para no salirnos del vector
//     for (int i = 1; i < size - 1; ++i) {
//         //Detección del pico
//         if (temperaturas[i] > temperaturas[i - 1] &&
//             temperaturas[i] > temperaturas[i + 1])
//             pic++;
//         //Detección del valle
//         else if (temperaturas[i] < temperaturas[i - 1] &&
//             temperaturas[i] < temperaturas[i + 1])
//             val++;
//     }
//
//     std::cout << pic << " " << val << "\n";
// }
//
//
// // Resuelve un caso de prueba, leyendo de la entrada la
// // configuración, y escribiendo la respuesta
// void resuelveCaso()
// {
//     int n, val;
//     std::cin >> n;
//
//     std::vector<int> temp(n);
//
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> val;
//         temp[i] = val;
//     }
//
//     resolver(temp);
// }
//
// int main() {
//     // Para la entrada por fichero.
//     // Comentar para acepta el reto
// #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif
//
//
//     int casos;
//     std::cin >> casos;
//
//     for (int i = 0; i < casos; i++)
//         resuelveCaso();
//
//
//     // Para restablecer entrada. Comentar para acepta el reto
// #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
// #endif
//
//     return 0;
// }
