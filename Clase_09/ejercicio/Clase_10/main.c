#include <stdio.h>
#include <stdlib.h>

typedef eEmpleado{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;
    }eEmpleado;

int menu();
void mostrarEmpleado(eEmpleado unEmpleado);
void mostrarEmpleados(eEmpleado lista[], int tam);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[],int tam, int legajo);
void AltaEmpleado(eEmpleado lista[],int tam);


int main()
{
    char seguir = 's';
    eEmpleado empleados[TAM]
    do{
        switch(menu())
        {
            case 1:

                    break;
            case 2:
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 5:
                    break;
            case 6:
                    break;



        }


    }while(seguir == 's');


    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Baja\n");
    printf(" 3- Modificacion\n");
    printf(" 4- Listar Empleados\n");
    printf(" 5- Ordenar Empleados\n");
    printf(" 6- Salir\n\n");
    scanf("%d",&opcion);
    return ocpion;

}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    for(int i = 0;i  <tam; i++)
        {
            lista[i].isEmpty = 1;//Esta vacio true 1
        }
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d %s %c %.2f %d",unEmpleado.legajo, unEmpleado.nombre,unEmpleado.sexo,unEmpleado.sueldo);
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{
    system("cls");
    printf("Legajo Nombre Sexo Sueldo");

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty==0)
        {
            mostrarEmpleado(lista[i]);
        }
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int indice;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado lista[],int tam, int legajo)
{
    int indice;
    for(int i = 0; i < tam; i++)
    {
        if((lista[i].legajo)&&(lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void AltaEmpleado(eEmpleado lista[],int tam)
{
    int existe;
    int indice;
    int legajo;

    indice = buscarLibre(lista, tam);
    system("cls");
    printf("Alta Empleado\n\n");

    if(indice==-1)
    {
        printf("No hay lugar en el sistema\n\n");
    }
    else
    {
        printf("Ingrese un legajo: ");
        scanf("%d", &legajo);

        existe = buscarEmpleado(lista[existe]);
    }
    if(existe!=1)
    {
        printf("Ya existe un empleado en el legajo %d \n",legajo);
        mostrarEmpleado(lista[existe]);
    }
    else
    {
        nuevoEmpleado.legajo = legajo;
        printf("Ingrase nombre: ");
        fflush(stdin);
        gets(nuevoEmpleado.nombre);
        printf("Ingrse sexo: ");
        fflush(stdin);
        scanf("%.2f", nuevoEmpleado.sueldo);

        nuevoEmpleado.isEmpty=0;
        lista[indice]=nuevoEmpleado,
        printf("Se ha dado de alta nuevo empleado");
        system()
    }
}

void bajaEmpleado(eEmpleado lista[], int tam)
{
    printf("Ingrese legajo: ");
    scanf("%d",)
}





