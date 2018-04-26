#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int buscarPorDni(EPersona lista[], long int dni,int tam)
{
    int i;
    int aux=-1;

    for(i=0; i<tam; i++)
    {
        if(dni==lista[i].dni&&!(lista[i].estado==0))
        {
            aux=i;
            break;
        }
    }
    return aux;
}

int obtenerEspacioLibre(EPersona lista[],int tam)
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

void igresoCadenaChar(char texto[],char dato[])
{
    printf("%s",texto);
    fflush(stdin);
    gets(dato);
    validarNombre(dato);

}
void validarNombre(char nombre[])
{
    int i;
    int flag=0;
    for(i=0; nombre[i]!='\0'; i++)
    {
        nombre[i]=toupper(nombre[i]);
        if(!validarLetra(nombre[i]))
        {
            printf("\nSOLO PUEDE INGRESAR LETRAS LETRAS Y SIN DEJAR ESPACIO!!!!!\n");
            flag=1;
            break;
        }
    }
    if(flag)
    {
        igresoCadenaChar("\nREINGRESE NOMBRE: ",nombre);
    }
}

int validarLetra(char dato)
{
    int flag=0;

    if(dato>='A'&&dato<='Z')
    {
        flag=1;
    }

    return flag;
}

long int ingresoLongInt(char texto[])
{
    long int dato;
    char auxChar[200];

    printf("\n%s",texto);
    gets(auxChar);

    dato=validarNumeroLongInt(auxChar);

    return dato;
}
int ingresoInt(char texto[])
{
    long int dato;
    char auxChar[200];

    printf("\n%s",texto);
    gets(auxChar);

    dato=validarNumeroInt(auxChar);

    return dato;
}
int validarNumeroInt(char dato[])
{
    int num;
    int flag=0;
    int i;

    for(i=0; dato[i]!='\0'; i++)
    {
        flag=esUnNumero(dato[i]);
        if(flag)
        {
            break;
        }
    }

    if(flag)
    {
        printf("ERROR:NO PUEDE INGRESRAR LETRAS!!!!!\n");
        num=ingresoInt("REINGRESE NUMERO: ");
    }
    else
    {
        num = atof(dato);
    }

    return num;
}

long int validarNumeroLongInt(char dato[])
{
    long int num;
    int flag=0;
    int i;

    for(i=0; dato[i]!='\0'; i++)
    {
        flag=esUnNumero(dato[i]);
        if(flag)
        {
            break;
        }
    }

    if(flag)
    {
        printf("ERROR:NO PUEDE INGRESRAR LETRAS!!!!!\n");
        num=ingresoLongInt("REINGRESE NUMERO: ");
    }
    else
    {
        num = atof(dato);
    }

    return num;
}

int esUnNumero(char dato)
{
    int flag=0;
    if((dato<'0'||dato>'9'))
    {
        flag=1;
    }
    return flag;
}

int validarDni(long int dni,EPersona lista[],int tam)
{
    int lugar;

    while(validarTamLongInt(dni,9,8))
    {
        dni=ingresoInt("ERROR:REINGRESE DNI: ");
    }

    lugar=buscarPorDni(lista,dni,tam);
    while(lista[lugar].dni==dni)
    {
        printf("\n\nYA EXISTE ESTE DNI EN LA LISTA!!!!\n\n");
        dni=0;
        while(validarTamLongInt(dni,9,8))
        {
            dni=ingresoInt("ERROR:REINGRESE DNI: ");
        }
        lugar=buscarPorDni(lista,dni,tam);
    }

    return dni;
}

/*int validarTamInt(int num,int tamMax,int tamMin)
{
    char auxChar[20];
    int auxInt;

    itoa(num,auxChar,10);

    auxInt=strlen(auxChar);

    while(auxInt>=tamMin&&auxInt<=tamMax)
    {
        num=ingresoInt("EL DNI NO ES VALIDO REINGRESE DNI: ");

        itoa(num,auxChar,10);

        auxInt=strlen(auxChar);
    }
    return num;
}*/

int validarTamLongInt(long int num,int tamMax,int tamMin)
{
    char auxChar[20];
    int auxInt;
    int flag=-1;
    itoa(num,auxChar,10);

    auxInt=strlen(auxChar);
    if(auxInt>=tamMin&&auxInt<=tamMax)
    {
        flag=0;
    }
    return flag;
}

