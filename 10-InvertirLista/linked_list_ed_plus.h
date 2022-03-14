#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h

#include <iostream>
#include <stdexcept>  // std::domain_error
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:

	void invertirNodos() {
		Nodo* ultimo = this->prim;
		while (this->prim!=this->ult) {
			Nodo* siguienteDelUltimo = this->ult->sig;
			this->ult->sig = this->prim; //Le asignamos al ultimo el primero como siguiente
			this->prim = this->prim->sig; //Asignamos el nuevo primero
			this->ult->sig->sig = siguienteDelUltimo;
		}
		this->ult = ultimo;
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
