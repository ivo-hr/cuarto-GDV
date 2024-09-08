// Eva Sanchez
// VJ60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//El coste del algoritmo es lineal, ya que recorremos los vectores una sola vez, 
//añadiendo despues el coste del recorrido en el caso de que haya un vector mas
//grande que el otro. Coste = O(n ∗ log(n)) 

void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) 
{
    int tamEDA = eda.size(), tamTPV = tpv.size(); 
    int auxEDA = 0, auxTPV = 0;

    //Hacemos un bucle que comprueba si son iguales o no
    while (auxEDA < tamEDA && auxTPV < tamTPV)
    {
        if (eda[auxEDA] == tpv[auxTPV])
        {
            comunes.push_back(eda[auxEDA]);
            auxEDA++;
            auxTPV++;
        }
            
        else
        {
            //En el caso de que la letra de eda sea menor que la de TPV
            //áñadimos la letra a la lista de EDA y aumentamos su valor
            if (eda[auxEDA] < tpv[auxTPV])
            {
                soloEda.push_back(eda[auxEDA]);
                auxEDA++;
            }
            
            //Y en el caso contrario, hacemos lo mismo pero con las 
            //variables de TPV
            else
            {
                soloTpv.push_back(tpv[auxTPV]);
                auxTPV++; 
            }        
        }
    }

    //En el caso de que el vector de EDA sea mayor, hacemos un recorrido 
    //para añadir el resto de letras
    if (auxEDA < tamEDA)
    {
        for (int i = auxEDA; i < tamEDA; i++)
            soloEda.push_back(eda[i]);
    }

    //Y hacemos lo mismo si se da el caso contrario con las de TPV
    else if (auxTPV < tamTPV)
    {
        for (int i = auxTPV; i < tamTPV; i++)
            soloTpv.push_back(tpv[i]);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int n;
    cin >> n;
    vector<string> eda(n);
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;
    for (string& e : eda) cin >> e;
    cin >> n;
    vector<string> tpv(n);
    for (string& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
