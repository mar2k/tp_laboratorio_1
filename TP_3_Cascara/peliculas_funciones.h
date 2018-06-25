

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[1000];
    int puntaje;
    char linkImagen[200];
    int estado;
}EMovie;

int obtenerEspacioLibrePelicula(EMovie lista[],int tam);

int iniEstado(EMovie *lista,int tam);

int ingresarPeliculas(EMovie *lista,int tam,int lugar);

int guardarEnArchivoPelicula(FILE *archivo,EMovie *pelicula,char *texto);

int mostrarListaPeliculas(EMovie *lista,int tam);

int buscarPorNombre(EMovie *lista,char *nombre,int tam);

int borrarDeLaListaPelicula(EMovie *lista,int ubicacion);

void modificarPelicula(EMovie lista[],int lugar);

int guardarEnArchivo(EMovie* x,int tam,char* archivo);

int cargarDesdeArchivo(EMovie* x,int tam,char* archivo);

void generarPaginaWeb(char *archivo,EMovie *movie,int tam);
