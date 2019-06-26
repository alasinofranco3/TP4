#ifndef ABB_H
#define ABB_H

#include <iostream>
#include "Nodo_abb.h"

using namespace std;

class Abb{
	private:
		Nodo_abb* raiz;
	public:
		//Descripcion:Constructor sin parametros
		//Pre:---
		//Post:Se creo un arbol vacio
		Abb();

		//Descripcion:Constructor con parametros
		//Pre:El parametro pasado debe ser valido
		//Post:Se creo un arbol con un elemento
		Abb(Nodo_abb* nueva_raiz);

		//Pre:El objteto debe existir
		//Post:Se devuelve la raiz del arbol
		Nodo_abb* obtener_raiz();

		//Pre:El parametro pasado debe ser valido.El objteto debe existir
		//Post:Se modifico la raiz del arbol por el valor pasado por parametro
		void asignar_raiz(Nodo_abb* nueva_raiz);

		//Pre:El arbol debe existir
		//Post:Indica si el arbol esta vacio o no
		bool es_vacio();

		//Pre:EL arbol debe existir y el parametro debe ser un puntero valido
		//Post:Se agrego el nodo al arbol
		void agregar(Nodo_abb* nodo_a_agregar);


		void borrar(Nodo_abb*);

		//Descripcion:Destructor
		//Pre:El objeto debe existir
		//Post:El objeto es destruido
		~Abb();
};

#endif // ABB_H
