#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

int igresoCadenaChar(char *texto,char *dato)
{
    int flag=-1;
    if(texto!=NULL&&dato!=NULL)
    {
        flag=0;
        printf("%s",texto);
        fflush(stdin);
        gets(dato);
    }
    return flag;
}

int validarSiSonLetra(char nombre[])
{
    int i;
    int flag=-1;

    if(nombre!=NULL)
    {
        flag=0;
        for(i=0; nombre[i]!='\0'; i++)
        {
            nombre[i]=toupper(nombre[i]);
            if(validarLetra(nombre[i]))
            {
                printf("\nSOLO PUEDE INGRESAR LETRAS LETRAS Y SIN DEJAR ESPACIO!!!!!\n");
                flag=-2;
                break;
            }
        }

    }
    return flag;
}

int validarLetra(char dato)
{
    int flag=-1;

    if((dato>='A'&&dato<='Z')||(dato>='a'&&dato<='z')||(dato=' '))
    {
        flag=0;
    }

    return flag;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

float ingresoNumero(char texto[])
{
    float dato=-1;
    char auxChar[200];

    if(texto!=NULL)
    {
        printf("%s",texto);
        fflush(stdin);
        gets(auxChar);
        dato=validarNumero(auxChar);
        if(dato==-1)
        {
            dato=-2;
        }
    }
    return dato;
}


float validarNumero(char dato[])
{
    float num;
    int flag=0;
    int i;
    int contadorPuntos=0;

    for(i=0; dato[i]!='\0'; i++)
    {

        if(dato[i]=='-'||dato[i]=='+')
        {
            if(i>0)
            {
                flag=1;
            }
        }
        else if(dato[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                flag=1;
            }
        }
        else
        {
            flag=esUnNumero(dato[i]);
        }
        if(flag)
        {
            break;
        }
    }

    if(flag)
    {
        num=ingresoNumero("ERROR:NUMERO NO VALIDO!!!!!\n\nREINGRESE NUMERO: ");
    }
    else
    {
        num = atof(dato);
    }

    return num;
}


int esUnNumero(char dato)
{
    int flag=-1;

    if(dato>='0'&&dato<='9')
    {
        flag=0;
    }
    return flag;
}

float multiplicacion(float num1,float num2)
{
    float total;

    total=num1*num2;

    return total;
}
