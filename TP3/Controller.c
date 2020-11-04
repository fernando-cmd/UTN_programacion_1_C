#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pArchivo = fopen(path,"r");
        if(pArchivo!=NULL)
        {
            retorno = 0;
            parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        }
    }
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pArchivo = fopen(path,"rb");
        if(pArchivo!=NULL)
        {
            retorno = 0;
            parser_EmployeeFromBinary(path,pArrayListEmployee);
        }
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char nombreAux[128];
    char horasTrabajasAux[128];
    char sueldoAux[128];
    int id;
    Employee* pEmployee;

    printf("\nNombre? ");
    fflush(stdin);
    gets(nombreAux);
    printf("\nHoras trabajadas? ");
    fflush(stdin);
    gets(horasTrabajasAux);
    printf("\nSueldo? ");
    fflush(stdin);
    gets(sueldoAux);
    id=controller_idMaximo(pArrayListEmployee);
    pEmployee = employee_newParametrosIdInt(id+1,nombreAux,horasTrabajasAux,sueldoAux);
    if(pEmployee!=NULL)
    {
        retorno = 0;
        ll_add(pArrayListEmployee,pEmployee);
    }
    else
    {
        printf("error");
    }
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;
    char nombreAux[128];
    int horasTrabajasAux;
    int sueldoAux;
    int idAux;
    int indexAux;
    int respuesta;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el id del empleado a modificar: ");
    scanf("%d", &idAux);

    indexAux = employee_getIndex(pArrayListEmployee,idAux);
    auxEmployee = (Employee*)ll_get(pArrayListEmployee,indexAux);



        do
        {
            printf("\n\nQue desea modificar: \n1)Nombre.\n2)Horas trabajadas.\n3)Sueldo.\n4)Salir\nIngrese su opcion: ");
            scanf("%d", &respuesta);
            switch(respuesta)
            {
                case 1:
                    if(utn_getNombre(nombreAux,128,"\nIngrese el nuevo nombre: ","\nNombre invalido",3)==0)
                    {
                        if(employee_setNombre(auxEmployee,nombreAux)==0)
                        {
                            printf("\nNombre modificado correctamente!");
                        }
                    }
                 break;

                case 2:
                     if(utn_getNumero(&horasTrabajasAux,"\nIngrese las horas trabajadas: ","Numero invalido",0,99999999,2)==0)
                     {
                         if(employee_setHorasTrabajadasInt(auxEmployee,horasTrabajasAux)==0)
                         {
                             printf("\nLa cantidad de horas fue modificada correctamente!");
                         }
                     }
                     break;

                case 3:
                     if(utn_getNumero(&sueldoAux,"\nIngrese el nuevo sueldo: ","Numero invalido",0,99999999,2)==0)
                     {
                         if(employee_setSueldoInt(auxEmployee,sueldoAux)==0)
                         {
                             printf("\nEl sueldo fue modificado correctamente!");
                         }
                     }
                    break;
                default:
                    printf("\nOpcion Invalida");
                    break;
            }
        }while(respuesta!=4);
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int idAux;
    int indexAux;
    char nombreAux[128];
    int respuesta;
    Employee* auxEmployee;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el id del empleado a eliminar: ");
    scanf("%d", &idAux);

    indexAux = employee_getIndex(pArrayListEmployee,idAux);

    auxEmployee = (Employee*) ll_get(pArrayListEmployee,indexAux);

    employee_getNombre(auxEmployee,nombreAux);

    printf("\nEsta seguro de eliminar a %s ID: %d 1(SI) 2(NO): ",nombreAux,idAux);
    scanf("%d", &respuesta);
    if(respuesta == 1)
    {
        ll_remove(pArrayListEmployee,indexAux);
        retorno = 0;
    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int idAux;
    int horasAux;
    int sueldoAux;
    char nombreAux[128];
    Employee* auxEmployee;
    int i;
    len = ll_len(pArrayListEmployee);

    for(i=0; i<len; i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
        employee_getId(auxEmployee,&idAux);
        employee_getNombre(auxEmployee,nombreAux);
        employee_getHorasTrabajadas(auxEmployee,&horasAux);
        employee_getSueldo(auxEmployee,&sueldoAux);

        printf("%3d  %15s  %4d  %5d\n",idAux,nombreAux,horasAux,sueldoAux);

    }

    return 0;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int respuesta;

    if(utn_getNumero(&respuesta,"\n\nEliga el criterio para ordenar\n1)Salario\n2)Nombre\n3)Horas Trabajadas\n4)id\nIngrese una opcion: ","\nOpcion invalida",0,5,2)==0)
    {
        switch(respuesta)
        {
            case 1:
                ll_sort(pArrayListEmployee,employee_CompareBySalary,0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_CompareByName,0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                ll_sort(pArrayListEmployee,employee_CompareById,0);
                controller_ListEmployee(pArrayListEmployee);
                break;
        }
    }
    return retorno;
}

int controller_sortEmployeeById(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(ll_sort(pArrayListEmployee,employee_CompareById,0)==0)
    {
        retorno = 0;
    }
    return retorno;
}

int controller_sortEmployeeByName(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(ll_sort(pArrayListEmployee,employee_CompareByName,0)==0)
    {
        retorno = 0;
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    Employee* auxEmployee;
    int len;
    int id;
    int salario;
    int horas;
    char nombre[NOMBRE_LEN];
    int i;

    if(pArrayListEmployee!=NULL  && path!=NULL)
    {
        pArchivo = fopen(path,"w");
        len = ll_len(pArrayListEmployee);
        if(pArchivo!=NULL)
        {
            retorno = 0;
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                if( employee_getId(auxEmployee,&id)==0 &&
                    employee_getNombre(auxEmployee,nombre)==0 &&
                    employee_getHorasTrabajadas(auxEmployee,&horas)==0 &&
                    employee_getSueldo(auxEmployee,&salario)==0 )
                    {
                        fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horas,salario);
                    }
            }
        }

    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    Employee* auxEmployee;
    int len;
    int id;
    int salario;
    int horas;
    char nombre[NOMBRE_LEN];
    int i;

    if(pArrayListEmployee!=NULL  && path!=NULL)
    {
        pArchivo = fopen(path,"w");
        len = ll_len(pArrayListEmployee);
        if(pArchivo!=NULL)
        {
            retorno = 0;
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                if( employee_getId(auxEmployee,&id)==0 &&
                    employee_getNombre(auxEmployee,nombre)==0 &&
                    employee_getHorasTrabajadas(auxEmployee,&horas)==0 &&
                    employee_getSueldo(auxEmployee,&salario)==0 )
                    {
                        fwrite(&id,sizeof(int),1,pArchivo);
                        fwrite(nombre,sizeof(char),1,pArchivo);
                        fwrite(&horas,sizeof(int),1,pArchivo);
                        fwrite(&salario,sizeof(int),1,pArchivo);
                    }
            }
        }
    }
}
int employee_getIndex(LinkedList* pArrayListEmployee, int id)
{
    int index;
    int i;
    int len;
    Employee* auxEmployee;

    len = ll_len(pArrayListEmployee);
    for(i=0; i<len; i++)
    {
        auxEmployee = ll_get(pArrayListEmployee,i);
        if(auxEmployee->id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

int controller_idMaximo(LinkedList* pArrayListEmployee)
{
    int len;
    int idAux;
    int idMax;
    Employee* auxEmployee;
    int i;
    len = ll_len(pArrayListEmployee);

    for(i=0; i<len; i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
        employee_getId(auxEmployee,&idAux);
        if(i==0)
        {
            idMax = idAux;
        }
        else
        {
            if(idAux>idMax)
            {
                idMax = idAux;
            }
        }

    }

    return idMax;
}
