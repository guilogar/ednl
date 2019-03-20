#include <iostream>
#include <map>
#include "../arboles/abin.h"

using namespace std;

bool evaluarExpresionRecursiva(Abin<char>::nodo n, Abin<char> arbol, map<char, bool> variables);

bool evaluarExpresion(Abin<char> arbol, map<char, bool> variables)
{
    return evaluarExpresionRecursiva(arbol.raizB(), arbol, variables);
}

bool evaluarExpresionRecursiva(Abin<char>::nodo n, Abin<char> arbol, map<char, bool> variables)
{
    if(n == Abin<char>::NODO_NULO) // Esto sucede si es un arbol vacio
    {
        return false;
    } else
    {
        if(arbol.hijoIzqdoB(n) == Abin<char>::NODO_NULO && // Esto sucede si es un nodo hoja
           arbol.hijoDrchoB(n) == Abin<char>::NODO_NULO)
        {
            map<char, bool>::iterator i = variables.find(arbol.elemento(n));
            if(i != variables.end())
            {
                return i->second;
            } else
            {
                return false;
            }
        } else // No es un nodo hoja
        {
            bool i = evaluarExpresionRecursiva(arbol.hijoIzqdoB(n), arbol, variables);
            bool d = evaluarExpresionRecursiva(arbol.hijoDrchoB(n), arbol, variables);
            bool res;
            char op = arbol.elemento(n);
            
            switch (op) {
                case '^':
                    res = i && d;
                    break;
                case '|':
                    res = i || d;
                    break;
                case '!':
                    res = !i;
                    break;
            }
            
            return res;
        }
    }
}

int numNietos(Abin<int>::nodo n, Abin<int> arbol, int numIter)
{
    if(numIter)
    {
        return numNietos(arbol.hijoIzqdoB(n), arbol, --numIter/*0*/) +
               numNietos(arbol.hijoDrchoB(n), arbol, --numIter/*-1*/);
    } else
    {
        if(n == Abin<int>::NODO_NULO)
            return 0;
        else
            return 1;
    }
}

int contarNodoTresNietosRecursiva(Abin<int>::nodo n, Abin<int> arbol)
{
    if(n != Abin<int>::NODO_NULO)
    {
        if(numNietos(n, arbol, 1) == 3)
            return 1 + contarNodoTresNietosRecursiva(arbol.hijoIzqdoB(n), arbol) +
                       contarNodoTresNietosRecursiva(arbol.hijoDrchoB(n), arbol);
        else
            return 0 + contarNodoTresNietosRecursiva(arbol.hijoIzqdoB(n), arbol) +
                       contarNodoTresNietosRecursiva(arbol.hijoDrchoB(n), arbol);
    } else
    {
        return 0;
    }
}

int contarNodoTresNietos(Abin<int> arbol)
{
    return contarNodoTresNietosRecursiva(arbol.raizB(), arbol);
}

int main(int argc, const char *argv[])
{
    // bool resultado = evaluarExpresion(Abin<char>(), map<char, bool>());
    return 0;
}
