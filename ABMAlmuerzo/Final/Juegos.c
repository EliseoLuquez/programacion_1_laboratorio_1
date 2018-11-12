#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"

void inicializarJuego(sJuego lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

void inicializarCat(sCategoria lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].id= 0;
        strcpy(lista[i].descripcion,"");
    }
}



//LISTAR ALGO
void listarCategorias(sCategoria cat[], int tam)
{
    printf("\nLista de categorias\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",cat[i].id, cat[i].descripcion);
    }
    printf("\n\n");
}

void listarJuegos(sJuego jue[], int tamj)
{
    printf("\nLista de Juegos\n\n");

    for(int i=0; i < tamj; i++)
    {
        printf(" %d  %10s\n",jue[i].id, jue[i].descripcion);
    }
    printf("\n\n");
}

int buscarJuegoId(sJuego lista[], int tam, int id)
{

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].id > 0)
        {
            return 1;
            break;
        }
    }

    return 0;
}

void obtenerJuego(sJuego juego[], int tamJ, int idJ, char desc[])
{
    for(int i = 0; i < tamJ; i++)
    {
        if(juego[i].id == idJ)
        {
            strcpy(desc, juego[i].descripcion);
            break;
        }
    }
}

int obtenerIdCategoria(sCategoria cat[], int tamCat, int indice)
{
    int id;

    for(int i = 0; i < tamCat; i++)
    {
        if(i == indice)
        {
            id = cat[i].id;
        }
    }

    return id;
}


int obtenerCategoria(sCategoria listaCat[], int tamCat,sJuego juego[], int tamJue, int idJue, char desc[])
{
    int flag = 1;

    for(int i = 0; i < tamJue; i++)
    {
        if(juego[i].id == idJue)
        {
            for(int j = 0; j < tamCat; j++)
            {
                if(listaCat[j].id == juego[i].codCategoria)
                {
                    strcpy(desc, listaCat[j].descripcion);
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
}

void harcodeoJuegos(sJuego listaJ[], int tamj, sCategoria listaCat[], int tamc)
{
    sJuego juegos[] =
    {
        {100, "Monopoly", 210.56, obtenerIdCategoria(listaCat, tamc, 0)},
        {101, "PES", 311.77, obtenerIdCategoria(listaCat, tamc, 1)},
        {102, "Poker", 215.97, obtenerIdCategoria(listaCat, tamc, 2)},
        {103, "Sims", 877.12, obtenerIdCategoria(listaCat, tamc, 3)},
        {104, "Ludo", 210.56, obtenerIdCategoria(listaCat, tamc, 0)},
        {105, "FIFA", 311.77, obtenerIdCategoria(listaCat, tamc, 1)},
        {106, "Truco", 215.97, obtenerIdCategoria(listaCat, tamc, 2)},
        {107, "Battlefield", 877.12, obtenerIdCategoria(listaCat, tamc, 3)},
        {108, "Life", 210.56, obtenerIdCategoria(listaCat, tamc, 0)},
        {109, "NHL", 311.77, obtenerIdCategoria(listaCat, tamc, 1)},
        {110, "Canasta", 215.97, obtenerIdCategoria(listaCat, tamc, 2)},
        {111, "LOL", 877.12, obtenerIdCategoria(listaCat, tamc, 3)},
        {112, "GOW", 500.01, obtenerIdCategoria(listaCat, tamc, 1)}
    };

    for(int i = 0; i < tamj; i++)
    {
        listaJ[i] = juegos[i];
    }
}


void harcodeoCategorias(sCategoria categ[], int tamC)
{
    sCategoria cat[]=
    {
        {0, "Mesa"},
        {1, "Consola"},
        {2, "Cartas"},
        {3, "PC"}
    };

    for(int i=0; i < tamC; i++)
    {
        categ[i] = cat[i];
    }
}

void mostrarJuegosXCategoria(sJuego jue[], int tamj, sCategoria cat[], int tamCat)
{
     int idCat;
     char descripcion[20];
     int idJue;
     int flag = 0;

     system("cls");
     printf("  *** Listado de Categorias ***\n\n");

     listarCategorias(cat, tamCat);
     printf("Ingrese id Categoria: ");
     scanf("%d",&idCat);

     obtenerJuego(jue, tamj, idJue, descripcion);

     system("cls");
     printf("\n--------------------JUEGOS---------------------\n");
     printf("\nID            Descripcion             Categoria\n\n");

     for(int i=0; i< tamCat; i++)
     {
         if(cat[i].id == idCat)
         {
             for(int j = 0; j < tamj; j++)
             {
                 if(jue[j].codCategoria == idCat)
                 {
                     fflush(stdin);
                     printf("%d %20s %20s\n", jue[j].id, jue[j].descripcion, cat[i].descripcion);
                     flag = 1;
                 }
             }
         }
     }
     printf("\n\n");

     if(flag == 0)
     {
         printf("No hay Juegos que mostrar\n\n");
     }
}
