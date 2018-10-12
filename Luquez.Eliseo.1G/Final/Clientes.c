#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Clientes.h"

void initCliente(sCliente* list, int len)
{
    for(int i = 0; i < len; i++)
    {
        list[i].isEmptyCliente = 1;
    }
}



int searchEmptyCliente(sCliente* list, int len)
{
    int r = -1;
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmptyCliente == 1)
        {
            r = i;
            break;
        }
    }
    return r;
}


int addCliente(sCliente* list, int len)
{
    sCliente newCliente;
    int r;
    int index;
    char auxName[51];
    char auxSexo[2];
    char auxTelefono[10];

    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyCliente(list,len);
        printf("\n** Nuevo Cliente **\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            r = -1;
            system("pause");
        }
        else
        {
            printf("\nCodigo Cliente %d \n",index) ;
            newCliente.codigoCliente = index;
            if(!getStringLetras("\nIngrese Nombre: ",auxName))
            {
                printf("El nombre solo debe estar compuesto por letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!getStringFoM("\nIngrese  Sexo f/m: ", &auxSexo))
            {
                printf("\nEl sexo debe ser f/m \n\n");
                system("pause");
                system("cls");

            }
            else if(!getStringTelefono("\nIngrese  Telefono: ",auxTelefono))
            {
                printf("\nError al ingresar telefono.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(newCliente.nombreCliente, auxName);
                strcpy(newCliente.sexo, auxSexo);
                strcpy(newCliente.telefono, auxTelefono);
                newCliente.isEmptyCliente = 0;
                list[index] = newCliente;
                system("pause");
                system("cls");
                printf("\n\nNUEVO CLIENTE INGRESADO:\n\n");
                printCliente(list[index]);
                printf("\n\n\n");
                system("pause");
                r = 0 ;
            }
        }

    }
    else
    {
        r = -1 ;
    }
    return r;
}



int sortCliente(sCliente* list, int len)
{
    sCliente auxCliente;
    int i, j;
    for(i = 0; i < len-1; i++)
    {
        for(j = i+1; j < len; j++)
        {

            if((strcmp(list[i].sexo, list[j].sexo)>0))
            {
                auxCliente = list[i];
                list[i] = list[j];
                list[j] = auxCliente;
            }
            else if((strcmp(list[i].sexo, list[j].sexo)==0))
            {
                if(strcmp(list[i].nombreCliente, list[j].nombreCliente) > 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente;
                }

            }
        }
    }
    return 0;
}



int removeCliente(sCliente* list, int len)
{
    int r = -1;
    int id;
    char answer;

    system("cls");
    printf("***  Baja Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);
    r = findClienteById(list, len, id);

    if(r == -1)
    {
        printf("No hay clientes con ese codigo %d\n\n", id);
        system("pause");
    }
    else
    {
        printCliente(list[r]);
        printf("Confirma baja s/n : ");
        fflush(stdin);
        scanf("%c", &answer);

        if(answer == 'n')
        {
            printf("\nBaja cancelada");
        }
        else
        {
            list[r].isEmptyCliente = -1; /** SE LE ASIGNA EL VALOR 1 PARA CAMBAIR SU ESTA DE LLENO(0)A VACIO**/
            printf("Baja exitosa\n\n");
        }
    system("pause");
    }
    return 0;
}



void printCliente(sCliente list)
{
    printf("\n-Cod.Cliente: %d  \n-Nombre: %s  \n-Sexo: %s  \n-Telefono: %s   \n\n", list.codigoCliente, list.nombreCliente, list.sexo, list.telefono);
}




void printClientes(sCliente* list, int len)
{
    system("cls");
    printf("\n Cod.Cliente Nombre Sexo Telefono\n\n");

    for(int i = 0; i < len; i++)
    {

        if(list[i].isEmptyCliente == 0)
        {
            printCliente(list[i]);
        }
    }
    system("pause");
}



int findClienteById(sCliente* list, int len, int id)
{
    int r = -1;

    for(int i = 0; i < len; i++)
    {
        if((list[i].isEmptyCliente == 0)&&(list[i].codigoCliente == id))
        {
            r = i; /** LE ASIGNO LA POSICION  ENCONTRADA Y SALGO **/
            break;
        }
    }
    return r;
}



void modifyCliente(sCliente* list, int len)
{

    int index;
    int id;
    int answer;
    char newName[51];
    char newSexo;
    char newTelefono[21];


    system("cls");
    printf("***  Modificar Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findClienteById(list, len, id);

    if(index == -1)
    {
        printf("No hay empleados con id %d\n\n", id);
        system("pause");
    }
    else
    {

        printf("Baja id %d",list[index].codigoCliente, len);
        int option;
        printf("¿ Que desea modificar ?\n");
        printf("1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                    printf("¿ Modificar nombre ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);

                    if(answer == 'n')
                    {
                        printf("\nModificacion de nombre cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo nombre: \n");
                        fflush(stdin);
                        gets(newName);
                        strcpy(list[index].nombreCliente, newName);

                        printf("\nModificacion de nombre exitosa\n\n");
                    }
                    break;

            case 2:
                    printf("¿ Modificar sexo ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);
                    if(answer == 'n')
                    {
                        printf("\nModificacion de sexo cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo sexo: \n");
                        scanf("%s", newSexo);
                        strcpy(list[index].sexo, newSexo);

                        printf("\nModificacion de sexo exitosa\n\n");
                    }
                    break;

            case 4:
                    printf("¿ Modificar telefono ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);
                    if(answer == 'n')
                    {
                        printf("\nModificacion de telefono cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo telefono: \n");
                        fflush(stdin);
                        gets(newTelefono);
                        strcpy(list[index].telefono, newTelefono);

                        printf("\nModificacion de telefono exitosa\n\n");
                    }
                    break;
            default:
                    printf("No ingresa opcion valida");
                    system("pause");
                    break;

    system("pause");
    }
    }
}



void harcodeoCliente(sCliente* list)
{

    sCliente x[]={
    {1111, "Juan", "m", "4564-1002", },
    {1112, "Pedro", "m", "4568-2222", },
    {1113, "Juana", "f", "4464-1654", },
    {1114, "Ana", "f", "4864-1012", },
    {1115, "Sara", "f", "4569-1818", }
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
}
