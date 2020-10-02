#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <string.h>
int initEmployees(Employee list[], int len)
{
    int retorno = -1;
    int i;
    if(len>0)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;
}

int addEmployee(Employee list[], int len, int indice, int id)
{
    int retorno = -1;
    Employee auxiliarEmployee;
    if(len>0 && indice>=0 && indice<len)
    {
        printf("Nombre? ");
        fflush(stdin);
        scanf("%s", &auxiliarEmployee.name);
        printf("\nApellido? ");
        fflush(stdin);
        scanf("%s", &auxiliarEmployee.lastName);
        printf("\nSalario? ");
        scanf("%f", &auxiliarEmployee.salary);
        printf("\nSector? ");
        scanf("%d", &auxiliarEmployee.sector);
        auxiliarEmployee.id = id;
        auxiliarEmployee.isEmpty = 0;
        list[indice] = auxiliarEmployee;
        id++;
        retorno = 0;
    }
    return retorno;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int retorno = -1;
    int i;
    if(len>0 && id>=0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int removeEmployee(Employee list[], int len)
{
    int i;
    int id;
    int retorno = -1;
    printf("Ingrese el id a eliminar: ");
    scanf("%d", &id);
    for(i=0; i<len; i++)
    {
        if(list[i].id == id)
        {
            list[i].isEmpty = 1;
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int sortEmployees(Employee list[], int len, int order)
{
    Employee auxEmployee;
	int retorno = -1;
	int i;
	int j;

	if(order == 0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].isEmpty==0 && list[j].isEmpty==0)
                {
                    if(strcmp(list[i].lastName, list[j].lastName)> 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                        retorno = 0;
                    }
                    if(strcmp(list[i].lastName, list[j].lastName) == 0)
                    {
                        if(list[i].sector < list[j].sector)
                        {
                            auxEmployee = list[i];
                            list[i] = list[j];
                            list[j] = auxEmployee;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    else if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].isEmpty==0 && list[j].isEmpty==0)
                {
                    if(strcmp(list[i].lastName, list[j].lastName)< 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                        retorno = 0;
                    }
                    if(strcmp(list[i].lastName, list[j].lastName) == 0)
                    {
                        if(list[i].sector > list[j].sector)
                        {
                            auxEmployee = list[i];
                            list[i] = list[j];
                            list[j] = auxEmployee;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
	return retorno;
}

void printEmployees(Employee list[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("\nID:%3d    %10s     %10s    %10.2f    %3d\n", list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
}

int menuPrincipal(){
    int opcion;
    printf("\n\n1. Cargar un Empleado");
    printf("\n2. Modificar un Empleado");
    printf("\n3. Eliminar un Empleado");
    printf("\n4. Informes: ");
    printf("\n5. Imprimir nomina de empleados");
    printf("\n6. Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>6)
    {
        printf("ERROR// Ingrese una opcion valida\n");
        scanf("%d", &opcion);
    }
    return opcion;
}

int subMenu()
{
	int opcion;
	printf("\n\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
	printf("\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
	printf("\nIngrese una opcion ");
	scanf("%d", &opcion);
	while(opcion!=1 && opcion!=2)
    {
        printf("ERROR// Ingrese una opcion valida\n");
        scanf("%d", &opcion);
    }
	return opcion;
}

int buscarPosicionLibre(Employee list[],int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int ModificarArray(Employee list[], int len, int id)
{
    int retorno=-1;
    int i;
    Employee auxEmployee;
    for(i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty==0)
        {
            printf("\nNombre? ");
            fflush(stdin);
            scanf("%s", &auxEmployee.name);
            printf("\nApellido? ");
            fflush(stdin);
            scanf("%s", &auxEmployee.lastName);
            printf("\nSalario? ");
            scanf("%f", &auxEmployee.salary);
            printf("\nSector? ");
            scanf("%d", &auxEmployee.sector);
            auxEmployee.id = id;
            auxEmployee.isEmpty = 0;
            list[id] = auxEmployee;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

void informeSalarios(Employee list[], int len)
{
    int i;
    float acumulador=0;
    int contadorEmpleados=0;
    int contadorSalariosPromedios=0;
    float promedio;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            acumulador = acumulador + list[i].salary;
            contadorEmpleados++;
        }
    }
    promedio = acumulador/contadorEmpleados;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && list[i].salary>promedio)
        {
            contadorSalariosPromedios++;
        }
    }
    printf("\nEl total de los salarios es: $%.2f\n",acumulador);
    printf("El salario promedio es: $%.2f\n",promedio);
    printf("Los empleados que superan el salario promedio son: %d",contadorSalariosPromedios);
}
