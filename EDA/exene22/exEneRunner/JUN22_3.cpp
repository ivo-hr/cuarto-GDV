/*
Nombre y Apellidos:
DNI:
Puesto de laboratorio:
*/

#include <iostream>
#include <vector>
using namespace std;

int resolverProblema(const vector<int>& v, int start, int end) {
    // Divide y vencerás: compararé si el numero siguiente es el inmediatamente siguiente del anterior.
    // Si lo es, el ultimo numero de la serie está a la derecha
    // Si no, estará a la izquierda

    //si el vector esta vacio, no hacer nada
    if (v.empty())
        return -1;

    //Caso base: queda un unico elemento, o solo hay uno
    if (start == end)
        //Se comprueba si voy a coger el ultimo elemento de la lista, o el siguiente
        if (v[start] == v[0] + start)
            return v[start];
        else
            return v[start - 1];

    ////Caso base 2: quedan 2 elementos, se comparan
    //if (start == end - 1)
    //    if (v[start] == (v[end] - 1))
    //        return v[end];
    //    else
    //        return v[start];


    //Se coge la mitad
    int midway = start + ((end - start) / 2);

    //Si el anterior y el siguiente no son consecutivos, se mira a la izq.
    //También se mira si es un numero consecutivo desde el primer numero del vector
    if (v[midway] == v[0] + midway)
        return resolverProblema(v, midway + 1, end);
    else
        return resolverProblema(v, start, midway);
}

int main() {
    int casos;
    cin >> casos;

    while (casos--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        cout << resolverProblema(v, 0, n - 1) << endl;
    }

    return 0;
}