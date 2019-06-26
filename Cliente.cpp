#include "Cliente.h"

Cliente::Cliente(){
	legajo = new string;
	alta = true;
	precio_base = 0;
	tipo = 'n';
}

Cliente::Cliente(bool nueva_alta, string nuevo_legajo, int nuevo_precio_base, char nuevo_tipo){
	legajo = new string(nuevo_legajo);
	precio_base = new int(nuevo_precio_base);
	alta = nueva_alta;
	tipo = nuevo_tipo;
}

bool Cliente::obtener_alta(){
	return alta;
}

string Cliente::obtener_legajo(){
	return *legajo;
}

int Cliente::obtener_precio_base(){
	return *precio_base;
}

char Cliente::obtener_tipo(){
	return tipo;
}

void Cliente::asignar_alta(bool nueva_alta){
	alta = nueva_alta;
}

void Cliente::asignar_legajo(string nuevo_legajo){
	*legajo = nuevo_legajo;
}

int Cliente::obtener_tamanio_cliente(){
	return 0;
}

void Cliente::mostrar_cliente(){}

Cliente::~Cliente(){
	delete legajo;
	delete precio_base;
}