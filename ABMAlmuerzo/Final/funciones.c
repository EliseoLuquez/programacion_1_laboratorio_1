#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"


/*****          VALIDACIONES               *******/
int getInt(char mensaje)
{
    int auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &auxiliar);
    return auxiliar;
}
float getFloat(char mensaje)
{
    float auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
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
       if((str[i] != ' ') || (str[i] != '-') || (str[i] < '0' || str[i] > '9'))
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

void getCharLetra(char msj[],char input)
{
    printf("%s",msj);
    fflush(stdin) ;
    scanf("%c", &input);
}


int getStringLetras(char msj[],char input[])
{
    char aux[256];
    fflush(stdin);
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
    fflush(stdin);
    getString(msj,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int esLetraFoM(char str)
{
    if((str != 'f') || (str != 'm') || (str != 'M') || (str != 'F'))
    {
        return 0;
    }

   return 1;
}



int getStringFoM(char msj[], char input)
{
    char aux;
    fflush(stdin);
    getCharLetra(msj, aux);
    if(esLetraFoM(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringTelefono(char msj[],char input[])
{
    char aux[256];
    fflush(stdin);
    getString(msj,aux);
    if(esTelefono(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esLetraSoN(char str)
{
    if(str != 's' && str != 'n' && str != 'S'&& str != 'N')
    {
        return 1;
    }
   return 0;
}

int continueSiONo(char msj[],char input)
{
    int retorno = -1;
    char aux;
    fflush(stdin);
    getStringLetras(msj,aux);
    if(esLetraSoN(aux))
    {
        input = aux;
        if(input == 's')
        {
            retorno = 1;
        }
        else if(input == 'n')
        {
           retorno = 0;
        }
    }
    return retorno;
}


//MENU

int menu()
{
    int opcion;

     system("cls");
    printf("\n                      *** >>>Menu de Opciones<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Alta Cliente                         |\n");
    printf("                 |  2-  Baja Cliente                         |\n");
    printf("                 |  3-  Modificacion Cliente                 |\n");
    printf("                 |  4-  Listar Cliente                       |\n");
    printf("                 |  5-  Alta Alquiler                        |\n");
    printf("                 |  6-  Listar Alquileres                    |\n");
    printf("                 |  7-  Listar Categorias                    |\n");
    printf("                 |  8-  Listar Juegos                        |\n");
    printf("                 |  9-  Listar Juegos Categorias             |\n");
    printf("                 | 10-  Listar Alquiler por Cliente          |\n");
    printf("                 | 11-  Listar Importe Total Alq por Cliente |\n");
    printf("                 | 12-  Listar Clientes Sin Alquilar         |\n");
    printf("                 | 13-  Listar Juegos Sin Alquilar           |\n");
    printf("                 | 20-  Salir                                |\n");
    printf("                 |___________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);
    /** Validar **/
    return opcion;
}


int menuModificarCliente()
{
    int opcion;

    system("cls");
    printf("\n                      *** >>>Menu de Opciones<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Nombre                               |\n");
    printf("                 |  2-  Sexo                                 |\n");
    printf("                 |  3-  Telefono                             |\n");
    printf("                 |  4-  Salir                                |\n");
    printf("                 |___________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);
    /** Validar **/
    return opcion;
}



