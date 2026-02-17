#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include <time.h> // Para medir el tiempo

int main (){
    clock_t inicio, fin;
    double tiempo_total;
    int n; 
    int i = 0; 
    Lista* lista = crear_lista();
    printf("Estimado usuario. Bienvenido a un sistema de Camaras de Medellín\nPor Favor ingrese el numero de vehiculos que quiere generar:\t");
    scanf("%d", &n);
    inicio = clock();
    while(i<n){
        insertar(lista, generar_vehiculo_aleatorio());
        i++;
    }
    fin = clock();   
    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de generacion: %f segundos\n", tiempo_total);

    return 0; 
}