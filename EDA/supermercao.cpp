#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using tMatriz = vector<vector<int>>;

// Comprobamos que se han cogido solo 3 productos
bool esValida(const vector<int>& mercadosMarcados, const int& nMercadosVisitados) {

    return mercadosMarcados[nMercadosVisitados] < 3; // Nos aseguramos que solo pilla 3 productos x mercado como mucho
}

void supermercado(vector<int>& sol, const int& k, const int& mercados, const int& totalProductos, const tMatriz& precios, vector<int>& mercadosMarcados, int costeAc, int& masBarato, bool& haySol) {

    for (int i = 0; i < mercados; ++i) 
    {
        sol[k] = i; // Meto nueva variable

        // Comprobamos si es valido
        if (esValida(mercadosMarcados, i)) 
        { 
            costeAc += precios[i][k]; // Sumamos el precio del producto k, del mercado i

            mercadosMarcados[i]++; // Añadimos el producto del mercado

            // Comprobamos si hemos mirado todo el mercado
            if (k + 1 == totalProductos) 
            { 
                if (costeAc < masBarato) // Es mejor solución
                {
                    masBarato = costeAc;
                }

                haySol = true;
            }
            else 
            {
                if (costeAc < masBarato) // Si todavia no sobrepasamos el limite, seguimos comprando
                {
                    supermercado(sol, k + 1, mercados, totalProductos, precios, mercadosMarcados, costeAc, masBarato, haySol);
                }
            }

            costeAc -= precios[i][k]; // Quitamos el precio del producto
            mercadosMarcados[i]--; // Devolvemos el producto
        }
    }
}


void resuelveCaso() {
    int mercados, productos;
    cin >> mercados;
    cin >> productos;

    tMatriz precios(mercados, vector<int>(productos));  

    vector<int> minimos;

    vector<int> marcas(mercados);

    vector<int> sol(3 * mercados);

    int masBarato = 0;

    // Coste cuadratico
    for (int i = 0; i < mercados; ++i) 
    {
        for (int j = 0; j < productos; ++j) 
        {
            cin >> precios[i][j];       // Guardamos los precios del mercado i
            masBarato += precios[i][j]; // Sumamos el total de todos los precios
        }
    }

    bool haySol = false;
    if (mercados == 0 || productos == 0)
        cout << 0 << endl;
    else 
    {
        supermercado(sol, 0, mercados, productos, precios, marcas, 0, masBarato, haySol);
        if (haySol)
            cout << masBarato << "\n";
        else
            cout << "Sin solucion factible\n";
    }
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}