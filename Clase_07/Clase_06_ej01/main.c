#include <stdio.h>
#include <stdlib.h> //DIRECTIVAS DE PREPROCESADOR
#include <string.h>

#define TAM 3

void ordenarAlumnos(int leg[], int pp[], int sp[], char nombres[][20], float prom[], char sexo[], int tam);

int main()
{
    int legajos[TAM];
    int pp[TAM];
    int sp[TAM];
    float promedios[TAM];
    char nombres[TAM][20];
    char sexos[TAM];

    for(int i=0;i<TAM;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("Ingrese nota primer parcial: ");
        fflush(stdin);
        scanf("%d", &pp[i]);
        printf("Ingrese nota segundo parcial: ");
        fflush(stdin);
        scanf("%d", &sp[i]);
        printf("Ingrese sexo f o m: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);
        promedios[i] = (float) (pp[i]+sp[i])/2;
        system("cls");
    }

   for(int i=0;i<TAM;i++)
   {

       printf("\n\nSu legajo es: %d", legajos[i]);
       printf("\nSu nombre es: %s", nombres[i]);
       printf("\nSu nota de primer parcial  es: %d", pp[i]);
       printf("\nSu nota de segundo parcial  es: %d", sp[i]);
       printf("\nEl promedio de los parciales  es: %.2f", promedios[i]);
       printf("\nSu sexo es: %c", sexos[i]);
   }
    printf("\n\n");


    return 0;
}

/*
void ordenarCharArray(char vec[], int tam, int criterio)
{
    char aux;
    for(int i=0;i<tam-1;i++)
    {
        for(int j = i+1;j<tam;j++)
        {
            if(vec[i]>vec[j]&&criterio)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

            else if(vec[i]<vec[j]&&criterio==0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

        }
    }

}

*/
void ordenarAlumnos(int leg[], int pp[], int sp[], char nombres[][20], float prom[], char sexo[], int tam)
{
    int i;
    int j;
    float auxFloat;
    int auxInt;
    char auxChar;
    char auxCad;


    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(prom[i]<prom[j])   // if(sex[i]< sex[j])
            {
                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = pp[i];
                pp[i] = pp[j];
                pp[j] = auxInt;

                auxInt = sp[i];
                sp[i] = sp[j];
                sp[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;

                strcpy(auxCad, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxCad);







            }

        }
    }
}
