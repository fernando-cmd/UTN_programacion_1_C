#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    LinkedList* listEmpleados = ll_newLinkedList();


    do
    {
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                "2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).\n"
                "3. Alta de empleado\n"
                "4. Modificar datos de empleado\n"
                "5. Baja de empleado\n"
                "6. Listar empleados\n"
                "7. Ordenar empleados\n"
                "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                "9. Guardar los datos de los empleados en el archivo data.dat (modo binario).\n"
                "10. Salir\n\n"
                "Ingrese una opcion: ");
                scanf("%d",&opcion);


       switch(opcion)
       {
           case 1:
               if(controller_loadFromText("data.csv",listEmpleados)==0)
               {
                   printf("\nArchivo cargado con exito\n");
               }
               else
               {
                   printf("\nError al cargar el archivo\n");
               }
               break;
           case 2:
                if(controller_loadFromBinary("data.bin",listEmpleados)==0)
                {
                    printf("\nArchivo cargado con exito\n");
                }
                else
                {
                    printf("\nError al cargar el archivo\n");
                }
                break;
           case 3:
                if(controller_addEmployee(listEmpleados)==0)
                {
                    printf("\nEmpleado cargado correctamente\n");
                }
                else
                {
                    printf("\nError al cargar el empleado\n");
                }
                break;
           case 4:
                controller_editEmployee(listEmpleados);
                break;
           case 5:
                if(controller_removeEmployee(listEmpleados)==0)
                {
                    printf("\nEmpleado removido exitosamente!");
                }
                else
                {
                    printf("\nError al eliminar el empleado!\n");
                }
                break;
           case 6:
                controller_ListEmployee(listEmpleados);
                break;
           case 7:
                controller_sortEmployee(listEmpleados);
                break;
           case 8:
               if(controller_saveAsText("data.csv",listEmpleados)==0)
               {
                   printf("\nGuardado exitoso!");
               }
                break;
           case 9:
               if(controller_saveAsBinary("data.dat",listEmpleados)==0)
               {
                   printf("\nArchivo guardado");
               }
               else
               {
                   printf("\nERROR");
               }
                break;
       }
    }while(opcion!=10);

    return 0;
}
