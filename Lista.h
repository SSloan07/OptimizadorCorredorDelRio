#ifndef LISTA_H
#define LISTA_H

#include "Vehiculo.h"

typedef struct Nodo {
    Vehiculo* vehiculo;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
    int tamanio;
} Lista;

Lista* crear_lista(void);
void destruir_lista(Lista* lista);
void insertar(Lista* lista, Vehiculo* vehiculo);

#endif