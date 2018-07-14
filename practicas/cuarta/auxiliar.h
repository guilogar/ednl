//#include "../arboles/abb.h"
#include "abbModified.h"
#include "../contenedores/pila.h"

#include <iostream>

template <typename T> void printAbin(typename Abin<T>::nodo nodo, Abin<T> A) {
    
    if(nodo != Abin<T>::NODO_NULO)
    {
        std::cout << A.elemento(nodo) << std::endl;
        printAbin(A.hijoIzqdoB(nodo), A);
        printAbin(A.hijoDrchoB(nodo), A);
    }
}
template <typename T> void printAbb(Abb<T> A) {
    
    if(!A.vacio())
    {
        std::cout << A.elemento() << std::endl;
        printAbb(A.izqdo());
        printAbb(A.drcho());
    }
}

// Ejercicio 3

template <typename T> Abb<T> equilibrarArbol(Abb<T> A);
template <typename T> int equilibrarArbolRec(Abb<T> A, Pila<T>& P);

template <typename T> Abb<T> equilibrarArbol(Abb<T> A)
{
    Pila<T> izq;
    Pila<T> der;
    izq.push(A.elemento());
    int num_elements_izq = 1 + equilibrarArbolRec(A.izqdo(), izq);
    int num_elements_der = equilibrarArbolRec(A.drcho(), der);
    
    int total = num_elements_izq + num_elements_der;
    T vector[total];
    for (int i = 0; i < num_elements_izq; i++) {
        vector[i] = izq.tope();
        izq.pop();
    }
    for (int i = num_elements_izq; i < total; i++) {
        vector[i] = der.tope();
        der.pop();
    }
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            if(vector[i] < vector[j]) {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
    int pos = (total / 2) + 1;
    
    Abb<T> B;
    B.insertar(vector[pos]);
    for (int i = pos - 1; i >= 0; i--) {
        B.insertar(vector[i]);
    }
    for (int i = pos + 1; i < total; i++) {
        B.insertar(vector[i]);
    }
    
    return B;
}


template <typename T> int equilibrarArbolRec(Abb<T> A, Pila<T>& P)
{
    if(A.vacio())
        return 0;
    else
    {
        P.push(A.elemento());
        return 1 + equilibrarArbolRec(A.izqdo(), P) + equilibrarArbolRec(A.drcho(), P);
    }
}


// Ejericio 6
typedef char T;
typedef Abb<T> Conjunto;

Conjunto DiferenciaConjuntos(Conjunto A, Conjunto B);
void DiferenciaConjuntosRec(Conjunto A, Conjunto B, Conjunto& C);
bool ElementoPerterneceConjunto(T elto, Conjunto B);
Conjunto UnionConjuntos(Conjunto A, Conjunto B);
Conjunto InterseccionConjuntos(Conjunto A, Conjunto B);

bool ElementoPerteneceConjunto(T elto, Conjunto B)
{
    if(B.vacio())
    {
        return false;
    }
    else
    {
        if(elto == B.elemento())
            return true;
        else
            return ElementoPerteneceConjunto(elto, B.izqdo()) ||
                   ElementoPerteneceConjunto(elto, B.drcho());
    }
}

Conjunto DiferenciaConjuntos(Conjunto A, Conjunto B)
{
    Conjunto C;
    DiferenciaConjuntosRec(A, B, C);
    
    return C;
}

void DiferenciaConjuntosRec(Conjunto A, Conjunto B, Conjunto& C)
{
    if(!A.vacio())
    {
        if(! ElementoPerteneceConjunto(A.elemento(), B))
            C.insertar(A.elemento());

        DiferenciaConjuntosRec(A.izqdo(), B, C);
        DiferenciaConjuntosRec(A.drcho(), B, C);
    }
}

