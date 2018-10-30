#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int edad;

}sPersona;

int main()
{

    char id[20];
    char nombre[20];
    char apellido[20];
    char edad[20];
    int can;
    FILE* f;



    f  = fopen("numeros.csv", "r");

    if(f == NULL)
    {
        exit(1);
    }
    while( !feof(f))
    {
        can = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, edad);


        if(can == 4)
        {
            printf("los numeros ingresados  son %s %s %s %s\n",  id, nombre, apellido, edad);
        }
        else{
            break;
        }

    }
    fclose(f);

    return 0;
}
