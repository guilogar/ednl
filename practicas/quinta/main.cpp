#include <iostream>
#include "auxiliar.h"


int main(int argc, const char *argv[])
{
    Agen<char> A;
    A.insertarRaiz(' ');
    A.insertarHijoIzqdo(A.raiz(), ' ');
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 'N');
    A.insertarHermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), 'N');
    A.insertarHermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), 'B');
    A.insertarHermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), 'B');
    
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 'B');
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 'N');
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 'B');
    
    dibujarMatrizDeArbol(A);
    return 0;
}
