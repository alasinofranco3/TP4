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
			int precio_cliente = precio_producto(telefono,ppal);
			cout << precio_cliente<<endl;
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
			Nodo_abb* r = ppal -> obtener_raiz();
			listar_abb(ppal,r);
			break;
		}
		case 'e':{
			telefono = pedir_telefono();
			Nodo_abb* aux = buscar_telefono(telefono,ppal);
			cout << aux -> obtener_cliente() -> obtener_tamanio_cliente();
			break;
		}
	}
	
	}
	delete ppal;
	return 0;
}