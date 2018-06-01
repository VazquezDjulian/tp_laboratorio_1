#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define TAMP 20


int main()
{
    int seguir =1 ;
    char opcion;
    int opcionInt;
    int flag = 0;
    ePersona personas[TAMP];

    inicializarStruct(personas,TAMP);

    do
    {
        printf("--GESTION DE PERSONAS--\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Listar en orden de carga\n\n");
        printf("6- Salir\n");

        fflush(stdin);
        scanf("%c",&opcion);



        switch(opcion)
        {
            case '1':
                alta(personas,TAMP);
                system("pause");
                system("cls");
                break;

            case '2':
                Baja(personas,TAMP);
                system("pause");
                system("cls");
                break;

            case '3':
                listaOrdenada(personas,TAMP);
                break;

            case '4':
                graficoPorEdades(personas,TAMP);
                system("pause");
                system("cls");
                break;

            case '5':
                mostrarPersonas(personas,TAMP);
                system("pause");
                system("cls");
                break;

            case '6':
                seguir = 0;
                break;

            default:
                system("cls");
                printf("Opcion no valida\n");
                break;
        }
    }while(seguir == 1);

    return 0;
}
