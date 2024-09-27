#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "lista.h"

int main()
{
    printf("\n============= LISTAS ENLAZADAS ============\n");
    printf("============= INT ============\n");
    ListaPtr lista = crearLista();

    int n1=8,n2=76,n3=32,n4=7,n5=23, n6=42;

    printf("\n=================== INSERTAR POSICIONES ===================\n");
    insertarPrimero(lista, &n1);
    insertarPrimero(lista, &n2);
    insertarPrimero(lista, &n3);
    insertarUltimo(lista, &n4);
    insertarPosicion(lista, &n5, 3);
    mostrarListaInt(lista);

    printf("\n=================== OBTENER DATOS ===================\n");
    printf("\nPRIMER DATO: %d\n", *(int*)obtenerPrimero(lista));
    printf("\nULTIMO DATO: %d\n", *(int*)obtenerUltimo(lista));
    printf("\nPOSICION DATO: %d\n", *(int*)obtenerPosicion(lista,2));

    printf("\n=================== OBTENER TAMANIO ===================\n");
    int tam = obtenerTamanio(lista);
    printf("\nTAMANIO: %d\n", tam);

    printf("\n=================== ELIMINAR DATOS ===================\n");
    printf("PRIMERO: \n");
    eliminarPrimero(lista);
    mostrarListaInt(lista);

    printf("\nULTIMO: \n");
    eliminarUltimo(lista);
    mostrarListaInt(lista);

    printf("\nPOSICION: \n");
    eliminarPosicion(lista,3);
    mostrarListaInt(lista);

    printf("=====================================================\n");
    printf("\n---- Agrego de nuevo ---- \n");
    insertarPrimero(lista, &n3);
    insertarUltimo(lista, &n4);
    insertarPosicion(lista,&n1,3);
    mostrarListaInt(lista);

    printf("\n=================== BUSCAR POSICION ===================\n");
    int datoBuscado = 8;
    printf("Posicion del dato: %d \n", buscarDato(lista, &datoBuscado, &compararInt));

    printf("\n=================== ORDENAR LISTA ===================\n");
    ordenarLista(lista, &compararInt);
    mostrarListaInt(lista);

    printf("\n================== ORDENAR LISTA COPIA ===============\n");
    ListaPtr lista2 = ordenarListaCopia(lista);
    mostrarListaInt(lista2);
    liberarLista(lista2);

    printf("\n============= INSERTAR EN ORDEN ============\n");
    insertarEnOrden(lista,&n6, &compararInt);
    mostrarListaInt(lista);

    printf("\n============= FLOAT ============\n");

    float f1=8.23,f2=76.49,f3=32.2,f4=7.43,f5=23.17;

    ListaPtr listaFloat = crearLista();

    insertarPrimero(listaFloat, &f1);
    insertarPrimero(listaFloat, &f2);
    insertarPrimero(listaFloat, &f3);
    insertarUltimo(listaFloat, &f4);
    insertarPosicion(listaFloat, &f5, 3);

    mostrarListaFloat(listaFloat);
    liberarLista(listaFloat);

    printf("\n============= CHAR ============\n");

    char c1[]="Haarper",c2[]="Freddie",c3[]="Bones",c4[]="Ramirez",c5[]="Hxzz";

    ListaPtr listaChar = crearLista();

    insertarPrimero(listaChar, c1);
    insertarPrimero(listaChar, c2);
    insertarPrimero(listaChar, c3);
    insertarUltimo(listaChar, c4);
    insertarPosicion(listaChar, c5, 3);

    mostrarListaChar(listaChar);


    PersonaPtr p1 = crearPersona("Haarper",11111111);
    PersonaPtr p2 = crearPersona("Freddie",55555555);
    PersonaPtr p3 = crearPersona("Bones",33333333);
    PersonaPtr p4 = crearPersona("Ramirez",77777777);

    ListaPtr listaPersona = crearLista();

    insertarPrimero(listaPersona, &p1);
    insertarPrimero(listaPersona, &p2);
    insertarPrimero(listaPersona, &p3);
    insertarPrimero(listaPersona, &p4);

    mostrarListaGenerico(listaPersona, &mostrarPersonaDatoPtr);

    ordenarLista(listaPersona, &compararPersonasDatoPtr);

    mostrarListaGenerico(listaPersona, &mostrarPersonaDatoPtr);

    liberarLista(listaPersona);

    return 0;
}
