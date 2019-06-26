#include "Abb.h"
#include "Nodo_abb.h"

Abb::Abb(){
	//raiz = new Nodo_abb();
	//cout << "Pido memoria para la raiz (constructor vacio) en: " << raiz << endl;
	raiz = NULL;
}

Abb::Abb(Nodo_abb* nueva_raiz){
	raiz = new Nodo_abb;
	cout << "Pido memoria para la raiz (constructor con nodo_abb*) en: " << raiz << endl;
	raiz = nueva_raiz;
}

Nodo_abb* Abb::obtener_raiz(){
	return raiz;
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

void Abb::borrar(Nodo_abb* nodo){
	if(!nodo) return;
	borrar(nodo -> obtener_hijo_izq());
	borrar(nodo -> obtener_hijo_der());
	delete nodo;

}

Abb::~Abb(){
	cout << "Uso borrar() que borra todos los nodos, raiz del ppal " << raiz << endl; 
	borrar(raiz);
	//delete raiz;
}