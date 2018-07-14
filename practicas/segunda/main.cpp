#include "AbinVec.h"
#include "auxiliar.h"
#include "abin_E-S.h"


using namespace std;

int main(int argc, const char *argv[])
{
    AbinVec<int> AVec(5, 0);
    AVec.insertarRaizB(6);
    AVec.insertarHijoIzqdoB(AVec.raizB(), 3);
    AVec.insertarHijoDrchoB(AVec.raizB(), 9);
    AVec.enseniarVector();
    
    AbinVec<int>::nodo izq = AVec.hijoIzqdoB(AVec.raizB());
    AbinVec<int>::nodo der = AVec.hijoDrchoB(AVec.raizB());
    
    std::cout << AVec.elemento(izq) << std::endl;
    std::cout << AVec.elemento(der) << std::endl;
    
    /*
     *Abin<int> Propio;
     *Propio.insertarRaizB(0);
     *Propio.insertarHijoIzqdoB(Propio.raizB(), 1);
     *Propio.insertarHijoDrchoB(Propio.raizB(), 2);
     *
     *Abin<int>::nodo unoPropio = Propio.hijoIzqdoB(Propio.raizB());
     *Abin<int>::nodo dosPropio = Propio.hijoDrchoB(Propio.raizB());
     *
     *Propio.insertarHijoIzqdoB(unoPropio, 3);
     *Propio.insertarHijoDrchoB(dosPropio, 4);
     *
     *
     *Abin<int>::nodo tresPropio = Propio.hijoIzqdoB(unoPropio);
     *Abin<int>::nodo cuatroPropio = Propio.hijoDrchoB(dosPropio);
     *
     *Propio.insertarHijoIzqdoB(tresPropio, 5);
     *Propio.insertarHijoDrchoB(cuatroPropio, 6);
     */
    //Propio.insertarHijoIzqdoB(cuatroPropio, 10);
    
    //std::cout << ((arbolesBinSimil(Propio, Prop)) ? "wiii" : ":(") << std::endl;
    
    /*
     *Propio.preordenAbin(Propio.raizB(), Propio);
     *Abin<int> P = arbolReflec(Propio);
     *std::cout << "======================" << std::endl;
     *P.preordenAbin(P.raizB(), P);
     */
    
    /*
     *Abin<int> ArbolAritmetico;
     *ArbolAritmetico.insertarRaizB('x');
     *ArbolAritmetico.insertarHijoIzqdoB(ArbolAritmetico.raizB(), 2);
     *ArbolAritmetico.insertarHijoDrchoB(ArbolAritmetico.raizB(), '*');
     *
     *Abin<int>::nodo suma = ArbolAritmetico.hijoDrchoB(ArbolAritmetico.raizB());
     *
     *ArbolAritmetico.insertarHijoIzqdoB(suma, 10);
     *ArbolAritmetico.insertarHijoDrchoB(suma, 9);
     *
     *double resultado = resArbolAritmetico(ArbolAritmetico);
     *std::cout << "Resultado => " << resultado << std::endl;
     */
    //std::cout << numSucesoresNodo(Propio.raizB(), Propio) << std::endl;
    //std::cout << numNodosNostalgicosArbol(Propio) << std::endl;
    
    return 0;
}
