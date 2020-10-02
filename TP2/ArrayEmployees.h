#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTY_EMPLEADOS 1000
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/**
 * \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
 * \(isEmpty) en TRUE en todas las posiciones del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int initEmployees(Employee list[], int len);

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la Employee
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployee(Employee list[], int len, int indice, int id);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
* 	\param Array de empleado
* 	\param int len Tamaño del array
* 	\param int Posicion del array donde se encuentra el valor buscado
* 	\return Retorna (-1) si no encuentra el valor buscado - (0) si encuentra el valor buscado
*
*/
int findEmployeeById(Employee list[], int len,int id);

/**
 * \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int removeEmployee(Employee list[], int len);

/**
 * \brief Ordenar el array de empleados por apellido y sector de manera ascendente
 * o descendente
 * \param Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int sortEmployees(Employee list[], int len, int order);

/** \brief Imprimi el array
 *
 * \param  Array
 * \param limite Limite del array de empleados
 *
 */
void printEmployees(Employee list[], int len);

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int buscarPosicionLibre(Employee list[],int len);

/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param Array de empleados a ser actualizado
 * \param Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int ModificarArray(Employee list[], int len, int id);

/**
 * \brief Calcula el total acumulado de Salarios y el promedio total
 * 	y lo imprime en pantalla.
 * \param Array de empleados
 * \param Limite del array de empleados
 *
 */
void informeSalarios(Employee list[], int len);

int menuPrincipal();
int subMenu();
