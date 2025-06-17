#include <iostream>
#include <vector>
using namespace std;



vector<char> tuplaSolucion;

bool procesarCaso(int M, const vector<int>& numeros, int pos, int calcPorAhora) {
    // Implementar la l�gica de backtracking aqu�

    //Caso base: hemos llegado al final de la lista de n�meros
    if (pos == numeros.size()) {
        // Verificar si la suma actual es igual a M
        return calcPorAhora == M;
    }


    //PODA POR SUMA/RESTA M�XIMA POSIBLE DESDE DONDE ESTAMOS
    int sumaRestante = 0;
    for (int i = pos; i < numeros.size(); i++)
        sumaRestante += numeros[i];

    //Si el n�mero final no est� en el intervalo de todo restado/todo sumado, no se va a poder llegar nunca
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

        if (n == 0) { // Caso especial cuando no hay n�meros
            if (M == 0) {
                cout << "SI" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            continue;
        }

        // Llamar a la funci�n que procesa el caso
        //El primer n�mero siempre se suma
        int calcPorAhora = numeros[0];
        //Se empieza por el siguiente numero
        int pos = 1;
        //La tupla solucion es el signo para cada n�mero. el del primero siempre ser� positivo.
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