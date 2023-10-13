#include "gfx/gfx.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int ysize = 300;
  int xsize = 300;

  int franjas, lineas, linea;
  char c;

  printf("ysize: ");
  scanf("%d", &ysize);
  printf("Cuantas franjas quieres: ");
  scanf("%d", &franjas);

  lineas = ysize / franjas;
  printf("%d lineas por franja\n", lineas);

  // Open a new window for drawing.
  gfx_open(xsize, ysize, "Rico perez");

  // Drawing color (0, 51, 255) to blue.
  // Drawing color (255, 255, 255) to white.

  // Draw a line and wait
  for (int y = 1; y < franjas; y++) {

    if ((y % 2) == 0) {
      gfx_color(0, 51, 255);
    } else {
      gfx_color(255, 255, 255);
    }

    for (int j = 1; j <= lineas; j++) {
      gfx_line(1, linea, xsize, linea);
      linea++;
    }

    c = gfx_wait();
  }

  // while (1) {
  //   c = gfx_wait();
  //   if (c == 'q')
  //     break;
  // }

  return EXIT_SUCCESS;
}
