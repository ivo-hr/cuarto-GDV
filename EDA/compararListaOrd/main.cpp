//Enrique Juan Gamboa
//EDA-GDV36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
//Tiene un coste de O(n) siendo n el tamaño del vector más grande de los dos.
//El bucle while se ejecuta m veces (siendo m el vector más pequeño), y el bucle for se ejecuta n-m veces.
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
                     vector<string>& comunes, vector<string>& soloEda,
                     vector<string>& soloTpv){

    //Contadores de posición para recorrer los vectores
    int posEda = 0, posTpv = 0;

    //Mientras no se haya llegado al final de ninguno de los dos vectores,
    //se comparan los elementos de ambos vectores y se añaden a los vectores correspondientes
    while(posEda < eda.size() && posTpv < tpv.size()){
        //Si los elementos son iguales, se añaden al vector de comunes y se incrementan las posiciones
        if(eda[posEda] == tpv[posTpv]){
            comunes.push_back(eda[posEda]);
            posEda++;
            posTpv++;
        }
        //Si el elemento de eda es menor que el de tpv, se añade al vector de soloEda y se incrementa la posición de eda
        else if(eda[posEda] < tpv[posTpv]){
            soloEda.push_back(eda[posEda]);
            posEda++;
        }
        //Y viceversa
        else{
            soloTpv.push_back(tpv[posTpv]);
            posTpv++;
        }
    }
    //Si no se ha llegado al final de alguno de los dos vectores, se añaden los elementos restantes al vector correspondiente
    if (posEda < eda.size()){
        for (int i = posEda; i < eda.size(); i++){
            soloEda.push_back(eda[i]);
        }
    }
    else if (posTpv < tpv.size()){
        for (int i = posTpv; i < tpv.size(); i++){
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
