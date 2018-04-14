#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaDeFunciones/Funciones.h"

int main()
{


    char seguir='s';//declaro todas las variables
    float numero1=0;
    float numero2=0;
    float sumar;
    float restar;
    float dividir;
    float multiplicar;
    int factorial;

    int opcion=0;

    while(seguir=='s')//bucle hasta que el usuario apreta la letra 'n'
    {
        printf("\n1- Ingresar 1er operando\n");
        printf("2- Ingresar 2do operando\n");
        printf("3- Calcular la suma\n");
        printf("4- Calcular la resta\n");
        printf("5- Calcular la division\n");
        printf("6- Calcular la multiplicacion\n");
        printf("7- Calcular el factorial\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                return main();
                break;
            case 2:
                numero2 = mostrarNumFloat("\nIngrese el numero: ");
                return main();
                break;
            case 3:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                numero2 = mostrarNumFloat("\nIngrese el numero: \n");
                sumar = sumarFloat(numero1, numero2);
                printf("El resultado de la suma es: %.2f",sumar);
                return main();
                break;
            case 4:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                numero2 = mostrarNumFloat("\nIngrese el numero: \n");
                restar = restarFloat(numero1,numero2);
                printf("El resultado de la suma es: %.2f",restar);
                return main();
                break;
            case 5:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                numero2 = mostrarNumFloat("\nIngrese el numero: ");
                dividir = dividirFloat(numero1,numero2);
                printf("El resultado de la suma es: %.2f",dividir);
                return main();
                break;
            case 6:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                numero2 = mostrarNumFloat("\nIngrese el numero: ");
                multiplicar = multiplicarFloat(numero1,numero2);
                printf("El resultado de la suma es: %.2f",multiplicar);
                return main();
                break;
            case 7:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                factorial = calcularFactorial(numero1);
                printf("El resultado A! de %.0f es: %d",numero1,factorial);
                return main();
                break;
            case 8:
                numero1 = mostrarNumFloat("\nIngrese el numero: ");
                numero2 = mostrarNumFloat("\nIngrese el numero: ");
                sumar = sumarFloat(numero1,numero2);
                restar = restarFloat(numero1,numero2);
                dividir = dividirFloat(numero1,numero2);
                multiplicar = multiplicarFloat(numero1,numero2);
                factorial = calcularFactorial(numero1);
                printf("La suma del primer numero y el segundo es %.2f,la resta es %.2f,\n La division es %.2f,el producto es %.2f y el resultado A! de %.0f es: %d",sumar,restar,dividir,multiplicar,numero1,factorial);


                return main();
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("No es un valor válido: Pruebe de nuevo");
                return main();
        }
    return 0;
    }
}
