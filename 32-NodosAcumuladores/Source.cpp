#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tDatos {
	int sumaAcumulada = 0, numAcumuladores = 0;
};

tDatos nodosAcumuladores(bintree<int> const& arbol) {
	if (arbol.left().empty() && arbol.right().empty()) {
		if (arbol.root() == 0) return { arbol.root(), 1 };
		else return { arbol.root(), 0 };
	}
	else {
		tDatos izq, dcha;
		if (!arbol.left().empty()) izq = nodosAcumuladores(arbol.left());
		if (!arbol.right().empty()) dcha = nodosAcumuladores(arbol.right());
		if (arbol.root() == (izq.sumaAcumulada + dcha.sumaAcumulada)) return { izq.sumaAcumulada + dcha.sumaAcumulada + arbol.root(), izq.numAcumuladores + dcha.numAcumuladores + 1 };
		else return { izq.sumaAcumulada + dcha.sumaAcumulada + arbol.root(), izq.numAcumuladores + dcha.numAcumuladores };
	}
}

bool resuelveCaso() {
	bintree<int> miArbol = leerArbol(-1);
	if (!miArbol.empty()) {
		tDatos sol = nodosAcumuladores(miArbol);
		std::cout << sol.numAcumuladores << std::endl;
	}
	else std::cout << "0" << std::endl;
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