#ifndef ABB_H
#define ABB_H

#include <iostream>
#include "Nodo_abb.h"


//class Nodo_abb;

using namespace std;
//class Nodo_abb;

class Abb{
	private:
		Nodo_abb* raiz;
		int* altura;
	public:
		//Descripcion:Constructor sin parametros
		//Pre:---
		//Post:Se creo un arbol vacio
		Abb();

		//Descripcion:Constructor con parametros
		//Pre:El parametro pasado debe ser valido
		//Post:Se creo un arbol con un elemento
		Abb(Nodo_abb* nueva_raiz, int nueva_altura);
		
		//Pre:El objteto debe existir
		//Post:Se devuelve la raiz del arbol
		Nodo_abb* obtener_raiz();
		
		//Pre:El objteto debe existir
		//Post:Se devuelve la altura del arbol
		int obtener_altura();
		
		//Pre:El parametro pasado debe ser valido.El objteto debe existir
		//Post:Se modifico la raiz del arbol por el valor pasado por parametro
		void asignar_raiz(Nodo_abb* nueva_raiz);

		//Descripcion:Destructor
		//Pre:El objeto debe existir
		//Post:El objeto es destruido
		~Abb();	 
};

#endif // ABB_H