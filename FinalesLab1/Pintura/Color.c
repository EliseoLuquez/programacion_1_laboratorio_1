#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Color.h"
#include "Componente.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** FUNCIONES COLOR  **/
/**
    int idColor;
    char nombre[50];
    int idComponente;
    int cantidad;
    **/

sColor* color_new()
{
    sColor* color = (sColor *) calloc ( 1 , sizeof (sColor));
    if(color == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return color;
}

int color_newParameteros(char* idColor, char* nombre, char* idComponente, char* cantidad)
{
    int idColorAux;
    int idCompAux;
    int cantAux;
    sColor* color = color_new();

    idColorAux = atoi(idColor);
    idCompAux = atoi(idComponente);
    cantAux = atoi(cantidad);

    color_setIdColor(color, idColorAux);
    color_setNombre(color, nombre);
    color_setIdComponente(color, idCompAux);
    color_setCantidad(color, cantAux);

    return color;
}

int color_setIdColor(sColor* this, int idColor)
{
    int ret;
    ret = RETURN_ERROR;

    if(idColor > 0 && this != NULL)
    {
        this->idColor = idColor;
        ret = RETURN_OK;
    }
    return ret;
}

int color_getIdColor(sColor* this, int* idColor)
{
    int ret;
    ret = RETURN_ERROR;

    if(idColor > 0 && this != NULL)
    {
        *idColor = this->idColor;
        ret = RETURN_OK;
    }
    return ret;
}

int color_setNombre(sColor* this, char* nombre)
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

char* color_getNombre(sColor* this)
{

    return this->nombre;
}

int color_setIdComponente(sColor* this, int componente)
{
    int ret;
    ret = RETURN_ERROR;

    if(componente > 0 && this != NULL)
    {
        this->idComponente = componente;
        ret = RETURN_OK;
    }
    return ret;
}

int color_getIdComponente(sColor* this, int* componente)
{
    int ret;
    ret = RETURN_ERROR;

    if(componente > 0 && this != NULL)
    {
        *componente = this->idComponente;
        ret = RETURN_OK;
    }
    return ret;
}

int color_setCantidad(sColor* this, int cantidad)
{
    int ret;
    ret = RETURN_ERROR;

    if(cantidad > 0 && this != NULL)
    {
        this->cantidad = cantidad;
        ret = RETURN_OK;
    }
    return ret;
}

int color_getCantidad(sColor* this, int* cantidad)
{
    int ret;
    ret = RETURN_ERROR;

    if(cantidad > 0 && this != NULL)
    {
        *cantidad = this->cantidad;
        ret = RETURN_OK;
    }
    return ret;
}

void  color_showColor(sColor* this)
{
    if(this != NULL )
    {
        printf ("%d  %s  %d  %d \n\n" , this->idColor, this->nombre, this->idComponente, this->cantidad);
    }
}

void  color_showColores(sColor* this)
{
    sColor* pColor;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            pColor = (sColor*)ll_get(this, i);
            color_showColor(pColor);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

}

/** Componente **/

sComponente* componente_new()
{
    sComponente* componente = (sComponente *) calloc ( 1 , sizeof (sComponente));
    if(componente == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return componente;
}

int componente_newParameteros(char* componenteId, char* nombre, char* base)
{
    int compIdAux;
    compIdAux = atoi(componenteId);
    sComponente* componente = componente_new();
    componente_setComponenteId(componente, compIdAux);
    componente_setNombre(componente, nombre);
    componente_setBase(componente, base);

    return componente;
}
/**
    int  componenteId;
    char nombre[50];
    char base[50];
    **/

int componente_setComponenteId(sComponente* this, int componenteId)
{
    int ret;
    ret = RETURN_ERROR;

    if(componenteId > 0 && this != NULL)
    {
        this->componenteId = componenteId;
        ret = RETURN_OK;
    }
    return ret;
}

int componente_getComponenteId(sComponente* this, int* componenteId)
{
    int ret;
    ret = RETURN_ERROR;

    if(componenteId > 0 && this != NULL)
    {
        *componenteId = this->componenteId;
        ret = RETURN_OK;
    }
    return ret;
}

int componente_setNombre(sComponente* this, char* nombre)
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

char* componente_getNombre(sComponente* this)
{

    return this->nombre;
}


int componente_setBase(sComponente* this, char* base)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->base,base);
        ret = RETURN_OK;
    }

    return ret;
}

char* componente_getBase(sComponente* this)
{

    return this->base;
}

void  componente_showComponente(sComponente* this)
{
    if(this != NULL )
    {
        printf ("%d  %s  %s \n\n" , this->componenteId , this->nombre , this->base);
    }
}

void  componente_showComponentes(sComponente* this)
{
    sComponente* pComp;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            pComp = (sComponente*)ll_get(this, i);
            componente_showComponente(pComp);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

}
/**
int componente_findCompById(sComponente* this, int len, int id)
{
    int r = RETURN_ERROR;

    if(this != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if((this != NULL)&&(this->componenteId == id))
            {
                r = i; // LE ASIGNO LA POSICION  ENCONTRADA Y SALGO
                break;
            }
        }
        r = RETURN_OK;
    }
    else
    {
        printf("No hay datos");
    }
    return r;
}
**/
