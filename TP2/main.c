#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
int main()
{
    int opcion;
    int id=0;
    int auxiliarIndice;
    int auxiliarId;
    Employee arrayEmployees[QTY_EMPLEADOS];
    int auxiliarOrden;

    if(initEmployees(arrayEmployees,QTY_EMPLEADOS)==0)
    {
        printf("\tIniciacion exitosa\n");
    }

    do
    {
        switch(menuPrincipal())
        {
            case 1:
                auxiliarIndice=buscarPosicionLibre(arrayEmployees, QTY_EMPLEADOS);
                if(addEmployee(arrayEmployees, QTY_EMPLEADOS, auxiliarIndice, id)==0)
                {
                    printf("\nCarga exitosa\n");
                    id++;
                }
                else
                {
                    printf("No queda espacio disponible\n");
                }
                break;
            case 2:
                printEmployees(arrayEmployees, QTY_EMPLEADOS);
                printf("Indique el id a modificar: \n");
                scanf("%d", &auxiliarId);
                auxiliarIndice = findEmployeeById(arrayEmployees, QTY_EMPLEADOS,  auxiliarId);
                if(ModificarArray(arrayEmployees, QTY_EMPLEADOS, auxiliarIndice)==0)
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("Error no se pudo modificar\n");
                }
                break;
            case 3:
                printEmployees(arrayEmployees, QTY_EMPLEADOS);
                if(removeEmployee(arrayEmployees, QTY_EMPLEADOS)==0)
                {
                    printf("Empleado Eliminado");
                }
                else
                {
                    printf("No se pudo eliminar el empleado");
                }
                break;
            case 4:
                switch(subMenu())
                {
                    case 1:
                        printf("Indique 0(descendente) o 1(ascendente)");
                        scanf("%d", &auxiliarOrden);
                        sortEmployees(arrayEmployees,QTY_EMPLEADOS,auxiliarOrden);
                        break;
                    case 2:
                        informeSalarios(arrayEmployees,QTY_EMPLEADOS);
                        break;
                }
                break;
            case 5:
                printEmployees(arrayEmployees,QTY_EMPLEADOS);
                break;
            case 6:
                opcion = 6;

        }
    }while(opcion!=6);
    return 0;
}
