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
    //char texto[]="LISTA DE LAS PELICULAS.bin";
    int opcion=0;
    int ok;
    //int cont=0;
    int lugar;
    char titulo[50];
    EMovie *movie=(EMovie*) malloc(sizeof(EMovie)*TAM_P);
    //FILE *archivo;

    iniEstado(movie,TAM_P);

    while(seguir=='s')
    {
        mostrarListaPeliculas(movie,TAM_P);
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- guardar y Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
        {
            lugar=obtenerEspacioLibrePelicula(movie,TAM_P);
            ok=ingresarPeliculas(movie,TAM_P,lugar);
            if(!ok)
            {
              printf("NUEVA PELICULA CARGADA!!!");
            }
            else
            {
                printf("NO SE PUDO CARGAR PELICULA");
            }
            break;
        }
        case 2:
        {
            igresoCadenaChar("INGRESE TITULO DE LA PELICULA: ",titulo);
            lugar=buscarPorNombre(movie,titulo,TAM_P);
            borrarDeLaListaPelicula(movie,lugar);

        }
        break;
        case 3:
        {

            break;
        }

        case 4:
        {

            break;
        }

        }
        system("pause");
        system("cls");
    }
    return 0;
}

/*

if(lugar!=NULL)
            {
                seGuardo=agregarPelicula(*lugar);
                if(seGuardo)
                {
                    printf("SE GUARDO CON EXITO!!!\n\n");
                    cont++;
                    aux=realloc(movie,cont);
                    if (aux == NULL)
                    {
                        printf("\nNo hay lugar en memoria\n");
                        exit(1);
                    }
                    (movie+cont-1)->estado=0;
                }
            }
            else
            {
                printf("NO HAY LUGAR\n\n");
            }

*/
