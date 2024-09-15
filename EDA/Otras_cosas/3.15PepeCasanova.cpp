////Sebastian Sanchez Castelli-Gair
////VJ57
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//struct cancion {
//    int duracion, puntuacion;
//};
// 
//// función que resuelve el problema
//void resolver(int n, int k, int duracionActualA, int duracionActualB, int duracionMaxCara, int puntuacionActual, int& mejorPuntuacion, const vector<cancion>& canciones, const vector<int>& acumulacionPuntuacionesRestantes) {
//    
//    //intentamos meter en la cara A
//    if (duracionActualA + canciones[k].duracion <= duracionMaxCara) { //si no se pasa de la cara A
//        //sumas
//        duracionActualA += canciones[k].duracion;
//        puntuacionActual += canciones[k].puntuacion;
//
//        if (k == n-1) {
//            if (puntuacionActual > mejorPuntuacion)
//                mejorPuntuacion = puntuacionActual;
//        }
//        else {
//            if (puntuacionActual + acumulacionPuntuacionesRestantes[k + 1] > mejorPuntuacion)
//                resolver(n, k + 1, duracionActualA, duracionActualB, duracionMaxCara, puntuacionActual, mejorPuntuacion, canciones, acumulacionPuntuacionesRestantes);
//
//        }
//
//        //restas
//        duracionActualA -= canciones[k].duracion;
//        puntuacionActual -= canciones[k].puntuacion;
//    }
//
//    //intentamos meter en la cara B
//    if (duracionActualB + canciones[k].duracion <= duracionMaxCara) { //si no se pasa de la cara B
//        //sumas
//        duracionActualB += canciones[k].duracion;
//        puntuacionActual += canciones[k].puntuacion;
//
//        if (k == n - 1) {
//            if (puntuacionActual > mejorPuntuacion)
//                mejorPuntuacion = puntuacionActual;
//        }
//        else {
//            if (puntuacionActual + acumulacionPuntuacionesRestantes[k + 1] > mejorPuntuacion)
//                resolver(n, k + 1, duracionActualA, duracionActualB, duracionMaxCara, puntuacionActual, mejorPuntuacion, canciones, acumulacionPuntuacionesRestantes);
//        }
//
//        //restas
//        duracionActualB -= canciones[k].duracion;
//        puntuacionActual -= canciones[k].puntuacion;
//    }
//
//    //no lo metemos en ninguna cara
//
//    if (k == n - 1) {
//        if (puntuacionActual > mejorPuntuacion)
//            mejorPuntuacion = puntuacionActual;
//    }
//    else {
//        if(puntuacionActual + acumulacionPuntuacionesRestantes[k+1] > mejorPuntuacion)
//            resolver(n, k + 1, duracionActualA, duracionActualB, duracionMaxCara, puntuacionActual, mejorPuntuacion, canciones, acumulacionPuntuacionesRestantes);
//    }
//    
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//    // leer los datos de la entrada
//    int n; cin >> n;
//
//    if (n == 0)
//        return false;
//
//    int duracion; cin >> duracion;
//
//    vector<cancion> canciones(n); int a, b;
//    vector<int> acumulacionPuntuacionesRestantes(n);
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a >> b;
//        canciones[i] = { a, b };
//        
//        acumulacionPuntuacionesRestantes[i] = b;
//    }
//
//    vector<int> sol(n); //cada cancion entra en a, b o no entra(1, 2 y 0)
//    int mejorPuntuacion = -1;
//
//    for (int i = n-2; i >= 0; i--)
//    {
//        acumulacionPuntuacionesRestantes[i] += acumulacionPuntuacionesRestantes[i + 1];
//    }
//
//    resolver(n, 0, 0, 0, duracion, 0, mejorPuntuacion, canciones, acumulacionPuntuacionesRestantes);
//    
//    // escribir sol
//    cout << mejorPuntuacion << '\n';
//    
//    return true;
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
//    while (resuelveCaso())
//        ;
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
