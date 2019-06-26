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
		string* cliente;
		while( (char)lectura[i] != 0){
				if((lectura[i]==' ' || (char)lectura[i] == 9)){
						nombres=true;
						if(nombres && ant!=0){
							cliente = new string(lectura.substr(ant,i-ant));
							cout << "Pido memoria para el string cliente (en caso de lista) en: " << cliente << endl;
							clientes -> agregar(cliente,pos_lista);
							pos_lista++;
						}
						ant = i + 1;
				}
				i++;
		}
		cliente = new string(lectura.substr(ant,i-ant));
		cout << "Pido memoria para el string cliente (en caso de lista) en: " << cliente << endl;
		clientes -> agregar(cliente,pos_lista);
}


void cargar_abb(ifstream& archivo,Abb* arbol,int precio_base){
	int cant_usuarios=0;
	int n_legajo = LEGAJO_DEFAULT;
	string telefono, usuarios,s_legajo;
	while(!archivo.eof()){
		archivo >> telefono;
		getline(archivo,usuarios);
		s_legajo = "00"+to_string(n_legajo);
		cant_usuarios = cantidad_espacios(usuarios);
		if(cant_usuarios > 1){
			Lista<string>* clientes = new Lista<string>;
			cout << "Pido memoria para la lista de una familia en: " << clientes << endl; 
			cargar_clientes(usuarios,clientes);
			Familia* family = new Familia(clientes,true,s_legajo, precio_base, 'f');
			cout << "Pido memoria para el objeto familia en: " << family << endl;
			Nodo_abb* aux1 = new Nodo_abb(0,0,telefono,family);
			cout << "Pido memoria para el objeto Nodo_Abb* (AUX) en: " << aux1 << endl;
			arbol -> agregar(aux1);
		}
		else{
			Individuo* ind = new Individuo(usuarios,true,s_legajo, precio_base, 'i');
			cout << "Pido memoria para el objeto individuo en: " << ind << endl;
			Nodo_abb* aux2 = new Nodo_abb(0,0,telefono,ind);
			arbol -> agregar(aux2);
			cout << "Pido memoria para el objeto Nodo_Abb* (AUX) en: " << aux2 << endl;
		}
		n_legajo++;
	}
}

void listar_abb(Abb* arbol,Nodo_abb* raiz){
	if(!raiz) return;
	listar_abb(arbol,raiz -> obtener_hijo_izq());
	
	if(raiz->obtener_cliente()->obtener_alta()){
    cout << "---------------------------------------" <<endl;
    cout << "Telefono: " << raiz -> obtener_telefono() << endl;
	 raiz -> obtener_cliente() -> mostrar_cliente();
	 cout << "---------------------------------------" <<endl;
	}
    
    listar_abb(arbol,raiz -> obtener_hijo_der());
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

float precio_producto(string telefono, Abb* arbol){

	Nodo_abb* aux = buscar_telefono(telefono,arbol);

  if(!aux){
    return -1;
  }

	float precio_a_pagar;

	if (aux->obtener_cliente()->obtener_tipo() == 'f'){
		int cant_familiares = aux->obtener_cliente()->obtener_tamanio_cliente();
		precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_familia*cant_familiares;
	} else {
			precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_individuo;
		}

	return precio_a_pagar;  
}

void dar_de_baja(string telefono, Abb* arbol){ 

	Nodo_abb* aux = buscar_telefono(telefono,arbol);
	bool baja = false;

	aux->obtener_cliente()->asignar_alta(baja);
	cout<<"El cliente solicitado ha sido dado de baja"<<endl;
	
}

string pedir_nombre(){
	string nombre;
	cout<<"introduzca el nombre del cliente"<<endl;
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
	cin>>legajo;
	return legajo;
}

void llenar_lista_familia(Lista<string>* familiares){
	char seguir_agregando = 's';
	while(seguir_agregando == 's'){
		string nombre;
		cout<<"Ingrese el nombre del familiar que desea agregar"<<endl;
		cin>>nombre;
		string* ptr_nombre = new string(nombre);
		cout << "Pido memoria para el string cliente llenar_lista_familia en: " << ptr_nombre << endl;
		familiares->agregar(ptr_nombre,1);
		cout<<"Se ha agregado el familiar deseado"<<endl;
		cout<<"Ingrese s si desea agregar otro familiar"<<endl;
		cin>>seguir_agregando;

	}
}

string pedir_telefono(){
	string telefono;

	cout<<"ingrese el numero de telefono"<<endl;
	cin>>telefono;
	
	while(telefono.length() != 8 || !atoi(telefono.c_str())){
    	cout<<"El numero ingresado no es valido,recuerde que los telefonos deben ser numeros de 8 digitos"<<endl;
    	cout<<"ingrese el numero de telefono"<<endl;
    	cin>>telefono;
  }
	return telefono;
	
}

bool telefono_disponible(string telefono,Abb* arbol){
	if(buscar_telefono(telefono,arbol) == NULL){
		return true;
	}
	return false;

}

string generar_telefono(int legajo, Abb* arbol){
	string s_legajo = to_string(legajo);
	string n_telefono = "00" + s_legajo;
	while(!telefono_disponible(n_telefono,arbol)){
		legajo ++;
		s_legajo = to_string(legajo);
		n_telefono = "00" + s_legajo;
	}
	return n_telefono;

}

void agregar_cliente(int precio_base,Abb* arbol){

	char indicador_cliente;
	int nuevo_legajo;
	//Cliente* ptr_cliente = new Cliente();
	string s_legajo;
	//string* s_nombre;

	cout<<"Ingrese i si el nuevo cliente es un individuo o f si es una familia"<<endl;
	cin>>indicador_cliente;

	while(indicador_cliente != 'i' && indicador_cliente != 'f'){
		cout<<"Comando invalido"<<endl;
		cout<<"Ingrese i si el nuevo cliente es un individuo o f si es una familia"<<endl;
		cin>>indicador_cliente;  
	}

	if(indicador_cliente == 'i'){
		nuevo_legajo = pedir_legajo('i');
		s_legajo = to_string(nuevo_legajo);
		//s_nombre = new string(pedir_nombre());
		Individuo* ind = new Individuo(pedir_nombre(),true,s_legajo,precio_base,'i');
		cout << "Pido memoria para el objeto individuo en: " << ind << endl;
		string telefono = generar_telefono(nuevo_legajo,arbol);
		Nodo_abb* aux1 = new Nodo_abb(0,0,telefono,ind);
		cout << "Pido memoria para el objeto Nodo_Abb* (AUX) en: " << aux1 << endl;
		arbol -> agregar(aux1);
	}
	else{
		nuevo_legajo = pedir_legajo('f');
		Lista<string>* familiares = new Lista<string>;
		cout << "Pido memoria para lista de familiares en agregar_cliente en: " << familiares << endl;
		llenar_lista_familia(familiares);
		s_legajo = to_string(nuevo_legajo);
		string telefono = generar_telefono(nuevo_legajo,arbol);
		Familia* familia = new Familia(familiares,true,s_legajo,precio_base,'f');
		cout << "Pido memoria para el objeto familia en: " << familia << endl; 
		Nodo_abb* aux2 = new Nodo_abb(0,0,telefono,familia);
		cout << "Pido memoria para el objeto Nodo_Abb* (AUX) en: " << aux2 << endl;
		arbol -> agregar(aux2);
	}
	
}