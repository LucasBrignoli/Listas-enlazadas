#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    printf("\n=================== INSERTAR POSICIONES ===================\n");
    insertarPrimero(lista, 8);
    insertarPrimero(lista, 76);
    insertarPrimero(lista, 32);
    insertarUltimo(lista, 7);
    insertarPosicion(lista, 23, 3);
    mostrarLista(lista);

    printf("\n=================== OBTENER DATOS ===================\n");
    printf("\nPRIMER DATO: %d\n", obtenerPrimero(lista));
    printf("\nULTIMO DATO: %d\n", obtenerUltimo(lista));
    printf("\nPOSICION DATO: %d\n", obtenerPosicion(lista,2));

    printf("\n=================== OBTENER TAMANIO ===================\n");
    int tam = obtenerTamanio(lista);
    printf("\nTAMANIO: %d\n", tam);

    printf("\n=================== ELIMINAR DATOS ===================\n");
    printf("PRIMERO: \n");
    eliminarPrimero(lista);
    mostrarLista(lista);

    printf("\nULTIMO: \n");
    eliminarUltimo(lista);
    mostrarLista(lista);

    printf("\nPOSICION: \n");
    eliminarPosicion(lista,3);
    mostrarLista(lista);

    printf("=====================================================\n");
    printf("\n---- Agrego de nuevo ---- \n");
    insertarPrimero(lista, 32);
    insertarUltimo(lista, 7);
    insertarPosicion(lista,23,3);
    mostrarLista(lista);

    printf("\n=================== BUSCAR POSICION ===================\n");
    printf("Posicion del dato: %d \n", buscarDato(lista,7));

    printf("\n=================== ORDENAR LISTA ===================\n");
    ordenarLista(lista);
    mostrarLista(lista);

    printf("\n================== ORDENAR LISTA COPIA ===============\n");
    ListaPtr lista2 = ordenarListaCopia(lista);
    mostrarLista(lista2);
    liberarLista(lista2);

    printf("\n============= INSERTAR EN ORDEN ============\n");
    insertarEnOrden(lista,42);
    mostrarLista(lista);

    return 0;
}
