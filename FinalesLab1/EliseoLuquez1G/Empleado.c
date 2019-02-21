#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

Employee* employee_new()/**  **/
{
    Employee* emp = (Employee *) calloc ( 1 , sizeof (Employee));
    if(emp == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return emp;
}


Employee* employee_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* dniStr, char* claveStr)
{
    Employee* emp = employee_new();
    employee_setId(emp, atoi(idStr));
    employee_setNombre(emp, nombreStr);
    employee_setApellido(emp, apellidoStr);
    employee_setDni(emp, atoi(dniStr));
    employee_setClave(emp, claveStr);

    return emp;
}

int employee_setId(Employee* this,int id)
{
    int ret;
    ret = RETURN_ERROR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        ret = RETURN_OK;
    }
    return ret;
}

int employee_getIdEmployee(Employee* this, int* id)
{
    int ret;
    ret = RETURN_ERROR;

    if(id > 0 && this != NULL)
    {
        *id = this->id;
        ret = RETURN_OK;
    }
    return ret;
}

int employee_getId(Employee* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->id;
    }
    return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        ret = RETURN_OK;
    }

    return ret;
}

char* employee_getNombre(Employee* this)
{
    return this->nombre;
}

int employee_setApellido(Employee* this,char* apellido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->apellido,apellido);
        ret = RETURN_OK;
    }
    return ret;
}

char* employee_getApellido(Employee* this)
{
    return this->apellido;
}

int employee_setDni(Employee* this,int dni)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->dni = dni;
        ret = RETURN_OK;
    }

    return ret;
}

int employee_getDni(Employee* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->id;
    }
    return ret;
}

int employee_setClave(Employee* this,char* clave)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->clave,clave);
        ret = RETURN_OK;
    }
    return ret;
}


char* employee_getClave(Employee* this)
{
    return this->clave;
}

void  employee_showEmployee(Employee* this)
{
    if(this != NULL )
    {
        printf(" %4d  %10s  %10s  %10d   %10s\n\n " , employee_getId(this), employee_getNombre(this),
                 employee_getApellido(this),employee_getDni(this), employee_getClave(this));
    }
}

void  employee_showEmployees(Employee* this)
{
    Employee* emp;
    int len;
    len = ll_len(this);
    if(this != NULL )
    {
        for(int i=0; i<len;i++)
        {
            emp = (Employee*)ll_get(this, i);
            employee_showEmployee(emp);
        }
    }
    else
    {
        printf("No hay envios cargados\n\n");
        system("pause");
    }

}


int employee_sortByName(void* empleadoA, void* empleadoB)
{
    int ret;
    ret = strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre);
    return ret;
}


int employee_sortById(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id)
    {
        ret = 1;
    } if(((Employee*)empleadoA)->id < ((Employee*)empleadoB)->id)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;

}
/*
int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas)
    {
        ret = 1;
    }
    else if(((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int employee_sortBySueldo(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo)
    {
        ret = 1;
    }
    else if(((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int employee_loadSueldo(void* empleado)
{
    void* ret;
    int horasBajas;
    int horasMedias;
    int horasAltas;
    if(((Employee*)empleado)->horasTrabajadas <= 176)
    {
        horasBajas = ((Employee*)empleado)->horasTrabajadas * 180;
        ((Employee*)empleado)->sueldo = horasBajas;
    }
    else if(((Employee*)empleado)->horasTrabajadas >= 177)
    {
        horasBajas = 176 * 180;
        horasMedias = ((Employee*)empleado)->horasTrabajadas - 176;
        ((Employee*)empleado)->sueldo = (horasMedias * 270) + horasBajas;
    }
    else if(((Employee*)empleado)->horasTrabajadas >= 208)
    {
        horasBajas = 176 * 180;
        horasMedias = 32 * 270;
        horasMedias = ((Employee*)empleado)->horasTrabajadas - 208;
        ((Employee*)empleado)->sueldo = (horasMedias * 360) + horasBajas;
    }
    ret = ((Employee*)empleado)->sueldo;
    return ret;
}

*/
/*
void initEmployee(Employee* list, int len)
{
    for(int i = 0; i < len; i++)
    {
        list[i].isEmptyEmployee = 1;
    }
}
*/

