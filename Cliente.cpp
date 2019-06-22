#include "Cliente.h"

Cliente::Cliente(){
	
}

Cliente::Cliente(bool nueva_alta, int nuevo_legajo){
	legajo = new int;
	cout << "Pido Memoria cliente" << endl;
	alta = nueva_alta;
	*legajo = nuevo_legajo;
}

bool Cliente::obtener_alta(){
	return alta;
}

int Cliente::obtener_legajo(){
	return *legajo;
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