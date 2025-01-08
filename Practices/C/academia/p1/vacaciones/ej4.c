/**
 * @file ej5.c
 * @brief Ejercicio 5: contexto para juegos y clientes.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @definitions
 */
// Definir el tamaño máximo de un nombre en caracteres
#define MAX_NOMBRE 255
#define MAX_JUEGOS 40
#define MAX_CLIENTES 100

/**
 * @typedefs
 */
// Definir tipo para un nombre en caracteres
typedef char TNombre[MAX_NOMBRE + 1];

/**
 * @structs
 */
// Definir estructura para una fecha
typedef struct {
  int dia; /**< Día de la fecha */
  int mes; /**< Mes de la fecha */
  int anyo; /**< Año de la fecha */
} TFecha;

// Definir estructura para un juego
typedef struct {
  int codigo; /**< Código del juego */
  TNombre nombre; /**< Nombre del juego */
  char genero; /**< Género del juego */
  float precio; /**< Precio del juego */
} TJuego;
typedef TJuego TJuegos[MAX_JUEGOS];

// Definir estructura para un cliente
typedef struct {
  int codigo; /**< Código del cliente */
  TNombre nombre; /**< Nombre del cliente */
  int descargado; /**< Indica si el juego fue descargado o no */
  TFecha descarga; /**< Fecha de descarga del juego */
} TCliente;
typedef TCliente TClientes[MAX_CLIENTES];

// Definir estructura para un servidor web
typedef struct {
  TJuegos listaJuegos; /**< Arreglo de juegos */
  int numJuegos; /**< Número de juegos en el arreglo */
  TClientes clientes; /**< Arreglo de clientes */
  int numClientes; /**< Número de clientes en el arreglo */
} TWeb;

/**
 * @functions
 */
// Mostrar juegos que pertenecen a un género específico
void mostrarGenero(TJuegos listaJuegos, int numJuegos) {
  char genBus; /**< Carácter ingresado por el usuario para filtrar juegos */
  // Pedir al usuario que ingrese un género
  do {
    printf("Introduce género (A)cción, (E)strategia, (D)eporte: ");
    scanf(" %c", &genBus);
  } while (genBus!= 'A' && genBus!= 'E' && genBus!= 'D');
  // Mostrar juegos que pertenecen al género ingresado
  for (int i = 0; i < numJuegos; i++) {
    if (listaJuegos[i].genero == genBus)
      printf("%s\n", listaJuegos[i].nombre);
  }
}

// Mostrar juegos que fueron descargados en una fecha específica
void mostrarJuegosFecha(TWeb web) {
  TFecha buscada; /**< Fecha ingresada por el usuario para filtrar descargas */
  // Pedir al usuario que ingrese una fecha
  printf("Introduce día, mes y año: ");
  scanf("%d %d %d", &buscada.dia, &buscada.mes, &buscada.anyo);

  // Mostrar juegos que fueron descargados en la fecha ingresada
  for (int i = 0; i < web.numClientes; i++) {
    if (web.clientes[i].descarga.dia == buscada.dia &&
        web.clientes[i].descarga.mes == buscada.mes &&
        web.clientes[i].descarga.anyo == buscada.anyo)
      for (int j = 0; j < web.numJuegos; j++) {
        if (web.clientes[i].descargado == web.listaJuegos[j].codigo) {
          printf("%s\n", web.listaJuegos[j].nombre);
        }
      }
  }
}

int main(void) {
  // Crear un servidor web con juegos y clientes
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
      {1, "Juan SinMiedo", 4, {15, 10, 2024}},
      {1, "Juan SinMiedo", 3, {15, 10, 2024}},
      {2, "Ana Banana", 3, {20, 11, 2024}},
      {3, "Pepe Pecas", 5, {5, 12, 2024}},
      {4, "Laura Risas", 7, {25, 12, 2024}},
      {5, "Carlos Tostado", 2, {1, 1, 2025}}
    },
   .numClientes = 5
  };

  // Mostrar juegos que fueron descargados en una fecha específica
  mostrarJuegosFecha(web);

  return EXIT_SUCCESS;
}
