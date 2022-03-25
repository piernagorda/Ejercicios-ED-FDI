#include <iostream>
#include <fstream>
#include <set>
#include <string>

bool resuelveCaso() {
	char tipo; //N numero P palabra
	int  k; //elementos distintos entre si
	std::cin >> tipo >> k;
	if (!std::cin)return false;
	if (tipo == 'N') {
		int n;
		std::set<int> conjunto;
		std::cin >> n;
		while (n != -1) {
			if (conjunto.empty() || conjunto.size()<k) conjunto.insert(n);
			else {
				if (conjunto.count(n) < 1 && n > *conjunto.begin()) {
					conjunto.insert(n);
					conjunto.erase(conjunto.begin());
				}
			}
			std::cin >> n;
		}
		for (auto it = conjunto.begin(); it != conjunto.cend(); ++it) std::cout << *it << " ";
		std::cout << "\n";
	}
	else {
		std::string n;
		std::set<std::string> conjunto;
		std::cin >> n;
		while (n != "FIN") {
			if (conjunto.empty() || conjunto.size() < k) conjunto.insert(n);
			else {
				if (conjunto.count(n) < 1 && n > *conjunto.begin()) {
					conjunto.insert(n);
					conjunto.erase(conjunto.begin());
				}
			}
			std::cin >> n;
		}
		for (auto it = conjunto.begin(); it != conjunto.cend(); ++it) std::cout << *it << " ";
		std::cout << "\n";
	}
	

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