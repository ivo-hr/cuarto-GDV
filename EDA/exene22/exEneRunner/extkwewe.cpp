#include "queue_eda.h"

template <class T>
class ExtQueue : public queue<T> {
public:
    void cuela(const T& a, const T& b) {

        //No hay suficientes cosas para colarlo
        if (empty() || nelems < 2)
            return;

        Nodo* nodoA = nullptr;
        Nodo* act = prim;

        //Busco a
        while (act != nullptr && act->elem != a)
            act = act->sig;

        //Si no lo encuentro
        if (act == nullptr)
            return;

        nodoA = act;

        //Busco el nodo b, y tengo que guardarme el anterior
        Nodo* nodoB = nullptr;
        Nodo* antB = nullptr;

        //Seteamos el nodo actual al siguiente
        act = nodoA->sig;
        //Seteamos el nodo anterior a b
        antB = nodoA;

        //buscamos el nodo b mientras seteamos su anterior
        while (act != nullptr && act->elem != b) {
            antB = act;
            act = act->sig;
        }
        //Si no lo encontramos, salimos
        if (act == nullptr)
            return;

        //Seteamos el nodo b
        nodoB = act;

        //Si ya estaba bien colocado, nos ahorramos el movimiento
        if (nodoA->sig == nodoB)
            return;

        //Si el nodo B era el ultimo, seteamos el anterior como último
        if (nodoB->sig == nullptr)
            ult = antB;
        //Si no, el siguiente del anterior a b es el siguiente de b (me lo salto)
        else
            antB->sig = nodoB->sig;
        //El siguiente del nodo B va a ser el siguiente de nodo A
        nodoB->sig = nodoA->sig;
        //El siguiente de nodo A va a ser el nodo B
        nodoA->sig = nodoB;
    }
};