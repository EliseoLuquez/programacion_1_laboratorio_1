#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#define TAM_JUEGO 10
#define TAM_CLIENTE 10



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int options()
{
    int option;

    system("cls");
    printf("\n*** Menu de Clientes ***\n\n");
    printf("\n    1- Altas\n");
    printf("\n    2- Modificar\n");
    printf("\n    3- Baja\n");
    printf("\n    4- Informar\n");
    printf("\n    5- Salir\n");
    printf("\n\n** Ingrese Opcion **\n");
    scanf("%d", &option);

    return option;
}


void initCliente(sCliente* list, int len)
{
    for(int i = 0; i < len; i++)
    {
        list[i].isEmptyCliente = 1;
    }
}

int searchEmpty(sCliente* list, int len)
{
    int r = -1;
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmptyCliente == 1)
        {
            r = i;
            break;
        }
    }
    return r;
}

int addCliente(sCliente* list, int len)
{
    sCliente newCliente;
    int r;
    int index;
    char auxName[51];
    char auxSexo;
    char auxTelefono[15];

    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmpty(list,len) ;
        printf("\n** Nuevo Cliente **\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            r = -1 ;
            system("pause");
        }
        else
        {
            printf("\n Codigo Cliente %d \n",index) ;
            newCliente.codigoCliente = index ;
            if(!getStringLetras("Ingrese nombre: ",auxName))
            {
                printf("El nombre solo debe estar compuesto por letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!getStringLetrasFM("\nIngrese  sexo f/m: ",auxSexo))
            {
                printf("\nEl sexo debe ser f/m \n\n");
                system("pause");
                system("cls");

            }
            else if(!getStringNumerosTelefono("\nIngrese  sector: ",auxTelefono))
            {
                printf("\nError al ingresar telefono.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(newCliente.nombreCliente, auxName);
                strcpy(newCliente.sexo, auxSexo);
                strcpy(newCliente.telefono, auxTelefono);
                newCliente.isEmptyCliente = 0;
                list[index] = newCliente;
                system("pause");
                system("cls");
                printf("\n\nNUEVO CLIENTE INGRESADO:\n\n");
                printCliente(list[index]);
                printf("\n\n\n");
                system("pause");
                r = 0 ;
            }
        }

    }
    else
    {
        r = -1 ;
    }
    return r;
}
void printCliente(sCliente list)
{
    printf("\nCOD.CLIENTE:%d - NOMBRE:%s - SEXO:%s - TELEFONO:%s -  \n\n", list.codigoCliente, list.nombreCliente, list.telefono);
}

void printClientes(sCliente* list, int len)
{
    system("cls");
    printf("\n COD.CLIENTE NOMBRE SEXO TELEFONO\n\n");

    for(int i = 0; i < len; i++)
    {

        if(list[i].isEmptyCliente == 0)
        {
            printCliente(list[i]);
        }
    }
    system("pause");
}

int findClienteById(sCliente* list, int len, int id)
{
    int r = -1;

    for(int i = 0; i < len; i++)
    {
        if((list[i].isEmptyCliente == 0)&&(list[i].codigoCliente == id))
        {
            r = i; /** LE ASIGNO LA POSICION  ENCONTRADA Y SALGO **/
            break;
        }
    }
    return r;
}

void modifyCliente(sCliente* list, int len)
{

    int index;
    int id;
    int answer;
    char newName[51];
    char newSexo;
    char newTelefono[15];


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

        printf("Baja id %d",list[index].codigoCliente, len);
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
                        printf("\nModificacion de nombre cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo nombre: \n");
                        fflush(stdin);
                        gets(newName);
                        strcpy(list[index].nombreCliente, newName);

                        printf("\nModificacion de nombre exitosa\n\n");
                    }
                    break;

            case 2:
                    printf("¿ Modificar sexo ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);
                    if(answer == 'n')
                    {
                        printf("\nModificacion de sexo cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo sexo: \n");
                        scanf("%s", &newSexo);
                        list[index].sexo = newSexo;

                        printf("\nModificacion de sexo exitosa\n\n");
                    }
                    break;

            case 4:
                    printf("¿ Modificar telefono ? s/n: ");
                    fflush(stdin);
                    scanf("%c", &answer);
                    if(answer == 'n')
                    {
                        printf("\nModificacion de telefono cancelada\n\n");
                    }
                    else
                    {
                        printf("Ingrese nuevo telefono: \n");
                        fflush(stdin);
                        gets(newTelefono);
                        list[index].telefono = newTelefono;

                        printf("\nModificacion de telefono exitosa\n\n");
                    }
                    break;

    system("pause");
    }
    }
}



/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* message, char* input)
{
    printf("%s", message);
    scanf ("%s", input);
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* message)
{
    char auxiliar;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char* str)
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' )&&(str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int esTelefono(char* str)
{
   int i = 0;
   int contGuiones = 0;
    while(str[i] != '\0')
   {
       if (str[i] == '-' && contGuiones == 0)
       {
           contGuiones++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}



/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char* str)
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

int esSoloLetrasFM(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != 'f') ||(str[i] != 'm') && (str[i] != 'F') || (str[i] != 'M'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char* message ,char* input)
{
    int r = 0;
    char aux[256];
    getString(message,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        r = 1;
    }

    return r;
}

int getStringLetrasFM(char* message ,char* input)
{
    int r = 0;
    char aux[256];
    getString(message,aux);
    if(esSoloLetrasFM(aux))
    {
        strcpy(input,aux);
        r = 1;
    }

    return r;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char* message ,char* input)
{
    int r = 0;
    char aux[256];
    getString(message,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        r = 1;
    }

    return r;
}
int getStringNumerosTelefono(char* message ,char* input)
{
    int r = 0;
    char aux[256];
    getString(message,aux);
    if(esTelefono(aux))
    {
        strcpy(input,aux);
        r = 1;
    }

    return r;
}

int validarNumeroFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarNumeroFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void harcodeoCliente(sCliente* list)
{

    sCliente x[]={
    {1111,"Juan",'m',4564-1002},
    {1112,"Pedro",'m',4568-2222},
    {1113,"Juana",'f',4464-1654},
    {1114,"Ana",'f',4864-1012},
    {1115,"Sara",'f',4569-1818}
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
}
