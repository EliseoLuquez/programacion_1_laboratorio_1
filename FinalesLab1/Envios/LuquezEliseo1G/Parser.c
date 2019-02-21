#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Envio.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idEnvioStr[6];
    char nombreProductoStr[20];
    char idCamionStr[6];
    char zonaDestinoStr[20];
    char kmRecorridoStr[20];
    char tipoEntregaStr[20];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idEnvioStr, nombreProductoStr, idCamionStr, zonaDestinoStr, kmRecorridoStr, tipoEntregaStr);
            if(cant != 6)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                Envio* env;
                env = envio_newParametros(idEnvioStr, nombreProductoStr, idCamionStr, zonaDestinoStr, kmRecorridoStr, tipoEntregaStr);
                env->costoEnvio = 0;
                ll_add(pArrayListEnvio, env);
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


