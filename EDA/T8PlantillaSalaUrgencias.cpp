/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no: 
*/

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <cassert>
#include <utility>

#include <unordered_map>
#include <list>
#include <set>

using namespace std;


using paciente = string;
using gravedad = int;

class urgencias {
protected:

    struct info_paciente {
        gravedad g;
        list<paciente>::iterator pos;
    };

    //El mapa de pacientes
    unordered_map<paciente, info_paciente> pacientes;
    list<paciente> leves;
    list<paciente> moderados;
    list<paciente> graves;  

    set<paciente> sanos;

public:

    // coste:
    void nuevo_paciente(paciente p, gravedad g) {
        
        if (pacientes.find(p) != pacientes.end())
            throw domain_error("Paciente repetido");
        if (g < 1 || g > 3)
            throw domain_error("Gravedad incorrecta");
        
        info_paciente info = {g, }; //Se crea la info del paciente
        switch (g) {
            case 1:
                leves.push_back(p);
                info.pos = --leves.end();
                break;
            case 2:
                moderados.push_back(p);
                info.pos = --moderados.end();
                break;
            case 3:
                // graves.push_back(p);
                // info.pos = --graves.end();
                // es lo mismo que esto:
                info.pos = graves.insert(graves.end(), p);

                break;
            
            pacientes.insert({p, info}); //Se inserta en el mapa
        }

    }
    
    // coste:
    int gravedad_actual(paciente p) const {
        if (pacientes.find(p) == pacientes.end())
            throw domain_error("Paciente inexistente");
        
        return pacientes.at(p).g;
    }

    // coste:
    paciente siguiente() {
        if (leves.empty() && moderados.empty() && graves.empty())
            throw domain_error("No hay pacientes");
        
        if (!graves.empty()) {
                paciente p = graves.front();
                graves.pop_front();
                return p;
        } else if (!moderados.empty()) {
            paciente p = moderados.front();
            moderados.pop_front();
            return p;
        } else {
            paciente p = leves.front();
            leves.pop_front();
            return p;
        }
    }

    // coste:
    void mejora(paciente p) {
        if (pacientes.find(p) == pacientes.end())
            throw domain_error("Paciente inexistente");
        
        info_paciente info = pacientes.at(p);

        switch (info.g) {
            case 1:
                leves.erase(info.pos);

                sanos.insert(p);
                break;
            case 2:
                moderados.erase(info.pos);

                leves.push_back(p);
                info.pos = --leves.end();
                break;
            case 3:
                graves.erase(info.pos);

                moderados.push_back(p);
                info.pos = --moderados.end();
                break;
        }
    }

    // coste:
    list<paciente> recuperados() const {
        return list<paciente>(sanos.begin(), sanos.end());
    }


};

bool resuelveCaso() { // No tocar esta función
    string orden, pac;
    int grav;
    cin >> orden;
    if (!cin) return false;
   
    urgencias sala;
   
    while (orden != "FIN") {
        try {
            if (orden == "nuevo_paciente") {
                cin >> pac >> grav;
                sala.nuevo_paciente(pac, grav);
            } else if (orden == "gravedad_actual") {
                cin >> pac;
                int g = sala.gravedad_actual(pac);
                cout << "La gravedad de " << pac << " es " << g << '\n';
            } else if (orden == "siguiente") {
                string p = sala.siguiente();
                cout << "Siguiente paciente: " << p << '\n';
            } else if (orden == "recuperados") {
                auto lista = sala.recuperados();
                cout << "Lista de recuperados:";
                for (auto & p : lista)
                    cout << ' ' << p;
                cout << '\n';
            } else if (orden == "mejora") {
                cin >> pac;
                sala.mejora(pac);
            } 
        } catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

#define DOMJUDGE
int main() {

#ifndef DOMJUDGE
    ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
