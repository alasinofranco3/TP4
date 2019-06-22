#include "Individuo.h"

Individuo::Individuo(string* nuevo_nombre,bool nueva_alta,int nuevo_legajo) : Cliente(nueva_alta,nuevo_legajo){
	nombre = new string;
	cout << "Pido Memoria Individuo" << endl;
	nombre = nuevo_nombre;
}

string Individuo::obtener_individuo(){
	return *nombre;
}

void Individuo::asignar_individuo(string* nuevo_nombre){
	nombre = nuevo_nombre;
}

Individuo::~Individuo(){
	delete nombre;
	cout << "Borro Individuo" << endl;
}