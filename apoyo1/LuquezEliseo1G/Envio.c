#include <stdio.h>
#include "Envio.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


Envio* envio_new()/**  **/
{
    Envio* env;
    env = (Envio*)malloc(sizeof(Envio));
    env->idEnvio = 0;
    strcpy(env->nombreProd, "");
    env->idCamion = 0;
    strcpy(env->zonaDestino, "");
    env->kmRecorrido = 0;
    env->tipoEntrega = 0;
    env->costoEnvio = 0;

    return env;
}

/*
Envio* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Envio* env;
    env = (Envio*)malloc(sizeof(Envio));
    env->id = idStr;
    strcpy(env->nombre, nombreStr);
    env->horasTrabajadas = horasTrabajadasStr;
    env->sueldo = 0;

    return env;
}
*/


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
int envio_getIdEnvio(Envio* this,int* idEnvio)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *idEnvio = this->idEnvio;
        ret = RETURN_OK;
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

int envio_getNombreProducto(Envio* this,char* nombreProducto)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(nombreProducto,this->nombreProd);
        ret = RETURN_OK;
    }

    return ret;
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

int envio_getIdCamion(Envio* this,int* idCamion)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *idCamion = this->idCamion;
        ret = RETURN_OK;
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

int envio_getZonaDestino(Envio* this,char* zonaDestino)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(zonaDestino,this->zonaDestino);
        ret = RETURN_OK;
    }

    return ret;
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
int envio_getKmRecorrido(Envio* this,float* kmRecorrido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *kmRecorrido = this->kmRecorrido;
        ret = RETURN_OK;
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
int envio_getTipoEntrega(Envio* this, int* tipoEntrega)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *tipoEntrega = this->tipoEntrega;
        ret = RETURN_OK;
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
int envio_getCostoEnvio(Envio* this, float* costoEnvio)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *costoEnvio = this->costoEnvio;
        ret = RETURN_OK;
    }

    return ret;
}

void  envio_showEnvio(Envio* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %10s  %4d  %10s   %.2f   %2d  %.2f \n\n " , this->idEnvio , this->nombreProd ,this->idCamion, this->zonaDestino, this->kmRecorrido, this->tipoEntrega, this->costoEnvio);
    }
}

void  envio_showEnvios(Envio* this)
{
    Envio* env;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
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




