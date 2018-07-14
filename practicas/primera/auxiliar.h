#ifndef IMPORTS
#define IMPORTS

#include "abinModified.h"
#include "abin.h"
#include "abin_E-S.h"

#endif

#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <algorithm>

// Cabeceras
int numNodosArbol(Abin<int> A);
int numNodosRec(Abin<int>::nodo nodo, Abin<int> A);

int alturaArbol(Abin<int> A);
int alturaRec(Abin<int>::nodo nodo, Abin<int> A);

int profundidadNodoRec(Abin<int>::nodo nodo, Abin<int> A);
int profundidadNodoIterativo(Abin<int>::nodo nodo, Abin<int> A);

int desequilibrioArbol(Abin<int> A);
int desequilibrioArbolRec(Abin<int>::nodo nodo, Abin<int> A);

bool arbolPseudoCompleto(Abin<int> A);
bool arbolPseudoCompletoRec(Abin<int>::nodo nodo, Abin<int> A);
bool nodoPseudoCompleto(Abin<int>::nodo nodo, Abin<int> A);

// Funciones
// Primero
int numNodosArbol(Abin<int> A)
{
    return numNodosRec(A.raizB(), A);
}

int numNodosRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if( nodo == Abin<int>::NODO_NULO )
        return 0;
    else
        return ( 1 + numNodosRec(A.hijoIzqdoB(nodo), A) + numNodosRec(A.hijoDrchoB(nodo), A) );
}

// Segundo
int alturaArbol(Abin<int> A)
{
    return alturaRec(A.raizB(), A);
}

int alturaRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if( nodo == Abin<int>::NODO_NULO )
        return -1;
    else
    {
        int izq = 1 + alturaRec(A.hijoIzqdoB(nodo), A);
        int der = 1 + alturaRec(A.hijoDrchoB(nodo), A);
        if( izq > der )
            return izq;
        else
            return der;
    }
}

// Tercero
int profundidadNodoRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if( nodo == Abin<int>::NODO_NULO )
        return -1;
    else
        return 1 + profundidadNodoRec(A.padreB(nodo), A);
}

int profundidadNodoIterativo(Abin<int>::nodo nodo, Abin<int> A) {
    int cont = 0;
    if( nodo == Abin<int>::NODO_NULO || nodo == A.raizB() )
        return 0;
    else
    {
        while( nodo != Abin<int>::NODO_NULO && nodo != A.raizB() ) {
            nodo = A.padreB(nodo);
            cont++;
        }
        return cont - 1;
    }
}

// Seis
int desequilibrioArbol(Abin<int> A)
{
    return desequilibrioArbolRec(A.raizB(), A);
}

int desequilibrioArbolRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        return std::max( std::abs(alturaRec(A.hijoIzqdoB(nodo), A) - alturaRec(A.hijoDrchoB(nodo), A)),
                         std::max(
                                   desequilibrioArbolRec(A.hijoIzqdoB(nodo), A), desequilibrioArbolRec(A.hijoDrchoB(nodo), A)
                                 )
               );
    }
}

// Siete
bool arbolPseudoCompleto(Abin<int> A)
{
    return arbolPseudoCompletoRec(A.raizB(), A);
}

bool arbolPseudoCompletoRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if( int altura = alturaRec(nodo, A) <= 2 )
    {
        std::cout << altura << std::endl;
        return ( nodoPseudoCompleto(A.hijoIzqdoB(nodo), A) && nodoPseudoCompleto(A.hijoDrchoB(nodo), A) );
    } else
    {
        int izq = alturaRec(A.hijoIzqdoB(nodo), A);
        int der = alturaRec(A.hijoDrchoB(nodo), A);
        
        if(izq == der)
            return arbolPseudoCompletoRec(A.hijoIzqdoB(nodo), A) && arbolPseudoCompletoRec(A.hijoDrchoB(nodo), A);
        else
            return ( izq > der ) ? arbolPseudoCompletoRec(A.hijoIzqdoB(nodo), A) : arbolPseudoCompletoRec(A.hijoDrchoB(nodo), A);
    }
}

bool nodoPseudoCompleto(Abin<int>::nodo nodo, Abin<int> A)
{
    return ( (A.hijoIzqdoB(nodo) == A.NODO_NULO && A.hijoDrchoB(nodo) == A.NODO_NULO) ||
             (A.hijoIzqdoB(nodo) != A.NODO_NULO && A.hijoDrchoB(nodo) != A.NODO_NULO)    );
}

#endif
