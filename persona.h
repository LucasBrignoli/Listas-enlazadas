#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct PersonaE;

typedef struct PersonaE * PersonaPtr;

/**
 * @brief Crea una nueva persona.
 * @pre nombre es una cadena válida y dni es un número entero.
 * @post Devuelve un puntero a la nueva persona creada.
 */
PersonaPtr crearPersona(char nombre[], int dni);

/**
 * @brief Compara dos punteros a datos de tipo Persona.
 * @pre d1 y d2 apuntan a personas válidas.
 * @post Devuelve un entero menor que, igual a, o mayor que cero si el primer DNI es menor, igual o mayor que el segundo, respectivamente.
 */
int compararPersonasDatoPtr(void * d1, void * d2);

/**
 * @brief Muestra el contenido de una persona.
 * @pre persona no es NULL.
 * @post Imprime el contenido de la persona en la salida estándar.
 */
void mostrarPersona(PersonaPtr persona);

/**
 * @brief Muestra el contenido de un puntero a datos de tipo Persona.
 * @pre dato es un puntero válido a Persona.
 * @post Imprime el contenido de la persona en la salida estándar.
 */
void mostrarPersonaDatoPtr(void * dato);

/**
 * @brief Libera la memoria ocupada por una persona.
 * @pre persona no es NULL.
 * @post Libera la memoria asociada a la persona.
 */
void liberarPersona(PersonaPtr persona);

/**
 * @brief Obtiene el DNI de una persona.
 * @pre persona no es NULL.
 * @post Devuelve el DNI de la persona.
 */
int getDni(PersonaPtr persona);

/**
 * @brief Obtiene el nombre de una persona.
 * @pre persona no es NULL.
 * @post Devuelve un puntero a la cadena del nombre de la persona.
 */
char* getNombre(PersonaPtr persona);

/**
 * @brief Establece un nuevo DNI para una persona.
 * @pre persona no es NULL.
 * @post Actualiza el DNI de la persona con el nuevo valor.
 */
void setDni(PersonaPtr persona, int nuevoDni);

/**
 * @brief Establece un nuevo nombre para una persona.
 * @pre persona no es NULL y nuevoNombre es una cadena válida.
 * @post Actualiza el nombre de la persona con la nueva cadena proporcionada.
 */
void setNombre(PersonaPtr persona, char* nuevoNombre);

#endif // PERSONA_H_INCLUDED
