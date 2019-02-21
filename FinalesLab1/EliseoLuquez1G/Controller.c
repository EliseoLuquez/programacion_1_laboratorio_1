#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
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
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        if(len != 0)
        {
            printf("Id Nombre Apellido  DNI  Clave \n\n");
            for(int i = 0; i < len; i++)
            {
               employee_showEmployees(pArrayListEmployee);
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
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    Employee* emp;


    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListEmployee);i++)
        {
            emp = (Employee*)ll_get(pArrayListEmployee, i);
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pFile;
    pFile = fopen(path, "wb");
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    Employee* emp = employee_new();
    int id;
    char nombre[20];
    char apellido[20];
    int dni;
    char clave[20];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        scanf("%d", &id);
        ret = employee_setId(emp, id);

        printf("Ingrese Nombre: ");
        scanf("%s", nombre);
        ret = employee_setNombre(emp, nombre);

        printf("Ingrese Apellido: ");
        scanf("%d", &apellido);
        ret = employee_setApellido(emp, apellido);

        printf("Ingrese dni: ");
        scanf("%d", &dni);
        ret = employee_setDni(emp, dni);

        ret = ll_add(pArrayListEmployee, emp);

        printf("Ingrese Clave: ");
        scanf("%d", &apellido);
        ret = employee_setClave(emp, clave);
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
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    int id;
    int idEdit;
    char nombreEmp[20];
    char ApellidoEmp[20];
    int dniEmp;
    char claveEmp[20];

    Employee* empAux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("\nIngrese Id: ");
        scanf("%d", &idEdit);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empAux = (Employee*) ll_get(pArrayListEmployee, i);
            ret = employee_getIdEmployee(empAux, &id);

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
                            printf("Ingrese Apellido: ");
                            scanf("%s",empAux->apellido);
                            strcpy(empAux->apellido, ApellidoEmp);
                            break;
                    case 3:
                            printf("Ingrese DNI: ");
                            scanf("%d",empAux->dni);
                            empAux->dni = dniEmp;
                            break;
                    case 4:
                            printf("Ingrese Clave: ");
                            scanf("%s",empAux->clave);
                             strcpy(empAux->clave, claveEmp);
                            break;
                    case 5:
                            break;
                    }
                    ret = ll_set(pArrayListEmployee, i, empAux);
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    char seguir;
    int id = 0;
    int indice;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            indice = (Employee*) ll_get(pArrayListEmployee, i);
           // ret = employee_gettId(indice, &id);

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
                     ll_remove(pArrayListEmployee, indice);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }

    return ret;
}





