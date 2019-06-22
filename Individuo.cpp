#include "Individuo.h"

Individuo::Individuo(string nuevo_nombre,bool nueva_alta,int nuevo_telefono) : Cliente(nueva_alta,nuevo_telefono){
	nombre = new string;
	*nombre = nuevo_nombre;
}

string Individuo::obtener_individuo(){
	return *nombre;
}

void Individuo::asignar_individuo(string nuevo_nombre){
	*nombre = nuevo_nombre;
}