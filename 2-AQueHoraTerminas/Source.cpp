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
	try {
		Horas res = hora1 + hora2;
		res.mostrarHora();
		std::cout << "\n";
	}
	catch (std::overflow_error e) {
		std::cout << "hoy no \n";
	}
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n; std::cin >> n; for (int i = 0; i < n; ++i) resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}
