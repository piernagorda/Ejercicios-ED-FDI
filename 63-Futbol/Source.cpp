#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <list>

/*
Ante el cambio de equipo continuo por parte de los jugadores, la Liga de F´utbol Profesional necesita
un nuevo gestor de futbolistas, m´as eficiente, que le permita conocer el equipo actual que tiene fichado
a cada jugador, o ciertos datos sobre el historial de fichajes.
La implementaci´on del sistema se realizar´a mediante un TAD gestor futbolistas con las siguientes
operaciones:

*/

struct tDatosJugador {
	std::string equipoActual;
	std::list<std::string>::iterator itJugador;
	std::unordered_map<std::string, int> equiposEnLosQueHaJugado;
};

class LigaFutbol {
public:
	LigaFutbol() {

	}

	/*
	• fichar(jugador, equipo): si el jugador (un string) no est´a dado de alta en el sistema, entonces
se registra por primera vez como perteneciente al equipo (otro string). Si el equipo no estaba
dado de alta, se le da en ese momento. Si el jugador ya estaba dado de alta, la operaci´on supone
un cambio de equipo, pasando a estar fichado por el nuevo equipo. Si el jugador ya estaba fichado
por este equipo, la operaci´on no tiene ning´un efecto.
	*/
	void fichar(std::string jugador, std::string equipo) {
		auto itMapaJugador = mapaJugadores.find(jugador);
		auto itMapaEquipo = mapaJugadores.find(equipo);
		if (itMapaJugador == mapaJugadores.end()) { //El jugador no existe -> se mete
			mapaJugadores[jugador].equipoActual = equipo;
			mapaJugadores[jugador].equiposEnLosQueHaJugado[equipo] = 1;
			mapaEquipos[equipo].push_back(jugador);
			auto itJugador = mapaEquipos[equipo].end();
			--itJugador;
			mapaJugadores[jugador].itJugador = itJugador;
		}
		else { //Esta cambiando de equipo
			std::string equipoAntiguo = mapaJugadores[jugador].equipoActual;
			mapaJugadores[jugador].equipoActual = equipo;
			mapaJugadores[jugador].equiposEnLosQueHaJugado[equipo] = 1;
			mapaEquipos[equipoAntiguo].erase(mapaJugadores[jugador].itJugador);
			mapaEquipos[equipo].push_back(jugador);
			auto itJugador = mapaEquipos[equipo].end();
			--itJugador;
			mapaJugadores[jugador].itJugador = itJugador;
		}
	}

	/*
	• equipo actual(jugador): devuelve el equipo actual por el que est´a fichado este jugador. En caso
de que el jugador no est´e dado de alta, lanzar´a una excepci´on domain error con mensaje Jugador
inexistente.
	*/
	std::string equipo_actual(std::string jugador) {
		auto it = mapaJugadores.find(jugador);
		if (it == mapaJugadores.end()) throw std::domain_error("Jugador inexistente");
		else return it->second.equipoActual;
	}
	/*
	• fichados(equipo): devuelve cu´antos jugadores tiene fichados actualmente el equipo. En caso
de que el equipo no est´e dado de alta, lanzar´a una excepci´on domain error con mensaje Equipo
inexistente.
	*/
	int fichados(std::string equipo) {
		auto it = mapaEquipos.find(equipo);
		if (it == mapaEquipos.end()) throw std::domain_error("Equipo inexistente");
		else return it->second.size();
	}
	/*
	• ultimos fichajes(equipo, n): devuelve en un tipo de datos lineal los n ´ultimos jugadores fichados por el equipo (n > 0) y que a´un siguen estando fichados por ese equipo. La tipo lineal estar´a
ordenada por el momento en el que fueron fichados, primero el ´ultimo fichaje. En caso de que el
equipo tenga menos de n jugadores, se devolver´an todos, ordenados de la misma manera. En caso
de que el equipo no est´e dado de alta, lanzar´a una excepci´on domain error con mensaje Equipo
inexistente.
	*/
	std::vector<std::string> ultimos_fichajes(std::string equipo, int n) {
		auto it = mapaEquipos.find(equipo);
		std::vector<std::string> ultimosFichajes;
		if (it == mapaEquipos.end()) throw std::domain_error("Equipo inexistente");
		else {
			if (it->second.size() > 0) {
				/*
				std::cout << "---\n";
				std::cout << "La lista de fichajes de "+equipo+" contiene: ";
				for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) std::cout << (*it2) << " ";
				std::cout << "\n";
				std::cout << "---\n";
				*/
				auto itFin = it->second.end();
				--itFin;
				while (n > 0) {
					ultimosFichajes.push_back(*itFin);
					if (itFin == it->second.begin()) break;
					--n;
					--itFin;
				}
			}
		}
		return ultimosFichajes;
	}

	/*
	• cuantos equipos(jugador): devuelve el n´umero de equipos distintos por los que ha estado fichado
el jugador. Si el jugador no est´a dado de alta en el sistema, devolver´a 0.
	*/
	int cuantos_equipos(std::string jugador) {
		auto it = mapaJugadores.find(jugador);
		if (it == mapaJugadores.end()) return 0;
		else return it->second.equiposEnLosQueHaJugado.size();
	}


private:
	//Tendremos un mapa de jugadores que guarde: su nombre como clave, y como valor: el equipo en el que juega y los equipos en los que ha jugado
	std::unordered_map<std::string, tDatosJugador> mapaJugadores;
	//Para los equipos solo hace falta guardar el nombre y una lista donde vayamos metiendo por el final los fichajes mas recientes y guardemos sus iteradores
	std::unordered_map<std::string, std::list<std::string>> mapaEquipos;
};

bool resuelveCaso() {
	std::string entrada;
	std::cin >> entrada;
	if (!std::cin) return false;
	LigaFutbol miLiga;
	while (entrada != "FIN") {
		
		//std::cout << "entrada recibida: " << entrada << std::endl;
		if (entrada == "fichar") {
			std::string equipo, jugador;
			std::cin >> jugador >> equipo;
			miLiga.fichar(jugador, equipo);
		}
		else if (entrada == "ultimos_fichajes") {
			std::string equipo; int n;
			std::cin >> equipo >> n;
			try {
				std::vector<std::string> sol = miLiga.ultimos_fichajes(equipo, n);
				std::cout << "Ultimos fichajes de "+equipo+": ";
				for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
				std::cout << "\n";
			}
			catch (std::exception e) {
				std::cout << "ERROR: "<< e.what() << "\n";
			}
		}
		else if (entrada == "cuantos_equipos") {
			std::string jugador;
			std::cin >> jugador;
			try {
				int sol = miLiga.cuantos_equipos(jugador);
				std::cout << "Equipos que han fichado a "+jugador+": "<< sol << std::endl;
			}
			catch (std::exception e) {
				std::cout<<"ERROR: "<<e.what() << "\n";
			}
		}
		else if (entrada == "fichados") {
			std::string equipo;
			std::cin >> equipo;
			try {
				int sol = miLiga.fichados(equipo);
				std::cout<<"Jugadores fichados por "+equipo+": "<<sol<<std::endl;
			}
			catch (std::exception e) {
				std::cout << "ERROR: "<<e.what() << "\n";
			}
		}
		else if (entrada == "equipo_actual") {
			std::string jugador;
			std::cin >> jugador;
			try {
				std::string sol = miLiga.equipo_actual(jugador);
				std::cout << "El equipo de "+jugador+" es "<< sol << std::endl;
			}
			catch (std::exception e) {
				std::cout << "ERROR: "<<e.what() << "\n";
			}
		}
		std::cin >> entrada;
	}
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