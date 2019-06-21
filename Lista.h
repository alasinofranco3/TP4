#ifndef LISTA_H
#define LISTA_H

#include "Nodo_lista.h"
template <typename Dato>
class Lista{
private:
	Nodo<Dato>* primero;
	int tamanio;

	//Pre:Debe existir un nodo en la posicion pasada por parametro
	//Post:Cambia el nodo pasado por parametro por el nodo de la posicion pasada por parametro
	void cambiar_nodo(Nodo<Dato>* nodo,int pos);
	//Pre:Debe existir el nodo en esa posicion
	//Post:Se va a retirar el nodo de esa posicion
	Nodo<Dato>* retirar(int pos);
public:
	//Descripcion:Constructor
	//Pre:---
	//Post:Se crea el objeto Lista
	Lista();
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de tamanio
	int obtener_tamanio();
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:Se agrego el objeto d a la lista en la posicion pos
	
	void agregar(Dato* d, int pos);
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:Se eleimino de la lista el objeto en la posicion pos
	void eliminar(int pos);
	
	//Pre:El objeto debe existir
	//Post:Devuelve true si la lista esta vacia y false en caso contrario
	bool es_vacia();
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:Devuelve el elemento de la lista en esa posicion.
	//template <typename Dato>
	Dato* consultar(int pos);
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:devuelve el nodo enn la posicion pos de la lista
	Nodo<Dato>* obtener_nodo(int pos);
	
	//Pre:El objeto debe existir,pos1 y pos 2 deben ser mayores a cero y menores o iguales a tamanio
	//Post:intercambio los nodos en  pos1 y pos 2
	void swap(int pos1, int pos2);
	
	//Pre:El objeto debe existir
	//Post:La lista se encuentra ordenada por numero de legajo de los trabajadores
	void ordenar();
	
	//Pre:El objeto debe existir
	//Post:Devuelve verdadero si el dato esta en la lista o falso en caso contrario
	bool esta(Dato* dato_a_buscar);

	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:EL objeto es destruido
	~Lista();


};
template <typename Dato>
Lista<Dato>::Lista(){
	primero = NULL;
	tamanio = 0;
}

template <typename Dato>
int Lista<Dato>::obtener_tamanio(){
	return tamanio;
}

template <typename Dato>
bool Lista<Dato>::es_vacia(){
	return !tamanio;
}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos){
	Nodo<Dato>* aux = primero;
	for(int i = 1; i<pos ; i++)
		aux = aux->obtener_siguiente();
	return aux;
}

template <typename Dato>
void Lista<Dato>::agregar(Dato* d, int pos){
	Nodo<Dato>* nuevo = new Nodo<Dato>(d);
	
	if(es_vacia())
		primero = nuevo;
	else if(pos == 1){
		nuevo->asignar_siguiente(primero);
		primero = nuevo;
	}
	else{
		Nodo<Dato>* aux = obtener_nodo(pos-1);
		nuevo->asignar_siguiente(aux->obtener_siguiente());
		aux->asignar_siguiente(nuevo);
	}
	tamanio ++;
}

template <typename Dato>
void Lista<Dato>::eliminar(int pos){
	Nodo<Dato>* aux;
	if(pos == 1){
		aux = primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo<Dato>* anterior = obtener_nodo(pos-1);
		aux = anterior->obtener_siguiente();
		anterior->asignar_siguiente(aux->obtener_siguiente());
	}
	tamanio--;
	delete aux;
}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::retirar(int pos){
	Nodo<Dato>* aux;
	if(pos == 1){
		aux = primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo<Dato>* anterior = obtener_nodo(pos-1);
		aux = anterior->obtener_siguiente();
		anterior->asignar_siguiente(aux->obtener_siguiente());
	}
	tamanio--;
	return aux;
}

template <typename Dato>
void Lista<Dato>::cambiar_nodo(Nodo<Dato>* nodo,int pos){
	if(es_vacia())
		primero = nodo;
	else if(pos == 1){
		nodo->asignar_siguiente(primero);
		primero = nodo;
	}
	else{
		Nodo<Dato>* aux = obtener_nodo(pos-1);
		nodo->asignar_siguiente(aux->obtener_siguiente());
		aux->asignar_siguiente(nodo);
	}
	tamanio ++;
}

template <typename Dato>
Dato* Lista<Dato>::consultar(int pos){
	Nodo<Dato>* aux = obtener_nodo(pos);
	return aux->obtener_elemento();
}

//Suponiendo que pos1<pos2
template <typename Dato>
void Lista<Dato>::swap(int pos1, int pos2){
	if((pos1 < obtener_tamanio())&&(pos2 <= obtener_tamanio() )){
	Nodo<Dato>* aux = retirar(pos1);
	Nodo<Dato>* aux2 = retirar(pos2-1);
	cambiar_nodo(aux2,pos1);
	cambiar_nodo(aux,pos2);
	}
}

template <typename Dato>
bool Lista<Dato>::esta(Dato* dato_a_buscar){
	for(int i = 1;i <= tamanio;i++){
		if(consultar(i) == dato_a_buscar){
			return true;
		}
	}
	return false;
}

template <typename Dato>
Lista<Dato>::~Lista(){
	while(!es_vacia())
		eliminar(1);
}

#endif