//Enrique Juan Gamboa
//51547377F

//No me ha dado tiempo a:

/*
1. Aplicar todas las condiciones
2. Corregir errores de solución
3. Poda
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tDatos {
    int num_habitantes;
    int num_invitados;
    int hada;
    vector<vector<int>> satisfaccion;
};


void convite(tDatos& datos, int capa, int& satisAct, int& satisMax, int& numSoluc, int& superstic, int hadaMala){
    
    //cuando se llega mas allá de la última capa
    if (capa == datos.num_invitados){
        if (hadaMala){
            //Si la satisfacción es igual a la máxima, una solución mas
            if (satisAct == satisMax){
                numSoluc++;
            }
            //Si es mayor, por ahora es la única solución
            else if (satisAct > satisMax){
                numSoluc = 1;
                satisMax = satisAct;
            }
        }
        return;
    }

    for (int i = 0; i < datos.num_habitantes; i++){
        //Si se quiere quedar
        if (datos.satisfaccion[capa][i] >= 0){
            //Sumamos a la satisfaccion actual
            satisAct += datos.satisfaccion[capa][i];
            //Si estoy en el mismo numero, sumo a la superstición
            if (capa == i)
                superstic++;

            //Subo de capa
            capa++;
            //Si la capa en la que estoy es la del hada, true
            if (i == datos.hada)
                hadaMala = true;
            
            //Si aún no se ha llegado a ser más supersticioso
            if (superstic <= (datos.num_invitados / 3))
                convite(datos, capa, satisAct, satisMax, numSoluc, superstic, hadaMala);

            //Reiniciamos para el backtracking
            hadaMala = false;
            superstic--;
            capa--;
            satisAct -= datos.satisfaccion[capa][i];
        }
       

    }


}

bool resuelve_caso() {
    tDatos d;
    cin >> d.num_habitantes;

    if (d.num_habitantes == 0)
        return false;

    cin >> d.num_invitados >> d.hada;
    for (int i = 0; i < d.num_invitados; i++) {
        vector<int> aux;
        int sAux;
        for (int j = 0; j < d.num_habitantes; j++) {
            cin >> sAux;
            aux.push_back(sAux);
        }
        d.satisfaccion.push_back(aux);
    }

    int capa = 0;
        int satisAct = 0;
        int satisMax = 0;
        int numSoluc = 0;
        int supersticion = 0;
        vector<int> soluc;
        bool hadaMala = false;
        convite(d, capa, satisAct, satisMax, numSoluc, supersticion, hadaMala);

        if(numSoluc < 1){
            cout << "No" << endl;
        }
        else{
            cout << satisMax << numSoluc << endl;
        }



    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("datos.in");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
        std::ofstream out("datos.out");
        auto coutbuf = std::cout.rdbuf(out.rdbuf());
    #endif
        while (resuelve_caso()) {}

    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        std::cout.rdbuf(coutbuf);
    //    system("PAUSE");
    #endif
        return 0;
}
