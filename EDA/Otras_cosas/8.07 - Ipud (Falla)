//Eva Sanchez Muñoz
//VJ60 

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
#include <exception>


using namespace std;

using duracion = int;
using cancion = string;
using artista = string;


class Ipud
{
protected: 

    struct cancionInfo
    {
        artista artist;
        duracion duration;

        std::list<cancion>::iterator playlistSongsIterator;
        std::list<cancion>::iterator recentSongsIterator;
    };

    std::list<cancion> playlistSongs;
    std::list<cancion> recentSongs;

    std::unordered_map<cancion, cancionInfo> memoria;

    int tiempoTotal; 

public:

    Ipud() { tiempoTotal = 0; }

    void addSong(const cancion& s, const artista& a, const duracion& d)
    {
        if (memoria.count(s) > 0)
            throw domain_error("ERROR AddSong");

        else
        {
            memoria[s].artist = a;
            memoria[s].duration = d;

            memoria[s].recentSongsIterator = recentSongs.end();
            memoria[s].playlistSongsIterator = playlistSongs.end();
        }
    }

    void addToPlaylist(const cancion& c) 
    {
        if (memoria.count(c) == 0)
            throw domain_error("ERROR AddPlaylist");
        
        if (memoria[c].playlistSongsIterator == playlistSongs.end())
        {
            memoria[c].playlistSongsIterator = playlistSongs.insert(playlistSongs.end(), c); 
            tiempoTotal += memoria[c].duration; 
       }
    }

    cancion current() 
    {
        if (playlistSongs.empty())
            throw domain_error("ERROR current");

        else
            return playlistSongs.front(); 
    }

    cancion play() 
    {
        if (!playlistSongs.empty())
        {
            cancion actual = playlistSongs.front(); 
            playlistSongs.pop_front(); 

            if (memoria[actual].recentSongsIterator != recentSongs.end())
                recentSongs.erase(memoria[actual].recentSongsIterator); 

            memoria[actual].recentSongsIterator = recentSongs.insert(recentSongs.begin(), actual); 
            tiempoTotal -= memoria[actual].duration; 

            memoria[actual].playlistSongsIterator = playlistSongs.end(); 

            return actual; 
        }

        else
            return "ERROR"; 
    }

    int totalTime() 
    {
        if (playlistSongs.empty())
            return 0;
        else
            return tiempoTotal; 
    }

    list<cancion> recent(int& n) 
    {
        list<cancion> lista; 

        if (n > 0 && recentSongs.size() > 0)
        {
            if (recentSongs.size() < n)
            {
                n = recentSongs.size();
                return recentSongs;
            }

            else
            {
                for (auto const& i : recentSongs)
                    lista.push_back(i);

                return lista;
            }
        }

        else
            return lista; 
    }

    void deleteSong(cancion c) 
    {
        if (memoria.count(c) > 0)
        {
            if (!recentSongs.empty() && memoria[c].recentSongsIterator != recentSongs.end())
            {
                recentSongs.erase(memoria[c].recentSongsIterator); 
                memoria[c].recentSongsIterator = recentSongs.end(); 
            }

            if (!playlistSongs.empty() && memoria[c].playlistSongsIterator != playlistSongs.end())
            {
                playlistSongs.erase(memoria[c].playlistSongsIterator); 
                memoria[c].playlistSongsIterator = playlistSongs.end(); 
            }

            memoria.erase(c); 
        }
    }
};


bool resuelveCaso()
{
    Ipud ipud; 

    string accion, song; 
    cin >> accion;

    while (accion != "FIN")
    {
        try {
            if (accion == "addSong")
            {
                string artist;
                int duration;

                cin >> song >> artist >> duration;

                ipud.addSong(song, artist, duration);
            }

            else if (accion == "addToPlaylist")
            {
                cin >> song;

                ipud.addToPlaylist(song);
            }

            else if (accion == "play")
            {
                cancion song = ipud.play();

                if (song != "ERROR")
                    cout << "Sonando " << song << "\n";

                else
                    cout << "No hay canciones en la lista\n";
            }
            
            else if (accion == "current")
            {
                ipud.current();
            }

            else if (accion == "totalTime")
                cout << "Tiempo total " << ipud.totalTime() << "\n";

            else if (accion == "deleteSong")
            {
                cin >> song;

                ipud.deleteSong(song);
            }

            else if (accion == "recent")
            {
                int n;
                cin >> n; 

                list<string> lista = ipud.recent(n);

                if (lista.empty())
                    cout << "No hay canciones recientes\n";
                
                else
                {
                    cout << "Las " << n << " mas recientes\n";

                    for (auto const& i : lista)
                        cout << "    " << i << "\n";
                }
            }

            cin >> accion;
        }

        catch (domain_error e) 
        {
            cout << e.what() << endl;
            cin >> accion;
        }
    }

    std::cout << "---\n";

    return true;
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
