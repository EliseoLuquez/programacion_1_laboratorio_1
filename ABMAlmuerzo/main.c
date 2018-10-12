#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MAIN C
//ESTRUCTURAS

typedef struct
{
    int id;
    char descripcion[20];

} eComida;

typedef struct
{
    int dia;
    int mes;
    int anio;

} efecha;

typedef struct
{
    int id;
    int idComida;
    int idEmp;
    efecha fecha;
    int isEmpty;

} eAlmuerzo;

//FUNCION MAIN
int main()
{
    char seguir = 's';
    int idAlmuerzo = 1000;

    eSector sectores[5];
    eComida comidas[5];
    eAlmuerzo almuerzos[20];

    cargarSectores(sectores);
    cargarComidas(comidas);
    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados,TAM);
    inicializarAlmuerzos(almuerzos, 20);
    harcodearEmpleados(empleados);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(empleados, TAM, sectores, 5);
            break;
        case 2:
            bajaEmpleado(empleados,TAM, sectores, 5);
            break;
        case 3:
            ModificarEmpleado(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 5:
            ordenarEmpleadosXlegajo(empleados, TAM);
            system("pause");
            break;
        case 6:
            listarEmpleadosXSector(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 7:
            ordenarXSectorYNombre(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 8:
            mostrarEmpleadosMasGanadores(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 9:
            listarComidas(comidas, 5);
            system("pause");
            break;
        case 10:
            altaAlmuerzo(almuerzos, 20, comidas, 5, empleados, TAM, sectores, 5, &idAlmuerzo);
            system("pause");
            break;
        case 11:
            mostrarAlmuerzos(almuerzos, 20, comidas, 5, empleados, TAM);
            system("pause");
            break;
        case 20:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

//MENU

int menu()
{
    int opcion;

     system("cls");
    printf("\n                      *** >>>Menu de Opciones<<< ***\n\n");
    printf("                  ___________________________________________\n");
    printf("                 |                                           |\n");
    printf("                 |                                           |\n");
    printf("                 |  1-  Alta                                 |\n");
    printf("                 |  2-  Baja                                 |\n");
    printf("                 |  3-  Modificacion                         |\n");
    printf("                 |  4-  Listar Empleados                     |\n");
    printf("                 |  5-  Ordenar Empleados                    |\n");
    printf("                 |  6-  Mostrar Empleados x Sector           |\n");
    printf("                 |  7-  Ordenar Empleados x Sector y Nombre  |\n");
    printf("                 |  8-  Listar empleados ganadores           |\n");
    printf("                 |  9-  Listar Comidas                       |\n");
    printf("                 |  10- Alta Almuerzo                        |\n");
    printf("                 |  11- Mostrar Almuerzos                    |\n");
    printf("                 |  20- Salir                                |\n");
    printf("                 |___________________________________________|\n");
    printf("                   Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


//CARGAR ALGO
void cargarComidas(eComida comidas[])
{
    eComida food[]=
    {
        {1, "Milanesa"},
        {2, "Pizza"},
        {3, "Ensalada"},
        {4, "Pescado"},
        {5, "Lasagna"}
    };

    for(int i=0; i < 5; i++)
    {
        comidas[i] = food[i];
    }
}

//LISTAR ALGO
void listarComidas(eComida c[], int tam)
{
    printf("\nLista de comidas\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",c[i].id, c[i].descripcion);
    }
    printf("\n\n");
}

//DAR DE ALTA ALGO
void altaAlmuerzo(eAlmuerzo* a, int tama, eComida c[], int tamc, eEmpleado e[], int tame, eSector s[], int tams, int* pId)
{
    int idAlmuerzo = *pId;
    int legajo;
    int idComida;
    efecha fecha;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    indice = buscarLibreAlmuerzo(a, tama);

    if(indice == -1)
    {
        printf("No se pueden cargar mas almuerzos\n\n");
    }
    else
    {
        nuevoAlmuerzo.id = idAlmuerzo;

        mostrarEmpleados(e, tame, s, tams);

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        nuevoAlmuerzo.idEmp = legajo;

        listarComidas(c, tamc);
        printf("Ingrese comida: ");
        scanf("%d", &idComida);

        nuevoAlmuerzo.idComida = idComida;

        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);

        nuevoAlmuerzo.fecha = fecha;

        nuevoAlmuerzo.isEmpty = 0;

        a[indice] = nuevoAlmuerzo;

        *pId = idAlmuerzo + 1;
    }
}

//BUSCARLIBRE
int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
//INICIALIZARLO
void inicializarAlmuerzos(eAlmuerzo lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

//MOSTRAR ALMUERZOS
void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame)
{
    int flag = 0;

    system("cls");
    printf("id   fecha   Legajo   Nombre    Comida\n\n");

    for(int i=0; i < tama; i++)
    {
        if( a[i].isEmpty == 0)
        {
            mostrarAlmuerzo(a[i], c, tamc, e, tame);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos cargados");
    }
    printf("\n\n");
}

//BUSCAR ALMUERZO
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eEmpleado e[], int tame)
{
    char descComida[20];
    int indice;
    eEmpleado empleado;

    obtenerDescComida(c, tamc, unAlmuerzo.idComida, descComida);
    indice = buscarEmpleado(e, tame, unAlmuerzo.idEmp);

    empleado = e[indice];

    printf("%4d %02d/%02d/%d  %d %10s  %10s\n", unAlmuerzo.id, unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes, unAlmuerzo.fecha.anio, empleado.legajo, empleado.nombre, descComida);
}

//OBTENER COMIDA
void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena)
{
    for(int i=0; i < tamc; i++)
    {
        if( c[i].id == idComida)
        {
            strcpy(cadena, c[i].descripcion);
        }
    }
}

//FUNCIONES.C
//BUSCAREMPLEADOS
 int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
 {
     int indice = -1;

     for(int i=0; i < tam; i++)
     {

         if( lista[i].legajo == legajo && lista[i].isEmpty == 0)
         {
             indice = i;
             break;
         }
     }
     return indice;

 }
 // DAR DE ALTA EMPLEADO
 void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
 {
     int indice;
     int legajo;
     int existe;
     int idSector;
     eEmpleado nuevoEmpleado;

     indice = buscarLibre(lista, tam);

     system("cls");
     printf("*** Alta empleado ***\n\n");

     if( indice == -1)
     {

         printf("No hay lugar en el sistema\n\n");
         system("pause");
     }
     else
     {
         printf("Ingrese legajo: ");
         scanf("%d", &legajo);

         existe = buscarEmpleado(lista, tam, legajo);

         if( existe != -1)
         {

             printf("Ya existe un empleado con el legajo %d\n", legajo);
             //  mostrarEmpleado(lista[existe]);
             system("pause");

         }
         else
         {

             nuevoEmpleado.legajo = legajo;

             printf("Ingrese nombre: ");
             fflush(stdin);
             gets(nuevoEmpleado.nombre);
             printf("Ingrese sexo: ");
             fflush(stdin);
             scanf("%c", &nuevoEmpleado.sexo);
             printf("Ingrese sueldo: ");
             fflush(stdin);
             scanf("%f", &nuevoEmpleado.sueldo);

             listarSectores(sectores, tamSector);
             printf("\nIngrese sector: ");
             scanf("%d", &idSector);

             nuevoEmpleado.idSector = idSector;


             nuevoEmpleado.isEmpty = 0;

             lista[indice] = nuevoEmpleado;

         }
     }

 }
//BAJA EMPLEADO
 void bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
 {

     int legajo;
     int indice;
     char seguir;

     system("cls");
     printf("  *** Baja empelado ***\n\n");

     printf("Ingrese legajo: ");
     scanf("%d", &legajo);

     indice = buscarEmpleado(lista, tam, legajo);

     if( indice == -1)
     {
         printf("No hay ningun empleado de legajo %d\n\n", legajo);
         system("pause");
     }
     else
     {
         mostrarEmpleado(lista[indice], sectores, tamSector);

         printf("\nConfima borrado s/n: ");
         fflush(stdin);
         scanf("%c", &seguir);

         if(seguir == 'n')
         {
             printf("Baja cancelada\n\n");

         }
         else

         {

             lista[indice].isEmpty = 1;
             printf("Borrado exitoso\n\n");
         }
         system("pause");
     }

 }
//MODIFICACIÓN
void ModificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
 {
     int legajo;
     int indice;
     char seguir;
     float nuevoSueldo;

     system("cls");
     printf("  *** Modificar  empleado ***\n\n");

     printf("Ingrese legajo: ");
     scanf("%d", &legajo);

     indice = buscarEmpleado(lista, tam, legajo);

     if( indice == -1)
     {
         printf("No hay ningun empleado de legajo %d\n\n", legajo);
         system("pause");
     }
     else
     {
         mostrarEmpleado(lista[indice], sectores, tamSector);

         printf("\nModifica sueldo? s/n: ");
         fflush(stdin);
         scanf("%c", &seguir);

         if(seguir == 'n')
         {
             printf("Modificacion cancelada\n\n");

         }
         else
         {
             printf("Ingrese nuevo sueldo: ");
             scanf("%f", &nuevoSueldo);
             lista[indice].sueldo = nuevoSueldo;

             printf("Modificacion exitosa\n\n");
         }
         system("pause");
     }

 }

//ORDENAR
void ordenarEmpleadosXlegajo(eEmpleado lista[], int tam)
 {
     eEmpleado auxEmpleado;
     for(int i=0; i<tam-1; i++)
     {
         for(int j= i+1; j < tam; j++)
         {

             if( lista[i].legajo > lista[j].legajo)
             {
                 auxEmpleado = lista[i];
                 lista[i] = lista[j];
                 lista[j] = auxEmpleado;

             }
         }
     }

     printf("Empleados ordenados con exito!!!\n\n");


 }

//LISTAR SECTORES
 void listarSectores(eSector sectores[], int tam)
 {

     printf("Id  Descripcion\n\n");
     for(int i=0; i< tam; i++)
     {
         printf("%d   %10s\n", sectores[i].id, sectores[i].descripcion);

     }
     printf("\n\n");
 }
//OBTENER SECTOR
 void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[])
 {

     for(int i=0; i < tam; i++)
     {

         if( sectores[i].id == idSector)
         {
             strcpy(cadena, sectores[i].descripcion);
         }
     }

 }
 //lISTAR EMPLEADOS POR SECTOR
 void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector)
 {
     int idSector;
     char descripcion[20];
     int flag = 0;

     system("cls");
     printf("  *** Listado de Sectores ***\n\n");

     listarSectores(sectores, tamSector);
     printf("Ingrese sector: ");
     scanf("%d",&idSector);

     obtenerSector(sectores, tam, idSector, descripcion);

     system("cls");
     printf("Empleados del sector %s\n\n", descripcion);
     for(int i=0; i< tam; i++)
     {
         if(x[i].isEmpty == 0 && x[i].idSector == idSector)
         {
             mostrarEmpleado(x[i], sectores, tamSector);
             flag = 1;
         }
     }

     printf("\n\n");

     if(flag == 0)
     {
         printf("No hay empleados que mostrar\n\n");
     }

 }

 //MOSTRAR EMPLEADOS POR SECTOR Y NOMBRE
 void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector)
 {

     char descripcionI[20];
     char descripcionJ[20];
     eEmpleado auxEmpleado;

     for(int i=0; i<tam -1; i++)
     {
         for(int j = i +1; j < tam; j++)
         {
             obtenerSector(sectores, tamSector, x[i].idSector, descripcionI);
             obtenerSector(sectores, tamSector, x[j].idSector, descripcionJ);
             if( strcmp(descripcionI, descripcionJ) > 0)
             {
                 auxEmpleado = x[i];
                 x[i] = x[j];
                 x[j] = auxEmpleado;
             }
             else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
             {
                 auxEmpleado = x[i];
                 x[i] = x[j];
                 x[j] = auxEmpleado;
             }
         }
     }
     printf("\nEmpleados ordenados con exito!!!\n\n");

 }
 //MOSTRAR EMPLEADOS MÁS GANADORES
 void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector)
 {
     float maxSueldo;
     char descripcion[20];
     int flag;
     int flag2;

     system("cls");
     printf("\n*** Empleados que mas ganan por sector ***\n\n");

     for(int i=0; i < tamSector; i++)
     {

         obtenerSector(sectores, tamSector, sectores[i].id, descripcion);
         printf("Sector %s\n", descripcion);
         printf("--------------\n\n");
         flag = 0;
         flag2 = 0;
         for(int j=0; j < tam; j++)
         {
             if( (x[j].sueldo > maxSueldo && x[j].isEmpty == 0 && x[j].idSector == sectores[i].id) || flag == 0)
             {
                 maxSueldo = x[j].sueldo;
                 flag = 1;
             }

             if( x[j].isEmpty == 0 && x[j].idSector == sectores[i].id)
             {
                 flag2 = 1;
             }

         }

         if(flag2 == 0)
         {
             printf("Sector Vacio\n");
         }
         else
         {

             for(int j=0; j < tam; j++)
             {
                 if( x[j].sueldo == maxSueldo && x[j].isEmpty == 0)
                 {
                     mostrarEmpleado(x[j], sectores, tamSector);
                 }
             }

         }

         printf("\n\n");
     }
 }


 //FUNCIONES.H
 //ACÁ GUARDAS LAS ESTRUCTURAS Y LOS PROTOTIPOS CON EL BRIEF

