#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>

using namespace std;

class Individuo : public Cliente{	
	private:
		string nombre;
	public:
		Individuo(string nuevo_nombre,int nuevo_telefono,bool nueva_alta);
		string obtener_individuo();
		void asignar_individuo(string nuevo_nombre);
};

#endif // INDIVIDUO_H