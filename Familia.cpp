#include "Familia.h"

Familia::Familia(Lista<Cliente> nueva_familiares,bool nueva_alta,int nuevo_telefono) : Cliente(nueva_alta,nuevo_telefono){
	familiares = new Lista<Cliente>;
	*familiares = nueva_familiares;
}

void Familia::mostrar_familia(){
	//familiares.a_texto();
}

void Familia::asignar_familia(Lista<Cliente> nueva_familiares){
	*familiares = nueva_familiares;
}