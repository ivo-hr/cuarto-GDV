//Enrique Juan Gamboa
//EDA-GDV36

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Tiene un coste de O(n) siendo n el tamaño de la palabra más grande (solo se realizan for uno detrás de otro)
bool anagramas(const string& cad1, const string& cad2) {
    if (cad1.size() != cad2.size())
        return false;

    //Vector en el que guardaremos el número de veces que aparece cada letra en ambas palabras
    std::vector<int> numletras(26, 0);

    //Sumamos en la posicion de la letra en el vector el número de veces que aparece en la palabra cad1
    //Restamos en la posicion de la letra en el vector el número de veces que aparece en la palabra cad2
    for (int i = 0; i < cad1.size(); i++) {
        numletras[cad1[i] - 'a']++; //Restamos 'a' para que la letra 'a' sea la posición 0 del vector
        numletras[cad2[i] - 'a']--;
    }

    //Comprobamos si el vector es de ceros
    for (int i = 0; i < 26; ++i)
        if (numletras[i] != 0)
            return false; //En cuanto encontramos que una letra no cumple, se sale del bucle devolviendo false

    //Se llega aquí solo si no se cuplio la condicion en el for anterior
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    cout << (anagramas(word1,word2) ? "SI" : "NO") << endl;
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