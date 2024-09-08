//Eva Sanchez Muñoz
//VJ60 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;

class Hora
{

protected:

    int hora;
    int minuto;
    int segundo;

    char separator;

public:

    Hora() : hora(0), minuto(0), segundo(0) {}

    Hora(const int& h, const int& min, const int& s) : hora(h), minuto(min), segundo(s)
    {
        bool inferior = h <= 23 && min <= 59 && s <= 59;
        bool superior = h >= 0 && min >= 0 && s >= 0;

        if (!(inferior && superior))
            throw std::domain_error("ERROR");
    }

    Hora operator + (const Hora& h) const
    {
        Hora hour = *this; 

        hour.hora += h.hora;
        hour.minuto += h.minuto;
        hour.segundo += h.segundo;

        hour.minuto += hour.segundo / 60;
        hour.hora += hour.minuto / 60;

        hour.segundo %= 60;
        hour.minuto %= 60;

        return hour; 
    }

    bool operator < (const Hora& h) const
    {
        if (hora < h.hora)
            return true;

        else if (hora == h.hora)
        {
            if (minuto < h.minuto)
                return true;

            else if (minuto == h.minuto)
            {
                if (segundo < h.segundo)
                    return true;
            }
        }

        return false;
    }

    friend std::istream& operator >> (std::istream& is, Hora& h)
    {
        is >> h.hora >> h.separator >> h.minuto >> h.separator >> h.segundo;

        return is;
    }

    friend std::ostream& operator << (std::ostream& os, const Hora& h)
    {
        os << std::setfill('0') << std::setw(2) << h.hora;
        os << h.separator;
        os << std::setfill('0') << std::setw(2) << h.minuto;
        os << h.separator;
        os << std::setfill('0') << std::setw(2) << h.segundo;

        return os;
    }
};

class Pelicula {

private:

    Hora final, inicio, duracion;
    char separator;

    string titulo;

public:

    bool operator < (const Pelicula& p) const {

        if (!((final < p.final) || (p.final < final)))
            return titulo.compare(p.titulo) < 0;

        return final < p.final;

    }

    friend std::istream& operator >> (std::istream& is, Pelicula& p);
    friend std::ostream& operator << (std::ostream& os, const Pelicula& p);

};

inline std::ostream& operator << (std::ostream& os, const Pelicula& p) 
{
    os << p.final << p.titulo;

    return os;
}

inline std::istream& operator >> (std::istream& is, Pelicula& p) {

    is >> p.inicio;
    is >> p.duracion;
    getline(is, p.titulo);
    p.final = p.inicio + p.duracion;

    return is;
}

bool resuelveCaso()
{
    int n; 
    cin >> n; 

    if (n == 0)
        return false; 

    vector<Pelicula> cartelera(n);

    for (Pelicula& p : cartelera)
        cin >> p;

    sort(cartelera.begin(), cartelera.end());

    for (Pelicula& p : cartelera)
        cout << p << "\n";

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
    system("PAUSE");
#endif

    return 0;
}
