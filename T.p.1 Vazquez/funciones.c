
float Sumar (float a, float b)
{
    float resultado;

    resultado = a + b;
    return resultado;
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

float Restar(float a,float b)
{
    float resultado;

    resultado = a - b;
    return resultado;
}

float Multiplicar(float a, float b)
{
    float resultado;

    resultado = a * b;
    return resultado;
}

float Dividir(float a, float b)
{
    float resultado;

    if(b != 0)
    {
        resultado = a / b;
        return resultado;
    }
    else
    {
        printf("Error, el 2do operando es 0");
    }
}

int Factorial(int numero)
{
    int resultado = 1;
    int i;
    for(i = 1; i <= numero; i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}

int ValidarEntero(float numero)
{
    int ParteEntera = (int) numero;

    if(numero - ParteEntera > 0)
    {
       return 0;
    }
    else
    {
       return 1;
    }
}

