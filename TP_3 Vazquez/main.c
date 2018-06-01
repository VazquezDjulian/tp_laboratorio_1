#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    eMovie peliculas[TA];
    char seguir='s';
    char todoOk='n';
    int opcion;
    int opcionAux;
    char opcionVal[500];

     cargaArchivo(peliculas);
     printf("Cierre el programa un vez termino de Agregar/Borrar/Modificar/etc...\n\n");

    while(seguir=='s')
    {
         while(todoOk=='n')
         {
            printf("**MENU PRINCIPAL**\n\n");
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Mostrar todo\n");
            printf("6- Salir\n");

            scanf("%s",&opcionVal);
            if(atoi(opcionVal) != 0)
            {
                opcionAux = atof(opcionVal);
                todoOk='s';
            }
            else
            {
                printf("La opcion no es correcta, reingrese\n");
                system("pause");
                system("cls");
            }
        }

        todoOk='n';

        if(opcionAux < 1 || opcionAux > 6)
        {
            opcion = opcionAux;
            printf("Opcion no valida\n");
            printf("Vuelva a ingresar\n");
            scanf("%d",&opcionAux);
        }
        if(opcionAux >= 1 || opcionAux <= 6)
        {
           opcion = opcionAux;
        }
            switch(opcion)
            {
                case 1:
                    system("cls");
                    if(validaIngresoDatos(peliculas) >= 0)
                    {
                        guardarBinario(peliculas);
                    }
                    else
                    {
                        printf("No se realizo la carga.\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    bajaLogica(peliculas);
                    guardarBinario(peliculas);
                    system("pause");
                    system("cls");
                    break;
                 case 3:
                    system("cls");
                    if(modificar(peliculas) > 0)
                    {
                        guardarBinario(peliculas);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    generarHtml(peliculas);
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    mostrarTodo(peliculas);
                    printf("\n");
                    system("pause");
                    system("cls");
                   break;
                case 6:
                    seguir = 'n';
                    break;
            }

    }

    return 0;
}
