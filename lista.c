#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

struct Lista{
    NodoPtr primero;
};

ListaPtr crearLista(){
    ListaPtr lista = (ListaPtr)malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

void insertarPrimero(ListaPtr lista, int dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;

};

void insertarUltimo(ListaPtr lista, int dato){
    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    NodoPtr actual = lista->primero;

    if(lista->primero == NULL){
        lista->primero = nuevoNodo;
    }else{
        while(getSiguiente(actual) != NULL){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual,nuevoNodo);
    }
};

void insertarPosicion(ListaPtr lista, int dato, int posicion){

    int tam = obtenerTamanio(lista);

    if(posicion > tam){
        printf("NO SE PUEDE AGREGAR EN POSICION QUE NO EXISTE \n\n");
    }else{
        if(posicion < 0){
            printf("NO SE PUEDE AGREGAR EN POSICION NEGATIVA\n\n");
        }else{
            if(posicion == 0){
                insertarPrimero(lista, dato);
            }else{
                if(posicion == tam){
                    insertarUltimo(lista, dato);
                }else{
                    if(posicion > 0 && posicion < tam){
                       NodoPtr actual = lista->primero;

                       for(int i=1; i<posicion-1;i++){
                        actual = getSiguiente(actual);
                       }
                    setSiguiente(actual, crearNodo(dato, getSiguiente(actual)));
                    }
                }
            }
        }
    }
};

int obtenerPrimero(ListaPtr lista){
    if(lista->primero == NULL){
        printf("LISTA NULA\n");
        return -1;
    }
    NodoPtr primero = lista->primero;
    return getDato(primero);
};
int obtenerUltimo(ListaPtr lista){
    if(lista->primero == NULL){
        printf("LISTA NULA\n");
        return -1;
    }

    NodoPtr ultimo = lista->primero;

    while(getSiguiente(ultimo) != NULL){
        ultimo = getSiguiente(ultimo);
    }
    return getDato(ultimo);
};

int obtenerPosicion(ListaPtr lista, int posicion){
    if(lista->primero == NULL){
        printf("LISTA NULA\n");
        return -1;
    }
    NodoPtr actual = lista->primero;
    for(int i=1; i<posicion;i++){
        actual = getSiguiente(actual);
    }
    return getDato(actual);
};

void eliminarPrimero(ListaPtr lista){
    if(lista->primero == NULL){
        printf("Lista vacia\n");
    }
    NodoPtr nodoABorrar = lista->primero;

    lista->primero = getSiguiente(nodoABorrar);
    liberarNodo(nodoABorrar);
};

void eliminarUltimo(ListaPtr lista){
    if(lista->primero == NULL){
        printf("Lista vacia\n");
    }
    NodoPtr actual = lista->primero;

    if (getSiguiente(actual) == NULL) {
        liberarNodo(actual);
        lista->primero = NULL;
        return;
    }
    while (getSiguiente(getSiguiente(actual)) != NULL) {
        actual = getSiguiente(actual);
    }
    liberarNodo(getSiguiente(actual));
    setSiguiente(actual, NULL);
};
void eliminarPosicion(ListaPtr lista, int pos){
    if (lista->primero == NULL) {
        printf("La lista está vacía.\n");
    }
    int tam = obtenerTamanio(lista);

    if (pos < 1 || pos > tam) {
        printf("La posicion es erronea\n");

    }
    if (pos == 1) {
        return eliminarPrimero(lista);
    }
    if (pos == tam) {
        return eliminarUltimo(lista);
    }

    NodoPtr actual = lista->primero;
    for (int i = 1; i < pos - 1; i++) {
        actual = getSiguiente(actual);
    }

    NodoPtr nodoAEliminar = getSiguiente(actual);
    setSiguiente(actual, getSiguiente(nodoAEliminar));

    free(nodoAEliminar);
};

NodoPtr obtenerPrimerNodo(ListaPtr lista){
    return lista->primero;
};
NodoPtr obtenerUltimoNodo(ListaPtr lista){
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        actual = getSiguiente(actual);
    }
    return actual;
};
NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion){
    int tam = obtenerTamanio(lista);
    int cont = 0;
    NodoPtr actual = lista->primero;

    if(posicion > tam){
        printf("Posicion fuera de limite\n");
        return NULL;
    }

    while(actual != NULL && cont < posicion){
        actual = getSiguiente(actual);
        cont =+1;
    }
    return actual;
};

