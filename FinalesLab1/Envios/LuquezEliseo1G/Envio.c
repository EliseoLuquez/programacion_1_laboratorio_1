#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Envio.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


Envio* envio_new()/**  **/
{
   //env = (Envio*)malloc(sizeof(Envio));
    Envio* env = (Envio *) calloc ( 1 , sizeof (Envio));
    if(env == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }
   /* env->idEnvio = 0;
    strcpy(env->nombreProd, "");
    env->idCamion = 0;
    strcpy(env->zonaDestino, "");
    env->kmRecorrido = 0;
    env->tipoEntrega = 0;
    env->costoEnvio = 0;*/

    return env;
}

Envio* envio_newParametros(char* idEnvioStr, char* nombreProdStr, char* idCamionStr, char* zonaDestStr, char* kmRecorridoStr, char* tipoEntregaStr)
{
    Envio* env = envio_new();
    float kmRecAux;
    kmRecAux = atof(kmRecorridoStr);
    envio_setIdEnvio(env, atoi(idEnvioStr));
    envio_setNombreProducto(env, nombreProdStr);
    envio_setIdCamion(env, atoi(idCamionStr));
    envio_setZoanDestino(env, zonaDestStr);
    envio_setKmRecorrido(env, kmRecAux);
    envio_setTipoEntrega(env, atoi(tipoEntregaStr));
    //envio_setCostoEnvio(env, atof(costoEnvioStr));

    return env;
}



int envio_setIdEnvio(Envio* this, int idEnvio)
{
    int ret;
    ret = RETURN_ERROR;

    if(idEnvio > 0 && this != NULL)
    {
        this->idEnvio = idEnvio;
        ret = RETURN_OK;
    }
    return ret;
}
int envio_getIdEnvio(Envio* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->idEnvio;;
    }

    return ret;
}

int envio_setNombreProducto(Envio* this,char* nombreProducto)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->nombreProd,nombreProducto);
        ret = RETURN_OK;
    }

    return ret;
}

char* envio_getNombreProducto(Envio* this)
{
    return this->nombreProd;
}

int envio_setIdCamion(Envio* this,int idCamion)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->idCamion = idCamion;
        ret = RETURN_OK;
    }

    return ret;
}

int envio_getIdCamion(Envio* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->idCamion;;
    }

    return ret;
}

int envio_setZoanDestino(Envio* this,char* zonaDestino)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->zonaDestino, zonaDestino);
        ret = RETURN_OK;
    }

    return ret;
}

char* envio_getZonaDestino(Envio* this)
{
    return this->zonaDestino;
}


int envio_setKmRecorrido(Envio* this,float kmRecorrido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->kmRecorrido = kmRecorrido;
        ret = RETURN_OK;
    }

    return ret;
}
float envio_getKmRecorrido(Envio* this)
{
    float ret;
    if(this != NULL)
    {
        ret = this->kmRecorrido;;
    }

    return ret;
}

int envio_setTipoEntrega(Envio* this,int tipoEntrega)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->tipoEntrega = tipoEntrega;
        ret = RETURN_OK;
    }

    return ret;
}
int envio_getTipoEntrega(Envio* this)
{
    int ret;
    if(this != NULL)
    {

        ret = this->tipoEntrega;;
    }

    return ret;
}

int envio_setCostoEnvio(Envio* this,float costoEnvio)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->costoEnvio = costoEnvio;
        ret = RETURN_OK;
    }

    return ret;
}
float envio_getCostoEnvio(Envio* this)
{
    float ret;
    if(this != NULL)
    {
       ret = this->costoEnvio;
    }
    return ret;
}

void  envio_showEnvio(Envio* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %10s  %4d  %10s   %.2f   %2d  %.2f \n\n " , envio_getIdEnvio(this), envio_getNombreProducto(this), envio_getIdCamion(this),
                 envio_getZonaDestino(this), envio_getKmRecorrido(this), envio_getTipoEntrega(this), envio_getCostoEnvio(this));
    }
}

void  envio_showEnvios(Envio* this)
{
    Envio* env;
    int len;
    len = ll_len(this);
    if(this != NULL )
    {
        for(int i=0; i<len;i++)
        {
            env = (Envio*)ll_get(this, i);
            envio_showEnvio(env);
        }
    }
    else
    {
        printf("No hay envios cargados\n\n");
        system("pause");
    }

}
/*int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),employee_getHorasTrabajadas(lista),employee_getSueldo(lista));
    }
    return 1;
}*/
/*
int vendedor_sortByName(void* empleadoA, void* empleadoB)
{
    int ret;
    ret = strcmp(((Envio*)empleadoA)->nombre, ((Envio*)empleadoB)->nombre);
    return ret;
}


int vendedor_sortById(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Envio*)empleadoA)->id > ((Envio*)empleadoB)->id)
    {
        ret = 1;
    } if(((Envio*)empleadoA)->id < ((Envio*)empleadoB)->id)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;

}

int vendedor_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Envio*)empleadoA)->cantProdVend > ((Envio*)empleadoB)->cantProdVend)
    {
        ret = 1;
    }
    else if(((Envio*)empleadoA)->cantProdVend < ((Envio*)empleadoB)->cantProdVend)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int vendedor_sortBySueldo(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Envio*)empleadoA)->nivel > ((Envio*)empleadoB)->nivel)
    {
        ret = 1;
    }
    else if(((Envio*)empleadoA)->nivel < ((Envio*)empleadoB)->nivel)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
*/

float envio_loadCosto(void* envios)
{
    float ret;
    float valor;


    if(((Envio*)envios)->kmRecorrido < 50)
    {
        valor = ((Envio*)envios)->kmRecorrido * 100;

        if(((Envio*)envios)->tipoEntrega == 0)
        {
            valor = valor + 250;
        }
        else if(((Envio*)envios)->tipoEntrega == 1)
        {
            valor = valor + 420;
        }
        else if(((Envio*)envios)->tipoEntrega == 2)
        {
            valor = valor + 75;
        }
    }
    else
    {
        valor = ((Envio*)envios)->kmRecorrido * 50;

        if(((Envio*)envios)->tipoEntrega == 0)
        {
            valor = valor + 250;
        }
        else if(((Envio*)envios)->tipoEntrega == 1)
        {
            valor = valor + 420;
        }
        else if(((Envio*)envios)->tipoEntrega == 2)
        {
            valor = valor + 75;
        }
    }
    ((Envio*)envios)->costoEnvio = valor;
    ret = ((Envio*)envios)->costoEnvio;
    return ret;
}




int envio_zonas(void* envios, char* zona)
{
    int retAux = 2;
    void* filterZona;
    if(strcmp(((Envio*)envios)->zonaDestino, zona )== 0)
    {
        filterZona = ((Envio*)envios);
        retAux = 0;
    }

    return retAux;
}




