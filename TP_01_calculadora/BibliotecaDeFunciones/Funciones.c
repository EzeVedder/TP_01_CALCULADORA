#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

//Funcion para mostrar un numero float
float mostrarNumFloat(char mensaje[])
{

    float a;//defino la variable que retorna la funcion
    printf("%s", mensaje);
    scanf("%f", &a);
    printf("El numero ingresado es: %f\n",a);//imprimo msj + la variable ingresada

    return a;
}

//Funcion para sumar dos numeros
float sumarFloat(float n1,float n2)
{

    float suma;//defino la variable que retorna la funcion
    suma = (n1+n2);//operacion suma

    return suma;

}

//Funcion para restar dos numeros
float restarFloat(float n1,float n2)
{

    float resta;//defino la variable que retorna
    resta = n1-n2;

    return resta;

}

//Funcion para multiplicar dos numeros
float multiplicarFloat(float n1,float n2)
{

    float producto;//defino la variable que retorna
    producto = n1*n2;

    return producto;

}

//Funcion para dividir dos numeros
float dividirFloat(float a, float b)
{
    float cociente;
    if (b == 0)//Aviso al usuario que no se puede realizar la operacion
    {
        printf("\nNo se puede dividir entre 0\n");
        return 0;
    }
    else
    {
        cociente = (float)a/b;
        return cociente;
    }
}

//Funcion para calcular factorial(Hay que castear el float)
int calcularFactorial(int a)
{

    int factorial = 1;
    int i;//esta es la variable de control (para controlar el for)
    if((int)a<=0)
    {
        printf("\nERROR!. No existe el factorial de un numero negativo ni de 0\n");
        return 0;
    }
    for(i = a; i >= 1; i--)
    {

        factorial = factorial*i;

    }
    return factorial;
}