int obtenerTamanio(ListaPtr lista){
    int tamanio = 0;

    NodoPtr actual = lista->primero;

    if(actual == NULL){
        return 0;
    }else{
        while(actual != NULL){
            tamanio = tamanio + 1;
            actual = getSiguiente(actual);
        }
    }

    return tamanio;
};

void ordenarLista(ListaPtr lista){
    int aux;
    int tam = obtenerTamanio(lista);

    for(int i=0; i< tam-1; i++){
        NodoPtr actual = lista->primero;
        NodoPtr siguiente = getSiguiente(actual);

        for(int j=i+1; j< tam; j++){
            if(getDato(actual) > getDato(getSiguiente(actual))){
                aux = getDato(actual);
                setDato(actual, getDato(siguiente)); ///getDato(actual) = getDato(getSiguiente(actual));
                setDato(siguiente,aux);              ///getDato(getSiguiente(actual)) = aux;
            }
             actual = siguiente;
             siguiente= getSiguiente(siguiente);
        }
        actual = lista->primero;
    }
};

ListaPtr ordenarListaCopia(ListaPtr lista){
    ListaPtr listaCopia = duplicarLista(lista);
    ordenarLista(listaCopia);
    return listaCopia;
};

ListaPtr duplicarLista(ListaPtr lista){
    if (lista == NULL) {
        return NULL;
    }
    ListaPtr nuevaLista = crearLista();

    NodoPtr actual = lista->primero;
    NodoPtr ultimoNuevoNodo = NULL;

    while (actual != NULL) {
        NodoPtr nuevoNodo = crearNodo(getDato(actual),getSiguiente(actual));
        if (nuevaLista->primero == NULL) {
            nuevaLista->primero = nuevoNodo;
        } else {
            setSiguiente(ultimoNuevoNodo,nuevoNodo);
        }
        ultimoNuevoNodo = nuevoNodo;
        actual = getSiguiente(actual);
    }
    return nuevaLista;
};

int buscarDato(ListaPtr lista, int datoBuscado){
    if(getDato(lista->primero) == datoBuscado){
        return getDato(lista->primero);
    }
    int tam = obtenerTamanio(lista);
    int encontro = -1;

    NodoPtr actual = lista->primero;
    if(datoBuscado == obtenerUltimo(lista)){
        return obtenerUltimo(lista);
    }
    for(int i=1; i<tam;i++){
        if(datoBuscado == getDato(actual)){
            encontro = i;
        }
        actual = getSiguiente(actual);
    }
    return encontro;
};

void insertarEnOrden(ListaPtr lista, int dato){
    if(lista == NULL){
        printf("Lista vacia");
    }
    NodoPtr nuevoNodo = crearNodo(dato,NULL);

    if(lista->primero == NULL && getDato(lista->primero)>= dato){
        setSiguiente(nuevoNodo, lista->primero);
        lista->primero = nuevoNodo;
    }else{
        NodoPtr actual = lista->primero;
        while(getSiguiente(actual)!=NULL && getDato(getSiguiente(actual))<dato){
            actual = getSiguiente(actual);
        }
        setSiguiente(nuevoNodo, getSiguiente(actual));
        setSiguiente(actual, nuevoNodo);
    }
};

void mostrarLista(ListaPtr lista){
    printf("LISTA\n");
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        mostrarNodo(actual);
        actual = getSiguiente(actual);

        }
    printf("\n");
};

void liberarLista(ListaPtr lista){
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        NodoPtr aux = getSiguiente(actual);
        free(actual);
        actual = getSiguiente(aux);

        }
    free(lista);
};
