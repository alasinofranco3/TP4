#include "Abb.h"
#include "Nodo_abb.h"

Abb::Abb(){
	raiz = new Nodo_abb;
	cout << "Pido Memoria Arbol" << endl;
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
	return raiz == NULL;
}

void Abb::agregar(Nodo_abb* nodo_a_agregar){
	bool fue_agregado = false;

	if(es_vacio()){
		asignar_raiz(nodo_a_agregar);
		fue_agregado = true;
	}

	Nodo_abb* actual = obtener_raiz();
	
	while(!fue_agregado){
		if(nodo_a_agregar -> obtener_telefono() >= actual->obtener_telefono()){
			if(actual->obtener_hijo_der() == NULL){
				actual -> asignar_hijo_der(nodo_a_agregar);
				fue_agregado = true;
			}
			else{
				actual = actual -> obtener_hijo_der();
			}
		}
		else{
			if(actual->obtener_hijo_izq() == NULL){
				actual->asignar_hijo_izq(nodo_a_agregar);
				fue_agregado = true;
			}
			else{
				actual = actual -> obtener_hijo_izq();
			}
		}
	}
}

Abb::~Abb(){

	delete raiz;
	delete altura;
	cout << "Borro raiz y altura";
}