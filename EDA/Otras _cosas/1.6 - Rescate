////Sebastian Sanchez Castelli-Gair
//// VJ57
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//struct sol {
//    int a, b;
//};
//
//// función que resuelve el problema
//sol resolver(const vector<int>& v, int m) {
//    int longSec = 0, maxLongSec = 0, inicio, inicioMax;
//    sol sol{ 0,0 };
//    for (int i = 0; i < v.size(); i++)
//    {
//        if (v[i] > m)//iniciamos secuencia
//        {
//            inicio = i;
//            longSec = 0;
//            while (i < v.size() && v[i] > m) {
//                i++; longSec++;
//                if (longSec > maxLongSec) {
//                    maxLongSec = longSec;
//                    inicioMax = inicio;
//                }
//            }
//        }
//    }
//    sol.a = inicioMax;
//    sol.b = sol.a + maxLongSec - 1;
//
//    return sol;
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//    // leer los datos de la entrada
//    int n, m, k;
//    vector<int> v;
//
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> k;
//        v.push_back(k);
//    }
//
//    sol sol = resolver(v, m);
//    // escribir sol
//    cout << sol.a << " " << sol.b << '\n';
//
//}
//
//int main() {
//    // Para la entrada por fichero.
//    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//
//
//    int numCasos;
//    std::cin >> numCasos;
//    for (int i = 0; i < numCasos; ++i)
//        resuelveCaso();
//
//
//    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif
//
//    return 0;
//}
