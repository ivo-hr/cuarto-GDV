#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Variables globales
int n, a, t; // tareas, alumnos, max tareas por alumno
vector<vector<int>> preferencias; // preferencias[alumno][tarea]
vector<vector<int>> asignacion; // asignacion[tarea][posicion] = alumno TUPLA SOLUCION
vector<int> tareasAlumno; // contador de tareas por alumno
int mejorSuma;
vector<vector<int>> mejorAsignacion;

// Función para calcular la suma actual de preferencias
int calcularSuma() {
    int suma = 0;
    for (int tarea = 0; tarea < n; tarea++) {
        for (int pos = 0; pos < 2; pos++) {
            int alumno = asignacion[tarea][pos];
            if (alumno != -1) {
                suma += preferencias[alumno][tarea];
            }
        }
    }
    return suma;
}

void backtrack(int tarea, int posicion) {
    // Caso base: hemos asignado todas las tareas
    if (tarea == n) {
        int sumaActual = calcularSuma();
        if (sumaActual > mejorSuma) {
            mejorSuma = sumaActual;
            mejorAsignacion = asignacion;
        }
        return;
    }

    // Calcular siguiente posición
    int siguienteTarea = tarea;
    int siguientePosicion = posicion + 1;
    //Si ya hemos llegado al estado de asginar un 3er alumno a una tarea (solo se pueden 2), se pasa a la siguiente tarea
    if (siguientePosicion == 2) {
        siguienteTarea++;
        siguientePosicion = 0;
    }

    // Probar cada alumno para la posición actual
    for (int alumno = 0; alumno < a; alumno++) {
        // Verificar restricciones
        bool valido = true;

        // El alumno no debe exceder el máximo de tareas ni ya estar asignado a esa tarea
        // solo comprobamos si está en segunda asignacion (se rellena la primera primero)
        if (tareasAlumno[alumno] >= t || 
            (posicion == 1 && asignacion[tarea][0] == alumno)) {
            valido = false;
        }

        if (valido) {
            // Hacer la asignación
            asignacion[tarea][posicion] = alumno;
            tareasAlumno[alumno]++;

            // Llamada recursiva. eventualmente llegará la suma final y determinará si es la mejor.
            backtrack(siguienteTarea, siguientePosicion);

            // Deshacer la asignación (backtrack) para probar con otro alumno
            asignacion[tarea][posicion] = -1;
            tareasAlumno[alumno]--;
        }
    }
}

int main() {
    while (true) {
        cin >> n >> a >> t;

        // Condición de parada: 3 ceros
        if (n == 0 && a == 0 && t == 0) break;

        // Inicializar estructuras
        preferencias.assign(a, vector<int>(n));
        
        asignacion.assign(n, vector<int>(2, -1));
        tareasAlumno.assign(a, 0);
        mejorSuma = -1;
        mejorAsignacion.assign(n, vector<int>(2, -1));

        // Leer preferencias
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < n; j++) {
                cin >> preferencias[i][j];
            }
        }

        // Ejecutar backtracking
        backtrack(0, 0);

        // Mostrar resultado
        cout << mejorSuma << endl;
    }

    return 0;
}

/*
TUPLA SOLUCIÓN:
- asignacion[tarea][posicion]: Matriz que representa qué alumnos están asignados
  a cada posición de cada tarea (segun el enunciado, max. 2 por tarea)
  El caso es rellenar esta tabla con el alumno que se dedique a cada tarea de modo que 
  hay una fila por tarea con dos huecos libres, que se rellenarán con el numero de alumno.
  EJEMPLO:
            posición 0    posición 1
  fregar     alumno0       alumno2
  limpiar    alumno1       alumno0
  recoger    alumno1       alumno2


  a partir de esto ya se podría sacar con la matriz de preferencias[alumno][tarea] el valor
  del trabajo por alumno y hacer la suma.


MARCADORES:
- tareasAlumno[alumno]: Contador que lleva el número de tareas asignadas a cada alumno
- Usado para verificar que no se exceda el límite t
- Se incrementa al hacer asignación y se decrementa al deshacerla

FUNCIONAMIENTO DEL BACKTRACKING:
1. Recorremos secuencialmente cada posición (tarea, posicion)
2. Para cada posición, probamos todos los alumnos posibles
3. Verificamos restricciones antes de asignar
4. Hacemos la asignación y marcamos el estado
5. Llamada recursiva para la siguiente posición
6. Deshacemos la asignación (backtrack)
7. Al completar todas las asignaciones, evaluamos si es mejor solución

PODA POR ESTIMACIÓN:
Calcularíamos una cota superior optimista sumando para cada tarea restante
las dos mejores preferencias disponibles (considerando las restricciones).
Si suma_actual + cota_superior <= mejor_suma_conocida, podamos la rama.

Ejemplo de poda:
- Si llevamos suma=20, mejor_conocida=50
- Quedan 2 tareas, mejores preferencias disponibles: (10,9) y (8,7)
- Cota superior: 20 + 10 + 9 + 8 + 7 = 54
- Como 54 > 50, continuamos explorando
- Si la cota fuera ≤ 50, podaríamos esta rama
*/