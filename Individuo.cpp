#include "Individuo.h"

Individuo::Individuo(string nuevo_nombre,int nuevo_telefono,bool nueva_alta) : Cliente(nueva_alta,nuevo_telefono){
	nombre = nuevo_nombre;
}

string Individuo::obtener_individuo(){
	return nombre;
}

void Individuo::asignar_individuo(string nuevo_nombre){
	nombre = nuevo_nombre;
}