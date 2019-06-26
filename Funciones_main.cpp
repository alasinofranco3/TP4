#include "Funciones_main.h"
using namespace std;

//-------------Funciones Auxiliares Funciones_Main.cpp--------------------//

string pedir_nombre(){
	string nombre;
	cout<<"introduzca el nombre del cliente"<<endl;
	cin>>nombre;
	return nombre;
}

string pedir_legajo(char tipo_cliente){
	string legajo;
	if(tipo_cliente == 'i')
		cout<<"Ingrese el legajo del cliente"<<endl;    
	else
		cout<<"Ingrese el legajo del titular/responsable"<<endl;
	cin>>legajo;
	while(atoi(legajo.c_str()) < 0){
		cout << "El legajo debe ser numerico y mayor a 0, ingrese legajo" << endl;
		cin>>legajo;
	}
	return legajo;
}

void llenar_lista_familia(Lista<string>* familiares){
	char seguir_agregando = 's';
	while(seguir_agregando == 's'){
		string nombre;
		cout<<"Ingrese el nombre del familiar que desea agregar"<<endl;
		cin>>nombre;
		string* ptr_nombre = new string(nombre);
		familiares->agregar(ptr_nombre,1);
		cout<<"Se ha agregado el familiar deseado"<<endl;
		cout<<"Ingrese s si desea agregar otro familiar"<<endl;
		cin>>seguir_agregando;
	}
}

bool telefono_disponible(string telefono,Abb* arbol){
	return buscar_telefono(telefono,arbol) == NULL;
}

string generar_telefono(string legajo, Abb* arbol){
	int i_legajo;
	string n_telefono = "00" + legajo;
	while(!telefono_disponible(n_telefono,arbol)){
		i_legajo = atoi(legajo.c_str());
		i_legajo ++;
		legajo = to_string(i_legajo);
		n_telefono = "00" + legajo;
	}
	return n_telefono;

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
char obtener_indicador(){
	char indicador_cliente;
	cout<<"Ingrese i si el nuevo cliente es un individuo o f si es una familia"<<endl;
	cin>>indicador_cliente;
	while(indicador_cliente != 'i' && indicador_cliente != 'f'){
		cout<<"Comando invalido"<<endl;
		cout<<"Ingrese i si el nuevo cliente es un individuo o f si es una familia"<<endl;
		cin>>indicador_cliente;  
	}
	return indicador_cliente;
}

//--------------------------------------------------------------------//



//----------------------Metodos de Funciones_Main.cpp-------------------------------//


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


void cargar_clientes(string lectura, Lista<string>* clientes){
		int pos_lista = 1,i = 0,ant = 0;
		string* cliente;
		while( (char)lectura[i] != 0){
				if((lectura[i]==' ' || (char)lectura[i] == 9)){
						if(ant!=0){
							cliente = new string(lectura.substr(ant,i-ant));
							clientes -> agregar(cliente,pos_lista);
							pos_lista++;
						}
						ant = i + 1;
				}
				i++;
		}
		cliente = new string(lectura.substr(ant,i-ant));
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
			cargar_clientes(usuarios,clientes);
			Familia* family = new Familia(clientes,true,s_legajo, precio_base, 'f');
			Nodo_abb* aux1 = new Nodo_abb(0,0,telefono,family);
			arbol -> agregar(aux1);
		}
		else{
			Individuo* ind = new Individuo(usuarios,true,s_legajo, precio_base, 'i');
			Nodo_abb* aux2 = new Nodo_abb(0,0,telefono,ind);
			arbol -> agregar(aux2);
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
		aux_busqueda = atoi(aux -> obtener_telefono().c_str());
		if(aux_busqueda == aux_telefono)
			fue_encontrado = true;
		else if(aux_telefono > aux_busqueda)
			aux = aux -> obtener_hijo_der();
		else
			aux = aux -> obtener_hijo_izq();
	}
	if (!aux)
		cout<<"El telefono buscado no se encuentra registrado como cliente"<<endl;  
	return aux;
}

float precio_producto(string telefono, Abb* arbol){
	Nodo_abb* aux = buscar_telefono(telefono,arbol);
  	if(!aux)
    	return -1;
	float precio_a_pagar;

	if (aux->obtener_cliente()->obtener_tipo() == 'f'){
		int cant_familiares = aux->obtener_cliente()->obtener_tamanio_cliente();
		precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_familia*cant_familiares;
	} 
	else
		precio_a_pagar = (aux->obtener_cliente()->obtener_precio_base())*descuento_individuo;

	return precio_a_pagar;  
}

void dar_de_baja(string telefono, Abb* arbol){ 
	Nodo_abb* aux = buscar_telefono(telefono,arbol);
	aux->obtener_cliente()->asignar_alta(false);
	cout<<"El cliente solicitado ha sido dado de baja"<<endl;	
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


void agregar_cliente(int precio_base,Abb* arbol){
	char indicador_cliente = obtener_indicador();
	string s_legajo = pedir_legajo(indicador_cliente);
	string telefono = generar_telefono(s_legajo,arbol);

	if(indicador_cliente == 'i'){
		Individuo* ind = new Individuo(pedir_nombre(),true,s_legajo,precio_base,'i');
		Nodo_abb* aux1 = new Nodo_abb(0,0,telefono,ind);
		arbol -> agregar(aux1);
	}
	else{
		Lista<string>* familiares = new Lista<string>;
		llenar_lista_familia(familiares);
		Familia* familia = new Familia(familiares,true,s_legajo,precio_base,'f');
		Nodo_abb* aux2 = new Nodo_abb(0,0,telefono,familia);
		arbol -> agregar(aux2);
	}
	
}

bool operaciones(Abb* ppal,char comando,string telefono){
	bool operacion = true;

	switch(comando){
			case 'a':{
				telefono = pedir_telefono();
				float precio_cliente = precio_producto(telefono,ppal);
				if (precio_cliente != -1){
					cout <<"El monto a abonar es:" <<precio_cliente<<" pesos"<<endl;
				}
				
				break;
			}
			case 'b':{
				agregar_cliente(PRECIO_BASE,ppal);
				break;
			}
			case 'c':{
				telefono = pedir_telefono();
				dar_de_baja(telefono,ppal);
				break;
			}
			case 'd':{
				listar_abb(ppal,ppal -> obtener_raiz());
				break;
			}
			case 'e':{
				telefono = pedir_telefono();
				Nodo_abb* aux = buscar_telefono(telefono,ppal);
				if(aux){
					aux->obtener_cliente()->mostrar_cliente();
				}
				break;
			}
			case 'f':{
				operacion = false;
				
			}
		}
	return operacion;

}

//--------------------------------------------------------------------//
