#include "Familia.h"

Familia::Familia(Lista<string>* nueva_familiares,bool nueva_alta,string nuevo_legajo, int nuevo_precio_base, char nuevo_tipo) : Cliente(nueva_alta,nuevo_legajo, nuevo_precio_base, nuevo_tipo){
	familiares = new Lista<string>;
	familiares = nueva_familiares;
}

void Familia::asignar_familia(Lista<string>* nueva_familiares){
	familiares = nueva_familiares;
}

int Familia::obtener_tamanio_cliente(){
	return familiares -> obtener_tamanio();
}

void Familia::mostrar_cliente(){
	for(int i=1;i<=familiares->obtener_tamanio();i++){

		cout << "Miembro " << i << ":" << *(familiares -> obtener_nodo(i) -> obtener_elemento()) << endl;
	}
}

Familia::~Familia(){
	delete familiares;
}