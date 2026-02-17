#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Vehiculo.h"
#define NUM_ESTACIONES 13
#define NUM_TIPO_VEHICULOS 6
#define NUM_DIA_SUMAANA 7

const char* nombresEstaciones[] =  {
    "Niquia", "Madera", "Acevedo", "Tricentenario", 
    "Caribe", "Industriales", "Poblado", "Aguacatala", 
    "Ayurá", "Envigado", "Itagüí", "Sabaneta", "La Estrella"
};

const char* tipoVehiculosArreglo[] = {
    "EMERGENCIA",
    "MEDICO",
    "PASAJEROS",
    "CARGA",
    "TAXI",
    "PARTICULAR"
};

const char* diaSemanaArreglo[] = {
    "LUNES",
    "MARTES",
    "MIERCOLES",
    "JUEVES",
    "VIERNES",
    "SABADO",
    "DOMINGO"
};


void generar_placa(char *placa) {
    // Generar 3 letras
    for (int i = 0; i < 3; i++) {
        placa[i] = 'A' + rand() % 26; // Con esto se generan letras desde la A hasta la Z, tomamos su codigo ASCII(65) para eso
    }

    // Generar número entre 0 y 999
    int numero = rand() % 1000;

    // Convertir a 3 dígitos con ceros a la izquierda
    sprintf(&placa[3], "%03d", numero);
}


// Definimos función para crear vehiculos aleatorios
Vehiculo* generar_vehiculo_aleatorio() {

    Vehiculo* vehiculo = malloc(sizeof(Vehiculo));
    if (vehiculo == NULL) return NULL;

    
    generar_placa(vehiculo->placa);

    vehiculo->tipo = rand() % 6;  // porque hay 6 valores en TipoVehiculo

    vehiculo->sentido = rand() % 2;

    int hora = rand() % 24;
    int minutos = rand() % 30; // Tiempo menor a 30 minutos
    vehiculo->hora_militar = hora * 100 + minutos;

    vehiculo->dia = rand() % 7;

    vehiculo->tiempo_tramo = 1 + (rand() % 6000) / 100.0f;

    strcpy(vehiculo->estacion, nombresEstaciones[rand() % NUM_ESTACIONES]);

    return vehiculo;
}

void imprimir_vehiculo(const Vehiculo* vehiculo) {

    if (vehiculo == NULL) {
        printf("Vehiculo NULL\n");
        return;
    }

    printf("------------------------");
    printf("Placa: %s\n", vehiculo->placa);
    printf("Tipo: %s\n", tipoVehiculosArreglo[vehiculo->tipo]);
    printf("Sentido: %s\n", vehiculo->sentido == 0 ? "Sur-Norte" : "Norte-Sur");
    printf("Hora: %04d\n", vehiculo->hora_militar);
    printf("Dia: %s\n", diaSemanaArreglo[vehiculo->dia]);
    printf("Tiempo tramo: %.2f minutos\n", vehiculo->tiempo_tramo);
    printf("Estacion: %s\n", vehiculo->estacion);
    printf("------------------------");
}

void liberar_vehiculo(Vehiculo* vehiculo) {
    free(vehiculo);
}