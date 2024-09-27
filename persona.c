#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

struct PersonaE{
  char nombre[10];
  int dni;
};

PersonaPtr crearPersona(char nombre[], int dni){

    PersonaPtr p = (PersonaPtr)malloc(sizeof(struct PersonaE));

    strcpy(p->nombre, nombre);
    p->dni = dni;

    return p;
};

int compararPersonasDatoPtr(void * d1, void * d2){
    PersonaPtr p1 = *(PersonaPtr*) d1;
    PersonaPtr p2 = *(PersonaPtr*) d2;

    return p1->dni > p2->dni;
};

void mostrarPersona(PersonaPtr persona){
    printf("================= PERSONA =================\n");
    printf("NOMBRE: %s\n", persona->nombre);
    printf("DNI: %d\n", persona->dni);
};

void mostrarPersonaDatoPtr(void * dato){
    PersonaPtr p = *(PersonaPtr*)(dato);
    mostrarPersona(p);
};

void liberarPersona(PersonaPtr persona){
    free(persona);
};

int getDni(PersonaPtr persona){
    return persona->dni;
};
char* getNombre(PersonaPtr persona){
    return persona->nombre;
};
//SETTERS
void setDni(PersonaPtr persona, int nuevoDni){
    persona->dni = nuevoDni;
};
void setNombre(PersonaPtr persona, char* nuevoNombre){
    strcpy(persona->nombre,nuevoNombre);
};
