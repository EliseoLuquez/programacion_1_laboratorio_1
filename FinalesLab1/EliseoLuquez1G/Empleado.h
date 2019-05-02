#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int hora;
    int minutos;
    int dia;
    int mes;
    int anio;

}sFecha;

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int dni;
    char clave[20];
    int isEmpty;
}Employee;

typedef struct
{
    int idFichaje;
    int idEmployee;
    sFecha fecha;
    char inOut[10];
}sFichaje;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* dniStr, char* claveStr);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this);
int employee_gettIdEmployee(Employee* this, int* id);

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

int employee_setApellido(Employee* this,char* apellido);
char* employee_getApellido(Employee* this);

int employee_setDni(Employee* this,int dni);
int employee_getDni(Employee* this);

int employee_setClave(Employee* this,char* clave);
char* employee_getClave(Employee* this);

void  employee_showEmployee(Employee* this);
void  employee_showEmployees(Employee* this);


int employee_sortByName(void* empleadoA, void* empleadoB);
int employee_sortById(void* empleadoA, void* empleadoB);
int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB);
int employee_sortBySueldo(void* empleadoA, void* empleadoB);
int employee_loadSueldo(void* empleado);



/** FECHA **/

sFecha* fecha_new();
int fecha_newParameteros(int hora, int minutos, int dia, int mes, int anio);
int fecha_setHora(sFecha* this, int hora);
int fecha_getHora(sFecha* this);
int fecha_setMinutos(sFecha* this, int minutos);
int fecha_getMinutos(sFecha* this);
int fecha_setDia(sFecha* this, int dia);
int fecha_getDia(sFecha* this);
int fecha_setMes(sFecha* this, int mes);
int fecha_getMes(sFecha* this);
int fecha_setAnio(sFecha* this, int anio);
int fecha_getAnio(sFecha* this);

/** FICHAJE **/

sFichaje* fichaje_new();
sFichaje* fichaje_newParametros(char* idFichajeStr, char* idEmployeeStr, char* inOut, sFecha* fecha);
int fichaje_setIdFichaje(sFichaje* this,int idFichaje);
int fichaje_getIdFichaje(sFichaje* this, int* idFichaje);
int fichaje_getIdFichajes(sFichaje* this);
int fichaje_setIdEmployee(sFichaje* this,int idEmployee);
int fichaje_getIdEmployee(sFichaje* this, int* idEmployee);
int fichaje_getIdEmpployees(sFichaje* this);
int fichaje_setInOut(sFichaje* this, char* inOut);
char* fichaje_getInOut(sFichaje* this);
void  fichaje_showFichaje(sFichaje* this);
void  fichaje_showFichajes(sFichaje* this);
#endif // employee_H_INCLUDED

