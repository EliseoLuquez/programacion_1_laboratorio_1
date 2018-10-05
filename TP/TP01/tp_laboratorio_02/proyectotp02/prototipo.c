#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipo.h"

#define LEN 3
#define OK 0
#define ERROR -1

int options()
{
    int option;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf("\n    1- Altas\n");
    printf("\n    2- Modificar\n");
    printf("\n    3- Baja\n");
    printf("\n    4- Informar\n");
    printf("\n    5- Salir\n");
    printf("\n\n** Ingrese Opcion **\n");
    scanf("%d", &option);

    return option;
}

int initEmployees(sEmployee* list, int len)
{
    int r = ERROR;
    if((list != NULL)&&(len > 0))
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        r = OK;
    }
    return r;
}

int searchEmpty(sEmployee* list, int len)
{
    int r = ERROR;
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            r = i;
            break;
        }
    }
    return i;
}

int addEmployees(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int r = ERROR;
    if((list != NULL) && (len > 0))
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id = id + i;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                r = OK;
                break;
            }
        }
    }

    return r;
}

void printEmployee(sEmployee list)
{
    printf("%d    %s    %s    %.2f\n", list.id, list.name, list.lastName, list.salary, list.sector);
}

void printEmployees(sEmployee* list, int len)
{
    int r = ERROR;
    int i;
    if(len>0)
    {
        printf("ID    NOMBRE    APELLIDO    SALARIO    SECTOR\n");
        for( i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list[i]);
            }
        }
        printf("\n\n\n");
        r = OK;
    }
    //return OK;
}

int findEmployeeById(sEmployee* list, int len, int id)
{
    int r = ERROR;

    for(int i = 0; i < len; i++)
    {
        if((list[i].isEmpty == 0)&&(list[i].id == id))
        {
            r = i; /** LE ASIGNO LA POSICION  ENCONTRADA Y SALGO **/
            break;
        }
    }
    return r;
}

/** DAR DE BAJA EMPLEADO **/
int removeEmployee(sEmployee* list, int len)
{
    int r = ERROR;
    int id;
    char answer;

    system("cls");
    printf("***  Baja Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);
    r = findEmployeeById(list, len, id);

    if(r == ERROR)
    {
        printf("No hay empleados con el id %d\n\n", id);
        system("pause");
    }
    else
    {
        printf("Confirma baja s/n\n");
        fflush(stdin);
        scanf("%c", &answer);

        if(answer == 's')
        {
            printf("Baja cancelada");
        }
        else
        {
            list[r].isEmpty = OK; /** SE LE ASIGNA EL VALOR 1 PARA CAMBAIR SU ESTA DE LLENO(0)A VACIO**/
            printf("Baja exitosa\n\n");
        }
    system("pause");
    }
    return ERROR;
}

int sortEmployees(sEmployee* list, int len, int order)
{
    sEmployee auxEmployee;
    int i, j;
    order = ERROR;
    for(i = 0; i < len-1; i++)
    {
        for(j = i+1; j < len; j++)
        {
           if(order == 1)
            { /** ascendente **/
            if(((strcmp(list[i].lastName, list[j].lastName)>0))&&(list[i].sector > list[j].sector))
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            }
            else if(order == 0) /** decendente**/
            {
                if(((strcmp(list[i].lastName, list[j].lastName)<0))&&(list[i].sector < list[j].sector))
            {
                auxEmployee = list[j];
                list[j] = list[i];
                list[i] = auxEmployee;

            }
            }

        }
    }
    return OK;
}

void modifyEmployee(sEmployee* list, int len)
{

    int index;
    int id;
    char answer;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;

    system("cls");
    printf("***  Modificar Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployeeById(list, len, id);

    if(index == -1)
    {
        printf("No hay empleados con id %d\n\n", id);
        system("pause");
    }
    else
    {
        printf("ID    NOMBRE    APELLIDO    SALARIO    SECTOR");
        printEmployee(list[index]);
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
                        printf("Modificacion de nombre cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo nombre: \n");
                        fflush(stdin);
                        gets(newName);
                        strcpy(list[index].name, newName);

                        printf("\nModificacion de nombre exitosa");
                    }
                    break;

            case 2:
                    printf("¿ Modificar apellido ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);

                    if(answer == 'n')
                    {
                        printf("Modificacion de apellido cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo apellido: \n");
                        fflush(stdin);
                        gets(newLastName);
                        strcpy(list[index].lastName, newLastName);

                        printf("Modificacion de apellido exitosa");
                    }
                    break;

            case 3:
                    printf("¿ Modificar salario ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);

                    if(answer == 'n')
                    {
                        printf("Modificacion de salario cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo salario: \n");
                        scanf("%f", &newSalary);
                        list[index].salary = newSalary;

                        printf("Modificacion de salario exitosa");
                    }
                    break;

            case 4:
                    printf("¿ Modificar sector ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);

                    if(answer == 'n')
                    {
                        printf("Modificacion de sector cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo sector: \n");
                        scanf("%d", &newSector);
                        list[index].sector =  newSector;

                        printf("Modificacion de sector exitosa");
                    }
                    break;
        }
    system("pause");
    }

}

