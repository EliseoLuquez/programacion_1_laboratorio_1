#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    char auxcad[50];


    printf("Ingrese su nombre: ");
    gets(auxcad);

    while(strlen(auxcad)>19)
    {
        printf("Error, nombre demasiado largo. Reingrese nombre  ");
        gets(auxcad);

    }
    strcpy(nombre, auxcad);

    printf("Usted se llama %s\n\n", nombre);



    return 0;
}
