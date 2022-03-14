#ifndef horas_h
#define horas_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

class Horas {
public:
	Horas(std::string horas, std::string minutos, std::string segundos) {
		_horas = stoi(horas);
		_minutos = stoi(minutos);
		_segundos = stoi(segundos);
	}

	int getHora()const { return _horas; }
	
	int getMinutos() const { return _minutos; }
	
	int getSegundos() const { return _segundos; }

	void mostrarHora() const{
		std::cout << std::setw(2) << std::setfill('0') << _horas << ':' << std::setw(2) << _minutos << ':' << std::setw(2) << _segundos << std::setfill(' ');
	}

	bool operator==(Horas a) {
		return (_horas == a.getHora() && _minutos == a.getMinutos() && _segundos == a.getSegundos());
	}

	bool operator<(Horas a) {
		return (_horas < a.getHora() || _horas == a.getHora() && _minutos < a.getMinutos() || _horas == a.getHora() && _minutos == a.getMinutos() && _segundos < a.getSegundos());
	}

private:

	int _horas;
	int _minutos;
	int _segundos;

	
};
#endif
