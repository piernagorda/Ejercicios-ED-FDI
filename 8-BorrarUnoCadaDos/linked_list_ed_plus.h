#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h

#include <stdexcept>  // std::domain_error
#include "Horas.h"
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
	public:
		void eliminarUnoCadaDos() {
			Nodo* puntero = this->prim;
			bool salir = false;
			while (puntero != nullptr && !salir) {
				if (puntero->sig != nullptr) {
					Nodo* temp = puntero->sig;
					puntero->sig = temp->sig;
					puntero = puntero->sig;
					delete temp;
				}
				else salir = true;
			}
		}

		void mostrarLista() {
			Nodo* puntero = this->prim;
			if (puntero != nullptr) {
				bool salir = false;
				while (!salir) {
					Horas hora = puntero->elem;
					hora.mostrarHora();
					std::cout << " ";
					puntero = puntero->sig;
					if (puntero == nullptr) salir = true;
				}
			}
		}
};

#endif // linked_list_ed_h
