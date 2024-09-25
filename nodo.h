#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * NodoPtr;

/**
 * @brief Crea un nuevo nodo
 * @pre Ninguna
 * @post Retorna un nuevo nodo con el dato y siguiente especificados
 */
NodoPtr crearNodo(int dato, NodoPtr siguiente);

/**
 * @brief Muestra el contenido de un nodo
 * @pre nodo no es NULL
 * @post Imprime el contenido del nodo en la salida estándar
 */
void mostrarNodo(NodoPtr nodo);

/**
 * @brief Libera la memoria ocupada por un nodo
 * @pre nodo no es NULL
 * @post La memoria ocupada por el nodo es liberada
 */
void liberarNodo(NodoPtr nodo);

// GETTERS Y SETTERS

/**
 * @brief Obtiene el dato almacenado en el nodo
 * @pre nodo no es NULL
 * @post Retorna el dato almacenado en el nodo
 */
int getDato(NodoPtr nodo);

/**
 * @brief Obtiene el puntero al siguiente nodo
 * @pre nodo no es NULL
 * @post Retorna el puntero al siguiente nodo
 */
NodoPtr getSiguiente(NodoPtr nodo);

/**
 * @brief Establece un nuevo dato en el nodo
 * @pre nodo no es NULL
 * @post El dato del nodo es actualizado con el nuevo valor
 */
void setDato(NodoPtr nodo, int nuevoDato);

/**
 * @brief Establece un nuevo nodo siguiente
 * @pre nodo no es NULL
 * @post El puntero al siguiente nodo es actualizado
 */
void setSiguiente(NodoPtr nodo, NodoPtr nuevoNodo);

#endif // NODO_H_INCLUDED
