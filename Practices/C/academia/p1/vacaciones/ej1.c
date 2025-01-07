#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALU 300
#define MAX_DNI 10
#define MAX_NOMBRE 50
#define MAX_PRUEBAS 10
#define MAX_EMAIL 100

typedef struct {
    char dni[MAX_DNI];
    char nombre[MAX_NOMBRE];
    char email[MAX_EMAIL];
    float teo, prac1, prac2;
    int pruebas[MAX_PRUEBAS];
    int numPruebas;
    int numFaltas;
} TAlumno;
typedef TAlumno TAlumnos[MAX_ALU];

typedef struct {
    TAlumnos alumnos;
    int numAlumnos;
} TListaAlumnos;

void listarSinFaltas(TAlumnos alumnos);
int buscarAlumno(TAlumnos alumnos, char *buscado);

int main(void)
{
    TAlumnos alumnos;

	return EXIT_SUCCESS;
}

void listarSinFaltas(TAlumnos alumnos)
{
    for (int i = 0; i < MAX_ALU; i++) {
        if (alumnos[i].numFaltas == 0)
            printf("%s %s\n", alumnos[i].nombre, alumnos[i].dni);
    }
}

int buscarAlumno(TAlumnos alumnos, char *buscado)
{
    int pos = -1, i;
    for (int i = 0; i < MAX_ALU && pos == -1; i++) {
        if (strcmp(alumnos[i].nombre, buscado) == 0)
            pos = i;
    }
    return pos;
}
