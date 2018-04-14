#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

float pedirNumero(char texto[])
{
    float num;
    char aux[200];

    printf("\n%s",texto);
    gets(aux);

    num=validarNumero(aux);

    return num;
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
        num=pedirNumero("ERROR:NUMERO NO VALIDO!!!!!\n\nREINGRESE NUMERO: ");
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

void suma(float num1,float num2)
{
    float total;
    total=num1+num2;
    printf("LA SUMA DE %.2f + %.2f ES= %.2f\n\n",num1,num2,total);
}

void resta(float num1,float num2)
{
    float total;
    total=num1-num2;
    printf("LA RESTA DE %.2f - %.2f ES= %.2f\n\n",num1,num2,total);
}

void multiplicacion(float num1,float num2)
{
    float total;
    total=num1*num2;
    printf("LA MULTIPICACION DE %.2f x %.2f ES= %.2f\n\n",num1,num2,total);
}

void divicion(float num1,float num2)
{
    float total;
    if(num2!=0)
    {
        total=num1/num2;
        printf("LA DIVICION DE %.2f / %.2f ES= %.2f\n\n",num1,num2,total);
    }
    else
    {
        printf("ERROR: NO SE PUEDE DIVIDIR POR 0.\n\n");
    }
}

void factorial(int num)
{
    long long int total=1;
    int i;
    char texTotal[100];

    printf("SOLO FACTORIAL DE NUMEROS ENTEROS POSITIVOS!!!!\n");
    printf("NUMEROS CON COMA SE TOMARA SOLO LA PARTE ENTERRA INGNORANDO LO DEMAS!!!!\n\n");

    if(num>=0&&num<=31)
    {
        for(i=num; i>=1; i--)
        {
            total*=i;
        }
        itoa(total,texTotal,10);
        printf("EL FACTORIAL DE %d! ES= %s\n\n",num,texTotal);
    }

    else if(num>31)
    {
        printf("ERROR:NOSE PUEDE HACER EL FACTORIAL DE %d INSUFICIENTE ESPACIO EN LA MEMORIA.\n\n",num);
    }
    else
    {
        printf("ERROR:NO SE PUEDE HACER EL FACTORIAL DE UN NUMERO NEGATIVO.\n\n");
    }
}
