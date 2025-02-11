
//Enrique Juan Gamboa
//51547377F

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

#include <set>
#include <map>

#include <list>
#include <cstdint>

using namespace std;


class Hogwarts {
private:
    struct infoAlumno{
        string casa;
        int puntos;
        int pos;
    };

    set<string> casas;
    map<string, infoAlumno> alumnos;
    int numAlumnos = 0;

    

public:

    //Coste 0(logN), ya que al ser un mapa ordenado puede buscar por inicial
   void registrar_estudiante(const string &nombre, const string &casa) {
        if(alumnos.find(nombre) != alumnos.end()){
            throw domain_error("Estudiante ya registrado");
        }

        if(casas.find(casa) == casas.end()){
            casas.insert(casa);
        }
        //La posición en la que se colocará el alumno al ingresar.
        //No hace falta colocarlo antes de los alumnos de número negativo porque sólo se cuenta mejor de la casa si puntos > 0,
        //y si se modifica la puntuación se colocan en actualizar_puntos
        numAlumnos++;

        infoAlumno info{casa, 0, numAlumnos};

        alumnos.insert({nombre, info});
   }
    //Coste O(n), ya que modificamos la posicion del resto de alumnos
    //En función de la posicion del modificado
   int actualizar_puntos(const string &nombre, int puntos) {
        if(alumnos.find(nombre) == alumnos.end()){
            throw domain_error("Estudiante no existente");
        }

        alumnos.at(nombre).puntos += puntos;

        //Movemos de posición al alumno. No hace falta comprobar si es él mismo, ya que su puntuación es igual
        //No se usa <= para dar prioridad a los que llegaron a esa posición primero.
        for (auto alumno : alumnos){
            if (alumno.second.puntos < alumnos.at(nombre).puntos){
                alumno.second.pos ++;
                alumnos.at(nombre).pos --;
            }
            else if (alumno.second.puntos > alumnos.at(nombre).puntos){
                alumno.second.pos --;
                alumnos.at(nombre).pos ++;
            }
        }

        return alumnos.at(nombre).puntos;
   }

    //Coste O(n), ya que modificamos la posicion del resto de alumnos
    //En función de la posicion del eliminado
   void eliminar_estudiante(const string &nombre) {
        if(alumnos.find(nombre) == alumnos.end()){
            throw domain_error("Estudiante no existente");
        }
        
        int expulPos = alumnos.at(nombre).pos;
        alumnos.erase(nombre);

        //Pasamos por los estudiantes para los que estuvieran debajo suya suban de posición
        for (auto alumno : alumnos){
            if (alumno.second.pos > expulPos)
                alumno.second.pos--;
        }
   }

    //Coste O(n^m), donde n es el número de alumnos y m el número de casas.
    //De esta manera, se añaden directamente en orden alfabético (gracias al set de casas)
    //Además con las posiciones y nombre de las casas se busca el de mayor posición.
   vector<pair<string, string>> mejor_de_cada_casa() const {
        
        vector<pair<string, string>> toReturn;
        
        for (auto casa : casas){
            string nombre = "Sin representante";

            int minPos = INT32_MAX;
            for (auto alumno : alumnos){
                if (alumno.second.casa == casa && alumno.second.pos < minPos && 
                    alumno.second.puntos > 0){
                    nombre = alumno.first;
                    minPos = alumno.second.pos;
                }

            }

            pair<string, string> representante = {casa, nombre};
            toReturn.emplace_back(representante);
        }

        return toReturn;
   }
};

bool resuelve_caso() {
   Hogwarts hogwarts;
   string comando;

   while (cin >> comando && comando != "FIN") {
       try {
           if (comando == "registrar_estudiante") {
               string nombre, casa;
               cin >> nombre >> casa;
               hogwarts.registrar_estudiante(nombre, casa);
               cout << "OK" << endl;
           } else if (comando == "actualizar_puntos") {
               string nombre;
               int puntos;
               cin >> nombre >> puntos;
               int p = hogwarts.actualizar_puntos(nombre, puntos);
               cout << "Puntos de " << nombre << ": " << p << endl;

           } else if (comando == "eliminar_estudiante") {
               string nombre;
               cin >> nombre;
               hogwarts.eliminar_estudiante(nombre);
               cout << "OK" << endl;
           } else if (comando == "mejor_de_cada_casa") {
               auto resultado = hogwarts.mejor_de_cada_casa();
               for (const auto &par : resultado) {
                   cout << par.first << ": " << par.second << endl;
               }

           }
       } catch (const exception &e) {
           cout << "ERROR: " << e.what() << endl;
       }
   }
   if(!cin) return false;
   cout << "---" << endl;
   return true;
}

int main() {
#ifndef DOMJUDGE
   std::ifstream in("datos.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out");
   auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
   while (resuelve_caso()) {}

#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
//    system("PAUSE");
#endif
   return 0;
}


//Enrique Juan Gamboa
//51547377F