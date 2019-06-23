#include "Funciones_main.h"
using namespace std;


void menu(){
cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;

        cout<<"a. Mostrar monto a abonar del producto"<< endl;
        cout<<"b. Agregar cliente"<< endl;
        cout<<"c. Dar de baja a un cliente"<< endl;
        cout<<"d. Listar clientes";
        cout<<"e. Buscar cliente por numero de telefono";
        cout<<"f. Salir de la aplicacion"<< endl;    

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;
}

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
  		Familia* family = new Familia(clientes,true,00102322, 1231, 'F');
  		Nodo_abb* aux1 = new Nodo_abb(0,0,atoi(telefono.c_str()),family);
      arbol -> agregar(aux1);
  	}
  	else{
  		Individuo* ind = new Individuo(&usuarios,true,00102332, 1222, 'i');
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

int precio_producto(int telefono, Abb* arbol){

  Nodo_abb* aux = buscar_telefono(telefono,arbol);

  int precio_a_pagar;

  if (aux->obtener_cliente()->obtener_tipo() == 'F'){
    precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_familia;
  } else {
      precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_individuo;
    }

  return precio_a_pagar;  
}

Nodo_abb* quitar_cliente(int telefono, Abb* arbol){ // hacerla void(?)

  Nodo_abb* aux = buscar_telefono(telefono,arbol);
  bool quitar = false;

  aux->obtener_cliente()->asignar_alta(quitar);
  cout<<"El cliente solicitado a sido eliminado"<<endl;
  return aux;
}

void agregar_cliente(){

  
}