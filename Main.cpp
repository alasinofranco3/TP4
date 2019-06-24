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
	menu();

	while(comando != 'f'){

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
			Nodo_abb* aux = buscar_telefono(telefono,ppal);
			while(!aux || !aux->obtener_cliente()->obtener_alta()){
				telefono = pedir_telefono();
			}
			int precio_cliente = precio_producto(telefono,ppal);
			cout <<"El monto a abonar es:" <<precio_cliente<<" pesos"<<endl;
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
			break;
		}
		case 'e':{
			telefono = pedir_telefono();
			Nodo_abb* aux = buscar_telefono(telefono,ppal);
			if(aux != NULL){
				cout << "Persona/s vinculada/s a este numero:"<<endl;;
				//HAY QUE IMPRIMIR POR PANTALLA EL NUMERO Y LOS NOMBRES DE LOS CLIENTES
			}
			break;
		}
		case 'f':{
			delete ppal;
			return 0;
		}


	}
	
	}
}