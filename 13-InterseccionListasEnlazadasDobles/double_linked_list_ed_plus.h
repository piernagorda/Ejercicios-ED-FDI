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
		auto punteroA = this->front;
		auto punteroAnteriorA = this->fantasma;
		auto punteroB = lista2.front();
		while (punteroA->sig != this->fantasma && punteroB != lista2.fantasma) {
			if (punteroA->elem == punteroB->elem) {
				punteroAnteriorA = punteroA;
				punteroA = punteroA->sig;
				punteroB = punteroB->sig;
			}
			else if (punteroA->elem < punteroB->elem) { //Tenemos que pasar del elemento de A y avanzar al siguiente
				punteroAnteriorA->sig = punteroA->sig;
				punteroA = punteroA->sig;
			}
			else {
				punteroB=punteroB->sig;
			}
		}
	}

	void mostrarLista() {
		if (!this->empty()) {
			auto primero = this->front();
			while (primero != this->fantasma) {
				std::cout << (primero->elem) << " ";
				primero = primero->sig;
			}
		}
		std::cout << "\n";
	}
};

#endif // double_linked_list_ed_h
