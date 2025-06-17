/*
Nombre completo:
DNI: N/A
Usuario del juez: N/A
Puesto de laboratorio: N/A
Qué has conseguido hacer y qué no:
He implementado el algoritmo de vuelta atrás completo con poda por viabilidad, pero no he incluido una poda por estimación.

Tupla solución: Un vector donde cada posición representa un voluntario y el valor en esa posición representa el área a la que está asignado (-1 si no está asignado).

Marcadores:
- Un vector para llevar la cuenta del lodo retirado en cada área
- Un contador de áreas completamente limpias
- Un acumulador del total de lodo retirado
- Un valor para guardar la mejor solución encontrada

Ejemplo de aplicación de poda por estimación:
Podríamos estimar el máximo potencial de lodo que se puede retirar sumando el máximo que cada voluntario no asignado podría aportar (el máximo de sus capacidades en cualquier área). Si esta estimación más lo ya retirado no supera el mejor valor encontrado hasta ahora, podamos.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, vector<T> const& v) {
    for (auto& e : v) out << e << " ";
    return out;
}

void resolver(vector<int>& soluc, int k, int n, int m, int l,
    vector<int>& kilosPorArea, vector<vector<int>> const& kilosPorVoluntario,
    vector<int>& lodoRetirado, int areasLimpias, int totalRetirado,
    int& maxRetirado, bool& posible) {

    // Caso base: todos los voluntarios asignados
    if (k == n) {
        // Comprobamos si se cumple la condición de áreas limpias
        if (areasLimpias >= l) {
            if (totalRetirado > maxRetirado) {
                maxRetirado = totalRetirado;
                posible = true;
            }
        }
        return;
    }

    // Probamos asignar el voluntario k a cada área posible
    for (int area = 0; area < m; area++) {
        // Asignamos el voluntario k al área 'area'
        soluc[k] = area;
        int incremento = kilosPorVoluntario[k][area];

        // Actualizamos estadísticas
        bool estabaLimpia = (lodoRetirado[area] >= kilosPorArea[area]);
        lodoRetirado[area] += incremento;
        totalRetirado += incremento;

        bool ahoraLimpia = (lodoRetirado[area] >= kilosPorArea[area]);
        int nuevoAreasLimpias = areasLimpias;
        if (!estabaLimpia && ahoraLimpia) {
            nuevoAreasLimpias++;
        }
        else if (estabaLimpia && !ahoraLimpia) {
            nuevoAreasLimpias--;
        }

		//Seguimos con la siguiente asignación
        resolver(soluc, k + 1, n, m, l, kilosPorArea, kilosPorVoluntario,
            lodoRetirado, nuevoAreasLimpias, totalRetirado, maxRetirado, posible);
        

        // Deshacemos los cambios para probar otras opciones
        lodoRetirado[area] -= incremento;
        totalRetirado -= incremento;
    }
}

void resuelveCaso() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> kilosPorArea(m);
    for (int i = 0; i < m; ++i) {
        cin >> kilosPorArea[i];
    }
    vector<vector<int>> kilosPorVoluntario(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> kilosPorVoluntario[i][j];

    vector<int> soluc(n, -1); // Cada posición representa un voluntario, el valor es el área asignada
    vector<int> lodoRetirado(m, 0);
    int maxRetirado = 0;
    bool posible = false;

    resolver(soluc, 0, n, m, l, kilosPorArea, kilosPorVoluntario,
        lodoRetirado, 0, 0, maxRetirado, posible);

    if (!posible) cout << "IMPOSIBLE" << endl;
    else cout << maxRetirado << endl;
}


 #define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
