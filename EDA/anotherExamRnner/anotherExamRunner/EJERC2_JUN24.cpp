#include <iostream>
#include <vector>
using namespace std;



vector<char> tuplaSolucion;

bool procesarCaso(int M, const vector<int>& numeros, int pos, int calcPorAhora) {
    // Implementar la lógica de backtracking aquí

    //Caso base: hemos llegado al final de la lista de números
    if (pos == numeros.size()) {
        // Verificar si la suma actual es igual a M
        return calcPorAhora == M;
    }


    //PODA POR SUMA/RESTA MÁXIMA POSIBLE DESDE DONDE ESTAMOS
    int sumaRestante = 0;
    for (int i = pos; i < numeros.size(); i++)
        sumaRestante += numeros[i];

    //Si el número final no está en el intervalo de todo restado/todo sumado, no se va a poder llegar nunca
    if (M > calcPorAhora + sumaRestante || M < calcPorAhora - sumaRestante)
        return false;

    // Recursividad: probamos sumar
    tuplaSolucion[pos] = '+';
    if (procesarCaso(M, numeros, pos + 1, calcPorAhora + numeros[pos]))
        return true;

    //Probamos restar
    tuplaSolucion[pos] = '-';
    if (procesarCaso(M, numeros, pos + 1, calcPorAhora - numeros[pos]))
        return true;

    //Si nada funciona
    return false;
}

int main() {
    int casos;
    cin >> casos;

    for (int i = 0; i < casos; ++i) {
        int M, n;
        cin >> M >> n;

        vector<int> numeros(n);
        for (int j = 0; j < n; ++j) {
            cin >> numeros[j];
        }

        if (n == 0) { // Caso especial cuando no hay números
            if (M == 0) {
                cout << "SI" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            continue;
        }

        // Llamar a la función que procesa el caso
        //El primer número siempre se suma
        int calcPorAhora = numeros[0];
        //Se empieza por el siguiente numero
        int pos = 1;
        //La tupla solucion es el signo para cada número. el del primero siempre será positivo.
        tuplaSolucion.resize(n);
        tuplaSolucion[0] = '+';
        if (procesarCaso(M, numeros, pos, calcPorAhora)) {
            cout << "SI" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}