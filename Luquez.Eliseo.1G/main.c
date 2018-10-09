#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#define TAM_JUEGO 10
#define TAM_CLIENTE 10

int main()
{
    //sFecha fechas[];
    //sCategoria categorias[];
    //sJuego[];
    sCliente clientes[TAM_CLIENTE];

    int primerCliente = 0;

    initCliente(clientes, TAM_CLIENTE);
    harcodeoCliente(clientes);
    char exit = 'n';
    do{
        switch(options())
        {
            case 1:
                    addCliente(clientes, TAM_CLIENTE);
                    primerCliente = 1;
                    break;
            case 2:
                    modifyCliente(clientes, TAM_CLIENTE);
                    break;
            case 3:
                    removeCliente(clientes, TAM_CLIENTE);
                    break;
            case 4:
                    sortCliente(clientes, TAM_CLIENTE, 0);
                    break;






        }
        }while(exit=='n');
    return 0;
}
