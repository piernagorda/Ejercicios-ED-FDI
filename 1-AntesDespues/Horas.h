#ifndef HORAS_H
#define HORAS_H
#include <stdexcept>

class Horas {
public:

	Horas(std::string hora) : _horas(0), _minutos(0), _segundos(0) {
		construirHora(hora);
		comprobarHoraValida();
	}

	int getHoras()const { return _horas; }
	int getMinutos() const { return _minutos; }
	int getSegundos() const { return _segundos; }

private:
	int _horas;
	int _minutos;
	int _segundos;

	void construirHora(std::string hora) {
		std::string segundos = hora.substr(6,2);
		_segundos = stoi(segundos);
		std::string minutos = hora.substr(3, 2);
		_minutos = stoi(minutos);
		std::string horas = hora.substr(0, 2);
		_horas = stoi(horas);
	}

	void comprobarHoraValida() {
		if (_horas < 0 || _horas>23 || _minutos < 0 || _minutos>59 || _segundos < 0 || _segundos>59) throw std::invalid_argument("Hora no valida");
		
	}
	
	bool operator<(Horas a, Horas b) {
	return a.getHoras() < b.getHoras() || a.getHoras() == b.getHoras() && a.getMinutos() < b.getMinutos() || a.getHoras() == b.getHoras() && a.getMinutos() == b.getMinutos() && a.getSegundos() < b.getSegundos();
	}

	bool operator==(Horas a, Horas b) {
		return a.getHoras() == b.getHoras() && a.getMinutos() == b.getMinutos() && a.getSegundos() == b.getSegundos();
	}

};


#endif