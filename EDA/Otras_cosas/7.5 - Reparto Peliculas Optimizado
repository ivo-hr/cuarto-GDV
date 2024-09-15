#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


using Pelicula = string;
using nombreActor = string;

struct actor
{
    nombreActor act;
    int minutes;
};

using RepartosPeliculas = unordered_map<Pelicula, vector<actor>>;// Nombre pelicula y actores involucrados

void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
    Pelicula peli; int numActores;
    nombreActor actor; int minutos;
    for (int i = 0; i < numPeliculas; ++i) {
        cin >> peli; cin >> numActores;
        
        RepartosPeliculas::iterator it = peliculas.find(peli);

        // Si la pelicula no existe, la creamos y metemos todos los actores
        if (it == peliculas.end())
        {
            for (int j = 0; j < numActores; ++j)
            {
                cin >> actor >> minutos;
                peliculas[peli].push_back({ actor,minutos});
            }
        }
    }
}


void procesarEmisiones(RepartosPeliculas repartos, vector<string> const& secEmisiones) {
    unordered_map<string, int> peliculas;
    map<nombreActor,int> minActor;
    string topPeli = "";
    int topEmision = 0;
    
    for (int i = 0; i < secEmisiones.size(); i++)
    {
        // Si la peli no existe, se crea con valor 1 por defecto, si existe, simplemente se suma su valor
        peliculas[secEmisiones[i]]++;
        if (peliculas[secEmisiones[i]] >= topEmision)
        {
            topEmision = peliculas[secEmisiones[i]];
            topPeli = secEmisiones[i];
        }
    }

    // Ultima pelicula mas emitida
    cout << topEmision << " " << topPeli << "\n";
    
    // Comparar actores
    map <nombreActor, int> minutosXActor;
    int topActor = 0;

    // Recorremos todas las peliculas emitidas
    for (auto it = peliculas.begin(); it != peliculas.end(); it++)
    {
        RepartosPeliculas::iterator itReparto = repartos.find((*it).first); 

        // Recorremos todos los actores de la pelicula emitida
        for (auto i = 0; i < (*itReparto).second.size(); i++)
        {
            // Si el actor no esta, se le añade con su tiempo correspondiente. Si existe, simplemente se le suma el tiempo extra
            minutosXActor[(*itReparto).second.at(i).act] += (*itReparto).second.at(i).minutes * (*it).second; // Minutos del actor * nº de emisiones de la peli
        
            // Si su tiempo en pantalla es mayor que el maximo
            if (topActor < minutosXActor[(*itReparto).second.at(i).act])
            {
                topActor = minutosXActor[(*itReparto).second.at(i).act];
            }
        }

    }

    // Escribimos todos los actores y el maximo de tiempo
    cout << topActor << " ";
    for (auto it = minutosXActor.begin(); it != minutosXActor.end(); it++)
    {
        if (topActor == (*it).second) // Si el actor tiene el maximo tiempo, lo metemos (como esta ordenado alfabeticamente, da igual)
        {
            std::cout << (*it).first << " ";
        }
    }
    std::cout << "\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
