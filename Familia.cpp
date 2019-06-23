#include "Familia.h"

Familia::Familia(Lista<string>* nueva_familiares,bool nueva_alta,int nuevo_legajo) : Cliente(nueva_alta,nuevo_legajo){
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

Familia::~Familia(){
	delete familiares;
	cout << "Borro Familiares" << endl;
}