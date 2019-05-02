#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Color.h"
#include "Componente.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_ColorFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idColorStr[10];
    char nombreStr[50];
    char idComponenteStr[10];
    char cantidadStr[10];


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^;];%[^;];%[^;];%[^;\n]\n", idColorStr, nombreStr, idComponenteStr, cantidadStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;\n]\n", idColorStr, nombreStr, idComponenteStr, cantidadStr);
            if(cant != 4)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                sColor* color;
                color = color_newParameteros(idColorStr, nombreStr, idComponenteStr, cantidadStr);
                ll_add(pArrayList, color);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
        system("pause");
    }

    return ret;
}




/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_ComponenteFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idComponenteStr[10];
    char nombreStr[50];
    char baseStr[10];


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^;];%[^;];%[^;\n]\n", idComponenteStr, nombreStr, baseStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^;];%[^;];%[^;\n]\n", idComponenteStr, nombreStr, baseStr);
            if(cant != 3)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                sComponente* comp;
                comp = componente_newParameteros(idComponenteStr, nombreStr, baseStr);
                ll_add(pArrayList, comp);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
        system("pause");
    }

    return ret;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVendedor LinkedList*
 * \return int
 *
 */
 /*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListVendedor)
{
    int ret;
    ret = RETURN_ERROR;

    if(pFile != NULL)//
    {
        while(!feof(pFile))
        {

                Vendedor* emp = vendedor_new();
                ret = fread(emp, sizeof(Vendedor),1,pFile);
                if(ret != 1)
                {
                    printf("Error al caargar datos\n");
                }
                else
                {
                    ll_add(pArrayListVendedor, emp);
                }
        }
    fclose(pFile);
    ret = RETURN_OK;
    }
    else
    {
        printf("No hay datos");
        system("pause");
    }

    return ret;
}
*/




