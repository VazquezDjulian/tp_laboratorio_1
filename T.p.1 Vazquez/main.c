#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    char opcionaux[10];
    float x =0;
    float y =0;
    char num1[25];
    char num2[25];
    float rsuma = 0;
    float rresta = 0;
    float rmultip = 0;
    float rdivision = 0;
    float rfactorial = 0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A= %.2f)\n",x);
        printf("2- Ingresar 2do operando (B= %.2f)\n",y);
        printf("3- Calcular la SUMA (A+B)\n");
        printf("4- Calcular la RESTA (A-B)\n");
        printf("5- Calcular la DIVISION (A/B)\n");
        printf("6- Calcular la MULTIPLICACION (A*B)\n");
        printf("7- Calcular el FACTORIAL (A!)\n");
        printf("8- Calcular TODAS las OPERACIONES\n");
        printf("9- REINICIAR operandos a 0\n");
        printf("10- Salir\n\n");
        printf("NOTA: Si uno de los numeros a operar es 0 no cargarlo ya que esta por defecto,\n en caso de ya tener cargados numeros usar la opcion de REINICIO\n\n");

        do{
         scanf("%s",&opcionaux);
        }while(ValueInt(opcionaux) != 1);
        opcion = atof(opcionaux);

        switch(opcion)
        {
            case 1:
                do
                {
                    printf("Ingrese el primer numero (A): ");
                    scanf("%s",&num1);
                }while(ValueInt(num1) != 1);
                x = atof(num1);
                system("cls");
                break;

            case 2:
                do
                {
                    printf("Ingrese el segundo numero numero (B): ");
                    scanf("%s",&num2);
                }while(ValueInt(num2) != 1);
                y = atof(num2);
                system("cls");
                break;

            case 3:
                rsuma = Sumar(x,y);
                printf("\n\nResultado de la Suma :  %.2f\n",rsuma);
                system("pause");
                system("cls");
                break;

            case 4:
                rresta = Restar(x,y);
                printf("\n\nResultado de la resta :  %.2f\n",rresta);
                system("pause");
                system("cls");
                break;

            case 5:
                 rdivision = Dividir(x,y);
                 if(y == 0)
                 {
                    printf("\n\n");
                 }
                 else
                 {
                    printf("\n\nResultado de la division :  %.2f\n",rdivision);
                 }
                 system("pause");
                 system("cls");
                break;

            case 6:
                rmultip = Multiplicar(x,y);
                printf("\n\nResultado de la multiplicacion :  %.2f\n",rmultip);
                system("pause");
                system("cls");
                break;

            case 7:
                if(x>=0)
                {
                    if(ValidarEntero(x) > 0)
                    {
                        rfactorial = Factorial(x);
                        printf("El factorial del primer numero es: %.0f\n",rfactorial);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("No esta definido el factorial para numeros flotantes \n");
                        system("pause");
                        system("cls");
                    }
                }
                else
                {
                    printf("No esta definido el factorial para numeros negativos \n");
                    system("pause");
                    system("cls");
                }
                break;

            case 8:
                rsuma = Sumar(x,y);
                printf("\n\nResultado de la Suma :  %.2f\n",rsuma);

                rresta = Restar(x,y);
                printf("\n\nResultado de la resta :  %.2f\n",rresta);

                rdivision = Dividir(x,y);
                 if(y == 0)
                 {
                    printf("\n\n");
                 }
                 else
                 {
                    printf("\n\nResultado de la division :  %.2f\n",rdivision);
                 }

                 rmultip = Multiplicar(x,y);
                 printf("\n\nResultado de la multiplicacion :  %.2f\n\n",rmultip);

                  if(x>=0)
                    {
                        if(ValidarEntero(x) > 0)
                        {
                            rfactorial = Factorial(x);
                            printf("El factorial del primer numero es: %.0f\n",rfactorial);
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            printf("No esta definido el factorial para numeros flotantes \n");
                             system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        printf("No esta definido el factorial para numeros negativos \n");
                        system("pause");
                        system("cls");
                    }
                break;

            case 9:
                x= 0;
                y = 0;
                system("pause");
                system("cls");
                break;

            case 10:
                seguir = 'n';
                break;

            default:
                printf("No es una opcion valida \n");
                system("pause");
                system("cls");
            break;
        }
    }
    return 0;
}
