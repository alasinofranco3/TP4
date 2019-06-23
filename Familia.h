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
		Familia(Lista<string>* nueva_familiares,bool nueva_alta,int nuevo_legajo);
		void mostrar_familia();
		void asignar_familia(Lista<string>* nueva_familiares);
		~Familia();

};

#endif // FAMILIA_H