//Sebastian Sanchez Hombria
//VJ57


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

using namespace std;

template <class T>

class queue_plus : public queue<T> {

public:
    queue_plus(){};

    void mezclaOrdenada(queue_plus<T>& other) { //sea queueA el primer q y queueB el que pasamos por referencia

        if (!other.empty()) {
            auto A = this->prim; auto beforeA = this->prim; auto B = other.prim; auto Bnext = other.prim->sig; auto Blast = other.prim;

            if (!this->empty()) {

                while (A != this->ult->sig) { //recorremos qA
                    if (B != nullptr && A->elem > B->elem) {

                        //calculamos segmento a meter
                        while (Bnext != nullptr && Bnext->elem < A->elem) {
                            Blast = Bnext;
                            Bnext = Bnext->sig;
                        }

                        //insertamos segmento
                        if (A == this->prim) {
                            auto auxA = A;
                            this->prim = B;
                            Blast->sig = auxA;
                            B = Bnext;
                        }
                        else {
                            beforeA->sig = B;
                            Blast->sig = A;
                            B = Bnext;
                        }

                        other.prim = B;
                    }

                    beforeA = A;
                    A = A->sig;

                }
                //insertamos el resto de qB

                beforeA->sig = other.prim;
                other.prim = nullptr;
            }
            else {
                this->prim = B;
                
            }
        }
        other.prim = nullptr;

    };

    void escribeQueue() {
        for (auto i = this->prim; i != nullptr; i = i->sig)
        {
            cout << i->elem << ' ';
        }
        cout << '\n';
    };
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    queue_plus<int> q;
    queue_plus<int> q2;

    cin >> n;

    while (n!=0){
        q.push(n);
        cin >> n;
    }

    cin >> n;
    while (n != 0) {
        q2.push(n);
        cin >> n;
    }

    q.mezclaOrdenada(q2);
    // escribir sol
    q.escribeQueue();
    
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
