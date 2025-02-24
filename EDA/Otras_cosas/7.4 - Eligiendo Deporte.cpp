﻿#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct deporte {
    int puntos;
    string nombre;

    bool operator<(deporte& other) {
        return (puntos > other.puntos) || ((puntos == other.puntos) && nombre < other.nombre);
    }
};

void resolver(string const& primerDeporte, map<string, vector<string>>& listaNombres, map<string, int>& participantes) {
    string deporte, alumno;
    deporte = primerDeporte;
    map<string, vector<string>> apuntados;
    
    while (deporte != "_FIN_") {
        participantes.insert({ deporte, 0 });
        cin >> alumno;
        while (!isupper(alumno[0]) && alumno != "_FIN_") {

            if (listaNombres.find(alumno) != listaNombres.end()) {
                if (listaNombres.at(alumno).back() != deporte) {
                    listaNombres.at(alumno).push_back(deporte);
                }
            }
            else{
                vector<string> v{ deporte };
                listaNombres.insert({ alumno,  v});

            }
            
            cin >> alumno;
           
        }
        deporte = alumno;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
 //configuración, y escribiendo la respuesta
bool resuelveCaso() {
     //leer los datos de la entrada
    string primerDeporte;
    cin >> primerDeporte;
    if (!cin) return false;

    map<string, vector<string>> listaNombres;
    map<string, int> participantes; //recogeremos los distintos deportes para luego sumarlos todos aqui dentro
    vector<int> deportes;

    resolver(primerDeporte, listaNombres, participantes);
    
    for (auto i : listaNombres) {
        if (i.second.size() < 2)// si solo ha puesto su nombre en un deporte
        {
            participantes.at(i.second[0])++;
        }
    }

   // ordenamos 
    vector<deporte> v;
    for (auto i : participantes)
    {
        v.push_back({ i.second, i.first });
    }

    sort(v.begin(), v.end()); //n log(n)
    map<string, int> result;
    for (auto i : v) {
        cout << i.nombre << " " << i.puntos << '\n';
    }
    cout << "---\n";
    return true;
}

int main() {
    //  Para la entrada por fichero.
    //  Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    //  Para restablecer entrada. Comentar para acepta el reto
 #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
