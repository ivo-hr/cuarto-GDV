
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
//Tiene complejidad O(n^2), ya que recorre los dos vectores. Se ha intentado hacer con complejidad O(n), pero no se ha conseguido
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
                     vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv){

    //Se comparan los dos vectores, y se  ejecuta un bucle u otro en funcion de sus longitudes
    if (eda.size() < tpv.size()) {
        //Se recorre todo el vector, y se comprueba si un alumno esta en ambos listados
        for (int i = 0; i < tpv.size(); i++) {
            bool enComunes = false;
            for (int j = 0; j < eda.size(); j++) {
                if (tpv[i] == eda[j]) {
                    comunes.push_back(eda[j]);
                    enComunes = true;
                }
            }
            if (!enComunes)
                soloTpv.push_back(tpv[i]);
        }
        //En el otro vector se compara con el de los comunes, y se añaden los que no estan en ese vector
        for (int i = 0; i < eda.size(); i++) {
            bool enComunes = false;
            for (int j = 0; j < comunes.size(); j++) {
                if (eda[i] == comunes[j]) {
                    enComunes = true;
                }
            }
            if (!enComunes)
                soloEda.push_back(eda[i]);
        }
    }
    //Igual que arriba
    else {
        for (int i = 0; i < eda.size(); i++) {
            bool enComunes = false;
            for (int j = 0; j < tpv.size(); j++) {
                if (eda[i] == tpv[j]) {
                    comunes.push_back(tpv[j]);
                    enComunes = true;
                }
            }
            if (!enComunes)
                soloEda.push_back(eda[i]);
        }
        for (int i = 0; i < tpv.size(); i++) {
            bool enComunes = false;
            for (int j = 0; j < comunes.size(); j++) {
                if (tpv[i] == comunes[j]) {
                    enComunes = true;
                }
            }
            if (!enComunes)
                soloTpv.push_back(tpv[i]);
        }
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
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
    comparaListados(eda,tpv,comunes,soloEda,soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
// #ifndef DOMJUDGE
//     std::ifstream in("datos.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
// #endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
// #ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
//     //system("PAUSE");
// #endif

    return 0;
}
