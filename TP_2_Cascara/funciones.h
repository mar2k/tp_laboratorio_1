#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

int validarEdad(int edad,int max,int min);

void validarNombre(char nombre[]);

int validarLetra(char dato);

int validarTamInt(int num,int tamMax,int tamMin);

int validarTamLongInt(long int num,int tamMax,int tamMin);

void borrarDeLaLista(EPersona lista[],int ubicacion);

void iniEstado(EPersona lista[],int tam);

void mostrarLista(EPersona lista[],int tam);

void cargaDeDatos(EPersona lista[],int lugar,int tam);

void igresoCadenaChar(char texto[],char dato[]);

int validarNumeroInt(char dato[]);

int esUnNumero(char dato);

int ingresoInt(char texto[]);

long int ingresoLongInt(char texto[]);

long int validarNumeroLongInt(char dato[]);

int validarDni(long int dni,EPersona lista[],int tam);


void cargaGrafico(int dato[]);

void hacerGrafico(EPersona lista[]);

int buscarMax(int dato[],int tam);

void mostrarGrafico(char dato1[],char dato2[],char dato3[],int tamMax);


void ordenarCadenaChar(EPersona lista[],int tam);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],long int dni,int tam);

#endif // FUNCIONES_H_INCLUDED
