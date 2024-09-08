// David Brey Plaza
// VJ08

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
using namespace std;

using libro = string;
using vendidos = int;

struct infoLibro 
{
    int ejemplares = 0;
    vendidos v = 0;
    list<libro>::const_iterator it;
};

using listaLibros = unordered_map<libro, infoLibro>;

class VentaLibros 
{
    listaLibros libros;
    map<vendidos, list<libro>, greater<vendidos>> topVentas;

public:

    //O(1)
    void nuevoLibro(int n, const libro& x) 
    { 
        libros[x].ejemplares += n; // Si existe, simplemente lo suma, si no lo crea y le asigna el valor n
    }

    //O(logn)
    void comprar(const libro& x) 
    { 
        auto it = libros.find(x);

        if(it == libros.end())
            throw out_of_range("Libro no existente");
        else
        {
            if ((*it).second.ejemplares <= 0)
                throw invalid_argument("No hay ejemplares");
            else
            {
                // Si esta metido, lo sacamos
                if (it->second.v > 0)
                    topVentas[it->second.v].erase(it->second.it);
                
                // Bajamos los ejemplares y subimos las ventas
                (*it).second.ejemplares--;
                it->second.v++;


                auto& itTop = topVentas[it->second.v];
                itTop.push_front(it->first);
                it->second.it = itTop.begin();

            }
            
        }
    }

    //O(1)
    bool estaLibro(const libro& x)  
    { 
        auto it = libros.find(x);
        if (it != libros.end())
            return true;
        else
            return false;
    }

    //Si no hay ventas, O(1), si hay entonces O(logn)
    void elimLibro(const libro& x) 
    { 
        auto it = libros.find(x);
        if (it != libros.end())
        {
            // Si ha vendido algun libro, lo sacamos de la lista de ventas
            if (it->second.v > 0)
                topVentas[it->second.v].erase(it->second.it);
            libros.erase(it);
        }

    }

    //O(1)
    int numEjemplares(const libro& x)  
    { 
        auto it = libros.find(x);
        if (it != libros.end())
            return (*it).second.ejemplares;
        else
            throw invalid_argument("Libro no existente");
    }

    //O(n). N = maximo de libros
    list<libro> top10()  
    { 
        auto it = topVentas.begin();
        list<libro> res;

        for (int i = 0; i < 10 && it != topVentas.end(); it++) 
        {
            // Cogemos todos los libros que hayan hecho X ventas hasta vaciar la lista de esa posicion o hasta llegar a 10 libros
            for (auto itLista = it->second.begin(); itLista != it->second.end() && i < 10; i++) 
            {
                res.push_back(*itLista);
                itLista++;
            }
        }

        return res;
    }

};

// Muestra el contenido de una lista
template <class T>
void mostrar(list<T> const& l) 
{
    for (auto const& e : l) {
        cout << e << '\n';
    }
}

bool resuelveCaso() 
{

    int numOp;

    cin >> numOp;
    if (!cin) return false;

    VentaLibros amazon;

    string operacion, titulo;

    for (int i = 0; i < numOp; ++i) {
        cin >> operacion;
        cin.ignore(1); // saltar blanco
        if (operacion == "nuevoLibro") {
            int unidades;
            cin >> unidades;
            cin.ignore(1);
            getline(cin, titulo);
            amazon.nuevoLibro(unidades, titulo);
        }
        else if (operacion == "comprar") {
            getline(cin, titulo);
            try {
                amazon.comprar(titulo);
            }
            catch (out_of_range const& e) {
                cout << e.what() << '\n';
            }
            catch (invalid_argument const& e) {
                cout << e.what() << '\n';
            }
        }
        else if (operacion == "estaLibro") {
            getline(cin, titulo);
            if (amazon.estaLibro(titulo)) {
                cout << "El libro " << titulo << " esta en el sistema\n";
            }
            else {
                cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "elimLibro") {
            getline(cin, titulo);
            amazon.elimLibro(titulo);
        }
        else if (operacion == "numEjemplares") {
            getline(cin, titulo);
            if (amazon.estaLibro(titulo)) {
                cout << "Existen " << amazon.numEjemplares(titulo) << " ejemplares del libro " << titulo << '\n';
            }
            else {
                cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "top10") {
            cout << "TOP10\n";
            mostrar(amazon.top10());
        }
    }
    // fin del caso
    cout << "---\n";
    return true;
    
}

int main() {

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
    //system("PAUSE");
#endif

}
