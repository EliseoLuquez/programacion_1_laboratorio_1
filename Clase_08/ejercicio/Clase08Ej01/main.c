#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include <string.h>
#define A 3



int main()
{
    sAlumno listadoMain[A];
    cargarListadoDeAlumnos(listadoMain, A);
    mostrarListadoDeAlumnos(listadoMain, A);
    printf("\nOrdenar\n");
    ordenarListadoDeAlumnoPorNombre(listadoMain, A);
    mostrarListadoDeAlumnos(listadoMain, A);


    return 0;
}
