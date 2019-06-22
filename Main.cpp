#include "Funciones_main.h"

int main(){
	Abb* ppal = new Abb();
	ifstream archivo("Clientes.txt");
	
	if(archivo.fail()){
		cout<< "No se pudo abrir el archivo"<< endl;
		return 0;
	}

	cargar_abb(archivo,ppal);

}