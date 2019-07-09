#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_ventaFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idVentaStr[50];
    char fechaVentaStr[50];
    char tipoFotoStr[50];
    char cantidadStr[50];
    char precioUnitarioStr[50];
    char cuitClienteStr[50];


    if(pFile != NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idVentaStr, fechaVentaStr, tipoFotoStr, cantidadStr, precioUnitarioStr, cuitClienteStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idVentaStr, fechaVentaStr, tipoFotoStr, cantidadStr, precioUnitarioStr, cuitClienteStr);
            if(cant != 6)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                Venta* pVenta;
                pVenta = venta_newParametros(idVentaStr, fechaVentaStr, tipoFotoStr, cantidadStr, precioUnitarioStr, cuitClienteStr);
                ll_add(pArrayList, pVenta);
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

                Vendedor* env = vendedor_new();
                ret = fread(env, sizeof(Vendedor),1,pFile);
                if(ret != 1)
                {
                    printf("Error al caargar datos\n");
                }
                else
                {
                    ll_add(pArrayListVendedor, env);
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
