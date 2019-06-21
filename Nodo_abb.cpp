#include "Nodo_abb.h"

Nodo_abb::Nodo_abb(){
	 hijo_izq = 0;
	 hijo_der = 0;
	 telefono = 000000000;
	 cliente = 0; /// dudoso
}

Nodo_abb::Nodo_abb(Nodo_abb* nuevo_hijo_izq,Nodo_abb* nuevo_hijo_der,int nuevo_telefono,Cliente* nuevo_cliente){
	hijo_izq = nuevo_hijo_izq;
	hijo_der = nuevo_hijo_der;
	telefono = nuevo_telefono;
	cliente = nuevo_cliente;
}

Nodo_abb* Nodo_abb::obtener_hijo_der(){
	return hijo_der;
}

Nodo_abb* Nodo_abb::obtener_hijo_izq(){
	return hijo_izq;
}

int Nodo_abb::obtener_telefono(){
	return telefono;
}

Cliente* Nodo_abb::obtener_cliente(){
	return cliente;
}

void Nodo_abb::asignar_hijo_der(Nodo_abb* nuevo_hijo_der){
	hijo_der = nuevo_hijo_der;
}

void Nodo_abb::asignar_hijo_izq(Nodo_abb* nuevo_hijo_izq){
	hijo_izq = nuevo_hijo_izq;
}

void Nodo_abb::asignar_telefono(int nuevo_telefono){
	telefono = nuevo_telefono;
}

void Nodo_abb::asignar_cliente(Cliente* nuevo_cliente){
	cliente = nuevo_cliente;
}

