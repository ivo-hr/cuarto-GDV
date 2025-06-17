/*
Nombre y Apellidos: [Tu nombre completo]
DNI: [Tu DNI]
Puesto de laboratorio: [Tu puesto]

Explicación:
- Esta función adelanta un segmento de la lista k posiciones
- Lo que he conseguido hacer: [Explica aquí lo que implementaste]
- Lo que no he conseguido hacer: [Explica aquí cualquier limitación]
*/

#include <iostream>
#include <list>
using namespace std;

// Función que adelanta un segmento de la lista k posiciones
void adelantarSegmento(list<char>& l, int n, int pos, int lon, int k) {
    //condicion inicial
    if (n <= 0 || pos < 0 || lon <= 0 || k <= 0)
        return;

    //Ajustamos lon si es más que la longitud del segmento
    if (pos + lon > n)
        lon = n - pos;


    //Rotamos a que la posición inicial esté al fernte
    for (int i = 0; i < pos; i++) {
        l.push_back(l.front());
        l.pop_front();
    }

    //Lista auxiliar en el que guardaremos el intervalo
    list<char> aux;
    for (int i = 0; i < lon; i++) {
        aux.push_back(l.front());
        l.pop_front();
    }

    //Desrotamos hasta el destino
    for (int i = 0; i < k; i++) {
        l.push_front(l.back());
        l.pop_back();
    }

    //insertamos la lista auxiliar
    for (int i = 0; i < lon; i++) {
        l.push_back(aux.front());
        aux.pop_front();
    }

    //Rerotamos a la posición original
    for (int i = 0; i < pos; i++) {
        l.push_front(l.back());
        l.pop_back();
    }
    for (int i = 0; i < k; i++) {
        l.push_back(l.front());
        l.pop_front();
    }

}

int main() {
    int casos;
    cin >> casos;

    while (casos--) {
        int n, pos, lon, k;
        cin >> n >> pos >> lon >> k;

        list<char> l;
        for (int i = 0; i < n; ++i) {
            char elem;
            cin >> elem;
            l.push_back(elem);
        }

        adelantarSegmento(l, n, pos, lon, k);

        // Mostrar la lista resultante
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (it != l.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}

/*
Cuestión: ¿Se tendría alguna ventaja al implementar la operación como método interno a la clase list?
Justificación: [Explica aquí tu respuesta cuando implementes la función]
*/