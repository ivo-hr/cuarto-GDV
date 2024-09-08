#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
using namespace std;

using book = string;
using sold = int;

struct bookInfo 
{
    int bookNum = 0;
    sold v = 0;
    list<book>::const_iterator it;
};

using bookList = unordered_map<book, bookInfo>;

class BookSell 
{
    bookList books;
    map<sold, list<book>, greater<sold>> topSellers;

public:

    //O(1)
    void newBook(int n, const book& x) 
    { 
        books[x].bookNum += n;
    }

    //O(logn)
    void comprar(const book& x) 
    { 
        auto it = books.find(x);

        if(it == books.end())
            throw out_of_range("Libro no existente");
        else
        {
            if ((*it).second.bookNum <= 0)
                throw invalid_argument("No hay ejemplares");
            else
            {
                if (it->second.v > 0)
                    topSellers[it->second.v].erase(it->second.it);

                (*it).second.bookNum--;
                it->second.v++;


                auto& itTop = topSellers[it->second.v];
                itTop.push_front(it->first);
                it->second.it = itTop.begin();

            }
            
        }
    }

    //O(1)
    bool isThereBook(const book& x)  
    { 
        auto it = books.find(x);
        if (it != books.end())
            return true;
        else
            return false;
    }

    //O(1) si no se vende, si sí O(logn)
    void eraseBook(const book& x) 
    { 
        auto it = books.find(x);
        if (it != books.end())
        {
            if (it->second.v > 0)
                topSellers[it->second.v].erase(it->second.it);
            books.erase(it);
        }

    }

    //O(1)
    int numOfBooks(const book& x)  
    { 
        auto it = books.find(x);
        if (it != books.end())
            return (*it).second.bookNum;
        else
            throw invalid_argument("Libro no existente");
    }

    //O(n) N = libros máx
    list<book> top10()  
    { 
        auto it = topSellers.begin();
        list<book> res;

        for (int i = 0; i < 10 && it != topSellers.end(); it++) 
        {
            for (auto listIt = it->second.begin(); listIt != it->second.end() && i < 10; i++) 
            {
                res.push_back(*listIt);
                listIt++;
            }
        }

        return res;
    }

};

template <class T>
void show(list<T> const& l) 
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

    BookSell amazon;

    string op, title;

    for (int i = 0; i < numOp; ++i) {
        cin >> op;
        cin.ignore(1);
        if (op == "nuevoLibro") {
            int unidades;
            cin >> unidades;
            cin.ignore(1);
            getline(cin, title);
            amazon.newBook(unidades, title);
        }
        else if (op == "comprar") {
            getline(cin, title);
            try{amazon.comprar(title);}
                
            catch (out_of_range const& e){cout << e.what() << '\n';}

            catch (invalid_argument const& e){cout << e.what() << '\n';} 
        }
        else if (op == "estaLibro") {
            getline(cin, title);
            if (amazon.isThereBook(title))
                cout << "El libro " << title << " esta en el sistema\n";
            else
                cout << "No existe el libro " << title << " en el sistema\n";
        }
        else if (op == "elimLibro") {
            getline(cin, title);
            amazon.eraseBook(title);
        }
        else if (op == "numEjemplares") {
            getline(cin, title);
            if (amazon.isThereBook(title))
                cout << "Existen " << amazon.numOfBooks(title) << " ejemplares del libro " << title << '\n';
            else
                cout << "No existe el libro " << title << " en el sistema\n";
        }
        else if (op == "top10") {
            cout << "TOP10\n";
            show(amazon.top10());
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