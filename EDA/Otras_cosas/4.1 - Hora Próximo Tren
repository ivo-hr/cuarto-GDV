//Eva Sanchez Muñoz
//VJ60 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

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

bool resuelveCaso() 
{
    int nTrenes, horaSalida; 
    cin >> nTrenes >> horaSalida;

    if (nTrenes == 0 && horaSalida == 0)
        return false;

    int hora, minuto, segundo;
    char puntos;

    vector<Hora>horario(nTrenes);

    for (Hora& h : horario)
        cin >> h;

    for (int i = 0; i < horaSalida; i++)
    {
        try
        {
            cin >> hora >> puntos >> minuto >> puntos >> segundo;

            Hora h(hora, minuto, segundo);

            auto aux = std::lower_bound(horario.begin(), horario.end(), h);

            if (aux == horario.end())
                cout << "NO" << std::endl;
            else
                std::cout << *aux << std::endl;
        }

        catch (const std::domain_error& de)
        {
            std::cout << de.what() << std::endl;
        }
    }

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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
