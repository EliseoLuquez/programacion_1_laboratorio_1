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

int altaAlq(sAlquiler listAlq[], int tamAlq, sCliente listCli[], int tamCli, sJuego listJuego[], int tamJue, int* AlqId)
{
    int idAlquiler = *AlqId;
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
            listAlq[indice] = nuevoAlquiler;

            *AlqId = idAlquiler + 1;
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

void mostrarAlquileresXCliente(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli, sCategoria cat[], int tamCat)
{
    int flag = 0;
    int idCli;
    char nombre[51];

    mostrarClientes(cli, tamCli);
    printf("Ingrese Id Cliente: ");
    fflush(stdin);
    scanf("%d", &idCli);
    obtenerCliente(cli, tamCli, idCli, nombre);

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
