/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include "gfx.h"
#include <stdio.h>

int main() {
  int ysize = 300;
  int xsize = 300;

  char c;

  // Open a new window for drawing.
  gfx_open(xsize, ysize, "Example Graphics Program");

  // Set the current drawing color to green.
  gfx_color(0, 200, 100);

  // Draw a triangle on the screen.
  gfx_line(0, 300, 100, 300);
  gfx_line(0, 300, 100, 300);

  while (1) {
    // Wait for the user to press a character.
    c = gfx_wait();

    // Quit if it is the letter q.
    if (c == 'q')
      break;
  }

  return 0;
}
