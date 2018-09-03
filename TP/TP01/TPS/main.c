#include <stdio.h>
#include <stdlib.h>

float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);
int factorial(int a);
int resultados();

int main()
{
   /*
   Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/
    float x;
    float y;
    int flagA = 0;
    int flagB = 0;
    int menu;
    int flagSalir = 0;

    do
    {
        system("cls");
        if(flagA==0)
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1. Ingresar 1er operando (A=%.2f)\n", x);
        }
        if(flagB==0)
        {
            printf("2. Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2. Ingresar 2do operando (B=%.2f)\n", y);
        }
        printf("3. Calcular operaciones: \na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\n");
        printf("d) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n");
        printf("4. Mostrar resultados\n");
        printf("5. Salir\n");
        printf("Elija una opcion\n");

        scanf("%d", &menu);

        switch(menu)
        {
                case 1:
                        system("cls");
                        printf("1. Ingresar 1er operando (A=x)\n");
                        scanf("%f", &x);
                        flagA=1;
                        break;
                case 2:
                        system("cls");
                        printf("2. Ingresar 2do operando (B=y)\n)");
                        scanf("%f", &y);
                        flagB=1;
                        break;
                case 3:
                        resultados();
                        system("pause");
                        break;

                case 4:
                        if(flagA!=1)
                        {
                            printf("Debe ingresar operando A");
                            printf("1. Ingresar 1er operando (A=x)\n");
                            scanf("%f", &x);
                        }
                        if(flagB!=1)
                        {
                            printf("Debe ingresar operando B");
                            printf("2. Ingresar 2do operando (B=y)\n)");
                            scanf("%f", &y);
                        }
                        printf("Resultados:\n");
                        printf("El resultado de A+B es: %.2f", suma(x, y));
                        printf("\nEl resultado de A-B es: %.2f", resta(x, y));
                        printf("",division(x, y));
                        printf("\nEl resultado de A*B es: %.2f", multiplicacion(x, y));
                        printf("\nEl factorial de A es: %d y el factorial de B es: %d\n",factorial(x), factorial(y));
                        system("pause");
                        break;
                case 5:
                        flagSalir=1;
                        printf("\nAprete Enter para salir\n");
                        break;
        }

    }
    while(flagSalir==0);

    return 0;
}


float suma(float a, float b)
{
    return a+b;
}
float resta(float a, float b)
{
    return a-b;
}
float multiplicacion(float a, float b)
{
    return a*b;
}
float division(float a, float b)
{
    if(b==0)
    {
        printf("\nNo se puede dividir por 0");
    }
    else
    {
    return  printf("\nEl resultado de A/B es: %.2f", division(a, b));
    }
}

int factorial (int a)
{
    int factorial = 1;
    int i;
    for (i=1; a >= i; i ++ )
    {
        factorial= factorial * i;
    }
    return factorial;
}
int resultados(a, b)
{
    printf("Resultados:\n");
    printf("El resultado de A+B es: %.2f", suma(a, b));
    printf("\nEl resultado de A-B es: %.2f", resta(a, b));
    printf("",division(a, b));
    printf("\nEl resultado de A*B es: %.2f", multiplicacion(a, b));
    printf("\nEl factorial de A es: %d y el factorial de B es: %d\n",factorial(a), factorial(b));

}


