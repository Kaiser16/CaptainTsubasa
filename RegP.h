#ifndef RegP
#define RegP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RegCT.h"
#include "RegJ.h"

typedef struct {
	char nombre[50];
	char titulo[50];
	int parada[2];
	int fisico[3];

}portero;

int nporteros;

portero *p;

void guardar_porteros(portero *p);

void cargar_porteros(portero **p);

void listar_p(portero *p);

void seleccionar_portero(portero *p);

void introducir_portero(portero **p,int i);

void eliminar_portero(portero **p);

#endif