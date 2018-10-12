#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"

int optionsAlquiler()
{
    int option;

    system("cls");
    printf("\n*** Menu de Alquiler ***\n\n");
    printf("\n    1- Altas\n");
    printf("\n    2- Modificar\n");
    printf("\n    3- Baja\n");
    printf("\n    4- Informar\n");
    printf("\n    5- Salir\n");
    printf("\n\n** Ingrese Opcion **\n");
    scanf("%d", &option);

    return option;
}

void initAlq(sAlquiler* list, int len)
{
    for(int i = 0; i < len; i++)
    {
        list[i].isEmptyAlquiler = 1;
    }
}

int searchEmptyAlq(sAlquiler* list, int len)
{
    int r = -1;
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmptyAlquiler == 1)
        {
            r = i;
            break;
        }
    }
    return r;
}


int addAlq(sAlquiler* listAlq, int lenAlq, sCliente* listCli, int lenCli, sJuego* listJuego, int lenJue)
{
    sAlquiler newAlquiler;
    int r;
    int index;
    char auxCodCli[5];
    char auxCodJue[5];
    sFecha fecha;

    if(listAlq != NULL && lenAlq > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyAlq(listAlq,lenAlq);
        printf("\n** Nuevo Alquiler **\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            r = -1;
            system("pause");
        }
        else
        {
            printf("\nCodigo Alquiler %d \n",index) ;
            newAlquiler.codigoAlquiler = index;

            if(!getStringNumeros("\nIngrese Codigo Cliente: ", auxCodCli))
            {
                printf("El codigo debe ser numerico.\n\n") ;
                system("pause");
                system("cls");
            }
            else
            {
                newAlquiler.codCliente = atoi(auxCodCli);
            }
            if(findClienteById(listCli, lenCli, newAlquiler.codCliente)== -1)
            {
                printf("\nNo Existe Cliente.\n\n");
                system("pause");
            }

            if(!getStringNumeros("\nIngrese Codigo de Juego: ", auxCodJue))
            {
                printf("\nEl codigo debe ser numerico.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                newAlquiler.codJuego = atoi(auxCodJue);
            }
            if(findJuegoById(listJuego, lenJue, auxCodJue)== -1)
            {
                    printf("\nNo Existe Juego.\n\n");
                    system("pause");
            }

            if(!getStringNumeros("\nIngrese Dia: ",fecha.dia)&&(fecha.dia < 1 || fecha.dia > 31))
            {
                printf("\nError al ingresar Dia.\n\n");
                system("pause");
                system("cls");
            }
            else if(!getStringNumeros("\nIngrese Mes : ",fecha.mes)&&(fecha.mes < 1 || fecha.mes > 12))
            {
                printf("\nError al ingresar Mes.\n\n");
                system("pause");
                system("cls");
            }
            else if(!getStringNumeros("\nIngrese Anio: ",fecha.anio))
            {
                printf("\nError al ingresar Anio.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(newAlquiler.fecha.dia, fecha.dia);
                strcpy(newAlquiler.fecha.mes, fecha.mes);
                strcpy(newAlquiler.fecha.anio, fecha.anio);

                newAlquiler.isEmptyAlquiler = 0;
                listAlq[index] = newAlquiler;
                system("pause");
                system("cls");
               // printf("\n\nNUEVO ALQUILER INGRESADO\n\n");
                printf("\n\n\n");
                system("pause");
                r = 0 ;
            }
        }
    }
    else
    {
        r = -1 ;
    }
    return r;
}


void printAlq(sAlquiler listAlq)
{
    printf("\n-Cod.Alquiler: %d  \n-Cod.Juego: %s  \n-Cod. Cliente: %s  \n-Fecha: %s / %s / &s  \n\n",
           listAlq.codigoAlquiler, listAlq.codJuego, listAlq.codCliente, listAlq.fecha.dia, listAlq.fecha.mes, listAlq.fecha.anio);
}




void printAlquileres(sAlquiler* listAlq, int lenAlq)
{
    system("cls");
    printf("\n\n-Cod.Alquiler \n-Cod.Juego \n-Cod.Cliente \n-Fecha\n\n");

    for(int i = 0; i < lenAlq; i++)
    {

        if(listAlq[i].isEmptyAlquiler == 0)
        {
            printAlq(listAlq[i]);
        }
    }
    system("pause");
}
