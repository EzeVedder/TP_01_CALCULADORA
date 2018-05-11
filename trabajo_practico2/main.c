#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Funciones.h"

#define T 20




int main()
{
    ePersona persona[T];
    int menor18=0;
    int edad19a35=0;
    int mayor35=0;
    int i;
    char continuar ='s';

    inicializarPersonas(persona,T);

    do
    {
        switch(menu("\n1- AGREGAR NUEVA PERSONA\n2- ELIMINAR PERSONA\n3- LISTA ORDEDANADA POR NOMBRE\n4- MOSTRAR GRAFICO POR EDADES\n5- SALIR\n"))
        {
        case 1:
            if(cargar(persona,T)) // cargar
            {
                printf("La persona se ha cargado en el sistema\n");
            }
            for(i=0;i<T;i++)
            {
            if(persona[i].edad<19)
            {
                menor18++;
            }
            else if(persona[i].edad>18 || persona[i].edad<36)
            {
                edad19a35++;
            }
            else
            {
                mayor35++;
            }
            }
            break;
        case 2:
            borrarPersona(persona,T);
            break;
        case 3:
            ordenarPersonas(persona,T);
            mostrarPersonas(persona,T);
            break;
        case 4:
            estadisticas(persona,T,menor18,edad19a35,mayor35);
            break;
        case 5:
            continuar = 'n';
            break;
        default:
            printf("Ingreso una opcion incorrecta");
        }
        getch();
        system("cls");
    }while(continuar!= 'n');


    return 0;
}




