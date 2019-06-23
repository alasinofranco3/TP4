#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>
#include "Cliente.h"

using namespace std;

class Individuo : public Cliente{	
	private:
		string* nombre;
	public:
		//Descripcion:Constructor con parametros
		//Pre:---
		//Post:Crea un objeto individuo
		Individuo(string* nuevo_nombre,bool nueva_alta,int nuevo_legajo, int nuevo_precio_base, char nuevo_tipo);

		//Pre:El objeto debe existir
		//Post:devuelve el nombre del individuo
		string obtener_individuo();

		//Pre:El objeto debe existir
		//Post:Modifica el nombre del individuo
		void asignar_individuo(string* nuevo_nombre);

		//Descripcion:Destructor
		//Pre:El objeto debe existir
		//Post:El objeto es destruido
		~Individuo();
};

#endif // INDIVIDUO_H