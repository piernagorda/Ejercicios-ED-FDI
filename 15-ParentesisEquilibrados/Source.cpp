#include <iostream>
#include <fstream>
#include <string>
#include "stack_eda.h"

bool resolver(std::string const& str) {
	bool retorno = true;
	stack<char> pila;
	for (int i = 0; i < str.size(); ++i) {
		if (str.at(i) == '(' || str.at(i) == '[' || str.at(i) == '{') pila.push(str.at(i));
		else if (str.at(i) == ')' || str.at(i) == ']' || str.at(i) == '}') {
			if (pila.empty()) retorno = false;
			else {
				if (str.at(i) == ')' && pila.top() != '(') retorno = false;
				else if (str.at(i) == ']' && pila.top() != '[') retorno = false;
				else if (str.at(i) == '}' && pila.top() != '{') retorno = false;
				else pila.pop();
			}
		}
	}
	return retorno && pila.empty();
}

bool resuelveCaso() {
	std::string str;
	std::getline(std::cin, str);
	if (!std::cin) return false;
	if (!resolver(str)) std::cout << "NO" << std::endl;
	else std::cout << "SI" << std::endl;
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