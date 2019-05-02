#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Color.h"
#include "Componente.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* pArrayListColor = ll_newLinkedList();
    LinkedList* pArrayListComponentes = ll_newLinkedList();
    //char pathArch = "color.txt";
    //char pathArch2 = "componente.txt";
    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                system("cls");
                //printf("\nIngrese Nombre de Archivo a cargar: ");
                //scanf("%s", pathArch);
                controller_colorLoadFromText("color.txt",pArrayListColor);
                controller_componenteLoadFromText("componente.txt", pArrayListComponentes);
                //controller_addComponente(pArrayListComponentes);
                break;
            case 2:
                controller_editComponente(pArrayListComponentes);

                break;
            case 3:controller_removeComponente(pArrayListComponentes);
                //ll_map(eEnvio, envio_loadCosto);
                //controller_ListEnvio(eEnvio);
                break;
            case 4:
                system("cls");
                controller_ListComponentes(pArrayListComponentes);
                system("cls");
                break;
            case 5:
                system("cls");
                controller_addColor(pArrayListColor, pArrayListComponentes);
                break;
            case 6:
                controller_ListColores(pArrayListColor);
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
        printf("  Menu:                     \n");
        printf("  1. Alta Componente        \n");
        printf("  2. Modificar Componente   \n");
        printf("  3. Baja Componente        \n");
        printf("  4. Listar Componente      \n");
        printf("  5. Nuevo Color            \n");
        printf("  6. Informar Componentes de Color\n");
        printf("  7. Salir                  \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 7);

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
        printf("     1. Ingrese Nuevo Nombre:      \n");
        printf("     2. Ingrese Nuevo 1-Base o 0-Pigmento:\n");
        printf("     3. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 3);

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

