#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"

void inicilizarAlq(sAlquiler lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int searchEmptyAlq(sAlquiler lista[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlq(sAlquiler listAlq[], int tamAlq, sCliente listCli[], int tamCli, sJuego listJuego[], int tamJue)
{
    int idAlquiler = 0;
    int idJuegoAux;
    int idClienteAux;
    sAlquiler nuevoAlquiler;
    int indice;
    int clientesCargados;
    clientesCargados = buscarLibreCliente(listCli, tamCli);
    indice = searchEmptyAlq(listAlq, tamAlq);
    int existeJuego;
    int existeCliente;

    if(indice == -1)
    {
        printf("No se pueden cargar mas alquileres");
    }
    else
    {
        if(!clientesCargados)
        {
            printf("No hay Clientes cargados\n\n");
            return 0;
        }
        else
        {
            printf("Ingrese ID del Juego: ");
            scanf("%d", &idJuegoAux);
           /** while(!getStringNumeros("Ingrese Id del Juego: ", idJuegoAux))
            {
                printf("Id de juego incorrecto");
            }
            **/
            nuevoAlquiler.idJuego = idJuegoAux;
            existeJuego = buscarJuegoId(listJuego, tamJue, idJuegoAux);

            /**while(!getStringNumeros("Ingrese Id Cliente: ", idClienteAux))
            {
                printf("Id de Cliente incorrecto");
            }
            **/
            printf("Ingrese ID del Cliente: ");
            scanf("%d", &idClienteAux);
            nuevoAlquiler.idCliente = idClienteAux;
            existeCliente = buscarCliente(listCli,tamCli, idClienteAux);

            printf("ingrese Dia: ");
            scanf("%d",&nuevoAlquiler.fecha.dia);

            printf("ingrese Mes: ");
            scanf("%d",&nuevoAlquiler.fecha.mes);

            printf("ingrese Anio: ");
            scanf("%d",&nuevoAlquiler.fecha.anio);

            nuevoAlquiler.isEmpty = 0;
            nuevoAlquiler.id = idAlquiler+1;
            listAlq[indice] = nuevoAlquiler;

            return 1;
        }
    }
}


//MOSTRAR Alquiler
void mostrarAlquileres(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli, sCategoria cat[], int tamCat)
{
    int flag = 0;

    system("cls");
    printf("Fecha     Id Alq      Cliente     Juego     Categoria\n\n");
    fflush(stdin);
    char descCat[51];
    char descJuego[21];
    char nombreCli[51];

    for(int i=0; i < tamAlq; i++)
    {
        if( alq[i].isEmpty == 0)
        {
            obtenerCliente(cli, tamCli, alq[i].idCliente, nombreCli);
            obtenerJuego(juego, tamJue, alq[i].idJuego, descJuego);
            obtenerCategoria(cat, tamCat, juego, tamJue, alq[i].idJuego, descCat);
            fflush(stdin);
            printf("\n%d/%d/%d %d %s     %s     %s", alq[i].fecha.dia, alq[i].fecha.mes, alq[i].fecha.anio, alq[i].id, nombreCli, descJuego, descCat);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados\n");
    }
    printf("\n\n");
}
 void  hardCordeoAlquileres(sAlquiler alquileres [])
{
        sAlquiler Alquiler [] =
        {
            { 100, 2, 2 , { 12 , 10 , 2018 }},
            { 102, 3, 3 , { 11 , 9 , 2018 }},
            { 103, 1, 4 , { 12 , 1 , 2018 }},
            { 104, 1, 0 , { 9 , 2 , 2018 }},
            { 105, 4, 1 , { 1 , 1 , 2018 }}
        };

        for( int i = 0; i < 5;i++)
        {
            alquileres [i] = Alquiler [i];
        }
}

void mostrarAlquileresXCliente(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli, sCategoria cat[], int tamCat)
{
    int flag = 0;
    int idCli;
    char nombre[51];

    mostrarClientes(cli, tamCli);
    printf("Ingrese Id Cliente: ");
    fflush(stdin);
    scanf("%d", &idCli);
    //obtenerCliente(cli, tamCli, idCli, nombre);

    system("cls");
    printf("ID Alq     Fecha     Cliente     Juego     Categoria\n\n");
    fflush(stdin);
    char descCat[51];
    char descJuego[21];
    char nombreCli[51];

    for(int i=0; i < tamAlq; i++)
    {
        if( alq[i].isEmpty == 0 && alq[i].idCliente == idCli)
        {
            obtenerCliente(cli, tamCli, alq[i].idCliente, nombreCli);
            obtenerJuego(juego, tamJue, alq[i].idJuego, descJuego);
            obtenerCategoria(cat, tamCat, juego, tamJue, alq[i].idJuego, descCat);
            fflush(stdin);
            printf("\n%d/%d/%d %d %s %s %s\n", alq[i].id, alq[i].fecha.dia, alq[i].fecha.mes, alq[i].fecha.anio, nombreCli, descJuego, descCat);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}

void mostrarTotalAlquileresXCliente(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli)
{
    int flag = 0;
    float total = 0;
    int idCli;

    mostrarClientes(cli, tamCli);
    printf("Ingrese Id Cliente: ");
    fflush(stdin);
    scanf("%d", &idCli);

    system("cls");
    fflush(stdin);

    for(int i=0; i < tamAlq; i++)
    {
        if(alq[i].idCliente == idCli)
        {
            for(int j = 0; j < tamJue;j++)
            {
                if(juego[j].id == alq[i].idJuego)
                {
                    total += juego[i].importe;
                    break;
                }
            }
            flag = 1;
        }
    }
    printf("Importe Total: %.2f\n\n", total);
    system("pause");
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}



