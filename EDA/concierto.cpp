
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
//soluc será la solución del problema dado con el orden de los artistas (si maxBenef = -1 no se ha encontrado solución)
//k es la capa del árbol en la que estamos
//n es el número de elementos (en este caso, grupos)
//actBenef es el beneficio actual
//maxBenef es el beneficio máximo encontrado hasta ahora, se usará para dar la solución final
//visit es un vector de booleanos que indica si un grupo ha sido visitado o no, se reinicia el empezar una nueva rama
//benef es la matriz de beneficios de los grupos, dependidndo de en qué posicion actuan
//cons es la matriz de consentimientos, si cons[i][j] = true, el grupo i puede actuar después del grupo j
void resolver(vector<int>& soluc, int k, int n, int actBenef, int& maxBenef, vector<bool>& visit,
                vector<vector<int>> const& benef, vector<vector<bool>> const& cons){
    
    //Por cada grupo
    for(int i = 0; i < n; i++){
        //Guardamos el grupo en la solución (por ahora)
        soluc[k] = i;
        //si no ha sido visitado (relevante para las ramas inferiores) y si es el 1er grupo o hay consentimiento
        //(k es la capa en la que estamos, k-1 la anterior. yo soy el grupo de que actuará en la capa k,
        //y el grupo de la capa k-1 es el último que ha actuado. Si estoy de acuerdo en actuar después de ellos, palante)
        if(!visit[i] && (k == 0 || cons[soluc[k]][soluc[k-1]])){
            //Subo el beneficio actual de la rama
            actBenef += benef[i][k];
            //He visitado este grupo
            visit[i] = true;
            //Si k (numero de capa) es igual a n-1 (numero de grupos contador desde 0), hemos llegado al final
            if(k == n-1){
                //Si el beneficio actual es mayor que el máximo encontrado hasta ahora, actualizamos el máximo
                if(actBenef > maxBenef) 
                    maxBenef = actBenef;
            }
            //Si no hemos llegado al final, seguimos bajando por el árbol llamando a la función recursivamente,
            //subiendo la (k)apa en la que estamos
            else 
                resolver(soluc, k+1, n, actBenef, maxBenef, visit, benef, cons);

            //Después de bajar por toda la rama, empezamos a deshacer lo que hemos hecho
            //para poder seguir probando con otras ramas (en el bucle for)
            actBenef -= benef[i][k];
            visit[i] = false;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<vector<int>> beneficios(n,vector<int>(n));
    vector<vector<bool>> consentimientos(n,vector<bool>(n));
    for (int i = 0; i < n ; ++i)
        for (int j = 0; j < n; ++j)
            cin >> beneficios[i][j];

    for (int i = 0; i < n ; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }

    vector<int> soluc(n);
    vector<bool> visitado(n, false);
    int mejoresBeneficios = -1;
    int beneficiosActuales = 0;
    int k = 0;
    resolver(soluc, k, n, beneficiosActuales, mejoresBeneficios, visitado, beneficios, consentimientos);
    // salida
    if (mejoresBeneficios == -1)
        cout << "NEGOCIA CON LOS ARTISTAS" << endl;
    else
        cout<< mejoresBeneficios << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
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
