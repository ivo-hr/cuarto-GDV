//Enrique Juan Gamboa
//EDA-GDV36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
/*

using namespace std;

// función que resuelve el problema

//He conseguido que el problema sea de complejidad O(n), ya que sólo recorro los vectores una vez cada uno
//haciendo uso de un vector auxiliar de tamaño 26, que me permite saber si un alumno va a ambos, sólo a eda, o sólo a tpv
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
                     vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv){

    //Buscamos la mayor longitud del dato de entrada de entre los dos vectores
    int maxAlumnos = 1;
    for (int i = 0; i < eda.size(); i++) {
        if (eda[i].size() > maxAlumnos) maxAlumnos = eda[i].size();
    }
    for (int i = 0; i < tpv.size(); i++) {
        if (tpv[i].size() > maxAlumnos) maxAlumnos = tpv[i].size();
    }

    //Vector auxiliar con el que determinaremos si un alumno sólo va a eda, a tpv, o a ambos
    //Sera de tamaño 26 * maxAlumnos, ya que cada alumno tiene una combinación de letras asociado, y el vector tiene que tener un tamaño suficiente
    std::vector<int> alumni((26 * maxAlumnos) + 1,0);

    //Si un alumno va a eda, se le suma 2 al vector alumni
    for (int i = 0; i < eda.size(); i++) {
        int index = 0;
        for (int j = 0; j < eda[i].size(); j++) {
            index += (eda[i][j]);
        }
        alumni[index] += 2;
    }
    //Si un alumno va a tpv, se le resta 1 al vector alumni
    for (int i = 0; i < tpv.size(); i++) {
        int index = 0;
        for (int j = 0; j < tpv[i].size(); j++) {
            index += (tpv[i][j]);
        }
        alumni[index] -= 1;
    }
    //Esto hace que, si un alumno va a ambos, el valor en alumni sea 1, si sólo va a eda, el valor sea 2, y si sólo va a tpv, el valor sea -1
    //Así podemos ignorar el valor 0 en el vector alumni (no hay alumno)
    for (int i = 0; i < alumni.size(); i++) {
        if (alumni[i] == 1) {
            comunes.push_back(string(1, 'a' + i));
        } else if (alumni[i] == 2) {
            soloEda.push_back(string(1, 'a' + i));
        } else if (alumni[i] == -1) {
            soloTpv.push_back(string(1, 'a' + i));
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(){
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
*/