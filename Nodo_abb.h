#ifndef NODO_ABB_H
#define NODO_ABB_H

#include <iostream>

using namespace std;

class Nodo_abb{

private:
	Nodo_abb* hijo_izq;
	Nodo_abb* hijo_der;
	int telefono;
	Cliente* cliente;
public:
	//Descripcion
	//Pre:
	//Post:
	Nodo_abb();
	
	//Pre:
	//Post:
	Nodo_abb(Nodo_abb* nuevo_hijo_izq,Nodo_abb* nuevo_hijo_der,int nuevo_telefono,Cliente* nuevo_cliente);
	
	//Pre:
	//Post:
	Nodo_abb* obtener_hijo_der();
	
	//Pre:
	//Post:
	Nodo_abb* obtener_hijo_izq();
	
	//Pre:
	//Post:
	int obtener_telefono();
	
	//Pre:
	//Post:
	Cliente* obtener_cliente();
	
	//Pre:
	//Post:
	void asignar_hijo_der(Nodo_abb* nuevo_hijo_der);
	
	//Pre:
	//Post:
	void asignar_hijo_izq(Nodo_abb* nuevo_hijo_izq);
	
	//Pre:
	//Post:
	void asignar_telefono(int nuevo_telefono);
	
	//Pre:
	//Post:
	void asignar_cliente(Cliente* nuevo_cliente);

};