//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//
//bool valido(int consumoActual, int consumoMax, int k, const vector<int>& sol,  const vector<int>& totalesPorColor) {
//    //mas de 2 luces seguidas no pueden ser iguales
//    if (k > 1 && sol[k] == sol[k - 1] && sol[k-1] == sol[k-2])
//        return false;
//
//    //no exceso de un color
//    int numOtrosColores = (k + 1) - totalesPorColor[sol[k]];
//    if (numOtrosColores + 1 < totalesPorColor[sol[k]])
//        return false;
//
//    //no exceso de energia
//    if (consumoActual > consumoMax)
//        return false;
//
//    return true;
//}
//
//void resolver(int n, int m, int consumoActual, int consumoMax, int& numCombinaciones, int k, vector<int> sol, const vector<int>& consumosPorColor, vector<int>& totalesPorColor) {
//
//    for (int i = 0; i < m; i++)
//    {
//        sol[k] = i;
//
//        //sumas
//        totalesPorColor[i]++;
//        consumoActual += consumosPorColor[i];
//
//        if (valido(consumoActual, consumoMax, k, sol, totalesPorColor)) {
//            if (k == n - 1) {
//                /*for (auto j : sol)
//                    cout << j << ' ';
//                cout << '\n';*/
//                numCombinaciones++;
//            }
//            else {
//                //posible poda
//                resolver(n, m, consumoActual, consumoMax, numCombinaciones, k + 1, sol, consumosPorColor, totalesPorColor);
//            }
//        }
//
//        //restas
//        totalesPorColor[i]--;
//        consumoActual -= consumosPorColor[i];
//
//
//    }
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//    // leer los datos de la entrada
//    int n, m, consumoMax;
//    int combinaciones = 0;
//    cin >> n;
//    if (n == 0) return false;
//    cin >> m >> consumoMax;
//    vector<int> consumosPorColor(m);
//    for (int& e : consumosPorColor) cin >> e;
//    vector<int> soluc(n);
//    int k = 0;
//    vector<int> totalesPorColor(m, 0); //aqui llevaremos cuantas hay puestas de cada color
//
//    vector<int> sol(n);
//
//    int numCombinaciones = 0;
//    resolver(n, m, 0, consumoMax, numCombinaciones, 0, sol, consumosPorColor, totalesPorColor);
//    
//    // Salida
//    cout << numCombinaciones << '\n';
//
//    return true;
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
//    while (resuelveCaso())
//        ;
//
//    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    //system("PAUSE");
//#endif
//
//    return 0;
//}
