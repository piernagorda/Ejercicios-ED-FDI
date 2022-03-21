#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tDatos {
	int minimo, maximo;
	bool esABB;
};

tDatos esABB(bintree<int> const& miArbol) {
	if (miArbol.empty()) return { -1, -1, true };
	else if (miArbol.left().empty() && miArbol.right().empty()) return { miArbol.root(), miArbol.root(), true };
	else {
		tDatos dcha = esABB(miArbol.right());
		tDatos izq = esABB(miArbol.left());
		if (!dcha.esABB || !izq.esABB) return { -1, -1, false };
		else {
			//-En caso de que ninguno de los dos hijos sea vacio:
			//La raiz ha de ser mayor que el maximo del lado izquierdo y menor que el minimo del lado derecho
			//Entonces, sera ABB si: raiz > izq.maximo y raiz < dcha.minimo
			//-En caso de que el hijo izquierdo sea vacio y no el derecho: la raiz es el minimo y el maximo el de la dcha
			//-En caso de que el hijo derecho sea vacio y no el izquierdo: la raiz es el maximo y el minimo, el de la izq
			if (!miArbol.left().empty() && !miArbol.right().empty() && miArbol.root() > izq.maximo && miArbol.root() < dcha.minimo) return { izq.minimo, dcha.maximo, true };
			else if (miArbol.left().empty() && !miArbol.right().empty() && miArbol.root() < dcha.minimo) return { miArbol.root(), dcha.maximo, true };
			else if (miArbol.right().empty() && !miArbol.left().empty() && miArbol.root() > izq.maximo) return { izq.minimo, miArbol.root(), true };
			else return { -1,-1, false };
		}
	}
}

void resuelveCaso() {
	bintree<int> miArbol = leerArbol(-1);
	if (esABB(miArbol).esABB) std::cout << "SI \n";
	else std::cout << "NO \n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n; std::cin >> n; for (int i = 0; i < n; ++i) resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}