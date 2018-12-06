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
    printf("\n                  *** >>>Menu de Opciones<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Cliente                              |\n");
    printf("                 |  2-  Alquiler                             |\n");
    printf("                 |  3-  Juegos                               |\n");
    printf("                 |  4-  Informes                             |\n");
    printf("                 |  5-  Salir                                |\n");
    printf("                 |___________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);
    /** Validar **/
    return opcion;
}

int menuCliente()
{
    int opcion;

    system("cls");
    printf("\n                      *** >>>Menu de Clientes<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Alta                                 |\n");
    printf("                 |  2-  Baja                                 |\n");
    printf("                 |  3-  Modificar                            |\n");
    printf("                 |  4-  Mostrar                              |\n");
    printf("                 |  5-  Salir                                |\n");
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

int menuAlquiler()
{
    int opcion;

    system("cls");
    printf("\n                      *** >>>Menu de Alquiler<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Alta                                 |\n");
    printf("                 |  2-  Mostrar                              |\n");
    printf("                 |  3-  Salir                                |\n");
    printf("                 |___________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);
    /** Validar **/
    return opcion;
}

int menuJuego()
{
    int opcion;

    system("cls");
    printf("\n                      *** >>>Menu de Juego<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Alta                                 |\n");
    printf("                 |  2-  Mostrar Juego                        |\n");
    printf("                 |  3-  Mostrar Categoria                    |\n");
    printf("                 |  4-  Mostrar Marca                        |\n");
    printf("                 |  5-  Salir                                |\n");
    printf("                 |___________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);
    /** Validar **/
    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n                      *** >>>Menu de Informes<<< ***\n\n");
    printf("                  ___________________________________________________\n");
    printf("                 |                                                   |\n");
    printf("                 |  1-  Mostrar Clientes por sexo y nombre           |\n");
    printf("                 |  2-  Mostrar Juegos por Categoria                 |\n");
    printf("                 |  3-  Mostrar Alquileres por Cliente               |\n");
    printf("                 |  4-  Total Importe de Alquiler por Cliente        |\n");
    printf("                 |  5-  Clientes que no Aluilaron                    |\n");
    printf("                 |  6-  Juegos que no se Alquilaron                  |\n");
    printf("                 |  7-  Telefono de Clientes que Alquilaron por Fecha|\n");
    printf("                 |  8-  Juegos Alquilados por Mujeres                |\n");
    printf("                 |  9-  Juegos mas Alquilados por Hombres            |\n");
    printf("                 | 10-  Alquiler por Juego                           |\n");
    printf("                 | 11-  Recaudacion por fecha                        |\n");
    printf("                 | 12-  Mostrar Juegos por Marca                     |\n");
    printf("                 | 13-  Mostrar cuantos Alquileres tiene c/Marca     |\n");
    printf("                 | 14-  Mostrar Alquiler por Marca                   |\n");
    printf("                 | 15-  Salir                                        |\n");
    printf("                 |___________________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);
    /** Validar **/
    return opcion;
}

/** \brief compara dos fechas
 *
 * \param fecha del arra alquileres
 * \param fecha ingresada por teclado.
 * \return no tiene retorno.
 *
 */

int compararFecha(sFecha fecha1, sFecha fecha2)
{
    int retAux = 0;

    if (fecha1.dia== fecha2.dia && fecha1.mes==fecha2.mes && fecha1.anio==fecha2.anio )
    {
        retAux=1;
    }
    return retAux;
}

void funciones_RecaudacionPorFecha(sAlquiler alquiler[], int tamAlq, sCliente cliente[], int tamCli, sJuego juego[], int tamJue, sFecha fecha[])
{
    system("cls");
    sFecha fechaAux;
    int recaudacion = 0;
    int existe=0;

    printf("\n\n *****    Recaudacion Total por Fecha    ***** \n\n\n");

    printf(" Ingrese dia: ");
    scanf("%d",&fechaAux.dia);
    printf("\n Ingrese mes:  ");
    scanf("%d", &fechaAux.mes);
    printf("\n Ingrese anio:  ");
    scanf("%d", &fechaAux.anio);

    for (int i=0; i<tamAlq; i++)
    {
        if(alquiler[i].isEmpty == 0 && compararFecha(alquiler[i].fecha,fechaAux))
        {
            for (int j = 0;j < tamJue;j++)
            {
                if(alquiler[i].idJuego == juego[j].id && juego[j].isEmpty == 0)
                {
                    recaudacion = recaudacion + juego[j].importe;
                    existe = 1;
                }
            }
        }
    }

    if(existe == 0)
    {
        printf("\nNo hay alquileres en esa fecha.\n");
    }
    else
    {
        printf("\nFecha         Recuadacion\n\n");
        printf("\%02d/%02d/%02d    %d\n\n", fechaAux.dia, fechaAux.mes, fechaAux.anio, recaudacion);
    }

}
