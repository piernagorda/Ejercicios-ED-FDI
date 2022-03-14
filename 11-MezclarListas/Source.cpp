#include <iostream>
#include <fstream>
#include <string>
#include "linked_list_ed_plus.h"

void resuelveCaso() {
	int n;
	linked_list_ed_plus<int> lista1;
	linked_list_ed_plus<int> lista2;
	std::cin >> n;
	while (n != 0) {
		lista1.push_back(n);
		std::cin >> n;
	}
	std::cin >> n;
	while (n != 0) {
		lista2.push_back(n);
		std::cin >> n;
	}
	if (!lista1.empty() && !lista2.empty()) {
		lista1.mezclarListas(lista2);
		lista1.mostrarLista();
	}
	else {
		if (lista1.empty()) lista2.mostrarLista();
		else lista1.mostrarLista();
	}
	std::cout << "\n";
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