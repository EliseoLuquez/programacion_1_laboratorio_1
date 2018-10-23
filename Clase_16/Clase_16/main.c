#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 typedef struct{

    int codigo;
    char marca[20];
    int capacidad;
    float precio;

 }sPendrive;

int cargarPendrive(sPendrive* pen);
int mostrarPendrive(sPendrive* pen);
sPendrive* new_pendrive();
sPendrive* new_pendriveParam(int codigo, char* marca, int capacidad, float precio);

int main()
{
   /** sPendrive miPendrive;
    sPendrive* peni = new_pendrive();

    if(cargarPendrive(miPendrive))
    {
        mostrarPendrive(miPendrive);
    }
    else
    {
        printf("no anda");
    }
    **/


    sPendrive* pen1, pen2;

    pen1 = new_pendriveParam(1234, "Kingston", 32, 560);
   // pen2 = new_pendrive();

    mostrarPendrive(pen1);
    //mostrarPendrive(pen2);

    free(pen1);
//    free(pen2);
    return 0;
}

int cargarPendrive(sPendrive* pen)
{
    if(pen != NULL)
    {
        sPendrive* nuevoPen;

        printf("Ingrese codigo: ");
        scanf("%d", &nuevoPen->codigo);
        printf("Ingrese marca: ");
        fflush(stdin);
        gets(nuevoPen->marca);
        printf("Ingrese capacidad: ");
        scanf("%d", &nuevoPen->capacidad);
        printf("Ingrese precio: ");
        scanf("%f", &nuevoPen->capacidad);
    }
    else
    {
        printf("No se encontro espacio en el array");
    }
}
int mostrarPendrive(sPendrive* pen)
{
    int todoOk = 0;
    if(pen != NULL)
    {
        printf("%d %s %d %f", pen->codigo, pen->marca, pen->capacidad, pen->precio);
        todoOk = 1;
    }
}
sPendrive* new_pendrive()
{
    sPendrive* p;

    p = (sPendrive*) malloc(sizeof(sPendrive));

    if( p != NULL)
    {
        p->codigo = 0;
        strcpy(p->marca, "");
        p->capacidad = 0;

    }
    return p;
}

sPendrive* new_pendriveParam(int codigo, char* marca, int capacidad, float precio)
{
    sPendrive* p;

    p = (sPendrive*) malloc(sizeof(sPendrive));

    if( p != NULL & marca != NULL)
    {
        p->codigo = codigo;
        strcpy(p->marca, marca);
        p->capacidad = capacidad;
        p->precio = precio;

    }
    return p;
}
