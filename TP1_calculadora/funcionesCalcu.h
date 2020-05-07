#include <stdio.h>
#include <stdlib.h>

int getInt(char[]);
/** \brief ingresa un numero por teclado y valida que sea entero
 *  \param  recive un string con el texto que se desea mostrar (char[])
 *  \return devuelve el entero ingresado
 */

int validarInt(float a);
/** \brief valida si es entero el numero
 *  \param  recive un float
 *  \return devuelve 1 si es un entero y 0 si es decimal
 */

void menuPrint(int , int, int, int );
/** \brief Imprime el menu de la calculadora, teniendo en cuenta si ya se ingresó a o b
 *  \param   valor de a (int)
 *  \param   valor de b (int)
 *  \param   flag de a   (para saber si ya se ingresó) (int)
 *  \param   flag de b   (para saber si ya se ingresó) (int)
 *  \return  no devuelve nada
 */

int sumar(int,int);
/** \brief  suma dos numeros enteros
 *  \param  valor a (int)
 *  \param  valor b (int)
 *  \return devuelve la suma
 */

int restar(int,int);
/** \brief  resta dos numeros enteros
 *  \param  valor a (int)
 *  \param  valor b (int)
 *  \return devuelve la resta
 */

float dividir(int,int);
/** \brief  divide dos numeros enteros
 *  \param  valor a (int)
 *  \param  valor b (int)
 *  \return devuelve la division en float
 */

int multiplicar(int,int);
/** \brief  multiplica dos numeros enteros
 *  \param  valor a (int)
 *  \param  valor b (int)
 *  \return devuelve la multiplicacion
 */
int factorial(int);
/** \brief  calcula factorial
 *  \param  valor a (int)
 *  \return devuelve a!
 */

void printResult(int,int,int,int,float,int,int,int);
/** \brief  imprime todos los resultados con las variables ingresadas
 *  \param  valor a (int)
 *  \param  valor b (int)
 *  \param  valor de la suma    (int)
 *  \param  valor de la resta   (int)
 *  \param  valor de la division (float)
 *  \param  valor de la multiplicacion (int)
 *  \param  valor del factorial A (int)
 *  \param  valor del factorial B (int)
 *  \return no devuelve nada
 */

