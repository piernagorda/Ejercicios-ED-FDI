#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Horas.h"

class peliculas {
public:
	peliculas(std::string nombre, Horas duracion, Horas inicio): _nombre(nombre), _duracion(duracion), _inicio(inicio) {
		_horaSumada = duracion + inicio;
	}
	std::string getNombre() const { return _nombre; }
	Horas getDuracion() const { return _duracion; }
	Horas getInicio() const { return _inicio; }
	Horas getHoraTotal() const { return _horaSumada; }

	bool operator<(peliculas const& a) const {
		return (getHoraTotal() < a.getHoraTotal() || getHoraTotal() == a.getHoraTotal() && _nombre < a.getNombre());
	}

private:
	std::string _nombre;
	Horas _duracion;
	Horas _inicio;
	Horas _horaSumada;

	
};

bool resuelveCaso() {
	int numPelis;
	std::cin >> numPelis;
	if (numPelis == 0) return false;
	std::vector<peliculas> lista;
	std::cin.ignore();
	for (int i = 0; i < numPelis; ++i) {
		std::string str; 
		std::getline(std::cin, str);
		std::string h1 = str.substr(0, 8);
		std::string h = h1.substr(0, 2); std::string m = h1.substr(3, 2); std::string s = h1.substr(6, 2);
		Horas inicio(h, m, s);
		std::string h2 = str.substr(9, 8);
		h = h2.substr(0, 2); m = h2.substr(3, 2); s = h2.substr(6, 2);
		Horas duracion(h, m, s);
		int tamPeli = str.size() - h1.size() - h2.size() - 2;
		std::string titulo = str.substr(18,tamPeli);
		lista.push_back({ titulo, inicio, duracion });
	}

	std::sort(lista.begin(), lista.end());
	
	for (int i = 0; i < lista.size(); ++i) {
		lista.at(i).getHoraTotal().mostrarHora();
		std::cout << " " << lista.at(i).getNombre() << std::endl;
	}
	std::cout << "---" << std::endl;
	
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());;
#endif // !DOMJUDGE
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}