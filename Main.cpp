#include "Funciones_main.h"
#include <iostream>

const int PRECIO_BASE = 1000;
using namespace std;

int main(){
	Abb* ppal = new Abb();
	ifstream archivo;
	archivo.open("Clientes.txt");
	
	if(archivo.fail()){
		cout<< "No se pudo abrir el archivo"<< endl;
		return 0;
	}

	cargar_abb(archivo,ppal,PRECIO_BASE);
	string telefono;
	char comando;
	bool seguir_operando = true;
	

	while(seguir_operando == true){
	
		menu();
		cout<<"Ingrese un comando"<< endl;
    	cin>> comando;

		while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f'){

			system("clear");
		    cout<<"Comando invalido"<<endl;
		    menu();
		    cout<<"Ingrese un comando"<< endl;
		    cin>> comando;
		}

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
				seguir_operando = false;
				
			}
		}
		
	}
	delete ppal;
	return 0;
}