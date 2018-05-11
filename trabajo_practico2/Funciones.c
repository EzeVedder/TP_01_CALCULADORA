#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int verificarDni(ePersona persona[],int T,int dni)
{
    for(int i=0; i<T; i++)
    {
        if(persona[i].dni==dni)
        {
            return 0;
        }
    }
    return 1;
}

void inicializarPersonas(ePersona persona[],int T)
{
    int i;

    for(i=0; i<T; i++)
    {
        persona[i].estado = -1;
    }

}
void mostrarPersona(ePersona persona)
{
    printf("\n%s\t%d\t%d\n",persona.nombre,persona.dni,persona.edad);
}

int menu(char mensaje[])
{
    int opcion;
    printf("\n\tMENU DE OPCIONES\n");
    printf("%s",mensaje);
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    printf("\n");

    return opcion;
}

int indexLibre(ePersona persona[],int T)
{
    int i;
    for(i=0; i<T; i++)
    {
        if(persona[i].estado==-1)
            return i;
    }
    return -1;
}

int cargar(ePersona persona[],int T)
{
    char auxStringNombre[100],auxStringDni[100],auxStringEdad[100];
    int auxDni,auxEdad,libre;
    libre = indexLibre(persona,T);
    if(libre==-1)
    {
        printf("ERROR: No hay espacio en el sistema.\n");
        return 0;
    }
    if(!getStringLetras("Ingrese nombre: ",auxStringNombre))
    {
        printf("El nombre debe contener solo letras.\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese DNI: ",auxStringDni))
    {
        printf("El DNI debe contener solo numeros.\n");
        return 0;
    }
    auxDni=atoi(auxStringDni);
    if(!verificarDni(persona,T,auxDni))
    {
        printf("El DNI se encuentra asignado a otro usuario.");
        return 0;
    }
    if(!getStringNumeros("Ingrese EDAD: ",auxStringEdad))
    {
        printf("La EDAD debe contener solo numeros.\n");
        return 0;
    }
    auxEdad = atoi(auxStringEdad);

    strcpy(persona[libre].nombre,auxStringNombre);
    persona[libre].dni = auxDni;
    persona[libre].edad = auxEdad;
    persona[libre].estado = 1;

    return 1;
}


void borrarPersona (ePersona persona[],int T)
{
    int i;
    int flagA;
    int aux;
    char respuesta;

    flagA = 0;
    printf("Ingrese el DNI de la persona que desea eliminar ");
    fflush(stdin);
    scanf("%d",&aux);
    for(i=0;i<T;i++)
    {
        if(persona[i].estado == 1 && aux == persona[i].dni)
            {
                mostrarPersona(persona[i]);
                printf("Esta seguro de eliminar? s/n\n");
                respuesta=getch();
                if(respuesta=='s' || respuesta == 'S' )
                {
                    persona[i].estado=0;
                    printf("\nLa persona ha sido eliminada\n");
                }
                else
                {
                    printf("\nHa cancelado la operacion\n");
                }
                flagA=1;
                break;
                }
    }
        if(flagA==0)
        {
            printf("No existe el DNI en sistema ");
        }

}

void ordenarPersonas(ePersona persona[],int T)
 {
    int i,j;
    ePersona auxPers;
    for(i=0;i<T-1;i++)
    {
        for(j=i+1;j<T;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
                auxPers=persona[i];
                persona[i]=persona[j];
                persona[j]=auxPers;

            }
        }
    }
 }

 void mostrarPersonas(ePersona persona[], int T)
{
    int i;
    printf("\nNombre Dni \t\tEdad\n");
    for(i=0;i<T;i++)
    {
        if(persona[i].estado==1)
        {
            mostrarPersona(persona[i]);
        }
    }
}

void estadisticas(ePersona persona[],int T,int cont18,int cont19, int cont35)
 {
     int mayor;
     int flag=0;
     int i;

    if(cont18>=cont19&&cont18>=cont35)
     {
         mayor=cont18;
     }
   else
    {
        if(cont19>=cont18&&cont19>=cont35)
        {
            mayor=cont19;
        }
        else
        {

            mayor=cont35;
        }
    }

     for(i=mayor;i>0;i--)
     {
         if(i<10)
         {
             printf("%02d|",i);
         }
         else
         {
             printf("%02d|",i);
         }

         if(i<=cont18)
         {
             printf("*");
         }
         if(i<=cont19)
         {
             flag=1;
             printf("\t*");
         }
         if(i<=cont35)
         {
             if(flag==0)
             {
                 printf("\t\t*");
             }
             else
             {
                 if(flag==1)
                 {
                     printf("\t*");
                 }
             }
         }
         printf("\n");
     }


       printf("--+-----------------");
       printf("\n |<18\t19-35\t>35");
 }








