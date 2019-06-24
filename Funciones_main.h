#ifndef FUNCIONES_MAIN_H
#define FUNCIONES_MAIN_H

#include "Lista.h"
#include "Nodo_lista.h"
#include "Abb.h"
#include "Nodo_abb.h"
#include "Cliente.h"
#include "Familia.h"
#include "Individuo.h"
#include <fstream>
#include <string>

void menu();
int cantidad_espacios(string lectura);
void cargar_clientes(string lectura, Lista<string>* clientes);
void cargar_abb(ifstream& archivo,Abb* arbol,int);
Nodo_abb* buscar_telefono(string telefono, Abb* arbol);
int precio_producto(string telefono, Abb* arbol);
string* pedir_nombre();
int pedir_legajo();
void agregar_cliente(int precio_base,Abb* arbol);


#endif // FUNCIONES_MAIN_H