#ifndef VEHICULO_H 
#define VEHICULO_H

typedef enum { EMERGENCIA, MEDICO, PASAJEROS, CARGA, TAXI, PARTICULAR } TipoVehiculo;

typedef enum { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO } DiaSemana;

typedef struct {
    char placa[7];
    TipoVehiculo tipo;
    int sentido;       // 0: Sur-Norte, 1: Norte-Sur
    int hora_militar;  // Ej: 0730, 1845
    DiaSemana dia;
    float tiempo_tramo; // Tiempo registrado en minutos
    char estacion[20];
} Vehiculo;

// Para crear la lista de estaciones 
extern const char* nombresEstaciones[];
extern const char* tipoVehiculosArreglo[];
extern const char* diaSemanaArreglo[];

// Funciones
Vehiculo* crear_vehiculo(const char* placa, TipoVehiculo tipo, int sentido, int hora_militar, DiaSemana dia, float tiempoTramo, const char* estacion);

Vehiculo* generar_vehiculo_aleatorio(); 

void generar_placa(char *placa);

void imprimir_vehiculo(const Vehiculo* vehiculo); 

void liberar_vehiculo(Vehiculo* vehiculo);



#endif