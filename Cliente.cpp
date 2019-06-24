#include "Cliente.h"

Cliente::Cliente(){
	legajo = new string;
	alta = true;
	//legajo = "";
	precio_base = 0;
	tipo = 'N';
}

Cliente::Cliente(bool nueva_alta, string nuevo_legajo, int nuevo_precio_base, char nuevo_tipo){
	legajo = new string;
	cout << "Pido Memoria cliente" << endl;
	alta = nueva_alta;
	*legajo = nuevo_legajo;
	precio_base = nuevo_precio_base;
	tipo = nuevo_tipo;
}

bool Cliente::obtener_alta(){
	return alta;
}

string Cliente::obtener_legajo(){
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

void Cliente::asignar_legajo(string nuevo_legajo){
	*legajo = nuevo_legajo;
}

int Cliente::obtener_tamanio_cliente(){
	return 0;
}

void Cliente::mostrar_cliente(){}

Cliente::~Cliente(){
	delete legajo;
	cout << "Borro legajo" << endl;
}