#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h
#include <iostream>
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed <T >::Nodo;
	public:

		void duplicarNodos() {
			Nodo* puntero = this->prim;
			if (puntero != nullptr) {
				bool salir = false;
				while (!salir) {
					Nodo* copia = new Nodo(puntero->elem, puntero->sig);
					puntero->sig = copia;
					if (copia->sig == nullptr) salir = true;
					puntero = copia->sig;
				}
			}
		}

		void mostrarLista() {
			Nodo* puntero = this->prim;
			if (puntero!= nullptr) {
				bool salir = false;
				while (!salir) {
					std::cout << puntero->elem << " ";
					puntero = puntero->sig;
					if (puntero == nullptr) salir = true;
				}
			}
		}
};

#endif // linked_list_ed_h
