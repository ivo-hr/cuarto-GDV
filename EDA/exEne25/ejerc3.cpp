/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:

Idea: crear dos unordered_map:
    1. Mapa de jugadores, con el historial de equipos a los que ha pertenecido (unordered_map<Jugador, vector<Equipo>)
    2. Mapa de equipos, en el que se guardará el nombre del equipo, el jugador y su timestamp (unordered_map<Equipo, pair<Jugador, time>>)

*/

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <list>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using Jugador = string;
using Equipo = string;

class GestorFutbolistas {
private:
    unordered_map<Jugador, vector<Equipo>> historialJugador;
    unordered_map<Equipo, vector<Jugador>> fichajesEquipo;
    unordered_map<Jugador, unordered_set<Equipo>> equiposUnicos;

public:
    // Coste: 
    void fichar(const Jugador& jugador, const Equipo& equipo) {
        //1º: Mirar si el jugador ya existe en el mapa de jugadores
        auto itJugador = historialJugador.find(jugador);
        //Si no está
        if (itJugador == historialJugador.end()) {
            //se crea un jugador nuevo
            historialJugador[jugador].push_back(equipo);
            //se le mete en el equipo
            fichajesEquipo[equipo].push_back(jugador);
            //se añade al historial de equipos diferentes
            equiposUnicos[jugador].insert(equipo);
        }
        else {
            //Se busca al jugador en el equipo en el que estaba
            Equipo oldEquipo = itJugador->second.back();
            //si el equipo es el mismo
            if (oldEquipo == equipo)
                return;
            //Si no
            auto& Fichajes = fichajesEquipo[oldEquipo];
            //Se borra del equipo viejo
            for (int i = 0; i < Fichajes.size(); i++) {
                if (Fichajes[i] == jugador) {
                    Fichajes.erase(Fichajes.begin() + i);
                    break;
                }
            }
            //Y se le mete en el nuevo
            fichajesEquipo[equipo].push_back(jugador);
            //Se añade el nuevo equipo al historial del jugador y a la lista de equipos en los que ha estado
            historialJugador[jugador].push_back(equipo);
            equiposUnicos[jugador].insert(equipo);
        }


    }

    // Coste:
    Equipo equipoActual(const Jugador& jugador) const {

        //1º: Mirar si el jugador existe en el mapa de jugadores
        auto itJugador = historialJugador.find(jugador);
        //Si no está
        if (itJugador == historialJugador.end())
            throw domain_error("Jugador inexistente");

        //Si está
        return itJugador->second.back();

    }

    // Coste:
    int fichados(const Equipo& equipo) const {
        auto itEquipos = fichajesEquipo.find(equipo);
        if (itEquipos == fichajesEquipo.end())
            throw domain_error("Equipo inexistente");

        return itEquipos->second.size();
    }

    // Coste: 
    list<Jugador> ultimosFichajes(const Equipo& equipo, int n) const {
        auto itEquipos = fichajesEquipo.find(equipo);
        if (itEquipos == fichajesEquipo.end())
            throw domain_error("Equipo inexistente");

        list<Jugador> toRet;
        //Esto hace que si no hay ningún fichaje devuelva nada sin romperse
        int startPoint = max(0, (int)itEquipos->second.size() - 1 - n);
        int endPoint = max(0, (int)itEquipos->second.size() - 1);

        for (int i = startPoint; i < endPoint; i++) {
            toRet.push_back(itEquipos->second.at(i));
        }

        return toRet;
    }

    // Coste:
    int cuantosEquipos(const Jugador& jugador) const {
        auto itJugador = equiposUnicos.find(jugador);
        if (itJugador == equiposUnicos.end())
            return 0;
        else
            return itJugador->second.size();
    }
};


bool resuelveCaso() {
    string operacion;
    cin >> operacion;
    if (!cin) return false;

    GestorFutbolistas gestor;
    while (operacion != "FIN") {
        try {
            if (operacion == "fichar") {
                string jugador, equipo;
                cin >> jugador >> equipo;
                gestor.fichar(jugador, equipo);
            }
            else if (operacion == "equipo_actual") {
                string jugador;
                cin >> jugador;
                string equipo = gestor.equipoActual(jugador);
                cout << "El equipo de " << jugador << " es " << equipo << endl;
            }
            else if (operacion == "fichados") {
                string equipo;
                cin >> equipo;
                int n = gestor.fichados(equipo);
                cout << "Jugadores fichados por " << equipo << ": " << n << endl;
            }
            else if (operacion == "ultimos_fichajes") {
                string equipo;
                int n;
                cin >> equipo >> n;
                list<string> ultimos = gestor.ultimosFichajes(equipo, n);
                cout << "Ultimos fichajes de " << equipo << ": ";
                for (const auto& jugador : ultimos) {
                    cout << jugador << " ";
                }
                cout << endl;
            }
            else if (operacion == "cuantos_equipos") {
                string jugador;
                cin >> jugador;
                int n = gestor.cuantosEquipos(jugador);
                cout << "Equipos que han fichado a " << jugador << ": " << n << endl;
            }
        }
        catch (std::exception& e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> operacion;
    }

    cout << "---\n";
    return true;
}

#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
    ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
