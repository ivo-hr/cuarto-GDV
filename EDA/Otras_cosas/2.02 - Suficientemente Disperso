// Eva Sanchez
// VJ60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esDisperso(const vector<int>& valores, int dispersion, int menor, int mayor)
{
    if (mayor == menor)
        return true;

    else if (mayor == menor + 1)
        return abs(valores[menor] - valores[mayor]) >= dispersion;

    if (abs(valores[menor] - valores[mayor]) < dispersion)
        return false;

    int mit = (menor + mayor) / 2;
    return esDisperso(valores, dispersion, menor, mit) && esDisperso(valores, dispersion, mit + 1, mayor);  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int tiradas, dispersion, num;
    cin >> tiradas >> dispersion;

    if (!cin)
        return false;

    vector<int>valores(tiradas);

    for (int i = 0; i < tiradas; i++)
    {
        cin >> num;
        valores[i] = num;
    }

    if (esDisperso(valores, dispersion, 0, tiradas - 1))
        cout << "SI\n";
    else
        cout << "NO\n";

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
