#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Horas.h"

bool resuelveCaso() {
	int numHoras;
	std::cin >> numHoras;
	if (numHoras == 0) return false;
	std::list<Horas> lista;
	for (int i = 0; i < numHoras; ++i) {
		std::string str; std::cin >> str;
		std::string h = str.substr(0, 2); std::string m = str.substr(3, 2); std::string s = str.substr(6, 2);
		Horas hora1(h, m, s);
		lista.push_back(hora1);
	}
	int contador = 1;
	auto it = lista.begin();
	while (it != lista.end()){
		if (contador % 2 == 0) it = lista.erase(it);
		else ++it;
		++contador;
	}
	for (auto it2 = lista.begin(); it2 != lista.end(); ++it2) {
		Horas temp = *it2;
		temp.mostrarHora();
		std::cout << " ";
	}
	std::cout << "\n";
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