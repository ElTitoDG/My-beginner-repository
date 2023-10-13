#include "gfx/gfx.h"
#include <stdio.h>
#include <stdlib.h>

// Drawing color (0, 51, 255) to blue.
// Drawing color (255, 255, 255) to white.

int main() {

  int ysize = 300;
  int xsize = 500;

  int franjas, lineas, linea;
  char c;

  printf("ysize: ");
  scanf("%d", &ysize);
  printf("Cuantas franjas quieres: ");
  scanf("%d", &franjas);

  lineas = ysize / franjas;
  printf("%d lineas por franja\n", lineas);

  // Open a new window for drawing.
  gfx_open(xsize, ysize, "Rico perez-1");

  linea = 1;
  // Solution 1 (working)
  for (int y = 1; y < ysize; y++) {

    if ((y % 2) == 0) {
      gfx_color(255, 255, 255);
    } else {
      gfx_color(0, 51, 255);
    }

    for (int j = 1; j <= lineas; j++) {
      linea++;
      gfx_line(1, linea, xsize, linea);
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
