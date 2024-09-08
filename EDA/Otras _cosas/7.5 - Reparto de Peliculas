#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

//Eva Sanchez Muñoz 
//VJ60

using namespace std;

using actorNombre = string;

struct Actor
{
    actorNombre actorName;
    int minutes;
};

using Pelicula = string;
using RepartoPeliculas = unordered_map<Pelicula, vector<Actor>>;

void leerRepartos(int n, RepartoPeliculas& movies)
{
    Pelicula film;
    int nActores, minutes;

    //Hacemos un recorrido del numero de peliculas
    for (int i = 0; i < n; i++)
    {
        cin >> film >> nActores;

        RepartoPeliculas::iterator it = movies.find(film);

        if (it == movies.end())
        {
            actorNombre actor;

            for (int i = 0; i < nActores; i++)
            {
                cin >> actor >> minutes;
                movies[film].push_back({actor, minutes});
            }
        }
    }
}

void procesarEmisiones(RepartoPeliculas reparto, vector<string>& emisiones)
{
    //Pelicula  

    unordered_map<string, int> peliculas;

    string maxName;
    int tam = emisiones.size(), maxEmision = 0;

    for (int i = 0; i < tam; i++)
    {
        unordered_map<string, int>::iterator it = peliculas.find(emisiones[i]);

        if (it == peliculas.end())
        {
            peliculas.insert({ emisiones[i], 1 });

            if (maxEmision == 0)
                maxEmision = 1;

            maxName = emisiones[i]; 
        }

        else
        {
            (*it).second++;

            if (maxEmision <= (*it).second)
            {
                maxName = (*it).first;
                maxEmision = (*it).second;
            }
        }
    }

    cout << maxEmision << " " << maxName << "\n";

    //-------------------------------------------------------

    //Actores 

    int maxTime = 0;
    auto i = peliculas.begin();

    map <actorNombre, int> minutosActor;

    while (i != peliculas.end())
    {
        unordered_map<Pelicula, vector<Actor>>::iterator it =
            reparto.find((*i).first);

        if (it != reparto.end())
        {
            int tamIt = (*it).second.size(); 

            for (int j = 0; j < tamIt; j++)
            {
                map<actorNombre, int>::iterator it1 =
                    minutosActor.find((*it).second.at(j).actorName);

                if (it1 == minutosActor.end())
                {
                    minutosActor.insert({ (*it).second.at(j).actorName,
                        (*it).second.at(j).minutes * (*i).second });

                    if (maxTime < (*it).second.at(j).minutes * (*i).second)
                        maxTime = (*it).second.at(j).minutes * (*i).second;
                }

                else
                {
                    (*it1).second += (*it).second.at(j).minutes * (*i).second;

                    if (maxTime < (*it1).second)
                        maxTime = (*it1).second;
                }
            }
        }

        i++;
    }

    cout << maxTime << " ";

    auto x = minutosActor.begin();

    while (x != minutosActor.end())
    {
        if (maxTime == (*x).second)
            cout << (*x).first << " ";

        x++;
    }

    cout << "\n";
}

bool resuelveCaso()
{
    int n;
    cin >> n;

    if (n == 0)
        return false;

    else
    {
        RepartoPeliculas movies;
        leerRepartos(n, movies);

        int nActores;
        cin >> nActores;

        string actorName;
        vector<string> emisiones;

        for (int i = 0; i < nActores; i++)
        {
            cin >> actorName;
            emisiones.push_back(actorName);
        }

        procesarEmisiones(movies, emisiones);

        return true;
    }
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
