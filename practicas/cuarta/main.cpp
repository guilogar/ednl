#include "auxiliar.h"

int main(int argc, const char *argv[])
{
    Abb<int> b;
    
    b.insertar(5);
    b.insertar(25);
    b.insertar(1);
    b.insertar(80);
    b.insertar(500);
    b.insertar(3);
    b.insertar(8);
    b.insertar(200);
    
    printAbb(b);
    //b.eliminarSubArbol(25);
    //printAbb(b);
    std::cout << "============================" << std::endl;
    Abin<int> a = (Abin<int>) b;
    printAbin(a.raizB(), a);
    /*
     *std::cout << a.elemento(a.raizB()) << std::endl;
     *std::cout << a.elemento(a.hijoIzqdoB(a.raizB())) << std::endl;
     *std::cout << a.elemento(a.hijoIzqdoB(a.hijoIzqdoB(a.raizB()))) << std::endl;
     *
     *std::cout << a.elemento(a.hijoDrchoB(a.raizB())) << std::endl;
     *std::cout << a.elemento(a.hijoIzqdoB(a.hijoDrchoB(a.raizB()))) << std::endl;
     *std::cout << a.elemento(a.hijoDrchoB(a.hijoDrchoB(a.raizB()))) << std::endl;
     *
     *std::cout << a.elemento(a.hijoIzqdoB(a.hijoDrchoB(a.hijoDrchoB(a.raizB())))) << std::endl;
     *std::cout << a.elemento(a.hijoIzqdoB(a.hijoIzqdoB(a.hijoDrchoB(a.hijoDrchoB(a.raizB()))))) << std::endl;
     */
    /*
     *std::cout << "===================================" << std::endl;
     *printAbb(equilibrarArbol(b));
     */
    return 0;
}
