#include <iostream>
#include <fstream>
#include "double_linked_list_ed_plus.h"

void resuelveCaso() {
	int n;
	std::cin >> n;
	double_linked_list_ed_plus<int> lista1;
	double_linked_list_ed_plus<int> lista2;
	while (n != 0) {
		lista1.push_back(n);
		std::cin >> n;
	}
	std::cin >> n;
	while (n != 0) {
		lista2.push_back(n);
		std::cin >> n;
	}
	lista1.interseccion(lista2);
	lista1.mostrarLista();
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