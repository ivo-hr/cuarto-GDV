#include <iostream>
#include <iomanip>
#include <fstream>

#include"bintree_eda.h"

//El coste del ejercicio es 

using namespace std; 

template <class T>

void resolver(const bintree<T>& tree, int& cont, int& sumPrev, int& sumPos)
{
    //Si el arbol es vacio, devolvemos 0. Si no, comprobamos los lados
    if (!tree.empty())
    {
        int der = 0, izq = 0;

        //Hallamos mediante el uso de recursividad el valor de los 
        //numeros situados a la izquierda
        if (!tree.left().empty())
        {
            sumPrev += tree.root();
            resolver(tree.left(), cont, sumPrev, sumPos);
            sumPrev -= tree.root();
            izq = sumPos;
        }

        //Repetimos el proceso con los valores situados a la derecha 
        if (!tree.right().empty())
        {
            sumPrev += tree.root();
            resolver(tree.right(), cont, sumPrev, sumPos);
            sumPrev -= tree.root(); 
            der = sumPos;
        }

        //Obtenemos el valor de los numeros situados debajo 
        //de la posicion actual (Es decir, el valor de los posteriores) 
        sumPos = der + izq;

        //Si el valor de los posteriores coincide con el de 
        //los anteriores, se añade uno al contador 
        if (sumPrev == sumPos)
            cont++;

        sumPos += tree.root(); 
    }

    else
        sumPos = 0; 
}

void resuelveCaso() 
{
    bintree<int> tree; 
    tree = leerArbol(-1); 

    int cont = 0, sumPre = 0, sumPos = 0; 

    resolver(tree, cont, sumPre, sumPos);

    cout << cont << "\n"; 
}

int main() 
{
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
     #endif 
    
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

     #ifndef DOMJUDGE 
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
