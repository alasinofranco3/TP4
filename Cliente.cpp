#include "Cliente.h"

Cliente::Cliente(){
	
}

Cliente::Cliente(bool nueva_alta, int nuevo_legajo, int nuevo_precio_base, char nuevo_tipo){
	legajo = new int;
	cout << "Pido Memoria cliente" << endl;
	alta = nueva_alta;
	*legajo = nuevo_legajo;
	precio_base = nuevo_precio_base;
	tipo = nuevo_tipo;
}

bool Cliente::obtener_alta(){
	return alta;
}

int Cliente::obtener_legajo(){
	return *legajo;
}

int Cliente::obtener_precio_base(){
	return precio_base;
}

char Cliente::obtener_tipo(){
	return tipo;
}

void Cliente::asignar_alta(bool nueva_alta){
	alta = nueva_alta;
}

void Cliente::asignar_legajo(int nuevo_legajo){
	*legajo = nuevo_legajo;
}

Cliente::~Cliente(){
	delete legajo;
	cout << "Borro legajo" << endl;
}