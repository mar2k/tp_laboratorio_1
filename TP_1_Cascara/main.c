#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    char opcion;
    float numero[2]= {};


    do
    {
        printf("(1) Ingresar 1er operando (A= %.2f)\n",numero[0]);
        printf("(2) Ingresar 2do operando (B= %.2f)\n",numero[1]);
        printf("(3) Calcular la suma (A+B)\n");
        printf("(4) Calcular la resta (A-B)\n");
        printf("(5) Calcular la division (A/B)\n");
        printf("(6) Calcular la multiplicacion (A*B)\n");
        printf("(7) Calcular el factorial (A!)\n");
        printf("(8) Calcular todas las operacione\n");
        printf("(9) Salir\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
        {
            numero[0]=pedirNumero("ingrese numero para la varaible A: ");
        }
        break;
        case '2':
        {
            numero[1]=pedirNumero("ingrese numero para la varaible B: ");
        }
        break;
        case '3':
        {
            suma(numero[0],numero[1]);
        }
        break;
        case '4':
        {
            resta(numero[0],numero[1]);
        }
        break;
        case '5':
        {
            divicion(numero[0],numero[1]);
        }

        break;
        case '6':
        {
            multiplicacion(numero[0],numero[1]);
        }
        break;
        case '7':
        {
            factorial(numero[0]);
        }
        break;
        case '8':
        {
            suma(numero[0],numero[1]);
            resta(numero[0],numero[1]);
            divicion(numero[0],numero[1]);
            multiplicacion(numero[0],numero[1]);
            factorial(numero[0]);
        }
        break;
        case '9':
        {
            seguir = 'n';
        }
        break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    return 0;
}
