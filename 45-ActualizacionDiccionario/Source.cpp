#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>


void resuelveCaso() {
	std::map<std::string, int> diccionarioAntiguo;
	std::map<std::string, int> diccionarioNuevo;
	std::vector<std::vector<std::string>> vectorSolucion(3); //Creamos un vector de vectores, donde pos 0 = +, pos 1 = - y pos 2 = *
	std::string str, str2, key, value, key2, value2;
	
	std::getline(std::cin, str);
	std::stringstream s(str);
	while (s >> key >> value) {
		std::pair<std::string, int> par(key, stoi(value));
		diccionarioAntiguo.insert(par);
	}
	std::getline(std::cin, str2);
	std::stringstream s2(str2);
	while (s2 >> key2 >> value2) {
		std::pair<std::string, int> par(key2, stoi(value2));
		diccionarioNuevo.insert(par);
	}
	//Se ha anadido clave: se guarda un + seguido de la clave
	//Se ha borrado clave: se guarda - seguido de la clave borrada
	//Si hay claves cuyo valor ha cambiado -> se pone * y el cambio
	
	auto itAntiguo = diccionarioAntiguo.begin();
	auto itNuevo = diccionarioNuevo.begin();
	
	while (itAntiguo != diccionarioAntiguo.end() && itNuevo != diccionarioNuevo.end()) {
		if ((*itAntiguo).first == (*itNuevo).first) { //Las claves son iguales
			if ((*itAntiguo).second != (*itNuevo).second) { //Si los valores son iguales, avanzamos ambos iteradores
				vectorSolucion[2].push_back((*itNuevo).first); //Metemos el cambio
			}
			++itAntiguo;
			++itNuevo;
		}
		else if ((*itAntiguo).first<(*itNuevo).first){ //Hay un valor menor en el diccionario antiguo -> ha sido eliminado
			vectorSolucion[1].push_back((*itAntiguo).first);
			++itAntiguo;
		}
		else { //Se ha anadido
			vectorSolucion[0].push_back((*itNuevo).first);
			++itNuevo;
		}
	}

	while (itAntiguo != diccionarioAntiguo.end()) { //Si quedan en el diccionario antiguo, se han borrado
		vectorSolucion[1].push_back((*itAntiguo).first);
		++itAntiguo;
	}
	while (itNuevo != diccionarioNuevo.end()) { //Si quedan en el diccionario nuevo, se han anadido
		vectorSolucion[0].push_back((*itNuevo).first);
		++itNuevo;
	}

	//Mostrar por pantalla
	if (vectorSolucion[0].size() == 0 && vectorSolucion[1].size() == 0 && vectorSolucion[2].size() == 0) std::cout << "Sin cambios \n";
	else {
		if (vectorSolucion[0].size() != 0) {
			std::cout << "+ ";
			for (int i = 0; i < vectorSolucion[0].size(); ++i) std::cout << vectorSolucion[0][i] << " ";
			std::cout << "\n";
		}
		if (vectorSolucion[1].size() != 0) {
			std::cout << "- ";
			for (int i = 0; i < vectorSolucion[1].size(); ++i) std::cout << vectorSolucion[1][i] << " ";
			std::cout << "\n";
		}
		if (vectorSolucion[2].size() != 0) {
			std::cout << "* ";
			for (int i = 0; i < vectorSolucion[2].size(); ++i) std::cout << vectorSolucion[2][i] << " ";
			std::cout << "\n";
		}
	}
	std::cout << "---\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n; std::cin >> n; 
	std::cin.ignore(); for (int i = 0; i < n; ++i) resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE

}