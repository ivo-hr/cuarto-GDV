

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct Cancion{
    int duracion;
    int puntos;
};

struct Casette{
    int duracionA;
    int duracionB;
    int puntosCasette;
};

//Funcion de poda por estimación optimista (?)
bool podarPorOptimismo(int capa, int puntosMax, int puntosCasette, vector<Cancion> const& canciones){
    int puntosRestantes = 0;
    for (int i = capa; i < canciones.size(); ++i){
        puntosRestantes += canciones[i].puntos;
    }
    return puntosCasette + puntosRestantes <= puntosMax;
}


// función que resuelve el problema
// Se hará backtracking
void resolver(vector<Cancion> const& canciones, int duracion, int capa, int& puntosMax, Casette casete){
    
    //Probamos meterla an la cara A
    if (casete.duracionA + canciones[capa].duracion <= duracion){
        casete.duracionA += canciones[capa].duracion;
        casete.puntosCasette += canciones[capa].puntos;

        if (capa == canciones.size() - 1){
            if (casete.puntosCasette > puntosMax){
                puntosMax = casete.puntosCasette;
            }
        }
        else{
            resolver(canciones, duracion, capa + 1, puntosMax, casete);
        }

        casete.duracionA -= canciones[capa].duracion;
        casete.puntosCasette -= canciones[capa].puntos;
    }
    //Ahora probamos meterla en la cara B
    if((casete.duracionB + canciones[capa].duracion <= duracion) && casete.duracionA != casete.duracionB){
        casete.duracionB += canciones[capa].duracion;
        casete.puntosCasette += canciones[capa].puntos;

        if (capa == canciones.size() - 1){
            if (casete.puntosCasette > puntosMax){
                puntosMax = casete.puntosCasette;
            }
        }
        else{
            resolver(canciones, duracion, capa + 1, puntosMax, casete);
        }

        casete.duracionB -= canciones[capa].duracion;
        casete.puntosCasette -= canciones[capa].puntos;
    }
    
    //Probamos no meterla
    if (capa == canciones.size() - 1){
        if (casete.puntosCasette > puntosMax){
            puntosMax = casete.puntosCasette;
        }
    }
    else{
        resolver(canciones, duracion, capa + 1, puntosMax, casete);
    }
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, duracion;
    cin >> n;
    if (n == 0) return false;
    cin >> duracion;
    vector<int> soluc(n);
    vector<Cancion> canciones(n);
    for (int i = 0; i < n; ++i)
        cin >> canciones[i].duracion >> canciones[i].puntos;

    


    int puntosMax = -1;
    Casette casette = {0, 0, 0};
    int capa = 0;
    resolver(canciones, duracion, capa, puntosMax, casette);
    // Salida
    cout << puntosMax << endl;
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
