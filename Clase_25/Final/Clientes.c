#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"

int buscarLibreCliente(sCliente lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//INICIALIZARLO
void inicializarClientes(sCliente lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

//DAR DE ALTA ALGO
void altaCliente(sCliente cliente[], int tam)
{
    char auxNombreCliente[51];
    char auxSexo;
    char auxTelefono[21];
    sCliente nuevoCliente;
    int indice;

    indice = buscarLibreCliente(cliente, tam);

    if(indice == -1)
    {
        printf("No se pueden cargar mas clientes\n\n");
    }
    else
    {
        printf("\n Nuevo Cliente, ID numero %d \n",indice) ;
        nuevoCliente.id = indice ;

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(auxNombreCliente);

        fflush(stdin);
        getCharLetra("Ingrese Sexo f/m: ",auxSexo);

        printf("Ingrese Telefono 1234-5678 : ");
        fflush(stdin);
        gets(auxTelefono);

        /**
        while(!getStringLetras("\nIngrese Nombre: ", auxNombreCliente))
        {
            printf("\nEl Nombre debe estar compuesto por letras.\n");
            system("pause");
            system("cls");
        }
        while(getStringFoM("\nIngrese Sexo f/m: ", auxSexo))
        {
            printf("\nEl sexo debe estar compuesto por f/m.\n");
            system("pause");
            system("cls");
        }
        while(getStringTelefono("\nIngrese Telefono ****-****: ", auxTelefono))
        {
            printf("\nEl Telefono desbe estar compuesto por(****-****).\n");
            system("pause");
            system("cls");
        }

        **/
        strcpy(nuevoCliente.nombreCliente, auxNombreCliente);
        nuevoCliente.sexo = auxSexo;
        strcpy(nuevoCliente.telefono, auxTelefono);
        nuevoCliente.isEmpty = 0;
        cliente[indice] = nuevoCliente;
    }
}

void mostrarCliente(sCliente cliente)
{
    printf("%d    %s    %c    %s\n\n",cliente.id, cliente.nombreCliente, cliente.sexo, cliente.telefono);
}

void mostrarClientes(sCliente cliente[], int tam)
{
    int flag = 0;
    system("cls");
    printf("\nId   Nombre   Sexo   Telefono  \n\n");

    for(int i = 0; i < tam; i++)
    {
        if(cliente[i].isEmpty == 0)
        {
            mostrarCliente(cliente[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay clientes cargados");
    }
    printf("\n\n");
}


//BAJA CLIENTE
 void bajaCliente(sCliente lista[], int tam)
 {

     int id;
     int indice;
     char seguir;

     system("cls");
     printf("  *** Baja empelado ***\n\n");

     printf("Ingrese id: ");
     scanf("%d", &id);

     indice = buscarCliente(lista, tam, id);

     if( indice == -1)
     {
         printf("No hay ningun cliente de id %d\n\n", id);
         system("pause");
     }
     else
     {
         mostrarCliente(lista[indice]);

         printf("\nConfima borrado s/n: ");
         fflush(stdin);
         scanf("%c", &seguir);

         if(seguir == 'n')
         {
             printf("Baja cancelada\n\n");

         }
         else

         {

             lista[indice].isEmpty = 1;
             printf("Borrado exitoso\n\n");
         }
         system("pause");
     }

 }

 //BUSCAREMPLEADOS
 int buscarCliente(sCliente lista[], int tam, int id)
 {
     int indice = -1;

     for(int i=0; i < tam; i++)
     {

         if( lista[i].id == id && lista[i].isEmpty == 0)
         {
             indice = i;
             break;
         }
     }
     return indice;

 }

 //MODIFICACIÓN
void modificarCliente(sCliente lista[], int tam)
 {
     int idAux;
     char auxId[10];
     int indice;
     char auxNombre[51];
     char auxSexo;
     char auxTelefono[21];
     char seguir;
     char respuesta;

     system("cls");
     printf("  *** Modificar  empleado ***\n\n");

            fflush(stdin);
            while(!getStringNumeros("Ingrese Id de cliente a modificar: ", auxId))
            {
                printf("El Id debe contener solo numeros");
            }
            idAux = atoi(auxId);
            indice = (buscarCliente(lista, tam, idAux));
            while(indice == -1)
            {
                printf("No hay ningun empleado de Id %d\n\n", auxId);
                system("pause");
            }
            mostrarCliente(lista[indice]);

     do{

         switch(menuModificarCliente())
         {

            case 1:
                    if(!continueSiONo("\nModificar Nombre ? s/n ", respuesta))
                    {
                        printf("Debe ingresar s(seguir)/n(salir)");
                    }
                    while(!getStringLetras("Ingrese nuevo Nombre: ", auxNombre))
                    {
                        printf("El Nombre debe contener solo letras");
                    }
                    strcpy(lista[indice].nombreCliente ,auxNombre);
                    printf("Moficacion de Nombre exitosa!\n\n");


                    break;

            case 2:
                    while(continueSiONo("Modificar Sexo? s/n ", respuesta))
                    {
                        printf("Debe ingresar s(seguir)/n(salir)");
                    }
                    if(!getStringFoM("Ingrese nuevo Sexo: ", auxSexo))
                    {
                        printf("El Sexo debe contener solo letras f/m");
                    }
                    else
                    {
                        lista[indice].sexo = auxSexo;
                        printf("Moficacion de Sexo exitosa!\n\n");
                    }
                    break;

            case 3:
                    fflush(stdin);
                    if(!continueSiONo("Modificar Telefono? s/n ", respuesta))
                    {
                        printf("Debe ingresar s(seguir)/n(salir)");
                    }
                    else if(respuesta != 's')
                    {
                        printf("\nModificacion de Telefono cancelada\n\n");
                    }
                    else if(!getStringTelefono("Ingrese nuevo Telefono: ", auxTelefono))
                    {
                        printf("El Telefono debe contener solo numeros(****-****)");
                    }
                    else
                    {
                        strcpy(lista[indice].telefono ,auxTelefono);
                        printf("Moficacion de Telefono exitosa!\n\n");
                    }
                    break;

            case 4:
                    fflush(stdin);
                    seguir = 'n';
                    break;


         }
      }while(seguir == 's');
 }

void harcodeoClientes(sCliente lista[])
{

    sCliente cliente[]={
    {100, "Roman", 'm', "1334-4568",0},
    {101, "Pedro", 'm', "1335-4567",0},
    {102, "Juana", 'f', "1336-4566",0},
    {103, "Ana  ", 'f', "1337-4566",0},
    {104, "Sara ", 'f', "1338-4565",0}
    };
    for(int i = 0; i< 5;i++)
    {
        lista[i] = cliente[i];
    }
}



int existenClientes(sCliente lista[], int tam)
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


void obtenerCliente(sCliente cliente[], int tamCli, int idCli, char nombre[])
{
    for(int i = 0; i < tamCli; i++)
    {
        if(cliente[i].id == idCli)
        {
            strcpy(nombre, cliente[i].nombreCliente);
        }
    }
}

void mostrarClientesSinAlq(sCliente clientes[], int tam, sAlquiler alquileres[], int tamAlq)
{
    int flag = 0;
    system("cls");
    printf("\nId   Nombre   Sexo   Telefono  \n\n");

    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            for(int j = 0; j < tamAlq; j++)
            {
                if(clientes[i].id != alquileres[j].idCliente)
                mostrarCliente(clientes[i]);
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
    {

        printf("No hay clientes cargados");
    }
    printf("\n\n");
}

void mostrarClientesPorSexoyNombre(sCliente cliente[], int tam)
{
    int flag = 0;
    sCliente auxCliente;
    system("cls");
    printf("\nId   Nombre   Sexo   Telefono  \n\n");

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam;j++)
        {
            if((cliente[i].sexo > cliente[j].sexo) > 0)
            {
                auxCliente = cliente[i];
                cliente[i] = cliente[j];
                cliente[j] = auxCliente;
                flag = 1;
            }
            else if(cliente[i].sexo == cliente[j].sexo)
            {
                if(strcmp(cliente[i].nombreCliente, cliente[j].nombreCliente) > 0)
                {
                    auxCliente = cliente[i];
                    cliente[i] = cliente[j];
                    cliente[j] = auxCliente;
                }

            }
        }
    }
    for(int i = 0; i < tam;i++)
    {
        mostrarCliente(cliente[i]);
    }
    if(flag == 0)
    {
        printf("No hay clientes cargados");
    }
    printf("\n\n");
}


int esMujer (sCliente clientes[], int tamCli, int idCliente)
{
    int retAux = 0;

    for(int i = 0; i < tamCli ; i++)
    {
        if (clientes[i].id == idCliente)
        {
            if (clientes[i].sexo  == 'f')
            {
                retAux = 1;
            }
            break;
        }
    }
    return retAux;
}

int esHombre(sCliente clientes[], int tamCli, int idCliente)
{
    int retAux = 0;

    for(int i = 0; i < tamCli ; i++)
    {
        if (clientes[i].id == idCliente)
        {
            if (clientes[i].sexo  == 'm')
            {
                retAux = 1;
            }
            break;
        }
    }
    return retAux;
}
