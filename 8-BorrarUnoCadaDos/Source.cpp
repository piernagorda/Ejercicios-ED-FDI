#include <iostream>
#include <fstream>
#include "linked_list_ed_plus.h"
#include "Horas.h"

bool resuelveCaso() {
	int numFechas;
	std::cin >> numFechas;
	if (numFechas == 0) return false;
	linked_list_ed_plus<Horas> lista;
	
	for (int i = 0; i < numFechas; ++i) {
		std::string str; std::cin >> str;
		std::string h = str.substr(0, 2); std::string m = str.substr(3, 2); std::string s = str.substr(6, 2);
		Horas hora(h, m, s);
		lista.push_back(hora);
	}
	lista.eliminarUnoCadaDos();
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