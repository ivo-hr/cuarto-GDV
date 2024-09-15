// David Brey Plaza
// VJ08

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int ROJAS,AZULES,VERDES;

bool esValida(const int& k, const vector<char>& v, const int& green, const int& blue) {

	if (green > blue || (v[k] == v[k - 1] && v[k] == 'v')) return false;
	else return true;

}

void escribirTorre(const vector<char>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 'r') { cout << "rojo "; }
		else if (v[i] == 'a') { cout << "azul "; }
		else if (v[i] == 'v') { cout << "verde "; }
	}
	cout << "\n";
}

void calcularCombinaciones(vector<char>& v, const int& alt, const int& k, int red, int green, int blue, bool& sol) {

	for (int i = 0; i < 3; i++)
	{
		bool nuevaPieza = true;
		// Metemos una nueva pieza
		if (i == 0 && blue < AZULES) { v[k] = 'a'; blue++; }
		else if (i == 1 && red < ROJAS) { v[k] = 'r'; red++; }
		else if (i == 2 && green < VERDES) { v[k] = 'v'; green++; }
		else
		{
			nuevaPieza = false;
		}

		if (nuevaPieza && esValida(k, v, green, blue))
		{
			if (k + 1>= alt)
			{
				if (blue + green < red)
				{
					escribirTorre(v);
					sol = true; // Nos aseguramos de informar que hay al menos una solucion
				}
			}
			else
			{
				calcularCombinaciones(v, alt, k + 1, red, green, blue, sol);
			}
		}

		// En caso de fallar, quitamos la pieza y volvemos a probar con otro color
		if (nuevaPieza)
		{
			if (i == 0) blue--;
			else if (i == 1) red--;
			else if (i == 2) green--;
		}
	}
}


bool resuelveCaso() {
	int altura;
	cin >> altura >> AZULES >> ROJAS >> VERDES;

	if (altura == 0 && AZULES == 0 && ROJAS == 0 && VERDES == 0) return false;

	bool sol = false;

	vector<char> v(altura);
	// Colocamos la primera pieza y nos aseguramos que es roja
	v[0] = 'r';

	// Apuntamos que ya hemos gastado un rojo y pasamos el limite de piezas de cada color
	calcularCombinaciones(v, altura, 1, 1, 0, 0, sol);
	if (!sol) std::cout << "SIN SOLUCION\n";

	cout << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}

