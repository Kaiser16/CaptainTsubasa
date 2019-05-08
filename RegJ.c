#include "RegJ.h"

void guardar_jugadores(jugador *j);
void cargar_jugadores(jugador **j);
void listar_j(jugador *j);
int buscar_jugador(jugador *j,char *nombre,char *titulo);
void introducir_jugador(jugador **j,int i);
void seleccionar_jugador(jugador *j);
void estadisticasj(jugador *j,int i);
void modificar_estadisticas_j(jugador *j,int njugador);
void eliminar_jugador(jugador **j);
void comparar_jugadores(jugador *j);
void comparar_estadisticas_j(jugador *j,int j1,int j2);

void guardar_jugadores(jugador *j){
	FILE *f;
	f=fopen("Jugadores.txt","w+");
	int i;
	for(i=0;i<njugadores;i++){
		fprintf(f,"%s-%s-",j[i].nombre,j[i].titulo);
		fprintf(f, "%d-%d-%d-",j[i].ataque[0],j[i].ataque[1],j[i].ataque[2]);
		fprintf(f, "%d-%d-%d-",j[i].defensa[0],j[i].defensa[1],j[i].defensa[2]);
		fprintf(f, "%d-%d-%d\n",j[i].fisico[0],j[i].fisico[1],j[i].fisico[2]);
	}
	fclose(f);
}

void cargar_jugadores(jugador **j){
    njugadores=0;
	FILE *f;
	f=fopen("Jugadores.txt","r+");
	char *cadena;
	char *delim="-";
	char *ptr;
	int i;
	while((fgets(cadena,100,f))!=NULL){	
		*j=(jugador* )realloc(*j,(njugadores+1)*sizeof(jugador));
		njugadores++;
		ptr=strtok(cadena,delim);
		strcpy((*j)[njugadores-1].nombre,ptr);
		ptr=strtok(NULL,delim);
		strcpy((*j)[njugadores-1].titulo,ptr);
		for(i=0;i<3;i++){
			ptr=strtok(NULL,delim);
			(*j)[njugadores-1].ataque[i]=atoi(ptr);
		}
		for(i=0;i<3;i++){
			ptr=strtok(NULL,delim);
			(*j)[njugadores-1].defensa[i]=atoi(ptr);
		}
		for(i=0;i<3;i++){
			ptr=strtok(NULL,delim);
			(*j)[njugadores-1].fisico[i]=atoi(ptr);
		}
	}
	fclose(f);
}

void introducir_jugador(jugador **j,int i){
	int k;
	char cadena[50];
	listar_j(*j);
	*j=(jugador*)realloc(*j,(njugadores+1)*sizeof(jugador));
	njugadores++;
	printf("Introduce el nombre: ");
	fflush(stdin);
	fgets(cadena,50,stdin);
	fixstring(cadena);
	strcpy((*j)[i].nombre,cadena);
	printf("Introduce el titulo: ");
	fflush(stdin);
	fgets(cadena,50,stdin);
	fixstring(cadena);
	strcpy((*j)[i].titulo,cadena);
	for(k=0;k<3;k++){
		(*j)[i].ataque[k]=0;
	}
	for(k=0;k<3;k++){
		(*j)[i].defensa[k]=0;
	}
	for(k=0;k<3;k++){
		(*j)[i].fisico[k]=0;
	}
}

void estadisticasj(jugador *j,int i){
	system("cls");
	printf("\n Nombre: %s\n",j[i].nombre);
	printf(" Titulo: %s\n",j[i].titulo);
	printf(" Ataque\n");
	printf("  1.Regate: %i - %i\n",j[i].ataque[0],j[i].ataque[0]+(j[i].fisico[0]/2));
	printf("  2.Remate: %i - %i\n",j[i].ataque[1],j[i].ataque[1]+(j[i].fisico[1]/2));
	printf("  3.Pase: %i - %i\n",j[i].ataque[2],j[i].ataque[2]+(j[i].fisico[2]/2));
	printf(" Defensa\n");
	printf("  4.Entrada: %i - %i\n",j[i].defensa[0],j[i].defensa[0]+(j[i].fisico[0]/2));
	printf("  5.Bloqueo: %i - %i\n",j[i].defensa[1],j[i].defensa[1]+(j[i].fisico[1]/2));
	printf("  6.Intercepcion: %i - %i\n",j[i].defensa[2],j[i].defensa[2]+(j[i].fisico[2]/2));
	printf(" Fisico\n");
	printf("  7.Rapidez: %i\n",j[i].fisico[0]);
	printf("  8.Potencia: %i\n",j[i].fisico[1]);
	printf("  9.Tecnica: %i\n\n",j[i].fisico[2]);
}

