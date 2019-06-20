#include "Cliente.h"

Cliente::Cliente(bool nueva_alta, int nuevo_legajo){
	alta = nueva_alta;
	legajo = nuevo_legajo;
}

bool obtener_alta(){
	return alta;
}

int obtener_legajo(){
	return legajo;
}

void asignar_alta(bool nueva_alta){
	alta = nueva_alta;
}

void asigna_legajo(int nuevo_legajo){
	legajo = nuevo_legajo;
}