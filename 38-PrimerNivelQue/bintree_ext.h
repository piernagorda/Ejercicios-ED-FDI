#ifndef bintree_ext_h
#define bintree_ext_h

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include "bintree_eda.h"

//Alumno: Javier Piernagorda Olive
//Correo: jpiernag@ucm.es
//Fecha: 22/2/2022

template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_ext() : bintree <T >() {}
    bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) :
        bintree<T>(l, e, r) {}

    struct tDatos {
        Link nodo;
        int nivel;
    };

    int levelRet(T const& buscado) {
        int sol = _levelRet(buscado);
        return sol ;
    }

protected:

    int _levelRet(T buscado) {
        int nivel = -1, profundidad = 1, apariciones=0;
        bool salir = false;
        std::queue<tDatos> miCola;
        //Metemos la raiz
        miCola.push({ this->raiz, profundidad });
        
        while (!miCola.empty() && !salir) {
            auto temp = miCola.front();
            miCola.pop();
            if (temp.nodo->elem == buscado) ++apariciones;
            //Metemos los hijos en cola con un nivel de profundidad mas
            if (temp.nodo->left != nullptr) miCola.push({ temp.nodo->left, temp.nivel + 1 });
            if (temp.nodo->right != nullptr) miCola.push({ temp.nodo->right, temp.nivel + 1 });
            //Vamos viendo si los del nivel actual son el elemento buscado
            if (!miCola.empty()) {
                while (!miCola.empty() && !salir && miCola.front().nivel == temp.nivel ) {
                    if (miCola.front().nodo->left != nullptr) miCola.push({ miCola.front().nodo->left, miCola.front().nivel + 1 });
                    if (miCola.front().nodo->right != nullptr) miCola.push({ miCola.front().nodo->right, miCola.front().nivel + 1 });
                    if (miCola.front().nodo->elem == buscado) ++apariciones;
                    if (apariciones == 2) {
                        nivel = miCola.front().nivel;
                        salir = true;
                    }
                    miCola.pop();
                }
                apariciones = 0;
            }
        }
        return nivel;
    }

};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_ext<T> leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_ext<T> iz = leerArbol_ext(vacio);
        bintree_ext<T> dr = leerArbol_ext(vacio);
        return { iz, raiz, dr };
    }
}
#endif // bintree_eda_h