void modificar_estadisticas_j(jugador *j,int njugador){
	int op,aux;
	do{
		do{
			estadisticasj(j,njugador);
			printf(" 0.Salir\n Opcion: ");
			scanf("%d",&op);
		}while(op<=0&&op>10);
		if(op!=0){
			printf(" Introduce valor: ");
			scanf("%d",&aux);
			switch (op){
				case 1: j[njugador].ataque[0]=aux;break;
				case 2: j[njugador].ataque[1]=aux;break;
				case 3: j[njugador].ataque[2]=aux;break;
				case 4: j[njugador].defensa[0]=aux;break;
				case 5: j[njugador].defensa[1]=aux;break;
				case 6: j[njugador].defensa[2]=aux;break;
				case 7: j[njugador].fisico[0]=aux;break;
				case 8: j[njugador].fisico[1]=aux;break;
				case 9: j[njugador].fisico[2]=aux;break;
			}
		}
	}while(op!=0);
}

int buscar_jugador(jugador *j,char *nombre,char *titulo){
	int i;
	for(i=0;i<njugadores;i++){
		if(strcmp(j[i].nombre,nombre)==0){
			if(strcmp(j[i].titulo,titulo)==0) return i;
		}
	}
	return -1;
}

void listar_j(jugador *j){
	int i;
	system("cls");
	printf("\n     |    Nombre    |    Titulo    |  Ataque  |  Defensa  |  Fisico  | \n");
	for(i=0;i<njugadores;i++){

		printf("   %d.  %s  -  %s  -",i+1,j[i].nombre,j[i].titulo);
		printf("  %d  -",(j[i].ataque[0]+j[i].ataque[1]+j[i].ataque[2]));
		printf("  %d  -",(j[i].defensa[0]+j[i].defensa[1]+j[i].defensa[2]));
		printf("  %d\n",(j[i].fisico[0]+j[i].fisico[1]+j[i].fisico[2]));
	}
	printf("\n");
}

void eliminar_jugador(jugador **j){
	int ijugador,op,i;
	char nombrej[50];
	char tituloj[50];
	char opc,opc2;
	do{
		listar_j(*j);
		printf(" Nombre del jugador: ");
		fflush(stdin);
		fgets(nombrej,50,stdin);
		fixstring(nombrej);
		printf(" Titulo del jugador: ");
		fflush(stdin);
		fgets(tituloj,50,stdin);
		fixstring(tituloj);
		ijugador=buscar_jugador(*j,nombrej,tituloj);
		if(ijugador!=-1){
			listar_j(*j);
			printf("%d. %s - %s\n",ijugador+1,(*j)[ijugador].nombre,(*j)[ijugador].titulo);
			printf(" Jugador a eliminar? (s/n): ");
			scanf("%c",&opc);
			if(opc=='s'){
				strcpy((*j)[ijugador].nombre,(*j)[njugadores-1].nombre);
				strcpy((*j)[ijugador].titulo,(*j)[njugadores-1].titulo);
				for(i=0;i<3;i++){
					(*j)[ijugador].ataque[i]=(*j)[njugadores-1].ataque[i];
				}
				for(i=0;i<3;i++){
					(*j)[ijugador].defensa[i]=(*j)[njugadores-1].defensa[i];
				}
				for(i=0;i<3;i++){
					(*j)[ijugador].fisico[i]=(*j)[njugadores-1].fisico[i];
				}
				*j=(jugador *)realloc((*j),(njugadores-1)*sizeof(jugador));
				njugadores--;
			}
		}
		else{
			printf("Jugador no encontrado\n Salir? (s/n): ");
			scanf("%c",&opc);
		}

	}while(opc!='s');
}

