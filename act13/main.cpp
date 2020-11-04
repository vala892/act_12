#include <iostream>
#include "arreglo.h"
using namespace std;

int main()
{
	Arreglo<float> arreglo;
	
    for (size_t i = 0; i < 10; i++) {
    	arreglo.insertar(100, 2);
    	arreglo.eliminar_inicio();
    	arreglo.eliminar_final();
    	arreglo.eliminar(4);
    	arreglo.buscar(4);
    	arreglo.buscar_todos(5);
    	for (size_t i = 0; i < arreglo.size(); i++) {
    		cout << arreglo[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
