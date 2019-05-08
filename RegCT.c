#include "RegCT.h"

void fixstring(char *a);
void menu();
void menu_jugadores(jugador **j);
void menu_porteros(portero **p);

void menu(){
    int op,i;
    i=0;
    cargar_jugadores(&j);
    cargar_porteros(&p);
    do{
        do{
            system("cls");
            printf("\n\n");
			printf("     TTTTTTTTTTTTTTT     SSSSSSSSSSS  UU      UU  BB              AAAAAAAAAAA         SSSSSSSSSSS   AAAAAAAAAAA\n");
			printf("    TTTTTTTTTTTTTTT    SSSS    SSSS   UU      UU  BB                        AA       SSSS    SSSS             AA\n");
			printf("       TTTTTTT        SSSS            UU      UU  BBBBBBBBBB      AAAAAAAAAAAA      SSSS            AAAAAAAAAAAA\n");
			printf("       TTTTTT        SSSSSSSSSSSSS    UU      UU  BB       BB    AA          AA    SSSSSSSSSSSSS   AA          AA\n");
			printf("      TTTTTTT                SSSS     UU      UU  BB       BB    AA          AA            SSSS    AA          AA\n");
			printf("      TTTTTT        SSSS    SSSS      UUU    UUU  BB       BB    AA          AA   SSSS    SSSS     AA          AA\n");
			printf("     TTTTTTT         SSSSSSSSSS         UUUUUU    BBBBBBBBBB      AAAAAAAAAAAAAA   SSSSSSSSSS       AAAAAAAAAAAAAA\n");
			
            printf("\n\t     ||INICIO||\n\n\t 1.Listar jugadores\n\t 2.Lista porteros \n\t 0.Salir\n\n\t Opcion: ");
            scanf("%i",&op);
        }while(op<0&&op>2);
        switch(op){
            case 1: menu_jugadores(&j);break;
            case 2: menu_porteros(&p);break;
        }
    }while (op!=0);
    guardar_jugadores(j);
    guardar_porteros(p);
}

void fixstring(char *a){
    a[strlen(a)-1]='\0';
}

void menu_jugadores(jugador **j){
    int op;
    do{
        do{
            op=-1;
            listar_j((*j));
            printf(" 1.Seleccionar jugador\n 2.Introducir jugador\n 3.Eliminar jugador\n 4.Comparar Jugadores\n 0.Salir\n\n Opcion: ");
            scanf("%d",&op);
        }while(op<1&&op>4);
        switch(op){
            case 1: seleccionar_jugador((*j));break;
            case 2: listar_j((*j));introducir_jugador(&(*j),njugadores);break;
            case 3: eliminar_jugador(&(*j));break;
            case 4: comparar_jugadores(*j);break;
        }
        if(op==1){

        }
    }while(op!=0);
}

void menu_porteros(portero **p){
    int op;
    do{
        do{
            op=-1;
            listar_p((*p));
            printf(" 1.Seleccionar portero\n 2.Introducir portero\n 3.Eliminar portero\n 0.Salir\n\n Opcion: ");
            scanf("%d",&op);
        }while(op<1&&op>3);
        switch(op){
            case 1: seleccionar_portero((*p));break;
            case 2: listar_p((*p));introducir_portero(&(*p),nporteros);break;
            case 3: eliminar_portero(&(*p));break;
        }
        if(op==1){

        }
    }while(op!=0);
}