#ifndef LISTA_H
#define LISTA_H

#include "persona.h"

typedef struct Nodo {
    Persona* persona;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
    int tamanio;
} Lista;

Lista* crear_lista(void);
void destruir_lista(Lista* lista);
int insertar_al_final(Lista* lista, Persona* persona);
void imprimir_lista(const Lista* lista);
Lista* copiar_lista(const Lista* original);
int esta_vacia_lista(const Lista* lista);

#endif