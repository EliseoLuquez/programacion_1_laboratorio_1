#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipo.h"

#define LEN 2
#define OK 0
#define ERROR -1



int main()
{
    int r;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    sEmployee employees[LEN];
    initEmployees(employees, LEN);
    char exit = 'n';
    do{
        switch(options())
        {
            case 1:
                    if(searchEmpty(employees, LEN) == OK)
                    {
                       id = 0000;
                       printf("INGRESE NOMBRE: \n");
                       fflush(stdin);
                       gets(name);
                       printf("INGRESE APELLIDO: \n");
                       fflush(stdin);
                       gets(lastName);
                       printf("INGRESE SALARIO: \n");
                       scanf("%f", &salary);
                       printf("INGRSE SECTOR: \n");
                       scanf("%d", &sector);

                       r = addEmployees(employees, LEN, id, name, lastName, salary, sector);
                    }
                    else
                    {
                        printf("ESPACIO LLENO\n\n");
                    }
                    break;
            case 2:
                    modifyEmployee(employees, LEN);

                    break;
            case 3:
                    removeEmployee(employees, LEN);

                    break;
            case 4:
                    sortEmployees(employees, LEN, 1);
                    printEmployees(employees, LEN);

                    break;
            case 5:
                    printf("Salir");
                    system("pause");
                    exit = 's';
                    break;
        }
      }while(exit=='n');






    return 0;
}

