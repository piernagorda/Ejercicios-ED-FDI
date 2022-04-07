#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;
	std::unordered_map<int, int> mapa;
	std::vector<int> solucion;
	for (int i = 0; i < n; ++i) {
		int a; std::cin >> a;
		if (mapa.count(a)==0) {
			std::pair<int, int> pareja(a, 1);
			mapa.insert(pareja);
			solucion.push_back(a);
		}
		else mapa.at(a)++;
	}
	for (int i = 0; i < solucion.size(); ++i) std::cout << solucion[i] << " " << mapa.at(solucion[i]) << std::endl;
	std::cout << "---\n";
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