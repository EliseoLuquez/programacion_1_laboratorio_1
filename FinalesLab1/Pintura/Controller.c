#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Color.h"
#include "Componente.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_colorLoadFromText(char* path , LinkedList* pArrayListColor)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r+");
    if(pFile != NULL)
    {
        ret = parser_ColorFromText(pFile, pArrayListColor);
        printf("Datos de color cargados con exito\n");
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_componenteLoadFromText(char* path , LinkedList* pArrayListComponentes)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r+");
    if(pFile != NULL)
    {
        ret = parser_ComponenteFromText(pFile, pArrayListComponentes);
        printf("Datos de componentes cargados con exito\n");
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}





/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 *
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    Employee* emp;


    if(pArrayList != NULL)
    {
        for(int i = 0; i<ll_len(pArrayList);i++)
        {
            emp = (Employee*)ll_get(pArrayList, i);
            fprintf(pFile, "%4d  %s  %s  %d   %s   %d \n",emp->id ,emp->nombre ,emp->apellido, emp->dni, emp->clave);
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
 * \param pArrayList LinkedList*
 * \return int
 *
 *
int controller_saveAsBinary(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pFile;
    pFile = fopen(path, "wb");
    Employee* emp;

    if(ll_len(pArrayList)!= 0)
    {
        if(pArrayList != NULL)
        {
            for(int i = 0; i<ll_len(pArrayList);i++)
            {
                emp = (Employee*)ll_get(pArrayList, i);
                fwrite(emp, sizeof(Employee*), 1, pFile);
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_addComponente(LinkedList* pArrayListComponentes)
{
    int ret;
    ret = RETURN_ERROR;
    int cantComp;
    char respuesta;
    int idAux;
    char idComp[5];
    char nombreAux[50];
    char baseAux[10];

    if(pArrayListComponentes != NULL)
    {
        do
        {
            sComponente* pComponente;
            sComponente* pUltimo;
            cantComp = ll_len(pArrayListComponentes); /** Obtengo la cantidad de componentes **/
            pUltimo = ll_get(pArrayListComponentes, cantComp-1);
            cantComp = pUltimo->componenteId;

            printf("Ingrese el nombre del componente: ");
            scanf("%s", nombreAux);
            for(int i = 0; i < cantComp; i++)
            {
                if(strcmp(pComponente->nombre, nombreAux) == 0)
                {
                    printf("Componente ya Existente!");
                }
                else
                {
                     pComponente = ll_get(pArrayListComponentes, i);
                     idAux = cantComp+1;
                     itoa(idAux, &idComp, 5);
                }

            }
            printf("Ingrese:\n 1-Base\n 2-Pigmento\n");
            scanf("%s", baseAux);

            pComponente = componente_newParameteros(idComp, nombreAux, baseAux);
            //printf("Desea ingresar mas componentes? s -Seguir  n -Salir\n");
            fflush(stdin);
            scanf("%c", &respuesta);

        }while(respuesta == 's');
        ret = RETURN_OK;
        system("cls");
    }
    else
    {
        printf("No hay Datos\n\n");
    }

    return ret;
}



/** \brief Alta Color
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_addColor(LinkedList* pArrayListColor, LinkedList* pArrayListComponentes)
{
    int ret;
    ret = RETURN_ERROR;
    int cantColor;
    int cantComp;
    int idCompAux;
    char idComp[5];
    char idColor[5];
    char resp;
    char colorAux[50];
    char compoAux[50];
    char cantidad[10];
    int id;
    int option;

    sColor* pColor = color_new();
    sComponente* pComponente = componente_new();
    char nombreAux[20];

    cantColor = ll_len(pArrayListColor); /** Obtengo la cantidad de colores **/
    cantComp = ll_len(pArrayListComponentes); /** Obtengo la cantidad de componentes **/

    if(pArrayListComponentes != NULL && pArrayListColor != NULL)
    {
        printf("Ingrese Nombre Color: ");
        scanf("%s", nombreAux);
        for(int i = 0; i < cantColor; i++)
        {
            if(strcmp(pColor->nombre, nombreAux) == 0)
            {
                printf("Color ya Existente!");
            }
            else
            {
                pColor = ll_get(pArrayListColor, i);
                id = cantColor+1;
                itoa(id, &idColor, 5);

            }
        }
        system("cls");
        controller_ListComponentes(pArrayListComponentes);
        printf("Componentes:\n");
        printf("1-Elegir componente existente\n");
        printf("2-Crear nuevo componente \n");
        scanf("%d", &option);
        do{
            if(option == 1)
            {
                printf("Ingrese id de componente : ");
                scanf("%s", idComp);
                idCompAux = atoi(idComp);
                idCompAux = componente_getComponenteId(pArrayListComponentes, &idCompAux);
            }
            else
            {
                controller_addComponente(pArrayListComponentes);
            }
            printf("Ingrese Cantidad en gramos de Componente: ");
            scanf("%s", cantidad);
            pColor = color_newParameteros(idColor, nombreAux, idComp, cantidad);
            ret = ll_add(pArrayListColor, pColor);
            scanf("%c", &resp);
        }while(resp == 's');
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
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_editComponente(LinkedList* pArrayListComponente)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    int id;
    int idEdit;
    int option;
    char nombreAux[20];
    char baseAux[20];

    sComponente* pCompAux = componente_new();
    len = ll_len(pArrayListComponente);
    if(pArrayListComponente != NULL)
    {
        system("cls");
        controller_ListComponentes(pArrayListComponente);
        printf("\nIngrese Id a Editar: ");
        scanf("%d", &idEdit);

        for(int i = 0; i < len; i++)
        {
            pCompAux = (sComponente*) ll_get(pArrayListComponente, i);/**  OBTENGO EL NODO  **/
            id = componente_getComponenteId(pCompAux, &idEdit);/** OBTENGO EL ID DEL NODO **/
            if(id == idEdit)
            {
                option = menuEdit();
                switch(option)
                {
                    case 1:
                            componente_showComponente(pCompAux);
                            scanf("%s",nombreAux);
                            strcpy(pCompAux->nombre, nombreAux);
                            break;
                    case 2:
                            scanf("%s", baseAux);
                            strcpy(pCompAux->base, baseAux);
                            break;
                    default:
                            break;
                }
                ret = ll_set(pArrayListComponente, i, pCompAux);
            }
            else
            {
                printf("Error");
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
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_removeComponente(LinkedList* pArrayListComponentes)
{
    int ret;
    ret = RETURN_ERROR;

    char seguir;
    int idRemove;
    int idAux;
    int indice;
    int len;

    if(pArrayListComponentes != NULL)
    {
        system("cls");
        controller_ListComponentes(pArrayListComponentes);
        printf("Menu Baja\n\n");
        printf("Ingrese Id a dar de Baja: \n");
        scanf("%d", &idRemove);
        len = ll_len(pArrayListComponentes);

        for(int i = 0; i < len; i++)
        {
            indice = (sComponente*) ll_get(pArrayListComponentes, i);/**  OBTENGO EL NODO  **/
            componente_getComponenteId(indice, &idAux);/** OBTENGO EL ID DEL NODO **/

            if(idAux == idRemove)
            {
                 componente_showComponente(ret);

                 printf("\nConfima borrado s/n: ");
                 fflush(stdin);
                 scanf("%c", &seguir);

                 if(seguir == 'n')
                 {
                     printf("Baja cancelada\n\n");
                 }
                 else

                 {
                     ll_remove(pArrayListComponentes, i);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }

    return ret;
}

int controller_ListColores(LinkedList* pArrayListColor)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListColor);

    if(pArrayListColor!= NULL)
    {
        if(len != 0)
        {
            printf("Id Nombre  idComp Cant\n\n");
            for(int i = 0; i < len; i++)
            {
                color_showColores(pArrayListColor);
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


/** \brief Listar Componentes
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int controller_ListComponentes(LinkedList* pArrayListComponentes)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListComponentes);

    if(pArrayListComponentes != NULL)
    {
        if(len != 0)
        {
            printf("Id Nombre    Base\n\n");
            for(int i = 0; i < len; i++)
            {
                componente_showComponentes(pArrayListComponentes);
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


