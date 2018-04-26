#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20


int main()
{
    EPersona listaPersonas[TAM];

    char seguir='s';
    char opcion;
    long int auxInt;
    int lugar;

    iniEstado(listaPersonas,TAM);

    do
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nINGRESE OPCION: ");

        opcion=getch();

        switch(opcion)
        {
        case '1':
        {
            system("cls");
            printf("OPCION 1:\n\n");

            lugar=obtenerEspacioLibre(listaPersonas,TAM);
            cargaDeDatos(listaPersonas,lugar,TAM);

        }
        break;
        case '2':
        {
            system("cls");
            printf("OPCION 2:\n\n");

            auxInt=ingresoLongInt("INGRESE DNI DE LA PERSONA: ");

            lugar=buscarPorDni(listaPersonas,auxInt,TAM);

            borrarDeLaLista(listaPersonas,lugar);

        }
        break;
        case '3':
        {
            system("cls");
            printf("OPCION 3:\n\n");

            ordenarCadenaChar(listaPersonas,TAM);

            mostrarLista(listaPersonas,TAM);

        }
        break;
        case '4':
        {
            system("cls");
            printf("OPCION 4:\n\n");

            hacerGrafico(listaPersonas);

        }
        break;
        case '5':
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
