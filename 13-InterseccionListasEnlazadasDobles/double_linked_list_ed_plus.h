//
//  double_linked_list_ed.h
//
//  Implementación del TAD double_linked_list con nodos doblemente
//   enlazados, circular, nodo cabecera (nodo fantasma) y puntero 
//   al nodo cabecera
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita 
//  Adaptada de la implementación del deque realizada por Alberto Verdejo

#ifndef double_linked_list_ed_plus_h
#define double_linked_list_ed_plus_h

#include <iostream>
#include <stdexcept>
#include <cassert>
#include "double_linked_list_ed.h"

template <typename T>
class double_linked_list_ed_plus: public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:

	void interseccion(double_linked_list_ed<T> &lista2) {
		auto punteroA = this->fantasma->sig;
		while (punteroA != this->fantasma && !lista2.empty()) {
			if ((punteroA->elem) < lista2.front()){
				punteroA = punteroA->sig;
				this->borra_elem(punteroA->ant);
			}
			else if (punteroA->elem == lista2.front()) {
				punteroA = punteroA->sig;
				lista2.pop_front();
			}
			else lista2.pop_front();
		}
		while (punteroA != this->fantasma) {
			punteroA = punteroA->sig;
			this->borra_elem(punteroA->ant);
		}
	}

	void mostrarLista() {
		while (!this->empty()) {
			std::cout << this->front() << " ";
			this->pop_front();
		}
		std::cout << "\n";
	}
};

#endif // double_linked_list_ed_h
