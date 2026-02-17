#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

Lista* crear_lista(void) {
    Lista* nueva = (Lista*)malloc(sizeof(Lista));
    if (!nueva) {
        fprintf(stderr, "Error: No se pudo asignar memoria para Lista\n");
        return NULL;
    }
    
    nueva->cabeza = NULL;
    nueva->tamanio = 0;
    return nueva;
}

void destruir_lista(Lista* lista) {
    if (!lista) {
        fprintf(stderr, "Advertencia: Intento de destruir lista NULL\n");
        return;
    }
    
    Nodo* actual = lista->cabeza;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        liberar_vehiculo(actual->vehiculo);
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
}

void insertar(Lista* lista, Vehiculo* vehiculo){
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) {
        fprintf(stderr, "Error: No se pudo asignar memoria para Nodo\n");
        return ;
    }
    
    // Insertar al inicio
    nuevo_nodo->vehiculo = vehiculo;
    nuevo_nodo->siguiente = lista->cabeza; 
    lista->cabeza = nuevo_nodo;
}

void recorrer(Lista* lista){
    Nodo* nodo_actual = lista->cabeza; 
    
    while(nodo_actual->siguiente != NULL){
        imprimir_vehiculo(nodo_actual->vehiculo);
        nodo_actual = nodo_actual->siguiente;
    }
}