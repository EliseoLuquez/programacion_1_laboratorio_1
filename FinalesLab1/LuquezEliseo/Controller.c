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

/*
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
/*
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
            printf("IDE Nom.Prod IDC ZonaDest.  KmRec TipoEntrega  CostoEnvio\n\n");
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
*/

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        ret = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}*/


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *//*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pFile;
    pFile = fopen("data.bin", "wb");
    Employee* emp;

    if(ll_len(pArrayListEmployee)!= 0)
    {
        if(pArrayListEmployee != NULL)
        {
            for(int i = 0; i<ll_len(pArrayListEmployee);i++)
            {
                emp = (Employee*)ll_get(pArrayListEmployee, i);
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
*/
/** \brief Alta Color
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 *//*
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
   /* cantComp = ll_len(pArrayListComponentes); /** Obtengo la cantidad de componentes **/
/*
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

*/

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 *//*
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
           /* id = componente_getComponenteId(pCompAux, &idEdit);/** OBTENGO EL ID DEL NODO **/
          /*  if(id == idEdit)
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
}*/

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 *//*
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
          /*  indice = (sComponente*) ll_get(pArrayListComponentes, i);/**  OBTENGO EL NODO  **/
         /*  componente_getComponenteId(indice, &idAux);/** OBTENGO EL ID DEL NODO **/
/*
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
}*/
