#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>
#include "Cliente.h"

using namespace std;

class Individuo : public Cliente{	
	private:
		string* nombre;
	public:
		Individuo(string nuevo_nombre,bool nueva_alta,int nuevo_telefono);
		string obtener_individuo();
		void asignar_individuo(string nuevo_nombre);
};

#endif // INDIVIDUO_H