int validarEdad(int edad,int max,int min)
{
    while(!(edad>=1&&edad<=100))
    {
        printf("\nLA EDAD NO NUEPED SER MENOR A 1 O MAYOR A 100!!!\n\n");
        edad=ingresoInt("REINGRESE EDAD: ");
    }
    return edad;
}

void ordenarCadenaChar(EPersona lista[],int tam)
{
    int i,j;
    EPersona aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>-1)
            {
                aux=lista[j];
                lista[j]=lista[i];
                lista[i]=aux;
            }

        }
    }
}

void cargaDeDatos(EPersona lista[],int lugar,int tam)
{
    EPersona nuevo;

    if(lugar!=-1)
    {
        printf("INGRESE DATOS DE LA PERSONA :\n\n");

        nuevo.dni=ingresoLongInt("INGRESE DNI: ");

        nuevo.dni=validarDni(nuevo.dni,lista,tam);

        igresoCadenaChar("\nINGRESE NOMBRE: ",nuevo.nombre);

        nuevo.edad=ingresoInt("INGRESE EDAD: ");

        nuevo.edad=validarEdad(nuevo.edad,100,1);

        nuevo.estado=1;

        lista[lugar]=nuevo;

    }

    else
    {
        printf("\n\nNO SE PUDO ENCONTRAR ESPACIO EN EL SISTEMA...\n\n");
    }


}

void mostrarLista(EPersona lista[],int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\nDNI: %ld -- NOMBRE: %s -- EDAD: %d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
            printf("----------------------------------------------\n\n");
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("NO HAY PERSONA EN LA LISTA!!!!\n\n");
    }
}

void iniEstado(EPersona lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
        lista[i].dni=0;
        lista[i].edad=0;
        strcpy(lista[i].nombre," ");
    }
}

void borrarDeLaLista(EPersona lista[],int ubicacion)
{
    char borrar;
    if(ubicacion>=0)
    {
        printf("\n\nQUIERE BORRAR A ESTA PERSONA? \n\nNOMBRE: %s\n\nEDAD: %d\n\nDNI: %ld\n\n",lista[ubicacion].nombre,lista[ubicacion].edad,lista[ubicacion].dni);
        printf("\nINGRESE OPCION [S/N]: ");
        borrar=getche();
        if(borrar=='s'||borrar=='S')
        {
            lista[ubicacion].estado=0;
            printf("\n\nLA PERSONA FUE BORRADA!!!!!\n\n");
        }
        else
        {
            printf("\n\nLA PERSONA NO FUE BORRADA!!!!!\n\n");
        }
    }
    if(ubicacion==-1)
    {
        printf("\nEL DNI INGRESADO NO SE ENCUENTRA EN LA LISTA!!!!!\n\n");
    }
}

void hacerGrafico(EPersona lista[])
{
    int contador[3]= {0};
    int i;

    for(i=0; i<20; i++)
    {
        if(lista[i].edad<=18&&lista[i].edad>=1)
        {
            contador[0]++;
        }
        else if(lista[i].edad>=19&&lista[i].edad<=35)
        {
            contador[1]++;
        }
        else if(lista[i].edad>35)
        {
            contador[2]++;
        }
    }
    cargaGrafico(contador);
}
void cargaGrafico(int dato[])
{
    char grafico1[20];
    char grafico2[20];
    char grafico3[20];
    int tamMax;
    int i;
    for(i=0; i<20; i++)
    {
        grafico1[i]=' ';
        grafico2[i]=' ';
        grafico3[i]=' ';
    }

    for(i=0; i<dato[0]; i++)
    {
        grafico1[i]='*';
    }

    for(i=0; i<dato[1]; i++)
    {
        grafico2[i]='*';
    }
    for(i=0; i<dato[2]; i++)
    {
        grafico3[i]='*';
    }

    tamMax=buscarMax(dato,3);
    mostrarGrafico(grafico1,grafico2,grafico3,tamMax);
}

int buscarMax(int dato[],int tam)
{
    int i;
    int max=0;
    for(i=0; i<tam; i++)
    {
        if(dato[i]>max)
        {
            max=dato[i];
        }
    }
    return max;
}

void mostrarGrafico(char dato1[],char dato2[],char dato3[],int tamMax)
{
    int i;

    for(i=tamMax; i>0; i--)
    {
        printf(" %c    %c    %c \n",dato1[i],dato2[i],dato3[i]);
    }
    printf("<18 19-35   36>\n");
}

