#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int dni;
    char clave[20];
    int isEmpty;
}Employee;

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

#endif // employee_H_INCLUDED

