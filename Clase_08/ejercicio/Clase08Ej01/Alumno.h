#ifndef ALUMNO_H_INCLUDE
#define ALUMNO_H_INCLUDE
#endif // ALUMNO_H_INCLUDE
typedef struct
{
    int legajo;
    char nombre[30];
    float promedio;
    int edad;
}sAlumno;

void mostrarUnAlumno(miAlumno);
sAlumno pedirAlumno();
void cargarListadoDeAlumnos(sAlumno[], int tam);
void mostrarListadoDeAlumnos(sAlumno[], int tam);
