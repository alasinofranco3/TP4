#ifndef NODO_ABB_H
#define NODO_ABB_H

#include <iostream>
#include "Cliente.h"

class Nodo_abb{
	private:
		Nodo_abb* hijo_izq;
		Nodo_abb* hijo_der;
		int telefono;
		Cliente* cliente;
	public:
		//Descripcion:Constructor sin parametros
		//Pre:---
		//Post:Crea un objeto Nodo
		Nodo_abb();
		
		//Descripcion:Constructor con parametros
		//Pre:---
		//Post:Crea un objeto Nodo
		Nodo_abb(Nodo_abb* nuevo_hijo_izq,Nodo_abb* nuevo_hijo_der,int nuevo_telefono,Cliente* nuevo_cliente);
		
		//Pre:El objeto debe existir
		//Post:Devuelve el nodo del hijo derecho
		Nodo_abb* obtener_hijo_der();
		
		//Pre:El objeto debe existir
		//Post:Devuelve el valornodo del hijo izquierdo
		Nodo_abb* obtener_hijo_izq();
		
		//Pre:El objeto debe existir
		//Post:Devuelve el numero de telefono
		int obtener_telefono();
		
		//Pre:El objeto debe existir
		//Post:Devuelve el objeto cliente
		Cliente* obtener_cliente();
		
		//Pre:El objeto debe existir
		//Post:Se modifico el nodo del hijo derecho
		void asignar_hijo_der(Nodo_abb* nuevo_hijo_der);
		
		//Pre:El objeto debe existir
		//Post:Se modifico el nodo del hijo izquierdo
		void asignar_hijo_izq(Nodo_abb* nuevo_hijo_izq);
		
		//Pre:El objeto debe existir
		//Post:Se modifico el numero de telefono
		void asignar_telefono(int nuevo_telefono);
		
		//Pre:El objeto debe existir
		//Post:Se modifico el objeto cliente
		void asignar_cliente(Cliente* nuevo_cliente);

};

#endif // NODO_ABB_H