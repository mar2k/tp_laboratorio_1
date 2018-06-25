#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "peliculas_funciones.h"
#define TAM_P 50

int main()
{
    char seguir='s';
    int opcion=0;
    int ok;
    int lugar;
    char titulo[50];
    char archivo[]="PELICULA.bin";
    char paginaWeb[]="LISTA DE LAS PELICULAS.html";
    EMovie *movie=(EMovie*) malloc(sizeof(EMovie)*TAM_P);

    iniEstado(movie,TAM_P);

    cargarDesdeArchivo(movie,TAM_P,archivo);

    do
    {
        mostrarListaPeliculas(movie,TAM_P);
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
        {
            system("cls");
            lugar=obtenerEspacioLibrePelicula(movie,TAM_P);
            ok=ingresarPeliculas(movie,TAM_P,lugar);
            if(!ok)
            {
                printf("NUEVA PELICULA CARGADA!!!\n");
            }
            else
            {
                printf("NO SE PUDO CARGAR PELICULA\n");
            }
            guardarEnArchivo(movie,TAM_P,archivo);
            break;
        }
        case 2:
        {
            igresoCadenaChar("INGRESE TITULO DE LA PELICULA: ",titulo);
            lugar=buscarPorNombre(movie,titulo,TAM_P);
            borrarDeLaListaPelicula(movie,lugar);
            guardarEnArchivo(movie,TAM_P,archivo);

        }
        break;
        case 3:
        {
            igresoCadenaChar("INGRESE TITULO DE LA PELICULA: ",titulo);
            lugar=buscarPorNombre(movie,titulo,TAM_P);
            modificarPelicula(movie,lugar);
            guardarEnArchivo(movie,TAM_P,archivo);
            break;
        }
        case 4:
        {
            system("cls");
            generarPaginaWeb(paginaWeb,movie,TAM_P);
            break;
        }

        case 5:
        {

            seguir = 'n';
            break;
        }

        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    return 0;
}

