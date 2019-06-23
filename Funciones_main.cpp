#include "Funciones_main.h"
using namespace std;


int cantidad_espacios(string lectura){
	int i=0,espacios=0;
	while((char)lectura[i] != 0){
		if((char)lectura[i] == 32)
			espacios++;
		i++;
	}
	return espacios;
}

void cargar_clientes(string lectura, Lista<string>* clientes){
    int pos_lista = 1;
    int i = 0;
    int ant = 0;
    bool nombres = false;
    string cliente;
    while( (char)lectura[i] != 0){
        if((lectura[i]==' ' || (char)lectura[i] == 9)){
            nombres=true;
            if(nombres && ant!=0){
              cliente = lectura.substr(ant,i-ant);
              cout<<cliente<<endl;
              clientes -> agregar(&cliente,pos_lista);
              pos_lista++;
            }
            ant = i + 1;
        }
        i++;
    }
    cliente = lectura.substr(ant,i-ant);
    cout<<cliente<<endl;
    clientes -> agregar(&cliente,pos_lista);
}


void cargar_abb(ifstream& archivo,Abb* arbol){
  int cant_usuarios=0;
  string telefono, usuarios;
  while(!archivo.eof()){
  	archivo >> telefono;
  	getline(archivo,usuarios);
  	cant_usuarios = cantidad_espacios(usuarios);
    cout<<"Cantidad de clientes:" << cant_usuarios<< endl;
  	if(cant_usuarios > 1){
  		Lista<string>* clientes = new Lista<string>; 
  		cargar_clientes(usuarios,clientes);
  		Familia* family = new Familia(clientes,true,00102322);
  		Nodo_abb* aux1 = new Nodo_abb(0,0,atoi(telefono.c_str()),family);
      arbol -> agregar(aux1);
  	}
  	else{
  		Individuo* ind = new Individuo(&usuarios,true,00102332);
  		Nodo_abb* aux2 = new Nodo_abb(0,0,atoi(telefono.c_str()),ind);
      arbol -> agregar(aux2);
  	}
  }
}


Nodo_abb* buscar_telefono(int telefono, Abb* arbol){

  Nodo_abb* aux = arbol -> obtener_raiz();
  bool fue_encontrado = false;
  while(aux && !fue_encontrado){

    if(aux -> obtener_telefono() == telefono){
      fue_encontrado = true;
    }

    else if(telefono > aux->obtener_telefono()){
      aux = aux -> obtener_hijo_der();
    }
    else
      aux = aux -> obtener_hijo_izq();
  }

  if (!aux){
    cout<<"El telefono buscado no se encuentra registrado como cliente"<<endl;  
  }

  return aux;
}