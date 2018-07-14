#ifndef COLA_ENLA_H
#define COLA_ENLA_H
#include <cassert>

template <typename T>
class Cola {
    public:
        Cola(); // constructor
        Cola(const Cola<T>& c); // ctor. de copia
        Cola<T>& operator =(const Cola<T>& c); // asignación
        bool vacia() const;
        const T& tope() const;
        void pop();
        void push(const T& x);
        ~Cola(); // destructor
    private:
        struct nodo {
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* c = 0): elto(e), sig(c) {}
        };
        nodo* tope_;
        nodo* begin_;
        void copiar(const Cola<T>& c);
};

template <typename T>
inline Cola<T>::Cola() : tope_(0), begin_(0) { }

template <typename T>
Cola<T>::Cola(const Cola<T>& c) : tope_(0), begin_(0)
{
    copiar(c);
}

template <typename T>
Cola<T>& Cola<T>::operator =(const Cola<T>& c)
{
    if (this != &c) { // evitar autoasignación
        this->~Cola(); // vaciar la Cola actual
        copiar(c);
    }
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{ return (!begin_); }

template <typename T>
inline const T& Cola<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    nodo* c = begin_;
    begin_ = begin_->sig;
    delete c;
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    if(begin_ == 0) {
        begin_ = tope_= new nodo(x, 0);
    } else {
        tope_->sig = new nodo(x, 0);
        tope_ = tope_->sig;
    }
}

// Destructor: vacía la Cola
template <typename T>
Cola<T>::~Cola()
{
    nodo* c;
    while (tope_) {
        c = tope_->sig;
        delete tope_;
        tope_ = c;
    }
}

// Hay que arreglar el copiar para cola normal.
// Método privado
template <typename T>
void Cola<T>::copiar(const Cola<T>& c)
{
    if (!c.vacia()) {
        begin_ = new nodo(c.begin_->elto); // copiar el primer elto
        
        // Copiar el resto de elementos hasta el fondo de la Cola.
        nodo* p = begin_; // recorre la Cola destino
        nodo* q = c.begin_->sig; // 2º nodo, recorre la Cola origen
        while (q) {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}
#endif // COLA_ENLA_H
