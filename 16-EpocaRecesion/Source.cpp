#include <iostream>
#include <fstream>
#include "stack_eda.h"

struct tSol {
	int ini=0;
	int duracion=0;
};

tSol resolver(stack<int>& pila) {
	int ini = pila.size()-1, duracion = 1, duracionMaxima = 1, maximoAnterior=pila.top();
	int numAnterior = pila.top();
	pila.pop();
	while (!pila.empty()) {
		//Si el numero en la cima de la pila es mayor que el anterior sacado
		if (pila.top() > numAnterior) { 
			++duracion; //Aumentamos la duracion
			if (duracion > duracionMaxima) { //Si la duracion actual es mayor que la maxima
				if (pila.top() > maximoAnterior) { //Si el numero en la cima supera al maximo anterior -> Recesion finalizada
					ini = pila.size() - 1;
					maximoAnterior = pila.top();
				}
				duracionMaxima = duracion; //Se actualiza la duracion maxima
			}
		}
		//Sino, ponemos otra vez el contador a 1
		else duracion = 1;
		//Sacamos de pila y establecemos el numero anterior
		numAnterior = pila.top();
		pila.pop();
	}
	return { ini, duracionMaxima };
}

bool resuelveCaso() {
	int tamPila;
	std::cin >> tamPila;
	if (!std::cin) return false;
	stack<int> cola;
	for (int i = 0; i < tamPila; ++i) {
		int n;
		std::cin >> n;
		cola.push(n);
	}
	tSol sol = resolver(cola);
	std::cout << sol.duracion << " " << sol.ini << std::endl;

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