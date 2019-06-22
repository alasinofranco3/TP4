#include "Abb.h"
#include "Nodo_abb.h"

Abb::Abb(){
	raiz = new Nodo_abb;
	raiz = NULL;
	altura = 0;
}

Abb::Abb(Nodo_abb* nueva_raiz,int nueva_altura){
	raiz = new Nodo_abb;
	altura = new int;
	raiz = nueva_raiz;
	*altura = nueva_altura;
}

Nodo_abb* Abb::obtener_raiz(){
	return raiz;
}

int Abb::obtener_altura(){
	return *altura;
}

void Abb::asignar_raiz(Nodo_abb* nueva_raiz){
	raiz = nueva_raiz;
}

bool Abb::es_vacio(){
	if(raiz == NULL) return true;
	return false;
}

void Abb::agregar(Nodo_abb* nodo_a_agregar){
	if(es_vacio()){
		raiz = nodo_a_agregar;
	}

	Nodo_abb* actual = raiz;
	bool fue_agregado = false;

	while(!fue_agregado){
		if(nodo_a_agregar->telefono >= actual->telefono){
			if(actual->hijo_der == NULL){
				actual->hijo_der = nodo_a_agregar;
				fue_agregado = true;
			}
			else{
				actual = actual->hijo_der;
			}
		}
		else{
			if(actual->hijo_izq == NULL){
				actual->hijo_izq = nodo_a_agregar;
				fue_agregado = true;
			}
			else{
				actual = actual->hijo_izq;
			}
		}
	}
}

Abb::~Abb(){
	delete raiz;
	delete altura;
}