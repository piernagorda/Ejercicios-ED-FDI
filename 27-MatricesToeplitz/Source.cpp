#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
using namespace std;
bool es_toeplitz(const std::list<std::list<int>>& matriz) {
	
	bool retorno = true;
	//Si tiene una sola lista -> valida
	if (matriz.size() == 1) return true;
	else {
		auto itPrimeraLista = matriz.begin(); //Iterador de la matriz, apunta a la primera lista
		auto contenido = (*itPrimeraLista);

		//Si las listas tienen un solo elemento -> valida
		if (contenido.size() == 1) return true;
	
		//En otro caso, comprobamos
		else {
			//Cogemos la segunda lista
			auto itSegundaLista = ++matriz.begin(); //Iterador a la segunda lista de la matriz
			
			for (itSegundaLista; itSegundaLista != matriz.end(); itSegundaLista++) {
				auto itLista1 = (*itPrimeraLista).begin();
				auto itLista2 = ++(*itSegundaLista).begin();
				//Comprobamos uno a uno los elementos
				for (itLista2; itLista2 != (*itSegundaLista).end(); itLista2++) {
					if (*itLista1 != *itLista2) return false;
					else ++itLista1;
				}
				++itPrimeraLista;
			}
			return retorno;
		}
	}
}

bool resuelveCaso() {
	std::list<std::list<int>> matriz;
	int n;
	auto itMatriz = matriz.begin();
	std::cin >> n;
	if (n == 0) return false;
	else {
		while (n != 0) {
			std::list<int> lista;
			while (n != 0) {
				auto itLista = lista.begin();
				lista.push_back(n);
				std::cin >> n;
			}
			matriz.insert(itMatriz, lista);
			std::cin >> n;
		}
	}
	if (es_toeplitz(matriz)) std::cout << "SI \n";
	else std::cout << "NO \n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());;
#endif // !DOMJUDGE
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}