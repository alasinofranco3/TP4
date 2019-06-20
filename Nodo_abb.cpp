#include "Nodo_abb"

Nodo_abb::Nodo_abb(){
	 hijo_izq = NULL;
	 hijo_der = NULL;
	 telefono = 000000000;
	 cliente = NULL; /// dudoso
}

Nodo_abb::Nodo_abb(Nodo_abb* nuevo_hijo_izq,Nodo_abb* nuevo_hijo_der,int nuevo_telefono,Cliente* nuevo_cliente){
	hijo_izq = nuevo_hijo_izq;
	hijo_der = nuevo_hijo_der;
	telefono = nuevo_telefono;
	cliente = nuevo_cliente;
}

Nodo_abb* obtener_hijo_der(){
	return hijo_der;
}

Nodo_abb* obtener_hijo_izq(){
	return hijo_izq;
}

int obtener_telefono(){
	return telefono;
}

Cliente* obtener_cliente(){
	return cliente;
}

void asignar_hijo_der(Nodo_abb* nuevo_hijo_der){
	hijo_der = nuevo_hijo_der;
}

void asignar_hijo_izq(Nodo_abb* nuevo_hijo_izq){
	hijo_izq = nuevo_hijo_izq;
}

void asignar_telefono(int nuevo_telefono){
	telefono = nuevo_telefono;
}

void asignar_cliente(Cliente* nuevo_cliente){
	cliente = nuevo_cliente;
}