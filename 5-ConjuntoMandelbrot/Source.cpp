#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

//Alumno: Javier Piernagorda Olive
//Fecha: 22/3/2022
//Correo: jpiernag@ucm.es

template <typename T>
class complejos {
public:

	complejos(float real, float imaginaria):_real(real), _imaginaria(imaginaria){
	}

	float parteReal() const { return this->_real; }
	float parteImaginaria() const { return this->_imaginaria; }

	complejos operator+(complejos a) {
		//(a+bi) + (c+di) = (a+c) + (b+d)i
		complejos retorno(this->_real + a.parteReal(), this->_imaginaria + a.parteImaginaria());
		return retorno;
	}

	complejos operator*(complejos otro) {
		//(a+bi) * (c+di) = (a*c-b*d) + (a*d+c*b)i
		float a = this->parteReal();
		float b = this->parteImaginaria();
		float c = otro.parteReal();
		float d = otro.parteImaginaria();
		complejos retorno(a * c - b * d, a * d + c * b);
		return retorno;
	}

private:
	float _real;
	float _imaginaria;
};

complejos<float> esDivergente(int iteracion, complejos<float> c, bool &diverge) {
	if (iteracion == 0) return { 0, 0 };
	else {
		complejos<float> ret = esDivergente(iteracion - 1, c, diverge);
		if (sqrt(ret.parteReal() * ret.parteReal() + ret.parteImaginaria() * ret.parteImaginaria()) > 2) {
			diverge = true;
			return { 0,0 };
		}
		else return ret*ret + c;
	}
}

void resuelveCaso() {
	float real, imaginaria;
	int iteraciones;
	std::cin >> real >> imaginaria >> iteraciones;
	complejos<float> num(real, imaginaria);
	bool diverge = false;
	esDivergente(iteraciones, num, diverge);
	if (!diverge) std::cout << "SI \n";
	else std::cout << "NO\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int numCasos; std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}