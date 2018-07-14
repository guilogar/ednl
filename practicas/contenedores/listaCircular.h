#ifndef ListaCircular_H
#define ListaCircular_H

#define POS_NULA 0
#include <cassert>

template <typename T> class ListaCircular {
    struct nodo; // declaración adelantada privada
    public:
        typedef nodo* posicion; // posición de un elemento
        ListaCircular(); // constructor, requiere ctor. T()
        ListaCircular(const ListaCircular<T>& l); // ctor. de copia, requiere ctor. T()
        ListaCircular<T>& operator =(const ListaCircular<T>& l); // asignación entre ListaCirculars
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura<Paste>
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion inipos() const;
        posicion fin() const; // posición después del último
        ~ListaCircular(); // destructor
    private:
        struct nodo {
            T elto;
            nodo *ant, *sig;
            nodo(const T& e, nodo* a = 0, nodo* s = 0) : elto(e), ant(a), sig(s) {}
        };
        nodo* L; // ListaCircular doblemente enlazada de nodos
        void copiar(const ListaCircular<T>& l);
};

// Método privado
template <typename T>
void ListaCircular<T>::copiar(const ListaCircular<T> &l)
{
     L = new nodo(T()); // crear el nodo cabecera
     L->ant = L->sig = L; // estructura circular
     
     // Copiar elementos de l
     for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T>
inline ListaCircular<T>::ListaCircular() : L(new nodo(T())) // crear cabecera
{
    L->ant = L->sig = L; // estructura circular
}

template <typename T>
inline ListaCircular<T>::ListaCircular(const ListaCircular<T>& l)
{ copiar(l); }

template <typename T>
ListaCircular<T>& ListaCircular<T>::operator =(const ListaCircular<T>& l)
{
    if (this != &l) { // evitar autoasignación
        this->~ListaCircular(); // vaciar la ListaCircular actual
        copiar(l);
    }
    return *this;
}
template <typename T> inline
void ListaCircular<T>::insertar(const T& x, ListaCircular<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    // el nuevo nodo con x queda en la posición p
}

template <typename T>
inline void ListaCircular<T>::eliminar(ListaCircular<T>::posicion p)
{
    assert(p->sig != L); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;
    delete q;
    // el nodo siguiente queda en la posición p
}

template <typename T> inline
typename ListaCircular<T>::posicion
ListaCircular<T>::siguiente(ListaCircular<T>::posicion p) const
{
    //assert(p->sig != L); // p no es fin
    if(p->sig == L->ant) {
        return L;
    } else {
        return p->sig;
    }
    //return p->sig;
}

template <typename T> inline
typename ListaCircular<T>::posicion
ListaCircular<T>::anterior(ListaCircular<T>::posicion p) const
{
    //assert(p != L); // p no es la primera posición
    if(p == L) {
        return p->ant->ant;
    } else {
        return p->ant;
    }
}

template <typename T> inline
const T& ListaCircular<T>::elemento(ListaCircular<T>::posicion p) const
{
    //assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T>
inline T& ListaCircular<T>::elemento(ListaCircular<T>::posicion p)
{
    //assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T>
typename ListaCircular<T>::posicion
ListaCircular<T>::buscar(const T& x) const
{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
            return q;
}

template <typename T>
inline typename ListaCircular<T>::posicion ListaCircular<T>::primera() const
{
    return L;
}

template <typename T>
inline typename ListaCircular<T>::posicion ListaCircular<T>::inipos() const
{
    if(L != 0)
        return L;
    else
        return POS_NULA;
}

template <typename T>
inline typename ListaCircular<T>::posicion ListaCircular<T>::fin() const
{
    return L->ant;
}

// Destructor: Vacía la ListaCircular y destruye el nodo cabecera
template <typename T>
ListaCircular<T>::~ListaCircular()
{
    if(L != 0)
    {
        nodo* q;
        while (L->sig != L)
        {
            q = L->sig;
            L->sig = q->sig;
            delete q;
        }
        
        delete L;
        L = 0;
    }
}
#endif // ListaCircular_H










