#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;
}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param vec el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona vec[]);

int buscarPersona(ePersona vec[], int tam, int dni);

void inicializarStruct(ePersona vec[], int tam);

int buscarLibre(ePersona vec[], int tam);

int ValueInt(char aux[25]);

void alta(ePersona vec[], int tam);

void mostarUnaPersona(ePersona vec[],int pos);

void Baja(ePersona vec[],int tam);

void mostrarPersonas(ePersona vec[],int tam);

void graficoPorEdades(ePersona vec[],int tam);


#endif // FUNCIONES_H_INCLUDED
