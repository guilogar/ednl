#include <iostream>
#include "Agen.hpp"
#include "abin.h"

struct nod {
    double operando;
    char operador;
    nod(char oper = 'n', double operand = 0.0): operando(operand), operador(oper) {}
};

// Ejercicio 1
bool arbolesBinSimil(Abin<int> A, Abin<int> B);
bool arbolesBinSimilRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> B);

bool arbolesBinSimil(Abin<int> A, Abin<int> B)
{
    return (A.arbolVacioB() && B.arbolVacioB()) ? true : arbolesBinSimilRec(A.raizB(), A, B.raizB(), B);
}

bool arbolesBinSimilRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> B)
{
    
    if(nodoA != Abin<int>::NODO_NULO && nodoB != Abin<int>::NODO_NULO)
    {
        bool igualIzq = arbolesBinSimilRec(A.hijoIzqdoB(nodoA), A, B.hijoIzqdoB(nodoB), B);
        bool igualDer = arbolesBinSimilRec(A.hijoDrchoB(nodoA), A, B.hijoDrchoB(nodoB), B);
        return igualIzq && igualDer;
    } else
        return (nodoA == Abin<int>::NODO_NULO && nodoB == Abin<int>::NODO_NULO);
}

// Ejercicio 2
Abin<int> arbolReflec(Abin<int> A);
void arbolReflecRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> &B);

Abin<int> arbolReflec(Abin<int> A)
{
    Abin<int> B;
    if(!A.arbolVacioB())
    {
        B.insertarRaizB(A.elemento(A.raizB()));
        arbolReflecRec(A.raizB(), A, B.raizB(), B);
    }
    return B;
}

void arbolReflecRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> &B)
{
    if(nodoA != Abin<int>::NODO_NULO)
    {
        Abin<int>::nodo izqA = A.hijoIzqdoB(nodoA);
        Abin<int>::nodo derA = A.hijoDrchoB(nodoA);
        
        if(izqA != Abin<int>::NODO_NULO)
        {
            B.insertarHijoDrchoB(nodoB, A.elemento(izqA));
            
            Abin<int>::nodo derB = B.hijoDrchoB(nodoB);
            arbolReflecRec(izqA, A, derB, B);
        }
        if(derA != Abin<int>::NODO_NULO)
        {
            B.insertarHijoIzqdoB(nodoB, A.elemento(derA));
            
            Abin<int>::nodo izqB = B.hijoIzqdoB(nodoB);
            arbolReflecRec(derA, A, izqB, B);
        }
    }
}

// Ejercicio 3
template <typename T> double resArbolAritmetico(Abin<T>);
template <typename T> bool esNodoHoja(typename Abin<T>::nodo, Abin<T>);
template <typename T> double resArbolAritmeticoRec(typename Abin<T>::nodo, Abin<T>);

template <typename T> double resArbolAritmetico(Abin<T> A)
{
    if(A.arbolVacioB())
        return 0;
    else
        return resArbolAritmeticoRec(A.raizB(), A);
}

template <typename T> bool esNodoHoja(typename Abin<T>::nodo nodo, Abin<T> A) {
    //return (A.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO && A.hijoDrchoB(nodo) == Abin<T>::NODO_NULO);
    return (A.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO);
}

template <typename T> double resArbolAritmeticoRec(typename Abin<T>::nodo nodo, Abin<T> A)
{
   if(esNodoHoja(nodo, A))
       return A.elemento(nodo);
   else
   {
       char operador = (char) A.elemento(nodo);
       switch (operador)
       {
           case '+':
               return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) +
                      resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
               break;
           case 'x':
           case '*':
               return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) *
                      resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
               break;
           case '-':
               return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) -
                      resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
               break;
           case '/':
               return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) /
                      resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
               break;
       }
   }
}

// Ejercicio 4


// Ejercicio nodos nostalgicos

template <typename T> int profundidadNodoRec(typename Abin<T>::nodo, Abin<T>);

template <typename T> int numSucesoresNodoRec(typename Abin<T>::nodo, Abin<T>);
template <typename T> int numSucesoresNodo(typename Abin<T>::nodo, Abin<T>);

template <typename T> bool nodoNostalgico(typename Abin<T>::nodo, Abin<T>);

template <typename T> int numNodosNostalgicosArbolRec(typename Abin<T>::nodo, Abin<T>);
template <typename T> int numNodosNostalgicosArbol(Abin<T> A);

template <typename T> int profundidadNodoRec(typename Abin<T>::nodo nodo, Abin<T> A)
{
    if( nodo == Abin<T>::NODO_NULO )
        return -1;
    else
        return 1 + profundidadNodoRec(A.padreB(nodo), A);
}

template <typename T> int numSucesoresNodoRec(typename Abin<T>::nodo nodo, Abin<T> A)
{
    if(nodo == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return 1 + numSucesoresNodoRec(A.hijoIzqdoB(nodo), A) + numSucesoresNodoRec(A.hijoDrchoB(nodo), A);
    }
}

template <typename T> int numSucesoresNodo(typename Abin<T>::nodo nodo, Abin<T> A)
{
    return numSucesoresNodoRec(A.hijoIzqdoB(nodo), A) + numSucesoresNodoRec(A.hijoDrchoB(nodo), A);
}

template <typename T> bool nodoNostalgico(typename Abin<T>::nodo nodo, Abin<T> A)
{
    return (profundidadNodoRec(nodo, A) > numSucesoresNodo(nodo, A));
}

template <typename T> int numNodosNostalgicosArbolRec(typename Abin<T>::nodo nodo, Abin<T> A)
{
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        int nos = (nodoNostalgico(nodo, A)) ? 1 : 0;
        return nos + numNodosNostalgicosArbolRec(A.hijoIzqdoB(nodo), A) + numNodosNostalgicosArbolRec(A.hijoDrchoB(nodo), A);
    }
}

template <typename T> int numNodosNostalgicosArbol(Abin<T> A)
{
    return numNodosNostalgicosArbolRec(A.raizB(), A);
}







