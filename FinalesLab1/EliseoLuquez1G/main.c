#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    LinkedList* pArrayListFichaje = ll_newLinkedList();
    LinkedList* pArrayListFilter = ll_newLinkedList();
    char pathArch[20];
    char pathArch2[20];
    char pathArchbin[20];
    //int nivel;

    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                system("cls");
                controller_loadFromText("empleados.csv" ,pArrayListEmployee);
                controller_loadFromTextFichajes("fichajes.csv", pArrayListFichaje);
                //printf("\nIngrese Nombre de Archivo a cargar: ");
                //scanf("%s", pathArch);

                //controller_addEmployee(pArrayListEmployee);
                break;
            case 2:
                controller_editEmployee(pArrayListEmployee);
                //controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:controller_removeEmployee(pArrayListEmployee);
                //ll_map(eEnvio, envio_loadCosto);
                //controller_ListEnvio(eEnvio);
                break;
            case 4:
                system("cls");
                controller_listEmployee(pArrayListEmployee);
               // eEnvioZona =  ll_filter(eEnvio, envio_zonas);
                system("cls");
               // printf("\nIngrese Nombre de Archivo zona: ");
                //scanf("%s", pathArch2);
               // controller_saveAsText(pathArch2, eEnvioZona);
                break;
            case 5:
                //controller_addFichaje(pArrayListEmployee, pArrayListFichaje);
                controller_listFichajes(pArrayListFichaje);
               // controller_saveAsBinary(pathArchbin, eEnvioZona);
                //controller_ListEnvio(eEnvioZona);
                break;
            case 6:
                controller_filterForFecha(pArrayListEmployee, pArrayListFichaje, pArrayListFilter);
                break;
            case 7:
                break;
        }
    }while(option != 7);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                      \n");
        printf("  1. Alta Empleado                                                           \n");
        printf("  2. Modificar Empleado                                                      \n");
        printf("  3. Baja Empleado                                                           \n");
        printf("  4. Listar Empleados                                                        \n");
        printf("  5. Fichajes Empleados                                                      \n");
        printf("  6. Listar Fichajes por fecha                                               \n");
        printf("  7. Salir                                                                   \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

int menuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Apellido                   \n");
        printf("     2. Dni                        \n");
        printf("     4. Clave                      \n");
        printf("     5. Modificar Todos            \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 6);

    return r;
}

int menuSort()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione el sort:           \n");
        printf("     1. Id.                        \n");
        printf("     2. Nombre.                    \n");
        printf("     3. Horas Trabajadas.          \n");
        printf("     4. Sueldo                     \n");
        printf("     5. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 5);

    return r;
}

