#include "RegP.h"

void guardar_porteros(portero *p);
void cargar_porteros(portero **p);
void listar_p(portero *p);
int buscar_portero(portero *p,char *nombre,char *titulo);
void introducir_portero(portero **p,int i);
void seleccionar_portero(portero *p);
void estadisticasp(portero *p,int i);
void modificar_estadisticas_p(portero *p,int nporteros);
void eliminar_portero(portero **p);

void guardar_porteros(portero *p){
	FILE *f;
	f=fopen("Porteros.txt","w+");
	int i;
	for(i=0;i<nporteros;i++){
		fprintf(f,"%s-%s-",p[i].nombre,p[i].titulo);
		fprintf(f, "%d-%d-",p[i].parada[0],p[i].parada[1]);
		fprintf(f, "%d-%d-%d\n",p[i].fisico[0],p[i].fisico[1],p[i].fisico[2]);
	}
	fclose(f);
}

void cargar_porteros(portero **p){
	nporteros=0;
	FILE *f;
	f=fopen("Porteros.txt","r+");
	char *cadena;
	char *delim="-";
	char *ptr;
	int i;
	while((fgets(cadena,100,f))!=NULL){

		*p=(portero* )realloc(*p,(nporteros+1)*sizeof(portero));
		nporteros++;
		ptr=strtok(cadena,delim);
		strcpy((*p)[nporteros-1].nombre,ptr);
		ptr=strtok(NULL,delim);
		strcpy((*p)[nporteros-1].titulo,ptr);
		for(i=0;i<2;i++){
			ptr=strtok(NULL,delim);
			(*p)[nporteros-1].parada[i]=atoi(ptr);
		}
		for(i=0;i<3;i++){
			ptr=strtok(NULL,delim);
			(*p)[nporteros-1].fisico[i]=atoi(ptr);
		}
	}
	fclose(f);
}

void listar_p(portero *p){
	int i;
	system("cls");
	printf("\n     |    Nombre    |    Titulo    |  Parada |  Fisico  | \n");
	for(i=0;i<nporteros;i++){

		printf("   %d.  %s  -  %s  -",i+1,p[i].nombre,p[i].titulo);
		printf("  %d  -",p[i].parada[0]+p[i].parada[1]);
		printf("  %d\n",p[i].fisico[0]+p[i].fisico[1]+p[i].fisico[2]);
	}
	printf("\n");
}

int buscar_portero(portero *p,char *nombre,char *titulo){
	int i;
	for(i=0;i<njugadores;i++){
		if(strcmp(p[i].nombre,nombre)==0){
			if(strcmp(p[i].titulo,titulo)==0) return i;
		}
	}
	return -1;
}

void introducir_portero(portero **p,int i){
	int k;
	char cadena[50];
	*p=(portero*)realloc(*p,(nporteros+1)*sizeof(portero));
	nporteros++;
	printf("Introduce el nombre: ");
	fflush(stdin);
	fgets(cadena,50,stdin);
	fixstring(cadena);
	strcpy((*p)[i].nombre,cadena);
	printf("Introduce el titulo: ");
	fflush(stdin);
	fgets(cadena,50,stdin);
	fixstring(cadena);
	strcpy((*p)[i].titulo,cadena);
	for(k=0;k<2;k++){
		(*p)[i].parada[k]=0;
	}
	for(k=0;k<3;k++){
		(*p)[i].fisico[k]=0;
	}
}

void seleccionar_portero(portero *p){
	char nombre[50],titulo[50];
	int i,opc;
	listar_p(p);
	printf(" Nombre del jugador: ");
	fflush(stdin);
	fgets(nombre,50,stdin);
	fixstring(nombre);
	printf(" Titulo del jugador: ");
	fflush(stdin);
	fgets(titulo,50,stdin);
	fixstring(titulo);
	i=buscar_portero(p,nombre,titulo);
	if(i!=-1){

		do{
			opc=-1;
			estadisticasp(p,i);
			printf(" 1.Modificar Estadisticas \n 0.Salir\n Opcion: ");
			scanf("%d",&opc);
			if(opc==1){
				modificar_estadisticas_p(p,i);
			}
		}while(opc!=0);
	}
	else printf("Jugador no encontrado\n");
}

void estadisticasp(portero *p,int i){
	system("cls");
	printf("\n Nombre: %s\n",p[i].nombre);
	printf(" Titulo: %s\n",p[i].titulo);
	printf(" Parada\n");
	printf("  1.Punio: %i - %i\n",p[i].parada[0],p[i].parada[0]+((p[i].fisico[0]+p[i].fisico[1])/4));
	printf("  2.Blocaje: %i - %i\n",p[i].parada[1],p[i].parada[1]+((p[i].fisico[2]+p[i].fisico[1])/4));
	printf(" Fisico\n");
	printf("  3.Rapidez: %i\n",p[i].fisico[0]);
	printf("  4.Potencia: %i\n",p[i].fisico[1]);
	printf("  5.Tecnica: %i\n\n",p[i].fisico[2]);
}

void modificar_estadisticas_p(portero *p,int nporteros){
	int op,aux;
	do{
		do{
			estadisticasp(p,nporteros);
			printf(" 0.Salir\n Opcion: ");
			scanf("%d",&op);
		}while(op<1&&op>5);
		if(op!=0){
			printf(" Introduce valor: ");
			scanf("%d",&aux);
			switch (op){
				case 1: p[nporteros].parada[0]=aux;break;
				case 2: p[nporteros].parada[1]=aux;break;
				case 3: p[nporteros].fisico[0]=aux;break;
				case 4: p[nporteros].fisico[1]=aux;break;
				case 5: p[nporteros].fisico[2]=aux;break;
			}
		}
	}while(op!=0);
}

void eliminar_portero(portero **p){
	int iportero,i;
	char nombre[50];
	char titulo[50];
	char opc;
	do{
		listar_p(*p);
		printf(" Nombre del jugador: ");
		fflush(stdin);
		fgets(nombre,50,stdin);
		fixstring(nombre);
		printf(" Titulo del jugador: ");
		fflush(stdin);
		fgets(titulo,50,stdin);
		fixstring(titulo);
		iportero=buscar_portero(*p,nombre,titulo);
		if(iportero!=-1){
			listar_p(*p);
			printf("%d. %s - %s\n",iportero+1,(*p)[iportero].nombre,(*p)[iportero].titulo);
			printf("Jugador a eliminar? (s/n): ");
			scanf("%c",&opc);
			if(opc=='s'){
				strcpy((*p)[iportero].nombre,(*p)[nporteros-1].nombre);
				strcpy((*p)[iportero].titulo,(*p)[nporteros-1].titulo);
				for(i=0;i<2;i++){
					(*p)[iportero].parada[i]=(*p)[nporteros-1].parada[i];
				}
				for(i=0;i<3;i++){
					(*p)[iportero].fisico[i]=(*p)[nporteros-1].fisico[i];
				}
				*p=(portero *)realloc((*p),(nporteros-1)*sizeof(portero));
				nporteros--;
			}
		}
		else{
			printf("Portero no encontrado\n Salir? (s/n): ");
			scanf("%c",&opc);
		}

	}while(opc!='s');
}