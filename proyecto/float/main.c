#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int funcion_validarNumeroFlotante(char str[]);
int funcion_getStringNumerosFlotantes(char mensaje[],char input[]);
void funcion_getString(char mensaje[],char input[]);



int main()
{
    float numero;
    fflush(stdin);
    char flotante[51];
    if(funcion_getStringNumerosFlotantes("ingrese numero", flotante))
    {
        numero = atof(flotante);
        printf(" es flotante %.2f", numero);
    }
    else
        {

            printf("el salario no es");
        }



    return 0;
}
int funcion_validarNumeroFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int funcion_getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarNumeroFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void funcion_getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}

