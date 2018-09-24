#ifndef ALUMNO_H_INCLUDE
#define ALUMNO_H_INCLUDE
#define VACIO 0
#define OCUPADO 1
#endif // ALUMNO_H_INCLUDE

typedef struct
{
    int legajo;
    char nombre[30];
    float promedio;
    int edad;
    int estado;
}sAlumno;

void mostrarUnAlumno(miAlumno);
sAlumno pedirAlumno();
/** \brief
 * \param
 * \param
 * \return -1 si no hay lugar
 *
 */

int cargarListadoDeAlumnos(sAlumno[], int tam);

void mostrarListadoDeAlumnos(sAlumno[], int tam);
int buscarLibre(sAlumno[], int tam);
