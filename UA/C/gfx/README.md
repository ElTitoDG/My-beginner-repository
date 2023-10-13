# Simple Graphics Library Documentation

A simple graphics library for CSE 20211 by Douglas Thain, designed to provide basic graphics functionality within C programs.

This library is licensed under a [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/). For complete documentation and more information, please visit [this link](http://www.nd.edu/~dthain/courses/cse20211/fall2013/gfx).

## Header File: `gfx.h`

### Functions

1. **`gfx_open(int width, int height, const char *title)`**
   - Opens a new graphics window with the specified dimensions and title. This function initializes the graphics environment and creates a window for drawing.

2. **`gfx_point(int x, int y)`**
   - Draws a point at the specified coordinates (x, y) on the graphics window. This function is useful for drawing individual pixels or points on the screen.

3. **`gfx_line(int x1, int y1, int x2, int y2)`**
   - Draws a line from the coordinates (x1, y1) to (x2, y2) on the graphics window. It is used to create simple line drawings on the screen.

4. **`gfx_color(int red, int green, int blue)`**
   - Changes the current drawing color to the specified RGB values. This function is essential for setting the color of points and lines before drawing them on the screen.

5. **`gfx_clear()`**
   - Clears the graphics window to the background color. This function is used to wipe the screen clean and start fresh for new drawings.

6. **`gfx_clear_color(int red, int green, int blue)`**
   - Changes the current background color to the specified RGB values. It is used to set the background color of the window.

7. **`gfx_wait()`**
   - Waits for the user to press a key or mouse button and returns the corresponding key or button press. This function allows the program to wait for user input before proceeding.

8. **`gfx_xpos()`**
   - Returns the X coordinate of the last event. It provides the X position of the mouse or the location where the key was pressed.

9. **`gfx_ypos()`**
   - Returns the Y coordinate of the last event. It provides the Y position of the mouse or the location where the key was pressed.

10. **`gfx_xsize()`**
    - Returns the X dimension of the window. It provides the width of the graphics window in pixels.

11. **`gfx_ysize()`**
    - Returns the Y dimension of the window. It provides the height of the graphics window in pixels.

12. **`gfx_event_waiting()`**
    - Checks to see if an event is waiting and returns a non-zero value if an event is available. This function is used to detect whether there is any pending user input.

13. **`gfx_flush()`**
    - Flushes all previous output to the window. It ensures that all drawing commands are sent to the screen and displayed properly.

## Source File

The source file provides the implementation of the functions declared in the header file. It includes functions to open a window, draw points and lines, change colors, clear the window, handle user events, and flush graphics output.

For more information, refer to the detailed documentation available [here](http://www.nd.edu/~dthain/courses/cse20211/fall2013/gfx).

Note: This library is designed for basic graphics usage and is well-suited for educational purposes.

