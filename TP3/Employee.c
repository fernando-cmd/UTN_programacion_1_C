#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>
//CONTRUSTORES Y DESTRUCTOR
Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    pEmployee = employee_new();
    if(pEmployee !=NULL)
    {
      if( employee_setId(pEmployee,idStr)== -1 ||
          employee_setNombre(pEmployee,nombreStr)== -1 ||
          employee_setHorasTrabajadas(pEmployee,horasTrabajadasStr)== -1 ||
          employee_setSueldo(pEmployee,sueldoStr)== -1 )
          {
              employee_delete(pEmployee);
              pEmployee = NULL;
          }
    }
    return pEmployee;
}

Employee* employee_newParametrosIdInt(int idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    pEmployee = employee_new();
    if(pEmployee !=NULL)
    {
      if( employee_setIdInt(pEmployee,idStr)== -1 ||
          employee_setNombre(pEmployee,nombreStr)== -1 ||
          employee_setHorasTrabajadas(pEmployee,horasTrabajadasStr)== -1 ||
          employee_setSueldo(pEmployee,sueldoStr)== -1 )
          {
              employee_delete(pEmployee);
              pEmployee = NULL;
          }
    }
    return pEmployee;
}


void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}




// SETTERS

int employee_setId(Employee* this,char* id)
{
    int retorno = -1;
    if(this != NULL) //&&) //id !=NULL && esNumerica(id,10)==0)
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}

int employee_setIdInt(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this !=NULL)//) && nombre !=NULL && validarNombre(nombre,NOMBRE_LEN)==0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this !=NULL)// && horasTrabajadas !=NULL && esNumerica(horasTrabajadas,300)==0)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasInt(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this !=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno = -1;
    if(this !=NULL)// && sueldo !=NULL && esNumerica(sueldo,300)==0)
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoInt(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this !=NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}



// GETTERS

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this !=NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this !=NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this !=NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this !=NULL && sueldo !=NULL)
    {
          *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


// COMPARACIONES

int employee_CompareByName(void* e1, void* e2)
{
    int retorno = -1;
    Employee* auxE1;
    Employee* auxE2;
    char nombreAuxE1[NOMBRE_LEN];
    char nombreAuxE2[NOMBRE_LEN];

    auxE1 = (Employee*)e1;
    auxE2 = (Employee*)e2;

    if( employee_getNombre(auxE1,&nombreAuxE1)==0 &&
        employee_getNombre(auxE2,&nombreAuxE2)==0)
    {
        if(strcmp(nombreAuxE1,nombreAuxE2)==1)
        {
            retorno = 1;
        }
        else
        {
            if(strcmp(nombreAuxE1,nombreAuxE2)==0)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    int retorno = -1;
    Employee* auxE1;
    Employee* auxE2;
    int idAuxE1;
    int idAuxE2;

    auxE1 = (Employee*)e1;
    auxE2 = (Employee*)e2;

    if( employee_getId(auxE1,&idAuxE1)==0 &&
        employee_getId(auxE2,&idAuxE2)==0)
    {
        if(idAuxE1>idAuxE2)
        {
            retorno = 1;
        }
        else
        {
            if(idAuxE1==idAuxE2)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int employee_CompareBySalary(void* e1, void* e2)
{
    int retorno = -1;
    Employee* auxE1;
    Employee* auxE2;
    int salaryE1;
    int salaryE2;

    auxE1 = (Employee*)e1;
    auxE2 = (Employee*)e2;

    if( employee_getSueldo(auxE1,&salaryE1)==0 &&
        employee_getSueldo(auxE2,&salaryE2)==0)
    {
        if(salaryE1>salaryE2)
        {
            retorno = 1;
        }
        else
        {
            if(salaryE1==salaryE1)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}


int employee_CompareByHorasTrabajadas(void* e1, void* e2)
{
    int retorno = -1;
    Employee* auxE1;
    Employee* auxE2;
    int horasAuxE1;
    int horasAuxE2;

    auxE1 = (Employee*)e1;
    auxE2 = (Employee*)e2;

    if( employee_getHorasTrabajadas(auxE1,&horasAuxE1)==0 &&
        employee_getHorasTrabajadas(auxE2,&horasAuxE2)==0)
    {
        if(horasAuxE1>horasAuxE2)
        {
            retorno = 1;
        }
        else
        {
            if(horasAuxE1==horasAuxE2)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

//VALIDACIONES
/*
static int validarNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
//		fpurge(stdin);
		//__fpurge(stdin); // Linux
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
*/
