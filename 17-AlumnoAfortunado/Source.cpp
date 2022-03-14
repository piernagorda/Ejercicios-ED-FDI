#include <iostream>
#include <fstream>
#include <deque>

bool resuelveCaso() {
	int alumnos, enCuanto;
	std::cin >> alumnos >> enCuanto;
	if (alumnos == 0 && enCuanto == 0) return false;
	std::deque<int> cola;
	for (int i = 1; i <= alumnos; ++i) 	cola.push_back(i);
	
	int contador = 0;
	while (cola.size() > 1) {
		if (contador < enCuanto) {
			cola.push_back(cola.front());
			cola.pop_front();
			++contador;
		}
		else {
			contador = 0;
			cola.pop_front();
		}
	}
	std::cout << cola.front() << std::endl;
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