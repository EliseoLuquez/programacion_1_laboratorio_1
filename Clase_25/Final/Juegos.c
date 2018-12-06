#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"

void juegos_inicializarJuego(sJuego lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

void juegos_inicializarMarca(sMarca marca[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        marca[i].id = 0;
        strcpy(marca[i].nombreMarca,"");
    }
}

void juegos_inicializarCat(sCategoria lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].id = 0;
        strcpy(lista[i].descripcion,"");
    }
}

int juegos_BuscarLibre(sJuego juego[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(juego[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int juegos_altaJuego(sJuego juego[], int tamJue, sCategoria cat[], int tamC)
{
    system("cls");
    int idJuego = 0;
    sJuego nuevoJuego;
    int indice;
    char descripcionAux[20];
    char importeAux[10];
    char idCategAux[5];
    indice = juegos_BuscarLibre(juego, tamJue);
    int existeJuego;

    if(indice == -1)
    {
        printf("No se pueden cargar mas Juegos");
    }
    else
    {
            printf("Ingrese Nombre del Juego: ");
            scanf("%s", descripcionAux);
            strcpy(nuevoJuego.descripcion, descripcionAux);

            printf("Ingrese Importe del Juego: ");
            scanf("%s", importeAux);
            nuevoJuego.importe = atoi(importeAux);

            juegos_listarCategorias(cat, tamC);
            printf("Ingrese Id Categoria: ");
            scanf("%s", idCategAux);
            nuevoJuego.codCategoria = atoi(idCategAux);

            nuevoJuego.isEmpty = 0;
            juego[indice] = nuevoJuego;
            nuevoJuego.id = idJuego++;
            return 1;
        }
}



//LISTAR ALGO
void juegos_listarCategorias(sCategoria cat[], int tam)
{
    system("cls");
    printf("\nLista de categorias\n\n");
    printf("\nID     Categorias\n\n");
    for(int i=0; i < tam; i++)
    {
        if(cat[i].id != 0)
        {
            printf(" %d  %10s\n",cat[i].id, cat[i].descripcion);
        }
    }

    printf("\n\n");
}

void juegos_listarMarca(sMarca marca[], int tamM)
{
    system("cls");
    printf("\nLista de Marcas\n\n");
    printf("\nID     Marcas\n\n");

    for(int i=0; i < tamM; i++)
    {
        if(marca[i].id != 0)
        {
            printf(" %d  %10s\n",marca[i].id, marca[i].nombreMarca);
        }
    }

    printf("\n\n");
}

void juegos_listarJuegos(sJuego jue[], int tamj)
{
    system("cls");
    printf("\nLista de Juegos\n\n");

    for(int i=0; i < tamj; i++)
    {
        if(jue[i].isEmpty != 1)
        {
            printf(" %d  %10s\n",jue[i].id, jue[i].descripcion);
        }
    }
    printf("\n\n");
}

int juegos_buscarJuegoId(sJuego lista[], int tam, int id)
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

void juegos_obtenerJuego(sJuego juego[], int tamJ, int idJ, char desc[])
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

int juegos_obtenerIdCategoria(sCategoria cat[], int tamCat, int indice)
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

int juegos_obtenerIdMarca(sMarca marca[], int tamM, int indice)
{
    int id;

    for(int i = 0; i < tamM; i++)
    {
        if(i == indice)
        {
            id = marca[i].id;
        }
    }

    return id;
}

int juegos_obtenerMarca(sMarca marca[], int tamM, sJuego juego[], int tamJue, int idJue, char nombre[])
{
    int flag = 1;

    for(int i = 0; i < tamJue; i++)
    {
        if(juego[i].id == idJue)
        {
            for(int j = 0; j < tamM; j++)
            {
                if(marca[j].id == juego[i].idMarca)
                {
                    strcpy(nombre, marca[j].nombreMarca);
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

int juegos_obtenerCategoria(sCategoria listaCat[], int tamCat,sJuego juego[], int tamJue, int idJue, char desc[])
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

void juegos_harcodeoJuegos(sJuego listaJ[], sMarca marca[], int tamM, sCategoria listaCat[], int tamc)
{
    sJuego juegos[] =
    {
        {100, "Ajedrez", 210, juegos_obtenerIdMarca(marca,tamM, 4), juegos_obtenerIdCategoria(listaCat, tamc, 1),0},
        {101, "PES", 311, juegos_obtenerIdMarca(marca,tamM, 2), juegos_obtenerIdCategoria(listaCat, tamc, 2),0},
        {102, "Poker", 215, juegos_obtenerIdMarca(marca,tamM, 4), juegos_obtenerIdCategoria(listaCat, tamc, 3),0},
        {103, "Sims", 877, juegos_obtenerIdMarca(marca,tamM, 2), juegos_obtenerIdCategoria(listaCat, tamc, 4),0},
        {104, "Ludo", 210, juegos_obtenerIdMarca(marca,tamM, 4), juegos_obtenerIdCategoria(listaCat, tamc, 1),0},
        {105, "FIFA", 311, juegos_obtenerIdMarca(marca,tamM, 2), juegos_obtenerIdCategoria(listaCat, tamc, 2),0},
        {106, "Truco", 215, juegos_obtenerIdMarca(marca,tamM, 1), juegos_obtenerIdCategoria(listaCat, tamc, 3),0},
        {107, "CoD", 877, juegos_obtenerIdMarca(marca,tamM, 3), juegos_obtenerIdCategoria(listaCat, tamc, 4),0},
        {108, "Life", 210, juegos_obtenerIdMarca(marca,tamM, 5), juegos_obtenerIdCategoria(listaCat, tamc, 1),0},
        {109, "NHL", 311, juegos_obtenerIdMarca(marca,tamM, 1), juegos_obtenerIdCategoria(listaCat, tamc, 2),0},
        {110, "Canasta", 215, juegos_obtenerIdMarca(marca,tamM, 4), juegos_obtenerIdCategoria(listaCat, tamc, 3),0},
        {111, "LOL", 877, juegos_obtenerIdMarca(marca,tamM, 5), juegos_obtenerIdCategoria(listaCat, tamc, 4),0},
        {112, "GOW", 500, juegos_obtenerIdMarca(marca,tamM, 3), juegos_obtenerIdCategoria(listaCat, tamc, 1),0}
    };

    for(int i = 0; i < 13; i++)
    {
        listaJ[i] = juegos[i];
    }
}


void juegos_harcodeoCategorias(sCategoria categ[])
{
    sCategoria cat[]=
    {
        {1, "Mesa"},
        {2, "Consola"},
        {3, "Cartas"},
        {4, "PC"}
    };

    for(int i=0; i < 4; i++)
    {
        categ[i] = cat[i];
    }
}

void juegos_harcodeoMarca(sMarca marca[], int tamM)
{
    sMarca m[]=
    {
        {1, "Ditoys"},
        {2, "Vulcanita"},
        {3, "Yetem"},
        {4, "Ruibal"},
        {5, "TopToys"}
    };

    for(int i=0; i < 5; i++)
    {
        marca[i] = m[i];
    }
}


void juegos_mostrarJuegosXCategoria(sJuego jue[], int tamj, sCategoria cat[], int tamCat)
{
     int idCat;
     char descripcion[20];
     int idJue;
     int flag = 0;

     system("cls");
     printf("  *** Listado de Categorias ***\n\n");

     juegos_listarCategorias(cat, tamCat);
     printf("Ingrese id Categoria: ");
     fflush(stdin);
     scanf("%d",&idCat);

     juegos_obtenerJuego(jue, tamj, idJue, descripcion);

     system("cls");
     printf("\n--------------------JUEGOS---------------------\n");
     printf("\nID            Descripcion             Categoria\n\n");

     for(int i=0; i< tamCat; i++)
     {
         if(cat[i].id == idCat)
         {
             for(int j = 0; j < tamj; j++)
             {
                 if(jue[j].codCategoria == idCat && jue[i].isEmpty != 1)
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



void juegos_mostrarJuegosXMarca(sJuego jue[], int tamj, sMarca marca[], int tamM)
{
     int idMarcaAux;
     char descripcion[20];
     int idJue;
     int flag = 0;

     system("cls");
     printf("  *** Listado de Marcas ***\n\n");

     juegos_listarMarca(marca, tamM);
     printf("Ingrese id Marca: ");
     fflush(stdin);
     scanf("%d",&idMarcaAux);

     juegos_obtenerJuego(jue, tamj, idJue, descripcion);

     system("cls");
     printf("\n--------------------JUEGOS---------------------\n");
     printf("\nID   Descripcion    Marcas\n\n");

     for(int i=0; i< tamj; i++)
     {
         if(jue[i].idMarca == idMarcaAux)
         {
             for(int j = 0; j < tamM; j++)
             {
                 if(marca[j].id == idMarcaAux && jue[i].isEmpty != 1)
                 {
                     printf("%d  %10s  %10s\n", jue[i].id, jue[i].descripcion, marca[j].nombreMarca);
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


