#include <iostream>
#include<cstring>
#include "arreglo dinamico.h"
using namespace std;

void modificar(int *a)
{
    *a = *a + 1;
}

int main() 
{
    Arreglo arreglo;
    arreglo.insertar_final(10);
    arreglo.insertar_final(0);
    arreglo.insertar_final(1);
    arreglo.insertar_final(4);
    arreglo.insertar_inicio(-10);

    for (size_t i = 0; i < arreglo.size(); i++)
    {
		cout << arreglo[i] << " ";
    }
    return 0;
}
