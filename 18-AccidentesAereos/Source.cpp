#include <iostream>
#include <fstream>
#include <stack>
#include <string>

struct tDatos {
	std::string fecha;
	int muertes;
};

bool resuelveCaso() {
	int n;
	std::cin>>n;
	if (!std::cin) return false;
	std::stack<tDatos> colaAccidentes;
	for (int i = 0; i < n; ++i) {
		std::string temp;
		int tempMuertes;
		std::cin >> temp >> tempMuertes;
		while (!colaAccidentes.empty() && tempMuertes >= colaAccidentes.top().muertes) colaAccidentes.pop();
		if (colaAccidentes.empty()) std::cout << "NO HAY \n";
		else std::cout << colaAccidentes.top().fecha << std::endl;
		colaAccidentes.push({ temp, tempMuertes });
	}
	std::cout << "---\n";
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