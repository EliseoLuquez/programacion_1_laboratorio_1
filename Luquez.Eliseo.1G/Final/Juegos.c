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


void harcodeoJuegos(sJuego* list)
{

    sJuego x[]={
    {1, "Deportes", 300, 1},
    {2, "Estrategia", 220, 2 },
    {3, "Shooter", 150, 4},
    {4, "Aventuras", 200, 5 },
    {5, "Accion", 250, 3}
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
}

void harcodeoCategorias(sCategoria* list)
{
    sCategoria x[]={
        {1,"Deportes"},
        {2,"Aventuras"},
        {3,"Estrategia"},
        {4,"Shooter"},
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
