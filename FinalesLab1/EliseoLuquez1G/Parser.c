#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char nombreStr[20];
    char apellidoStr[6];
    char dniStr[20];
    char claveStr[20];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, apellidoStr, dniStr, claveStr);
            if(cant != 5)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                Employee* emp;
                emp = employee_newParametros(idStr, nombreStr, apellidoStr, dniStr, claveStr);
                ll_add(pArrayList, emp);
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

    if(pFile != NULL)
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



