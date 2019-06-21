#ifndef FAMILIA_H
#define FAMILIA_H

#include <iostream>

using namespace std;

class Familia : public Cliente{
	private:
		Lista familiares;
	public:
		Familia(Lista nueva_familiares,bool nueva_alta,int nuevo_telefono);
		void mostrar_familia();
		void asignar_familia(Lista nueva_familiares);

};

#endif // FAMILIA_H