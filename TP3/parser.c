#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char idAux[10];
    char nombreAux[128];
    char horasTrabajasAux[128];
    char sueldoAux[128];
    int i = 0;
    Employee* pEmployee;
    int r;
    //r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajasAux,sueldoAux);
    do
    {
    r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajasAux,sueldoAux);
        if(r==4)
        {
            retorno = 0;
            pEmployee = employee_newParametros(idAux,nombreAux,horasTrabajasAux,sueldoAux);
            ll_add(pArrayListEmployee,pEmployee);
        }
    }while(!feof(pFile));
    fclose(pFile);

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char idAux[10];
    char nombreAux[128];
    char horasTrabajasAux[128];
    char sueldoAux[128];
    Employee* pEmployee;
    int r;

    do
    {
        r=fread(pEmployee,sizeof(Employee),1,pFile);
        if(r==4)
        {
            retorno = 0;
            employee_getId(pEmployee,&idAux);
            employee_getNombre(pEmployee,nombreAux);
            employee_getHorasTrabajadas(pEmployee,&horasTrabajasAux);
            employee_getSueldo(pEmployee,&sueldoAux);
            pEmployee = employee_newParametros(idAux,nombreAux,horasTrabajasAux,sueldoAux);
            ll_add(pArrayListEmployee,pEmployee);
        }
    }while(!feof(pFile));
    fclose(pFile);

    return retorno;
}
