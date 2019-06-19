#ifndef NODO_LISTA_H
#define NODO_LISTA_H

#include <iostream>

using namespace std;

//template <class Dato>
template <typename Dato>
class Nodo_lista{

private:
	Dato* elemento;
	Nodo_lista* psig;
public:
	//Descripcion:Constructor con un parametro
	//Pre:---
	//Post:El objeto es creado con los el valor d para elemento y le asigna a psig el valor por defecto
	
	Nodo_lista(Dato* d);
	//Descripcion:Constructor con parametros
	//Pre:---
	//Post:Crea un objeto Nodo_lista
	Nodo_lista(Dato* d, Nodo_lista* psig);
	
	//Pre:El objeto debe existir
	//Post:Se modifico el valor de elemento
	void asignar_elemento(Dato* d);
	
	//Pre:El objeto debe existir
	//Post:Se modifico el valor de psig
	void asignar_siguiente(Nodo_lista* psig);
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de elemento
	Dato* obtener_elemento();
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de siguiente
	Nodo_lista* obtener_siguiente();
	
	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:El objeto es destruido
	~Nodo_lista();

};

template <typename Dato>
Nodo_lista<Dato>::Nodo_lista(Dato* d){
	elemento = d;
	psig=NULL;
}

template <typename Dato>
Nodo_lista<Dato>::Nodo_lista(Dato* d, Nodo_lista* sig){
	elemento = d;
	psig = sig;
}

template <typename Dato>
void Nodo_lista<Dato>::asignar_elemento(Dato* d){
	elemento = d;
}

template <typename Dato>
void Nodo_lista<Dato>::asignar_siguiente(Nodo_lista* sig){
	psig = sig;
}

template <typename Dato>
Dato* Nodo_lista<Dato>::obtener_elemento(){
	return elemento;
}

template <typename Dato>
Nodo_lista<Dato>* Nodo_lista<Dato>::obtener_siguiente(){
	return psig;
}
template <typename Dato>
Nodo_lista<Dato>::~Nodo_lista(){
	delete elemento;
	
}
#endif