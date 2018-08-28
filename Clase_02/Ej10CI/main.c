#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*/*Al presionar el botón pedir números hasta que el usuario quiera, mostrar:
    1-Suma de los negativos.
    2-Suma de los positivos.
    3-Cantidad de positivos.
    4-Cantidad de negativos.
    5-Cantidad de ceros.
    6-Cantidad de números pares.
    7-Promedio de positivos.
    8-Promedios de negativos.
    9-Diferencia entre positivos y negativos, (positvos-negativos).
    10-maximo y minimo
    */
    char respuesta ='s';
    int numero;
    //int continuar;
    int acumuladorDePositivos;
    int acumuladorDeNegativos;
    int contadorDePositivos;
    int contadorDeNegativos;
    int contadorDeCeros;
    int contadorDeNumerosPares;
    float promedioPositivos;
    float promedioNegativos;
    int diferencia;
    int maximo;
    int minimo;
    int contador;

    contador = 0;
    //continuar = 1;
    contadorDePositivos = 0;
    contadorDeNegativos = 0;
    acumuladorDeNegativos = 0;
    acumuladorDePositivos = 0;
    contadorDeCeros = 0;
    contadorDeNumerosPares = 0;

   // while(continuar)
    do
        {
            contador++;
            printf("Ingrese un numero: ");
            scanf("%d", &numero);


        if(numero>0)
        {
            contadorDePositivos++;
            acumuladorDePositivos+=numero;
        }
        else if(numero<0)
        {
            contadorDeNegativos++;
            acumuladorDeNegativos+=numero;
        }
        else if(numero==0)
        {
            contadorDeCeros++;
        }

        if(numero%2==0)
        {
            contadorDeNumerosPares++;
        }

        if(contador==1)
        {
            maximo = numero;
            minimo = numero;
        }
        else if(numero>maximo)
        {
            maximo=numero;
        }
        else if(numero<minimo)
        {
            minimo=numero;
        }
            // printf("Ingrese 1 para continuar 0 para salir\n");
            //scanf("%d", &continuar);
            printf("Desea continuar (s/n)\n");
            fflush(stdin);
            scanf("%c", &respuesta);

        }while(respuesta =='s');

        promedioPositivos =(float)acumuladorDePositivos/contadorDePositivos;
        promedioNegativos =(float)acumuladorDeNegativos/contadorDeNegativos;
        diferencia = contadorDePositivos-contadorDeNegativos;
        printf("\nLa suma de los negativos es: %d", acumuladorDeNegativos);
        printf("\nLa suma de los positivos es: %d", acumuladorDePositivos);
        printf("\nLa cantidad de negativos es: %d", contadorDeNegativos);
        printf("\nLa cantidad de positivos es: %d", contadorDePositivos);
        printf("\nLa cantidad de ceros es: %d", contadorDeCeros);
        printf("\nLa cantidad de numeros pares es: %d", contadorDeNumerosPares);
        printf("\nEl promedio de positivos es: %.2f", promedioPositivos);
        printf("\nEl promedio de negativos es: %.2f", promedioNegativos);
        printf("\nLa diferencia de pos y neg es: %d", diferencia);
        printf("\nEl maximo es: %d", maximo);
        printf("\nEl minimo es: %d", minimo);


    return 0;
}
