#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"
#define TAM_JUEGO 20
#define TAM_CLIENTE 20
#define TAM_ALQ 10
#define TAM_CAT 10
#define TAM_FECHA 10
#define TAM_MARCA 10

int main()
{
    char seguir = 's';

    fflush(stdin);
    sCategoria categorias[TAM_CAT];
    sCliente clientes[TAM_CLIENTE];
    sAlquiler alquileres[TAM_ALQ];
    sJuego juegos[TAM_JUEGO];
    sMarca marca[TAM_MARCA];
    sFecha fecha[TAM_FECHA];


    inicializarClientes(clientes, TAM_CLIENTE);
    inicilizarAlq(alquileres, TAM_ALQ);
    juegos_inicializarJuego(juegos, TAM_JUEGO);
    juegos_inicializarMarca(marca, TAM_MARCA);
    juegos_inicializarCat(categorias, TAM_CAT);

    harcodeoClientes(clientes);
    juegos_harcodeoCategorias(categorias);
    juegos_harcodeoMarca(marca, 5);
    juegos_harcodeoJuegos(juegos, marca, 5, categorias, 4);
    hardCordeoAlquileres(alquileres);

    do
    {
        switch(menu())
        {
        case 1:
            switch(menuCliente())
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
                    break;
            }
            break;

        case 2:
            switch(menuAlquiler())
            {
                case 1:
                    altaAlq(alquileres, TAM_ALQ, clientes, TAM_CLIENTE, juegos, TAM_JUEGO);
                    break;
                case 2:
                    mostrarAlquileres(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE, categorias, TAM_CAT, marca, TAM_MARCA);
                    system("pause");
                    break;
                case 3:
                    break;
            }
            break;

        case 3:
            switch(menuJuego())
            {
                case 1:
                    juegos_altaJuego(juegos, TAM_JUEGO, categorias, TAM_CAT);
                    break;
                case 2:
                    juegos_listarJuegos(juegos, TAM_JUEGO);
                    system("pause");
                    break;
                case 3:
                    juegos_listarCategorias(categorias, TAM_CAT);
                    system("pause");
                    break;
                case 4:
                    juegos_listarMarca(marca, TAM_MARCA);
                    system("pause");
                    break;
                case 5:
                    break;
            }
            break;

        case 4:
            switch(menuInformes())
            {
                case 1:
                    mostrarClientes(clientes, TAM_CLIENTE);
                    mostrarClientesPorSexoyNombre(clientes, TAM_CLIENTE);
                    mostrarClientes(clientes, TAM_CLIENTE);
                    system("pause");
                    break;
                case 2:
                    juegos_mostrarJuegosXCategoria(juegos, TAM_JUEGO, categorias, TAM_CAT);
                    system("pause");
                    break;
                case 3:
                    mostrarAlquileresXCliente(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE, categorias, TAM_CAT);
                    system("pause");
                    break;
                case 4:
                    mostrarTotalAlquileresXCliente(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE);
                    system("pause");
                    break;
                case 5:
                    alquileres_ClientesQueNoAlquilaron(alquileres, TAM_ALQ, clientes, TAM_CLIENTE);
                    system("pause");
                    break;
                case 6:
                    alquileres_JuegosQueNoAlquilaron(alquileres, TAM_ALQ, juegos, TAM_JUEGO);
                    system("pause");
                    break;
                case 7:
                    Alquileres_TelefonoDeAlquilerPorFecha(clientes, TAM_CLIENTE, alquileres, TAM_ALQ, fecha, juegos, TAM_JUEGO);
                    system("pause");
                    break;
                case 8:
                    alquileres_JuegosAlqPorMujeres(alquileres, TAM_ALQ, clientes, TAM_CLIENTE, juegos, TAM_JUEGO);
                    system("pause");
                    break;
                case 9:
                    alquileres_JuegosMasAlquiladosPorHombres(alquileres, TAM_ALQ, clientes, TAM_CLIENTE, juegos, TAM_JUEGO);
                    system("pause");
                    break;
                case 10:
                    alquileres_MostrarAlquileresPorJuego(alquileres, TAM_ALQ, juegos, TAM_JUEGO, clientes, TAM_CLIENTE);
                    system("pause");
                    break;
                case 11:
                    funciones_RecaudacionPorFecha(alquileres, TAM_ALQ, clientes, TAM_CLIENTE, juegos, TAM_JUEGO, fecha);
                    system("pause");
                    break;
                case 12:
                    juegos_mostrarJuegosXMarca(juegos, TAM_JUEGO, marca, TAM_MARCA);
                    system("pause");
                    break;
                case 13:
                    alquileres_MostrarCantidadDeAlqPorMarca(alquileres, TAM_ALQ, juegos, TAM_JUEGO, marca, TAM_MARCA);
                    system("pause");
                    break;
                case 14:
                    alquileres_MostrarAlquileresPorMarca(alquileres, TAM_ALQ, juegos, TAM_JUEGO, marca, TAM_MARCA, clientes, TAM_CLIENTE);
                    system("pause");
                    break;
                case 15:
                    break;
            }
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
