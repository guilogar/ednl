#include "Agen.hpp"
#include "agen_E-S.h"
#include "auxiliar.h"

int main(int argc, const char *argv[])
{
    Agen<int> Arbolito;
    rellenarAgen(Arbolito, 10);
    int grado = gradoArbolGeneral(Arbolito);
    std::cout << "Grado => " << grado << std::endl;
    /*
     *Arbolito.insertarRaiz(5);
     *Agen<int>::nodo raiz = Arbolito.raiz();
     *
     *Arbolito.insertarHijoIzqdo(raiz, 10);
     *
     *Agen<int>::nodo izq = Arbolito.hijoIzqdo(raiz);
     *Arbolito.insertarHermDrcho(izq, 6);
     */
    
    
    return 0;
}
