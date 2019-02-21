#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


Usuario* usuario_new()/** parametros **/
{
    Usuario* usrio;
    usrio = (Usuario*)malloc(sizeof(Usuario));
    usrio->id = 0;
    strcpy(usrio->nombre, "");
    strcpy(usrio->email, "");
    strcpy(usrio->sexo, "");
    strcpy(usrio->pais, "");
    strcpy(usrio->password, "");
    strcpy(usrio->ip_Address, "");

    return usrio;
}


Usuario* usuario_newParametros(char* idStr, char* nombreStr, char* emailStr, char* sexoStr, char* paisStr, char* passwordStr,
                                char* ip_AddressStr)
{
    Usuario* usrio = usuario_new();
    int retAux = 0;

    if(usuario_setId(usrio, atoi(idStr))){
        if(usuario_setNombre(usrio, nombreStr)){
            if(usuario_setEmail(usrio, emailStr)){
                if(usuario_setSexo(usrio, sexoStr)){
                    if(usuario_setPais(usrio, paisStr)){
                        if(usuario_setPassword(usrio, passwordStr)){
                            if(usuario_setIp_Address(usrio, ip_AddressStr))
                            {
                                retAux = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if(retAux == 0)
    {
        usrio = NULL;
    }


    return usrio;
}

/** Getters y Setters **/

int usuario_setId(Usuario* this, int id)
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
int usuario_getId(Usuario* this, int* id)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *id = this->id;
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_setNombre(Usuario* this, char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_getNombre(Usuario* this, char* nombre)
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

int usuario_setEmail(Usuario* this, char* email)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->email,email);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_getEmail(Usuario* this, char* email)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(email, this->email);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_setSexo(Usuario* this, char* sexo)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->sexo, sexo);
        ret = RETURN_OK;
    }

    return ret;
}
int usuario_getSexo(Usuario* this, char* sexo)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(sexo, this->sexo);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_setPais(Usuario* this, char* pais)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->pais,pais);
       ret = RETURN_OK;
    }

    return ret;
}
int usuario_getPais(Usuario* this, char* pais)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(pais, this->pais);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_setPassword(Usuario* this, char* password)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->password,password);;
       ret = RETURN_OK;
    }

    return ret;
}
int usuario_getPassword(Usuario* this, char* password)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(password, this->password);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_setIp_Address(Usuario* this, char* ip_Address)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->ip_Address,ip_Address);
        ret = RETURN_OK;
    }

    return ret;
}

int usuario_getIp_Address(Usuario* this, char* ip_Address)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(ip_Address, this->ip_Address);
        ret = RETURN_OK;
    }

    return ret;
}

/** Ordenamientos y demas **/


void  usuario_showUsuario(Usuario* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %s  %s  %s   %s   %s   %s \n\n " , this->id , this->nombre ,this->email, this->sexo, this->pais,
                 this->password, this->ip_Address);
    }
}

void  usuario_showUsuarios(Usuario* this)
{
    Usuario* usrio;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            usrio = (Usuario*)ll_get(this, i);
            usuario_showUsuario(usrio);
        }
    }
    else
    {
        printf("No hay usuarios cargados\n\n");
        system("pause");
    }

}

int usuario_sortByName(void* usuarioA, void* usuarioB)
{
    int ret;
    ret = strcmp(((Usuario*)usuarioA)->nombre, ((Usuario*)usuarioB)->nombre);
    if(ret == 0)
    {
        strcmp(((Usuario*)usuarioA)->sexo, ((Usuario*)usuarioB)->sexo);
    }
    return ret;
}

int usuario_sortByNaciName(void* usuarioA, void* usuarioB)
{
    int ret;
    ret = strcmp(((Usuario*)usuarioA)->pais, ((Usuario*)usuarioB)->pais);
    if(ret == 0)
    {
        strcmp(((Usuario*)usuarioA)->nombre, ((Usuario*)usuarioB)->nombre);
    }

    return ret;
}
/*

int vendedor_sortById(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Usuario*)empleadoA)->id > ((Usuario*)empleadoB)->id)
    {
        ret = 1;
    } if(((Usuario*)empleadoA)->id < ((Usuario*)empleadoB)->id)
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
    if(((Usuario*)empleadoA)->email > ((Usuario*)empleadoB)->email)
    {
        ret = 1;
    }
    else if(((Usuario*)empleadoA)->email < ((Usuario*)empleadoB)->email)
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
    if(((Usuario*)empleadoA)->nivel > ((Usuario*)empleadoB)->nivel)
    {
        ret = 1;
    }
    else if(((Usuario*)empleadoA)->nivel < ((Usuario*)empleadoB)->nivel)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

float vendedor_loadSueldo(void* vendedor)
{
    float ret;
    float porcentaje;


    if(((Usuario*)vendedor)->nivel == 0)
    {
        porcentaje = ((Usuario*)vendedor)->montoVendido * 0.2;
        ((Usuario*)vendedor)->comision = porcentaje ;
    }
    else if(((Usuario*)vendedor)->nivel >= 1)
    {
        if(((Usuario*)vendedor)->email < 100)
        {
            porcentaje = ((Usuario*)vendedor)->montoVendido * 0.035;
            ((Usuario*)vendedor)->comision = porcentaje ;
        }
        else if(((Usuario*)vendedor)->email >= 100)
        {
            porcentaje = ((Usuario*)vendedor)->montoVendido * 0.05;
            ((Usuario*)vendedor)->comision = porcentaje ;
        }
    }
    ret = ((Usuario*)vendedor)->comision;
    return ret;
}


int vendedor_niveles(void* vendedor, int* nivel)
{
    int retAux = -1;
    void* filter;
    if(((Usuario*)vendedor)->nivel == 0 && nivel == 0)
    {
        filter = ((Usuario*)vendedor);
        retAux = 0;
    }
    else if(((Usuario*)vendedor)->nivel == 1 && nivel == 1)
    {
        filter = ((Usuario*)vendedor);
        retAux = 1;
    }
    else if(((Usuario*)vendedor)->nivel == 2 && nivel == 2)
    {
        filter = ((Usuario*)vendedor);
        retAux = 2;
    }
    return retAux;
}
*/






