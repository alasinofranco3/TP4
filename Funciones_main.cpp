#include "Funciones_main.h"

int cantidad_espacios(string lectura){
	int i=0,espacios=0;
	while((char)lectura[i] != 0){
		if(lectura[i] == " ")
			espacios++;
		i++;
	}
	return espacios;

}



void cargar_clientes(string lectura,Lista<Cliente> clientes){
    int pos_lista = 1;
    int i =0;
    int ant = 0;
    string cliente;
    while( (char)lectura[i] != 0){
        if(lectura[i]==' ' || (char)lectura[i] == 9){
            cliente = lectura.substr(ant,i-ant);
            clientes -> agregar()
            ant = i + 1;
            pos_lista++;
        }
        i++;
    }
    cliente = lectura.substr(ant,i-ant);
    Actor* Aactor = new Actor(actor);
    actores -> agregar(Aactor, pos_lista);
}



   

void cargar_abb(ifstream* archivo,Abb* arbol){
  int pos_lista = 1, cant_usuarios=0;
  string telefono, usuarios;
  while(!archivo.eof()){
  	archivo >> telefono;
  	getline(archivo,usuarios);
  	cant_usuarios = cantidad_espacios(string usuarios);
  	if(cant_usuarios > 1){
  		Lista<Cliente>* clientes = new Lista<Cliente>; 
  		cargar_clientes(usuarios,clientes);
  		Nodo_abb* aux = new Nodo_abb(0,0,atoi(telefono.c_str()),clientes);
  	}
  	else{
  		Nodo_abb* aux = new Nodo_abb(0,0,atoi(telefono.c_str()),usuarios);
  	}


  	arbol -> agregar(aux);



  }

}

        getline(archivo, nombre);
        getline(archivo, genero);
        getline(archivo, nota_s);
        nota = atoi(nota_s.c_str());
        getline(archivo, director);
        getline(archivo, actores);
        Pelicula* Nueva_pelicula = new Pelicula(nombre, genero, director, nota, actores);
        lista -> agregar(Nueva_pelicula, pos_lista);
        getline(archivo, aux);
        pos_lista++;
