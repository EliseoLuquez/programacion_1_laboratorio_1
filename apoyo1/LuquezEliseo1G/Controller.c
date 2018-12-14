#include <stdio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Envio.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEnvio)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_EnvioFromText(pFile, pArrayListEnvio);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */

int controller_ListEnvio(LinkedList* pArrayListEnvio)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListEnvio);

    if(pArrayListEnvio != NULL)
    {
        if(len != 0)
        {
            printf("IDE Nom.Prod IDC zonaDest.  KmRec TipoEntrega  CostoEnvio\n\n");
            for(int i = 0; i < len; i++)
            {
                envio_showEnvios(pArrayListEnvio);
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


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    Envio* env;


    if(pArrayListEnvio != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListEnvio);i++)
        {
            env = (Envio*)ll_get(pArrayListEnvio, i);
            fprintf(pFile, "%4d  %s  %d  %s   %.2f   %d  %.2f \n",env->idEnvio ,env->nombreProd ,env->idCamion, env->zonaDestino, env->kmRecorrido, env->tipoEntrega, env->costoEnvio);
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




