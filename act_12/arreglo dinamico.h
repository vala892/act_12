#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include<cstring>
using namespace std;

class Arreglo
{
    int *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 5;

public:
    Arreglo();
    ~Arreglo();
    void insertar_final(int v);
    void insertar_inicio(int v);
    size_t size();
    int operator[](size_t p)
    {
        return arreglo[p];
    }
    
private:
    void expandir();
};

#endif
