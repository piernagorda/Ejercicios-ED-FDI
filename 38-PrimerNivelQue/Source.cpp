#include <iostream>
#include <fstream>
#include "bintree_ext.h"



void resuelveCaso() {
	char tipo='.', buscado;
	int buscadoNum;
	std::cin >> tipo;
	if (tipo == 'N') {
		std::cin >> buscadoNum;
		bintree_ext<int> miArbol = leerArbol_ext(-1);
		int sol = miArbol.levelRet(buscadoNum);
		if ( sol!= -1) std::cout << sol << std::endl;
		else std::cout << "NO EXISTE \n";
	}
	else {
		std::cin >> buscado;
		bintree_ext<char> miArbol = leerArbol_ext('.');
		int sol = miArbol.levelRet(buscado);
		if ( sol != -1) std::cout << sol << std::endl;
		else std::cout << "NO EXISTE \n";
	}
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