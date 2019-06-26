#include "Funciones_main.h"
#include <iostream>


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

		seguir_operando = operaciones(ppal,comando,telefono);
		
	}
	delete ppal;
	return 0;
}