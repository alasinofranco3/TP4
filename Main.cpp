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

	cargar_abb(archivo,ppal);
	char comando;
	menu();
	cout<<"Ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f'){

            cout<<"Comando invalido"<<endl;
            cout<<"Ingrese un comando"<< endl;
            cin>> comando;
            system("clear");

        }
	//bool cond = buscar_telefono(12315121,ppal);
	//if(cond)
	//	cout << "Fue Encontrado :)" << endl;
	//else
	//	cout << "No Fue Encontrado :(" << endl;
	archivo.close();
	delete ppal;
	return 0;
}