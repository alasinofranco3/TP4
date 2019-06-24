#include "Familia.h"

Familia::Familia(Lista<string>* nueva_familiares,bool nueva_alta,string nuevo_legajo, int nuevo_precio_base, char nuevo_tipo) : Cliente(nueva_alta,nuevo_legajo, nuevo_precio_base, nuevo_tipo){
	familiares = new Lista<string>;
	cout << "Pido Memoria Lista Familia" << endl;
	familiares = nueva_familiares;
}

void Familia::mostrar_familia(){
	//familiares.a_texto();
}

void Familia::asignar_familia(Lista<string>* nueva_familiares){
	familiares = nueva_familiares;
}

int Familia::obtener_tamanio_cliente(){
	return familiares -> obtener_tamanio();
}

Familia::~Familia(){
	delete familiares;
	cout << "Borro Familiares" << endl;
}