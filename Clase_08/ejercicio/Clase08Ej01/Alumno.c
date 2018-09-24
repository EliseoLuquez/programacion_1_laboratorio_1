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

int buscarLibre(sAlumno listado[], int tam)
{
    int i;
    int flag = -1;
    for(i = 0; i < tam; i++)
    {
        if(listado[i].estado==VACIO)
        {
           flag = i;
           break;
        }

    }
    return flag;
}
int cargarListadoDeAlumnos(sAlumno  listado[], int tam)
{
    int index;
    int flag = 0;
    index=buscarLibre(listado, tam);
    if(index!=-1)
    {
        listado[index]=pedirAlumno();
        listado[index].estado=OCUPADO;
    }
    return index;
}
 void mostrarListadoDeAlumnos(sAlumno listado[], int tam)
 {
    for(int i = 0; i < tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            mostrarUnAlumno(listado[i]);

        }
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



