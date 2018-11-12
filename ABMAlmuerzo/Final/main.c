#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"
#define TAM_JUEGO 15
#define TAM_CLIENTE 10
#define TAM_ALQ 10
#define TAM_CAT 4

int main()
{
    char seguir = 's';
    int idAlquiler = 0;
    fflush(stdin);
    sCategoria categorias[TAM_CAT];
    sCliente clientes[TAM_CLIENTE];
    sAlquiler alquileres[TAM_ALQ];
    sJuego juegos[TAM_JUEGO];

    inicializarClientes(clientes, TAM_CLIENTE);
    inicilizarAlq(alquileres, TAM_ALQ);
    inicializarJuego(juegos, TAM_JUEGO);
    inicializarCat(categorias, TAM_CAT);

    harcodeoClientes(clientes);
    harcodeoCategorias(categorias, TAM_CAT);
    harcodeoJuegos(juegos, TAM_JUEGO, categorias, TAM_CAT);

    do
    {
        switch(menu())
        {
        case 1:
            altaCliente(clientes, TAM_CLIENTE);
            break;
        case 2:
            bajaCliente(clientes,TAM_CLIENTE);
            break;
        case 3:
            modificarCliente(clientes, TAM_CLIENTE);
            system("pause");
            break;
        case 4:
            mostrarClientes(clientes, TAM_CLIENTE);
            system("pause");
            break;
        case 5:
            altaAlq(alquileres, TAM_ALQ, clientes, TAM_CLIENTE, juegos, TAM_JUEGO, &idAlquiler);
            break;
        case 6:
            mostrarAlquileres(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE, categorias, TAM_CAT);
            system("pause");
            break;
        case 7:
            listarCategorias(categorias, TAM_CAT);
            system("pause");
            break;
        case 8:
            listarJuegos(juegos, TAM_JUEGO);
            system("pause");
            break;
        case 9:
            mostrarJuegosXCategoria(juegos, TAM_JUEGO, categorias, TAM_CAT);
            system("pause");
            break;
        case 10:
            mostrarAlquileresXCliente(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE, categorias, TAM_CAT);
            system("pause");
            break;
        case 11:
          //  mostrarAlmuerzos(almuerzos, 20, comidas, 5, empleados, TAM);
            system("pause");
            break;
        case 20:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
