#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE_PELICULA 100
#define MAX_OPINIONES 15
#define MAX_PELICULAS 50

typedef struct {
    int codigo;
    char nombrePeli[MAX_NOMBRE_PELICULA];
    char genero;
    int espectadores;
    int opiniones[MAX_OPINIONES];
    int numOpiniones;
} TPelicula;
typedef TPelicula TPeliculas[MAX_PELICULAS];

typedef struct {
    TPeliculas peliculas;
    int numPeliculas;
} TListaPeliculas;

int main(void)
{
    TListaPeliculas lista;
    lista.numPeliculas = 0;


    return EXIT_SUCCESS;
}

void mostrarPelisTerror(TListaPeliculas pelis)
{
    if (pelis.numPeliculas == 0)
        printf("No hay peliculas\n");
    else {
        for (int i = 0; i < pelis.numPeliculas; i++) {
            if (pelis.peliculas[i].genero == 'T')
                if (pelis.peliculas[i].espectadores > 500)
                    printf("%s\n", pelis.peliculas[i].nombrePeli);
        }
    }
}
