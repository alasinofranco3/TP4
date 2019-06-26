#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;
const float descuento_familia =  0.65;
const float descuento_individuo = 0.9;

class Cliente{

private:
	bool alta;
	string* legajo;
	int* precio_base;
	char tipo;

public:
	Cliente();
 	//Descripcion:Constructor con parametros
	//Pre:---
	//Post:Crea un objeto cliente
 	Cliente(bool nueva_alta, string nuevo_legajo, int nuevo_precio_base, char nuevo_tipo);

 	//Pre:El objeto debe existir
	//Post:Devuelve si esta de alta o no
 	bool obtener_alta();

 	//Pre:El objeto debe existir
	//Post:Devuelve el numero de legajo
	string obtener_legajo();

	//Pre:El objeto debe existir
	//Post:Devuelve el precio base
	int obtener_precio();

	//Pre:El objeto debe existir
	//Post:Devuelve el tipo cliente siendo F familia e I individuo
	char obtener_tipo();

	//Pre:El objeto debe existir
	//Post:Se modifica el estado de alta
	void asignar_alta(bool nueva_alta);

	//Pre:El objeto debe existir
	//Post:Se modifica el numero de legajo
	void asignar_legajo(string nuevo_legajo);

    //Pre: El objeto debe existir
    //Post: Devuelve el precio base del cliente
	int obtener_precio_base();

    //Pre: El objeto debe existir
    //Post: Devuelve el tamanio del cliente que representa la cantidad de miembros
	virtual int obtener_tamanio_cliente();

    //Pre: El objeto debe existir
    //Post: Devuelve los nombres/nombre del cliente
	virtual void mostrar_cliente();

	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:El objeto es destruido
	virtual ~Cliente();

};

#endif // CLIENTE_H
