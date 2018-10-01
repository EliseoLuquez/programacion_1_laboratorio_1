#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTY_EMPLOYEES 2
typedef struct
    {
        int id;
        char name[51];
        char lastName[51];
        float salary;
        int sector;
        int isEmpty;

    }Employee;

int options();
void InitEmployees(Employee* list,int qty);
void printEmployee(Employee* aEmployee);
void printEmployees(Employee* list, int qty);
int searchEmpty(Employee* list, int qty);
int findEmployee(Employee* list, int qty, int id);
int addEmployee(Employee* list, int qty, int id, char name[],char lastName[],float salary,int sector);
void removeEmployee(Employee* list, int qty);
void modifyEmployee(Employee* list, int qty);
void sortEmployees(Employee* list, int qty, int order);

int main()
{
    char seguir = 's';
    Employee employees[QTY_EMPLOYEES];
    InitEmployees(employees,QTY_EMPLOYEES);
    int r;
    do
    {
    switch(options())
    {
        case 1:

                addEmployee(employees, QTY_EMPLOYEES, id, name, lastName, salary, sector);
                break;
        case 2:
                modifyEmployee(employees, QTY_EMPLOYEES);
                system("pause");
                break;
        case 3:
                removeEmployee(employees, QTY_EMPLOYEES);
                break;
        case 4:
                sortEmployees(employees, QTY_EMPLOYEES, 1);
                printEmployees(employees, QTY_EMPLOYEES);
                break;
        case 5:
                printf("Salir");
                system("pause");
                seguir = 'n';
                break;
    }
    }while(seguir == 's');
    return 0;
}
/** MENU **/
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

/** INICIALIZADOR DE EMPLEADO**/
void InitEmployees(Employee* list,int qty)
{
    for(int i = 0; i < qty; i++)
    {
        list[i].isEmpty = 1;
    }
}

/** MOSTRAR UN SOLO EMPLEADO **/
void printEmployee(Employee aEmployee)
{
    printf(" %d  %s  %s  %.2f  %d",aEmployee.id, aEmployee.name, aEmployee.lastName, aEmployee.salary, aEmployee.sector);
}

/** MOSTRAR TODOS LOS EMPLEADOS **/
void printEmployees(Employee* list, int qty)
{
    system("cls");
    printf("Id  Name  LasteName  Salary  Sector\n\n");

    for(int i = 0; i < qty; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printEmployee(list[i]);
        }
    system("pause");
    }
}

/** BUSCA LUGAR LIBRE PARA GUARDAR EMPLEADO **/
int searchEmpty(Employee* list, int qty)
{
    int index = -1;

    for(int i = 0; i < qty; i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i; /** LE ASIGNO LA POSICION LIBRE ENCONTRADA Y SALGO **/
            break;
        }
    }
    return index;
}

/** BUSCA EMPLEADO **/
int findEmployee(Employee* list, int qty, int id)
{
    int index = -1;

    for(int i = 0; i < qty; i++)
    {
        if((list[i].isEmpty == 0)&&(list[i].id == id))
        {
            index = i; /** LE ASIGNO LA POSICION  ENCONTRADA Y SALGO **/
            break;
        }
    }
    return index;
}

/** **/
int addEmployee(Employee* list, int qty, int id, char name[],char lastName[],float salary,int sector)
{
        for(int i = 0; i < qty; i++)
        {
            int flag = 0;
            if(flag == 0)
            {
                id = 0000;
            }
            else
            {
                id++;
            }
            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(list[i].name);
            strcpy(list[i].name, name);
            printf("Ingrese apellido: \n");
            fflush(stdin);
            gets(list[i].lastName);
            strcpy(list[i].lastName, lastName);
            printf("Ingrese salario: \n");
            scanf("%f", &list[i].salary);
            list[i].salary = salary;
            printf("Ingrese sector: \n");
            scanf("%d", &list[i].sector);
            list[i].sector = sector;



        //newEmployee.isEmpty = 0;/** NEWEMPLOYEE PASA A ESTAR LLENO **/

        //list[index] = newEmployee;  /** ASIGNO AL INDICE LOS DATOS DE NEWEMPLEOYEE**/
        }
        return 0;
}



/** DAR DE BAJA EMPLEADO **/
void removeEmployee(Employee* list, int qty)
{
    int index;
    int id;
    char seguir;

    system("cls");
    printf("***  Baja Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);
    index = findEmployee(list, qty, id);

    if(index == -1)
    {
        printf("No hay empleados con el id %d\n\n", id);
        system("pause");
    }
    else
    {
        printEmployee(list[index]);
        printf("Confirma baja s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada");
        }
        else
        {
            list[index].isEmpty = 1; /** SE LE ASIGNA EL VALOR 1 PARA CAMBAIR SU ESTA DE LLENO(0)A VACIO **/
            printf("Baja exitosa\n\n");
        }
    system("pause");
    }
}

/** MODIFICA DEATOS DE EMPLEADO INTRODUCIENDO EL LEGAJO **/
void modifyEmployee(Employee* list, int qty)
{

    int index;
    int id;
    char seguir;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;

    system("cls");
    printf("***  Modificar Empleado  ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployee(list, qty, id);

    if(index == -1)
    {
        printf("No hay empleados con id %d\n\n", id);
        system("pause");
    }
    else
    {
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
                    scanf("%c", &seguir);

                    if(seguir == 'n')
                    {
                        printf("Modificacion de nombre cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo nombre: \n");
                        fflush(stdin);
                        gets(newName);
                        strcpy(list[index].name, newName);

                        printf("Modificacion de nombre exitosa");
                    }
                    break;

            case 2:
                    printf("¿ Modificar apellido ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &seguir);

                    if(seguir == 'n')
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
                    scanf("%c", &seguir);

                    if(seguir == 'n')
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
                    scanf("%c", &seguir);

                    if(seguir == 'n')
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

/** ORDENO LA LISTA DE EMPLEADO POR PARAMETROS **/
void sortEmployees(Employee* list, int qty, int order)
{
    Employee auxEmployee;
    int i, j;
    order = -1;
    for(i = 0; i < qty-1; i++)
    {
        for(j = i+1; j < qty; j++)
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
}












































