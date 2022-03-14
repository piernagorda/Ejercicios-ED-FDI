#include <iostream>
#include <fstream>
#include <string>
#include "Horas.h"

void resuelveCaso() {
	std::string str; std::cin >> str;
	std::string h = str.substr(0, 2); std::string m = str.substr(3, 2); std::string s = str.substr(6, 2);
	Horas hora1(h, m, s);
	std::cin >> str;
	std::string h2 = str.substr(0, 2); std::string m2 = str.substr(3, 2); std::string s2 = str.substr(6, 2);
	Horas hora2(h2, m2, s2);
	if (hora1 < hora2) {
		hora1.mostrarHora(); std::cout << " "; hora2.mostrarHora(); std::cout << "\n";
	}
	else if (hora2 < hora1) {
		hora2.mostrarHora(); std::cout << " "; hora1.mostrarHora(); std::cout << "\n";
	}
	else std::cout << "IGUALES" << std::endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int numCasos; std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}