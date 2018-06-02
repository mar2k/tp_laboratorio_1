

typedef struct{
    char titulo[20];
    char genero[20];
    float duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
    int estado;
}EMovie;

int obtenerEspacioLibrePelicula(EMovie lista[],int tam);

int iniEstado(EMovie *lista,int tam);

int ingresarPeliculas(EMovie *lista,int tam,int lugar);

int guardarEnArchivoPelicula(FILE *archivo,EMovie *pelicula,char *texto);

int mostrarListaPeliculas(EMovie *lista,int tam);

int buscarPorNombre(EMovie *lista,char *nombre,int tam);

int borrarDeLaListaPelicula(EMovie *lista,int ubicacion);

