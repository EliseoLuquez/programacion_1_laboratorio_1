#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Usuarios.h"
#include "Temas.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_UsuariosFromText(pFile, pArrayListUsuario);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        ret = parser_UsuariosFromBinary(pFile, pArrayListUsuario);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 *//*
int controller_addEmployee(LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    Vendedor* vend = employee_new();
    int id;
    char nombre[20];
    int horasTeabajadas;
    int sueldo;

    if(pArrayListUsuario != NULL)
    {
        printf("Ingrese ID: ");
        scanf("%d", &id);
        ret = employee_setId(emp, id);

        printf("Ingrese Nombre: ");
        scanf("%s", nombre);
        ret = employee_setNombre(emp, nombre);

        printf("Ingrese Horas Trabajadas: ");
        scanf("%d", &horasTeabajadas);
        ret = employee_setHorasTrabajadas(emp, horasTeabajadas);

        printf("Ingrese Sueldo: ");
        scanf("%d", &sueldo);
        ret = employee_setSueldo(emp, sueldo);

        ret = ll_add(pArrayListUsuario, emp);
    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
/*int controller_editEmployee(LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    int id;
    int idEdit;
    char nombreEmp[20];
    int horasTrabajadas;
    int sueldo;

    Vendedor* empAux = employee_new();

    if(pArrayListUsuario != NULL)
    {
        system("cls");
        printf("\nIngrese Id: ");
        scanf("%d", &idEdit);

        for(int i = 0; i < ll_len(pArrayListUsuario); i++)
        {
            empAux = (Vendedor*) ll_get(pArrayListUsuario, i);
            ret = employee_getId(empAux, &id);

            if(ret == RETURN_OK)
            {
                if(id == idEdit)
                {
                    switch(menuEdit())
                    {
                    case 1:
                            employee_showEmployee(empAux);
                            printf("Ingrese Nombre: ");
                            scanf("%s",empAux->nombre);
                            strcpy(empAux->nombre, nombreEmp);
                            break;
                    case 2:
                            printf("Ingrese Horas Trabajadas: ");
                            scanf("%d",empAux->horasTrabajadas);
                            empAux->horasTrabajadas = horasTrabajadas;
                            break;
                    case 3:
                            printf("Ingrese Sueldo: ");
                            scanf("%d",empAux->sueldo);
                            empAux->sueldo = sueldo;
                            break;
                    case 4:
                            break;

                    }
                    ret = ll_set(pArrayListUsuario, i, empAux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }




    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 *
int controller_removeEmployee(LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    char seguir;
    int id = 0;
    int indice;

    if(pArrayListUsuario != NULL)
    {
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListUsuario); i++)
        {
            indice = (Vendedor*) ll_get(pArrayListUsuario, i);
            ret = employee_getId(indice, &id);

            if(ret == RETURN_OK)
            {
                 employee_showEmployee(ret);

                 printf("\nConfima borrado s/n: ");
                 fflush(stdin);
                 scanf("%c", &seguir);

                 if(seguir == 'n')
                 {
                     printf("Baja cancelada\n\n");

                 }
                 else

                 {
                     ll_remove(pArrayListUsuario, indice);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }

    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */

int controller_ListUsuario(LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListUsuario);

    if(pArrayListUsuario != NULL)
    {
        if(len != 0)
        {
            printf("Id Nombre Email Sexo  Pais Passwprd Ip_Address\n\n");
            for(int i = 0; i < len; i++)
            {
                usuario_showUsuarios(pArrayListUsuario);
                ret = RETURN_OK;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            system("pause");
        }
    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
/*
int controller_sortEmployee(LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;
    if(pArrayListUsuario != NULL)
    {
        switch(menuSort())
        {
        case 1:
                ll_sort(pArrayListUsuario, employee_sortById,1);
                employee_showEmployees(pArrayListUsuario);
                break;
        case 2:
                ll_sort(pArrayListUsuario, employee_sortByName,1);
                employee_showEmployees(pArrayListUsuario);
                break;
        case 3:
                ll_sort(pArrayListUsuario, employee_sortByHsTrabajadas,1);
                employee_showEmployees(pArrayListUsuario);
                break;
        case 4:
                ll_sort(pArrayListUsuario, employee_sortBySueldo,1);
                employee_showEmployees(pArrayListUsuario);
                break;
        case 5:
                break;
        }
    }
    else
    {
        printf("No hay datos\n");
    }
    system("pause");

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    Usuario* usrio;


    if(pArrayListUsuario != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListUsuario);i++)
        {
            usrio = (Usuario*)ll_get(pArrayListUsuario, i);
            fprintf(pFile, "%d,%s,%s,%s,%s,%s,%s\n",usrio->id ,usrio->nombre ,usrio->email, usrio->sexo, usrio->pais, usrio->password, usrio->ip_Address);
        }
        fclose(pFile);
        ret = RETURN_OK;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pFile;
    pFile = fopen(path, "wb");
    Usuario* usrio;

    if(ll_len(pArrayListUsuario)!= 0)
    {
        if(pArrayListUsuario != NULL)
        {
            for(int i = 0; i<ll_len(pArrayListUsuario);i++)
            {
                usrio = (Usuario*)ll_get(pArrayListUsuario, i);
                fwrite(usrio, sizeof(Usuario*), 1, pFile);
            }
            fclose(pFile);
            ret = RETURN_OK;
        }
        else
        {
            printf("No hay Archivo\n");
            system("pause");
        }
     }
     else
     {
         printf("No hay Datos\n");
     }

    return ret;
}

