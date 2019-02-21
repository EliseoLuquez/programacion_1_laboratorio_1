#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Usuarios.h"
#include "Temas.h"
#include "parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    int option1 = 0;
    LinkedList* eUsuario = ll_newLinkedList();
    char pathArch[20]= "usuarios.dat";

    int nivel;

    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                controller_loadFromText(pathArch , eUsuario);
                break;

            case 2:
                option1 = menuSort();
                switch(option1)
                {
                    case 1:
                        controller_ListUsuario(eUsuario);
                        break;
                    case 2:
                        ll_sort(eUsuario, usuario_sortByName, 1);
                        break;
                }
                break;

            case 3:
                controller_ListUsuario(eUsuario);
                break;
            case 4:
                //ll_map(eUsuario, vendedor_loadSueldo);
                break;
            case 5:/*
                system("cls");
                eVendedorNivel =  ll_filter(eUsuario, vendedor_niveles);
                system("cls");
                printf("\nIngrese Nombre de Archivo segun Nivel elegido: ");
                scanf("%s", pathArch2);
                controller_saveAsText(pathArch2, eVendedorNivel);*/
                break;
            case 6:/*
                printf("\nIngrese Nombre de Archivo bin segun Nivel elegido: ");
                scanf("%s", pathArchbin);
                controller_saveAsBinary(pathArchbin, eVendedorNivel);
               // controller_ListEmployee(eVendedorNivel);*/
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
        printf("  Menu:                                                             \n");
        printf("  1. cargar archivo                                               \n");
        printf("  2. ordenar                                                   \n");
        printf("  3. ESCUCHAR TEMA                                                  \n");
        printf("  4. GUARDAR ESTADISTICA                                            \n");
        printf("  5. INFORMAR                                                       \n");
        printf("  7. Salir                                                          \n");
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
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("     4. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 4);

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
        printf("     1. Nombre                     \n");
        printf("     2. Nacionalidad y Nombre.     \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 5);

    return r;
}

