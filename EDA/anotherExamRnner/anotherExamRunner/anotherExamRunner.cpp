#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

using namespace std;




class Urgencias {


private:

    unordered_map<int, deque<string>> gravedad_pacientes;
    
    unordered_map<string, int> paciente_gravedad;
    set<string> sanos;

public:
    // Constructor
    Urgencias() {}

    // Operaciones del TAD
    void nuevo_paciente(const string& paciente, int gravedad) {
        
        if (1 > gravedad || 3 < gravedad)
            throw domain_error("Gravedad incorrecta");
        if (paciente_gravedad.find(paciente) != paciente_gravedad.end())
            throw domain_error("Paciente repetido"); // Ejemplo de excepción
        
        gravedad_pacientes[gravedad].push_back(paciente);
        paciente_gravedad[paciente] = gravedad;
        
    }

    int gravedad_actual(const string& paciente) const {
        auto it = paciente_gravedad.find(paciente);
        if (it == paciente_gravedad.end())
            throw domain_error("Paciente inexistente"); // Ejemplo de excepción
        else
            return it->second;
    }

    string siguiente() {
        // TODO: Implementar lógica
        string toRet;
        for (int i = 3; i >= 1; i--) {
            if (!gravedad_pacientes[i].empty()) {
                toRet = gravedad_pacientes[i].front();
                gravedad_pacientes[i].pop_front();
                paciente_gravedad.erase(toRet);
                return toRet;
            }
        }
        throw domain_error("No hay pacientes"); // Ejemplo de excepción
    }

    void mejora(const string& paciente) {
        auto it = paciente_gravedad.find(paciente);
        if (it == paciente_gravedad.end())
            throw domain_error("Paciente inexistente"); // Ejemplo de excepción

        int gravedad = it->second;

        auto pos = find(gravedad_pacientes[gravedad].begin(), gravedad_pacientes[gravedad].end(), paciente);
        if (pos != gravedad_pacientes[gravedad].end())
            gravedad_pacientes[gravedad].erase(pos);
        

        if (gravedad == 1) {
 
            paciente_gravedad.erase(paciente);
            sanos.insert(paciente);
        }
        else {
            gravedad_pacientes[gravedad - 1].push_front(paciente);
            paciente_gravedad[paciente]--;

        }
    }

    set<string> recuperados() const {
        
        return sanos;
    }
};

// Función para procesar la entrada y generar la salida
void procesar_entrada() {
    Urgencias urgencias;
    string comando;

    while (cin >> comando) {
        try {
            if (comando == "FIN") {
                break;
            }
            else if (comando == "nuevo_paciente") {
                string paciente;
                int gravedad;
                cin >> paciente >> gravedad;
                urgencias.nuevo_paciente(paciente, gravedad);
            }
            else if (comando == "gravedad_actual") {
                string paciente;
                cin >> paciente;
                int gravedad = urgencias.gravedad_actual(paciente);
                cout << "La gravedad de " << paciente << " es " << gravedad << endl;
            }
            else if (comando == "siguiente") {
                string paciente = urgencias.siguiente();
                cout << "Siguiente paciente: " << paciente << endl;
            }
            else if (comando == "mejora") {
                string paciente;
                cin >> paciente;
                urgencias.mejora(paciente);
            }
            else if (comando == "recuperados") {
                set<string> recuperados = urgencias.recuperados();
                cout << "Lista de recuperados:";
                for (const string& paciente : recuperados) {
                    cout << " " << paciente;
                }
                cout << endl;
            }
        }
        catch (const domain_error& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }
    cout << "---" << endl;
}

int main() {
    // Procesar múltiples casos de prueba
    while (cin.peek() != EOF) {
        procesar_entrada();
    }
    return 0;
}