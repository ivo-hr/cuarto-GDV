//
//  queue_eda.h
//
//  Implementaci�n del TAD cola con nodos enlazados
//  y punteros al primero y al �ltimo nodo
//
//  Estructuras de Datos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:

    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el �ltimo de la lista enlazada.
     */
    struct Nodo {
        Nodo() : sig(nullptr) {}
        Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
        T elem;
        Nodo* sig;
    };

    // punteros al primer y �ltimo elemento
    Nodo* prim;
    Nodo* ult;

    // n�mero de elementos en la cola
    int nelems;

public:

    // constructor: cola vac�a
    queue() : prim(nullptr), ult(nullptr), nelems(0) {}

    // destructor
    ~queue() {
        libera();
    }

    // constructor por copia
    queue(queue<T> const& other) {
        copia(other);
    }

    // operador de asignaci�n
    queue<T>& operator=(queue<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // a�adir un elemento al final de la cola
    void push(T const& elem) {
        Nodo* nuevo = new Nodo(elem);

        if (ult != nullptr)
            ult->sig = nuevo;
        ult = nuevo;
        if (prim == nullptr) // la cola estaba vac�a
            prim = nuevo;
        ++nelems;
    }

    // consultar el primero de la cola
    T const& front() const {
        if (empty())
            throw std::domain_error("la cola vacia no tiene primero");
        return prim->elem;
    }

    // eliminar el primero de la cola
    void pop() {
        if (empty())
            throw std::domain_error("eliminando de una cola vacia");
        Nodo* a_borrar = prim;
        prim = prim->sig;
        if (prim == nullptr) // la cola se ha quedado vac�a
            ult = nullptr;
        delete a_borrar;
        --nelems;
    }

    // consultar si la cola est� vac�a
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tama�o de la cola
    int size() const {
        return nelems;
    }

protected:

    void libera() {
        while (prim != nullptr) {
            Nodo* a_borrar = prim;
            prim = prim->sig;
            delete a_borrar;
        }
        ult = nullptr;
    }

    // this est� sin inicializar
    void copia(queue const& other) {
        if (other.empty()) {
            prim = ult = nullptr;
            nelems = 0;
        }
        else {
            Nodo* act = other.prim; // recorre la cola original
            Nodo* ant = new Nodo(act->elem); // �ltimo nodo copiado
            prim = ant;
            while (act->sig != nullptr) {
                act = act->sig;
                ant->sig = new Nodo(act->elem);
                ant = ant->sig;
            }
            ult = ant;
            nelems = other.nelems;
        }
    }

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

        //Si el nodo B era el ultimo, seteamos el anterior como �ltimo
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

#endif // queue_eda_h
