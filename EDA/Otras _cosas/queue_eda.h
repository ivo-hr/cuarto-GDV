//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//



//
//IMPORTANTE: ESTE ARCHIVO CONTIENE QUEU CON METODOS DE LOS EJERCICIOS      5_3 INVERIR UNA COLA(invertir),      5_4 EXAMEN FINAL ORDINARIA(cuela),      5_5 A LA COLA PEPSI COLA(cuela pringado)
//
//ALGUN DETALLE:    
//                  TIENE UN METODO IMPRIME COLA, ASI EVITAS DESTRUIRLO AL LEER FUERA DE LA CLASE, PERO NO SE PIDE EN NINGUN SITIO
// 
//                  EL EJERCICIO 5_3, EN EL METODO DE      invertir()      LE PREGUNTE A MIGUEL Y ME DIJO QUE NO ESTABA MAL, PERO 
//                  SI SE PUEDE HACER MEJOR CON 3 PUNTEROS A NODOS EN VEZ DE 5



#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error
#include <iostream>

template <class T>
class queue {
protected:
   
   /*
    Nodo que almacena internamente el elemento (de tipo T),
    y un puntero al nodo siguiente, que puede ser nullptr si
    el nodo es el último de la lista enlazada.
    */
   struct Nodo {
      Nodo() : sig(nullptr) {}
      Nodo(T const& el, Nodo * si = nullptr) : elem(el), sig(si) {}
      T elem;
      Nodo* sig;
   };

   // punteros al primer y último elemento
   Nodo* prim;
   Nodo* ult;

   // número de elementos en la cola
   int nelems;

public:

    // constructor: cola vacía
    queue() : prim(nullptr), ult(nullptr), nelems(0) {}

    // destructor
    ~queue() {
        libera();
    }

    // constructor por copia
    queue(queue<T> const& other) {
        copia(other);
    }

    // operador de asignación
    queue<T>& operator=(queue<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // añadir un elemento al final de la cola
    void push(T const& elem) {
        Nodo* nuevo = new Nodo(elem);

        if (ult != nullptr)
            ult->sig = nuevo;
        ult = nuevo;
        if (prim == nullptr) // la cola estaba vacía
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
        if (prim == nullptr) // la cola se ha quedado vacía
            ult = nullptr;
        delete a_borrar;
        --nelems;
    }

    // consultar si la cola está vacía
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño de la cola
    int size() const {
        return nelems;
    }

    void invertir() { //5_2

        if (!empty()) {

            Nodo* currNode = prim; Nodo* auxNode = currNode; Nodo* lastNode = nullptr; Nodo* nextNode;

            while (currNode->sig != nullptr) {
                nextNode = currNode->sig;
                currNode->sig = lastNode;
                lastNode = auxNode;
                currNode = auxNode = nextNode;
            }
            currNode->sig = lastNode;

            //finalmente damos la vuelta a los punteros de inicio y fin
            Nodo* newU = prim;
            prim = currNode;
            ult = newU;
        }

    }

    void cuela(const T& a, const T& b) { //coste lineal porque recorremos la cola una unica vez(O(n))

        Nodo* aux = prim; Nodo* ppb = nullptr; Nodo* antb;
        
        while (aux != nullptr &&aux->elem != a) {
            aux = aux->sig;
        }

        if (aux == nullptr)
            return;

        ppb = antb = aux;

        aux = aux->sig;

        while (aux != nullptr&&aux->elem != b)
        {
            antb = antb->sig;
            aux = aux->sig;
        }

        if (aux == nullptr)
            return;

        antb->sig = aux->sig;
        aux->sig = ppb->sig;
        ppb->sig = aux;


    };

    void cuelaPringado(const T& pr, queue<T>& q) {

        Nodo* aux = prim; Nodo* sigColada = nullptr;

        while (aux != nullptr && aux->elem != pr) {
            aux = aux->sig;
        }

        if (aux == nullptr)
            return;

        sigColada = aux->sig;

        Nodo* auxCol = q.prim;
        aux->sig = auxCol;
        q.ult->sig = sigColada;
        
        q.prim = nullptr;
        q.ult = nullptr;

    }

    void imprimeCola() {

        Nodo* aux =  prim;
        while (aux != nullptr) {
            std::cout << aux->elem << ' ';
            aux = aux->sig;
        }
        std::cout << '\n';
    }
protected:
   
   void libera() {
      while (prim != nullptr) {
         Nodo * a_borrar = prim;
         prim = prim->sig;
         delete a_borrar;
      }
      ult = nullptr;
   }
   
   // this está sin inicializar
   void copia(queue const& other) {
      if (other.empty()) {
         prim = ult = nullptr;
         nelems = 0;
      } else {
         Nodo * act = other.prim; // recorre la cola original
         Nodo * ant = new Nodo(act->elem); // último nodo copiado
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
};

#endif // queue_eda_h
