#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define TAMP 20

void inicializarStruct(ePersona vec[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1; //esta vacio? SI
    }
}

int buscarLibre(ePersona vec[], int tam)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)//si esta vacio el elemento, lo devuelvo para cargar sobre el
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarPersona(ePersona vec[], int tam, int dni)
{
    int i;
    int esta = -1;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].dni == dni)
        {
            esta = i; //me devuelva la posicion si lo encuenta
            break;
        }
    }
    return esta; // me reotorna -1 si no hay nada

}

int ValueInt(char aux[25])
{
    int flag = 0;
    if(atoi(aux) != 0)
    {
       flag = 1;
       return flag;
    }
    else
    {
        printf("Debe ingresar un numero\n");
        return flag;
    }
}

void alta(ePersona vec[], int tam)
{
    int posi;
    int esta;
    ePersona persona;
    char dniChar[25];
    int dniInt;
    char nombreAux[150];
    int longitudNombre;
    char secChar[5];
    char edadChar[25];
    int edadInt;

    system("cls");
    printf("--ALTA DE PERSONA--\n");
    posi = buscarLibre(vec,tam);
    if(posi == -1)
    {
        printf("No hay espacio en sistema\n");
    }
    else
    {
        do
        {
            printf("Ingrese el DNI: ");
             fflush(stdin);
            scanf("%s",&dniChar);
        }while(ValueInt(dniChar) != 1);
        dniInt = atof(dniChar); //validando que se ingresen numeros y convirtiendolos


        esta = buscarPersona(vec,tam,dniInt); //validamos que no este ese legajo numerico ya cargado
        if(esta != -1)//si ya esta cargado
        {
            printf("Ese DNI esta cargado y pertenece a : \n\n");
            mostarUnaPersona(vec,esta);
        }
        else
        {
            persona.dni = dniInt;
            persona.isEmpty = 0; //esta vacio? falso, ya hay algo

            do
            {
                printf("Ingrese Nombre: ");
                fflush(stdin);
                //scanf("%[^\n]",nombreAux);
                gets(nombreAux);
                longitudNombre = strlen(nombreAux);
                }while(longitudNombre>=49);// lo que queremos es que se pida siempre que supere nuestro maximo de 50 en estructura

            strcpy(persona.nombre,nombreAux);

            do
            {
                printf("Ingrese Edad: ");
                fflush(stdin);
                scanf("%s",&edadChar);
            }while(ValueInt(edadChar) != 1);
            edadInt = atof(edadChar);
            persona.edad = edadInt;

            vec[posi] = persona;
        }
    }
}

void mostarUnaPersona(ePersona vec[],int pos)
{
    printf("DNI\t\t\t NOMBRE\t\t EDAD\n\n");
    printf("%d\t\t %s\t\t\t %d\n",vec[pos].dni,vec[pos].nombre,vec[pos].edad);
}

void Baja(ePersona vec[],int tam)
{
    char dniAux[20];
    int dni;
    int esta;
    char confirmar;

    printf("--BAJA DE EMPLEADO--\n");
    mostrarPersonas(vec,tam);
    printf("\n");

    do
        {
            printf("Ingrese el DNI correspondiente a dar de baja\n");
            fflush(stdin);
            scanf("%s",&dniAux);
        }while(ValueInt(dniAux) != 1);
        dni = atof(dniAux);

        esta = buscarPersona(vec,tam,dni);
        if(esta == -1)//si NO esta cargado
        {
            printf("Ese no esta en sistema\n");
        }
        else
        {
            printf("El legajo pertenece a : \n");
            mostarUnaPersona(vec,esta);

            do
            {
                printf("Confirmar baja de la persona [S || N]\n");
                fflush(stdin);
                scanf("%c",&confirmar);
                confirmar = tolower(confirmar);
            }while(confirmar == 'n' && confirmar == 's'); //por que no OR

            if(confirmar == 's')
            {
                vec[esta].isEmpty = 1;
                printf("Baja realizada\n");
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
}

void mostrarPersonas(ePersona vec[],int tam)
{
    int i;
    int j;
    system("cls");
    printf("DNI\t\t\t NOMBRE\t\t EDAD \n");
    for(i=0;i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            printf("%d\t\t %s\t\t\t %d\n",vec[i].dni,vec[i].nombre,vec[i].edad);
        }

    }
}

void listaOrdenada(ePersona vec[],int tam)
{
    int i;
    int j;
    ePersona personaAux;

    system("cls");
    printf("DNI\t\t\t NOMBRE\t\t EDAD \n");

    for(i = 0; i< tam-1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(strcmp(vec[i].nombre,vec[j].nombre) > 0)
            {
                personaAux = vec[j];
                vec[j] = vec[i];
                vec[i] = personaAux;
            }
        }
    }
    mostrarPersonas(vec,tam);

    printf("\n");
}

void graficoPorEdades(ePersona vec[],int tam)
{
    int i;
    int j;
    int rangoUno;
    int rangoDos;
    int rangoTres;
    int matriz[tam][3];
    char auxRangoUno;
    char auxRangoDos;
    char auxRangoTres;

    rangoUno = 0;
    rangoDos = 0;
    rangoTres = 0;

    //INICIALIZO LA MATRIZ CON TODOS CEROS
    for(i = 0; i < tam; i++)
    {
        matriz[i][0] = 0;
        matriz[i][1] = 0;
        matriz[i][2] = 0;
    }

    //CUANTO CUANTA CANTIDAD TIENE CADA RANGO
    for(i = 0; i < tam; i++ )
    {
        if(vec[i].isEmpty == 0)
        {
            if(vec[i].edad < 18)
            {
                rangoUno = rangoUno + 1;
            }
            if(vec[i].edad >= 18 && vec[i].edad < 35)
            {
                rangoDos = rangoDos + 1;
            }
            if(vec[i].edad >= 35)
            {
                rangoTres = rangoTres + 1;
            }
        }
    }

    //PARA CADA UNO DE LOS RANGOS, CARGO LA CANTIDAD DE UNOS QUE DIGA LA VARIABLE EN LA COLUMNA CORRESPONDIENTE
    for(i = 0; i < rangoUno; i++)
    {
        matriz[i][0] = 1;
    }
    for(i = 0; i < rangoDos; i++)
    {
        matriz[i][1] = 1;
    }
    for(i = 0; i < rangoTres; i++)
    {
        matriz[i][2] = 1;
    }

    //MUESTRO LA MATRIZ EN ORDEN INVERSO
    for(i = 1; i < tam+1; i++)
    {
        j = tam - i;
        if(matriz[j][0] == 0)
        {
            auxRangoUno = ' ';
        }else
        {
            auxRangoUno = '*';
        }
        if(matriz[j][1] == 0)
        {
            auxRangoDos = ' ';
        }else
        {
            auxRangoDos = '*';
        }
        if(matriz[j][2] == 0)
        {
            auxRangoTres = ' ';
        }else
        {
            auxRangoTres = '*';
        }

        if(auxRangoUno != ' ' || auxRangoDos != ' ' || auxRangoTres != ' ' )
        {
            printf("%c\t\t%c\t\t%c\n",auxRangoUno,auxRangoDos,auxRangoTres);
        }
    }
    printf("<18\t>\t=18<35\t\t>35\n");
}

