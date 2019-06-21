#include "Abb.h"
#include "Nodo_abb.h"

Abb::Abb(){
	raiz = NULL;
	altura = 0;
}

Abb::Abb(Nodo_abb* nueva_raiz,int nueva_altura){
	raiz = nueva_raiz;
	altura = nueva_altura;
}

Nodo_abb* Abb::obtener_raiz(){
	return raiz;
}

int Abb::obtener_altura(){
	return altura;
}

void Abb::asignar_raiz(Nodo_abb* nueva_raiz){
	raiz = nueva_raiz;
}

Abb::~Abb(){
	delete raiz;
}