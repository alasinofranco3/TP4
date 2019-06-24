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

	cargar_abb(archivo,ppal,400);
	char comando;
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
	bool cond = buscar_telefono("12345678",ppal);
	if(cond)
		cout << "Fue Encontrado :)" << endl;
	else
		cout << "No Fue Encontrado :(" << endl;
	archivo.close();
	delete ppal;
	return 0;
}