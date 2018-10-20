#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    char nombre[51];
    int legajo;
    float sueldo;
    eFecha fecha;

}eEmpleado;

//void miFuncion(int* x);
int main()
{
    eEmpleado unEmpleado;
    eEmpleado* pEmpleado;
    pEmpleado = &unEmpleado;

    printf("ingrese legajo");
    scanf("%d ", pEmpleado->legajo);
    printf("ingrese nombre");
    scanf("%s", pEmpleado->nombre);
    printf("ingrese dia");
    scanf("%d ", &pEmpleado->fecha.dia);
    printf("ingrese mes");
    scanf("%d ", &pEmpleado->fecha.mes);
    printf("ingrese anio");
    scanf("%d ", &pEmpleado->fecha.anio);




   /** for(int i = 0; i < 5; i++)
    int vec[5];
   // miFuncion(&x);
    {
        printf("Ingrese un numero ");
        scanf("%d", vec+i);


    }
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *(vec+i));

    }
    **/

    return 0;

}

/**void miFuncion(int* x)
{
    *x = 38;
}
**/
