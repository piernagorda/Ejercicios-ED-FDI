#include <iostream>
#include <fstream>
#include "linked_list_ed.h"
#include "linked_list_ed_plus.h"

bool resuelveCaso() {
	int tam;
	std::cin >> tam;
	if (tam == -1) return false;
	linked_list_ed_plus<char> lista;
	for (int i = 0; i < tam; ++i) {
		char temp; std::cin >> temp;
		lista.push_back(temp);
	}
	lista.eliminarRepetidos();
	lista.mostrarLista();
	std::cout << "\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while(resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}