//FUNCION PARA EL DÍA

#include <time.h>


int main()
{
    time_t t = time(NULL);
    struct tm hoy=*localtime(&t);

    printf("Hoy es: %d/%d/%d\n", hoy.tm_year + 1900, hoy.tm_mon +1, hoy.tm_mday);
    return 0;
}


//VALIDACIONES
 float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}

int function_getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}

char function_getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

int function_esNum(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int function_esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int function_esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int function_esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

void function_getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

int function_getStringLetras(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}

int function_getStringNumeros(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


void function_continueYesOrNo(char msj[],char input[])
{
    do
    {
        if(!function_getStringLetras(msj,input))
        {
            printf("*** ERROR *** Debe ingresar la letra S o N");
            system("pause");
            system("cls");
        }

    }
    while(!(input[0] == 's' || input[0] == 'n' || input[0] == 'S' || input[0] == 'N'));

}

float function_toFloat(char original[],double floatConverted)
{
    char *originalPointer;
    double finalFloat;
    finalFloat = strtod(original, &originalPointer);

    floatConverted = finalFloat;
    return floatConverted;
}


//FUNCIONES CON VALIDACIONES
int addEmployee(eEmployee list[], int len)
{
    eEmployee newEmployee ;
    int ret;
    int index ;
    char auxName[21];
    char auxLastName[21];
    char auxSalary[10] ;
    char auxSector[10] ;


    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmpty(list,len) ;
        printf("\n------- Alta empleado -------\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {


            printf("\n Nuevo empleado, ID numero %d \n",index) ;
            newEmployee.id = index ;
            if(!function_getStringLetras("Ingrese nombre: ",auxName))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!function_getStringLetras("Ingrese apellido: ",auxLastName))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!function_getStringNumeros("Ingrese el salario: ",auxSalary) && auxSalary > 0)
            {
                printf("**** Error ****\n\n");
                system("pause");
                system("cls");

            }
            else if(!function_getStringNumeros("Ingrese el sector: ",auxSector))
            {
                printf("Error el sector debe tener solo numeros.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(newEmployee.name,auxName) ;
                strcpy(newEmployee.lastName,auxLastName) ;
                newEmployee.salary = atoi(auxSalary) ;
                newEmployee.sector = atoi(auxSector) ;
                newEmployee.isEmpty = 0;
                list[index] = newEmployee ;
                system("pause");
                system("cls");
                printf("\n\nEMPLEADO DADO DE ALTA CON EXITO:\n\n");
                showEmployee(list[index]);
                printf("\n\n\n");
                system("pause");
                ret = 0 ;
            }
        }

    }
    else
    {
        ret = -1 ;
    }
    return ret;
}
