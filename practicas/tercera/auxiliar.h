#include <iostream>
#include <algorithm>
#include "Agen.hpp"


// Ejercicio 1
template <typename T> int numHijos(typename Agen<T>::nodo nodo, Agen<T> A);
template <typename T> int gradoArbolGeneral(Agen<T> A);
template <typename T> int gradoArbolGeneralRec(typename Agen<T>::nodo nodo, Agen<T> A);

template <typename T> int numHijos(typename Agen<T>::nodo nodo, Agen<T> A)
{
    int numHijos = 0;
    typename Agen<T>::nodo izq = A.hijoIzqdo(nodo);
    
    while(izq != Agen<T>::NODO_NULO)
    {
        izq = A.hermDrcho(izq);
        numHijos++;
    }
    return numHijos;
}

template <typename T> int gradoArbolGeneral(Agen<T> A)
{
    return gradoArbolGeneralRec(A.raiz(), A);
}

template <typename T> int gradoArbolGeneralRec(typename Agen<T>::nodo nodo, Agen<T> A)
{
    int maximo;
    typename Agen<T>::nodo hijo;
    
    if(nodo == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        maximo = numHijos(nodo, A);
        hijo = A.hijoIzqdo(nodo);
        
        while(hijo != Agen<T>::NODO_NULO)
        {
            maximo = std::max(gradoArbolGeneralRec(hijo, A), maximo);
            hijo = A.hermDrcho(hijo);
        }
        return maximo;
    }
}

/*
 *template <typename T> int gradoArbolGeneralRec(typename Agen<T>::nodo nodo, Agen<T> A)
 *{
 *    int gradoNodo;
 *    int gradoHijo;
 *    int gradoHijoMax;
 *    
 *    if(nodo == Agen<T>::NODO_NULO)
 *    {
 *        return 0;
 *    }
 *    else
 *    {
 *        gradoNodo = 0;
 *        gradoHijo = 0;
 *        gradoHijoMax = 0;
 *        
 *        typename Agen<T>::nodo izq = A.hijoIzqdo(nodo);
 *        while(izq != Agen<T>::NODO_NULO)
 *        {
 *            gradoHijo = gradoArbolGeneralRec(izq, A);
 *            
 *            if(gradoHijo > gradoHijoMax)
 *                gradoHijoMax = gradoHijo;
 *            
 *            izq = A.hermDrcho(izq);
 *            gradoNodo++;
 *        }
 *        return std::max(gradoHijoMax, gradoNodo);
 *    }
 *}
 */


