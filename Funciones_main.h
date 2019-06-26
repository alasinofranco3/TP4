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

const int LEGAJO_DEFAULT = 100000;
const int PRECIO_BASE = 1000;

void menu();

    //Pre: Debe recibir parametros validos
    //Post: Carga los clientes en memoria din?ica
    void cargar_clientes(string lectura, Lista<string>* clientes);

    //Pre: El achivo debe ser valido y el ABB debe existir
    //Post: Agrega los objetos cliente al ABB
    void cargar_abb(ifstream& archivo,Abb* arbol,int);

    //Pre: Los parametros deben ser validos y el abb existir
    //Post: Se devuelve el nodo que contiene al cliente que coincide su telefono
    Nodo_abb* buscar_telefono(string telefono, Abb* arbol);

    //Pre: Los parametros deben ser validos y el abb existir
    //Post: Se da de baja el cliente en cuestion
    void dar_de_baja(string telefono, Abb* arbol);

    //Pre: Los parametros deben ser validos y el abb existir
    //Post: Devuelve el precio del cliente en cuestion
    float precio_producto(string telefono, Abb* arbol);

    //Pre: El abb debe existir
    //Post: Devuelve todos los datos de los clientes del ABB
    void listar_abb(Abb* arbol,Nodo_abb* raiz);

    //Pre: -----
    //Post: Recibe un numero de telefono valido
    string pedir_telefono();

    //Pre: Los parametros deben ser validos y el abb existir
    //Post: Se agrega un nuevo cliente al abb
    void agregar_cliente(int precio_base,Abb* arbol);


#endif // FUNCIONES_MAIN_H
