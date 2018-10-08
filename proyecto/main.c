#include <stdio.h>
#include <stdlib.h>
#include "proyecto.h"
#define LEN 1000

int main()
{
    int r;
    int firstEmployee = 1;

    sEmployee employees[LEN];

    initEmployees(employees, LEN);
    harcodeoEmployee(employees);
    char exit = 'n';
    do{
        switch(options())
        {
            case 1:
                    addEmployee(employees, LEN);
                    firstEmployee = 1;
                    break;
            case 2:
                    if(firstEmployee == 0)
                    {
                        printf("Primero debe cargar un Empleado\n\n");
                        system("pause");
                    }
                    else
                    {
                        modifyEmployee(employees, LEN);
                    }
                    system("pause");
                    break;
            case 3:
                    if(firstEmployee == 0)
                    {
                        printf("Primero debe cargar un Empleado\n\n");
                        system("pause");
                    }
                    else
                    {
                        removeEmployee(employees, LEN);
                    }
                    system("pause");
                    break;
            case 4:
                    system("cls");
                    if(firstEmployee == 0)
                    {
                        printf("Primero debe cargar un Empleado\n\n");
                        system("pause");
                    }
                    else
                    {
                        sortEmployees(employees, LEN, 1);/** Orden 0 Descendente, 1 Ascendente**/
                        printEmployees(employees, LEN);
                        printf("\nEl total de salarios es de %.2f\n", totalSalary(employees, LEN));
                        printf("\nEl promedio de salarios es de %.2f\n", salaryAverage(employees, LEN));
                        printf("\nLos empleados que tienen salario por ensima de la media son %d\n", aboveAverage(employees, LEN));
                        system("pause");
                    }

                    break;
            case 5:
                    printf("Salir\n\n");
                    system("pause");
                    exit = 's';
                    break;
        }
      }while(exit=='n');






    return 0;
}

