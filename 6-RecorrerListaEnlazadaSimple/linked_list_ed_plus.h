#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h
#include <iostream>
#include <stdexcept>  // std::domain_error
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed <T >::Nodo;
public:
	void mostrarPropiedad(char c) {
		Nodo *puntero = this->prim;
		bool salir = false;
		while (!salir) {
			if (puntero->elem[0] == c) {
				std::cout << puntero->elem << " ";
				puntero = puntero->sig;
			}
			else puntero = puntero->sig;
			if (puntero->sig == nullptr) salir = true;
		}
	}
};
#endif // linked_list_ed_h
