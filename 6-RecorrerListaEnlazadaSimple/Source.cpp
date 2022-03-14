#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linked_list_ed_plus.h"

bool resuelveCaso() {
	char c;
	std::cin >> c;
	if (!std::cin) return false;
	linked_list_ed_plus<std::string> lista;
	std::string str;
	getline(std::cin, str); // para saltar el final de linea
	getline(std::cin, str); // lee la linea del caso
	std::stringstream ss(str); // construye el objeto ss de tipo stringstream
	while (ss) {
		std::string aux;
		ss >> aux;
		lista.push_back(aux);
	}
	lista.mostrarPropiedad(c);
	std::cout << "\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}
