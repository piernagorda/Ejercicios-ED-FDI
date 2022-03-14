#include <iostream>
#include <fstream>
#include "linked_list_ed_plus.h"

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;
	linked_list_ed_plus<int> lista;
	while (n != 0) {
		lista.push_back(n);
		std::cin >> n;
	}
	lista.duplicarNodos();
	lista.mostrarLista();
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