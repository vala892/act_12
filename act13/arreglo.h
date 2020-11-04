#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

template <class T>
class Arreglo
{
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 1000;

public:
    Arreglo();
    ~Arreglo();
    void insertar_final(const T& v);
    void insertar_inicio(const T& v);
    void insertar(const T& v, size_t p);

    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);

    T* buscar(const T& v);
    Arreglo<T*> buscar_todos(const T& v);

    size_t size();
    T operator[](size_t p)
    {
        return arreglo[p];
    }

    friend Arreglo<T>& operator<<(Arreglo<T> &a, const T& v)
    {
        a.insertar_final(v);

        return a;
    }

private:
    void expandir();
};

template <class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
Arreglo<T>::~Arreglo()
{
    delete[] arreglo;
}

template <class T>
void Arreglo<T>::insertar_final(const T& v)
{
    if (cont == tam) {
        expandir();
    }
    arreglo[cont] = v;
    cont++;
}

template <class T>
void Arreglo<T>::insertar_inicio(const T& v)
{
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > 0; i--) {
        arreglo[i] = arreglo[i-1]; 
    }
    arreglo[0] = v;
    cont++;
}

template <class T>
void Arreglo<T>::insertar(const T& v, size_t p)
{
    if (p >= cont) {
        cout << "Posición no válida" << endl;
        return;
    }
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > p; i-- ) {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = v;
    cont++;
}

template <class T>
void Arreglo<T>::eliminar_final()
{
    if (cont == 0) {
        cout << "Arreglo vacío" << endl;
        return;
    }
    cont--;
}
template <class T>
void Arreglo<T>::eliminar_inicio()
{
    if (cont == 0) {
        cout << "Arreglo vacío" << endl;
        return;
    }
    for (size_t i = 0; i < cont-1; i++) {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}
template <class T>
void Arreglo<T>::eliminar(size_t p)
{
    if (cont == 0) {
        cout << "Arreglo vacío" << endl;
        return;
    }
    for (size_t i = p; i < cont - 1; i++) {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
T* Arreglo<T>::buscar(const T& v)
{
    for (size_t i = 0; i < cont; i++) {
        if (v == arreglo[i]) {
            return &arreglo[i];
        }
    }
    return null;
}

template <class T>
size_t Arreglo<T>::size()
{
    return cont;
}
template <class T>
void Arreglo<T>::expandir()
{
    T *nuevo = new T[tam+MAX];

    for (size_t i = 0; i < cont; i++) {
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif
