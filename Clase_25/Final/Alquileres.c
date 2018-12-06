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

int altaAlq(sAlquiler listAlq[], int tamAlq, sCliente listCli[], int tamCli, sJuego listJuego[], int tamJue)
{
    int idAlquiler = -1;
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
            existeJuego = juegos_buscarJuegoId(listJuego, tamJue, idJuegoAux);

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

            nuevoAlquiler.id = idAlquiler++;
            return 1;
        }
    }
}


//MOSTRAR Alquiler
void mostrarAlquileres(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli, sCategoria cat[], int tamCat, sMarca marca[], int tamM)
{
    int flag = 0;

    system("cls");
    printf("  Fecha     Id Alq    Cliente     Juego   Marca  Categoria\n\n");
    fflush(stdin);
    char descCat[51];
    char descJuego[21];
    char nombreCli[51];
    char marcaNombre[20];

    for(int i=0; i < tamAlq; i++)
    {
        if( alq[i].isEmpty == 0)
        {
            obtenerCliente(cli, tamCli, alq[i].idCliente, nombreCli);
            juegos_obtenerJuego(juego, tamJue, alq[i].idJuego, descJuego);
            juegos_obtenerMarca(marca, tamM, juego, tamJue, alq[i].idJuego, marcaNombre);
            juegos_obtenerCategoria(cat, tamCat, juego, tamJue, alq[i].idJuego, descCat);
            fflush(stdin);
            printf("\n%2d/%2d/%d %4d  %10s %10s %10s %10s\n",alq[i].fecha.dia, alq[i].fecha.mes, alq[i].fecha.anio, alq[i].id, nombreCli, descJuego, marcaNombre, descCat);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados\n");
    }
    printf("\n\n");
}
 void  hardCordeoAlquileres(sAlquiler alquileres[])
{
        sAlquiler Alquiler [] =
        {
            {1000, 101, 100, { 12 , 10 , 2018 },0},
            {1001, 101, 101, { 11 , 11 , 2018 },0},
            {1002, 112, 102, { 12 , 11 , 2018 },0},
            {1003, 110, 103, {  9 , 12 , 2018 },0},
            {1004, 101, 101, { 11 , 12 , 2018 },0},
            {1005, 112, 102, { 12 , 12 , 2018 },0},
            {1006, 110, 103, { 19 , 12 , 2018 },0},
            {1007, 108, 104, { 27 , 12 , 2018 },0}
        };

        for( int i = 0; i < 8;i++)
        {
            alquileres [i] = Alquiler [i];
        }
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
    //obtenerCliente(cli, tamCli, idCli, nombre);

    system("cls");
    printf("                *** Alquileres por Cliente ***\n\n");
    printf(" Fecha     Id Alq    Cliente     Juego     Categoria\n\n");
    fflush(stdin);
    char descCat[51];
    char descJuego[21];
    char nombreCli[51];

    for(int i=0; i < tamAlq; i++)
    {
        if( alq[i].isEmpty == 0 && alq[i].idCliente == idCli)
        {
            obtenerCliente(cli, tamCli, alq[i].idCliente, nombreCli);
            juegos_obtenerJuego(juego, tamJue, alq[i].idJuego, descJuego);
            juegos_obtenerCategoria(cat, tamCat, juego, tamJue, alq[i].idJuego, descCat);
            fflush(stdin);
            printf("\n%2d/%2d/%d %4d  %10s %10s  %10s\n",alq[i].fecha.dia, alq[i].fecha.mes, alq[i].fecha.anio, alq[i].id, nombreCli, descJuego, descCat);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}

void mostrarTotalAlquileresXCliente(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli)
{
    int flag = 0;
    int total = 0;
    int idCli;
    int promedio = 0;
    int cant = 0;
    printf("*** Total Alquileres por Cliente ***\n\n");
    mostrarClientes(cli, tamCli);
    printf("Ingrese Id Cliente: ");
    fflush(stdin);
    scanf("%d", &idCli);

    system("cls");
    fflush(stdin);

    for(int i=0; i < tamAlq; i++)
    {
        if(alq[i].idCliente == idCli)
        {
            for(int j = 0; j < tamJue;j++)
            {
                if(juego[j].id == alq[i].idJuego)
                {
                    total = total + juego[j].importe;
                    cant++;
                    break;
                }
            }
            promedio = total/cant;
            flag = 1;
        }
    }
    printf("*** Total Alquileres por Cliente ***\n\n");
    printf("El Cliente %s:\n\n", cli[idCli].nombreCliente);
    printf("Pago un Importe Total de Alquiler: %d\n", total);
    printf("Pago un Promedio Total de Alquiler: %d\n\n\n", promedio);

    system("pause");
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}

/*
void mostrarTotalAlquileresyPromedio(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue)
{
    int flag = 0;
    int total = 0;
    int idCli;
    float promedio;
    int cant = 0;
   // mostrarClientes(cli, tamCli);
   // printf("Ingrese Id Cliente: ");
   // fflush(stdin);
   // scanf("%d", &idCli);

    system("cls");
    fflush(stdin);

    for(int i=0; i < tamAlq; i++)
    {
        for(int j = 0; j < tamJue;j++)
        {
            if(juego[j].id == alq[i].idJuego)
            {
                total += juego[i].importe;
                cant++;
                break;
            }
        }
    }
    promedio =(float)total/cant;
    flag = 1;

    printf("Importe Total: %.2f\n\n", total);
    printf("Promedio Total: %.2f\n\n", promedio);
    system("pause");
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}
*/

void alquileres_ClientesQueNoAlquilaron(sAlquiler alq[], int tamAlq, sCliente clientes[], int tamCli)
{
    int flag = 0;
    int flagAlq = 0;
    system("cls");
    fflush(stdin);
    printf("*** Clientes Sin Alquileres ***\n\n");
    printf("\nId   Nombre   Sexo   Telefono  \n\n");

    for(int i=0; i < tamCli; i++)
    {
        flagAlq = 0;
        if(clientes[i].isEmpty == 0)
        {
            for(int j=0; j < tamAlq; j++)
            {
                if(alq[j].isEmpty == 0)
                {
                    if(alq[j].idCliente == clientes[i].id)
                    {
                        flagAlq = 1;
                        break;
                    }
                }
            }
            if(flagAlq == 0)
            {
                mostrarCliente(clientes[i]);
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("\nTodos lo clientes Alquilaron\n");
    }
    printf("\n\n");
}



void alquileres_JuegosQueNoAlquilaron(sAlquiler alq[], int tamAlq, sJuego juegos[], int tamJue)
{
    int flag = 0;
    int flagAlq = 0;
    system("cls");
    fflush(stdin);
    printf("*** Juegos Sin Alquileres ***\n\n");
    printf("\nId Juego \n\n");

    for(int i=0; i < tamJue; i++)
    {
        flagAlq = 0;
        if(juegos[i].isEmpty == 0)
        {
            for(int j=0; j < tamAlq; j++)
            {
                if(alq[j].isEmpty == 0)
                {
                    if(alq[j].idJuego == juegos[i].id)
                    {
                        flagAlq = 1;
                        break;
                    }
                }
            }
            if(flagAlq == 0)
            {
                printf("%d %s\n", juegos[i].id, juegos[i].descripcion);
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("\nTodos lo Juegos se Alquilaron\n");
    }
    printf("\n\n");
}



void Alquileres_TelefonoDeAlquilerPorFecha(sCliente cliente[],int tamClie, sAlquiler alquiler[], int tamAlq, sFecha fecha[], sJuego juegos[], int tamJue)
{
    system("cls");
    sFecha fechaAux;
    int existe=0;

    printf("\n\n *****    TELEFONOS DE CLIENTES    ***** \n\n\n");

    printf(" Ingrese dia: ");
    scanf("%d",&fechaAux.dia);
    printf("\n Ingrese mes:  ");
    scanf("%d", &fechaAux.mes);
    printf("\n Ingrese anio:  ");
    scanf("%d", &fechaAux.anio);

    printf("\n\n  TELEFONOS  \n");

    for (int i=0;i < tamAlq;i++)
    {
        if(alquiler[i].isEmpty == 0)
        {
            for (int j = 0;j < tamClie;j++)
            {
                if (compararFecha(alquiler[i].fecha,fechaAux) && cliente[j].isEmpty == 0 && alquiler[i].idCliente == cliente[j].id)
                {
                    printf("\n   %10s \n ", cliente[j].telefono);

                    existe=1;
                    break;
                }
            }

        }
    }
    if (existe == 0)
    {
        printf("\nNo hay alquileres en esa fecha.\n");
    }
}


void alquileres_JuegosAlqPorMujeres(sAlquiler alquiler[], int tamAlq, sCliente cliente[], int tamCli, sJuego juego[], int tamJue)
{
    system("cls");
    printf("*** Juegos Alquilados por Mujeres ***\n\n");
    printf("Id Juego\n");
    for(int i = 0;i < tamAlq;i++)
    {
        if(alquiler[i].isEmpty == 0)
        {
            for(int j = 0;j < tamCli;j++)
            {
                if(cliente[j].isEmpty == 0 && alquiler[i].idCliente == cliente[j].id)
                {
                    if(esMujer(cliente, tamCli, cliente[j].id))
                    {
                        //printf("%d %s\n", cliente[j].id, cliente[j].nombreCliente);
                        for(int k = 0;k < tamJue;k++)
                        {
                            if(juego[k].id == alquiler[i].idJuego)
                            {
                                printf("%d %s\n", alquiler[i].idJuego, juego[k].descripcion);
                            }
                        }
                    }
                }
            }
       }
    }
}


void alquileres_JuegosMasAlquiladosPorHombres(sAlquiler alquiler[], int tamAlq, sCliente cliente[], int tamCli, sJuego juego[], int tamJue)
{
    system("cls");
    printf("*** Juegos Mas Alquilados por Hombres ***\n\n");
    printf("Id Juego Cantidad\n\n");
    int contJuego[tamJue];
    int masAlq = 0;

    for(int i = 0; i < tamJue;i++)
    {
        contJuego[i] = 0;
    }

    for(int i = 0;i < tamAlq;i++)
    {
        if(alquiler[i].isEmpty == 0)
        {
            for(int j = 0;j < tamCli;j++)
            {
                if(cliente[j].isEmpty == 0 && alquiler[i].idCliente == cliente[j].id)
                {
                    if(esHombre(cliente, tamCli, cliente[j].id))
                    {
                        //printf("%d %s\n", cliente[j].id, cliente[j].nombreCliente);
                        for(int k = 0;k < tamJue;k++)
                        {
                            if(juego[k].id == alquiler[i].idJuego)
                            {
                                contJuego[k]++;
                               // printf("%d %s\n", alquiler[i].idJuego, juego[k].descripcion);
                            }
                            if(contJuego[k]> masAlq)
                            {
                                masAlq = contJuego[k];
                            }

                        }
                    }
                }
            }
       }
    }
    for(int i = 0;i < tamJue;i++)
    {
        if(contJuego[i] == masAlq)
        {
            printf("%d %s      %d\n\n", juego[i].id, juego[i].descripcion, contJuego[i]);
        }

    }

}

void alquileres_MostrarAlquileresPorJuego(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sCliente cli[], int tamCli)
{
    int flag = 0;
    int idJue;

    juegos_listarJuegos(juego, tamJue);
    printf("Ingrese Id Juego: ");
    fflush(stdin);
    scanf("%d", &idJue);

    system("cls");
    printf("  Fecha     Id Alq    Cliente\n\n");
    fflush(stdin);
    char descCat[51];
    char descJuego[21];
    char nombreCli[51];

    for(int i=0; i < tamAlq; i++)
    {
        if( alq[i].isEmpty == 0 && alq[i].idJuego == idJue)
        {
            obtenerCliente(cli, tamCli, alq[i].idCliente, nombreCli);
            fflush(stdin);
            printf("\n%2d/%2d/%d %4d  %10s\n",alq[i].fecha.dia, alq[i].fecha.mes, alq[i].fecha.anio, alq[i].id, nombreCli);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}


void alquileres_MostrarCantidadDeAlqPorMarca(sAlquiler alquiler[], int tamAlq, sJuego juego[], int tamJue, sMarca marca[], int tamM)
{
    system("cls");
    printf("*** Juegos Mas Alquilados por Marca ***\n\n");

    int idMarcaAux = 0;
    int contJuego = 0;
    juegos_listarMarca(marca, tamM);
    printf("Ingrese Id Marca: ");
    scanf("%d", &idMarcaAux);

    for(int i = 0;i < tamJue;i++)
    {
        if(juego[i].isEmpty == 0 && juego[i].idMarca == idMarcaAux)
        {
            for(int j = 0;j < tamAlq;j++)
            {
                if(alquiler[j].idJuego == juego[i].id)
                {
                    contJuego++;
                }
            }
        }
    }
    if(contJuego != 0)
    {
        printf("\nHubo %d Alquileres de la Marca %s\n\n", contJuego, marca[idMarcaAux].nombreMarca);
    }
}



void alquileres_MostrarAlquileresPorMarca(sAlquiler alq[], int tamAlq, sJuego juego[], int tamJue, sMarca marca[], int tamM, sCliente cli[], int tamCli)
{
    int flag = 0;
    int idMarcaAux;

    juegos_listarMarca(marca, tamM);
    printf("Ingrese Id Marca: ");
    fflush(stdin);
    scanf("%d", &idMarcaAux);

    system("cls");
    printf("Id   Cliente\n\n");

    for(int i = 0;i < tamJue;i++)
    {
        if(juego[i].idMarca == idMarcaAux && juego[i].isEmpty == 0)
        {
            for(int j = 0; j < tamAlq; j++)
            {
                if(alq[j].isEmpty == 0 && alq[j].idJuego == juego[i].id)
                {
                    for(int k = 0;k < tamCli;k++)
                    {
                        if(cli[k].id == alq[j].idCliente)
                        {

                            mostrarCliente(cli[k]);
                            flag = 1;
                            //printf("\n %4d  %10s\n", alq[i].id, nombreCli);
                        }
                    }
                }
            }
        }

    }
    if(flag == 0)
    {
        printf("\nNo hay alquileres cargados del cliente\n");
    }
    printf("\n\n");
}



