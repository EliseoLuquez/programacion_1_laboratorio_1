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
        ret = this->dni;
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
        printf("%d  %15s  %s  %d   %s\n\n " , employee_getId(this), employee_getNombre(this),
                 employee_getApellido(this), employee_getDni(this), employee_getClave(this));
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

/** FICHAJES Y FECHA **/
/** FUNCIONES FECHA  **/
sFecha* fecha_new()
{
    sFecha* fecha = (sFecha *) calloc ( 1 , sizeof (sFecha));
    if(fecha == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return fecha;
}

int fecha_newParameteros(int hora, int minutos, int dia, int mes, int anio)
{
    sFecha* fecha = fecha_new();
    fecha_setHora(fecha, hora);
    fecha_setMinutos(fecha, minutos);
    fecha_setDia(fecha, dia);
    fecha_setMes(fecha, mes);
    fecha_setAnio(fecha, anio);
    return fecha;
}

int fecha_setHora(sFecha* this, int hora)
{
    int ret;
    ret = RETURN_ERROR;

    if(hora > 0 && this != NULL)
    {
        this->hora = hora;
        ret = RETURN_OK;
    }
    return ret;
}

int fecha_getHora(sFecha* this)
{
    return this->hora;
}

int fecha_setMinutos(sFecha* this, int minutos)
{
    int ret;
    ret = RETURN_ERROR;

    if(minutos > 0 && this != NULL)
    {
        this->minutos = minutos;
        ret = RETURN_OK;
    }
    return ret;
}

int fecha_getMinutos(sFecha* this)
{
    return this->minutos;
}

int fecha_setDia(sFecha* this, int dia)
{
    int ret;
    ret = RETURN_ERROR;

    if(dia > 0 && this != NULL)
    {
        this->dia = dia;
        ret = RETURN_OK;
    }
    return ret;
}

int fecha_getDia(sFecha* this)
{
    return this->dia;
}

int fecha_setMes(sFecha* this, int mes)
{
    int ret;
    ret = RETURN_ERROR;

    if(mes > 0 && this != NULL)
    {
        this->mes = mes;
        ret = RETURN_OK;
    }
    return ret;
}

int fecha_getMes(sFecha* this)
{
    return this->mes;
}

int fecha_setAnio(sFecha* this, int anio)
{
    int ret;
    ret = RETURN_ERROR;

    if(anio > 0 && this != NULL)
    {
        this->anio = anio;
        ret = RETURN_OK;
    }
    return ret;
}

int fecha_getAnio(sFecha* this)
{
    return this->anio;
}
/** FUNCIONES FICHAJE  **/
sFichaje* fichaje_new()
{
    sFichaje* fich = (sFichaje *) calloc ( 1 , sizeof (sFichaje));
    if(fich == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return fich;
}


sFichaje* fichaje_newParametros(char* idFichajeStr, char* idEmployeeStr, char* inOut, sFecha* fecha)
{
    sFichaje* pFich = fichaje_new();
    int idFich;
    int idEmp;
    idFich = atoi(idFichajeStr);
    idEmp = atoi(idEmployeeStr);
    fichaje_setIdFichaje(pFich, idFich);
    fichaje_setIdEmployee(pFich, idEmp);
    fichaje_setInOut(pFich, inOut);
    fecha_newParameteros(&fecha->hora, &fecha->minutos, &fecha->dia, &fecha->mes, &fecha->anio);



    return pFich;
}

int fichaje_setIdFichaje(sFichaje* this, int idFichaje)
{
    int ret;
    ret = RETURN_ERROR;

    if(idFichaje > 0 && this != NULL)
    {
        this->idFichaje = idFichaje;
        ret = RETURN_OK;
    }
    return ret;
}

int fichaje_getIdFichaje(sFichaje* this, int* idFichaje)
{
    int ret;
    ret = RETURN_ERROR;

    if(idFichaje > 0 && this != NULL)
    {
        *idFichaje = this->idFichaje;
        ret = RETURN_OK;
    }
    return ret;
}

int fichaje_getIdFichajes(sFichaje* this)
{
    return this->idFichaje;
}

int fichaje_setIdEmployee(sFichaje* this, int idEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    if(idEmployee > 0 && this != NULL)
    {
        this->idEmployee = idEmployee;
        ret = RETURN_OK;
    }
    return ret;
}

int fichaje_getIdEmployee(sFichaje* this, int* idEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    if(idEmployee > 0 && this != NULL)
    {
        *idEmployee = this->idEmployee;
        ret = RETURN_OK;
    }
    return ret;
}

int fichaje_getIdEmpployees(sFichaje* this)
{
    return this->idEmployee;
}


int fichaje_setInOut(sFichaje* this, char* inOut)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->inOut, inOut);
        ret = RETURN_OK;
    }

    return ret;
}

char* fichaje_getInOut(sFichaje* this)
{
    return this->inOut;
}

void  fichaje_showFichaje(sFichaje* this)
{
    if(this != NULL )
    {
        printf("%d %d %d %d %2d %2d %4d %s\n\n " , fichaje_getIdFichajes(this), fichaje_getIdEmpployees(this),
                fecha_getHora(this), fecha_getMinutos(this), fecha_getDia(this), fecha_getMes(this),
               fecha_getAnio(this), fichaje_getInOut(this));
    }
}

void  fichaje_showFichajes(sFichaje* this)
{
    sFichaje* pFich;
    int len;
    len = ll_len(this);
    if(this != NULL )
    {
        for(int i=0; i<len;i++)
        {
            pFich = (sFichaje*)ll_get(this, i);
            fichaje_showFichaje(pFich);
        }
    }
    else
    {
        printf("No hay envios cargados\n\n");
        system("pause");
    }

}

