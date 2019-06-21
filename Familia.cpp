#include "Familia.h"

Familia::Familia(Lista nueva_familiares,bool nueva_alta,int nuevo_telefono) : Cliente(nueva_alta,nuevo_telefono){
	familiares = nueva_familiares;
}

Familia::mostrar_familia(){
	//familiares.a_texto();
}

Familia::asignar_familia(Lista nueva_familiares){
	familiares = nueva_familiares;
}