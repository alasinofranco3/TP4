#include "Cliente.h"

Cliente::Cliente(bool nueva_alta, int nuevo_legajo){
	alta = nueva_alta;
	legajo = nuevo_legajo;
}

bool Cliente::obtener_alta(){
	return alta;
}

int Cliente::obtener_legajo(){
	return legajo;
}

void Cliente::asignar_alta(bool nueva_alta){
	alta = nueva_alta;
}

void Cliente::asignar_legajo(int nuevo_legajo){
	legajo = nuevo_legajo;
}