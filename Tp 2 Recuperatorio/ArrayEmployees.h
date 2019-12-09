#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Inputs.h"

#define EMPTY -1
#define NOT_EMPTY 0

struct
{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;

}typedef eEmployee;

struct
{
     int id;
     int contador;

}typedef eAux;


/** \brief Entrega una estructura ya completa que tenga un id,nombre,apellido,salario,sectory un estado.
 *
 * \param eEmployee estructura a ser harrcodeada
 * \param len Tamanio de la estructura
 * \return void
 *
 */
void harcodeo(eEmployee lista[],int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief Busca si en el Array de estructura encuentra un espacio
            que no este acupado y te devuelve el indice del mismo
 *
 * \param lista[] Array a recorrer
 * \param len tamanio del Array
 * \return Indice del espacio vacio
 *
 */
int espacioLibre(eEmployee lista[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief Genera un Id sabiendo cual es el ultimo mas grande
 *
 * \param lista[] Estructura a revisar
 * \param len tamanio de la estructura
 * \param valMenor el primer id que se pueda ingresar
 * \return int Id generado
 *
 */
int autoId(eEmployee lista[], int len,int valMenor);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief busca entre los id existentes el mayor
 *
 * \param eEmployee estructura a revisar
 * \param len tamanio
 * \param valMenor primer id que se pueda ingresar
 * \return int id mayor hasta el momento
 *
 */
int idMayor(eEmployee lista[],int len,int valMenor);

//----------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief junta todos los datos para poder agregar un empleado
 *
 * \param lista eEmployee*
 * \param len
 * \return int 0 si todo salio bien -1 si el iindice no existe
 *
 */
int agragarEmpleado(eEmployee lista[],int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */

int addEmployee(eEmployee empleados[],int tam,int *id,char name[],char apellido[],float *salario,int *sector);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *   pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee list[], int len,int id);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 *     find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len, int id);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief ordena alfabeticamente de la A-Z junco con sus sectores
 *
 * \param list eEmployee*
 * \param len int
 * \return void
 *
 */
void ordenarAfabeticamenteUp(eEmployee list[], int len);


//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief ordena alfabeticamente de la Z-A junco con sus sectores
 *
 * \param list eEmployee*
 * \param len int
 * \return void
 *
 */
void ordenarAfabeticamenteDown(eEmployee list[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee list[], int length);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief Muetra solo el empleado que se le pide
 *
 * \param list eEmployee*
 * \param index pocision del Empleado
 * \return void
 *
 */
void mostrarUnEmpleado(eEmployee list[], int index);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief es el menu donde se encuentran las opciones de las modificaciones que se puedan hacer
 *
 * \param list eEmployee*
 * \param lengh int
 * \return int
 *
 */
int  modificarMenu(eEmployee list[], int lengh);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra el apellido y el sector de un empleado
 *
 * \param list eEmployee*
 * \param len int
 * \return void
 *
 */
void mostrarApellidoSector(eEmployee list[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief suma todos los salarios de los empleados
 *
 * \param list eEmployee*
 * \param len int
 * \return float resultado final
 *
 */
float totalSalarios(eEmployee list[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------


/** \brief  saca el promedio del salari entre todos los empleados
 *
 * \param list eEmployee*
 * \param len int
 * \return float resultado del promedio
 *
 */
float promedioDeSalarios(eEmployee list[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra cuantos empleados suuperan el promedio de salarios
 *
 * \param list eEmployee*
 * \param len int
 * \return int
 *
 */
int superanPromedioSalario(eEmployee list[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra el total el promedio y cuantos se pasan del promedio
 *
 * \param list eEmployee*
 * \param len int
 * \return int
 *
 */
int informeSalario(eEmployee list[], int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief pide ingresar un id y lo elimina (logicamente) del array
 *
 * \param eEmployee[]
 * \param len int
 * \return int
 *
 */
int baja(eEmployee[],int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief mustra un menu de opciones:
    [1] Ordenados alfabeticamente por Apellido y Sector
    [2] -Total: -Promedio de los salarios
                -Cuantos empleados superan el salario promedio
    [3] Cancelar
 *
 * \param eEmployee[]
 * \param len int
 * \return int
 *
 */
int informes(eEmployee[],int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief mustra un menu de opciones para Ordenados alfabeticamente por Apellido y Sector segun
    [0] Mayor a Menor
    [1] Menor a Mayor
 *
 * \param eEmployee[]
 * \param len int
 * \return int
 *
 */
int informeOrdenar(eEmployee[],int len);

//----------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra el contenido del array
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
void mostrarEmpleados(eEmployee lista[],int len);
