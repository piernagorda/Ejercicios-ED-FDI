#include <iostream>
#include <fstream>
#include <string>
#include "Horas.h"

void resuelveCaso() {
	std::string horaA, horaB;
	std::cin >> horaA >> horaB;
	Horas hora1(horaA);
	Horas hora2(horaB);
	if (hora1 == hora2) std::cout << "IGUALES" << std::endl;
	else {
		if (hora1 < hora2) std::cout << horaA << " " << horaB << std::endl;
		else std::cout << horaB << " " << horaA << std::endl;
	}
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