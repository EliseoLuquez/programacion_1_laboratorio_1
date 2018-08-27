#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*3.	Escribir  un programa que realice las siguientes acciones
•	Limpie la pantalla
•	Asigne a 2 variables numero1 y numero2 valores distintos de cero
•	Efectúe el producto de dichas variables
•	Muestre el resultado pos pantalla
•	Obtenga el cuadrado de numero1 y lo muestre par pantalla
    */
    system("cls");

    int numero1;
    int numero2;
    int producto;
    int cuadrado;

    numero1 = rand()% 50;
    numero2 = rand()% 50;
    printf("El numero1 es: %d\n", numero1);
    printf("El numero2 es: %d\n", numero2);

    producto = numero1*numero2;
    printf("El producto es: %d\n", producto);
    cuadrado = numero1*numero1;
    printf("El cuadrado de numero1 es: %d", cuadrado);










}
