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
void cargar_abb(ifstream& archivo,Abb* arbol);
Nodo_abb* buscar_telefono(int telefono, Abb* arbol);
int precio_producto(int telefono, Abb* arbol);



#endif // FUNCIONES_MAIN_H