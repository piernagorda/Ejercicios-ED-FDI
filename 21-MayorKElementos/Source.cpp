#include <iostream>
#include <fstream>
#include "queue_eda.h"
#include "double_linked_list_ed.h"


double_linked_list_ed<int> crearListaInicial(queue<int> cola, int const& tamSegmento, int &maximo) {
	double_linked_list_ed<int> lista;
	int maximo = cola.front();
	lista.push_front(maximo); //Metemos el primer elemento en la lista
	cola.pop(); //Lo sacamos de la cola
	for (int i = 0; i < tamSegmento - 1 && !cola.empty(); ++i) {
		//Recibimos un elemento menor que la parte trasera de la lista -> Se guarda en la lista
		if (cola.front() <= lista.back()) lista.push_back(cola.front());
		//Si recibimos un elemento mayor nos dan igual todos los anteriores que sean menores
		else {
			bool salir = false;
			while (!lista.empty() && !salir) {
				if (lista.back() < cola.front()) lista.pop_back(); //El elemento de la parte trasera de la lista es menor
				else {
					salir = true;
				}
			}
			lista.push_back(cola.front());
			if (lista.back() > maximo) maximo = lista.back();
		}
		cola.pop(); //Sacamos el elemento de la cola
	}
	return lista;
}

void resolver(queue<int> &cola, double_linked_list_ed<int> &listaInicial, int const& tamCola, int const& tamSegmento, int maximoInicial) {
	std::cout << maximoInicial << " ";
	int maximoEnCola = maximoInicial;
	for (int i = 0; i < tamCola; ++i) {
		int temp = cola.front();
		
	}

	
}

bool resuelveCaso() {
	int tamCola, tamSegmento;
	std::cin >> tamCola >> tamSegmento;
	if (!std::cin) return false;
	queue<int> cola;
	for (int i = 0; i < tamCola; ++i) {
		int n; std::cin >> n;
		cola.push(n);
	}
	int maximo = 0;
	double_linked_list_ed<int> lista = crearListaInicial(cola, tamSegmento, maximo);
	resolver(cola, lista, tamCola, tamSegmento, maximo);
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