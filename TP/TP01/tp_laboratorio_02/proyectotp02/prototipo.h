#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED


typedef struct
    {
        int id;
        char name[51];
        char lastName[51];
        float salary;
        int sector;
        int isEmpty;

    }sEmployee;

int options();
int initEmployees(sEmployee* list, int len);
int addEmployees(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int searchEmpty(sEmployee* list, int len);
void printEmployees(sEmployee* list, int len);
int findEmployeeById(sEmployee* list, int len, int id);
void modifyEmployee(sEmployee* list, int len);
int sortEmployees(sEmployee* list, int len, int order);
int removeEmployee(sEmployee* list, int len);

#endif // PROTOTIPO_H_INCLUDED
