#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "peliculas_funciones.h"

int obtenerEspacioLibrePelicula(EMovie lista[],int tam)
{
    int i;
    int aux=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            aux=i;
            break;
        }
    }
    return aux;
}

int iniEstado(EMovie *lista,int tam)
{
    int i;

    int flag=-1;

    if(lista!=NULL&&tam>0)
    {
        flag=0;
        for(i=0; i<tam; i++)
        {
            (lista+i)->estado=0;
        }
    }
    return flag;
}

int ingresarPeliculas(EMovie *lista,int tam,int lugar)
{
    EMovie nuevo;
    int esValido;
    int flag=-1;

    if(lista!=NULL&&lugar>=0)
    {
        flag=0;

        printf("INGRESE DATOS:\n\n");

        do
        {
            igresoCadenaChar("INGRESE TITULO: ",nuevo.titulo);
            esValido=validarSiSonLetra(nuevo.titulo);
        }
        while(esValido);

        do
        {
            igresoCadenaChar("INGRESE DESCRIPCION: ",nuevo.descripcion);
            esValido=validarSiSonLetra(nuevo.descripcion);
        }
        while(esValido);

        do
        {
            esValido=0;
            nuevo.duracion=ingresoNumero("INGRESE DURACION: ");
            if(nuevo.duracion<1)
            {
                printf("LA PELICULA NO PUEDE DURA MENOS DE 1 HORA");
                esValido=-1;
            }
        }
        while(esValido);

        do
        {
            igresoCadenaChar("INGRESE GENERO: ",nuevo.genero);
            esValido=validarSiSonLetra(nuevo.genero);
        }
        while(esValido);

        do
        {
            esValido=0;
            printf("PONGA UN PUNTAJE DEL 1 AL 10\n");
            nuevo.puntaje=ingresoNumero("INGRESE EL PUNTAJE DE LA PELICULA: ");
            if(!(nuevo.puntaje>0&&nuevo.puntaje<=10))
            {
                printf("ERROR: SOLO ");
                esValido=1;
            }
        }
        while(esValido);

        igresoCadenaChar("INGRESE IMAGEN: ",nuevo.linkImagen);

        nuevo.estado=1;

        *(lista+lugar)=nuevo;
    }

    return flag;
}

int guardarEnArchivoPelicula(FILE *archivo,EMovie *pelicula,char *texto)
{
    int flag=-1;

    if(archivo!=NULL&&pelicula!=NULL)
    {
        fwrite(pelicula,sizeof(EMovie),1,archivo);
        flag=0;
    }
    fclose(archivo);

    return flag;
}


int mostrarListaPeliculas(EMovie *lista,int tam)
{
    int i;
    int flag=-1;

    if(lista!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==1)
            {
                printf("\nTITULO: %s -- GENERO: %s -- DURACIO: %.2f -- PUNTAJE: %d\n",lista[i].titulo,lista[i].genero,lista[i].duracion,lista[i].puntaje);
                printf("----------------------------------------------\n\n");
                flag=0;
            }
        }
        if(flag)
        {
            printf("NO HAY PELICULAS EN LA LISTA!!!!\n\n");
            flag=-2;
        }
    }
    return flag;
}


int buscarPorNombre(EMovie *lista,char *nombre,int tam)
{
    int i;
    int aux=-1;

    if(lista!=NULL&&nombre!=NULL)
    {
        aux=-2;
        for(i=0; i<tam; i++)
        {
            if(stricmp(nombre,(lista+i)->titulo)==0&&(lista[i].estado==1))
            {
                aux=i;
                break;
            }
        }
    }

    return aux;
}


int borrarDeLaListaPelicula(EMovie *lista,int ubicacion)
{
    char borrar;
    int flag=-1;

    if(lista!=NULL&&ubicacion>=0)
    {
        flag=0;
        printf("\n\nQUIERE BORRAR A ESTA PELICULA? \n\TITULO: %s\n\nPUNTAJE: %d\n\nDURACION: %.2f\n\n",lista[ubicacion].titulo,lista[ubicacion].puntaje,lista[ubicacion].duracion);
        printf("\nINGRESE OPCION [S/N]: ");
        borrar=getche();
        if(borrar=='s'||borrar=='S')
        {
            lista[ubicacion].estado=0;
            printf("\n\nFUE BORRADA!!!!!\n\n");
        }
        else
        {
            printf("\n\nNO FUE BORRADA!!!!!\n\n");
        }
    }
    if(ubicacion==-1)
    {
        printf("\nEL TITULO INGRESADO NO SE ENCUENTRA EN LA LISTA!!!!!\n\n");
    }

    return flag;
}
