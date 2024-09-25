#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo{
    int dato;
    NodoPtr siguiente;
};

NodoPtr crearNodo(int dato,NodoPtr siguiente){

    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;
};
void mostrarNodo(NodoPtr nodo){
    printf(" %d ", nodo->dato);

};
void liberarNodo(NodoPtr nodo){
    free(nodo);
};

///GETTERS Y SETTERS
//GETTERS
int getDato(NodoPtr nodo){
    return nodo->dato;
};
NodoPtr getSiguiente(NodoPtr nodo){
    return nodo->siguiente;
};
//SETTERS
void setDato(NodoPtr nodo, int nuevoDato){
    nodo->dato = nuevoDato;
};
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente){
    nodo->siguiente = nuevoSiguiente;
};
