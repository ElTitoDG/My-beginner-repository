/**
 * @file ej5.c
 * @brief Ejercicio 5: contexto para juegos y clientes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @definitions
 */
// Definir el tamaño máximo de un nombre en caracteres
#define MAX_NOMBRE 255
#define MAX_JUEGOS 40
#define MAX_CLIENTES 100
#define MAX_DESCARGAS 100
#define MAX_LUDOPATAS 10

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

typedef struct {
  int descargado;
  TFecha fecha;
} TDescarga;
typedef TDescarga TDescargas[MAX_DESCARGAS];

typedef struct {
  int codigo;
  TNombre nombre;
  TDescargas descargas;
  int numDescargas;
} TLudopata;
typedef TLudopata TLudopatas[MAX_LUDOPATAS];

// Definir estructura para un servidor web
typedef struct {
  TJuegos listaJuegos; /**< Array de juegos */
  int numJuegos; /**< Número de juegos en el array */
  TClientes clientes; /**< Array de clientes */
  int numClientes; /**< Número de clientes en el array */
  TLudopatas ludopatas; /**< Array de ludopatas*/
  int numLodopatas; /**< Número de ludopatas en el array */
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
      {10, "Hollow Knight", 'A', 15.00},
      {11, "Red Dead Redemption 2", 'A', 59.99},
      {12, "Celeste", 'A', 19.99},
      {13, "Portal 2", 'A', 9.99},
      {14, "The Sims 4", 'S', 49.99},
      {15, "Hades", 'A', 24.99}
    },
    .numJuegos = 15,
    .clientes = {
      {1, "Juan SinMiedo", 1, {15, 10, 2024}},
      {2, "Ana Banana", 3, {20, 11, 2024}},
      {3, "Pepe Pecas", 5, {15, 10, 2024}},
      {4, "Laura Risas", 7, {25, 12, 2024}},
      {5, "Carlos Tostado", 2, {15, 10, 2025}}
    },
    .numClientes = 5,
    .ludopatas = {
      {1, "Luis Ludópata", {{1, {1, 1, 2024}}, {2, {2, 1, 2024}}, {3, {3, 1, 2024}}}, 3},
      {2, "Maria Multipass", {{4, {5, 2, 2024}}, {5, {6, 2, 2024}}}, 2},
      {3, "Pedro Pérez", {{6, {7, 3, 2024}}}, 1},
      {4, "Sofía Sin Juegos", {}, 0}
    },
    .numLodopatas = 4
  };

  // Para cada ludopata imprime su nombre y los codigos de los juegos que se ha descargado
  for (int i = 0; i < web.numLodopatas; i++) {
    printf("Nombre: %s\n", web.ludopatas[i].nombre);
    if (web.ludopatas[i].numDescargas == 0)
      printf("El cliente no se ha descargado ningun juego\n");
    else {
      printf("Codigos descargados: ");
      for (int j = 0; j < web.ludopatas[i].numDescargas; j++) {
	printf("%d ", web.ludopatas[i].descargas[j].descargado);
      }
      printf("\n");
    }
  }

  // Para cada ludopata imprime su nombre y los nombres de los juegos que se ha descargado
  for (int i = 0; i < web.numLodopatas; i++) {
    printf("Nombre: %s\n", web.ludopatas[i].nombre);
    for (int j = 0; web.ludopatas[i].numDescargas; j++) {
      int juegoDescargado = web.ludopatas[i].descargas[j].descargado;
      for (int k = 0; k < web.numJuegos; k++) {
	if (juegoDescargado == web.listaJuegos[k].codigo)
	  printf("Nombre juego descargado: %s\n", web.listaJuegos[k].nombre);
      }
    }
    
  }


  printf("%d\n", web.numJuegos);
  printf("%s\n", web.clientes[3].nombre);
  for (int i = 0; i < web.numClientes; i++) {
    printf("%d\n", web.clientes[i].codigo);
  }

  // ejercicio 4b) imprime el nombre de todos los juegos
  printf("Nombre de todos los juegos disponibles: \n\t");
  for (int i = 0; i < web.numJuegos; i++) {
    printf("%s\n", web.listaJuegos[i].nombre);
  }

  // Imprime el precio medio de todos los juegos
  float totalPrecio = 0;
  for (int i = 0; i < web.numJuegos; i++) {
    totalPrecio += web.listaJuegos[i].precio;
  }
  printf("Precio medio de todos los juegos disponibles: %.2f\n", totalPrecio/web.numJuegos);

  // Imprime la fecha en la que cada cliente se ha descargado su juego
  printf("Para cada cliente, su nombre y la fecha en la que se ha descargado el juego\n");
  for (int i = 0; i < web.numClientes; i++) {
    printf("%s se ha descargado el juego en %2d/%2d/%4d\n",
	   web.clientes[i].nombre,
	   web.clientes[i].descarga.dia,
	   web.clientes[i].descarga.mes,
	   web.clientes[i].descarga.anyo);
  }

  // Imprime los juegos que valen mas de 30 euros
  printf("Juegos que valen mas de 30 euros\n");
  for (int i = 0; i < web.numJuegos; i++) {
    if (web.listaJuegos[i].precio > 30)
      printf("%s\n", web.listaJuegos[i].nombre);
  }

  // Imprime el juego que mas vale
  float maxPrecio = -1;
  int posMaxPrecio = -1;
  for (int i = 0; i < web.numJuegos; i++) {
    if (web.listaJuegos[i].precio > maxPrecio) {
      posMaxPrecio = i;
      maxPrecio = web.listaJuegos[i].precio;
    }
  }
  printf("El juego que mas vale es %s y su precio es %.2f",
	 web.listaJuegos[posMaxPrecio].nombre, maxPrecio);

  // Imprime la cantidad de juegos del genero introducido por el usuario
  char genero;
  do {
    printf("Introduce el genero del juego (A)ventura, (I)+D, (S)ociopatia? ");
    scanf(" %c", &genero);
    if (genero != 'A' && genero != 'S' && genero != 'I')
      printf("Error en genero\n");
  } while (genero != 'A' && genero != 'S' && genero != 'I');

  int cuantos = 0;
  for (int i = 0; i < web.numJuegos; i++) {
    if (web.listaJuegos[i].genero == genero)
      cuantos++;
  }

  if (cuantos == 0)
    printf("No hay juegos del genero introducido\n");
  else
    printf("Hay %d juegos del genero introducidon\n", cuantos);

  // Imprime el codigo del cliente cuyo nombre es el introducido por el usuario
  TNombre nombreCliente;
  int pos = -1;

  printf("Introduce el nombre del cliente: ");
  scanf(" %[^\n]", nombreCliente);
  for (int i = 0; i < web.numClientes; i++) {
    if (strcmp(nombreCliente, web.clientes[i].nombre) == 0)
      pos = i;
  }
  if (pos == -1)
    printf("No hay ningun cliente con el nombre %s\n", nombreCliente);
  else
    printf("El codigo del cliente %s es %d\n", nombreCliente, web.clientes[pos].codigo);

  // Ejericico 4c - pide el codigo del cliente e imprime el nombre del juego que se ha descargado
  int codBuscado;
  printf("Introduce el codigo del cliente a buscar: ");
  scanf("%d", &codBuscado);
  pos = -1;
  for (int i = 0; i < web.numClientes && pos == -1; i++) {
    if (web.clientes[i].codigo == codBuscado)
      pos = i;
  }

  if (pos == -1)
    printf("El codigo %d del cliente no existe\n", codBuscado);
  else {
    int codJuegoBuscado = web.clientes[pos].descargado;
    printf("El codigo del juego que se ha descargado %d\n", codJuegoBuscado);
    int posJuego = 1;
    for (int i = 0; i < web.numJuegos; i++) {
      if (web.listaJuegos[i].codigo == codJuegoBuscado)
	posJuego = i;
    }

    if (posJuego == -1)
      printf("Error fatal\n");
    else
      printf("El nombre del juego es %s\n", web.listaJuegos[posJuego].nombre);
  }

  // Pide el nombre del un juego e imprime los clientes que se han descargado ese juego
  TNombre juegoBuscado;
  printf("Introduce el nombre del juego a buscar: \n");
  scanf(" %[^\n]", juegoBuscado);

  int posJuego = -1;
  for (int i = 0; i < web.numJuegos && posJuego == -1; i++) {
    if (strcmp(web.listaJuegos[i].nombre, juegoBuscado) == 0)
      posJuego = i;
  }

  if (posJuego == -1)
    printf("No se encuentra el juego de nombre %s\n", juegoBuscado);
  else {
    int codJuegoBuscado = web.listaJuegos[posJuego].codigo;
    for (int i = 0; i < web.numClientes; i++) {
      if (web.clientes[i].descargado == codJuegoBuscado)
	printf("%s\n", web.clientes[i].nombre);
    }
  }
					      
  return EXIT_SUCCESS;
}
