#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"


void mostrarUnAlumno(sAlumno miAlumno)
{
    printf("\n%d  \n%s \n%f  \n%d",miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.edad);
}

sAlumno pedirAlumno()
{
    sAlumno alumnito;
    printf("Ingrese legajo: ");
    scanf("%d",&alumnito.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(alumnito.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &alumnito.promedio);
    printf("Ingrese edad: ");
    scanf("%d", &alumnito.edad);


   return alumnito;
}

void cargarListadoDeAlumnos(sAlumno  listado[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        listado[i]=pedirAlumno();
    }
}
 void mostrarListadoDeAlumnos(sAlumno listado[], int tam)
 {
    for(int i = 0; i < tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }
 }

 void ordenarListadoDeAlumnoPorNombre(sAlumno listado[], int tam)
 {
      sAlumno auxAlumno;
     // int auxInt; NO HACER ASI
     //float auxFloat; NO HACER ASI
     //char auxString[50]; NO HACER ASI
     int i;
     int j;
     for(i = 0; i < tam; i++)
     {
         for(j = i + 1; j < tam; j++)
         {
             if(strcmp(listado[i].nombre, listado[j].nombre)<0)
                {
                  auxAlumno = listado[i];
                  listado[i] = listado[j];
                  listado[j] = auxAlumno;
                   /*
                    NO HACER DE ESTA FORMA
                   auxInt = listado[i].legajo;
                    listado[i].legajo = listado[j].legajo;
                    listado[j].legajo = auxInt;*/
                }
         }
     }

 }

