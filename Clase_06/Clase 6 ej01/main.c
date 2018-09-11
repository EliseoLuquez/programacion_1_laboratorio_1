#include <stdio.h>
#include <stdlib.h>
#define TAM 8
void mostrarCharArray(char vec[], int tam);
void ordenarCharArray(char vec[], int tam, int criterio);
int main()
{

    char letras[]={'d', 'c', 'a', 'f', 'A', 'C', 'z', 'Z'};

    mostrarCharArray(letras, TAM);
    ordenarCharArray(letras, TAM, 1);
    mostrarCharArray(letras, TAM);

    return 0;
}

void mostrarCharArray(char vec[], int tam)
{

    for(int i=0;i<8;i++)
    {
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}

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


