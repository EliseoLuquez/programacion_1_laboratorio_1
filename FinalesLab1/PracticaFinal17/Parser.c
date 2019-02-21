#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Usuarios.h"
#include "Temas.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
int parser_UsuariosFromText(FILE* pFile , LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char nombreStr[128];
    char emailStr[50];
    char sexoStr[20];
    char paisStr[20];
    char passwordStr[20];
    char ip_AddressStr[20];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, emailStr, sexoStr, paisStr, passwordStr, ip_AddressStr);
            if(cant != 7)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                Usuario* usrio = usuario_newParametros(idStr, nombreStr, emailStr, sexoStr, paisStr, passwordStr, ip_AddressStr);

                ll_add(pArrayListUsuario, usrio);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Archivo no hay datos\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListUsuario LinkedList*
 * \return int
 *
 */
int parser_UsuariosFromBinary(FILE* pFile , LinkedList* pArrayListUsuario)
{
    int ret;
    ret = RETURN_ERROR;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Usuario* usrio = usuario_new();
                ret = fread(usrio, sizeof(Usuario),1,pFile);
                if(ret != 1)
                {
                    printf("Error al cargar datos\n");
                }
                else
                {
                    ll_add(pArrayListUsuario, usrio);
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



