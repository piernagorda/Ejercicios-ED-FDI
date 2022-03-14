#include <iostream>
#include <fstream>
#include "linked_list_ed_plus.h"

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;
	linked_list_ed_plus<int> lista;
	for (int i = 0; i < n; ++i) {
		int a; std::cin >> a;
		lista.push_back(a);
	}
	lista.intercambiarDosADos();
	lista.mostrarLista();
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while( resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}