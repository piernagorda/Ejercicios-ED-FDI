#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>

bool esVocal(char c) {
	return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

void revertirSegundaTransformacion(std::queue<char>& cola) {
	std::stack<char> ultimos;
	int tam = cola.size();
	for (int i = 0; i < tam && !cola.empty(); ++i) {
		char temp = cola.front();
		cola.pop();
		if (i % 2 == 0) cola.push(temp);
		else ultimos.push(temp);
	}
	while (!ultimos.empty()) {
		cola.push(ultimos.top());
		ultimos.pop();
	}
}

std::queue<char> revertirPrimeraTransformacion(std::queue<char>& cola) {
	std::stack<char> pila;
	std::queue<char> retorno;
	while (!cola.empty()){
		char temp = cola.front();
		cola.pop();
		if (esVocal(temp)) retorno.push(temp);
		else {
			pila.push(temp);
			while (!cola.empty() && !esVocal(cola.front())) {
				pila.push(cola.front());
				cola.pop();
			}
			while (!pila.empty()) {
				retorno.push(pila.top());
				pila.pop();
			}
		}
	}
	return retorno;
}

void mostrarLista(std::queue<char> &cola) {
	while (!cola.empty()) {
		std::cout << cola.front();
		cola.pop();
	}
	std::cout << "\n";
}

bool resuelveCaso() {
	std::string str;
	std::getline(std::cin, str);
	if (!std::cin) return false;
	std::queue<char> miCola;
	for (int i = 0; i < str.size(); ++i) miCola.push(str.at(i));
	revertirSegundaTransformacion(miCola);
	std::queue<char> sol = revertirPrimeraTransformacion(miCola);
	mostrarLista(sol);
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