#include <iostream>
#include <fstream>
#include "set_eda.h"

/*
La raiz del arbol sera aquel elemento que entre primero. El begin() apunta al menor
*/

bool resuelveCaso() {
	int numDatos, numPreguntas;
	std::cin >> numDatos;
	if (numDatos == 0) return false;
	set<int> conjunto;
	for (int i = 0; i < numDatos; ++i) {
		int n; std::cin >> n;
		conjunto.insert(n);
	}
	std::cin >> numPreguntas;
	
	for (int i = 0; i < numPreguntas; ++i) {
		int n; std::cin >> n;
		std::pair<bool, int> sol = conjunto.lower(n);
		if (sol.first) std::cout << sol.second << std::endl;
		else std::cout << "NO HAY\n";
	}
	std::cout << "---\n";
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