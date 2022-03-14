#ifndef queue_eda_plus_h
#define queue_eda_plus_h

#include <stdexcept>  // std::domain_error
#include <iostream>
#include "queue_eda.h"
#include <stack>

template <class T>
class queue_plus: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void revertirSegundaTransformacion() {
		std::stack<char> ultimos;
		int tam = this->nelems;
		for (int i = 0; i < tam && !this->empty(); ++i) {
			char temp = this->front();
			this->pop();
			if (i % 2 == 0) this->push(temp);
			else ultimos.push(temp);
		}
		while (!ultimos.empty()) {
			this->push(ultimos.top());
			ultimos.pop();
		}
	}
	
	void revertirPrimeraTransformacion() {
		std::stack<char> pila;
		int n = this->nelems;
		for (int i = 0; i < n; ++i) {
			char temp = this->front();
			this->pop();
			if (esVocal(temp)) this->push(temp);
			else {
				pila.push(temp);
				if (!this->empty()) {
					while (!this->empty() && !esVocal(this->front())) {
						pila.push(this->front());
						this->pop();
						++i;
					}
				}
				while (!pila.empty()) {
					this->push(pila.top());
					pila.pop();
				}
			}
		}
	}
	

	bool esVocal(char c) {
		return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
	}

	void mostrarLista() {
		while (!this->empty()) {
			std::cout << this->front();
			this->pop();
		}
		std::cout << "\n";
	}
};

#endif // queue_eda_h
