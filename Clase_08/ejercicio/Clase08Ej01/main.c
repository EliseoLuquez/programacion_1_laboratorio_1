#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include <string.h>
#define A 3
#define VACIO 0
#define OCUPADO 1




int main()
{
    sAlumno listadoMain[A];
    int opcion;
    int i;
    int auxleg;
    for(i=0;i<A;i++)
    {
        listadoMain[i].estado=VACIO;
    }
    do{
        printf("1. Alta\n2. Modificar\n3. Mostrar\n4. Salir\nElija");
        scanf("%d", opcion);
        switch(opcion){
            case 1:
                    cargarListadoDeAlumnos(listadoMain, A);
                    if(i!=-1)
                    {
                        printf("Carga exitosa");
                    }
                    else
                    {
                        printf("No hay espacio");
                    }
                    break;
            case 2:
                    printf("Ingrese legajo: ");
                    scanf("%d", &auxleg);
                    for(i=0;i<A;i++)
                    {
                        if(auxleg==listadoMain[i].legajo&&alistadoMain[i].legajo==OCUPADO)
                        {
                            printf("ingrese nuevo promedio: ");
                            scanf("%f", &listadoMain[i].promedio);
                            break;
                        }
                    }

                    break;
            case 3:
                    mostrarListadoDeAlumnos(listadoMain, A);
                    break;
                }



    }
    cargarListadoDeAlumnos(listadoMain, A);
    mostrarListadoDeAlumnos(listadoMain, A);
    printf("\nOrdenar\n");
    ordenarListadoDeAlumnoPorNombre(listadoMain, A);
    mostrarListadoDeAlumnos(listadoMain, A);


    return 0;
}