void seleccionar_jugador(jugador *j){
	char nombre[50],titulo[50];
	int i,opc;
	listar_j(j);
	printf(" Nombre del jugador: ");
	fflush(stdin);
	fgets(nombre,50,stdin);
	fixstring(nombre);
	printf(" Titulo del jugador: ");
	fflush(stdin);
	fgets(titulo,50,stdin);
	fixstring(titulo);
	i=buscar_jugador(j,nombre,titulo);
	if(i!=-1){

		do{
			opc=-1;
			estadisticasj(j,i);
			printf(" 1.Modificar Estadisticas \n 0.Salir\n Opcion: ");
			scanf("%d",&opc);
			if(opc==1){
				modificar_estadisticas_j(j,i);
			}
		}while(opc!=0);
	}
	else printf("Jugador no encontrado\n");
}

void comparar_jugadores(jugador *j){
	char *nombre;
	char *titulo;
	int j1,j2;
	printf("Introduce nombre jugador 1: ");
	fflush(stdin);
	fgets(nombre,50,stdin);
	fixstring(nombre);
	printf("Introduce titulo jugador 1: ");
	fflush(stdin);
	fgets(titulo,50,stdin);
	fixstring(titulo);
	j1=buscar_jugador(j,nombre,titulo);
	printf("Introduce nombre jugador 2: ");
	fflush(stdin);
	fgets(nombre,50,stdin);
	fixstring(nombre);
	printf("Introduce titulo jugador 2: ");
	fflush(stdin);
	fgets(titulo,50,stdin);
	fixstring(titulo);
	j2=buscar_jugador(j,nombre,titulo);
	comparar_estadisticas_j(j,j1,j2);
}

void comparar_estadisticas_j(jugador *j,int j1,int j2){
	system("cls");
	printf("\n Nombre: %s - %s\n",j[j1].nombre,j[j2].nombre);
	printf(" Titulo:   %s - %s\n",j[j1].titulo,j[j2].titulo);
	printf(" Ataque\n");
	printf("  1.Regate:       %i - %i\n",j[j1].ataque[0]-j[j2].ataque[0],j[j1].ataque[0]+(j[j2].fisico[0]/2)-j[j1].ataque[0]+(j[j2].fisico[0]/2));
	printf("  2.Remate:       %i - %i\n",j[j1].ataque[1]-j[j2].ataque[1],j[j1].ataque[1]+(j[j2].fisico[1]/2)-j[j1].ataque[1]+(j[j2].fisico[1]/2));
	printf("  3.Pase:         %i - %i\n",j[j1].ataque[2]-j[j2].ataque[2],j[j1].ataque[2]+(j[j1].fisico[2]/2)-j[j2].ataque[2]+(j[j2].fisico[2]/2));
	printf(" Defensa\n");
	printf("  4.Entrada:      %i - %i\n",j[j1].defensa[0]-j[j2].defensa[0],j[j1].defensa[0]+(j[j1].fisico[0]/2)-j[j2].defensa[0]+(j[j2].fisico[0]/2));
	printf("  5.Bloqueo:      %i - %i\n",j[j1].defensa[1]-j[j2].defensa[1],j[j1].defensa[1]+(j[j1].fisico[1]/2)-j[j2].defensa[1]+(j[j2].fisico[1]/2));
	printf("  6.Intercepcion: %i - %i\n",j[j1].defensa[2]-j[j2].defensa[2],j[j1].defensa[2]+(j[j1].fisico[2]/2)-j[j2].defensa[2]+(j[j2].fisico[2]/2));
	printf(" Fisico\n");
	printf("  7.Rapidez:      %i\n",j[j1].fisico[0]-j[j2].fisico[0]);
	printf("  8.Potencia:     %i\n",j[j1].fisico[1]-j[j2].fisico[1]);
	printf("  9.Tecnica:      %i\n\n",j[j1].fisico[2]-j[j2].fisico[2]);
	system("pause");
}