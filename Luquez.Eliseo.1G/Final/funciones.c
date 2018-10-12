#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"


int optionsCliente()
{
    int option;

    system("cls");
    printf("\n*** Menu de Clientes ***\n\n");
    printf("\n    1- Altas\n");
    printf("\n    2- Modificar\n");
    printf("\n    3- Baja\n");
    printf("\n    4- Informar\n");
    printf("\n    5- Alta Alquiler\n");
    printf("\n    6- Listar Alquileres\n");
    printf("\n    7- Salir \n");
    printf("\n\n** Ingrese Opcion **\n");
    scanf("%d", &option);

    return option;
}








/*****          VALIDACIONES               *******/
int getInt(char mensaje)
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}
float getFloat(char mensaje)
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}
char getChar(char mensaje)
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;
}

/** \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico 0 si no lo es
 */
int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i]<'0'||str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief
 * \param str Array con la cadena a ser analizada
 * \return
 */
int esTelefono(char str[])
{
    int i = 0;
    int contadorGuiones = 0;
    while(str[i] != '\0')
    {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1)
        return 1;

    return 0;
}

/** \brief verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene espacio o letras y numeros, y 0 si no lo es
 */
int esAlfaNumerico(char str[])
{
    int i = 0;
    while(str[i] !='\0')
    {
        if((str[i] != ' ')&&(str[i] < 'a'||str[i] > 'z')&&(str[i] < 'A'||str[i] > 'Z')&&(str[i]<'0'||str[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo '' y letras y 0 si no lo es
 */
int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] !='\0')
    {
        if((str[i] != ' ')&&(str[i] < 'a'||str[i] > 'z')&&(str[i] < 'A'||str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}



void getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}



int getStringLetras(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}

int getStringNumeros(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int esLetraFoM(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] == 'f' || str[i] == 'm'|| str[i] == 'M'|| str[i] == 'F')
           return 1;
       i++;
   }
   return 0;
}



int getStringFoM(char msj[], char input[])
{
    char letra[2];
    getString(msj, letra);
    if (esLetraFoM(letra))
        {
            strcpy(input,letra);
            return 1;
        }
    return 0;
}



int getStringTelefono(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);
    if(esTelefono(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}











