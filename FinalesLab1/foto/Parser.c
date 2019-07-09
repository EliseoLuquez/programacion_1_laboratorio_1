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
