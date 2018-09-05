# include  "Luquez.h"
# include  <stdio.h>


float suma(float a, float b)
{
    return (a+b);
}
float resta(float a, float b)
{
    return (a-b);
}
float multiplicacion(float a, float b)
{
    return (a*b);
}
float division(float a, float b)
{
    return a/b;
}

int factorial (int a)
{
    int valor;
    if(a==0)
    {
        return 1;
    }
    valor=a*factorial(a-1);

    return valor;
}
