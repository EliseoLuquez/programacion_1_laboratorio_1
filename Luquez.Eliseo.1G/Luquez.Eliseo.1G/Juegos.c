#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"


void initJuego(sJuego* list, int len)
{
    for(int i = 0; i < len; i++)
    {
        list[i].isEmptyJuego = 1;
    }
}

void initCat(sCategoria* list, int len)
{
    for(int i = 0; i < len; i++)
    {
        list[i].isEmptyCat = 1;
    }
}

int searchEmptyJuego(sJuego* list, int len)
{
    int r = -1;
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmptyJuego == 1)
        {
            r = i;
            break;
        }
    }
    return r;
}

int findJuegoById(sJuego* list, int len, int id)
{
    int r = -1;

    for(int i = 0; i < len; i++)
    {
        if((list[i].isEmptyJuego == 0)&&(list[i].codigoJuego == id))
        {
            r = i; /** LE ASIGNO LA POSICION  ENCONTRADA Y SALGO **/
            break;
        }
    }
    return r;
}


void harcodeoJuegos(sJuego* listJue)
{

    sJuego x[]={
    {1, "FIFA", 300,1},
    {2, "AGE", 220, 2 },
    {3, "LUDO", 150, 4},
    {4, "MarioBross", 200, 2},
    {5, "GTA", 250, 5},
    {6, "MONOPOLY", 150, 5},
    {7, "GODofWAR", 200, 5 },
    {8, "NFS", 250, 5}
    };
    for(int i = 0; i< 5;i++)
    {
        listJue[i] = x[i];
    }
}

void harcodeoCategorias(sCategoria* list)
{
    sCategoria x[]={
        {1,"Deportes"},
        {2,"Aventuras"},
        {3,"Estrategia"},
        {4,"Mesa"},
        {5,"Accion"}
    };

    for(int i=0; i < 5; i++)
    {
        list[i] = x[i];
    }
}

void printJuegos(sJuego* listJue, int lenJue)
{
    system("cls");

    for(int i = 0; i < lenJue; i++)
    {

        if(listJue[i].isEmptyJuego == 0)
        {
            printf("\n\n-Cod.Juego %d \n-Descripcion %s \n-Importe %.2f \n-Categoria %s\n\n",listJue[i].codigoJuego, listJue[i].descripcion, listJue[i].importe, listJue[i].importe);
        }
    }
    system("pause");
}


void printJuegosMesa(sJuego* listJue, int lenJue)
{
    system("cls");

    for(int i = 0; i < lenJue; i++)
    {
        if((listJue[i].isEmptyJuego == 0)&&(listJue[i].descripcion == "Mesa"))
        {
            printf("\n\n-Cod.Juego %d \n-Descripcion %s \n-Importe %.2f \n-Categoria %s\n\n",listJue[i].codigoJuego, listJue[i].descripcion, listJue[i].importe, listJue[i].importe);
        }
    }
    system("pause");
}
