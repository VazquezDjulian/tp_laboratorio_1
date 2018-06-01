#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TA 100

typedef struct{
    int id;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[1024];
    int puntaje;
    char linkImagen[500];
    int estado;
}eMovie;


/** Carga al programa un archivo binario para su lectura,si no exsite, tambien lo crea.
 * \param pelis eMovie*
 * \return int. 0 si lo puede abrir; valor ilogico si no.
 */
int cargaArchivo(eMovie* pelis);



/** Inicializa el ID y el Estado en 0 de todo elemento de la estructura.
 *
 * pelis eMovie*
 * \return
 */
Inicializar(eMovie* pelis);


/** Carga un array de estructura, validando cada uno de los campos en cuanto a tipo de dato y longitudes.
 * \param pelis eMovie*
 * \return Un array de estructura cargado de datos.
 */
validaIngresoDatos(eMovie* pelis);


/** Obtiene la primer posicion de memoria vacia para guardar alli cada array de estructura.
 *
 * \param pelix eMovie*
 * \return int. 0 si hay espacio, valor ilogico si no.
 */
int obtenerEspacioLibre(eMovie* pelix);


/** Escribe en el archivo binaro aquello que ingresamos mediante el programa.
 *
 * \param pelis eMovie*
 * \return void
 */
void guardarBinario(eMovie* pelis);


/** Genera un archivo html que contiene todos los datos que se cargaron.
 * \param pelis eMovie*
 * \param length int
 * \return void
 */
void generarHtml(eMovie* pelis);


/** Muestra por consola los datos cargados en el programa.
 *
 * \param pelis eMovie*
 * \return void
 */
void mostrarTodo(eMovie* pelis);


/** Elimina de manera logica un array de la estructura. De manera que no sea mostrado.
 *
 * \param pelis eMovie*
 * \return void. El estado modificado del array.
 */
void bajaLogica(eMovie* pelis);


/** Permite modificar cada uno de los datos que estan cargados en cada campo de la estuctura.
 *
 * \param eMovie*pelis
 * \return int. Devuleve 1 si se concreto una modificacion; un valor ilogico si no.
 */
int modificar(eMovie*pelis);


/** Genera automaticamente un ID para cada array de estructura. Es incremental.
 *
 * \param pelis[] eMovie
 * \return int. Un Id unico.
 */
int GenerarId(eMovie pelis[]);


#endif // FUNCIONES_H_INCLUDED
