#ifndef envio_H_INCLUDED
#define envio_H_INCLUDED
typedef struct
{
    int idEnvio;
    char nombreProd[50];
    int idCamion;
    char zonaDestino[50];
    float kmRecorrido;
    int tipoEntrega;
    float costoEnvio;

}Envio;

Envio* envio_new();


int envio_setIdEnvio(Envio* this, int idEnvio);
int envio_getIdEnvio(Envio* this,int* idEnvio);

int envio_setNombreProducto(Envio* this,char* nombreProducto);
int envio_getNombreProducto(Envio* this,char* nombreProducto);

int envio_setIdCamion(Envio* this,int idCamion);
int envio_getIdCamion(Envio* this,int* idCamion);

int envio_setZoanDestino(Envio* this,char* zonaDestino);
int envio_getZonaDestino(Envio* this,char* zonaDestino);

int envio_setKmRecorrido(Envio* this,float kmRecorrido);
int envio_getKmRecorrido(Envio* this,float* kmRecorrido);

int envio_setTipoEntrega(Envio* this,int tipoEntrega);
int envio_getTipoEntrega(Envio* this, int* tipoEntrega);

int envio_setCostoEnvio(Envio* this,float costoEnvio);
int envio_getCostoEnvio(Envio* this, float* costoEnvio);

void  envio_showEnvio(Envio* this);
void  envio_showEnvios(Envio* this);

float envio_loadCosto(void* envios);
int envio_zonas(void* envios, char* zona);


#endif // employee_H_INCLUDED

