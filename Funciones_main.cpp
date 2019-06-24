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


void cargar_abb(ifstream& archivo,Abb* arbol,int precio_base){
  int cant_usuarios=0;
  int n_legajo = 100000;
  string telefono, usuarios,s_legajo;
  while(!archivo.eof()){
  	archivo >> telefono;
  	getline(archivo,usuarios);
    s_legajo = "00"+to_string(n_legajo);
  	cant_usuarios = cantidad_espacios(usuarios);
    cout<<"Cantidad de clientes:" << cant_usuarios<< endl;
  	if(cant_usuarios > 1){
  		Lista<string>* clientes = new Lista<string>; 
  		cargar_clientes(usuarios,clientes);
  		Familia* family = new Familia(clientes,true,s_legajo, precio_base, 'f');
  		Nodo_abb* aux1 = new Nodo_abb(0,0,telefono,family);
      arbol -> agregar(aux1);
  	}
  	else{
  		Individuo* ind = new Individuo(&usuarios,true,s_legajo, precio_base, 'i');
  		Nodo_abb* aux2 = new Nodo_abb(0,0,telefono,ind);
      arbol -> agregar(aux2);
  	}
    n_legajo++;
  }
}


Nodo_abb* buscar_telefono(string telefono, Abb* arbol){

  Nodo_abb* aux = arbol -> obtener_raiz();
  int aux_telefono = atoi(telefono.c_str()),aux_busqueda=0;
  bool fue_encontrado = false;
  while(aux && !fue_encontrado){

    aux_busqueda = atoi(aux -> obtener_telefono() . c_str());
    if(aux_busqueda == aux_telefono){
      fue_encontrado = true;
    }

    else if(aux_telefono > aux_busqueda){
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

int precio_producto(string telefono, Abb* arbol){

  Nodo_abb* aux = buscar_telefono(telefono,arbol);

  int precio_a_pagar;

  if (aux->obtener_cliente()->obtener_tipo() == 'f'){
    precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_familia;
  } else {
      precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_individuo;
    }

  return precio_a_pagar;  
}

void dar_de_baja(string telefono, Abb* arbol){ // hacerla void(?)

  Nodo_abb* aux = buscar_telefono(telefono,arbol);
  bool baja = false;

  aux->obtener_cliente()->asignar_alta(baja);
  cout<<"El cliente solicitado ha sido dado de baja"<<endl;
}

string* pedir_nombre(){
  string* nombre;
  cout<<"introduzca el nombre del cliente";
  cin>>*nombre;
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
  cin>>legajo;
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


string pedir_telefono(){
  string telefono;
  do{
  cout << "Ingrese N° Telefono: ";
  cin>> telefono;
  }
  while(telefono.length() != 8 && !atoi(telefono.c_str()));
  return telefono;
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
    string s_legajo = to_string(nuevo_legajo);
    Individuo* ind = new Individuo(pedir_nombre(),true,s_legajo,precio_base,'i');
    ptr_cliente = ind;
  }
  else{
    nuevo_legajo = pedir_legajo('f');
    Lista<string>* familiares = new Lista<string>;
    llenar_lista_familia(familiares);
    string s_legajo = to_string(nuevo_legajo);
    //nuevo_legajo = pedir_legajo('f');
    Familia* familia = new Familia(familiares,true,s_legajo,precio_base,'f'); 
    ptr_cliente = familia;
  }
  string n_telefono = "00" + to_string(nuevo_legajo);
  Nodo_abb* aux = new Nodo_abb(0,0,n_telefono,ptr_cliente);
  
  arbol -> agregar(aux);
}