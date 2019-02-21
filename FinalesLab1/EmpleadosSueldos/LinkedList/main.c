#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
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
    LinkedList* eEmpleado = ll_newLinkedList();
    LinkedList* eEmpleadoDos = ll_newLinkedList();


    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",eEmpleado);
                break;
            case 2:
                ll_map(eEmpleado, employee_loadSueldo);
                //controller_loadFromBinary("data.csv",eEmpleado);
                break;
            case 3:
                controller_addEmployee(eEmpleado);
                break;
            case 4:
                controller_editEmployee(eEmpleado);
                break;
            case 5:
                controller_removeEmployee(eEmpleado);
                break;
            case 6:
                controller_ListEmployee(eEmpleado);
                break;
            case 7:
                controller_sortEmployee(eEmpleado);
                break;
            case 8:
                controller_saveAsText("info.csv", eEmpleado);
                break;
           /* case 9:
                controller_saveAsBinary("data.bin", eEmpleado);
                break;*/
        }
    }while(option != 10);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n");
        printf("  2. Cargar los sueldos de los empleados segun sus horas trabajadas                                        \n");
        printf("  3. Alta de empleado                                                            \n");
        printf("  4. Modificar datos de empleado                                                 \n");
       // printf("  5. Baja de empleado                                                            \n");
        printf("  6. Listar empleados                                                            \n");
        printf("  7. Ordenar empleados                                                           \n");
        printf("  8. Guardar los datos de los empleados en el archivo info.csv (modo texto).     \n");
       // printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   \n");
        printf(" 10. Salir                                                                       \n");
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

