#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h

#include <iostream>
#include <stdexcept>  // std::domain_error
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:

	void intercambiarDosADos() {
		Nodo* punteroActual = this->prim;
		Nodo* punteroAnterior = nullptr;
		while (punteroActual != nullptr && punteroActual->sig != nullptr) {
			Nodo* temp = punteroActual->sig->sig; //El tercer elemento
			if (punteroActual == this->prim) {
				punteroActual->sig->sig = punteroActual; //Hacemos que el segundo apunte al primero
				this->prim = punteroActual->sig; //Hacemos al segundo primero
				punteroActual->sig = temp; //El primero apunta ahora al tercero
				punteroAnterior = this->prim->sig;
			}
			else { 
				punteroActual->sig->sig = punteroActual; //Hacemos que el segundo apunte al primero
				punteroAnterior->sig = punteroActual->sig; //Enlazamos con la parte anterior de la lista
				punteroActual->sig = temp; //Enlazamos el segundo con el tercero
				punteroAnterior = punteroActual;
			}
			punteroActual = temp;
		}
	}

	void mostrarLista() {
		Nodo* punteroActual = this->prim;
		while (punteroActual != nullptr) {
			std::cout << punteroActual->elem << " ";
			punteroActual = punteroActual->sig;
		}
		std::cout << "\n";
	}
};

#endif // linked_list_ed_h
