#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include "Horas.h"

struct tDatos {
	Horas hora;
	bool encontrado;
};

//La idea inicial era ir recorriendo el vector de horas y en cuanto encontrase una que fuese mayor o igual a la hora que queriamos
//consultar, devolver esa hora, parar el bucle que recorriese el vector y acabar. Sin embargo, al juez esa solucion le debe parecer
//muy ineficiente y la solucion es una busqueda binaria (recursiva o iterativa). He copiado un codigo de internet de una BB iterativa
//y la he modificado rapidamente para devolver lo que yo quiero. Sin embargo, he usado algo que no se ha dado en ED todavia (se da en DA)
//que es la cola de prioridad. Al recorrer el vector en la busqueda binaria, puede haber varios candidatos (todos aquellos que sean mayores a la
//hora deseada) salvo que la posicion del medio sea justo nuestra hora. Entonces, meteremos todas las horas candidatas en una cola de minimos 
//y sacaremos la mas prioritaria, es decir, la mas proxima a nuestra hora (la minima). No se si con una BB recursiva se mejoraria 
// (a priori si, pero no se si el juez daria error por stack overflow o algo asi con vectores muy grandes), 
//por lo que subo esta que si que se que da CORRECT
tDatos binarySearch(std::vector<Horas> &array, Horas &hora, int low, int high) {
	// Repeat until the pointers low and high meet each other
	std::priority_queue<Horas, std::vector<Horas>, std::greater<Horas>> cola;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (array[mid] == hora) return {array[mid], true};
		if (array[mid] < hora) low = mid + 1;
		else {
			cola.push(array[mid]);
			high = mid - 1;
		}
	}
	if (cola.empty()) return { array[0], false };
	else return { cola.top(), true };
}


bool resuelveCaso() {
	int tamVector, consultas;
	std::cin >> tamVector >> consultas;
	if (tamVector == 0 && consultas == 0) return false;
	std::vector<Horas> vector;
	for (int i = 0; i < tamVector; ++i) {
		std::string str; std::cin >> str;
		std::string h = str.substr(0, 2); std::string m = str.substr(3, 2); std::string s = str.substr(6, 2);
		vector.push_back({ h, m, s });
	}
	for (int i = 0; i < consultas; ++i) {
		std::string str; std::cin >> str;
		std::string h = str.substr(0, 2); std::string m = str.substr(3, 2); std::string s = str.substr(6, 2);
		try {
			Horas hora1(h, m, s);
			tDatos sol = binarySearch(vector, hora1, 0, tamVector - 1);
			if (sol.encontrado) {
				sol.hora.mostrarHora();
				std::cout << "\n";
			}
			else std::cout << "NO \n";
		}
		catch (std::overflow_error e) {
			std::cout << "ERROR\n";
		}
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