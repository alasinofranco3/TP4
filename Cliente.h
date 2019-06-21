#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente{

private:
	bool alta;
	int legajo;
};

public:
 	//Descripcion:Constructor sin parametros
	//Pre:---
	//Post:Crea un objeto cliente
 	Cliente();                      ////// es al pedo crearlo sin parametros (?)

 	//Descripcion:Constructor con parametros
	//Pre:---
	//Post:Crea un objeto cliente
 	Cliente(bool alta, int legajo);

 	//Pre:El objeto debe existir
	//Post:Devuelve si esta de alta o no
 	bool obtener_alta();

 	//Pre:El objeto debe existir
	//Post:Devuelve el numero de legajo
	int obtener_legajo();

	//Pre:El objeto debe existir
	//Post:Se modifica el estado de alta
	void asignar_alta();

	//Pre:El objeto debe existir
	//Post:Se modifica el numero de legajo
	void asigna_legajo();

};	

#endif // CLIENTE_H