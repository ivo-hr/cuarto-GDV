#include <iostream>
#include "list_eda.h"

// Extensión del TAD list con el método partition
template <class T>
class extended_list : public list<T> {
public:
    // Hereda todos los constructores de list
    using list<T>::list;

    void partition(int pivote) {
        if (this->empty()) return;

        // Punteros para manejar las dos sublistas
        typename list<T>::Nodo* menor_inicio = nullptr;
        typename list<T>::Nodo* menor_fin = nullptr;
        typename list<T>::Nodo* mayor_inicio = nullptr;
        typename list<T>::Nodo* mayor_fin = nullptr;

        // Recorremos la lista original
        typename list<T>::Nodo* actual = this->fantasma->sig;

        while (actual != this->fantasma) {
            typename list<T>::Nodo* siguiente = actual->sig;

            // Desenganchamos el nodo actual
            actual->ant->sig = actual->sig;
            actual->sig->ant = actual->ant;

            // Lo colocamos en la sublista correspondiente
            if (actual->elem <= pivote) {
                // Va a la sublista de menores o iguales
                if (menor_inicio == nullptr) {
                    menor_inicio = menor_fin = actual;
                    actual->ant = actual->sig = actual; // Lista circular de un elemento
                }
                else {
                    // Insertamos al final de la sublista de menores
                    actual->ant = menor_fin;
                    actual->sig = menor_inicio;
                    menor_fin->sig = actual;
                    menor_inicio->ant = actual;
                    menor_fin = actual;
                }
            }
            else {
                // Va a la sublista de mayores
                if (mayor_inicio == nullptr) {
                    mayor_inicio = mayor_fin = actual;
                    actual->ant = actual->sig = actual; // Lista circular de un elemento
                }
                else {
                    // Insertamos al final de la sublista de mayores
                    actual->ant = mayor_fin;
                    actual->sig = mayor_inicio;
                    mayor_fin->sig = actual;
                    mayor_inicio->ant = actual;
                    mayor_fin = actual;
                }
            }

            actual = siguiente;
        }

        // Reenlazamos las sublistas con el nodo fantasma
        if (menor_inicio != nullptr && mayor_inicio != nullptr) {
            // Tenemos ambas sublistas
            this->fantasma->sig = menor_inicio;
            menor_inicio->ant = this->fantasma;
            menor_fin->sig = mayor_inicio;
            mayor_inicio->ant = menor_fin;
            mayor_fin->sig = this->fantasma;
            this->fantasma->ant = mayor_fin;
        }
        else if (menor_inicio != nullptr) {
            // Solo tenemos sublista de menores
            this->fantasma->sig = menor_inicio;
            menor_inicio->ant = this->fantasma;
            menor_fin->sig = this->fantasma;
            this->fantasma->ant = menor_fin;
        }
        else if (mayor_inicio != nullptr) {
            // Solo tenemos sublista de mayores
            this->fantasma->sig = mayor_inicio;
            mayor_inicio->ant = this->fantasma;
            mayor_fin->sig = this->fantasma;
            this->fantasma->ant = mayor_fin;
        }
        // Si ambas son nullptr, la lista queda vacía (solo el fantasma)
    }
};

// Programa principal para resolver el ejercicio
int main() {
    int n, pivote;

    while (std::cin >> n >> pivote) {
        extended_list<int> lista;

        // Leemos los elementos y los insertamos en la lista
        for (int i = 0; i < n; i++) {
            int elem;
            std::cin >> elem;
            lista.push_back(elem);
        }

        // Aplicamos partition
        lista.partition(pivote);

        // Escribimos el resultado
        bool primero = true;
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (!primero) std::cout << " ";
            std::cout << *it;
            primero = false;
        }
        std::cout << std::endl;
    }

    return 0;
}