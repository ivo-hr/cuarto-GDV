#include <iostream>
#include <stdexcept>
#include <fstream>
#include <unordered_map>
#include <list>

using namespace std;

using Libro = string;

class eReader {
private:
    struct InfoLibro {
        int numPags;
        int pagActual;
        list<Libro>::iterator posSecAbiertos;
    };
    unordered_map<Libro,InfoLibro> libros;
    list<Libro> secAbiertos;

public:
    // O(1)
    eReader() { };

    // O(1)
    void poner_libro(const Libro& x, int n) {
        // si el libro ya esta no se hace nada
        // Se crea la informacion del libro
        InfoLibro infoL = {n,1,secAbiertos.end()};
        libros.insert({x, infoL}); // Se inserta en la tabla, O(1)
    }

    // O(1)
    void abrir(const Libro& x) {
        auto itL = libros.find(x); // O(1)
        if (itL == libros.end()) throw std::domain_error("Libro no encontrado");
        else { // El libro esta en la tabla. Consulta su informacion
            InfoLibro infoL = itL->second;
            if (infoL.posSecAbiertos != secAbiertos.end()) {
                // Si esta abierto lo elimina de su posicion
                secAbiertos.erase(infoL.posSecAbiertos); // Coste constante!
            }
            // Añade el libro al principio de la lista y guarda el iterador
            infoL.posSecAbiertos = secAbiertos.insert(secAbiertos.begin(),x); // O(1)
        }
    }

    // O(1)
    void avanzar_pag() {
        // Si no hay ningun libro abierto produce error
        if (secAbiertos.empty()) throw std::domain_error("Ningun libro abierto");
        else {// Si hay libros abiertos. Obtiene el primero
            Libro l = secAbiertos.front(); // O(1)
            // incrementa la pagina en la informacion de la tabla
            InfoLibro& infoL = libros[l]; // O(1)
            infoL.pagActual++;
            // Si la pagina es mayor que la ultima vuelve a la primera
            if (infoL.pagActual > infoL.numPags)
                infoL.pagActual = 1;
        }
    }

    // O(1)
    const Libro& abierto() const {
        if (secAbiertos.empty()) throw std::domain_error("Ningun libro abierto");
        else return secAbiertos.front(); // O(1)
    }

    // O(1)
    int pag_libro(const Libro& x) const {
        auto itL = libros.find(x); // O(1)
        if (itL == libros.end()) throw std::domain_error("Libro no encontrado");
        else return itL->second.pagActual;
    }

    // O(1)
    void elim_libro(const Libro& x) {
        auto itL = libros.find(x); // O(1)
        if (itL != libros.end()) {
            InfoLibro infoL = itL->second;
            // Si el libro esta abierto lo elimina de la lista
            if (infoL.posSecAbiertos != secAbiertos.end()) {
                secAbiertos.erase(infoL.posSecAbiertos); // O(1)
                libros.erase(x); // Mejor libros.erase(itL); (solo versión STL), // O(1)
            }
        }
    }

    // O(n), n = el parametro de entrada
    list<Libro> recientes(int n) const {
        list<Libro> l;
        for (auto it = secAbiertos.cbegin(); it != secAbiertos.cend() && n > 0; n--, ++it)
            l.push_back(*it);
        return l;
    }
};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    eReader reader;
    while (comando != "FIN") {
        try {
            if (comando == "poner_libro") {
                Libro l; int n;
                cin >> l >> n;
                reader.poner_libro(l, n);
            } else if (comando == "abrir") {
                Libro l;
                cin >> l;
                reader.abrir(l);
            } else if (comando == "avanzar_pag") {
                reader.avanzar_pag();
            } else if (comando == "abierto") {
                Libro l = reader.abierto();
                cout << "Leyendo " << l << endl;
            } else if (comando == "pag_libro") {
                Libro l;
                cin >> l;
                int n = reader.pag_libro(l);
                cout << "Libro " << l << " por pagina " << n << endl;
            } else if (comando == "elim_libro") {
                Libro l;
                cin >> l;
                reader.elim_libro(l);
            } else if (comando == "recientes") {
                int n;
                cin >> n;
                cout << "Ultimos libros abiertos: ";
                for (const auto l : reader.recientes(n))
                    cout << l << " ";
                cout << endl;
            }
        } catch (std::exception &e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("../../Ejercicios/08EReader/reader1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) { }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
