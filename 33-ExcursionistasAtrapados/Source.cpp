#include <iostream>
#include <fstream>
#include "bintree_eda.h"

//Alumno: Javier Piernagorda
//Correo: jpiernag@ucm.es
//Fecha: 21/2/2022

struct tDatos {
	int numRescatistasRama, numMaximoAtrapados;
	bool yaAtendidos;
};

tDatos numExcursionistas(bintree<int> const& miArbol) {
	if (miArbol.empty()) return { 0, 0, false };
	else if (miArbol.left().empty() && miArbol.right().empty()) {
		if (miArbol.root() != 0) return { 1, miArbol.root(), true };
		else return { 0, 0, false };
	}
	else {
		tDatos izq = numExcursionistas(miArbol.left());
		tDatos dcha = numExcursionistas(miArbol.right());
		//Si el nodo no necesita rescate, pasamos para arriba el # de rescatistas necesarios en rama izq, en rama derecha,
		//el maximo que se ha quedado atrapado en una rama y si esa rama ya estara atendida por un rescatista o no
		if (miArbol.root() == 0) return { izq.numRescatistasRama + dcha.numRescatistasRama, std::max(izq.numMaximoAtrapados, dcha.numMaximoAtrapados), (izq.yaAtendidos || dcha.yaAtendidos) };
		//En caso de que no, es el mismo proceso pero sumamos los escaladores atrapados del nodo al maximo entre rama izquierda, derecha y pasamos que esa
		//rama SI esta atendida ya por un escalador (un true, en lugar de izq.yaAtendido || dcha.yaAtendido, ya que si o si va a estar atendida al estar
		//el nodo necesitando un rescatista
		else {
			if (izq.yaAtendidos || dcha.yaAtendidos)
				return { izq.numRescatistasRama + dcha.numRescatistasRama, std::max(izq.numMaximoAtrapados, dcha.numMaximoAtrapados) + miArbol.root(), true };
			else return { 1, miArbol.root(), true };
		}
	}
}

void resuelveCaso() {
	bintree<int> miArbol = leerArbol(-1);
	tDatos sol = numExcursionistas(miArbol);
	std::cout << sol.numRescatistasRama << " " << sol.numMaximoAtrapados << std::endl;
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