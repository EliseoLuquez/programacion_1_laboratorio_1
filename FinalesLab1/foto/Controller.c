#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


int controller_List(LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayList);

    if(pArrayList != NULL)
    {
        if(len != 0)
        {
            printf("Id Fecha Tipo Cant. Precio Unit. Cuit\n\n");
            for(int i = 0; i < len; i++)
            {
                venta_showVentas(pArrayList);
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_ventaFromText(pFile, pArrayList);
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
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int controller_ListVenta(LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayList);

    if(pArrayList != NULL)
    {
        if(len != 0)
        {
            printf("*******************\n");
            printf("Informe de ventas\n");
            printf("*******************\n");
            printf("- Cantidad de fotos revelados totales: %d\n", ll_count(pArrayList ,venta_fotoCantidad));
            printf("- Cantidad de ventas por un monto mayor a $150: %d\n", ll_count(pArrayList, venta_ventasMayor150));
            printf("- Cantidad de ventas por un monto mayor a $300: %d\n", ll_count(pArrayList, venta_ventasMayor300));
            printf("- Cantidad de fotos Polaroids reveladas: %d\n", ll_count(pArrayList, venta_cantidadFotosPolarodids));
            printf("*******************\n");
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
/**int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),employee_getHorasTrabajadas(lista),employee_getSueldo(lista));
    }
    return 1;
}**/


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    Venta* pVenta;


    if(pArrayList != NULL)
    {
        fprintf(pFile, "*******************\n");
        fprintf(pFile,"Informe de ventas\n");
        fprintf(pFile,"*******************\n");
        fprintf(pFile,"- Cantidad de fotos revelados totales: %d\n", ll_count(pArrayList, venta_fotoCantidad));
        fprintf(pFile,"- Cantidad de ventas por un monto mayor a $150: %d\n", ll_count(pArrayList, venta_ventasMayor150));
        fprintf(pFile,"- Cantidad de ventas por un monto mayor a $300: %d\n", ll_count(pArrayList, venta_ventasMayor300));
        fprintf(pFile,"- Cantidad de fotos Polaroids reveladas: %d\n", ll_count(pArrayList, venta_cantidadFotosPolarodids));
        fprintf(pFile,"*******************\n");
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


