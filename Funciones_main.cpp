#include "Funciones_main.h"
using namespace std;


void menu(){
cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;

        cout<<"a. Mostrar monto a abonar del producto"<< endl;
        cout<<"b. Agregar cliente"<< endl;
        cout<<"c. Dar de baja a un cliente"<< endl;
        cout<<"d. Listar clientes"<<endl;
        cout<<"e. Buscar cliente por numero de telefono"<<endl;;
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

Nodo_abb* dar_de_baja(int telefono, Abb* arbol){ // hacerla void(?)

  Nodo_abb* aux = buscar_telefono(telefono,arbol);
  bool baja = false;

  aux->obtener_cliente()->asignar_alta(baja);
  cout<<"El cliente solicitado ha sido dado de baja"<<endl;
  return aux;
}

string pedir_nombre(){
  string nombre;
  cout<<"introduzca el nombre del cliente"
  cin>>nombre;
  return nombre;
}

int pedir_legajo(char tipo_cliente){
  
  int legajo;

  if(tipo_cliente == 'i'){
    cout<<"Ingrese el legajo del cliente"<<endl;    
  }
  else{
    cout<<"Ingrese el legajo del titular/responsable"<<endl;
  }
  cin<<legajo;
  return legajo;
}

void llenar_lista_familia(Lista<string>* familiares){
  char seguir_agregando = 's';
  while(seguir_agregando == 's'){
    string nombre;
    string* ptr_nombre = new string;
    ptr_nombre = &nombre;
    cout<<"Ingrese el nombre del familiar que desea agregar"<<endl;
    cin>>nombre;
    familiares->agregar(ptr_nombre,1);
    cout<<"Se ha agregado el familiar deseado"<<endl;
    cout<<"Ingrese s si desea agregar otro familiar"<<endl;
    cin>>seguir_agregando;

  }
}

bool telefono_disponible(int telefono){

}

void agregar_cliente(int precio_base,Abb* arbol){

  char indicador_cliente;
  int nuevo_legajo;
  Cliente* ptr_cliente = new Cliente();

  cout<<"Ingrese i si el nuevo cliente es un individuo o f si es una familia"<<endl;
  cin>>indicador_cliente;

  while(indicador_cliente != 'i' && indicador_cliente != 'f'){
    cout<<"Comando invalido"<<endl;
    cout<<"Ingrese i si el nuevo cliente es un individuo o f si es una familia"<<endl;
    cin>>indicador_cliente;  
  }

  if(indicador_cliente == 'i'){
    nuevo_legajo = pedir_legajo('i');
    Individuo* ind = new Individuo(pedir_nombre(),true,nuevo_legajo,precio_base,'i');
    ptr_cliente = ind;
  }
  else{
    nuevo_legajo = pedir_legajo('f');
    Lista<string>* familiares = new Lista<string>;
    llenar_lista_familia(familiares);
    nuevo_legajo = pedir_legajo('f');
    Familia* familia = new Familia(familiares,true,nuevo_legajo,precio_base,'f'); 
    ptr_cliente = familia;
  }
  
  //VERIFICAR SI EL TELEFONO ESTA DISPONIBLE//
  //CREAR EL NODO Y AGREGARLO AL ARBOL//

}