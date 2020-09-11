#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    float primerOperador=0;
    float segundoOperador=0;
    int opcion;
    float suma;
    float resta;
    float div;
    float mult;
    long int factorialA;
    long int factorialB;
    int banderaDelPrimero;
    int banderaDelSegundo;
    int banderaOperaciones;

    banderaDelPrimero=0;
    banderaDelSegundo=0;
    banderaOperaciones=0;
    do
    {
        printf("Menu de opciones\n\n"
               "1. Ingresar el primer operador(A=%.2f).\n"
               "2. Ingresar el segundo operador(B=%.2f).\n"
               "3. Calcular las siguientes operaciones:\n"
               "               a) Calcular la suma(A+B)\n"
               "               b) Calcular la resta(A-B)\n"
               "               c) Calcular la division(A/B)\n"
               "               d) Calcular la multiplicacion(A*B)\n"
               "               e) Calcular el factorial(!A) y (!B)\n"
               "4. Informar Resultados.\n"
               "5. Salir.\n", primerOperador, segundoOperador);
        scanf("%d", &opcion);
        while(opcion<1 || opcion>5)
        {
            printf("ERROR// Ingrese una opcion valida\n"
                   "1. Ingresar el primer operador(A=%.2f).\n"
                   "2. Ingresar el segundo operador(B=%.2f).\n"
                   "3. Calcular todas las operaciones\n"
                   "4. Informar Resultados.\n5. Salir.\n", primerOperador, segundoOperador);
            scanf("%d\n", &opcion);
        }

        switch(opcion)
        {
            case 1:
                printf("\nIngrese el primer numero: \n");
                fflush(stdin);
                scanf("%f", &primerOperador);
                printf("\n");
                banderaDelPrimero=1;
                break;

            case 2:
                printf("\nIngrese el segundo numero: \n");
                fflush(stdin);
                scanf("%f", &segundoOperador);
                printf("\n");
                banderaDelSegundo=1;
                break;

            case 3:
                if(banderaDelPrimero==1 && banderaDelSegundo==1)
                {
                    suma = SumarNumeros(primerOperador,segundoOperador);
                    resta = RestarNumeros(primerOperador,segundoOperador);
                    div = DividirNumeros(primerOperador,segundoOperador);
                    mult = MultiplicarNumeros(primerOperador,segundoOperador);
                    factorialA = CalcularFactorial(primerOperador);
                    factorialB = CalcularFactorial(segundoOperador);
                    printf("Se han realizado las operaciones con exito!!\n");
                    banderaOperaciones=1;
                }
                else
                {
                    printf("Primero ingrese los dos operadores\n\n");
                }
                printf("\n");
                break;
            case 4:
                if(banderaOperaciones==1)
                {
                    printf("El resultado de A+B es: %.2f\n", suma);
                    printf("El resultado de A-B es: %.2f\n", resta);
                    printf("El resultado de A/B es: %.2f\n", div);
                    printf("El resultado de A*B es: %.2f\n", mult);
                    printf("El factorial de A es: %ld\n", factorialA);
                    printf("El factorial de B es: %ld\n\n", factorialB);
                }
                else
                {
                    printf("No se han realizado las operaciones todavia\n\n");
                }
                printf("\n");
                break;
        }
    }while(opcion!=5);
    return 0;
}
