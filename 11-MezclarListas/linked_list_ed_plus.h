//
//  linked_list_ed.h
//
//  Implementación del TAD linked_list con nodos enlazados
//  y punteros al primer y  último nodo
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita 
//  Adaptada de la implementación del queue realizada por Alberto Verdejo

#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h

#include <stdexcept>  // std::domain_error
#include <iostream>
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:

	void mezclarListas(linked_list_ed_plus<T> &lista2) {
		Nodo* punteroA = nullptr;
		while (this->prim != punteroA && ((lista2.prim) != nullptr)) {
			if (this->prim->elem <= lista2.prim->elem) { //Si el elemento de la lista A es menor que el de B
				this->ult->sig = this->prim; //Enlazamos el ultimo con el primero 
				this->ult = this->ult->sig; //Actualizamos el ultimo
				this->prim = this->prim->sig; //Actualizamos el primero al siguiente
				this->ult->sig = nullptr; //Actualizamos que
			}
			else { //Sino, lo enlazamos
				this->ult->sig = lista2.prim;
				this->ult = this->ult->sig;
				lista2.prim = lista2.prim->sig;
				this->ult->sig = nullptr;
			}
			if (punteroA == nullptr) punteroA = this->ult;
		}
		//Entonces, ahora puede que queden algunos elementos por enlazar de A o B (solo se da una opcion) entonces puede que entre a alguno
		//de los dos bucles siguientes (pero solo a uno!)
		while (lista2.prim != nullptr) {
			this->ult->sig = lista2.prim;
			this->ult = this->ult->sig;
			lista2.prim = lista2.prim->sig;
			this->ult->sig = nullptr;
		}
		while (this->prim!=punteroA) {
			this->ult->sig = this->prim;
			this->ult = this->ult->sig;
			this->prim = this->prim->sig;
			this->ult->sig = nullptr; 
		}
	}

	void mostrarLista() {
		Nodo* punteroActual = this->prim;
		while (punteroActual != nullptr) {
			std::cout << punteroActual->elem << " ";
			punteroActual = punteroActual->sig;
		}
	}

};

#endif // linked_list_ed_h
