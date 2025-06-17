#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Asumimos que existe la clase Fecha con operadores de orden
struct Fecha {
    int d, m, a;

    bool operator<(const Fecha& other) const {
        if (a != other.a) return a < other.a;
        if (m != other.m) return m < other.m;
        return d < other.d;
    }
    // Operador de entrada para leer fechas en formato dd/mm/aa
    friend istream& operator>>(istream& is, Fecha& f) {
        char sep;
        is >> f.d >> sep >> f.m >> sep >> f.a;
        return is;
    }

    // Operador de salida para mostrar fechas
    friend ostream& operator<<(ostream& os, const Fecha& f) {
        if (f.d < 10) os << "0";
        os << f.d << "/";
        if (f.m < 10) os << "0";
        os << f.m << "/";
        if (f.a < 10) os << "0";
        os << f.a;
        return os;
    }
};

class Tienda {
private:
    // Para cada producto: mapa ordenado de fecha -> cantidad disponible
    unordered_map<string, map<Fecha, int>> almacen;

    // Para cada producto: cola de clientes esperando
    unordered_map<string, queue<string>> listas_espera;

public:
    // Constructora: almacén vacío y no hay clientes en espera
    Tienda() {}

    // Adquirir CANT unidades del producto COD con fecha F
    // Devuelve vector con clientes servidos en orden de llegada
    vector<string> adquirir(const string& COD, const Fecha& F, int CANT) {

        vector<string> clientes_servidos;

        //Primero damos producto a los clientes en espera
        while (CANT > 0 && !listas_espera[COD].empty()) {
            //Añadimos el cliente servido
            clientes_servidos.push_back(listas_espera[COD].front());
            //Lo quitamos de la lista de espera
            listas_espera[COD].pop();
            //Quitamos una unidad
            CANT--;
        }

        //Si queda algo, lo metemos al almacén
        if (CANT > 0) {
            almacen[COD][F] += CANT;
        }


        //Devolvemos los clientes que hemos servido
        return clientes_servidos;
    }

    // Vender una unidad del producto COD al cliente CLI
    // Devuelve {éxito, fecha} - fecha solo válida si éxito = true
    pair<bool, Fecha> vender(const string& COD, const string& CLI) {
        // Verificar si hay existencias
        if (almacen[COD].empty()) {
            //Metemos al cliente en la lista de espera
            listas_espera[COD].push(CLI);
            return { false, Fecha{} };
        }

        //Si las hay, vendemos el producto y quitamos una unidad del almacén
        //Cogemos la primera entrada del mapa ordenado
        auto it = almacen[COD].begin();
        Fecha f = it->first;
        it->second--;
        if (it->second == 0)
            almacen[COD].erase(it);

        return { true, f };
    }

    // Devuelve cuántas unidades tiene la tienda del producto COD
    int cuantos(const string& COD) {
        int total = 0;
        //Para cada entrada del producto en su fecha, se le suma la cantidad de esa fecha
        for (const auto& cant : almacen[COD])
            total += cant.second;
        return total;
    }

    // Indica si hay clientes en la lista de espera del producto COD
    bool hay_esperando(const string& COD) {
        return !listas_espera[COD].empty();
    }
};

void resuelveCaso() {
    Tienda tienda;
    string operacion;

    while (cin >> operacion && operacion != "FIN") {
        if (operacion == "adquirir") {
            string codigo;
            Fecha fecha;
            int cantidad;
            cin >> codigo >> fecha >> cantidad;

            vector<string> servidos = tienda.adquirir(codigo, fecha, cantidad);

            cout << "PRODUCTO ADQUIRIDO";
            for (const string& cliente : servidos) {
                cout << " " << cliente;
            }
            cout << endl;

        }
        else if (operacion == "vender") {
            string codigo, cliente;
            cin >> codigo >> cliente;

            auto resultado = tienda.vender(codigo, cliente);

            if (resultado.first) {
                cout << "VENDIDO " << resultado.second << endl;
            }
            else {
                cout << "EN ESPERA" << endl;
            }

        }
        else if (operacion == "cuantos") {
            string codigo;
            cin >> codigo;
            cout << tienda.cuantos(codigo) << endl;

        }

        else if (operacion == "hay_esperando") {
            string codigo;
            cin >> codigo;
            cout << (tienda.hay_esperando(codigo) ? "SI" : "NO") << endl;
        }
    }

    cout << "---" << endl;
}

int main() {
    resuelveCaso();
    return 0;
}