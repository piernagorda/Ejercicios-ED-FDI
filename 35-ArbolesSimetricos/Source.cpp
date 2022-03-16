#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <string>

bool esSimetrico(bintree<char> const& arbolLeft, bintree<char> const& arbolRight) {
	if (arbolLeft.empty() && arbolRight.empty()) return true;
	else if (!arbolLeft.empty() && !arbolRight.empty()) return esSimetrico(arbolLeft.left(), arbolRight.right()) && esSimetrico(arbolLeft.right(), arbolRight.left());
	else return false;
}

bool resuelveCaso() {
	bintree<char> miArbol = leerArbol('.');
	if (miArbol.empty()) std::cout << "SI \n";
	else {
		if (esSimetrico(miArbol.left(), miArbol.right())) std::cout << "SI \n";
		else std::cout << "NO \n";
	}
	return true;
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