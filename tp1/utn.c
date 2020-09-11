#include "utn.h"

float SumarNumeros(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

float RestarNumeros(float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

float MultiplicarNumeros(float primerNumero, float segundoNumero)
{
    float multiplicacion;
    multiplicacion = primerNumero * segundoNumero;
    return multiplicacion;
}

float DividirNumeros(float primerNumero, float segundoNumero)
{
    float division;
    division = primerNumero/segundoNumero;
    return division;
}

int CalcularFactorial(int numero)
{
    int resultado;
    if(numero == 0)
    {
        resultado = 1;
    }
    else
    {
         resultado = numero * CalcularFactorial(numero - 1);
    }
    return resultado;
}
