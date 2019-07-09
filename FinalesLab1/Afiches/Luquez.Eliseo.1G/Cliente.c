#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cliente.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/**  Cliente Funciones **/
sCliente* cliente_new()
{
    sCliente* pCliente = (sCliente *) calloc ( 1 , sizeof (sCliente));
    if(pCliente == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return pCliente;
}


sCliente* cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* cuitStr)
{
    sCliente* pCliente = cliente_new();
    cliente_setId(pCliente, atoi(idStr));
    cliente_setNombre(pCliente, nombreStr);
    cliente_setApellido(pCliente, apellidoStr);
    cliente_setCuit(pCliente, cuitStr);


    return pCliente;
}

int cliente_setId(sCliente* this,int id)
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
int cliente_getId(sCliente* this)
{
    return this->id;
}

int cliente_setNombre(sCliente* this,char* nombre)
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

int cliente_getNombre(sCliente* this,char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        ret = RETURN_OK;
    }

    return ret;
}

int cliente_setApellido(sCliente* this,char* apellido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->apellido ,apellido );
        ret = RETURN_OK;
    }

    return ret;
}

int cliente_getApellido(sCliente* this,char* apellido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(apellido ,this->apellido );
        ret = RETURN_OK;
    }

    return ret;
}


int cliente_setCuit(sCliente* this, char* cuit)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->cuit,cuit);
        ret = RETURN_OK;
    }

    return ret;
}

int cliente_getCuit(sCliente* this,char* cuit)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(cuit,this->cuit);
        ret = RETURN_OK;
    }

    return ret;
}




void  cliente_showCliente(sCliente* this)
{
    if(this != NULL )
    {
        printf ("%4d  %s  %s  %s \n\n " , (sCliente*)this->id , (sCliente*)this->nombre , (sCliente*)this->apellido , (sCliente*)this->cuit);
    }
}

void  cliente_showClientes(sCliente* this)
{
    sCliente* pCliente;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            pCliente = (sCliente*)ll_get(this, i);
            cliente_showCliente(pCliente);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

}
/*
int employee_sortByName(void* empleadoA, void* empleadoB)
{
    int ret;
    ret = strcmp(((sCliente*)empleadoA)->nombre, ((sCliente*)empleadoB)->nombre);
    return ret;
}


int employee_sortById(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((sCliente*)empleadoA)->id > ((sCliente*)empleadoB)->id)
    {
        ret = 1;
    } if(((sCliente*)empleadoA)->id < ((sCliente*)empleadoB)->id)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;

}

int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((sCliente*)empleadoA)->horasTrabajadas > ((sCliente*)empleadoB)->horasTrabajadas)
    {
        ret = 1;
    }
    else if(((sCliente*)empleadoA)->horasTrabajadas < ((sCliente*)empleadoB)->horasTrabajadas)
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
    if(((sCliente*)empleadoA)->sueldo > ((sCliente*)empleadoB)->sueldo)
    {
        ret = 1;
    }
    else if(((sCliente*)empleadoA)->sueldo < ((sCliente*)empleadoB)->sueldo)
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
    if(((sCliente*)empleado)->horasTrabajadas <= 176)
    {
        horasBajas = ((sCliente*)empleado)->horasTrabajadas * 180;
        ((sCliente*)empleado)->sueldo = horasBajas;
    }
    else if(((sCliente*)empleado)->horasTrabajadas >= 177)
    {
        horasBajas = 176 * 180;
        horasMedias = ((sCliente*)empleado)->horasTrabajadas - 176;
        ((sCliente*)empleado)->sueldo = (horasMedias * 270) + horasBajas;
    }
    else if(((sCliente*)empleado)->horasTrabajadas >= 208)
    {
        horasBajas = 176 * 180;
        horasMedias = 32 * 270;
        horasMedias = ((sCliente*)empleado)->horasTrabajadas - 208;
        ((sCliente*)empleado)->sueldo = (horasMedias * 360) + horasBajas;
    }
    ret = ((sCliente*)empleado)->sueldo;
    return ret;
}
*/
/**  Venta Funciones **/

sVenta* venta_new()
{
    sVenta* pVenta = (sVenta *) calloc ( 1 , sizeof (sVenta));
    if(pVenta == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return pVenta;
}


sVenta* venta_newParametros(char* idVentaStr, char* idClienteStr,char* cantAficheStr ,char* nombreImgStr, char* zonaStr, char* estadoStr)
{
    sVenta* pVenta = cliente_new();
    venta_setIdVenta(pVenta, atoi(idVentaStr));
    venta_setIdCliente(pVenta, atoi(idClienteStr));
    venta_setCantAfiches(pVenta, atoi(cantAficheStr));
    venta_setNombreArchImg(pVenta, nombreImgStr);
    venta_setZona(pVenta, zonaStr);
    venta_setEstado(pVenta, estadoStr);
    return pVenta;
}

int venta_setIdVenta(sVenta* this,int idVenta)
{
    int ret;
    ret = RETURN_ERROR;

    if(idVenta > 0 && this != NULL)
    {
        this->idVenta = idVenta;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getIdVenta(sVenta* this)
{
    return this->idVenta;
}

int venta_setIdCliente(sVenta* this,int idCliente)
{
    int ret;
    ret = RETURN_ERROR;

    if(idCliente > 0 && this != NULL)
    {
        this->idCliente = idCliente;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getIdCliente(sVenta* this)
{
    return this->idCliente;
}

int venta_setCantAfiches(sVenta* this,int cantAfiches)
{
    int ret;
    ret = RETURN_ERROR;

    if(cantAfiches > 0 && this != NULL)
    {
        this->cantAfiches = cantAfiches;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getCantAfiches(sVenta* this)
{
    return this->cantAfiches;
}

int venta_setNombreArchImg(sVenta* this,char* nombreArchImg)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->nombreArchImg,nombreArchImg);
        ret = RETURN_OK;
    }

    return ret;
}

int venta_getNombreArchImg(sVenta* this,char* nombreArchImg)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(nombreArchImg,this->nombreArchImg);
        ret = RETURN_OK;
    }

    return ret;
}

int venta_setZona(sVenta* this,char* zona)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->zona ,zona );
        ret = RETURN_OK;
    }

    return ret;
}

int venta_getZona(sVenta* this,char* zona)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(zona ,this->zona );
        ret = RETURN_OK;
    }

    return ret;
}


int venta_setEstado(sVenta* this,char* estado)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->estado ,estado );
        ret = RETURN_OK;
    }

    return ret;
}

int venta_getEstado(sVenta* this,char* estado)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(estado ,this->estado );
        ret = RETURN_OK;
    }

    return ret;
}



void  venta_showVenta(sVenta* this)
{
    if(this != NULL )
    {
        printf ("%d  %4d  %4d  %10s  %10s  %10s\n", (sVenta*)this->idVenta ,(sVenta*)this->idCliente , (sVenta*)this->cantAfiches , (sVenta*)this->nombreArchImg,
                (sVenta*)this->zona, (sVenta*)this->estado);
    }
}

void  venta_showVentas(sVenta* this)
{
    sVenta* pVenta;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            pVenta = (sVenta*)ll_get(this, i);
            venta_showVenta(pVenta);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

}

