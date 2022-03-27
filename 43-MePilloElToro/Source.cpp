#include <iostream>
#include <fstream>
#include <map>
#include <string>

void resuelveCaso() {
	int numCasos; 
	std::string temp;
	std::cin >> numCasos;
	while (numCasos != 0) {
		std::map<std::string, int> diccionario;
		for (int i = 0; i < numCasos; ++i) {
			std::string alumno, valor;
			std::cin.ignore();
			std::getline(std::cin, alumno);
			std::cin >> valor;
			if (diccionario.find(alumno) == diccionario.end()) {
				if (valor == "CORRECTO") diccionario.insert(std::pair<std::string, int>(alumno, 1));
				else diccionario.insert(std::pair<std::string, int>(alumno, -1));
			}
			else {
				if (valor == "CORRECTO") diccionario.at(alumno)++;
				else diccionario.at(alumno)--;
			}
		}
		for (auto it = diccionario.begin(); it != diccionario.end(); ++it) {
			if ((*it).second != 0) std::cout << (*it).first << ", " << (*it).second << std::endl;
		}
		std::cout << "---" << std::endl;
		std::cin >> numCasos;
	}
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGEs
}