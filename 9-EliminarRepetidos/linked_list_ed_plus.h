#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h
#include "linked_list_ed.h"
#include <iostream>
#include <stdexcept>  // std::domain_error

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:
	void eliminarRepetidos() {
		Nodo* punteroActual = this->prim;
		while (punteroActual->sig != nullptr) {
			if (punteroActual->sig->elem == punteroActual->elem) {
				Nodo* temp = punteroActual->sig;
				punteroActual->sig = temp->sig;
				delete temp;
			}
			else punteroActual = punteroActual->sig;
		}
	}

	void mostrarLista() {
		Nodo* punteroActual = this->prim;
		while (punteroActual != nullptr) {
			std::cout << punteroActual->elem<<" ";
			punteroActual = punteroActual->sig;
		}
	}

};
#endif // linked_list_ed_h
