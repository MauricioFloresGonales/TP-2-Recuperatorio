#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
* */

int getInt(int* valor,char message[],char eMessage[],int lowLimit, int hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
* */ int getFloat(float* valor,char message[],char eMessage[], float lowLimit, float hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------


/** \brief valida que lo que se ingresa se un  numero
 *
 * \param input numero a validar
 * \return int si solo se ingreseo una numero [0] si no [-1]
 *
 */

int validarNumero(char* numeroChar);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
* */

 int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** \brief solicita una de las dos letras que se pide
 *
 * \param input Se carga el caracter ingresado
 * \param message[] Es el mensaje a ser mostrado
 * \param eMessage[] Es el mensaje a ser mostrado en caso de error
 * \param oneLimit letra que se puede ingrear
 * \param twoLimit otra letra que se puede ingrear
 * \return int Si obtuvo el caracter [0] si no [-1]
 *
 */
int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Muestra dos opciones para verificar que el dato ingresado es el correcto ingresanddo
            's' si el dato es correcto o 'n' si el dato es incorrecto.
 * \param messge[] mensaje para la opcion firmativa
 * \param eMessage[] mensaje para la opcion negativa
 * \return int Retorna [0] si el dato es correcto,[1] si el dato es cancelado,[-1] si no ingreso una 's' ni 'n'.
 *
 */
int confirmar(char messge[],char eMessage[]);// salta un warnig por usar la funcion 'getch'

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error al pasar los limites
* \param eMessage Es el mensaje a ser mostrado en caso de error al poner un numero
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
* */

int getString(char* input,char message[],char eMessage[],char eNumMessage[], int lowLimit, int hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** \brief recorre un Array y determina si hay todos los caracteres son
            letras
 *
 * \param palabra Array a analiizar
 * \param tam tamanio del Array
 * \return int Si no encontro un numero [0] si encontro un numero [-1]
 *
 */
int validarLetrasEnString(char palabra[],int tam);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita una cadena de caracteres al usuario y la valida haceptando numeros en la palabra
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error al pasar los limites
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*/
int getStringWithNums(char* input,char message[],char eMessage[],int lowLimit, int hiLimit);
