#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float Sumar (float,float );
/** Realiza la operacion aritmetica de la suma entre dos numeros cargados.
 *
 * Valor de tipo Float que representa el primer numero cargado a operar.
 * Valor de tipo Float que representa el segundo numero cargado a operar.
 * Valor de tipo Float que representa el resultado de la suma entre ambos numeros cargados.
 */

int ValueInt(char[]);
/** Valida que el numero cargado sea un numero y no otro tipo de dato
*
*  Valor de tipo Char que representa el numero en cadena en cadena de caracteres.
*  Valor de tipo Int que son esos caracteres transformados a tipo de dato entero o numerico.
*/

float Restar(float,float);
/** Realiza la operacion aritmetica de la resta entre dos numeros cargados.
 *
 * Valor de tipo Float que representa el primer numero cargado a operar.
 * Valor de tipo Float que representa el segundo numero cargado a operar.
 *  Valor de tipo Float que representa el resultado de la resta entre ambos numeros cargados.
 */

float Multiplicar(float, float);
/** Realiza la operacion aritmetica de la multiplicacion entre dos numeros cargados.
 *
 * Valor de tipo Float que representa el primer numero cargado a operar.
 * Valor de tipo Float que representa el segundo numero cargado a operar.
 *  Valor de tipo Float que representa el resultado de la multiplicacion entre ambos numeros cargados.
 */

float Dividir(float, float);
/** Realiza la operacion aritmetica de la divicion entre dos numeros cargados.
 *
 * Valor de tipo Float que representa el primer numero cargado a operar.
 * Valor de tipo Float que representa el segundo numero cargado a operar.
 *  Valor de tipo Float que representa el resultado de la divicion entre ambos numeros cargados.
 */

int Factorial(int);
/** Realiza la operacion aritmetica factorial de un numero cargado.
*
* Valor de tipo float que representa el numero a operar.
* Valor de tipo Int que representa el resultado del factorial de un numero.
*/

int ValidarEntero(float);
/** Realiza la validacion de un numero entero
*
* Valor de tipo Float que representa el numero a operar.
* Valor de tipo Int 1 o 0 dependiendo de si es un entero o de si no lo es, respectivamente.
*/



#endif // FUNCIONES_H_INCLUDED
