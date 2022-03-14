#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"
//using namespace std;

template <typename T>
T encontrarMinimo(bintree<T> const& miArbol) {
	if (miArbol.left().empty() && miArbol.right().empty()) return miArbol.root();
	else {
		T min = miArbol.root();
		if (!miArbol.left().empty()) min = std::min(min, encontrarMinimo(miArbol.left()));
		if (!miArbol.right().empty()) min = std::min(min, encontrarMinimo(miArbol.right()));
		return min;
	}
}


bool resuelveCaso() {
	char tipo;
	std::cin >> tipo;
	if (!std::cin) return false;
	if (tipo == 'N') {
		bintree<int> miArbol = leerArbol(-1);
		std::cout << encontrarMinimo(miArbol) << std::endl;
	}
	else {
		std::string delim = "#";
		bintree<std::string> miArbol = leerArbol(delim);
		std::cout << encontrarMinimo(miArbol) << std::endl;
	}
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