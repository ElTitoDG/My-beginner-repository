#include "gfx/gfx.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int ysize = 300;
  int xsize = 300;

  int franjas, lineSize;

  printf("Cuantas franjas quieres: ");
  scanf("%d", &franjas);
  printf("Tamaño de las lineas: ");
  scanf("%d", &lineSize);
  printf("Se dibujaran %d con un tamaño de %d pixeles\n", franjas, lineSize);

  char c;

  // Open a new window for drawing.
  gfx_open(xsize, ysize, "Rico perez");

  // Set the current drawing color to blue.
  // gfx_color(255, 255, 255) color white.

  // Draw a line and wait
  for (int y = 1; y < franjas; y++) {
    gfx_line(0, y, xsize, y);
    c = gfx_wait();
    if ((y % 2) == 0) {
      gfx_color(0, 51, 255);
    } else {
      gfx_color(255, 255, 255);
    }
  }

  return EXIT_SUCCESS;
}
