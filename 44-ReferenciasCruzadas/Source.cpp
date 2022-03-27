#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void imprimirVector(std::vector<int> const& apariciones) {
	for (auto it = apariciones.begin(); it != apariciones.end(); ++it) std::cout << *it << " ";
	std::cout << "\n";
}

bool resuelveCaso() {
	int lineas;
	std::cin >> lineas;
	std::cin.ignore();
	if (lineas == 0) return false;
	std::map<std::string, std::vector<int>> diccionario;
	for (int i = 0; i < lineas; ++i) {
		std::string temp, word;
		std::getline(std::cin, temp);
		std::istringstream ls(temp);
		while (ls>> word) {
			//La palabra no existe
			if (word.size() > 2) {
				for (auto& c : word)c = tolower(c);
				auto it = diccionario.find(word);
				if (it == diccionario.end()) {
					std::vector<int> temp2 = { i+1 };
					diccionario.insert(std::pair<std::string, std::vector<int>>(word, temp2));
				}
				//Si existe, vemos que la linea donde ha aparecido no sea la actual
				else {
					if ((*it).second[(*it).second.size() - 1] != i+1) (*it).second.push_back(i+1);
				}
			}
		}
	}
	for (auto it = diccionario.begin(); it != diccionario.end(); ++it) {
		std::cout << (*it).first<<" ";
		imprimirVector((*it).second);
	}
	std::cout << "---"<<std::endl;
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