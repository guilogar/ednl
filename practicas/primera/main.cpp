#include <iostream>

#ifndef IMPORTS
#define IMPORTS

//#include "abin.h"
#include "abinModified.h"
#include "abin_E-S.h"

#endif

#include "auxiliar.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Abin<int> Propio;
    Propio.insertarRaizB(0);
    Propio.insertarHijoIzqdoB(Propio.raizB(), 1);
    Propio.insertarHijoDrchoB(Propio.raizB(), 2);
    
    Abin<int>::nodo uno = Propio.hijoIzqdoB(Propio.raizB());
    Abin<int>::nodo dos = Propio.hijoDrchoB(Propio.raizB());
    
    Propio.insertarHijoIzqdoB(uno, 3);
    Propio.insertarHijoDrchoB(dos, 4);
    
    
    Abin<int>::nodo tres = Propio.hijoIzqdoB(uno);
    Abin<int>::nodo cuatro = Propio.hijoDrchoB(dos);
    
    Propio.insertarHijoIzqdoB(tres, 5);
    Propio.insertarHijoDrchoB(cuatro, 6);
    /*
     *Propio.insertarHijoIzqdoB(dos, 3);
     *Propio.insertarHijoDrchoB(dos, 4);
     *
     *Abin<int>::nodo tres = Propio.hijoIzqdoB(dos);
     *Abin<int>::nodo cuatro = Propio.hijoDrchoB(dos);
     *
     *Propio.insertarHijoIzqdoB(cuatro, 5);
     *Propio.insertarHijoDrchoB(cuatro, 6);
     *
     *Abin<int>::nodo cinco = Propio.hijoIzqdoB(cuatro);
     *Abin<int>::nodo seis = Propio.hijoDrchoB(cuatro);
     */
    
    /*
     *Abin<int> A;
     *rellenarAbin(A, 3);
     *
     *imprimirAbin(A);
     *
     *cout << "El numero de nodos del Arbol Binario A es => " << numNodosArbol(A) << endl;
     *cout << "La altura del arbol es => " << alturaArbol(A) << endl;
     *
     *cout << "La profundidad del nodo \"cuatro\" con recursividad es => " << profundidadNodoRec(cuatro, Propio) << endl;;
     *cout << "La profundidad del nodo \"cuatro\" con iterativo es => " << profundidadNodoIterativo(cuatro, Propio) << endl;
     *
     *cout << "Y la altura es => " << Propio.alturaB() << endl;
     *cout << "Y la profundidad de \"tres\" es => " << Propio.profundidadNodoRec(tres) << endl;
     *
     *cout << "El desequilibrio de este arbol es => " << desequilibrioArbol(Propio) << endl;
     */
     cout << "El desequilibrio de este arbol es => " << desequilibrioArbol(Propio) << endl;
    
    //cout << "¿Esté arbol es pseudocompleto? => " << (( arbolPseudoCompleto(Propio) ) ? "Sí :3" : "Nop ;(") << endl;
    
    
    return 0;
}
