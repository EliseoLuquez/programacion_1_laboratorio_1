#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "Parser.h"
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

int controller_loadFromTextFichajes(char* path , LinkedList* pArrayListFichaje)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_fichajeFromText(pFile, pArrayListFichaje);
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

int controller_listEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        if(len != 0)
        {
            printf(" Id  Nombre  Apellido  DNI  Clave \n\n");
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

int controller_listFichajes(LinkedList* pArrayListFichaje)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListFichaje);

    if(pArrayListFichaje != NULL)
    {
        if(len != 0)
        {
            printf("IdFich  IdEmp  hr/min dia/mes/anio \n\n");
            for(int i = 0; i < len; i++)
            {
                fichaje_showFichajes(pArrayListFichaje);
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

    Employee* pEmp = employee_new();
    Employee* pUltEmp;
    int lenEmp;
    char nombre[20];
    char apellido[20];
    char dni[20];
    char clave[20];
    char auxId[10];

    if(pArrayListEmployee != NULL)
    {
        lenEmp = ll_len(pArrayListEmployee);
        pUltEmp = ll_get(pArrayListEmployee, lenEmp-1);
        lenEmp = pUltEmp->id;
        sprintf(auxId, "%d", lenEmp+1);

        printf("Ingrese Nombre: ");
        scanf("%s", nombre);

        printf("Ingrese Apellido: ");
        scanf("%s", apellido);

        printf("Ingrese dni: ");
        scanf("%s", dni);

        printf("Ingrese Clave: ");
        scanf("%s", clave);

        pEmp = employee_newParametros(auxId, nombre, apellido, dni, clave);
        ll_add(pArrayListEmployee, pEmp);
        ret = RETURN_OK;
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

    int len;
    int id;
    int idEdit;
    int dniAux;
    char nombreAux[50];
    char apellidoAux[50];
    char claveAux[50];


    Employee* empAux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        controller_listEmployee(pArrayListEmployee);
        printf("\nIngrese Id: ");
        scanf("%d", &idEdit);
        len = ll_len(pArrayListEmployee);

        for(int i = 0; i < len; i++)
        {
            empAux = (Employee*) ll_get(pArrayListEmployee, i);
            for(int i = 0; i < len;i++)
            {

                if(empAux->id == idEdit)
                {
                    switch(menuEdit())
                    {
                    case 1:
                            employee_showEmployee(empAux);
                            printf("Ingrese Nombre: ");
                            scanf("%s",nombreAux);
                            strcpy(empAux->nombre, nombreAux);
                            break;
                    case 2:
                            printf("Ingrese Apellido: ");
                            scanf("%s",apellidoAux);
                            strcpy(empAux->apellido, apellidoAux);
                            break;
                    case 3:
                            printf("Ingrese Dni: ");
                            scanf("%d",&dniAux);
                            empAux->dni = dniAux;
                            break;
                    case 4:
                            printf("Ingrese Clave: ");
                            scanf("%s",claveAux);
                            strcpy(empAux->clave, claveAux);
                            break;
                    case 5:
                            employee_showEmployee(empAux);
                            printf("Ingrese Nombre: ");
                            scanf("%s",nombreAux);
                            strcpy(empAux->nombre, nombreAux);

                            printf("Ingrese Apellido: ");
                            scanf("%s",apellidoAux);
                            strcpy(empAux->apellido, apellidoAux);

                            printf("Ingrese Dni: ");
                            scanf("%d", &dniAux);
                            empAux->dni = dniAux;

                            printf("Ingrese Clave: ");
                            scanf("%s", claveAux);
                            strcpy(empAux->clave, claveAux);
                            break;
                    }
                    break;
                    //ll_set(pArrayListEmployee, i, empAux);
                    ret = RETURN_OK;
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
    Employee* pEmp;
    char seguir;
    int id = 0;

    if(pArrayListEmployee != NULL)
    {
        controller_listEmployee(pArrayListEmployee);
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmp = (Employee*) ll_get(pArrayListEmployee, i);

            if(pEmp->id == id)
            {
                 employee_showEmployee(pEmp);

                 printf("\nConfima borrado s/n: ");
                 fflush(stdin);
                 scanf("%c", &seguir);

                 if(seguir == 'n')
                 {
                     printf("Baja cancelada\n\n");

                 }
                 else

                 {
                     ll_remove(pArrayListEmployee, i);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }

    return ret;
}

int controller_addFichaje(LinkedList* pArrayListEmployee, LinkedList* pArrayListFichaje)
{
    int ret;
    ret = RETURN_ERROR;
    Employee* pEmp;
    sFichaje* pFich;
    sFecha* fecha;
    int lenFichaje;
    int lenEmp;
    int idFichaje;
    int idEmp;
    char idFichajeStr[10];
    char idEmployeeStr[10];
    char inOut[10];
    char claveAux[20];
    char hora[10];
    char min[10];
    char dia[10];
    char mes[10];
    char anio[10];
    int cantF;
    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID Empleado: ");
        scanf("%d", &idEmp);
        printf("Ingrese clave: ");
        scanf("%s", claveAux);

        lenEmp = ll_len(pArrayListEmployee);
        lenFichaje = ll_len(pArrayListFichaje);

        for(int i = 0; i < lenEmp; i++)
        {
            pEmp = ll_get(pArrayListEmployee, i);

            if((pEmp->id == idEmp)&&(strcmp(pEmp->clave, claveAux)) == 0)
            {
                pFich = ll_get(pArrayListFichaje, lenFichaje-1);
;
                cantF = (&pFich->idFichaje+1);
                printf("%d", cantF);
                //sprintf(idFichajeStr,"%d", cantF);/** Paso cantF a String **/
                itoa(cantF, &idFichajeStr, 10);

                //sprintf(idEmployeeStr,"%d", idEmp);
                itoa(idEmp, &idEmployeeStr, 10);
                /** no entra **/
                printf("Ingrese IN/OUT: ");
                scanf("%s", inOut);

                printf("Ingrese Hora: ");
                scanf("%s", hora);

                printf("Ingrese Minutos: ");
                scanf("%s", min);

                printf("Ingrese Dia: ");
                scanf("%s", dia);

                printf("Ingrese Mes: ");
                scanf("%s", mes);

                printf("Ingrese Anio: ");
                scanf("%s", anio);

                fecha = fecha_newParameteros(hora, min, dia, mes, anio);
                printf(" ya ingrese todos los datos");
                pFich = fichaje_newParametros(idFichajeStr, idEmployeeStr, inOut, fecha);
                ll_add(pArrayListEmployee, pFich);
                ret = RETURN_OK;
                break;

            }
        }
        if(ret != 1)
        {
            printf("Error en el usuario o clave");
        }

    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;
}


int controller_filterForFecha(LinkedList* pArrayListEmployee, LinkedList* pArrayListFichaje, LinkedList* pArrayListFilter)
{
    int dia;
    int mes;
    int anio;
    int lenEmp;
    int lenFich;
    int listFilter;
    int ret;
    ret = RETURN_ERROR;

    Employee* pEmp;
    sFichaje* pFichaje;

    printf("Ingrese Dia: ");
    scanf("%d", &dia);

    printf("Ingrese Mes: ");
    scanf("%d", &mes);

    printf("Ingrese Anio: ");
    scanf("%d", &anio);

    lenEmp = ll_len(pArrayListEmployee);
    lenFich = ll_len(pArrayListFichaje);

    for(int i = 0; i < lenFich-1; i++)
    {
        pFichaje = ll_get(pArrayListFichaje, i);
        printf("%d\n", dia);
        printf("%d", pFichaje->fecha.dia);
        if((pFichaje->fecha.dia == dia) && (pFichaje->fecha.mes  == mes) && ( pFichaje->fecha.anio == anio) && (strcmp(pFichaje->inOut, "IN")) == 0)
        {
            printf("\npaso el 1 if");
            for(int j = 0; j < lenEmp-1; j++)
            {
                pEmp = ll_get(pArrayListEmployee, j);
                if(pEmp->id == pFichaje->idEmployee)
                {
                    ll_add(pArrayListFilter, pEmp);
                    ret = RETURN_OK;
                    break;
                }
            }
        }
        else
        {
            printf("No hay ingresos en la fecha");
            break;
        }
    }
    listFilter = ll_len(pArrayListFilter);
    controller_listFichajes(pArrayListFilter);

    return ret;

}




