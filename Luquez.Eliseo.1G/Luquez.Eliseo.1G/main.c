#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"
#define TAM_JUEGO 10
#define TAM_CLIENTE 10
#define TAM_ALQ 10
#define TAM_CAT 10

int main()
{

    sCliente clientes[TAM_CLIENTE];
    sJuego juegos[TAM_JUEGO];
    sAlquiler alquileres[TAM_ALQ];
    sCategoria categorias[TAM_CAT];

    int primerCliente = 1;
    int r;
    initAlq(alquileres, TAM_ALQ);
    initCliente(clientes, TAM_CLIENTE);
    initJuego(juegos, TAM_JUEGO);
    initCat(categorias, TAM_CAT);

    harcodeoCliente(clientes);
    harcodeoJuegos(juegos);
    harcodeoCategorias(categorias);

    char exit = 'n';
    do{
        switch(optionsCliente())
        {
            case 1:/** ALTA DE CLIENTES **/
                    r = addCliente(clientes, TAM_CLIENTE);
                    primerCliente = 1;
                    break;
            case 2:/** MODIFICAR CLIENTES **/
                    printClientes(clientes, TAM_CLIENTE);
                    modifyCliente(clientes, TAM_CLIENTE);
                    break;
            case 3:/** REMOVER CLIENTES **/
                    printClientes(clientes, TAM_CLIENTE);
                    removeCliente(clientes, TAM_CLIENTE);
                    break;
            case 4:/** LISTADO DE CLIENTES **/
                    sortCliente(clientes, TAM_CLIENTE);
                    printClientes(clientes, TAM_CLIENTE);
                    break;
            case 5:/**  ALTA ALQUILERES **/
                    r = addAlq(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE);
                    break;
            case 6:/** LISTAR ALQUILERES **/
                    printAlquileres(alquileres, TAM_ALQ);
                    break;
            case 7:/** LISTAR JUEGOS **/
                    printJuegos(juegos, TAM_JUEGO);
                    break;
            case 8:/** SALIR **/
                    printf("Saliendo...\n\n");
                    exit = 's';

                    break;

        }
        }while(exit=='n');
    return 0;
}
