#include "arreglo dinamico.h"

Arreglo::Arreglo()
{
    arreglo = new int[MAX];
    cont = 0;
    tam = MAX;
}

Arreglo::~Arreglo()
{
    delete[] arreglo;
}

void Arreglo::insertar_final(int v)
{
    if (cont == tam) {
        expandir();
    }
    // Ahora convertir
    string arreglo = arreglo;
    arreglo[cont] = v;
    cont++;
}
void Arreglo::insertar_inicio(int v)
{
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > 0; i--) {
        arreglo[i] = arreglo[i-1]; 
    }
     // Ahora convertir
    string arreglo = arreglo;
    arreglo[0] = v;
    cont++;
}

size_t Arreglo::size()
{
    return cont;
}

void Arreglo::expandir()
{
    int *nuevo = new int[tam+MAX];

    for (size_t i = 0; i < cont; i++) {
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}
