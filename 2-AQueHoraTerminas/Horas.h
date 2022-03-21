#ifndef horas_h
#define horas_h

#include <stdexcept>
#include <string>
#include <iomanip>
#include <iostream>

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

	Horas operator+(Horas a) {
		int horaRetorno = a.getHora() + _horas + ((a.getMinutos() + _minutos + (a.getSegundos() + _segundos) / 60) / 60);
		int minutosRetorno = (a.getMinutos() + _minutos + (a.getSegundos() + _segundos) / 60) % 60;
		int segundosRetorno = (a.getSegundos() + _segundos) % 60;
		if (horaRetorno > 23) throw std::overflow_error("Hoy no");
		else {
			Horas retorno = Horas(std::to_string(horaRetorno), std::to_string(minutosRetorno), std::to_string(segundosRetorno));
			return retorno;
		}
	}

private:

	int _horas;
	int _minutos;
	int _segundos;

	
};
#endif
