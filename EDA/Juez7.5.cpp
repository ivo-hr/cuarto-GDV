#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


using movie = string;
using actN = string;

struct actor
{
    actN oscar;
    int min;
};

using movieCast = unordered_map<movie, vector<actor>>;

void readCast(int movieN, movieCast& movies) {
    movie mov; 
    actN actor; 
    int actN;
    int tim;
    for (int i = 0; i < movieN; ++i) {
        cin >> mov; cin >> actN;
        movieCast::iterator it = movies.find(mov);
        if (it == movies.end())
        {
            for (int j = 0; j < actN; ++j)
            {
                cin >> actor >> tim;
                movies[mov].push_back({ actor,tim });
            }
        }
    }
}


void emProc(movieCast cast, vector<string> const& secEm) {
    unordered_map<string, int> movies;
    map<actN, int> minActor;
    string topMov = "";
    int topEm = 0;
    for (int i = 0; i < secEm.size(); i++)
    {
        movies[secEm[i]]++;
        if (movies[secEm[i]] >= topEm)
        {
            topEm = movies[secEm[i]];
            topMov = secEm[i];
        }
    }
    cout << topEm << " " << topMov << "\n";
    map <actN, int> minXactor;
    int topActor = 0;
    for (auto it = movies.begin(); it != movies.end(); it++)
    {
        movieCast::iterator itCast = cast.find((*it).first);
        for (auto i = 0; i < (*itCast).second.size(); i++)
        {
            minXactor[(*itCast).second.at(i).oscar] += (*itCast).second.at(i).min * (*it).second;
            if (topActor < minXactor[(*itCast).second.at(i).oscar])
                topActor = minXactor[(*itCast).second.at(i).oscar];
        }
    }
    cout << topActor << " ";
    for (auto it = minXactor.begin(); it != minXactor.end(); it++)
        if (topActor == (*it).second)
            std::cout << (*it).first << " ";
    std::cout << "\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int movN, emN;
    cin >> movN;
    if (movN == 0)
        return false;

    movieCast casts;
    readCast(movN, casts);

    cin >> emN;
    vector<string> emSec(emN);
    for (string& s : emSec) cin >> s;

    emProc(casts, emSec);

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