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
                printf("\nTITULO: %s -- GENERO: %s -- DURACIO: %d -- PUNTAJE: %d\n",lista[i].titulo,lista[i].genero,lista[i].duracion,lista[i].puntaje);
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
        system("cls");
        flag=0;
        printf("QUIERE BORRAR A ESTA PELICULA? \n\nTITULO: %s\n\nPUNTAJE: %d\n\nDURACION: %d\n",lista[ubicacion].titulo,lista[ubicacion].puntaje,lista[ubicacion].duracion);
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


void modificarPelicula(EMovie lista[],int lugar)
{
    char modifica;
    char seguir='s';
    int esValido;
    int opcion;

    printf("TITULO: %s\nDESCRIPCION: %s \n\nDESEA MODIFICAR?[S/N] ",lista[lugar].titulo,lista[lugar].descripcion);

    modifica=getch();

    system("cls");

    if(modifica=='s'||modifica=='S')
    {
        do
        {
            printf("1- TITULO\n");
            printf("2- DESCRIPCION\n");
            printf("3- DURACION\n");
            printf("4- GENERO\n");
            printf("5- PUNTAJE\n");
            printf("6- IMAGEN\n");
            printf("7- SALIR\n");

            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
            {
                do
                {
                    igresoCadenaChar("INGRESE TITULO: ",lista[lugar].titulo);
                    esValido=validarSiSonLetra(lista[lugar].titulo);
                }
                while(esValido);

                break;
            }
            case 2:
            {
                do
                {
                    igresoCadenaChar("INGRESE DESCRIPCION: ",lista[lugar].descripcion);
                    esValido=validarSiSonLetra(lista[lugar].descripcion);
                }
                while(esValido);


                break;
            }
            case 3:
            {
                do
                {
                    esValido=0;
                    lista[lugar].duracion=ingresoNumero("INGRESE DURACION: ");
                    if(lista[lugar].duracion<1)
                    {
                        printf("LA PELICULA NO PUEDE DURA MENOS DE 1 HORA");
                        esValido=-1;
                    }
                }
                while(esValido);

                break;
            }
            case 4:
            {
                do
                {
                    igresoCadenaChar("INGRESE GENERO: ",lista[lugar].genero);
                    esValido=validarSiSonLetra(lista[lugar].genero);
                }
                while(esValido);

                break;
            }
            case 5:
            {
                do
                {
                    esValido=0;
                    printf("PONGA UN PUNTAJE DEL 1 AL 10\n");
                    lista[lugar].puntaje=ingresoNumero("INGRESE EL PUNTAJE DE LA PELICULA: ");
                    if(!(lista[lugar].puntaje>0&&lista[lugar].puntaje<=10))
                    {
                        printf("ERROR: SOLO ");
                        esValido=1;
                    }
                }
                while(esValido);

                break;
            }
            case 6:
            {
                igresoCadenaChar("INGRESE IMAGEN: ",lista[lugar].linkImagen);

                break;
            }
            case 7:
            {
                seguir = 'n';
                break;
            }

            }
            system("pause");
            system("cls");
        }
        while(seguir=='s');
    }
}

int guardarEnArchivo(EMovie* x,int tam,char* archivo)
{

    FILE *f;
    int todoOk=1;

    f=fopen(archivo,"wb");

    if(f != NULL&&x!=NULL)
    {
        fwrite(x,sizeof(EMovie),tam,f);
        fclose(f);
        todoOk=0;
    }

    return todoOk;
}

int cargarDesdeArchivo(EMovie* x,int tam,char* archivo)
{
    int flag =0;
    int todoOk=0;
    FILE *f;

    f=fopen(archivo, "rb");
    if(f==NULL)
    {
        f= fopen(archivo, "wb");
        if(f==NULL)
        {
            todoOk=1;
            flag=1;
        }
    }

    if(flag ==0)
    {
        fread(x,sizeof(EMovie),tam,f);
    }

    fclose(f);
    return todoOk;
}


void generarPaginaWeb(char *archivo,EMovie *movie,int tam)
{
    FILE* miPelicula;
    int i;

    if(archivo!=NULL&&movie!=NULL)
    {
        miPelicula = fopen(archivo, "w");
        rewind(miPelicula);

        for(i=0; i<tam; i++)
        {
            if((movie+i)->estado==1)
            {
                fprintf(miPelicula,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>TITULO: %s</a></h3><ul><li>GENERO: %s</li><li>PUNTAJE: %d</li><li>DURACION: %d</li></ul><p>DESCRIPCION: %s</p></article>",(movie+i)->linkImagen,(movie+i)->titulo,(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion,(movie+i)->descripcion);
            }

        }
        fclose(miPelicula);

        printf("SE GENERO LA PAGINA WEP!!!!\n");
    }
    else
    {
        printf("NO SE PUDO GENERO LA PAGINA WEP!!!!\n");
    }

}

