#include <iostream>
#include <cmath>

#include "../arboles/abin.h"
#include "../arboles/agen.h"
#include "../arboles/apos.h"
#include "../arboles/abb.h"
#include "../contenedores/pila.h"

// Ejercicio 2
template <typename T> void anadirElementoMinMax(Apo<T>&, T);

template <typename T> void anadirElementoMinMax(Apo<T>& A, T elto)
{
    
}

// Ejercicio 5
template <typename T> int alturaArbolGeneral(typename Agen<T>::nodo nodo, Agen<T> A);
template <typename T> void dibujarMatrizDeArbol(Agen<T> A);
template <typename T> void dibujarMatrizDeArbolRec(typename Agen<T>::nodo nodo, Agen<T> A, Pila<T>& P);

template <typename T> int alturaArbolGeneral(typename Agen<T>::nodo nodo, Agen<T> A)
{
    if(A.padre(nodo) == Agen<T>::NODO_NULO)
        return 0;
    else
        return 1 + alturaArbolGeneral(A.padre(nodo), A);
}

template <typename T> void dibujarMatrizDeArbol(Agen<T> A) {
    Pila<T> P;
    dibujarMatrizDeArbolRec(A.raiz(), A, P);
    
    int vector[8][8];
    while(!P.vacia()) {
        std::cout << P.tope() << std::endl;
        T elto = P.tope();
        vector[elto.i][elto.j] = elto.val;
        P.pop();
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //std::cout << ((vector[j][i]) ? 'B' : 'N');
            std::cout << (vector[i][j]);
        }
        std::cout << std::endl;
    }
}

template <typename T> void dibujarMatrizDeArbolRec(typename Agen<T>::nodo nodo, Agen<T> A, Pila<T>& P)
{
    //std::cout << A.elemento(nodo) << std::endl;
    if(nodo != Agen<T>::NODO_NULO)
    {
        if(A.hijoIzqdo(nodo) == Agen<T>::NODO_NULO)
        {
            if(alturaArbolGeneral(nodo, A) == 3)
                P.push(A.elemento(nodo));
            else
            {
                for (int i = 0; i < std::pow(4, (3 - alturaArbolGeneral(nodo, A))); i++) {
                    P.push(A.elemento(nodo));
                }
            }
        }
        else
        {
            if(A.elemento(nodo) == ' ')
            {
                typename Agen<T>::nodo nod = A.hijoIzqdo(nodo);
                for (int i = 0; i < 4; i++) {
                    dibujarMatrizDeArbolRec(nod, A, P);
                    nod = A.hermDrcho(nod);
                }
            }
        }
    }
}
