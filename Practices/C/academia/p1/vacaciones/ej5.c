#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 255
#define MAX_JUEGOS 40
#define MAX_CLIENTES 100

typedef char TNombre[MAX_NOMBRE + 1];

typedef struct {
  int dia, mes, anyo;
} TFecha;

typedef struct {
  int codigo;
  TNombre nombre;
  char genero;
  float precio;
} TJuego;
typedef TJuego TJuegos[MAX_JUEGOS];

typedef struct {
  int codigo;
  TNombre nombre;
  int descargado;
  TFecha descarga;
} TCliente;
typedef TCliente TClientes[MAX_CLIENTES];

typedef struct {
  TJuegos listaJuegos;
  int numJuegos;
  TClientes clientes;
  int numClientes;
} TWeb;

void mostrarGenero(TJuegos listaJuegos, int numJuegos)
{
  char genBus;
  do {
    printf("Introduce genero (A)ccion, (E)strategia, (D)eporte: ");
    scanf(" %c", &genBus);
  } while (genBus != 'A' && genBus != 'E' && genBus != 'D');
  for (int i = 0; i < numJuegos; i++) {
    if (listaJuegos[i].genero == genBus)
      printf("%s\n", listaJuegos[i].nombre);
  }
}

void mostrarJuegosFecha(TWeb web)
{
  TFecha buscada;
  int posJuego;
  printf("Introduce dia, mes y año: ");
  scanf("%d %d %d", &buscada.dia, &buscada.mes, &buscada.anyo);
}

int main(void)
{
  TWeb web = {
    .listaJuegos = {
      {1, "The Legend of Zelda: Breath of the Wild", 'A', 59.99},
      {2, "Elden Ring", 'A', 69.99},
      {3, "Minecraft", 'I', 26.95},
      {4, "Super Mario Odyssey", 'A', 49.99},
      {5, "Cyberpunk 2077", 'A', 59.99},
      {6, "The Witcher 3: Wild Hunt", 'A', 39.99},
      {7, "Among Us", 'I', 4.99},
      {8, "Stardew Valley", 'S', 14.99},
      {9, "Grand Theft Auto V", 'A', 29.99},
      {10, "Hollow Knight", 'A', 15.00}
        },
    .numJuegos = 10,
    .clientes = {
      {1, "Juan SinMiedo", 1, {15, 10, 2024}},
      {2, "Ana Banana", 3, {20, 11, 2024}},
      {3, "Pepe Pecas", 5, {5, 12, 2024}},
      {4, "Laura Risas", 7, {25, 12, 2024}},
      {5, "Carlos Tostado", 2, {1, 1, 2025}}
    },
    .numClientes = 5
  };

  return EXIT_SUCCESS;
}
