#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <string>

void hallarDatos(bintree<char> const& arbol, int& numNodos, int& numHojas, int& altura, int alturaActual) {
	if (arbol.left().empty() && arbol.right().empty()) {
		++numHojas;
		++numNodos;
		if (alturaActual > altura) altura = alturaActual;
	}
	else {
		++numNodos;
		if (alturaActual > altura) altura = alturaActual;
		if (!arbol.left().empty()) hallarDatos(arbol.left(), numNodos, numHojas, altura, alturaActual+1);
		if (!arbol.right().empty()) hallarDatos(arbol.right(), numNodos, numHojas, altura, alturaActual+1);
	}
}

int sumaNodos(bintree <char> const& arbol) { // O(N)
	if (arbol.empty()) {
		return 0;
	}
	else {
		int res_iz = sumaNodos(arbol.left());
		int res_dr = sumaNodos(arbol.right());
		return { res_iz + res_dr + 1 };
	}
}


bool resuelveCaso() {
	/*
	calcular su n´umero de nodos, cu´antos de ellos son hojas, y cu´al es
	la altura del ´arbol
	*/
	bintree<char> arbol = leerArbol('.');
	int numNodos = 0, numHojas = 0, altura = 0, alturaActual = 1;
	if (!arbol.empty()) {
		hallarDatos(arbol, numNodos, numHojas, altura, alturaActual);
		std::cout << numNodos << " " << numHojas << " " << altura << std::endl;
	}
	else std::cout << "0 0 0" << std::endl;
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