#ifndef FAMILIA_H
#define FAMILIA_H

#include <iostream>
#include "Cliente.h"
#include "Lista.h"

using namespace std;

class Familia : public Cliente{
	private:
		Lista<Cliente*> familiares;
	public:
		Familia(Lista<Cliente*> nueva_familiares,bool nueva_alta,int nuevo_telefono);
		void mostrar_familia();
		void asignar_familia(Lista<Cliente*> nueva_familiares);

};

#endif // FAMILIA_H