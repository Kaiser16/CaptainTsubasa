#ifndef RegJ
#define RegJ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RegP.h"
#include "RegCT.h"

typedef struct{
    char nombre[50];
    char titulo[50];
    int ataque[3];
    int defensa[3];
    int fisico[3];
}jugador;

int njugadores;

jugador *j;

void guardar_jugadores(jugador *j);

void cargar_jugadores(jugador **j);

void listar_j(jugador *j);

void seleccionar_jugador(jugador *j);

void introducir_jugador(jugador **j,int i);

void eliminar_jugador(jugador **j);

void comparar_jugadores(jugador *j);

#endif