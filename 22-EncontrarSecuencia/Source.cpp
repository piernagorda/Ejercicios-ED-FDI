#include <iostream>
#include <fstream>
#include <list>

//Devuelve la posicion donde esta la secuencia
template < class T >
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {
	auto indiceLista1 = ini1;
	auto indiceInicioSecuencia = ini1;
	auto indiceLista2 = ini2;
	auto retorno = ini1;
	bool salir = false, fijar = false;
	//Tenemos dos indices: uno para recorrer la lista 1 (que siempre se hace ++) y otro para recorrer la lista 2
	//que se hace ++ solo cuando lista1[i] = lista2[j]. En caso contrario, el indice de la lista 2 se vuelve a poner
	//a ini2
	while (indiceLista1!=fin1 && !salir) {
		//Si hemos encontrado un elemento que coincide
		if ((*indiceLista1) == (*indiceLista2)) {
			if (!fijar) { //Esto se hace para fijar un posible inicio de secuencia (el que devolveremos)
				indiceInicioSecuencia = indiceLista1;
				fijar = true;
			}
			++indiceLista2; //Hacemos ++ al indice de la lista 2
			if (indiceLista2 == fin2) {  //Si hemos llegado al fin de la secuencia 2 -> Tenemos secuencia!
				retorno = indiceInicioSecuencia;
				salir = true;
			}
		}
		//Si el elemento encontrado no coincide
		else {
			//Se pone fijar a false para que la proxima vez que encontremos una posible secuencia, podamos volver a marcar su inicio
			fijar = false;
			//Se pone el indice de la lista 2 a ini2 de nuevo
			indiceLista2 = ini2;
		}
		if (indiceLista1 == fin1 || salir == true) break;
		else ++indiceLista1;
	}
	if (salir == true) return retorno;
	else return fin1;
}

bool resuelveCaso() {
	std::list <int> lista1;
	std::list <int > lista2;
	int tam1, tam2;
	std::cin >> tam1 >> tam2;
	if (tam1==0 && tam2==0) return false;
	for (int i = 0; i < tam1; ++i) {
		int n; std::cin >> n;
		lista1.push_back(n);
	}
	for (int i = 0; i < tam2; ++i) {
		int n; std::cin >> n;
		lista2.push_back(n);
	}
	
	auto it = Mysearch(lista1.begin(), lista1.end(), lista2.begin(), lista2.end());
	while (it != lista1.end()) {
		if (it != lista1.end()) {
			for (int i = 0; i < lista2.size(); ++i) it = lista1.erase(it);
		}
		it = Mysearch(lista1.begin(), lista1.end(), lista2.begin(), lista2.end());
	}
	
	//-------------------------------------------------
	for (auto it2 = lista1.begin(); it2 != lista1.end(); ++it2) {
		std::cout << (*it2) << " ";
	}
	std::cout << "\n";

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