#ifndef FAMILIA_H
#define FAMILIA_H

#include <iostream>
#include "Cliente.h"
#include "Lista.h"

using namespace std;

class Familia : public Cliente{
	private:
		Lista<string>* familiares;
	public:
		//Descripcion:Constructor con parametros
		//Pre:---
		//Post:Crea un objeto familia
		Familia(Lista<string>* nueva_familiares,bool nueva_alta,string nuevo_legajo, int nuevo_precio_base, char nuevo_tipo);

		//Pre:El objeto debe existir
		//Post:Imprime por pantalla la familia
		void mostrar_familia();

		//Pre:El objeto debe existir
		//Post:Modifica la lista de famlia
		void asignar_familia(Lista<string>* nueva_familiares);

		int obtener_tamanio_cliente();
		
		//Descripcion:Destructor
		//Pre:El objeto debe existir
		//Post:El objeto es destruido
		~Familia();


};

#endif // FAMILIA_H