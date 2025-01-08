#include <iostream>
#include <vector>
#include <set>

using namespace std;


// Suma de los cuadrados de un numero

int sumaCuadrados(int n){
    int toReturn = 0;

    while(n > 0){
        toReturn += (n%10)*(n%10);
        n /= 10;
    }

    return toReturn;
}

// Chequear si un numero es feliz

bool esFeliz(int num){

    set<int> numeros;
    vector<int> numerosCalculados;

    //mientras no se encuentre un 1 y no se repita el número
    //(.find(x) devuelve el iterador .end() si no se encuentra x) 
    while (num != 1 && numeros.find(num) == numeros.end()){
        numeros.insert(num);
        numerosCalculados.push_back(num);

        num = sumaCuadrados(num);
    }
    //añadimos el último número
    numerosCalculados.push_back(num);

    for (int i = 0; i < numerosCalculados.size(); i++){
        cout << numerosCalculados[i] << " ";
    }

    return num == 1;
}

int main(){
    
    while (true){
        int n;
        cin >> n;

        if (esFeliz(n)){
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }


    return 0;
}