#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cliente.h"
#define RETURN_OK 1
#define RETURN_ERROR 0
/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_ventaFromText(FILE* pFile, LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idVentaStr[10];
    char idClienteStr[10];
    char CantAfichesStr[50];
    char nombreImgStr[50];
    char zonaStr[50];
    char estadoStr[50];

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idVentaStr, idClienteStr, CantAfichesStr, nombreImgStr, zonaStr, estadoStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idVentaStr, idClienteStr, CantAfichesStr, nombreImgStr, zonaStr, estadoStr);
            if(cant != 6)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
                break;
            }
            else
            {
                sVenta* pVenta;
                pVenta = venta_newParametros(idVentaStr, idClienteStr, CantAfichesStr, nombreImgStr, zonaStr, estadoStr);
                ll_add(pArrayList, pVenta);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo sin datos\n\n");
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
int parser_clienteFromText(FILE* pFile , LinkedList* pArrayListCliente)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[10];
    char nombreStr[50];
    char apellidoStr[50];
    char cuitStr[50];


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, apellidoStr, cuitStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, apellidoStr, cuitStr);
            if(cant != 4)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                sCliente* pCliente;

                pCliente = cliente_newParametros(idStr, nombreStr, apellidoStr, cuitStr);
                ll_add(pArrayListCliente, pCliente);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo sin datos\n\n");
        system("pause");
    }

    return ret;
}
