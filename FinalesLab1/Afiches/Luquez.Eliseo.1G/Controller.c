#include <stdio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cliente.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("cliente.txt", "r");
    if(pFile != NULL)
    {
        ret = parser_clienteFromText(pFile, pArrayCliente);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}


int controller_loadVentaFromText(char* path , LinkedList* pArrayListVenta)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("venta.txt", "r");
    if(pFile != NULL)
    {
        ret = parser_ventaFromText(pFile, pArrayListVenta);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
/*int controller_loadFromBinary(char* path , LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        ret = parser_EmployeeFromBinary(pFile, pArrayCliente);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}*/

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
    int ret;
    ret = RETURN_ERROR;

    sCliente* pCliente = cliente_new();
    sCliente* pUltCli;
    sCliente* auxCliente;
    int lencliente;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    char auxId[10];

    if(pArrayListCliente != NULL)
    {
        lencliente = ll_len(pArrayListCliente);
        pUltCli = ll_get(pArrayListCliente, lencliente-1);
        lencliente = pUltCli->id;
        sprintf(auxId, "%d", lencliente+1);

        printf("Ingrese Nombre: ");
        scanf("%s", nombre);

        printf("Ingrese Apellido: ");
        scanf("%s", apellido);

        printf("Ingrese Cuit: ");
        scanf("%s", cuit);

        for(int i = 0; i < lencliente; i++)
        {
            auxCliente = ll_get(pArrayListCliente, i);
            if(strcmp(cuit, auxCliente->cuit) == 0)
            {
                printf("Ya existe un cliente con Cuit: %s", cuit);
                system("pause");
                break;
            }
            else
            {
                pCliente = cliente_newParametros(auxId, nombre, apellido, cuit);
                ll_add(pArrayListCliente, pCliente);
                printf("Cliente ingresado con exito!\n");
                system("pause");
                ret = RETURN_OK;
                break;
            }
        }

    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
/*int controller_editEmployee(LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;

    int id;
    int idEdit;
    char nombreEmp[20];
    int horasTrabajadas;
    int sueldo;

    sCliente* empAux = employee_new();

    if(pArrayCliente != NULL)
    {
        system("cls");
        printf("\nIngrese Id: ");
        scanf("%d", &idEdit);

        for(int i = 0; i < ll_len(pArrayCliente); i++)
        {
            empAux = (sCliente*) ll_get(pArrayCliente, i);
            ret = employee_getId(empAux, &id);

            if(ret == RETURN_OK)
            {
                if(id == idEdit)
                {
                    switch(menuEdit())
                    {
                    case 1:
                            employee_showEmployee(empAux);
                            printf("Ingrese Nombre: ");
                            scanf("%s",empAux->nombre);
                            strcpy(empAux->nombre, nombreEmp);
                            break;
                    case 2:
                            printf("Ingrese Horas Trabajadas: ");
                            scanf("%d",empAux->horasTrabajadas);
                            empAux->horasTrabajadas = horasTrabajadas;
                            break;
                    case 3:
                            printf("Ingrese Sueldo: ");
                            scanf("%d",empAux->sueldo);
                            empAux->sueldo = sueldo;
                            break;
                    case 4:
                            break;

                    }
                    ret = ll_set(pArrayCliente, i, empAux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }




    return ret;
}
*/
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
/*int controller_removeEmployee(LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;

    char seguir;
    int id = 0;
    int indice;

    if(pArrayCliente != NULL)
    {
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayCliente); i++)
        {
            indice = (sCliente*) ll_get(pArrayCliente, i);
            ret = employee_getId(indice, &id);

            if(ret == RETURN_OK)
            {
                 employee_showEmployee(ret);

                 printf("\nConfima borrado s/n: ");
                 fflush(stdin);
                 scanf("%c", &seguir);

                 if(seguir == 'n')
                 {
                     printf("Baja cancelada\n\n");

                 }
                 else

                 {
                     ll_remove(pArrayCliente, indice);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }

    return ret;
}
*/
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
int controller_ListCliente(LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayCliente);

    if(pArrayCliente != NULL)
    {
        if(len != 0)
        {
            printf("Id  Nombre  Apellido  Cuit\n\n");
            for(int i = 0; i < len; i++)
            {
                cliente_showClientes(pArrayCliente);
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

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
/*int controller_sortEmployee(LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;
    if(pArrayCliente != NULL)
    {
        switch(menuSort())
        {
        case 1:
                ll_sort(pArrayCliente, employee_sortById,1);
                employee_showEmployees(pArrayCliente);
                break;
        case 2:
                ll_sort(pArrayCliente, employee_sortByName,1);
                employee_showEmployees(pArrayCliente);
                break;
        case 3:
                ll_sort(pArrayCliente, employee_sortByHsTrabajadas,1);
                employee_showEmployees(pArrayCliente);
                break;
        case 4:
                ll_sort(pArrayCliente, employee_sortBySueldo,1);
                employee_showEmployees(pArrayCliente);
                break;
        case 5:
                break;
        }
    }
    else
    {
        printf("No hay datos\n");
    }
    system("pause");

    return ret;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
/*int controller_saveAsText(char* path , LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen("info.csv", "w");
    sCliente* emp;


    if(pArrayCliente != NULL)
    {
        for(int i = 0; i<ll_len(pArrayCliente);i++)
        {
            emp = (sCliente*)ll_get(pArrayCliente, i);
            fprintf(pFile, "%d,%s,%d,%d,",emp->id ,emp->nombre ,emp->horasTrabajadas, emp->sueldo);
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
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayCliente LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path , LinkedList* pArrayCliente)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pFile;
    pFile = fopen("data.bin", "wb");
    sCliente* emp;

    if(ll_len(pArrayCliente)!= 0)
    {
        if(pArrayCliente != NULL)
        {
            for(int i = 0; i<ll_len(pArrayCliente);i++)
            {
                emp = (sCliente*)ll_get(pArrayCliente, i);
                fwrite(emp, sizeof(sCliente*), 1, pFile);
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
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addVenta(LinkedList* pArrayListVenta)
{
    int ret;
    ret = RETURN_ERROR;

    sVenta* pVenta;
    sVenta* pUltVenta;


    int lenVenta;
    char idClienteAux[50];
    char nombreArchImg[50];
    char cantAfiches[50];
    char zona[50];
    char auxId[10];
    char estadoAux[50];

    if(pArrayListVenta != NULL)
    {
        lenVenta = ll_len(pArrayListVenta);
        pUltVenta = ll_get(pArrayListVenta, lenVenta-1);
        lenVenta = pUltVenta->idVenta;
        sprintf(auxId, "%d", lenVenta+1);

        printf("Ingrese Id Cliente: ");
        scanf("%s", idClienteAux);

        printf("Ingrese Cantidad Afiches: ");
        scanf("%s", cantAfiches);

        printf("Ingrese Nombre de archivo Imagen: ");
        scanf("%s", nombreArchImg);

        printf("Ingrese Zona: ");
        scanf("%s", zona);

        estadoAux[50] = "a cobrar";
        pVenta = venta_newParametros(auxId, idClienteAux, cantAfiches, nombreArchImg, zona, estadoAux);
        ll_add(pArrayListVenta, pVenta);
        printf("venta ingresada con exito!");
        system("pause");
        ret = RETURN_OK;
    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;
}

