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

void inicializarMarca(sMarca marcas[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        marcas[i].id= 0;
        strcpy(marcas[i].descripcion,"");
    }
}

void listarMarcas(sMarca marcas[], int tam)
{
    printf("\nLista de Marcas\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",marcas[i].id, marcas[i].descripcion);
    }
    printf("\n\n");
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
        printf("%d  %s\n",jue[i].id, jue[i].descripcion);
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

int obtenerIdMarca(sMarca marcas[], int tamMarca, int indice)
{
    int id;

    for(int i = 0; i < tamMarca; i++)
    {
        if(i == indice)
        {
            id = marcas[i].id;
        }
    }

    return id;
}


int obtenerMarca(sMarca marcas[], int tamMarca, sJuego juego[], int tamJue, int idJue, char desc[])
{
    int flag = 1;

    for(int i = 0; i < tamJue; i++)
    {
        if(juego[i].id == idJue)
        {
            for(int j = 0; j < tamMarca; j++)
            {
                if(marcas[j].id == juego[i].codMarca)
                {
                    strcpy(desc, marcas[j].descripcion);
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

void harcodeoJuegos(sJuego listaJ[], int tamj, sCategoria listaCat[], int tamc, sMarca marcas[], int tamMarca)
{
    sJuego juegos[] =
    {
        {100, "Monopoly", 210.56, obtenerIdCategoria(listaCat, tamc, 0),obtenerIdMarca(marcas, tamMarca, 1)},
        {101, "PES", 311.77, obtenerIdCategoria(listaCat, tamc, 1),obtenerIdMarca(marcas, tamMarca, 2)},
        {102, "Poker", 215.97, obtenerIdCategoria(listaCat, tamc, 2),obtenerIdMarca(marcas, tamMarca, 3)},
        {103, "Sims", 877.12, obtenerIdCategoria(listaCat, tamc, 3),obtenerIdMarca(marcas, tamMarca, 4)},
        {104, "Ludo", 210.56, obtenerIdCategoria(listaCat, tamc, 0),obtenerIdMarca(marcas, tamMarca, 5)},
        {105, "FIFA", 311.77, obtenerIdCategoria(listaCat, tamc, 1),obtenerIdMarca(marcas, tamMarca, 1)},
        {106, "Truco", 215.97, obtenerIdCategoria(listaCat, tamc, 2),obtenerIdMarca(marcas, tamMarca, 2)},
        {107, "Battlefield", 877.12, obtenerIdCategoria(listaCat, tamc, 3),obtenerIdMarca(marcas, tamMarca, 3)},
        {108, "Life", 210.56, obtenerIdCategoria(listaCat, tamc, 0),obtenerIdMarca(marcas, tamMarca, 4)},
        {109, "NHL", 311.77, obtenerIdCategoria(listaCat, tamc, 1),obtenerIdMarca(marcas, tamMarca, 5)},
        {110, "Canasta", 215.97, obtenerIdCategoria(listaCat, tamc, 2),obtenerIdMarca(marcas, tamMarca, 1)},
        {111, "LOL", 877.12, obtenerIdCategoria(listaCat, tamc, 3),obtenerIdMarca(marcas, tamMarca, 2)},
        {112, "GOW", 500.01, obtenerIdCategoria(listaCat, tamc, 1),obtenerIdMarca(marcas, tamMarca, 3)}
    };

    for(int i = 0; i < tamj; i++)
    {
        listaJ[i] = juegos[i];
    }
}

void harcodeoMarcas(sMarca marcas[])
{
    sMarca mar[]=
    {
        {1, "Ditoys"},
        {2, "Vulcanita"},
        {3, "Yetem"},
        {4, "Ruibal"},
        {5, "TopToys"}
    };

    for(int i=0; i < 5; i++)
    {
        marcas[i] = mar[i];
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


void mostrarJuegosSinAlq(sJuego juegos[], int tamJue, sAlquiler alquileres[], int tamAlq)
{
    int flag = 0;
    system("cls");
    printf("\nId  Juego\n\n");

    for(int i = 0; i < tamJue; i++)
    {
        if(juegos[i].isEmpty == 0)
        {
            for(int j = 0; j < tamAlq; j++)
            {
                if(juegos[i].id != alquileres[j].idJuego)
                printf("%d %s\n", juegos[i].id, juegos[i].descripcion);
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
    {
        printf("No hay clientes cargados");
    }
}

void mostrarJuegosXMarca(sJuego jue[], int tamj, sMarca marcas[], int tamMar)
{
     int idMar;
     char descripcion[20];
     int idJue;
     int flag = 0;

     system("cls");
     printf("  *** Listado de Categorias ***\n\n");

     listarMarcas(marcas, tamMar);
     printf("Ingrese id Categoria: ");
     scanf("%d",&idMar);

     //obtenerJuego(jue, tamj, idJue, descripcion);

     system("cls");
     printf("\n--------------------JUEGOS---------------------\n");
     printf("\nID            Descripcion             Categoria\n\n");

     for(int i=0; i< tamMar; i++)
     {
         if(marcas[i].id == idMar)
         {
             for(int j = 0; j < tamj; j++)
             {
                 if(jue[j].codMarca == idMar)
                 {
                     fflush(stdin);
                     printf("%d %20s %20s\n", jue[j].id, jue[j].descripcion, marcas[i].descripcion);
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
